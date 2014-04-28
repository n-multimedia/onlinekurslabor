<?php
/**
 * @file
 * nm_stream_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nm_stream_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create nm_stream content'.
  $permissions['create nm_stream content'] = array(
    'name' => 'create nm_stream content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any nm_stream content'.
  $permissions['delete any nm_stream content'] = array(
    'name' => 'delete any nm_stream content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own nm_stream content'.
  $permissions['delete own nm_stream content'] = array(
    'name' => 'delete own nm_stream content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any nm_stream content'.
  $permissions['edit any nm_stream content'] = array(
    'name' => 'edit any nm_stream content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own nm_stream content'.
  $permissions['edit own nm_stream content'] = array(
    'name' => 'edit own nm_stream content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
