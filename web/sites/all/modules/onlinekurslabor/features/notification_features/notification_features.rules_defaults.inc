<?php

/**
 * @file
 * notification_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function notification_features_default_rules_configuration() {
  $items = array();
  $items['rules_new_node_message'] = entity_import('rules_config', '{ "rules_new_node_message" : {
      "LABEL" : "New Node Message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "courses_news" : "courses_news",
                "courses_generic_task" : "courses_generic_task",
                "courses_generic_task_solution" : "courses_generic_task_solution",
                "courses_docs" : "courses_docs",
                "courses_group" : "courses_group",
                "forum" : "forum"
              }
            }
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "message_new_node",
              "param_user" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-message-node-ref" ],
            "value" : [ "node" ]
          }
        }
      ]
    }
  }');
  return $items;
}
