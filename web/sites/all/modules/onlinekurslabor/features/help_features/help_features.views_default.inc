<?php
/**
 * @file
 * help_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function help_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'book_button_navigation';
  $view->description = 'z.B. die Hilfe erhält eine Button-Navigation mithilfe von hochgeladenen Icons';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Book - Button-Navigation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['display_comment'] = '** oh mann.
es fehlt ein wrapper class=row und ohne rewrite nicht hinzukriege. kotz';
  $handler->display->display_options['css_class'] = 'lolalu';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-xs-6 col-sm-4 section-help-element';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Book: Top level book */
  $handler->display->display_options['relationships']['bid']['id'] = 'bid';
  $handler->display->display_options['relationships']['bid']['table'] = 'book';
  $handler->display->display_options['relationships']['bid']['field'] = 'bid';
  $handler->display->display_options['relationships']['bid']['label'] = 'Buch';
  $handler->display->display_options['relationships']['bid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Navigations-Icon */
  $handler->display->display_options['fields']['field_navigation_icon']['id'] = 'field_navigation_icon';
  $handler->display->display_options['fields']['field_navigation_icon']['table'] = 'field_data_field_navigation_icon';
  $handler->display->display_options['fields']['field_navigation_icon']['field'] = 'field_navigation_icon';
  $handler->display->display_options['fields']['field_navigation_icon']['label'] = '';
  $handler->display->display_options['fields']['field_navigation_icon']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_navigation_icon']['alter']['text'] = '[field_navigation_icon]
<br>
<span>[title]</span>';
  $handler->display->display_options['fields']['field_navigation_icon']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_navigation_icon']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_navigation_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_navigation_icon']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_navigation_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_navigation_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Book: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'book_menu_links';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
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
    'book' => 'book',
  );
  /* Filter criterion: Content: Navigations-Icon (field_navigation_icon:fid) */
  $handler->display->display_options['filters']['field_navigation_icon_fid']['id'] = 'field_navigation_icon_fid';
  $handler->display->display_options['filters']['field_navigation_icon_fid']['table'] = 'field_data_field_navigation_icon';
  $handler->display->display_options['filters']['field_navigation_icon_fid']['field'] = 'field_navigation_icon_fid';
  $handler->display->display_options['filters']['field_navigation_icon_fid']['operator'] = 'not empty';

  /* Display: In Help-Context */
  $handler = $view->new_display('panel_pane', 'In Help-Context', 'help_navigation');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: filtert auf bid = übergebener wert */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'bid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'filtert auf bid = übergebener wert';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_description'] = 'Beachte auch: section_help_views_post_render';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.book',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'filtert auf bid = übergebener wert',
    ),
  );
  $translatables['book_button_navigation'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Buch'),
    t('[field_navigation_icon]
<br>
<span>[title]</span>'),
    t('In Help-Context'),
    t('Alle'),
    t('Beachte auch: section_help_views_post_render'),
    t('View panes'),
  );
  $export['book_button_navigation'] = $view;

  return $export;
}
