<?php
/**
 * @file
 * section_projects_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function section_projects_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function section_projects_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function section_projects_features_image_default_styles() {
  $styles = array();

  // Exported image style: projects_logo.
  $styles['projects_logo'] = array(
    'label' => 'projects_logo',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
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
function section_projects_features_node_info() {
  $items = array(
    'projects_blog' => array(
      'name' => t('Projects - Tagebucheintrag'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'projects_cooperation_agreement' => array(
      'name' => t('Projects - Kooperationsvereinbarung'),
      'base' => 'node_content',
      'description' => t('Hierbei handelt es sich um eine gemeinsame Vereinbarung zwischen dem Praxispartner, Ihrem Team und Dozenten der Lehrveranstaltung, um die Erwartung bezüglich der Projektergebnisse zu klären. Die Vereinbarung ist für den Dozenten, den Praxispartner und die Studierendenteams sichtbar.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'projects_documentation' => array(
      'name' => t('Projects - Dokumentation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'projects_objective' => array(
      'name' => t('Projects - Lernzielvereinbarung'),
      'base' => 'node_content',
      'description' => t('Hierbei handelt es sich um eine individuelle Vereinbarung zwischen Ihnen und dem Dozenten der Lehrveranstaltung, um die fachlichen und überfachlichen Lernziele des Projekts festzulegen. Die Vereinbarung ist für Sie, den Dozenten, den Praxispartner und die Teammitglieder sichtbar.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'projects_organization' => array(
      'name' => t('Projects - Partnerorganisation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'projects_proposal' => array(
      'name' => t('Projects - Projektvorschlag'),
      'base' => 'node_content',
      'description' => t('Hierbei handelt es sich um einen Vorschlag für ein Projekt von einem Praxispartner. Die Projektvorschläge können jederzeit von einem Praxispartner eingereicht werden. Vor Semesterbeginn hat der Dozent dann die Möglichkeit passende Projektvorschläge für seine Lehrveranstaltungen auszuwählen und eine Kooperationsvereinbarung vorzubereiten.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_og_membership_type().
 */
function section_projects_features_default_og_membership_type() {
  $items = array();
  $items['og_projects_proposal_membership'] = entity_import('og_membership_type', '{
    "name" : "og_projects_proposal_membership",
    "description" : "og_projects_proposal_membership",
    "language" : "",
    "rdf_mapping" : []
  }');
  return $items;
}
