<?php

/**
 * @file
 *   Shows the last status each user sent to the current user, if any.
 */

/**
 * Field handler to show the last status sent to the current user.
 */
class statuses_views_handler_field_last extends views_handler_field {
  function render($values) {
    global $user;
    $uid = $values->{$this->field_alias};
    $message = db_select('statuses')
      ->fields('statuses', array('message'))
      ->condition('type', 'user')
      ->condition('message', '', '<>')
      ->condition(db_or()
        ->condition(db_and()
          ->condition('sender', $user->uid)
          ->condition('recipient', $uid))
        ->condition(db_and()
          ->condition('sender', $uid)
          ->condition('recipient', $user->uid)))
      ->orderBy('sid', 'DESC')
      ->execute()
      ->fetchField();
    $message = _statuses_run_filter($message);
    if (variable_get('statuses_nl2br', 0)) {
      $message = nl2br($message);
    }
    return '<span class="statuses-content">' . $message . '</span>';
  }
}
