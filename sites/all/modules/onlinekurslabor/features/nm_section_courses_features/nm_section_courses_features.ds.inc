<?php
/**
 * @file
 * nm_section_courses_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nm_section_courses_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'profile2|student|default';
  $ds_fieldsetting->entity_type = 'profile2';
  $ds_fieldsetting->bundle = 'student';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'statueses' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'user_courses' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['profile2|student|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function nm_section_courses_features_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'statueses';
  $ds_field->label = 'Statueses';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'profile2' => 'profile2',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'statuses|statuses',
    'block_render' => '3',
  );
  $export['statueses'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_courses';
  $ds_field->label = 'Student Kurse';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'profile2' => 'profile2',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|courses_user_courses-block',
    'block_render' => '3',
  );
  $export['user_courses'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nm_section_courses_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|student|default';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'student';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_3col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'user_courses',
        1 => 'field_photo',
        2 => 'group_users_courses',
      ),
      'right' => array(
        3 => 'field_gender',
        4 => 'field_birthday',
        7 => 'group_user_personal_info',
        8 => 'field_about_me',
      ),
      'middle' => array(
        5 => 'group_user_stream',
        6 => 'statueses',
      ),
    ),
    'fields' => array(
      'user_courses' => 'left',
      'field_photo' => 'left',
      'group_users_courses' => 'left',
      'field_gender' => 'right',
      'field_birthday' => 'right',
      'group_user_stream' => 'middle',
      'statueses' => 'middle',
      'group_user_personal_info' => 'right',
      'field_about_me' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
  );
  $export['profile2|student|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function nm_section_courses_features_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sponsors_logo';
  $ds_view_mode->label = 'Sponsors Logo';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['sponsors_logo'] = $ds_view_mode;

  return $export;
}
