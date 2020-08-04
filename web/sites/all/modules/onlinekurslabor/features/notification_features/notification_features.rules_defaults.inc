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
  $items['notification_features_chnd_msg_solution_assessed'] = entity_import('rules_config', '{ "notification_features_chnd_msg_solution_assessed" : {
      "LABEL" : "Changed Node Message: L\\u00f6sung bewertet",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "AND" : [
            { "node_is_of_type" : {
                "node" : [ "node" ],
                "type" : { "value" : { "courses_generic_task_solution" : "courses_generic_task_solution" } }
              }
            },
            { "workflow_check_transition" : {
                "node" : [ "node" ],
                "old_state" : { "value" : { "3" : "3" } },
                "new_state" : { "value" : { "4" : "4" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "message_changed_node",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_changed" : "Changed entity" } }
          }
        },
        { "data_set" : { "data" : [ "entity-changed:arguments:action" ], "value" : "assessed" } },
        { "data_set" : {
            "data" : [ "entity-changed:field-message-node-ref" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-changed:arguments:printable-node-type" ],
            "value" : "solution"
          }
        }
      ]
    }
  }');
  $items['notification_features_chnd_msg_solution_rejected'] = entity_import('rules_config', '{ "notification_features_chnd_msg_solution_rejected" : {
      "LABEL" : "Changed Node Message: L\\u00f6sung zur\\u00fcckgewiesen",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "AND" : [
            { "node_is_of_type" : {
                "node" : [ "node" ],
                "type" : { "value" : { "courses_generic_task_solution" : "courses_generic_task_solution" } }
              }
            },
            { "workflow_check_transition" : {
                "node" : [ "node" ],
                "old_state" : { "value" : { "3" : "3", "4" : "4" } },
                "new_state" : { "value" : { "2" : "2" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "message",
              "param_type" : "message_changed_node",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_changed" : "Changed entity" } }
          }
        },
        { "data_set" : { "data" : [ "entity-changed:arguments:action" ], "value" : "rejected" } },
        { "data_set" : {
            "data" : [ "entity-changed:field-message-node-ref" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-changed:arguments:printable-node-type" ],
            "value" : "solution"
          }
        }
      ]
    }
  }');
  $items['rules_new_node_message'] = entity_import('rules_config', '{ "rules_new_node_message" : {
      "LABEL" : "New Node Message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php" ],
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
        },
        { "data_set" : {
            "data" : [ "entity-created:arguments:printable-node-type" ],
            "value" : "\\u003C?php echo _custom_general_get_printable_contenttype_name($node-\\u003Etype);?\\u003E"
          }
        }
      ]
    }
  }');
  return $items;
}
