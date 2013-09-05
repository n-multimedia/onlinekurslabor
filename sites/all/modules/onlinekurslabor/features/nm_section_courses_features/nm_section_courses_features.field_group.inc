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
  $field_group->identifier = 'group_course_design|node|courses_course|form';
  $field_group->group_name = 'group_course_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_general';
  $field_group->data = array(
    'label' => 'Design',
    'weight' => '7',
    'children' => array(
      0 => 'field_course_picture',
      1 => 'field_course_header',
      2 => 'field_field_courses_sponsors',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_design|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_features|node|courses_course|form';
  $field_group->group_name = 'group_course_features';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_general';
  $field_group->data = array(
    'label' => 'Features',
    'weight' => '8',
    'children' => array(
      0 => 'field_collaborative_features',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_features|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_general_data|node|courses_course|form';
  $field_group->group_name = 'group_course_general_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_general';
  $field_group->data = array(
    'label' => 'Allgemein / Kursinfo',
    'weight' => '6',
    'children' => array(
      0 => 'field_subtitle',
      1 => 'field_workload',
      2 => 'field_long_description',
      3 => 'field_short_description',
      4 => 'field_time_span',
      5 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Allgemein / Kursinfo',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_course_general_data|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_general|node|courses_course|form';
  $field_group->group_name = 'group_course_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kurs - Allgemein',
    'weight' => '0',
    'children' => array(
      0 => 'group_course_design',
      1 => 'group_course_general_data',
      2 => 'group_course_features',
      3 => 'group_courses_vhb',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_course_general|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_courses_vhb|node|courses_course|form';
  $field_group->group_name = 'group_courses_vhb';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_general';
  $field_group->data = array(
    'label' => 'VHB Einstellungen',
    'weight' => '9',
    'children' => array(
      0 => 'field_vhb_lvnr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_courses_vhb|node|courses_course|form'] = $field_group;

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
