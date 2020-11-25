<?php

/**
 * @file
 * nm_general_features.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nm_general_features_filter_default_formats() {
  $formats = array();

  // Exported format: email-Filtered HTML.
  $formats['email_filtered_html'] = array(
    'format' => 'email_filtered_html',
    'name' => 'email-Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
