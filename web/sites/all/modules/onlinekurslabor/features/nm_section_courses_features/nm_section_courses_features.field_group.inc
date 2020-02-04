<?php

/**
 * @file
 * nm_section_courses_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nm_section_courses_features_field_group_info() {
  $field_groups = array();

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
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Design',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'design',
        'classes' => 'group-course-design field-group-htab',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_course_design|node|courses_course|form'] = $field_group;

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
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Features',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'features',
        'classes' => 'group-course-features field-group-htab',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_course_features|node|courses_course|form'] = $field_group;

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
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Allgemein / Kursinfo',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'common',
        'classes' => 'group-course-general-data field-group-htab',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_course_general_data|node|courses_course|form'] = $field_group;

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
      0 => 'group_course_lehet',
      1 => 'group_course_design',
      2 => 'group_course_features',
      3 => 'group_course_general_data',
      4 => 'group_course_projects',
      5 => 'group_courses_text',
      6 => 'group_courses_vhb',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-course-general field-group-htabs',
      ),
    ),
  );
  $field_groups['group_course_general|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_lehet|node|courses_course|form';
  $field_group->group_name = 'group_course_lehet';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_general';
  $field_group->data = array(
    'label' => 'LeHet',
    'weight' => '10',
    'children' => array(
      0 => 'group_lehet_responsive',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'LeHet',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-course-lehet field-group-fieldset',
        'description' => 'Bitte wählen Sie hier nur etwas an, wenn es sich bei diesem Kurs um einen <a href="https://www.uni-augsburg.de/de/forschung/projekte/lehet/" target=_blank>LeHet</a>-Kurs handelt.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_course_lehet|node|courses_course|form'] = $field_group;

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
    'weight' => '13',
    'children' => array(
      0 => 'field_course_proposals',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Projekte',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'projects',
        'classes' => 'group-course-projects field-group-htab',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_course_projects|node|courses_course|form'] = $field_group;

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
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Lehrtext',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'domain',
        'classes' => 'group-courses-text field-group-htab',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_courses_text|node|courses_course|form'] = $field_group;

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
    'weight' => '12',
    'children' => array(
      0 => 'field_vhb_lvnr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'VHB Einstellungen',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'vhb',
        'classes' => 'group-courses-vhb field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_courses_vhb|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lehet_responsive_left|node|courses_course|form';
  $field_group->group_name = 'group_lehet_responsive_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lehet_responsive';
  $field_group->data = array(
    'label' => 'lehet-responsive-left',
    'weight' => '5',
    'children' => array(
      0 => 'field_lehet_kompetenzbereich',
      1 => 'field_lehet_material',
      2 => 'field_lehet_subjects',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'lehet-responsive-left',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lehet-responsive-left field-group-div col-md-6 col-xs-12',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lehet_responsive_left|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lehet_responsive_right|node|courses_course|form';
  $field_group->group_name = 'group_lehet_responsive_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_lehet_responsive';
  $field_group->data = array(
    'label' => 'lehet-responsive-right',
    'weight' => '7',
    'children' => array(
      0 => 'field_lehet_content',
      1 => 'field_lehet_schooltype',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'lehet-responsive-right',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lehet-responsive-right field-group-div col-md-6 col-xs-12',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lehet_responsive_right|node|courses_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lehet_responsive|node|courses_course|form';
  $field_group->group_name = 'group_lehet_responsive';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'courses_course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_lehet';
  $field_group->data = array(
    'label' => 'LeHet',
    'weight' => '19',
    'children' => array(
      0 => 'group_lehet_responsive_left',
      1 => 'group_lehet_responsive_right',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'LeHet',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-lehet-responsive field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_lehet_responsive|node|courses_course|form'] = $field_group;

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
  $field_groups['group_user_account_tab|user|user|form'] = $field_group;

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
  $field_groups['group_user_master_tab|user|user|form'] = $field_group;

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
  $field_groups['group_user_personal_info|profile2|student|default'] = $field_group;

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
      1 => 'custom_general_fieldset',
      2 => 'privatemsg',
      3 => 'timezone',
      4 => 'locale',
      5 => 'wysiwyg',
      6 => 'biblio_fieldset',
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
  $field_groups['group_user_settings_tab|user|user|form'] = $field_group;

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
  $field_groups['group_user_stream|profile2|student|default'] = $field_group;

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
    'label' => 'Studierendendaten',
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
  $field_groups['group_user_student_tab|user|user|form'] = $field_group;

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
      0 => 'group_user_account_tab',
      1 => 'group_user_master_tab',
      2 => 'group_user_settings_tab',
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
  $field_groups['group_user_tabs|user|user|form'] = $field_group;

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
  $field_groups['group_users_courses|profile2|student|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Allgemein / Kursinfo');
  t('Design');
  t('Einstellungen');
  t('Features');
  t('Kurs - Allgemein');
  t('LeHet');
  t('Lehrtext');
  t('Meine Kurse');
  t('Persönliche Informationen');
  t('Projekte');
  t('Stammdaten');
  t('Stream');
  t('Studierendendaten');
  t('Tab Container');
  t('VHB Einstellungen');
  t('Zugangsdaten');
  t('lehet-responsive-left');
  t('lehet-responsive-right');

  return $field_groups;
}
