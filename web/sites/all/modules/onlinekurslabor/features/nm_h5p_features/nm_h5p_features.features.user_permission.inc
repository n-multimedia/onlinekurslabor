<?php
/**
 * @file
 * nm_h5p_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nm_h5p_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'update h5p libraries'.
  $permissions['update h5p libraries'] = array(
    'name' => 'update h5p libraries',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'h5p',
  );

  return $permissions;
}
