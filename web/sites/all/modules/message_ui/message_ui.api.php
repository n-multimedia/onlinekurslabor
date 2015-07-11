<?php

/**
 * @file
 * Defining the API part of the message UI module.
 */

/**
 * Implements hook_message_ui_view_alter().
 *
 * @param $build
 *  A render-able array which returned by the page callback function.
 * @param $message
 *  The message object.
 */
function hook_message_ui_view_alter(&$build, $message) {
  // Check the output of the message as you wish.
}
