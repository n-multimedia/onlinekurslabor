<?php
/**
 * @file
 * nm_section_content_features.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function nm_section_content_features_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_12';
  $ds_view_mode->label = 'Media_12';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_12'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_3';
  $ds_view_mode->label = 'Media_3';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_3'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_4';
  $ds_view_mode->label = 'Media_4';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_4'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_6';
  $ds_view_mode->label = 'Media_6';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_6'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'media_9';
  $ds_view_mode->label = 'Media_9';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['media_9'] = $ds_view_mode;

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
