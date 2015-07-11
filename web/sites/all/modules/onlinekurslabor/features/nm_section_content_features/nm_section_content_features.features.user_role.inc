<?php
/**
 * @file
 * nm_section_content_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nm_section_content_features_user_default_roles() {
  $roles = array();

  // Exported role: Autor.
  $roles['Autor'] = array(
    'name' => 'Autor',
    'weight' => 2,
    'machine_name' => 'autor',
  );

  return $roles;
}
