<?php

/**
 * @file
 *
 * Provides a handler that builds the string for user links we what to use with Linkit core.
 */
class linkit_picker_handler_field_user_info extends views_handler_field {

  function query() {
    // Do nothing, as this handler does not need to do anything to the query itself.
  }

  function render($values) {
    $uid = $values->uid;
    $users_name = $values->users_name;
    $value = $users_name . ' [path:user/' . $uid . ']';
    return $value;
  }

}