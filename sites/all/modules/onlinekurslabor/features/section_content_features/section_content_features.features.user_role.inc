<?php
/**
 * @file
 * section_content_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function section_content_features_user_default_roles() {
  $roles = array();

  // Exported role: Autor.
  $roles['Autor'] = array(
    'name' => 'Autor',
    'weight' => 6,
  );

  return $roles;
}
