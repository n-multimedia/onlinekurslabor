<?php

/**
 * @file
 * nm_section_courses_features.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function nm_section_courses_features_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:courses_course:add user'
  $permissions['node:courses_course:add user'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:administer group'
  $permissions['node:courses_course:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:approve and deny subscription'
  $permissions['node:courses_course:approve and deny subscription'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_docs content'
  $permissions['node:courses_course:create courses_docs content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_generic_task content'
  $permissions['node:courses_course:create courses_generic_task content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_generic_task_solution content'
  $permissions['node:courses_course:create courses_generic_task_solution content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-student' => 'kurs-student',
      'kurs-tutor' => 'kurs-tutor',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_group content'
  $permissions['node:courses_course:create courses_group content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_news content'
  $permissions['node:courses_course:create courses_news content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:create forum content'
  $permissions['node:courses_course:create forum content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-student' => 'kurs-student',
      'kurs-tutor' => 'kurs-tutor',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_docs content'
  $permissions['node:courses_course:delete any courses_docs content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_generic_task content'
  $permissions['node:courses_course:delete any courses_generic_task content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_generic_task_solution content'
  $permissions['node:courses_course:delete any courses_generic_task_solution content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_group content'
  $permissions['node:courses_course:delete any courses_group content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_news content'
  $permissions['node:courses_course:delete any courses_news content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any forum content'
  $permissions['node:courses_course:delete any forum content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_docs content'
  $permissions['node:courses_course:delete own courses_docs content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_generic_task content'
  $permissions['node:courses_course:delete own courses_generic_task content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_generic_task_solution content'
  $permissions['node:courses_course:delete own courses_generic_task_solution content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_group content'
  $permissions['node:courses_course:delete own courses_group content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_news content'
  $permissions['node:courses_course:delete own courses_news content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own forum content'
  $permissions['node:courses_course:delete own forum content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:manage members'
  $permissions['node:courses_course:manage members'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:manage permissions'
  $permissions['node:courses_course:manage permissions'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:manage roles'
  $permissions['node:courses_course:manage roles'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:moderate'
  $permissions['node:courses_course:moderate'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:subscribe'
  $permissions['node:courses_course:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:subscribe without approval'
  $permissions['node:courses_course:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:unsubscribe'
  $permissions['node:courses_course:unsubscribe'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_docs content'
  $permissions['node:courses_course:update any courses_docs content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_generic_task content'
  $permissions['node:courses_course:update any courses_generic_task content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_generic_task_solution content'
  $permissions['node:courses_course:update any courses_generic_task_solution content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_group content'
  $permissions['node:courses_course:update any courses_group content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_news content'
  $permissions['node:courses_course:update any courses_news content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update any forum content'
  $permissions['node:courses_course:update any forum content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update group'
  $permissions['node:courses_course:update group'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_docs content'
  $permissions['node:courses_course:update own courses_docs content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_generic_task content'
  $permissions['node:courses_course:update own courses_generic_task content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_generic_task_solution content'
  $permissions['node:courses_course:update own courses_generic_task_solution content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-student' => 'kurs-student',
      'kurs-tutor' => 'kurs-tutor',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_group content'
  $permissions['node:courses_course:update own courses_group content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_news content'
  $permissions['node:courses_course:update own courses_news content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-tutor' => 'kurs-tutor',
    ),
  );

  // Exported og permission: 'node:courses_course:update own forum content'
  $permissions['node:courses_course:update own forum content'] = array(
    'roles' => array(
      'kurs-dozent' => 'kurs-dozent',
      'kurs-student' => 'kurs-student',
      'kurs-tutor' => 'kurs-tutor',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:add user'
  $permissions['node:courses_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:administer group'
  $permissions['node:courses_group:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:approve and deny subscription'
  $permissions['node:courses_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:create courses_docs content'
  $permissions['node:courses_group:create courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create courses_generic_task content'
  $permissions['node:courses_group:create courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create courses_generic_task_solution content'
  $permissions['node:courses_group:create courses_generic_task_solution content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:create courses_group content'
  $permissions['node:courses_group:create courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create courses_news content'
  $permissions['node:courses_group:create courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create forum content'
  $permissions['node:courses_group:create forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_docs content'
  $permissions['node:courses_group:delete any courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_generic_task content'
  $permissions['node:courses_group:delete any courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_generic_task_solution content'
  $permissions['node:courses_group:delete any courses_generic_task_solution content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_group content'
  $permissions['node:courses_group:delete any courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_news content'
  $permissions['node:courses_group:delete any courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any forum content'
  $permissions['node:courses_group:delete any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_docs content'
  $permissions['node:courses_group:delete own courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_generic_task content'
  $permissions['node:courses_group:delete own courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_generic_task_solution content'
  $permissions['node:courses_group:delete own courses_generic_task_solution content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_group content'
  $permissions['node:courses_group:delete own courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_news content'
  $permissions['node:courses_group:delete own courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own forum content'
  $permissions['node:courses_group:delete own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:manage members'
  $permissions['node:courses_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:manage permissions'
  $permissions['node:courses_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:manage roles'
  $permissions['node:courses_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:moderate'
  $permissions['node:courses_group:moderate'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:subscribe'
  $permissions['node:courses_group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:subscribe without approval'
  $permissions['node:courses_group:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:unsubscribe'
  $permissions['node:courses_group:unsubscribe'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:update any courses_docs content'
  $permissions['node:courses_group:update any courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any courses_generic_task content'
  $permissions['node:courses_group:update any courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any courses_generic_task_solution content'
  $permissions['node:courses_group:update any courses_generic_task_solution content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:update any courses_group content'
  $permissions['node:courses_group:update any courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any courses_news content'
  $permissions['node:courses_group:update any courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any forum content'
  $permissions['node:courses_group:update any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update group'
  $permissions['node:courses_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update own courses_docs content'
  $permissions['node:courses_group:update own courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own courses_generic_task content'
  $permissions['node:courses_group:update own courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own courses_generic_task_solution content'
  $permissions['node:courses_group:update own courses_generic_task_solution content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:update own courses_group content'
  $permissions['node:courses_group:update own courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own courses_news content'
  $permissions['node:courses_group:update own courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own forum content'
  $permissions['node:courses_group:update own forum content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
