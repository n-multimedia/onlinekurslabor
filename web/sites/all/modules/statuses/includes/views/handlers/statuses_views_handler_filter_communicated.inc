<?php

/**
 * @file
 *   Shows only users who have sent status messages to or received status messages from the current user.
 */

/**
 * Shows only users who have sent status messages to or received status messages from the current user.
 */
class statuses_views_handler_filter_communicated extends views_handler_filter {
  function query() {
    global $user;
    $this->ensure_my_table();
    $alias = $this->query->ensure_table('users');
    $recipient_sub_query = db_select('statuses')
      ->fields('statuses', array('recipient'))
      ->condition('type', 'user')
      ->condition('sender', $user->uid);
    $sender_sub_query = db_select('statuses')
      ->fields('statuses', array('sender'))
      ->condition('type', 'user')
      ->condition('recipient', $user->uid);
    $this->query->add_where(0, db_and()
      ->condition(db_or()->condition("$alias.uid", $recipient_sub_query, 'IN')->condition("$alias.uid", $sender_sub_query, 'IN'))
      ->condition("$alias.uid", $user->uid));
  }
}
