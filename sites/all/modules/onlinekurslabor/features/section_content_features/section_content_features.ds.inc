<?php
/**
 * @file
 * section_content_features.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function section_content_features_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'task';
  $ds_view_mode->label = 'Task';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['task'] = $ds_view_mode;

  return $export;
}
