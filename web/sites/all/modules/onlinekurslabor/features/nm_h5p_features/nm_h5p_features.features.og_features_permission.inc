<?php

/**
 * @file
 * nm_h5p_features.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function nm_h5p_features_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:content_domain:create h5p_content content'
  $permissions['node:content_domain:create h5p_content content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any h5p_content content'
  $permissions['node:content_domain:delete any h5p_content content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own h5p_content content'
  $permissions['node:content_domain:delete own h5p_content content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any h5p_content content'
  $permissions['node:content_domain:update any h5p_content content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own h5p_content content'
  $permissions['node:content_domain:update own h5p_content content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:create h5p_content content'
  $permissions['node:courses_course:create h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:delete any h5p_content content'
  $permissions['node:courses_course:delete any h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:delete own h5p_content content'
  $permissions['node:courses_course:delete own h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:update any h5p_content content'
  $permissions['node:courses_course:update any h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:update own h5p_content content'
  $permissions['node:courses_course:update own h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create h5p_content content'
  $permissions['node:courses_group:create h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any h5p_content content'
  $permissions['node:courses_group:delete any h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own h5p_content content'
  $permissions['node:courses_group:delete own h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any h5p_content content'
  $permissions['node:courses_group:update any h5p_content content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own h5p_content content'
  $permissions['node:courses_group:update own h5p_content content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
