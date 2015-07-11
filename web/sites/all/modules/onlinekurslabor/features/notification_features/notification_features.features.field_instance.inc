<?php
/**
 * @file
 * notification_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function notification_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'message-message_new_node-field_message_node_ref'
  $field_instances['message-message_new_node-field_message_node_ref'] = array(
    'bundle' => 'message_new_node',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'field_message_node_ref',
    'label' => 'Node',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Node');

  return $field_instances;
}
