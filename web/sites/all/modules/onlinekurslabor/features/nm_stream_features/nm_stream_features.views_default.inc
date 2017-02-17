<?php
/**
 * @file
 * nm_stream_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nm_stream_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nm_stream';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'NM Stream';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['pager']['options']['waypoint']['infinite'] = 1;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'nm_stream';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="view-content">
<div class="views-row"></div>
</div>';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['id'] = 'field_nm_stream_context_target_id';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['field'] = 'field_nm_stream_context_target_id';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['ui_name'] = 'Context';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_nm_stream_context_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Container */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['ui_name'] = 'Container';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Privacy */
  $handler->display->display_options['arguments']['field_nm_privacy_value']['id'] = 'field_nm_privacy_value';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['table'] = 'field_data_field_nm_privacy';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['field'] = 'field_nm_privacy_value';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['ui_name'] = 'Privacy';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_nm_privacy_value']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nm_stream' => 'nm_stream',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['nm_stream'] = array(
    t('Master'),
    t('more'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Load more'),
    t('<div class="view-content">
<div class="views-row"></div>
</div>'),
    t('OG membership from node'),
    t('Alle'),
    t('Content pane'),
    t('View panes'),
  );
  $export['nm_stream'] = $view;

  return $export;
}
