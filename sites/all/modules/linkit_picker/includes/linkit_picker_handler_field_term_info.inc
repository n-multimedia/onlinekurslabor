<?php

/**
 * @file
 *
 * Provides a handler that builds the string for term links we what to use with Linkit core.
 */
class linkit_picker_handler_field_term_info extends views_handler_field {

  function query() {
    // Do nothing, as this handler does not need to do anything to the query itself.
  }

  function render($values) {
    $tid = $values->tid;
    $term_data_name = $values->term_data_name;
    $path = taxonomy_term_path(taxonomy_get_term($tid));
    $value = $term_data_name . ' [path:' . $path . ']';
    return $value;
  }

}