<?php

/**
 * @file
 * environment_indicator_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function environment_indicator_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "environment_indicator" && $api == "default_environment_indicator_environments") {
    return array("version" => "1");
  }
}
