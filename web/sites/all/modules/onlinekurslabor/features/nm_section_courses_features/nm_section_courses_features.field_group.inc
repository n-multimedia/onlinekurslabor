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
      0 => 'field_course_header',
      1 => 'field_course_picture',
      2 => 'field_field_courses_sponsors',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-course-design field-group-htab',
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
    'weight' => '9',
    'children' => array(
      0 => 'field_collaborative_features',
      1 => 'field_access_features',
      2 => 'field_other_features',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-course-features field-group-htab',
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
      0 => 'field_long_description',
      1 => 'field_short_description',
      2 => 'field_subtitle',
      3 => 'field_time_span',
      4 => 'field_workload',
      5 => 'field_semester',
      6 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Allgemein / Kursinfo',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-course-general-data field-group-htab',
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
      1 => 'group_course_features',
      2 => 'group_course_general_data',
      3 => 'group_course_projects',
      4 => 'group_courses_text',
      5 => 'group_courses_vhb',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-course-general field-group-htabs',
      ),
    ),
  );
  $export['group_course_general|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_projects|node|courses_course|form';
  $field_group->group_name = 'group_course_projects';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_general';
  $field_group->data = array(
    'label' => 'Projekte',
    'weight' => '11',
    'children' => array(
      0 => 'field_course_proposals',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-projects field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_course_projects|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_courses_text|node|courses_course|form';
  $field_group->group_name = 'group_courses_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_general';
  $field_group->data = array(
    'label' => 'Lehrtext',
    'weight' => '8',
    'children' => array(
      0 => 'field_domain_ref',
      1 => 'field_domain_demo_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-courses-text field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_courses_text|node|courses_course|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'field_vhb_lvnr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-courses-vhb field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_courses_vhb|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_account_tab|user|user|form';
  $field_group->group_name = 'group_user_account_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_tabs';
  $field_group->data = array(
    'label' => 'Zugangsdaten',
    'weight' => '18',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_account_tab|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_master_tab|user|user|form';
  $field_group->group_name = 'group_user_master_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_tabs';
  $field_group->data = array(
    'label' => 'Stammdaten',
    'weight' => '19',
    'children' => array(
      0 => 'profile_master',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_master_tab|user|user|form'] = $field_group;

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
        'classes' => ' group-user-personal-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_personal_info|profile2|student|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_settings_tab|user|user|form';
  $field_group->group_name = 'group_user_settings_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_tabs';
  $field_group->data = array(
    'label' => 'Einstellungen',
    'weight' => '21',
    'children' => array(
      0 => 'og_user_node',
      1 => 'timezone',
      2 => 'overlay_control',
      3 => 'locale',
      4 => 'wysiwyg',
      5 => 'biblio_fieldset',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_settings_tab|user|user|form'] = $field_group;

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
        'classes' => ' group-user-stream field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_stream|profile2|student|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_student_tab|user|user|form';
  $field_group->group_name = 'group_user_student_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_tabs';
  $field_group->data = array(
    'label' => 'Studentendaten',
    'weight' => '20',
    'children' => array(
      0 => 'profile_student',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_student_tab|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_tabs|user|user|form';
  $field_group->group_name = 'group_user_tabs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tab Container',
    'weight' => '0',
    'children' => array(
      0 => 'group_user_settings_tab',
      1 => 'group_user_master_tab',
      2 => 'group_user_account_tab',
      3 => 'group_user_student_tab',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_tabs|user|user|form'] = $field_group;

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
        'classes' => ' group-users-courses field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_users_courses|profile2|student|default'] = $field_group;

  return $export;
}
