<?php
/**
 * @file
 * section_projects_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function section_projects_features_user_default_roles() {
  $roles = array();

  // Exported role: Kooperationspartner.
  $roles['Kooperationspartner'] = array(
    'name' => 'Kooperationspartner',
    'weight' => 9,
    'machine_name' => 'kooperationspartner',
  );

  return $roles;
}
