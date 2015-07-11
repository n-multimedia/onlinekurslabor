<?php
/**
 * @file
 * section_projects_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function section_projects_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create projects_blog content'.
  $permissions['create projects_blog content'] = array(
    'name' => 'create projects_blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create projects_cooperation_agreement content'.
  $permissions['create projects_cooperation_agreement content'] = array(
    'name' => 'create projects_cooperation_agreement content',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create projects_documentation content'.
  $permissions['create projects_documentation content'] = array(
    'name' => 'create projects_documentation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create projects_objective content'.
  $permissions['create projects_objective content'] = array(
    'name' => 'create projects_objective content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create projects_organization content'.
  $permissions['create projects_organization content'] = array(
    'name' => 'create projects_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create projects_proposal content'.
  $permissions['create projects_proposal content'] = array(
    'name' => 'create projects_proposal content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any projects_blog content'.
  $permissions['delete any projects_blog content'] = array(
    'name' => 'delete any projects_blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any projects_cooperation_agreement content'.
  $permissions['delete any projects_cooperation_agreement content'] = array(
    'name' => 'delete any projects_cooperation_agreement content',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any projects_documentation content'.
  $permissions['delete any projects_documentation content'] = array(
    'name' => 'delete any projects_documentation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any projects_objective content'.
  $permissions['delete any projects_objective content'] = array(
    'name' => 'delete any projects_objective content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any projects_organization content'.
  $permissions['delete any projects_organization content'] = array(
    'name' => 'delete any projects_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any projects_proposal content'.
  $permissions['delete any projects_proposal content'] = array(
    'name' => 'delete any projects_proposal content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own projects_blog content'.
  $permissions['delete own projects_blog content'] = array(
    'name' => 'delete own projects_blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own projects_cooperation_agreement content'.
  $permissions['delete own projects_cooperation_agreement content'] = array(
    'name' => 'delete own projects_cooperation_agreement content',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own projects_documentation content'.
  $permissions['delete own projects_documentation content'] = array(
    'name' => 'delete own projects_documentation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own projects_objective content'.
  $permissions['delete own projects_objective content'] = array(
    'name' => 'delete own projects_objective content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own projects_organization content'.
  $permissions['delete own projects_organization content'] = array(
    'name' => 'delete own projects_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own projects_proposal content'.
  $permissions['delete own projects_proposal content'] = array(
    'name' => 'delete own projects_proposal content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any projects_blog content'.
  $permissions['edit any projects_blog content'] = array(
    'name' => 'edit any projects_blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any projects_cooperation_agreement content'.
  $permissions['edit any projects_cooperation_agreement content'] = array(
    'name' => 'edit any projects_cooperation_agreement content',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any projects_documentation content'.
  $permissions['edit any projects_documentation content'] = array(
    'name' => 'edit any projects_documentation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any projects_objective content'.
  $permissions['edit any projects_objective content'] = array(
    'name' => 'edit any projects_objective content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any projects_organization content'.
  $permissions['edit any projects_organization content'] = array(
    'name' => 'edit any projects_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any projects_proposal content'.
  $permissions['edit any projects_proposal content'] = array(
    'name' => 'edit any projects_proposal content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own projects_blog content'.
  $permissions['edit own projects_blog content'] = array(
    'name' => 'edit own projects_blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own projects_cooperation_agreement content'.
  $permissions['edit own projects_cooperation_agreement content'] = array(
    'name' => 'edit own projects_cooperation_agreement content',
    'roles' => array(
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own projects_documentation content'.
  $permissions['edit own projects_documentation content'] = array(
    'name' => 'edit own projects_documentation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own projects_objective content'.
  $permissions['edit own projects_objective content'] = array(
    'name' => 'edit own projects_objective content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own projects_organization content'.
  $permissions['edit own projects_organization content'] = array(
    'name' => 'edit own projects_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own projects_proposal content'.
  $permissions['edit own projects_proposal content'] = array(
    'name' => 'edit own projects_proposal content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
