<?php
/**
 * @file
 * nm_section_content_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nm_section_content_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['book-navigation'] = array(
    'cache' => 5,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'book',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -20,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -20,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
