<?php
/**
 * @file
 * Stub file for bootstrap_image_widget().
 */

/**
 * Returns HTML for an image field widget.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element representing the image field widget.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_image_widget()
 *
 * @ingroup theme_functions
 */
function bootstrap_image_widget($variables) {
  $element = $variables['element'];
  $output = '';
  $output .= '<div class="image-widget form-managed-file clearfix">';

  if (isset($element['preview'])) {
    $output .= '<div class="image-preview">';
    $output .= drupal_render($element['preview']);
    $output .= '</div>';
  }

  $output .= '<div class="image-widget-data">';
  if ($element['fid']['#value'] != 0) {
    $element['filename']['#markup'] = '<div class="form-group">' . $element['filename']['#markup'] . ' <span class="file-size badge">' . format_size($element['#file']->filesize) . '</span></div>';
  }
  else {
    $element['upload']['#prefix'] = '<div class="input-group">';
    $element['upload_button']['#prefix'] = '<span class="input-group-btn">';
    $element['upload_button']['#suffix'] = '</span></div>';
  }

  $output .= drupal_render_children($element);
  $output .= '</div>';
  $output .= '</div>';

  return $output;
}
