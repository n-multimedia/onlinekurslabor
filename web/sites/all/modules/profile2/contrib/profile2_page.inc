<?php

/**
 * @file
 * Adds separate pages for viewing and editing profiles.
 */

/**
 * Shows the profile page for the current user.
 *
 * @see user_page()
 */
function profile2_page_own($base_path) {
  global $user;
  if ($user->uid) {
    menu_set_active_item($base_path . '/' . $user->uid);
    return menu_execute_active_handler(NULL, FALSE);
  }
  else {
    return drupal_get_form('user_login');
  }
}

/**
 * Re-direct a menu item to path based on the profile base-path.
 */
function profile2_page_goto($profile, $sub_path = NULL) {
  $path = profile2_page_get_base_path($profile->type());
  $path .= "/{$profile->uid}";
  if ($sub_path)  {
    $path .= "/$sub_path";
  }
  drupal_goto($path);
}

/**
 * Profile view page.
 */
function profile2_page_view($profile) {
  // If there is only one breadcrumb (Home), add the user account link to it.
  $breadcrumb = drupal_get_breadcrumb();
  if (count($breadcrumb) == 1) {
    $account = user_load($profile->uid);
    $breadcrumb[] = l($account->name, "user/{$account->uid}");
    drupal_set_breadcrumb($breadcrumb);
  }
  drupal_set_title($profile->label());
  return $profile->view('page', NULL, TRUE);
}

/**
 * The profile edit form.
 */
function profile2_form($form, &$form_state, $profile) {
  global $user;
  if (empty($form_state['profiles'])) {
    $form_state['profiles'][$profile->type] = $profile;
  }
  // Prevent invoking the same hooks twice, so tell profile2_attach_form() to
  // skip invoking the hooks.
  $form_state['profile2_skip_hook'] = TRUE;
  profile2_attach_form($form, $form_state);

  // If using edit title mode, add a field for the title and validate function.
  $type = profile2_get_types($profile->type);
  if (!empty($type->data['edit_label'])) {
    $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#description' => t('Enter a title for this profile'),
      '#required' => TRUE,
      '#default_value' => $profile->label,
      '#maxlength' => 255,
      '#weight' => -5,
    );
    $form['#validate'][] = 'profile2_form_validate';
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 40,
  );
  if (user_access('administer profiles') || $user->uid === $profile->uid &&
      user_access("delete own {$profile->type} profile")) {
    $delete_button_label = t('Delete profile');
  }
  if (empty($profile->is_new) && !empty($delete_button_label)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => $delete_button_label,
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('profile2_form_submit_delete')
    );
  }
  $form['#submit'][] = 'profile2_form_submit';
  return $form;
}

/**
 * Profile form validate handler.
 *
 * Set the profile label from the entered title.
 */
function profile2_form_validate($form, &$form_state) {
  $profile = reset($form_state['profiles']);
  $profile->label = $form_state['values']['title'];
}

/**
 * Profile form submit handler.
 */
function profile2_form_submit($form, &$form_state) {
  // The profile is being saved by profile2_form_submit_handler().
  $form_state['redirect'] = $form_state['profile2']->path();
}

/**
 * Profile form submit handler for the delete button.
 */
function profile2_form_submit_delete($form, &$form_state) {
  $form_state['redirect'] = $form_state['profile2']->path() . '/delete';
}

/**
 * Confirm form for deleting a profile.
 */
function profile2_page_delete_confirm_form($form, &$form_state, $profile) {
  global $user;
  $form_state += array('profile2' => $profile);
  $type = profile2_get_types($profile->type);
  if (isset($profile->uid) && $profile->uid === $user->uid) {
    $confirm_question = t('Are you sure you want to delete your own %label profile ?',
      array('%label' => $type->getTranslation('label')));
  }
  elseif (user_access('administer profiles')) {
    $user_account = user_load($profile->uid);
    if (!empty($user_account)) {
      $confirm_question = t("Are you sure you want to delete profile %label of user %user?",
        array('%label' => $type->getTranslation('label'), '%user' => $user_account->name));
    }
  }
  return confirm_form($form, $confirm_question, $profile->path());
}

function profile2_page_delete_confirm_form_submit($form, &$form_state) {
  $profile = $form_state['profile2'];
  $type = profile2_get_types($profile->type);
  $profile->delete();
  drupal_set_message(t('Deleted %label.', array('%label' => $type->getTranslation('label'))));
  $form_state['redirect'] = 'user/' . $profile->uid;
}
