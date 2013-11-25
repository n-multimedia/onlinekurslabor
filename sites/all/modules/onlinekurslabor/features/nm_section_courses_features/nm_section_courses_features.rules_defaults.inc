<?php
/**
 * @file
 * nm_section_courses_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nm_section_courses_features_default_rules_configuration() {
  $items = array();
  $items['rules_course_task_assessed'] = entity_import('rules_config', '{ "rules_course_task_assessed" : {
      "LABEL" : "Course Task Assessed",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "AND" : [
            { "workflow_check_transition" : {
                "node" : [ "node" ],
                "old_state" : { "value" : { "3" : "3" } },
                "new_state" : { "value" : { "4" : "4" } }
              }
            },
            { "node_is_of_type" : {
                "node" : [ "node" ],
                "type" : { "value" : { "courses_generic_task_solution" : "courses_generic_task_solution" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:og-group-ref:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "course_fetched" : "Course" } }
          }
        },
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "[course_fetched:title] - [node:title] - wurde bewertet",
            "message" : "Hallo,\\r\\nIhre L\\u00f6sung f\\u00fcr die Aufgabe [node:title] wurde bewertet. \\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_course_task_submitted'] = entity_import('rules_config', '{ "rules_course_task_submitted" : {
      "LABEL" : "Course Task Submitted",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "workflow_rules", "rules", "onlinekurslabor_rules" ],
      "ON" : [ "workflow_state_changed" ],
      "IF" : [
        { "AND" : [
            { "workflow_check_transition" : {
                "node" : [ "node" ],
                "old_state" : { "value" : { "2" : "2" } },
                "new_state" : { "value" : { "3" : "3" } }
              }
            },
            { "node_is_of_type" : {
                "node" : [ "node" ],
                "type" : { "value" : { "courses_generic_task_solution" : "courses_generic_task_solution" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:og-group-ref:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "course_fetched" : "Course" } }
          }
        },
        { "mail_to_user_roles_in_group" : {
            "group" : [ "course-fetched" ],
            "roles" : { "value" : { "106505419" : "106505419" } },
            "subject" : "[course-fetched:title] - [node:title] - wurde eingereicht",
            "message" : "Hallo,\\r\\neine L\\u00f6sung f\\u00fcr die Aufgabe \\u0022[node:title]\\u0022 wurde eingereicht. \\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]"
          }
        }
      ]
    }
  }');
  $items['rules_courses_member_subscribe'] = entity_import('rules_config', '{ "rules_courses_member_subscribe" : {
      "LABEL" : "Courses Member Subscribe",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "onlinekurslabor_rules", "og" ],
      "ON" : [ "og_user_insert" ],
      "IF" : [
        { "AND" : [
            { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
            { "node_is_of_type" : {
                "node" : [ "og-membership:group" ],
                "type" : { "value" : { "courses_course" : "courses_course" } }
              }
            },
            { "user_has_role" : {
                "account" : [ "account" ],
                "roles" : { "value" : { "66784200" : "66784200" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "og-membership:group:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_course" : "Fetched entity" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "[site:name] - Anmeldung f\\u00fcr [entity-course:title]",
            "message" : "Hallo [account:name],\\r\\ndanke f\\u00fcr deine Anmeldung. Du bist nun f\\u00fcr den Kurs [entity-course:title] eingetragen.\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "account:language" ]
          }
        },
        { "mail_to_user_roles_in_group" : {
            "group" : [ "entity-course" ],
            "roles" : { "value" : { "106505419" : "106505419" } },
            "subject" : "[entity-course:title] - Anmeldung - [account:name]",
            "message" : "Hallo,\\r\\nder Benutzer \\u0022[account:name]\\u0022 hat sich f\\u00fcr den Kurs \\u0022[entity-course:title]\\u0022 angemeldet.\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]"
          }
        }
      ]
    }
  }');
  return $items;
}
