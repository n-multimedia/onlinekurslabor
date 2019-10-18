<?php

/**
 * @file
 * nm_general_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nm_general_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'roles_hide_actions';
  $context->description = 'hide tabs above content';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'Autor' => 'Autor',
        'Dozent' => 'Dozent',
        'Kooperationspartner' => 'Kooperationspartner',
        'Student' => 'Student',
        'Test Student' => 'Test Student',
        'Tutor' => 'Tutor',
      ),
    ),
  );
  $context->reactions = array(
    'hide_local_tasks' => array(
      'hide_local_tasks' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('hide tabs above content');
  $export['roles_hide_actions'] = $context;

  return $export;
}
