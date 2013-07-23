<?php
/**
 * @file
 * nm_section_content_features.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nm_section_content_features_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_html' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<h1> <h2> <h3> <h4> <h5> <h6> <a> <p> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <bib> <ibib> <img>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(),
      ),
      'biblio_filter_reference' => array(
        'weight' => -41,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -39,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_content_tasks' => array(
        'weight' => -38,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
