<?php

/**
 * @file
 * nm_general_features.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function nm_general_features_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'file_icon';
  $ds_view_mode->label = 'File-Icon';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['file_icon'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'filename';
  $ds_view_mode->label = 'Filename';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['filename'] = $ds_view_mode;

  return $export;
}
