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
    'children' => array(
      0 => 'field_course_header',
      1 => 'field_course_picture',
      2 => 'field_field_courses_sponsors',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-course-design field-group-htab',
        'description' => '',
        'id' => 'design',
        'required_fields' => 1,
      ),
      'label' => 'Design',
    ),
    'format_type' => 'fieldset',
    'label' => 'Design',
    'weight' => '7',
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
    'children' => array(
      0 => 'field_collaborative_features',
      1 => 'field_access_features',
      2 => 'field_other_features',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-course-features field-group-htab',
        'description' => '',
        'id' => 'features',
        'required_fields' => 1,
      ),
      'label' => 'Features',
    ),
    'format_type' => 'fieldset',
    'label' => 'Features',
    'weight' => '9',
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
    'children' => array(
      0 => 'field_long_description',
      1 => 'field_short_description',
      2 => 'field_subtitle',
      3 => 'field_time_span',
      4 => 'field_workload',
      5 => 'field_semester',
      6 => 'title',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-course-general-data field-group-htab',
        'description' => '',
        'id' => 'common',
        'required_fields' => 1,
      ),
      'label' => 'Allgemein / Kursinfo',
    ),
    'format_type' => 'fieldset',
    'label' => 'Allgemein / Kursinfo',
    'weight' => '6',
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
    'children' => array(
      0 => 'group_course_design',
      1 => 'group_course_features',
      2 => 'group_course_general_data',
      3 => 'group_course_lehet',
      4 => 'group_course_projects',
      5 => 'group_courses_text',
      6 => 'group_courses_vhb',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => ' group-course-general field-group-htabs',
      ),
    ),
    'format_type' => 'htabs',
    'label' => 'Kurs - Allgemein',
    'weight' => '0',
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
    'children' => array(
      0 => 'group_lehet_responsive',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-course-lehet field-group-fieldset',
        'description' => 'Bitte wählen Sie hier nur etwas an, wenn es sich bei diesem Kurs um einen <a href="https://www.uni-augsburg.de/de/forschung/projekte/lehet/" target=_blank>LeHet</a>-Kurs handelt.',
        'id' => '',
        'required_fields' => 0,
      ),
      'label' => 'LeHet (disabled in section_courses_form_alter)',
    ),
    'format_type' => 'fieldset',
    'label' => 'LeHet (disabled in section_courses_form_alter)',
    'weight' => '10',
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
    'children' => array(
      0 => 'field_course_proposals',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-course-projects field-group-htab',
        'description' => '',
        'id' => 'projects',
        'required_fields' => 1,
      ),
      'label' => 'Projekte',
    ),
    'format_type' => 'fieldset',
    'label' => 'Projekte',
    'weight' => '13',
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
    'children' => array(
      0 => 'field_domain_ref',
      1 => 'field_domain_demo_ref',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-courses-text field-group-htab',
        'description' => '',
        'id' => 'domain',
        'required_fields' => 1,
      ),
      'label' => 'Lehrtext',
    ),
    'format_type' => 'fieldset',
    'label' => 'Lehrtext',
    'weight' => '8',
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
    'children' => array(
      0 => 'field_vhb_lvnr',
    ),
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => 'group-courses-vhb field-group-fieldset',
        'description' => '',
        'id' => 'vhb',
        'required_fields' => 1,
      ),
      'label' => 'VHB Einstellungen',
    ),
    'format_type' => 'fieldset',
    'label' => 'VHB Einstellungen',
    'weight' => '12',
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
    'children' => array(
      0 => 'field_lehet_kompetenzbereich',
      1 => 'field_lehet_material',
      2 => 'field_lehet_subjects',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-lehet-responsive-left field-group-div col-md-6 col-xs-12',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'required_fields' => 1,
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'lehet-responsive-left',
    ),
    'format_type' => 'div',
    'label' => 'lehet-responsive-left',
    'weight' => '5',
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
    'children' => array(
      0 => 'field_lehet_content',
      1 => 'field_lehet_schooltype',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-lehet-responsive-right field-group-div col-md-6 col-xs-12',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'required_fields' => 1,
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'lehet-responsive-right',
    ),
    'format_type' => 'div',
    'label' => 'lehet-responsive-right',
    'weight' => '7',
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
    'children' => array(
      0 => 'group_lehet_responsive_left',
      1 => 'group_lehet_responsive_right',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => 'group-lehet-responsive field-group-div',
        'description' => '',
        'effect' => 'none',
        'id' => '',
        'label_element' => 'h3',
        'required_fields' => 1,
        'show_label' => '0',
        'speed' => 'fast',
      ),
      'label' => 'LeHet',
    ),
    'format_type' => 'div',
    'label' => 'LeHet',
    'weight' => '19',
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
    'children' => array(
      0 => 'account',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Zugangsdaten',
    'weight' => '18',
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
    'children' => array(
      0 => 'profile_master',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Stammdaten',
    'weight' => '19',
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
    'children' => array(
      0 => 'field_gender',
      1 => 'field_birthday',
      2 => 'field_about_me',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => ' group-user-personal-info field-group-fieldset',
        'description' => '',
      ),
      'label' => 'Persönliche Informationen',
    ),
    'format_type' => 'fieldset',
    'label' => 'Persönliche Informationen',
    'weight' => '3',
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
    'children' => array(
      0 => 'og_user_node',
      1 => 'custom_general_fieldset',
      2 => 'privatemsg',
      3 => 'timezone',
      4 => 'locale',
      5 => 'wysiwyg',
      6 => 'biblio_fieldset',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Einstellungen',
    'weight' => '21',
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
    'children' => array(
      0 => 'statueses',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => ' group-user-stream field-group-fieldset',
        'description' => '',
      ),
      'label' => 'Stream',
    ),
    'format_type' => 'fieldset',
    'label' => 'Stream',
    'weight' => '2',
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
    'children' => array(
      0 => 'profile_student',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Studierendendaten',
    'weight' => '20',
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
    'children' => array(
      0 => 'group_user_account_tab',
      1 => 'group_user_master_tab',
      2 => 'group_user_settings_tab',
      3 => 'group_user_student_tab',
    ),
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
    'format_type' => 'tabs',
    'label' => 'Tab Container',
    'weight' => '0',
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
    'children' => array(
      0 => 'user_courses',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => ' group-users-courses field-group-fieldset',
        'description' => '',
      ),
      'label' => 'Meine Kurse',
    ),
    'format_type' => 'fieldset',
    'label' => 'Meine Kurse',
    'weight' => '1',
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
  t('LeHet (disabled in section_courses_form_alter)');
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
