<?php

/**
 * @file
 * Views handler field.
 */

class footnotes_views_handler_field extends views_handler_field_markup {

  /**
   * Function init().
   */
  function init(&$view, $options) {
    parent::init($view, $options);
  }

  /**
   * Function render_link().
   */
  function render_link($data, $values) {
    return $data;
  }

}

