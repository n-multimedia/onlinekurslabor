<?php
/**
 * @file
 * nm_general_features.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function nm_general_features_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Support Formular zur Kontaktaufnahme';
  $fe_block_boxes->format = 'php_code';
  $fe_block_boxes->machine_name = 'support_formular';
  $fe_block_boxes->body = '<?php
echo support_form_page_callback();
?>';

  $export['support_formular'] = $fe_block_boxes;

  return $export;
}
