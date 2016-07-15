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

/**
 * Implements hook_ds_custom_fields_info().
 */
function annvid_features_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'annvid_codefield_get_player_code';
  $ds_field->label = 'AnnVid Codefield get Player Code';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
 return _AnnVid_getPlayerCode(arg(1));?>',
      'format' => 'php_code',
    ),
    'use_token' => 1,
  );
  $export['annvid_codefield_get_player_code'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'annvid_codefield_load_stream';
  $ds_field->label = 'annvid-codefield-load-stream';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
module_load_include(\'inc\', \'nm_stream\', \'inc/blocks\');
return _nm_stream_get_renderedGUI(arg(1));
?>',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['annvid_codefield_load_stream'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'annvid_codefield_streamtimeline';
  $ds_field->label = 'AnnVid - codefield - StreamTimeLine';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
return _AnnVid_getStreamTimeLine();
?>',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['annvid_codefield_streamtimeline'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function annvid_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|annvid|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'annvid';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_h5preference',
        3 => 'annvid_codefield_streamtimeline',
        4 => 'annvid_codefield_load_stream',
      ),
      'header' => array(
        1 => 'field_show_h5p_annotationlist',
        2 => 'annvid_codefield_get_player_code',
      ),
      'right' => array(
        5 => 'field_pdffile',
      ),
    ),
    'fields' => array(
      'field_h5preference' => 'left',
      'field_show_h5p_annotationlist' => 'header',
      'annvid_codefield_get_player_code' => 'header',
      'annvid_codefield_streamtimeline' => 'left',
      'annvid_codefield_load_stream' => 'left',
      'field_pdffile' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|annvid|default'] = $ds_layout;

  return $export;
}
