<?php

function profile2_revisions_view_for_user($type, $account) {
  return profile2_revision_overview(profile2_load_by_user($account, $type));
}

function profile2_tab_revision_view($type, $account, $vid) {
  $current_profile = profile2_load_by_user($account, $type);
  $profile_revision = profile2_load($current_profile->pid, $vid);
  return profile2_view($profile_revision, 'revision');
}

function profile2_tab_get_revision_revert($type, $account, $vid) {
  $current_profile = profile2_load_by_user($account, $type);
  $profile_revision = profile2_load($current_profile->pid, $vid);
  return drupal_get_form('profile2_revision_revert_confirm', $profile_revision);
}

function profile2_tab_get_revision_delete($type, $account, $vid) {
  $current_profile = profile2_load_by_user($account, $type);
  $profile_revision = profile2_load($current_profile->pid, $vid);
  return drupal_get_form('profile2_revision_delete_confirm', $profile_revision);
}
