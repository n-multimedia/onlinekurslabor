<?php

/**
 * @file
 * notification_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function notification_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function notification_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function notification_features_default_message_type() {
  $items = array();
  $items['message_changed_node'] = entity_import('message_type', '{
    "name" : "message_changed_node",
    "description" : "Changed Node",
    "argument_keys" : [ "@action", "@printable_node_type" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "@action a @printable_node_type",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E@action a @printable_node_type\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['message_new_node'] = entity_import('message_type', '{
    "name" : "message_new_node",
    "description" : "New Node",
    "argument_keys" : [ "@printable_node_type" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "created a @printable_node_type",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003Ecreated a @printable_node_type\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
