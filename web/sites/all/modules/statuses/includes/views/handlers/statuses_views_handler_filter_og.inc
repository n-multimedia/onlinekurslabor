<?php

/**
 * @file
 *   Show group statuses in user streams.
 */

/**
 * Limits statuses to those in the current user's stream and in the current user's groups' streams.
 */
class statuses_views_handler_filter_og extends views_handler_filter {
  function query() {
    global $user;

    // Unfortunately since OG uses entities heavily there isn't a simple way to
    // incorporate this into the main Views query.
    $groups = og_get_entity_groups('user', $user, array(OG_STATE_ACTIVE));

    $alias = $this->ensure_my_table();
    $where = db_and();
    $where
      ->condition("$alias.recipient", $user->uid)
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
