<?php
/**
 * @file
 * nm_section_courses_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function nm_section_courses_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['section_content-content_authors_tools'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'content_authors_tools',
    'module' => 'section_content',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -37,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -37,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_content-content_node_tabs'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'content_node_tabs',
    'module' => 'section_content',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -35,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -35,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_courses-course_header_section'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_header_section',
    'module' => 'section_courses',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -29,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_courses-course_instructors_tools'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_instructors_tools',
    'module' => 'section_courses',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -32,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -32,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_courses-course_node_tabs'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_node_tabs',
    'module' => 'section_courses',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -31,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -31,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_courses-course_tasks_generic_description'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_tasks_generic_description',
    'module' => 'section_courses',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -28,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -28,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_courses-course_tasks_generic_solution'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_tasks_generic_solution',
    'module' => 'section_courses',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -27,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -27,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['section_courses-course_tasks_generic_tips'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_tasks_generic_tips',
    'module' => 'section_courses',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -26,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -26,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['section_courses-course_top_navigation'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_top_navigation',
    'module' => 'section_courses',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => -25,
      ),
      'bootstrap_onlinekurslabor' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap_onlinekurslabor',
        'weight' => -25,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
