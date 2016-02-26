<?php
/**
 * @file
 * videosafe_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function videosafe_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'videosafe_folderview';
  $view->description = 'All panes for the content-type videosafe';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'VideoSafe - FolderView';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Inhalt: Ordner */
  $handler->display->display_options['fields']['field_parent_folder']['id'] = 'field_parent_folder';
  $handler->display->display_options['fields']['field_parent_folder']['table'] = 'field_data_field_parent_folder';
  $handler->display->display_options['fields']['field_parent_folder']['field'] = 'field_parent_folder';
  $handler->display->display_options['fields']['field_parent_folder']['label'] = '';
  $handler->display->display_options['fields']['field_parent_folder']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_parent_folder']['alter']['path'] = 'videosafe/[field_parent_folder-target_id]';
  $handler->display->display_options['fields']['field_parent_folder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_parent_folder']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Inhalt: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Inhalt: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videosafe_folder' => 'videosafe_folder',
  );

  /* Display: parent folder */
  $handler = $view->new_display('panel_pane', 'parent folder', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'show a link to the parent folder of the actual folder';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_parent_folder' => 'field_parent_folder',
    'nid' => 'nid',
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['regions'] = array(
    'field_parent_folder' => 'left',
    'nid' => 'left',
    'title' => 'left',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Ordner */
  $handler->display->display_options['fields']['field_parent_folder']['id'] = 'field_parent_folder';
  $handler->display->display_options['fields']['field_parent_folder']['table'] = 'field_data_field_parent_folder';
  $handler->display->display_options['fields']['field_parent_folder']['field'] = 'field_parent_folder';
  $handler->display->display_options['fields']['field_parent_folder']['label'] = '';
  $handler->display->display_options['fields']['field_parent_folder']['alter']['path'] = 'videosafe/[field_parent_folder-target_id]';
  $handler->display->display_options['fields']['field_parent_folder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_parent_folder']['settings'] = array(
    'link' => 1,
  );
  /* Feld: Inhalt: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '&nbsp;&gt;&nbsp;';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videosafe_folder' => 'videosafe_folder',
    'videosafe_video' => 'videosafe_video',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:node.members--1',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: Nid',
    ),
  );

  /* Display: subfolders */
  $handler = $view->new_display('panel_pane', 'subfolders', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Unterordner';
  $handler->display->display_options['display_description'] = 'shows a list of the subfolders';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'last_updated' => 'last_updated',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Beschreibung';
  /* Feld: Inhalt: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Letzte Änderung';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'custom';
  $handler->display->display_options['fields']['last_updated']['custom_date_format'] = 'd.m.Y H:i:s';
  $handler->display->display_options['fields']['last_updated']['second_date_format'] = 'long';
  /* Feld: Inhalt: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Inhalt: Ordner (field_parent_folder) */
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['id'] = 'field_parent_folder_target_id';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['table'] = 'field_data_field_parent_folder';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['field'] = 'field_parent_folder_target_id';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_folder_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:node.members--1',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: parent_folder (field_parent_folder)',
    ),
  );

  /* Display: videos */
  $handler = $view->new_display('panel_pane', 'videos', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Videodateien';
  $handler->display->display_options['display_description'] = 'shows a list of the videos in this folder';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_video' => 'field_video',
    'body' => 'body',
    'last_updated' => 'last_updated',
    'field_available_in' => 'field_available_in',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_video';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_video' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_available_in' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Feld: Inhalt: Video */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = 'Dateiname';
  $handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'file_view_mode' => 'media_12',
  );
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Beschreibung';
  /* Feld: Inhalt: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Letzte Änderung';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'custom';
  $handler->display->display_options['fields']['last_updated']['custom_date_format'] = 'd.m.Y H:i:s';
  $handler->display->display_options['fields']['last_updated']['second_date_format'] = 'long';
  /* Feld: Inhalt: Verfügbar in */
  $handler->display->display_options['fields']['field_available_in']['id'] = 'field_available_in';
  $handler->display->display_options['fields']['field_available_in']['table'] = 'field_data_field_available_in';
  $handler->display->display_options['fields']['field_available_in']['field'] = 'field_available_in';
  $handler->display->display_options['fields']['field_available_in']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_available_in']['alter']['path'] = 'domain/text/[field_available_in-target_id]';
  $handler->display->display_options['fields']['field_available_in']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_available_in']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_available_in']['multi_type'] = 'ul';
  /* Feld: Inhalt: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Inhalt: Ordner (field_parent_folder) */
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['id'] = 'field_parent_folder_target_id';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['table'] = 'field_data_field_parent_folder';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['field'] = 'field_parent_folder_target_id';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_folder_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videosafe_video' => 'videosafe_video',
  );
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_folder_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:node.members--1',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: parent_folder (field_parent_folder)',
    ),
  );
  $translatables['videosafe_folderview'] = array(
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
    t('Alle'),
    t('parent folder'),
    t('show a link to the parent folder of the actual folder'),
    t('&nbsp;&gt;&nbsp;'),
    t('View panes'),
    t('subfolders'),
    t('Unterordner'),
    t('shows a list of the subfolders'),
    t('Titel'),
    t('Beschreibung'),
    t('Letzte Änderung'),
    t('videos'),
    t('Videodateien'),
    t('shows a list of the videos in this folder'),
    t('Dateiname'),
    t('Verfügbar in'),
  );
  $export['videosafe_folderview'] = $view;

  return $export;
}
