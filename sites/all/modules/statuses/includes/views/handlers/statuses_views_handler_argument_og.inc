<?php

/**
 * @file
 *   Show group statuses in user streams.
 */

/**
 * Limits statuses to those in the argument user's stream and in the argument user's groups' streams.
 */
class statuses_views_handler_argument_og extends views_handler_argument {
  function query() {
    // Unfortunately since OG uses entities heavily there isn't a simple way to
    // incorporate this into the main Views query.
    // OG 2.x can handle an ID instead of an entity object so we can drop the user_load().
    $groups = og_get_entity_groups('user', user_load($this->argument), array(OG_STATE_ACTIVE));

    $alias = $this->ensure_my_table();
    $where = db_and();
    $where
      ->condition("$alias.recipient", $this->argument)
      ->condition("$alias.type", 'user');
    if (empty($groups)) {
      $query = $where;
    }
    else {
      $query = db_or();
      $query->condition($where);
      $query->condition(db_and()
        ->condition("$alias.type", 'og')
        ->condition("$alias.recipient", $groups, 'IN')
      );
    }
    $this->query->add_where(0, $query);
  }
}
