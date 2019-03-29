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
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
          2 => 2,
        ),
        'parent' => NULL,
        'class' => 'row',
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
        'width' => '26.3311842451191',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'col-xs-12 col-sm-3 col-sm-push-6',
        'hide_empty' => 0,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'column',
        'width' => '25.13203096959442',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 3,
        ),
        'class' => 'col-xs-12 col-sm-3 ',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'column',
        'width' => '48.53678478528647',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 4,
        ),
        'class' => 'col-xs-12 col-sm-6 col-sm-pull-3',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right',
        ),
        'parent' => '2',
        'class' => '',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'middle',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $export['profile_layout'] = $layout;

  return $export;
}
