<?php
/**
 * @file
 * nm_section_courses_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nm_section_courses_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'instructor_frontpage';
  $context->description = 'Sets courses-overview as instructor\'s <front> page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'Dozent' => 'Dozent',
      ),
    ),
  );
  $context->reactions = array(
    'context_redirect' => array(
      'redirect_path' => 'courses',
      'enable_message' => 0,
      'redirect_message' => '',
      'qsa' => 1,
      'redirect_type' => '302',
      'admin_key' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets courses-overview as instructor\'s <front> page');
  $export['instructor_frontpage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_courses';
  $context->description = 'Signals that Courses-Section is active';
  $context->tag = '';
  $context->conditions = array(
    'custom_general_condition_section_courses' => array(
      'values' => array(
        'courses_course' => 'courses_course',
        'courses_group' => 'courses_group',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Signals that Courses-Section is active');
  $export['section_courses'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_courses_course';
  $context->description = 'Signals that a Course in Courses-Section is active';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'section_courses' => 'section_courses',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Signals that a Course in Courses-Section is active');
  $export['section_courses_course'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_courses_course_instructor_tools';
  $context->description = 'Displays course tools for instructors';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'section_courses_course' => 'section_courses_course',
      ),
    ),
    'user' => array(
      'values' => array(
        'Dozent' => 'Dozent',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Displays course tools for instructors');
  $export['section_courses_course_instructor_tools'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_courses_course_navigation';
  $context->description = 'Sets navigation blocks when courses content active.';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'section_courses_course' => 'section_courses_course',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'section_courses-course_header_section' => array(
          'module' => 'section_courses',
          'delta' => 'course_header_section',
          'region' => 'header',
          'weight' => '-10',
        ),
        'section_courses-course_top_navigation' => array(
          'module' => 'section_courses',
          'delta' => 'course_top_navigation',
          'region' => 'header',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets navigation blocks when courses content active.');
  $export['section_courses_course_navigation'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'student_frontpage';
  $context->description = 'Sets courses-overview as student\'s <front> page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'Student' => 'Student',
      ),
    ),
  );
  $context->reactions = array(
    'context_redirect' => array(
      'redirect_path' => 'courses',
      'enable_message' => 0,
      'redirect_message' => '',
      'qsa' => 1,
      'redirect_type' => '302',
      'admin_key' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets courses-overview as student\'s <front> page');
  $export['student_frontpage'] = $context;

  return $export;
}
