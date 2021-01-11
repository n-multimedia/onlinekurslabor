<?php

/**
 * @file
 * Menu callbacks for hook_menu().
 */

/**
 * @see profile2_diff_latest
 */
function profile2_diff_latest_by_user($type, $user) {
  profile2_diff_latest(profile2_load_by_user($user, $type));
}

/**
 * Menu callback - show latest diff for a given profile.
 */
function profile2_diff_latest($profile) {
  $revisions = profile2_revision_list($profile);
  $new = array_shift($revisions);
  $old = array_shift($revisions);
  $link_base = _profile2_revision_base_path($profile, TRUE);
  drupal_goto("$link_base/diff/{$old->vid}/{$new->vid}");
}

/**
 * @see profile2_diff_diffs_overview()
 */
function profile2_diff_diffs_overview_user($type, $user) {
  return profile2_diff_diffs_overview(profile2_load_by_user($user, $type));
}

/**
 * Generate an overview table of older revisions of a profile and provide
 * an input form to select two revisions for a comparison.
 */
function profile2_diff_diffs_overview($profile) {
  drupal_set_title(t('Revisions for @title', array('@title' => $profile->label())));
  return drupal_get_form('profile2_diff_profile2_revisions', $profile);
}

/**
 * Input form to select two revisions.
 *
 * @param $viewed_profile
 *   Profile whose revisions are displayed for selection.
 */
function profile2_diff_profile2_revisions($form, $form_state, $viewed_profile) {
/*
  $revision_list = profile2_revision_list($viewed_profile);
  $revision_count = count($revision_list);

  if ($revision_count > REVISION_LIST_SIZE) {
    // If the list of revisions is longer than the number shown on one page split the array.
    $page = isset($_GET['page']) ? $_GET['page'] : '0';
    $revision_chunks = array_chunk(profile2_revision_list($viewed_user), REVISION_LIST_SIZE);
    $revisions = $revision_chunks[$page];
    // Set up global pager variables as would 'pager_query' do.
    // These variables are then used in the theme('pager') call later.
    global $pager_page_array, $pager_total, $pager_total_items;
    $pager_total_items[0] = $revision_count;
    $pager_total[0] = ceil($revision_count / REVISION_LIST_SIZE);
    $pager_page_array[0] = max(0, min($page, ((int)$pager_total[0]) - 1));
  }
  else {
    $revisions = $revision_list;
  }*/

  $data = profile2_revision_list_build($viewed_profile);

  // Each element of $data is an array containing:
  // 'row': an array keyed by the revision-id, containing an array keyed 'data' containing markup.
  // 'operations: an array containing revert and delete links.

  foreach ($data as $item) {
    $row = $item['row'];
    $vid = key($row);
    $revision_ids[$vid] = '';
    $form['info'][$vid] = array(
      '#markup' => $row[$vid]['data'],
      '#revision' => $row[$vid]['revision'],
    );
    $operations = array();
    foreach ($item['operations'] as $operation) {
      if (!is_array($operation)) {
        $operations[] = array('#markup' => $operation);
      }
    }
    $form['operations'][$vid] = $operations;
  }
  $new_vid = key($revision_ids);
  next($revision_ids);
  $old_vid = key($revision_ids);
  $form['diff']['old'] = array(
    '#type' => 'radios',
    '#options' => $revision_ids,
    '#default_value' => $old_vid
  );
  $form['diff']['new'] = array(
    '#type' => 'radios',
    '#options' => $revision_ids,
    '#default_value' => $new_vid
  );
  $form['profile'] = array(
    '#type' => 'value',
    '#value' => $viewed_profile,
  );
  $form['submit'] = array('#type' => 'submit', '#value' => t('Compare'));

//   if ($revision_count > REVISION_LIST_SIZE) {
//     $form['#suffix'] = theme('pager', NULL, REVISION_LIST_SIZE, 0);
//   }
  // use the diff module's theme function.
  $form['#attached'] = diff_build_attachments(TRUE);
  $form['#theme'] = 'diff_node_revisions';

  return $form;
}

/**
 * Submit code for input form to select two revisions.
 */
function profile2_diff_profile2_revisions_submit($form, &$form_state) {
  // the ids are ordered so the old revision is always on the left
  $old_vid = min($form_state['values']['old'], $form_state['values']['new']);
  $new_vid = max($form_state['values']['old'], $form_state['values']['new']);
  $link_base = _profile2_revision_base_path($form_state['values']['profile'], TRUE);
  $form_state['redirect'] = "$link_base/diff/{$old_vid}/{$new_vid}";
}

/**
 * Validation for input form to select two revisions.
 */
function profile2_diff_profile2_revisions_validate($form, &$form_state) {
  $old_vid = $form_state['values']['old'];
  $new_vid = $form_state['values']['new'];
  if ($old_vid==$new_vid || !$old_vid || !$new_vid) {
    form_set_error('diff', t('Select different revisions to compare.'));
  }
}

/**
 * @see profile2_diff_diffs_show
 */
function profile2_diff_diffs_show_by_user($profile_type, $pr_user, $old_vid, $new_vid) {
  return profile2_diff_diffs_show(profile2_load_by_user($pr_user, $profile_type), $old_vid, $new_vid);
}

/**
 * Create output string for a comparison of 'profile' between
 * versions 'old_vid' and 'new_vid'.
 *
 * @param $profile
 *   profile on which to perform comparison
 * @param $old_vid
 *   Version ID of the old revision.
 * @param $new_vid
 *   Version ID of the new revision.
 */
function profile2_diff_diffs_show($profile, $old_vid, $new_vid) {
  module_load_include('inc', 'diff', 'diff.pages');
  $uid = $profile->uid;
  $pid = $profile->pid;

  $profile2_revisions = profile2_revision_list($profile);
  $old_rev = $profile2_revisions[$old_vid];
  $new_rev = $profile2_revisions[$new_vid];

  // mode-dependent base for links
  $link_base = _profile2_revision_base_path($profile, TRUE);

  // Generate table header (date, profile-name, logmessage).
  $old_header = t('!date by !username', array(
    '!date' => l(format_date($old_rev->timestamp), "$link_base/view/$old_vid"),
    '!username' => theme('username', array('account' => $old_rev)),
  ));
  $new_header = t('!date by !username', array(
    '!date' => l(format_date($new_rev->timestamp), "$link_base/view/$new_vid"),
    '!username' => theme('username', array('account' => $new_rev)),
  ));

  $old_log = $old_rev->log != '' ? '<p class="revision-log">'. filter_xss($old_rev->log) .'</p>' : '';
  $new_log = $new_rev->log != '' ? '<p class="revision-log">'. filter_xss($new_rev->log) .'</p>' : '';

  // Generate previous diff/next diff links.
  $next_vid = _diff_get_next_vid($profile2_revisions, $new_vid);
  if ($next_vid) {
    $next_link = l(t('next diff >'), "$link_base/diff/$new_vid/$next_vid");
  }
  else {
    $next_link = '';
  }
  $prev_vid = _diff_get_previous_vid($profile2_revisions, $old_vid);
  if ($prev_vid) {
    $prev_link = l(t('< previous diff'), "$link_base/diff/$prev_vid/$old_vid");
  }
  else {
    $prev_link = '';
  }

  $cols = _diff_default_cols();
  $header = _diff_default_header($old_header, $new_header);
  $rows = array();
  if ($old_log || $new_log) {
    $rows[] = array(
      array(
        'data' => $old_log,
        'colspan' => 2
      ),
      array(
        'data' => $new_log,
        'colspan' => 2
      )
    );
  }
  $rows[] = array(
    array(
      'data' => $prev_link,
      'class' => array('diff-prevlink'),
      'colspan' => 2
    ),
    array(
      'data' => $next_link,
      'class' => array('diff-nextlink'),
      'colspan' => 2
    )
  );
  $old_profile = profile2_load($pid, $old_vid);
  $new_profile = profile2_load($pid, $new_vid);
  $rows = array_merge($rows, _profile2_diff_body_rows($old_profile, $new_profile));
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('class' => array('diff')),
    'cols' => $cols
  ));
  $profile_view = profile2_view($new_profile, 'diff_standard');
  $profile_output = drupal_render($profile_view);
  $stripped_output = trim(strip_tags($profile_output));
  // Omit header for profile display if no rendered output, apart from label.
  if (!empty($stripped_output) && $stripped_output != $new_profile->label()) {
    if ($profile->vid == $new_vid) {
      $output .= '<div class="diff-section-title">'. t('Current revision:') .'</div>';
    }
    else {
      $output .= '<div class="diff-section-title">'. t('Revision of !new_date:', array('!new_date' => format_date($new_profile->revision_timestamp))) .'</div>';
    }
    $output .= $profile_output;
  }
  return $output;
}

/**
 * Creates an array of rows which represent a diff between $old_profile and $new_profile.
 * The rows can be used via theme('diff_table') to be displayed.
 *
 * @param $old_profile
 *   profile for comparison which will be displayed on the left side.
 * @param $new_profile
 *   profile for comparison which will be displayed on the right side.
 */
function _profile2_diff_body_rows($old_profile, $new_profile) {
  // make use of the user comparison functions in the diff module.
  module_load_include('inc', 'diff', 'diff.pages');
  $context = array(
    'states' => array(variable_get('diff_default_state_profile2', 'raw')),
    'view_mode' => 'diff_standard',
  );
  return diff_entity_body_rows('profile2', $old_profile, $new_profile, $context);
}

/**
 * Show the inline diff of a given profile object v. the profile with $old_vid.
 * If $old_vid = 0 returns the normally rendered content of the profile object.
 * If metadata is TRUE a header will be added with a legend explaining the color code.
 * This function returns HTML code.
 */
function profile2_diff_inline_show($profile, $old_vid = 0, $metadata = TRUE) {
  $new_profile = /*clone*/ $profile;
  $content = $new_profile->buildContent();
  $new = drupal_render($content);
  module_load_include('inc', 'diff', 'diff.pages');
  if ($old_vid) {
    $old_profile = profile2_load($profile->pid, $old_vid);
    $content = $old_profile->buildContent();
    $old = drupal_render($content);
    $output = $metadata ? theme('profile2_diff_inline_metadata', array('profile' => $new_profile)) : '';
    $output .= diff_get_inline($old, $new);
    return $output;
  }
  return $new;
}
