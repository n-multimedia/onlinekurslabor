<?php
/**
 * @file
 * nm_general_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nm_general_features_user_default_roles() {
  $roles = array();

  // Exported role: Moderator.
  $roles['Moderator'] = array(
    'name' => 'Moderator',
    'weight' => 4,
    'machine_name' => 'moderator',
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 5,
    'machine_name' => 'administrator',
  );

  return $roles;
}
