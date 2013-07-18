<?php
/**
 * @file
 * Provide user interface for changing workflow state.
 */

/**
 * Menu callback. Display workflow summary of a node.
 */
function workflow_tab_page($node = NULL) {
  drupal_set_title($node->title);
  $workflow = workflow_get_workflow_type_map_by_type($node->type);
  foreach (workflow_get_workflow_states() as $data) {
    $states[$data->sid] = check_plain(t($data->state));
  }
  $deleted_states = array();
  $options = array('status' => 0);
  foreach (workflow_get_workflow_states($options) as $data) {
    $deleted_states[$data->sid] = check_plain(t($data->state));
  }
  $current = workflow_node_current_state($node);

  // theme_workflow_history_current_state() must run state through check_plain().
  $current_state = theme('workflow_history_current_state', array('state_name' => $states[$current]));

  $output = theme('workflow_current_state', array('state' => $states[$current]));

  // Show the form to allow state changing.
  // But only if we are not at the terminal state.
  $choices = workflow_field_choices($node);
  if (count($choices) != 0 || count($choices) != 1 || $current != key($choices)) {
    $form = drupal_get_form('workflow_tab_form', $node, $workflow->wid, $states, $current);
    $output .= drupal_render($form);
  }

  $rows = array();
  foreach (workflow_get_workflow_node_history_by_nid($node->nid) as $history) {
    if ($history->sid == $current && !isset($deleted_states[$history->sid]) && !isset($current_themed)) {
      // Theme the current state differently so it stands out.
      $state_name = theme('workflow_history_current_state',  array('state_name' => $states[$history->sid]));
      // Make a note that we have themed the current state; other times in the history
      // of this node where the node was in this state do not need to be specially themed.
      $current_themed = TRUE;
    }
    elseif (isset($deleted_states[$history->sid])) {
      // The state has been deleted, but we include it in the history.
      $state_name = theme('workflow_deleted_state', array('deleted_state' => $deleted_states[$history->sid]));
      $footer_needed = TRUE;
    }
    else {
      // Regular state.
      $state_name = check_plain(t($states[$history->sid]));
    }
    if (isset($deleted_states[$history->old_sid])) {
      $old_state_name = theme('workflow_deleted_state', array('deleted_state' => $deleted_states[$history->old_sid]));
      $footer_needed = TRUE;
    }
    elseif (isset($states[$history->old_sid])) {
      $old_state_name = check_plain(t($states[$history->old_sid]));
    }
    else {
      $old_state_name = '*';
    }

    $variables = array(
        'history' => $history,
        'old_sid' => $history->old_sid,
        'old_state_name' => $old_state_name,
        'sid' => $history->sid,
        'state_name' => $state_name,
        );

    // Allow other modules to modify the row.
    drupal_alter('workflow_history', $variables);

    $rows[] = theme('workflow_history_table_row', $variables);
  }

  // Mark the first and last rows.
  $rows[0]['class'][] = 'first';
  $last = count($rows) - 1;
  $rows[$last]['class'][] = 'last';

  // Only display the table if there's anything in it.
  if ($rows) {
    $output .= theme('workflow_history_table', array('rows' => $rows, 'footer' => !empty($footer_needed)));
    $output .= theme('pager', array('tags' => variable_get('workflow_states_per_page', 20)));
  }
  return $output;
}

/*
 * Theme one workflow history table row.
 *
 * $old_state_name and $state_name must be run through check_plain(t()) prior
 * to calling this theme function.
 */
function theme_workflow_history_table_row($variables) {
  $row = array();
  $old_state_name = $variables['old_state_name'];
  $state_name = $variables['state_name'];
  $history = $variables['history'];
  $row = array(
    'data' => array(
      format_date($history->stamp),
      $old_state_name,
      $state_name,
      theme('username', array('account' => $history)),
      check_markup($history->comment, filter_default_format()),
      ),
    'class' => array('workflow_history_row'),
    );

  if (!empty($variables['extra'])) {
    $row['data'][] = $variables['extra'];
  }

  return $row;
}

/*
 * Theme entire workflow history table.
 */
function theme_workflow_history_table($variables) {
  $rows = $variables['rows'];
  $footer = $variables['footer'];
  $headers = array(t('Date'), t('Old State'), t('New State'), t('By'), t('Comment'));
  $output = theme('table', array('header' => $headers, 'rows' => $rows, 'caption' => t('Workflow History')));
  if ($footer) {
    $output .= t('*State is no longer available.');
  }
  return $output;
}

/**
 * Theme the current state in the workflow history table.
 */
function theme_workflow_history_current_state($variables) {
  return '<strong>' . check_plain(t($variables['state_name'])) . '</strong>';
}

/**
 * Theme a deleted state in the workflow history table.
 */
function theme_workflow_deleted_state($variables) {
  return check_plain(t($variables['state_name'])) . '*';
}

/**
 * Form builder. Allow workflow state change and scheduling from workflow tab.
 *
 * @param $node
 *   Node for which workflow information will be displayed.
 * @param $wid
 *   ID of workflow to display.
 * @param $states
 *   Array of states for the workflow.
 * @param $current
 *   Current workflow state of this node.
 * @return
 *   Form definition array.
 */
function workflow_tab_form($form, $form_state, $node, $wid, $states, $current) {
  // Let's make sure we should be here.
  if (workflow_node_tab_access($node) === FALSE) {
    return;
  }

  $form['#tab'] = TRUE;
  $choices = workflow_field_choices($node);
  $min = $states[$current] == t('(creation)') ? 1 : 2;

  // Invoke a callback indicating a transition is about to occur. Modules
  // may veto the transition by returning FALSE.
  // In this case, the transition is not about to occur, but we want to
  // know if it should be dropped from the list of choices.
  if (empty($choices)) {
    return;
  };
  foreach ($choices as $sid => $name) {
    if ($current == $sid) {
      continue;
    }
    $result = module_invoke_all('workflow', 'transition pre', $current, $sid, $node);
    // Stop if a module says so.
    if (in_array(FALSE, $result)) {
      // if vetoed, remove from list.
      unset($choices[$sid]);
    }
  }

  // Only build form if user has possible target state(s).
  if (count($choices) >= $min) {
    $workflow = workflow_get_workflow_type_map_by_type($node->type);
    $workflow = workflow_get_workflows_by_wid($workflow->wid);

    $form['#wf'] = $workflow;
    $form['#choices'] = $choices;

    $name = check_plain((t($workflow->name)));
    $timestamp = '';
    $comment = '';

    // See if scheduling information is present.
    if (!empty($node->workflow_scheduled_timestamp) && !empty($node->workflow_scheduled_sid)) {
      global $user;
      if (variable_get('configurable_timezones', 1) && $user->uid && drupal_strlen($user->timezone)) {
        $timezone = $user->timezone;
      }
      else {
        $timezone = variable_get('date_default_timezone', 0);
      }
      // The default value should be the upcoming sid.
      $current = $node->workflow_scheduled_sid;
      $timestamp = $node->workflow_scheduled_timestamp;
      $comment = $node->workflow_scheduled_comment;
    }

    // Include the same form elements here that are included on a
    // regular node editing page. $form is modified by reference.
    workflow_node_form($form, $form_state, t('Change @name state', array('@name' => $name)), $name, $current, $choices, $timestamp, $comment);

    $form['node'] = array(
      '#type' => 'value',
      '#value' => $node,
      );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Update workflow'),
      );
  }
  return $form;
}

/**
 * Submit handler for the form on the workflow tab.
 *
 * @see workflow_tab_form()
 */
function workflow_tab_form_submit($form, &$form_state) {
  // The entire node object was stashed in the form.
  $node = $form_state['values']['node'];

  if (isset($form_state['values']['workflow'])) {
    $node->workflow = $form_state['values']['workflow'];
    $node->workflow_comment = isset($form_state['values']['workflow_comment']) ?
      $form_state['values']['workflow_comment'] : '';

    if (!empty($form_state['values']['workflow_scheduled'])) {
      $node->workflow_scheduled = $form_state['values']['workflow_scheduled'];
    }
    if (!empty($form_state['values']['workflow_scheduled_date'])) {
      $node->workflow_scheduled_date = $form_state['values']['workflow_scheduled_date'];
    }
    if (!empty($form_state['values']['workflow_scheduled_hour'])) {
      $node->workflow_scheduled_hour = $form_state['values']['workflow_scheduled_hour'];
    }
    if (!empty($form_state['values']['workflow_scheduled_timezone'])) {
      $node->workflow_scheduled_timezone = $form_state['values']['workflow_scheduled_timezone'];
    }
  }
  // ALERT: Rules that use node_save to check the node transition are going to be missed if
  // the tab form is used to check for the change. It is *always* better practice to use
  // the transition change itself as your value to check for changes with Rules and other
  // behaviors. Do NOT rely on node_save() to drive transition changes.
  workflow_transition($node, $node->workflow);
}
