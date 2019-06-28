<?php

/**
 * @file
 * annvid_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function annvid_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function annvid_features_node_info() {
  $items = array(
    'annvid' => array(
      'name' => t('AnnVid'),
      'base' => 'node_content',
      'description' => t('Container for the content of annvid (video & pdf)'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
