<?php
/**
 * @file
 * videosafe_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function videosafe_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function videosafe_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function videosafe_features_node_info() {
  $items = array(
    'videosafe_folder' => array(
      'name' => t('VideoSafe - Folder'),
      'base' => 'node_content',
      'description' => t('Videos werden in Ordnern gespeichert'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'videosafe_video' => array(
      'name' => t('VideoSafe - Video'),
      'base' => 'node_content',
      'description' => t('Ein geschütztes Video, das in einer Folder organisiert wird'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
