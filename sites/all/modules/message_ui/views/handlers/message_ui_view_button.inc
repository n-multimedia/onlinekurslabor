<?php

/**
 * Delete button for a message instance.
 */
class message_ui_view_button extends views_handler_field_entity {

  function render($values) {
    $message = message_load($values->mid);

    if (message_ui_access_control('view', $message)) {
      return l(t('View'), 'message/' . $message->mid);
    }
  }
}
