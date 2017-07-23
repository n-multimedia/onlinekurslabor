<?php
/**
 * @file
 * home_features.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function home_features_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'home_layout_loggedin';
  $layout->admin_title = 'home layout loggedin';
  $layout->admin_description = 'the layout for the home page (loggedin)';
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
        'width' => 100.00000000000061,
        'width_type' => '%',
        'children' => array(
          0 => 10,
          1 => 15,
        ),
        'parent' => 'canvas',
        'class' => '',
        'hide_empty' => 0,
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 11,
          1 => 12,
        ),
        'parent' => 'main',
        'class' => 'top',
        'hide_empty' => 0,
      ),
      11 => array(
        'type' => 'column',
        'width' => '17.92246792246792',
        'width_type' => '%',
        'parent' => '10',
        'children' => array(
          0 => 13,
        ),
        'class' => 'col-md-2',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'column',
        'width' => '82.07753207753208',
        'width_type' => '%',
        'parent' => '10',
        'children' => array(
          0 => 14,
        ),
        'class' => 'col-md-10',
        'hide_empty' => 0,
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'picture_',
        ),
        'parent' => '11',
        'class' => '',
        'hide_empty' => 0,
      ),
      'picture_' => array(
        'type' => 'region',
        'title' => 'space-left md2',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
        'hide_empty' => 0,
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'main_',
        ),
        'parent' => '12',
        'class' => '',
        'hide_empty' => 0,
      ),
      'main_' => array(
        'type' => 'region',
        'title' => 'main',
        'width' => 100,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
        'hide_empty' => 0,
      ),
      15 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tabs_',
        ),
        'parent' => 'main',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      'tabs_' => array(
        'type' => 'region',
        'title' => 'tabbed output',
        'width' => 100,
        'width_type' => '%',
        'parent' => '15',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $export['home_layout_loggedin'] = $layout;

  return $export;
}
