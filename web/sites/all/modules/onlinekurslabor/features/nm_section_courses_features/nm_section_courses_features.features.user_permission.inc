<?php
/**
 * @file
 * nm_section_courses_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nm_section_courses_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer advanced forum'.
  $permissions['administer advanced forum'] = array(
    'name' => 'administer advanced forum',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'administer forums'.
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forum',
  );

  // Exported permission: 'create courses_course content'.
  $permissions['create courses_course content'] = array(
    'name' => 'create courses_course content',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create courses_docs content'.
  $permissions['create courses_docs content'] = array(
    'name' => 'create courses_docs content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create courses_generic_task content'.
  $permissions['create courses_generic_task content'] = array(
    'name' => 'create courses_generic_task content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create courses_generic_task_solution content'.
  $permissions['create courses_generic_task_solution content'] = array(
    'name' => 'create courses_generic_task_solution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create courses_group content'.
  $permissions['create courses_group content'] = array(
    'name' => 'create courses_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create courses_news content'.
  $permissions['create courses_news content'] = array(
    'name' => 'create courses_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any courses_course content'.
  $permissions['delete any courses_course content'] = array(
    'name' => 'delete any courses_course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any courses_docs content'.
  $permissions['delete any courses_docs content'] = array(
    'name' => 'delete any courses_docs content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any courses_generic_task content'.
  $permissions['delete any courses_generic_task content'] = array(
    'name' => 'delete any courses_generic_task content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any courses_generic_task_solution content'.
  $permissions['delete any courses_generic_task_solution content'] = array(
    'name' => 'delete any courses_generic_task_solution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any courses_group content'.
  $permissions['delete any courses_group content'] = array(
    'name' => 'delete any courses_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any courses_news content'.
  $permissions['delete any courses_news content'] = array(
    'name' => 'delete any courses_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own courses_course content'.
  $permissions['delete own courses_course content'] = array(
    'name' => 'delete own courses_course content',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own courses_docs content'.
  $permissions['delete own courses_docs content'] = array(
    'name' => 'delete own courses_docs content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own courses_generic_task content'.
  $permissions['delete own courses_generic_task content'] = array(
    'name' => 'delete own courses_generic_task content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own courses_generic_task_solution content'.
  $permissions['delete own courses_generic_task_solution content'] = array(
    'name' => 'delete own courses_generic_task_solution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own courses_group content'.
  $permissions['delete own courses_group content'] = array(
    'name' => 'delete own courses_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own courses_news content'.
  $permissions['delete own courses_news content'] = array(
    'name' => 'delete own courses_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any courses_course content'.
  $permissions['edit any courses_course content'] = array(
    'name' => 'edit any courses_course content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any courses_docs content'.
  $permissions['edit any courses_docs content'] = array(
    'name' => 'edit any courses_docs content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any courses_generic_task content'.
  $permissions['edit any courses_generic_task content'] = array(
    'name' => 'edit any courses_generic_task content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any courses_generic_task_solution content'.
  $permissions['edit any courses_generic_task_solution content'] = array(
    'name' => 'edit any courses_generic_task_solution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any courses_group content'.
  $permissions['edit any courses_group content'] = array(
    'name' => 'edit any courses_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any courses_news content'.
  $permissions['edit any courses_news content'] = array(
    'name' => 'edit any courses_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any student profile'.
  $permissions['edit any student profile'] = array(
    'name' => 'edit any student profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own courses_course content'.
  $permissions['edit own courses_course content'] = array(
    'name' => 'edit own courses_course content',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own courses_docs content'.
  $permissions['edit own courses_docs content'] = array(
    'name' => 'edit own courses_docs content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own courses_generic_task content'.
  $permissions['edit own courses_generic_task content'] = array(
    'name' => 'edit own courses_generic_task content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own courses_generic_task_solution content'.
  $permissions['edit own courses_generic_task_solution content'] = array(
    'name' => 'edit own courses_generic_task_solution content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own courses_group content'.
  $permissions['edit own courses_group content'] = array(
    'name' => 'edit own courses_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own courses_news content'.
  $permissions['edit own courses_news content'] = array(
    'name' => 'edit own courses_news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own student profile'.
  $permissions['edit own student profile'] = array(
    'name' => 'edit own student profile',
    'roles' => array(
      'Student' => 'Student',
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any student profile'.
  $permissions['view any student profile'] = array(
    'name' => 'view any student profile',
    'roles' => array(
      'Student' => 'Student',
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view forum statistics'.
  $permissions['view forum statistics'] = array(
    'name' => 'view forum statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'view last edited notice'.
  $permissions['view last edited notice'] = array(
    'name' => 'view last edited notice',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'view own student profile'.
  $permissions['view own student profile'] = array(
    'name' => 'view own student profile',
    'roles' => array(
      'Student' => 'Student',
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
