<?php

/**
 * @file
 * nm_stream_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nm_stream_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nm_stream_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nm_stream_features_image_default_styles() {
  $styles = array();

  // Exported image style: profile_stream_thumbnail.
  $styles['profile_stream_thumbnail'] = array(
    'label' => 'profile_stream_thumbnail',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 40,
          'height' => 40,
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
function nm_stream_features_node_info() {
  $items = array(
    'nm_stream' => array(
      'name' => t('NM Stream'),
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
