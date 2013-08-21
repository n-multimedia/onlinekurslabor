<?php

/**
 * @file
 * Plugin to handle the 'profile2' content type which allows individual profiles
 * to be embedded into a panel.
 */


/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('User Profile (Profile2)'),
  'description' => t('The profile of a user.'),
  'required context' => new ctools_context_required(t('User'), 'entity:user'),
  'category' => t('User'),
  'defaults' => array('type' => 'main', 'build_mode' => 'account'),
);

/**
 * Render the user profile2 content type.
 */
function profile2_profile2_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = isset($context->data->uid) ? clone($context->data) : NULL;
  if (!$account) {
    return NULL;
  }
  // Loads and check access for requested profile.
  $profile = profile2_load_by_user($account, $conf['type']);
  if (empty($profile) || !profile2_access('view', $profile)) {
    return NULL;
  }

  $block = new stdClass();
  $block->module = 'profile2';
  $block->title = check_plain($profile->label);
  $block->content = drupal_render($profile->view($conf['build_mode']));
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function profile2_profile2_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" user custom profile', array('@s' => $context->identifier));
}

/**
 * Display the administrative information for a profile2 pane.
 */
function profile2_profile2_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->module = 'profile2';
  // Title should display a profile type label.
  if ($profile = profile2_get_types($conf['type'])) {
    $block->title = check_plain($profile->label);
  }
  else {
    $block->title = t('Deleted/missing profile type @type', array('@type' => $conf['type']));
  }
  // Content dispays assigned build mode.
  $block->content = t('Build mode: @mode', array('@mode' => _profile2_build_mode_label($conf['build_mode'])));
  return $block;
}

/**
 * The submit form stores the data in $conf.
 */
function profile2_profile2_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * The form to add or edit a profile as content.
 */
function profile2_profile2_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // Select type of profile to display.
  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Select Profile2 Type'),
    '#options' => _profile2_types_options(),
    '#default_value' => $conf['type'],
  );
  // Select a build mode for the profile type.
  $form['build_mode'] = array(
    '#title' => t('Build mode'),
    '#type' => 'select',
    '#description' => t('Select a build mode for this profile.'),
    '#options' => _profile2_build_options(),
    '#default_value' => $conf['build_mode'],
  );
  return $form;
}

/**
 * Helper function : build the list of profile types for the 'edit' form.
 */
function _profile2_types_options() {
  $type_list = array();

  foreach (profile2_get_types() as $type => $info) {
    $type_list[$type] = $info->label;
  }

  return $type_list;
}

/**
 * Helper function : build the list of build modes for profile types.
 */
function _profile2_build_options($build_mode = NULL) {
  $build_mode_options = array();

  $entity = entity_get_info('profile2');
  foreach ($entity['view modes'] as $mode => $option) {
    $build_mode_options[$mode] = $option['label'];
  }

  return $build_mode_options;
}

/**
 * Helper function : build the list of build modes for profile types.
 */
function _profile2_build_mode_label($build_mode = 'account') {
  $modes = _profile2_build_options();
  if (isset($modes[$build_mode])) {
    return $modes[$build_mode];
  }
  else {
    return $modes['account'];
  }
}
