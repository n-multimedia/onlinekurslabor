<?php
/**
 * @file
 * help_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function help_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_navigation_icon'.
  $field_bases['field_navigation_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_navigation_icon',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
