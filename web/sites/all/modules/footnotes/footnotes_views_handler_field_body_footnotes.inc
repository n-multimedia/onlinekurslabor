<?php

/**
 * @file
 * Views handler for the body footnotes.
 */

class footnotes_views_handler_field_body_footnotes extends footnotes_views_handler_field {

  function init(&$view, $options) {
    parent::init($view, $options);
  }

  /**
   * Function render_name().
   */
  function render_name($data, $values) {
    $start = strpos($data, '<ul class="footnotes">');
    // By default footnotes are at the end, but they could be anywhere really.
    if ($start !== FALSE) {
      $data = substr($data, $start);
    }
    else {
      // There are no footnotes.
      $data = '';
    }
    return $data;
  }

  /**
   * Function render().
   */
  function render($values) {
    $body = parent::render($values);
    return $this->render_link($this->render_name($body, $values), $values);
  }

}
