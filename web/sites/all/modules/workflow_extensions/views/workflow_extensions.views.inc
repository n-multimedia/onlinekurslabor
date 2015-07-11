<?php

/**
 * @file
 *  Declare new and alter workflow fields, sorts and filters.
 */

/**
 * Implementation of hook_views_data().
 *
 * Ommitted, we're altering existing groups, not creating a new one.
 *
 function workflow_extensions_views_data() {
 }
 */

/**
 * Implements hook_views_data_alter().
 */
function workflow_extensions_views_data_alter(&$data) {
  $data['workflow_node']['state_change_form'] = array(
    'title' => t('State transition form'),
    'help' => t("Display a form to transition the node's workflow state"),
    'field' => array(
      'handler' => 'workflow_extensions_handler_field_state_change_form',
      'click sortable' => FALSE,
    ),
  );
  $data['workflow_node_history']['hid'] = array(
    'title' => t('Hid'),
    'help' => t('Unique number for state transition log record'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'numeric' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['workflow_node_history']['uid'] = array(
    'title' => t('User'),
    'help' => t('Relate this transition record to the user who transitioned state.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('user'),
    ),
  );
  $data['workflow_node_history']['edit_comment'] = array(
    'title' => t('Edit comment'),
    'help' => t('Provide a link to edit the workflow log comment.'),
    'field' => array(
      'handler' => 'workflow_extensions_handler_field_workflow_comment_link_edit',
    ),
  );

  return;
}

/**
 * Implements hook_views_handlers().
 *
 * Register the handlers used in Workflow Extensions views.
 */
function workflow_extensions_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'workflow_extensions') . '/views',
    ),
    'handlers' => array(
      'workflow_extensions_handler_field_state_change_form' => array('parent' => 'views_handler_field'),
      'workflow_extensions_handler_field_workflow_comment_link_edit' => array('parent' => 'views_handler_field'),
    ),
  );
}
