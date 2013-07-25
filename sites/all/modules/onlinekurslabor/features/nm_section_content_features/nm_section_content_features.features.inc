<?php
/**
 * @file
 * nm_section_content_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nm_section_content_features_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nm_section_content_features_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nm_section_content_features_node_info() {
  $items = array(
    'content_chapter' => array(
      'name' => t('Content - Kapitel'),
      'base' => 'node_content',
      'description' => t('Kapitel der Lehrtexte, die durch ein Gebiet zusammengefasst werden.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'content_domain' => array(
      'name' => t('Content - Thema'),
      'base' => 'node_content',
      'description' => t('Das Themastellt einen themenspezifischen Container für (multimediale) Kapitel und Bibliografien dar.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'content_multiple_choice' => array(
      'name' => t('Content - Multiple Choice'),
      'base' => 'node_content',
      'description' => t('Multiple Choice Fragen für Studientexte'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'content_question_and_answer' => array(
      'name' => t('Content - Frage und Antwort'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
