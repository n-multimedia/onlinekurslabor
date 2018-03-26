<?php

/**
 * @file
 * Display Suite footnotes field ui file.
 */

/**
 * Renders footnotes field.
 *
 * @param array $field
 *   The field array.
 *
 * @return string
 *   The rendered HTML.
 */
function _footnotes_field_render($field) {
  $render = array(
    '#prefix' => '<div id="footnotes-all">',
    '#markup' => NULL,
    '#suffix' => '</div>',
    '#attached' => array(
      'js' => array(
        array(
          'data' => drupal_get_path('module', 'footnotes_field') . '/js/footnotes_field.js',
          'type' => 'file',
        ),
      ),
      'css' => array(
        array(
          'data' => drupal_get_path('module', 'footnotes_field') . '/css/footnotes_field.css',
          'type' => 'file',
        ),
      ),
    ),
  );
  return drupal_render($render);
}
