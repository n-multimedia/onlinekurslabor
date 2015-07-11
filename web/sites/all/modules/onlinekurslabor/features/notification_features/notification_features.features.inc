<?php
/**
 * @file
 * notification_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function notification_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function notification_features_default_message_type() {
  $items = array();
  $items['message_new_node'] = entity_import('message_type', '{
    "name" : "message_new_node",
    "description" : "New Node",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : { "de" : [
        { "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E", "format" : "filtered_html" }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
