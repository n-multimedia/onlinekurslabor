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
        'children' => array(
          0 => 'main',
        ),
        'class' => 'course-info',
        'column_class' => '',
        'column_separation' => '0.5em',
        'contains' => 'column',
        'fixed_width' => '',
        'no_scale' => FALSE,
        'parent' => NULL,
        'region_class' => '',
        'region_separation' => '0.5em',
        'row_class' => '',
        'row_separation' => '0.5em',
        'type' => 'row',
      ),
      'content' => array(
        'class' => 'course-info-content col-md-12',
        'parent' => '2',
        'title' => 'Content',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'links' => array(
        'class' => 'header_left col-md-8',
        'parent' => 'main-row',
        'title' => 'header_left',
        'type' => 'region',
        'width' => '65.40245299300852',
        'width_type' => '%',
      ),
      'links_' => array(
        'class' => 'subheader_left col-md-8',
        'parent' => '1',
        'title' => 'subheader_left',
        'type' => 'region',
        'width' => '65.40245205837297',
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'class' => 'course',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'links',
          1 => 'rechts',
        ),
        'class' => 'row course-info-header',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'rechts' => array(
        'class' => 'header_right col-md-4',
        'parent' => 'main-row',
        'title' => 'header_right',
        'type' => 'region',
        'width' => '34.597547006991476',
        'width_type' => '%',
      ),
      'rechts_' => array(
        'class' => 'subheader_right col-md-4',
        'parent' => '1',
        'title' => 'subheader_right',
        'type' => 'region',
        'width' => '34.59754794162703',
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 'links_',
          1 => 'rechts_',
        ),
        'class' => 'course-info-subheader',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      2 => array(
        'children' => array(
          0 => 'content',
        ),
        'class' => 'row',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $export['course_information'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'profile_layout';
  $layout->admin_title = 'profile-layout';
  $layout->admin_description = 'Die Sortierung in der GUI ist falsch. middle ist tatsächlich middle, auch wenn rechts angeordnet. 
Hintergrund ist ein bootstrap-problem';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 1,
          1 => 'main',
          2 => 2,
        ),
        'class' => 'row',
        'column_class' => '',
        'column_separation' => '0.5em',
        'contains' => 'column',
        'fixed_width' => '',
        'no_scale' => FALSE,
        'parent' => NULL,
        'region_class' => '',
        'region_separation' => '0.5em',
        'row_class' => '',
        'row_separation' => '0.5em',
        'type' => 'row',
      ),
      'center' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => 'main-row',
        'title' => 'right',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'left' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '3',
        'title' => 'left',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-xs-12 col-sm-3 col-sm-push-6',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '26.3311842451191',
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'center',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'right' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '4',
        'title' => 'middle',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 3,
        ),
        'class' => 'col-xs-12 col-sm-3 ',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '25.13203096959442',
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 4,
        ),
        'class' => 'col-xs-12 col-sm-6 col-sm-pull-3',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '48.53678478528647',
        'width_type' => '%',
      ),
      3 => array(
        'children' => array(
          0 => 'left',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
      4 => array(
        'children' => array(
          0 => 'right',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '2',
        'type' => 'row',
      ),
    ),
  );
  $export['profile_layout'] = $layout;

  return $export;
}
