<?php
/**
 * @file
 * nm_section_courses_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nm_section_courses_features_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_personal_info|profile2|student|default';
  $field_group->group_name = 'group_user_personal_info';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'student';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Persönliche Informationen',
    'weight' => '3',
    'children' => array(
      0 => 'field_gender',
      1 => 'field_birthday',
      2 => 'field_about_me',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Persönliche Informationen',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_personal_info|profile2|student|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_stream|profile2|student|default';
  $field_group->group_name = 'group_user_stream';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'student';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Stream',
    'weight' => '2',
    'children' => array(
      0 => 'statueses',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Stream',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_stream|profile2|student|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_users_courses|profile2|student|default';
  $field_group->group_name = 'group_users_courses';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'student';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meine Kurse',
    'weight' => '1',
    'children' => array(
      0 => 'user_courses',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Meine Kurse',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_users_courses|profile2|student|default'] = $field_group;

  return $export;
}
