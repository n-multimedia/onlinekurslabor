<?php
/**
 * @file
 * nm_general_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nm_general_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['custom_general-custom_general_space'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'custom_general_space',
    'module' => 'custom_general',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['custom_general-custom_general_top_nav'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'custom_general_top_nav',
    'module' => 'custom_general',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -25,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
