<?php
/**
 * @file
 * section_content_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function section_content_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'author_frontpage';
  $context->description = 'Sets domain-overview as author\'s <front> page';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'Autor' => 'Autor',
      ),
    ),
  );
  $context->reactions = array(
    'context_redirect' => array(
      'redirect_path' => 'node/7',
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
  t('Sets domain-overview as author\'s <front> page');
  $export['author_frontpage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_content';
  $context->description = 'Signals that Content-Section is active';
  $context->tag = '';
  $context->conditions = array(
    'custom_general_condition_section_content' => array(
      'values' => array(
        'content_domain' => 'content_domain',
      ),
    ),
  );
  $context->reactions = array(
    'debug' => array(
      'debug' => 1,
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Signals that Content-Section is active');
  $export['section_content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'section_content_domain_blocks';
  $context->description = 'displays domain specific blocks';
  $context->tag = '';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'section_content' => 'section_content',
      ),
    ),
    'context_og_condition_member_status' => array(
      'values' => array(
        1 => 1,
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'Autor' => 'Autor',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'section_content-content_node_tabs' => array(
          'module' => 'section_content',
          'delta' => 'content_node_tabs',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'sidebar_first',
          'weight' => '-16',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => '1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
    'debug' => array(
      'debug' => 1,
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('displays domain specific blocks');
  $export['section_content_domain_blocks'] = $context;

  return $export;
}
