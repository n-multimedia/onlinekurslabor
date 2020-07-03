<?php

/**
 * @file
 * nm_section_courses_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nm_section_courses_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nm_section_courses_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nm_section_courses_features_image_default_styles() {
  $styles = array();

  // Exported image style: course_header.
  $styles['course_header'] = array(
    'label' => 'course_header',
    'effects' => array(
      12 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/png',
          'quality' => 75,
        ),
        'weight' => -10,
      ),
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1170,
          'height' => 200,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: course_header_list_item.
  $styles['course_header_list_item'] = array(
    'label' => 'course_header_list_item',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: course_overview_image.
  $styles['course_overview_image'] = array(
    'label' => 'course_overview_image',
    'effects' => array(
      12 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 131,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: course_sponsor_logo.
  $styles['course_sponsor_logo'] = array(
    'label' => 'course_sponsor_logo',
    'effects' => array(
      13 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 85,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function nm_section_courses_features_node_info() {
  $items = array(
    'courses_course' => array(
      'name' => t('Courses - Kurs'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'courses_docs' => array(
      'name' => t('Courses - Kursdokument'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'courses_generic_task' => array(
      'name' => t('Courses - Generische Aufgabe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'courses_generic_task_solution' => array(
      'name' => t('Courses - Generische Lösung'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'courses_group' => array(
      'name' => t('Courses - Kursgruppe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'courses_news' => array(
      'name' => t('Courses - Ankündigung'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function nm_section_courses_features_default_profile2_type() {
  $items = array();
  $items['student'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "student",
    "label" : "Student",
    "weight" : "0",
    "data" : { "registration" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_workflow_default_workflows().
 */
function nm_section_courses_features_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: generic_solution_workflow
  $workflows['generic_solution_workflow'] = array(
    'name' => 'generic_solution_workflow',
    'tab_roles' => 2,
    'options' => 'a:4:{s:16:"comment_log_node";i:0;s:15:"comment_log_tab";i:0;s:13:"name_as_title";i:0;s:12:"watchdog_log";i:1;}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'generic_solution_workflow',
      ),
      1 => array(
        'state' => 'Entwurf',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'generic_solution_workflow',
      ),
      2 => array(
        'state' => 'Eingereicht',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'generic_solution_workflow',
      ),
      3 => array(
        'state' => 'Bewertet',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'generic_solution_workflow',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name',
        'state' => '(creation)',
        'target_state' => 'Entwurf',
      ),
      1 => array(
        'roles' => 'workflow_features_author_name',
        'state' => '(creation)',
        'target_state' => 'Eingereicht',
      ),
      2 => array(
        'roles' => 'workflow_features_author_name,Moderator,Dozent,Tutor',
        'state' => 'Entwurf',
        'target_state' => 'Eingereicht',
      ),
      3 => array(
        'roles' => 'Moderator,Dozent,Tutor',
        'state' => 'Entwurf',
        'target_state' => 'Bewertet',
      ),
      4 => array(
        'roles' => 'Moderator,Dozent,Tutor,Student,Test Student',
        'state' => 'Eingereicht',
        'target_state' => 'Entwurf',
      ),
      5 => array(
        'roles' => 'Moderator,Dozent,Tutor,Student,Test Student',
        'state' => 'Eingereicht',
        'target_state' => 'Bewertet',
      ),
      6 => array(
        'roles' => 'Moderator,Dozent,Tutor,Student,Test Student',
        'state' => 'Bewertet',
        'target_state' => 'Entwurf',
      ),
      7 => array(
        'roles' => 'Moderator,Dozent,Tutor,Student,Test Student',
        'state' => 'Bewertet',
        'target_state' => 'Eingereicht',
      ),
    ),
    'node_types' => array(
      0 => 'courses_generic_task_solution',
    ),
  );

  return $workflows;
}
