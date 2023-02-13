<?php

/**
 * @file
 * nm_general_features.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function nm_general_features_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'col_md_8col_md_3col_md_1';
  $layout->admin_title = 'col-md-8col-md-3col-md-1';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
        ),
        'contains' => 'column',
        'parent' => NULL,
        'type' => 'row',
      ),
      'center' => array(
        'class' => 'col-md-3 col-xs-11',
        'parent' => 'main-row',
        'title' => 'col-md-3',
        'type' => 'region',
        'width' => 25,
        'width_type' => '%',
      ),
      'col_md_1' => array(
        'class' => 'col-md-1 col-xs-1',
        'parent' => 'main-row',
        'title' => 'col-md-1',
        'type' => 'region',
        'width' => 25,
        'width_type' => '%',
      ),
      'left' => array(
        'class' => 'col-md-8 col-xs-12',
        'parent' => 'main-row',
        'title' => 'col-md-8',
        'type' => 'region',
        'width' => 50,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'left',
          1 => 'center',
          2 => 'col_md_1',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $export['col_md_8col_md_3col_md_1'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span11span1';
  $layout->admin_title = 'col-md-11col-md-1';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'contains' => 'column',
        'parent' => NULL,
        'type' => 'row',
      ),
      'center' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-11 col-xs-12',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
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
      'tools' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'tools',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-1 col-xs-12',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span11span1'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span11span1_adminonly';
  $layout->admin_title = 'col-md-11col-md-1_adminonly';
  $layout->admin_description = 'adds a col-md-1 to the right. used in courses and projects.
If current person is no course-/project-admin, cold-md-1 will be hidden.
See template.php';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'contains' => 'column',
        'parent' => NULL,
        'type' => 'row',
      ),
      'center' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-11',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
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
      'tools' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'tools',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-1',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span11span1_adminonly'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span12';
  $layout->admin_title = 'col-md-12';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
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
        'class' => 'col-md-12',
        'parent' => 'main-row',
        'title' => 'Zentriert',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'center',
        ),
        'class' => 'col-md-12',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $export['span12'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span3span6span3';
  $layout->admin_title = 'col-md-3col-md-6col-md-3';
  $layout->admin_description = '';
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
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'left' => array(
        'class' => '',
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
        'class' => 'col-md-6',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '52.17311397788196',
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
        'parent' => '4',
        'title' => 'right',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 3,
        ),
        'class' => 'left col-md-3',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '25.13203096959442',
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 4,
        ),
        'class' => 'right col-md-3',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '22.694855052523614',
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
  $export['span3span6span3'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span3span8span1';
  $layout->admin_title = 'col-md-3col-md-8col-md-1';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 1,
          1 => 'main',
          2 => 3,
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
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-8 col-xs-11',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '62.562595933139804',
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
      'outline' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'outline',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'tools' => array(
        'class' => '',
        'parent' => '4',
        'title' => 'tools',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-3 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '25.513982085512044',
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'outline',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
      3 => array(
        'children' => array(
          0 => 4,
        ),
        'class' => 'col-md-1 col-xs-1',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '11.923421981422717',
        'width_type' => '%',
      ),
      4 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '3',
        'type' => 'row',
      ),
    ),
  );
  $export['span3span8span1'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span3span9';
  $layout->admin_title = 'col-md-3col-md-9';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'class' => 'row-fluid',
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
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-9 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '63.62016668139117',
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
      'navigation' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'outline',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-3 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '36.37983331860883',
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'navigation',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span3span9'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span4span8';
  $layout->admin_title = 'col-md-4col-md-8';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 1,
          1 => 'main',
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
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-8 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '63.62016668139117',
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
      'navigation' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'outline',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-4 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '36.37983331860883',
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'navigation',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span4span8'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span6span6';
  $layout->admin_title = 'col-md-6col-md-6';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 1,
          1 => 'main',
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
        'parent' => 'main-row',
        'title' => 'right',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'left' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'left',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-6 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
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
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-6 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'left',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span6span6'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span8span4';
  $layout->admin_title = 'col-md-8col-md-4';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
          1 => 1,
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
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-8 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'news',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'news' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'tools' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'tools',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-4 col-xs-12',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span8span4'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span8span4_mobile_bottom_up';
  $layout->admin_title = 'col-md-8col-md-4:mobile-bottom-up';
  $layout->admin_description = 'mobil befindet sich die rechte Spalte oben statt nach unten
Vorsicht beim Befüllen: tools und main erscheinen vertauscht.';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'class' => 'row',
        'column_class' => '',
        'column_separation' => '0.5em',
        'contains' => 'column',
        'fixed_width' => '',
        'hide_empty' => 0,
        'no_scale' => FALSE,
        'parent' => NULL,
        'region_class' => '',
        'region_separation' => '0.5em',
        'row_class' => '',
        'row_separation' => '0.5em',
        'type' => 'row',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-4 col-md-push-8 col-xs-12 custom-general--column-right',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'news',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'news' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => 'main-row',
        'title' => 'tools (wird rechts dargestellt)',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'tools' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '2',
        'title' => 'main (wird links dargestellt)',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-8 col-md-pull-4 col-xs-12 custom-general--column-left',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span8span4_mobile_bottom_up'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span9span3';
  $layout->admin_title = 'col-md-9col-md-3';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
          1 => 1,
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
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-9 col-xs-12',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'news',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'news' => array(
        'class' => '',
        'parent' => 'main-row',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'tools' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'tools',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-3 col-xs-12',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span9span3'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'span9span3_mobile_bottom_up';
  $layout->admin_title = 'col-md-9col-md-3:mobile-bottom-up';
  $layout->admin_description = 'mobil befindet sich die rechte Spalte oben statt nach unten
Vorsicht beim Befüllen: tools und main erscheinen vertauscht.';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'class' => 'row',
        'column_class' => '',
        'column_separation' => '0.5em',
        'contains' => 'column',
        'fixed_width' => '',
        'hide_empty' => 0,
        'no_scale' => FALSE,
        'parent' => NULL,
        'region_class' => '',
        'region_separation' => '0.5em',
        'row_class' => '',
        'row_separation' => '0.5em',
        'type' => 'row',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-3 col-md-push-9 col-xs-12 custom-general--column-right',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'news',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'news' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => 'main-row',
        'title' => 'tools (wird rechts dargestellt)',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'tools' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '2',
        'title' => 'main (wird links dargestellt)',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-9 col-md-pull-3 col-xs-12 custom-general--column-left',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $export['span9span3_mobile_bottom_up'] = $layout;

  return $export;
}
