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
      'main' => array(
        'children' => array(
          0 => 10,
          1 => 15,
        ),
        'class' => '',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100.00000000000061,
        'width_type' => '%',
      ),
      'main_' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '14',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'picture_' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '13',
        'title' => 'space-left md2',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'tabs_' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '15',
        'title' => 'tabbed output',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      10 => array(
        'children' => array(
          0 => 11,
          1 => 12,
        ),
        'class' => 'top',
        'contains' => 'column',
        'hide_empty' => 0,
        'parent' => 'main',
        'type' => 'row',
      ),
      11 => array(
        'children' => array(
          0 => 13,
        ),
        'class' => 'col-md-2',
        'hide_empty' => 0,
        'parent' => '10',
        'type' => 'column',
        'width' => '17.92246792246792',
        'width_type' => '%',
      ),
      12 => array(
        'children' => array(
          0 => 14,
        ),
        'class' => 'col-md-10',
        'hide_empty' => 0,
        'parent' => '10',
        'type' => 'column',
        'width' => '82.07753207753208',
        'width_type' => '%',
      ),
      13 => array(
        'children' => array(
          0 => 'picture_',
        ),
        'class' => '',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => '11',
        'type' => 'row',
      ),
      14 => array(
        'children' => array(
          0 => 'main_',
        ),
        'class' => '',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => '12',
        'type' => 'row',
      ),
      15 => array(
        'children' => array(
          0 => 'tabs_',
        ),
        'class' => 'row',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $export['home_layout_loggedin'] = $layout;

  return $export;
}
