<?php
/**
 * @file
 * nm_section_courses_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nm_section_courses_features_user_default_roles() {
  $roles = array();

  // Exported role: Dozent.
  $roles['Dozent'] = array(
    'name' => 'Dozent',
    'weight' => 3,
    'machine_name' => 'dozent',
  );

  // Exported role: Student.
  $roles['Student'] = array(
    'name' => 'Student',
    'weight' => 2,
    'machine_name' => 'student',
  );

  return $roles;
}
