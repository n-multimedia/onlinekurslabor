<?php

/**
 * @file
 * Views handler for the body content.
 */

class footnotes_views_handler_field_body_content extends footnotes_views_handler_field {

  /**
   * Function init().
   */
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
      $result = substr($data, 0, $start);
      $data = $result;
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
