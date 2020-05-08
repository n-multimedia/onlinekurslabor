<?php

/**
 * @file
 * videosafe_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function videosafe_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create videosafe_folder content'.
  $permissions['create videosafe_folder content'] = array(
    'name' => 'create videosafe_folder content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create videosafe_video content'.
  $permissions['create videosafe_video content'] = array(
    'name' => 'create videosafe_video content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any videosafe_folder content'.
  $permissions['delete any videosafe_folder content'] = array(
    'name' => 'delete any videosafe_folder content',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any videosafe_video content'.
  $permissions['delete any videosafe_video content'] = array(
    'name' => 'delete any videosafe_video content',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own videosafe_folder content'.
  $permissions['delete own videosafe_folder content'] = array(
    'name' => 'delete own videosafe_folder content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own videosafe_video content'.
  $permissions['delete own videosafe_video content'] = array(
    'name' => 'delete own videosafe_video content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any videosafe_folder content'.
  $permissions['edit any videosafe_folder content'] = array(
    'name' => 'edit any videosafe_folder content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any videosafe_video content'.
  $permissions['edit any videosafe_video content'] = array(
    'name' => 'edit any videosafe_video content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own videosafe_folder content'.
  $permissions['edit own videosafe_folder content'] = array(
    'name' => 'edit own videosafe_folder content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own videosafe_video content'.
  $permissions['edit own videosafe_video content'] = array(
    'name' => 'edit own videosafe_video content',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
