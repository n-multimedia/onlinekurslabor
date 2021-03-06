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
  $items['nm_section_courses_features_courses_member_added'] = entity_import('rules_config', '{ "nm_section_courses_features_courses_member_added" : {
      "LABEL" : "Courses Member Added",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og", "rules_session_vars" ],
      "ON" : { "og_user_insert" : [], "og_user_approved" : [] },
      "IF" : [
        { "AND" : [
            { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
            { "node_is_of_type" : {
                "node" : [ "og-membership:group" ],
                "type" : { "value" : { "courses_course" : "courses_course" } }
              }
            },
            { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "2" : "2" } } } },
            { "og_user_in_group" : {
                "account" : [ "account" ],
                "group" : [ "og-membership:group" ],
                "states" : { "value" : { "1" : "1" } }
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
        { "load_data_from_session" : {
            "USING" : { "data_key" : "section_courses_new_member_add_welcome_message" },
            "PROVIDE" : { "loaded_session_data" : { "course_welcome_message" : "Course welcome message" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "[site:name] - Anmeldung f\\u00fcr [entity-course:title]",
            "message" : "Hallo [account:name],\\r\\nSie sind nun im Kurs \\u0022[entity-course:title]\\u0022 eingetragen.\\r\\n[course-welcome-message:value]\\r\\n\\r\\nLink zum Kurs: [entity-course:url].\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "account:language" ]
          }
        },
        { "remove_data_from_session" : { "data_key" : "section_courses_new_member_add_welcome_message" } }
      ]
    }
  }');
  $items['nm_section_courses_features_courses_member_unsubscribe'] = entity_import('rules_config', '{ "nm_section_courses_features_courses_member_unsubscribe" : {
      "LABEL" : "Courses Member Unsubscribe",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "onlinekurslabor_rules", "og" ],
      "ON" : { "og_user_delete" : [] },
      "IF" : [
        { "AND" : [
            { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
            { "node_is_of_type" : {
                "node" : [ "og-membership:group" ],
                "type" : { "value" : { "courses_course" : "courses_course" } }
              }
            },
            { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "2" : "2" } } } }
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
            "subject" : "[site:name] - Abmeldung von [entity-course:title]",
            "message" : "Hallo [account:name],\\r\\nSie sind nun aus dem Kurs \\u0022[entity-course:title]\\u0022 abgemeldet.\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "account:language" ]
          }
        },
        { "mail_to_user_roles_in_group" : {
            "group" : [ "entity-course" ],
            "og_roles" : { "value" : { "kurs-dozent" : "kurs-dozent", "kurs-tutor" : "kurs-tutor" } },
            "subject" : "[entity-course:title] - Abmeldung - [account:name]",
            "message" : "\\r\\n[account:name] hat sich \\/ wurde von dem Kurs \\u0022[entity-course:title]\\u0022 abgemeldet.\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]"
          }
        }
      ]
    }
  }');
  $items['nm_section_courses_features_rejected_solution_mail'] = entity_import('rules_config', '{ "nm_section_courses_features_rejected_solution_mail" : {
      "LABEL" : "Rejected solution: Mail",
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
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "node:author:uid" ] },
            "PROVIDE" : { "entity_fetched" : { "solutions_owner" : "Owner of solution" } }
          }
        },
        { "mail" : {
            "to" : "[solutions-owner:mail]",
            "subject" : "L\\u00f6sung zur\\u00fcckgewiesen",
            "message" : "Ihre L\\u00f6sung \\u0022[node:title]\\u0022 wurde zur\\u00fcckgewiesen mit der Bitte um \\u00dcberarbeitung.\\r\\n\\r\\nMehr dazu unter:\\r\\n[node:url]\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_course_forum_topic_created'] = entity_import('rules_config', '{ "rules_course_forum_topic_created" : {
      "LABEL" : "Course Forum Topic Created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "onlinekurslabor_rules" ],
      "ON" : { "node_insert--forum" : { "bundle" : "forum" } },
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:og-group-ref:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "course_fetched" : "Course" } }
          }
        },
        { "mail_to_user_roles_in_group" : {
            "group" : [ "course-fetched" ],
            "og_roles" : { "value" : {
                "kurs-dozent" : "kurs-dozent",
                "kurs-tutor" : "kurs-tutor",
                "kurs-student" : "kurs-student"
              }
            },
            "exlude_user" : [ "node:author:uid" ],
            "subject" : "[course-fetched:title] -  neues Thema im Forum",
            "message" : "\\r\\nes gibt ein neues Thema \\u0022[node:title]\\u0022 im Forum. \\r\\n\\r\\nLink zum Thema:\\r\\n[node:url]\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]"
          }
        }
      ]
    }
  }');
  $items['rules_course_forum_topic_reply'] = entity_import('rules_config', '{ "rules_course_forum_topic_reply" : {
      "LABEL" : "Course Forum Topic Reply",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : { "comment_insert--comment_node_forum" : { "bundle" : "comment_node_forum" } },
      "IF" : [
        { "NOT data_is" : { "data" : [ "comment:node:author" ], "value" : [ "comment:author" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "comment:node:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "course_fetched" : "Course" } }
          }
        },
        { "mail" : {
            "to" : [ "comment:node:author:mail" ],
            "subject" : "[course-fetched:title] - Es gibt eine neue Antwort in Ihrem Foren-Thema",
            "message" : "Hallo [comment:node:author],\\r\\nes gibt eine neue Antwort im Foren-Thema \\u0022[comment:node:title]\\u0022.\\r\\n\\r\\nLink zum Kommentar:\\r\\n[comment:url]\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_course_task_assessed'] = entity_import('rules_config', '{ "rules_course_task_assessed" : {
      "LABEL" : "Course Task Assessed",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : { "workflow_state_changed" : [] },
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
            "message" : "Hallo [node:author],\\r\\nIhre L\\u00f6sung f\\u00fcr die Aufgabe [node:title] wurde bewertet. \\r\\n\\r\\nLink zur Bewertung:\\r\\n[node:url]\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_course_task_submitted'] = entity_import('rules_config', '{ "rules_course_task_submitted" : {
      "LABEL" : "Course Task Submitted",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workflow_rules", "rules", "onlinekurslabor_rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "AND" : [
            { "workflow_check_transition" : {
                "node" : [ "node" ],
                "old_state" : { "value" : { "1" : "1", "2" : "2" } },
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
            "og_roles" : { "value" : { "kurs-dozent" : "kurs-dozent", "kurs-tutor" : "kurs-tutor" } },
            "subject" : "[course-fetched:title] - [node:title] - wurde eingereicht",
            "message" : "\\r\\n\\r\\neine L\\u00f6sung f\\u00fcr die Aufgabe \\u0022[node:title]\\u0022 wurde eingereicht. \\r\\n\\r\\nLink zur L\\u00f6sung:\\r\\n[node:url]\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]"
          }
        }
      ]
    }
  }');
  $items['rules_courses_member_subscribe'] = entity_import('rules_config', '{ "rules_courses_member_subscribe" : {
      "LABEL" : "Courses Member Subscribe",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og", "onlinekurslabor_rules" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "AND" : [
            { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
            { "node_is_of_type" : {
                "node" : [ "og-membership:group" ],
                "type" : { "value" : { "courses_course" : "courses_course" } }
              }
            },
            { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "2" : "2" } } } },
            { "og_user_in_group" : {
                "account" : [ "account" ],
                "group" : [ "og-membership:group" ],
                "states" : { "value" : { "2" : "2" } }
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
            "message" : "Hallo [account:name],\\r\\n\\r\\ndanke f\\u00fcr Ihre Anmeldung zu \\u0022[entity-course:title]\\u0022.\\r\\n\\r\\nDie Anfrage \\u0022[og-membership:og-membership-request]\\u0022 wurde zur \\u00dcberpr\\u00fcfung hinterlegt.\\r\\n\\r\\nLink zum Kurs: [entity-course:url].\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "account:language" ]
          }
        },
        { "mail_to_user_roles_in_group" : {
            "group" : [ "entity-course" ],
            "og_roles" : { "value" : { "kurs-dozent" : "kurs-dozent", "kurs-tutor" : "kurs-tutor" } },
            "subject" : "[entity-course:title] - Anmeldung - [account:name]",
            "message" : "\\r\\n[account:name] m\\u00f6chte am Kurs \\u0022[entity-course:title]\\u0022 mit der Anfrage \\u0022[og-membership:og-membership-request]\\u0022 teilnehmen.\\r\\n\\r\\n\\u003Ca href=[site:url]\\/course\\/admin\\/[entity-course:nid]\\/members\\u003EBest\\u00e4tigen oder Ablehnen\\u003C\\/a\\u003E\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]"
          }
        }
      ]
    }
  }');
  return $items;
}
