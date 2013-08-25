<?php
/**
 * @file
 * nm_general_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nm_general_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'edit any master profile'.
  $permissions['edit any master profile'] = array(
    'name' => 'edit any master profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own master profile'.
  $permissions['edit own master profile'] = array(
    'name' => 'edit own master profile',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any master profile'.
  $permissions['view any master profile'] = array(
    'name' => 'view any master profile',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own master profile'.
  $permissions['view own master profile'] = array(
    'name' => 'view own master profile',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
