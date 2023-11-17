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
  $ds_fieldsetting->id = 'message|message_changed_node|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'message_changed_node';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'message_new' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['message|message_changed_node|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|message_changed_node|full';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'message_changed_node';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'message_new' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
    ),
  );
  $export['message|message_changed_node|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|message_new_node|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'message_new_node';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'message_new' => array(
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
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
      'format' => 'default',
      'label' => 'hidden',
      'weight' => '0',
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
  $ds_field->label = 'Message New|Changed';
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
  $ds_layout->id = 'message|message_changed_node|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'message_changed_node';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_new' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'message_new',
        1 => 'message__message_text__0',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['message|message_changed_node|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|message_changed_node|full';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'message_changed_node';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_new' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'message_new',
        1 => 'message__message_text__0',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['message|message_changed_node|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|message_new_node|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'message_new_node';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_new' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'message_new',
        1 => 'message__message_text__0',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
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
    'classes' => array(),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_new' => 'ds_content',
    ),
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_disable_css' => FALSE,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_wrapper' => 'div',
    'regions' => array(
      'ds_content' => array(
        0 => 'message_new',
        1 => 'message__message_text__0',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
  );
  $export['message|message_new_node|full'] = $ds_layout;

  return $export;
}
