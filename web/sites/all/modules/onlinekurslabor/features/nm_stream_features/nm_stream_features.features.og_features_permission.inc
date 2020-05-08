<?php

/**
 * @file
 * nm_stream_features.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function nm_stream_features_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:content_domain:create nm_stream content'
  $permissions['node:content_domain:create nm_stream content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any nm_stream content'
  $permissions['node:content_domain:delete any nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:delete own nm_stream content'
  $permissions['node:content_domain:delete own nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:update any nm_stream content'
  $permissions['node:content_domain:update any nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:update own nm_stream content'
  $permissions['node:content_domain:update own nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:create nm_stream content'
  $permissions['node:courses_course:create nm_stream content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any nm_stream content'
  $permissions['node:courses_course:delete any nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:delete own nm_stream content'
  $permissions['node:courses_course:delete own nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:update any nm_stream content'
  $permissions['node:courses_course:update any nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:update own nm_stream content'
  $permissions['node:courses_course:update own nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create nm_stream content'
  $permissions['node:courses_group:create nm_stream content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:delete any nm_stream content'
  $permissions['node:courses_group:delete any nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own nm_stream content'
  $permissions['node:courses_group:delete own nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any nm_stream content'
  $permissions['node:courses_group:update any nm_stream content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own nm_stream content'
  $permissions['node:courses_group:update own nm_stream content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
