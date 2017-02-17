<?php
/**
 * @file
 * annvid_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function annvid_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create annvid content'.
  $permissions['create annvid content'] = array(
    'name' => 'create annvid content',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any annvid content'.
  $permissions['delete any annvid content'] = array(
    'name' => 'delete any annvid content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own annvid content'.
  $permissions['delete own annvid content'] = array(
    'name' => 'delete own annvid content',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any annvid content'.
  $permissions['edit any annvid content'] = array(
    'name' => 'edit any annvid content',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own annvid content'.
  $permissions['edit own annvid content'] = array(
    'name' => 'edit own annvid content',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
