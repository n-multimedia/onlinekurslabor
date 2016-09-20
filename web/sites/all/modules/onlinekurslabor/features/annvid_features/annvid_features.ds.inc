<?php
/**
 * @file
 * annvid_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function annvid_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|annvid|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'annvid';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'annvid_codefield_get_player_code' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'annvid_codefield_load_stream' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'annvid_codefield_streamtimeline' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|annvid|default'] = $ds_fieldsetting;

  return $export;
}

