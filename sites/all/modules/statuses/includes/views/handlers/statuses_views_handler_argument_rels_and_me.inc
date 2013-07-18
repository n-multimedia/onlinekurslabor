<?php

/**
 * @file
 *   Allow only statuses from a user and that user's friends.
 */

/**
 * Argument handler to select statuses relevant to a user and that user's friends.
 */
class statuses_views_handler_argument_rels_and_me extends views_handler_argument {
  function query($group_by = FALSE) {
    $this->ensure_my_table();
    $alias = $this->query->ensure_table('users');
    $argument = $this->argument;
    $this->query->add_where(isset($this->options['group']) ? $this->options['group'] : 0, db_or()
      ->condition(db_and()
        ->condition(db_or()
          ->condition('requestee_id', $argument)
          ->condition('requester_id', $argument))
        ->condition('approved', 1))
      ->condition("$alias.uid", $argument));
  }
}
