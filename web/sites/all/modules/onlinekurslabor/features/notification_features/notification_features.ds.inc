<?php
/**
 * @file
 * notification_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function notification_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|message_new_node|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'message_new_node';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'message_new' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|message_new_node|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|message_new_node|full';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'message_new_node';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'message_new' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|message_new_node|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function notification_features_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'message_new';
  $ds_field->label = 'Message New';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'message' => 'message',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array();
  $export['message_new'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function notification_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|message_new_node|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'message_new_node';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message_new',
      ),
    ),
    'fields' => array(
      'message_new' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['message|message_new_node|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|message_new_node|full';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'message_new_node';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message_new',
      ),
    ),
    'fields' => array(
      'message_new' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['message|message_new_node|full'] = $ds_layout;

  return $export;
}
