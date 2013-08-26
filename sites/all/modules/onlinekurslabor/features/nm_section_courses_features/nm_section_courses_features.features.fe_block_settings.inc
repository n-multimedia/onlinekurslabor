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

  $export['section_content-content_node_tabs'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'content_node_tabs',
    'module' => 'section_content',
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
        'weight' => -3,
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

  $export['section_courses-course_instructors_tools'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_instructors_tools',
    'module' => 'section_courses',
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

  $export['section_courses-course_node_tabs'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_node_tabs',
    'module' => 'section_courses',
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

  $export['section_courses-course_tasks_generic_description'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'course_tasks_generic_description',
    'module' => 'section_courses',
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
        'weight' => -17,
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
        'weight' => -16,
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
        'weight' => -15,
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
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
