<?php

/**
 * @file
 *  Handler for the 'Workflow: state change form' field.
 */

class workflow_extensions_handler_field_state_change_form extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  function access() {
    return user_access('access workflow summary views');
  }

  function query() {
    // Not calling parent::query() as it will treat this as a real db field.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $node = node_load($values->{$this->aliases['nid']});
    return workflow_extensions_change_state_form($node);
  }
}
