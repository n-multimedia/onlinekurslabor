<?php
/**
 * @file
 * nm_section_courses_features.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function nm_section_courses_features_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'course_information';
  $layout->admin_title = 'Course Information';
  $layout->admin_description = 'Layout for not-enrolled users and anonymous users.';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'course-info',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
        'class' => 'course',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'links',
          1 => 'rechts',
        ),
        'parent' => 'main',
        'class' => 'row course-info-header',
      ),
      'links' => array(
        'type' => 'region',
        'title' => 'header_left',
        'width' => '65.40245299300852',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'header_left col-md-8',
      ),
      'rechts' => array(
        'type' => 'region',
        'title' => 'header_right',
        'width' => '34.597547006991476',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'header_right col-md-4',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'links_',
          1 => 'rechts_',
        ),
        'parent' => 'main',
        'class' => 'course-info-subheader',
      ),
      'links_' => array(
        'type' => 'region',
        'title' => 'subheader_left',
        'width' => '65.40245205837297',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'subheader_left col-md-8',
      ),
      'rechts_' => array(
        'type' => 'region',
        'title' => 'subheader_right',
        'width' => '34.59754794162703',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'subheader_right col-md-4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'content',
        ),
        'parent' => 'main',
        'class' => 'row',
      ),
      'content' => array(
        'type' => 'region',
        'title' => 'Content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'course-info-content col-md-12',
      ),
    ),
  );
  $export['course_information'] = $layout;

  return $export;
}
