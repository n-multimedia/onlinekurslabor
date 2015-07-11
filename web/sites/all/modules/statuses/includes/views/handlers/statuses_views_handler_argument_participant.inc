<?php

/**
 * @file
 *   Allow only statuses where a given user is a participant.
 */

/**
 * Argument handler to select statuses where a given user is a participant.
 */
class statuses_views_handler_argument_participant extends views_handler_argument {
  function query($group_by = FALSE) {
    $this->ensure_my_table();
    $argument = $this->argument;
    $this->query->add_where(0, db_or()
        ->condition("$this->table_alias.sender", $argument)
        ->condition(db_and()
          ->condition("$this->table_alias.recipient", $argument)
          ->condition("$this->table_alias.type", 'user')));
  }
}
