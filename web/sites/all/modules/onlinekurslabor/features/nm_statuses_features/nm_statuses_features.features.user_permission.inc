<?php
/**
 * @file
 * nm_statuses_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nm_statuses_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer Statuses settings'.
  $permissions['administer Statuses settings'] = array(
    'name' => 'administer Statuses settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'delete all status comments'.
  $permissions['delete all status comments'] = array(
    'name' => 'delete all status comments',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'Tutor' => 'Tutor',
      'administrator' => 'administrator',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'delete all statuses'.
  $permissions['delete all statuses'] = array(
    'name' => 'delete all statuses',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'delete comments on own statuses'.
  $permissions['delete comments on own statuses'] = array(
    'name' => 'delete comments on own statuses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'delete own status comments'.
  $permissions['delete own status comments'] = array(
    'name' => 'delete own status comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'delete own statuses'.
  $permissions['delete own statuses'] = array(
    'name' => 'delete own statuses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'delete status messages on own nodes'.
  $permissions['delete status messages on own nodes'] = array(
    'name' => 'delete status messages on own nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'delete status messages on own profile'.
  $permissions['delete status messages on own profile'] = array(
    'name' => 'delete status messages on own profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'edit all status comments'.
  $permissions['edit all status comments'] = array(
    'name' => 'edit all status comments',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'Tutor' => 'Tutor',
      'administrator' => 'administrator',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'edit all statuses'.
  $permissions['edit all statuses'] = array(
    'name' => 'edit all statuses',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'edit comments on own statuses'.
  $permissions['edit comments on own statuses'] = array(
    'name' => 'edit comments on own statuses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'edit own status comments'.
  $permissions['edit own status comments'] = array(
    'name' => 'edit own status comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'edit own statuses'.
  $permissions['edit own statuses'] = array(
    'name' => 'edit own statuses',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'post status comment'.
  $permissions['post status comment'] = array(
    'name' => 'post status comment',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'post status messages to other streams'.
  $permissions['post status messages to other streams'] = array(
    'name' => 'post status messages to other streams',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'send messages to all users at once'.
  $permissions['send messages to all users at once'] = array(
    'name' => 'send messages to all users at once',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'update and view own stream'.
  $permissions['update and view own stream'] = array(
    'name' => 'update and view own stream',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'use PHP for context visibility'.
  $permissions['use PHP for context visibility'] = array(
    'name' => 'use PHP for context visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'view all status comments'.
  $permissions['view all status comments'] = array(
    'name' => 'view all status comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fbss_comments',
  );

  // Exported permission: 'view all statuses'.
  $permissions['view all statuses'] = array(
    'name' => 'view all statuses',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'statuses',
  );

  // Exported permission: 'view own status comments'.
  $permissions['view own status comments'] = array(
    'name' => 'view own status comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fbss_comments',
  );

  return $permissions;
}
