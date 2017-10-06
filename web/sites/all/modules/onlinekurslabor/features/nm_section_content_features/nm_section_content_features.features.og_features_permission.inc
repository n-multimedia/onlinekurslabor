<?php
/**
 * @file
 * nm_section_content_features.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function nm_section_content_features_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:content_domain:add user'
  $permissions['node:content_domain:add user'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:administer group'
  $permissions['node:content_domain:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:approve and deny subscription'
  $permissions['node:content_domain:approve and deny subscription'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create content_chapter content'
  $permissions['node:content_domain:create content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create content_multiple_choice content'
  $permissions['node:content_domain:create content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create content_question_and_answer content'
  $permissions['node:content_domain:create content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create forum content'
  $permissions['node:content_domain:create forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:delete any content_chapter content'
  $permissions['node:content_domain:delete any content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any content_multiple_choice content'
  $permissions['node:content_domain:delete any content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any content_question_and_answer content'
  $permissions['node:content_domain:delete any content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any forum content'
  $permissions['node:content_domain:delete any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:delete own content_chapter content'
  $permissions['node:content_domain:delete own content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own content_multiple_choice content'
  $permissions['node:content_domain:delete own content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own content_question_and_answer content'
  $permissions['node:content_domain:delete own content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own forum content'
  $permissions['node:content_domain:delete own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:edit any master profile'
  $permissions['node:content_domain:edit any master profile'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:manage members'
  $permissions['node:content_domain:manage members'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:manage permissions'
  $permissions['node:content_domain:manage permissions'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:manage roles'
  $permissions['node:content_domain:manage roles'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:subscribe'
  $permissions['node:content_domain:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:subscribe without approval'
  $permissions['node:content_domain:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:unsubscribe'
  $permissions['node:content_domain:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any content_chapter content'
  $permissions['node:content_domain:update any content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any content_multiple_choice content'
  $permissions['node:content_domain:update any content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any content_question_and_answer content'
  $permissions['node:content_domain:update any content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any forum content'
  $permissions['node:content_domain:update any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:update group'
  $permissions['node:content_domain:update group'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own content_chapter content'
  $permissions['node:content_domain:update own content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own content_multiple_choice content'
  $permissions['node:content_domain:update own content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own content_question_and_answer content'
  $permissions['node:content_domain:update own content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own forum content'
  $permissions['node:content_domain:update own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:view any master profile'
  $permissions['node:content_domain:view any master profile'] = array(
    'roles' => array(),
  );

  return $permissions;
}
