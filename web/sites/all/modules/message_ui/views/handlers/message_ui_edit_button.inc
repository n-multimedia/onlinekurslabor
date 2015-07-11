<?php

/**
 * Edit button for a message instance.
 */
class message_ui_edit_button extends views_handler_field_entity {

  function render($values) {
    $message = message_load($values->mid);

    if (message_ui_access_control('edit', $message)) {
      return l(t('Edit'), 'message/' . $message->mid . '/edit');
    }
  }
}
