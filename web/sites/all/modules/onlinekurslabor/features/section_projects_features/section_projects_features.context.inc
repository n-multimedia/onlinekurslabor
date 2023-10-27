<?php

/**
 * @file
 * section_projects_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function section_projects_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_projects';
  $context->description = 'Signals that Projects-Section is active';
  $context->tag = '';
  $context->conditions = array(
    'custom_general_condition_section_projects' => array(
      'values' => array(
        'projects_cooperation_agreement' => 'projects_cooperation_agreement',
        'projects_organization' => 'projects_organization',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Signals that Projects-Section is active');
  $export['section_projects'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_projects_project';
  $context->description = 'Signals that a Cooperation partner or Cockpit is active.';
  $context->tag = '';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        'section_projects' => 'section_projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'section_projects-projects_header_and_navigation' => array(
          'delta' => 'projects_header_and_navigation',
          'module' => 'section_projects',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Signals that a Cooperation partner or Cockpit is active.');
  $export['section_projects_project'] = $context;

  return $export;
}
