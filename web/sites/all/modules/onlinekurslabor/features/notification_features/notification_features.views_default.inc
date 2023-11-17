<?php

/**
 * @file
 * notification_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function notification_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nm_activity_stream';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'NM Activity Stream';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'php';
  $handler->display->display_options['cache']['php_cache_results'] = 'return  _onlinekurslabor_cache_is_group_cache_valid(5,\'nm_activity_stream-results\')';
  $handler->display->display_options['cache']['php_cache_output'] = 'return _onlinekurslabor_cache_is_group_cache_valid(60,\'nm_activity_stream-output\')';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'collapse_wrapper';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_message_node_ref_target_id']['id'] = 'field_message_node_ref_target_id';
  $handler->display->display_options['relationships']['field_message_node_ref_target_id']['table'] = 'field_data_field_message_node_ref';
  $handler->display->display_options['relationships']['field_message_node_ref_target_id']['field'] = 'field_message_node_ref_target_id';
  $handler->display->display_options['relationships']['field_message_node_ref_target_id']['label'] = 'node_ref';
  $handler->display->display_options['relationships']['field_message_node_ref_target_id']['required'] = TRUE;
  /* Field: Message: Nachricht ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['label'] = 'Rendered Nachricht';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Content access: Access */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_message_node_ref_target_id';

  /* Display: Activity pane */
  $handler = $view->new_display('panel_pane', 'Activity pane', 'activity_display');
  $handler->display->display_options['display_description'] = 'shows activity ';
  $translatables['nm_activity_stream'] = array(
    t('Master'),
    t('more'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('node_ref'),
    t('Rendered Nachricht'),
    t('.'),
    t(','),
    t('1'),
    t('@count'),
    t('Activity pane'),
    t('shows activity '),
    t('View panes'),
  );
  $export['nm_activity_stream'] = $view;

  return $export;
}
