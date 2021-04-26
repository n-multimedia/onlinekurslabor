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

  // Exported permission: 'download all h5ps'.
  $permissions['download all h5ps'] = array(
    'name' => 'download all h5ps',
    'roles' => array(),
    'module' => 'h5p',
  );

  // Exported permission: 'download own h5ps'.
  $permissions['download own h5ps'] = array(
    'name' => 'download own h5ps',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
    ),
    'module' => 'h5p',
  );

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
