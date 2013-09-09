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
    'name' => 'course_header',
    'label' => 'course_header',
    'effects' => array(
      6 => array(
        'label' => 'Skalieren und zuschneiden',
        'help' => 'Skalieren und zuschneiden wird das Seitenverhältnis des ursprünglichen Bildes erhalten, und dann die überstehenden Ränder entfernen. Dies ist besonders nützlich für die Erstellung von perfekt quadratischen Vorschaubildern ohne Verzerrung des Bildes.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1170,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: course_overview_image.
  $styles['course_overview_image'] = array(
    'name' => 'course_overview_image',
    'label' => 'course_overview_image',
    'effects' => array(
      12 => array(
        'label' => 'Skalieren und zuschneiden',
        'help' => 'Skalieren und zuschneiden wird das Seitenverhältnis des ursprünglichen Bildes erhalten, und dann die überstehenden Ränder entfernen. Dies ist besonders nützlich für die Erstellung von perfekt quadratischen Vorschaubildern ohne Verzerrung des Bildes.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'course_sponsor_logo',
    'label' => 'course_sponsor_logo',
    'effects' => array(
      13 => array(
        'label' => 'Skalierung',
        'help' => 'Eine Skalierung behält das Seitenverhältnis des Originalbildes bei. Sofern nur eine Seitenlänge angegeben ist, wird die andere berechnet.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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
      'title_label' => t('Title'),
      'help' => '',
    ),
    'courses_docs' => array(
      'name' => t('Courses - Kursdokument'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'courses_generic_task' => array(
      'name' => t('Courses - Generische Aufgabe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'courses_generic_task_solution' => array(
      'name' => t('Courses - Generische Lösung'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'courses_group' => array(
      'name' => t('Courses - Kursgruppe'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'courses_news' => array(
      'name' => t('Courses - Ankündigung'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
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
    "rdf_mapping" : [  ]
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
        'roles' => '',
        'state' => '(creation)',
        'target_state' => 'Bewertet',
      ),
      3 => array(
        'roles' => 'workflow_features_author_name,Dozent,Moderator',
        'state' => 'Entwurf',
        'target_state' => 'Eingereicht',
      ),
      4 => array(
        'roles' => 'Dozent,Moderator',
        'state' => 'Entwurf',
        'target_state' => 'Bewertet',
      ),
      5 => array(
        'roles' => 'Dozent,Moderator',
        'state' => 'Eingereicht',
        'target_state' => 'Entwurf',
      ),
      6 => array(
        'roles' => 'Dozent,Moderator',
        'state' => 'Eingereicht',
        'target_state' => 'Bewertet',
      ),
      7 => array(
        'roles' => 'Dozent,Moderator',
        'state' => 'Bewertet',
        'target_state' => 'Entwurf',
      ),
      8 => array(
        'roles' => 'Dozent,Moderator',
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
