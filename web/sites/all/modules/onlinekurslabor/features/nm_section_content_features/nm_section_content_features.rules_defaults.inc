<?php

/**
 * @file
 * nm_section_content_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function nm_section_content_features_default_rules_configuration() {
  $items = array();
  $items['rules_domain_member_approved'] = entity_import('rules_config', '{ "rules_domain_member_approved" : {
      "LABEL" : "Domain Member Approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_insert" : [], "og_user_approved" : [] },
      "IF" : [
        { "AND" : [
            { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
            { "node_is_of_type" : {
                "node" : [ "og-membership:group" ],
                "type" : { "value" : { "content_domain" : "content_domain" } }
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
            "PROVIDE" : { "entity_fetched" : { "entity_domain" : "Fetched entity" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "[site:name] - Anmeldung f\\u00fcr [entity-domain:title]",
            "message" : "Hallo [account:name],\\r\\nSie sind nun im Lehrtext \\u0022[entity-domain:title]\\u0022 als aktives Mitglied eingetragen.\\r\\n\\r\\nLink zum Lehrtext: [entity-domain:url].\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]",
            "language" : [ "account:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_domain_member_subscribe'] = entity_import('rules_config', '{ "rules_domain_member_subscribe" : {
      "LABEL" : "Domain Member Subscribe",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og", "onlinekurslabor_rules" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "AND" : [
            { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
            { "node_is_of_type" : {
                "node" : [ "og-membership:group" ],
                "type" : { "value" : { "content_domain" : "content_domain" } }
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
            "PROVIDE" : { "entity_fetched" : { "entity_domain" : "Fetched entity" } }
          }
        },
        { "mail_to_user_roles_in_group" : {
            "group" : [ "entity-domain" ],
            "og_roles" : { "value" : [] },
            "subject" : "[entity-domain:title] - Anmeldung",
            "message" : "[account:name] m\\u00f6chte Mitglied im Lehrtext \\u0022[entity-domain:title]\\u0022 mit der Anfrage \\u0022[og-membership:og-membership-request]\\u0022 werden.\\r\\n\\r\\n\\u003Ca href=[site:url]\\/domain\\/members\\/[entity-domain:nid]\\u003EBest\\u00e4tigen oder Ablehnen\\u003C\\/a\\u003E\\r\\n\\r\\nViele Gr\\u00fc\\u00dfe\\r\\nDas Team vom [site:name]"
          }
        }
      ]
    }
  }');
  return $items;
}
