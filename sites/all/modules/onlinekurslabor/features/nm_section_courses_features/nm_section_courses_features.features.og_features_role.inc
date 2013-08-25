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

  return $roles;
}
