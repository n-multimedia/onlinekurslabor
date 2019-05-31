<?php

/**
 * @file
 * nm_administration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nm_administration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nm_administration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
