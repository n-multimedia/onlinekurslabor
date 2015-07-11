<?php

/**
 * @file
 *
 * Provides a handler that builds the string for node links we what to use with Linkit core.
 */
class linkit_picker_handler_field_node_info extends views_handler_field {

  function query() {
    // Do nothing, as this handler does not need to do anything to the query itself.
  }

  function render($values) {
    $nid = $values->nid;
    $title = $values->node_title;
    // $type = ucwords($values->node_type);
    $value = $title . ' [path:node/' . $nid . ']';
    return $value;
  }

}