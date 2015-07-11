<?php
/**
 * @file
 * section_projects_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function section_projects_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['section_projects-project_cockpit_main'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'project_cockpit_main',
    'module' => 'section_projects',
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
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_projects-projects_course_group_actions'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'projects_course_group_actions',
    'module' => 'section_projects',
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
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_projects-projects_header_and_navigation'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'projects_header_and_navigation',
    'module' => 'section_projects',
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
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_projects-projects_po_tools'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'projects_po_tools',
    'module' => 'section_projects',
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
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-d6bd052973023461a8446f1b9b5728a7'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'd6bd052973023461a8446f1b9b5728a7',
    'module' => 'views',
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
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
