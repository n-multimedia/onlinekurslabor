<?php
/**
 * @file
 * nm_section_courses_features.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function nm_section_courses_features_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:courses_course:course-administrator'.
  $roles['node:courses_course:course-administrator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'courses_course',
    'name' => 'course-administrator',
  );

  // Exported OG Role: 'node:courses_course:kurs-dozent'.
  $roles['node:courses_course:kurs-dozent'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'courses_course',
    'name' => 'kurs-dozent',
  );

  // Exported OG Role: 'node:courses_course:kurs-student'.
  $roles['node:courses_course:kurs-student'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'courses_course',
    'name' => 'kurs-student',
  );

  // Exported OG Role: 'node:courses_course:kurs-tutor'.
  $roles['node:courses_course:kurs-tutor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'courses_course',
    'name' => 'kurs-tutor',
  );

  return $roles;
}
