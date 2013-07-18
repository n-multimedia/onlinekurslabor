<?php

/**
 * @file
 *  Canned, ready-to-customise workflow-related views:
 *  1) Workflow Dashboard: a state transition form for each node that is subject
 *     to workflow
 *  2) Workflow History: a customisable view version of the Workflow module's
 *     built-in workflow history, node/%/workflow, with extra options such as
 *     "edit comment" links.
 */

/**
 * Implements hook_views_default_views().
 */
function workflow_extensions_views_default_views() {

  $view = new view();
  $view->name = 'workflow_dashboard';
  $view->description = 'All content with workflow state transition buttons where applicable.';
  $view->tag = 'workflow extensions';
  $view->base_table = 'node';
  $view->human_name = 'Workflow dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access workflow summary views';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 20;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Workflow: Current state */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'workflow_node';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  /* Field: Workflow: State transition form */
  $handler->display->display_options['fields']['state_change_form']['id'] = 'state_change_form';
  $handler->display->display_options['fields']['state_change_form']['table'] = 'workflow_node';
  $handler->display->display_options['fields']['state_change_form']['field'] = 'state_change_form';
  $handler->display->display_options['fields']['state_change_form']['alter']['text'] = 'Here you go: [state_change_form]';
  $handler->display->display_options['fields']['state_change_form']['alter']['path'] = 'node';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'workflow-dashboard';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Workflow dashboard';
  $handler->display->display_options['menu']['description'] = 'Workflow dashboard';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['workflow_dashboard'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('Current state'),
    t('State transition form'),
    t('Here you go: [state_change_form]'),
    t('Page'),
  );
  $views[$view->name] = $view;


  // Workflow history with editable state transition comments
  $view = new view();
  $view->name = 'workflow_history';
  $view->description = 'Workflow state transition history across all nodes or a single node.';
  $view->tag = 'workflow extensions';
  $view->base_table = 'node';
  $view->human_name = 'Workflow history';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Workflow history';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access workflow summary views';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 100;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Workflow: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'workflow_node_history';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'State transitioner';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Workflow: Hid */
  $handler->display->display_options['fields']['hid']['id'] = 'hid';
  $handler->display->display_options['fields']['hid']['table'] = 'workflow_node_history';
  $handler->display->display_options['fields']['hid']['field'] = 'hid';
  $handler->display->display_options['fields']['hid']['exclude'] = TRUE;
  /* Field: Workflow: Previous time */
  $handler->display->display_options['fields']['stamp']['id'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['table'] = 'workflow_node_history';
  $handler->display->display_options['fields']['stamp']['field'] = 'stamp';
  $handler->display->display_options['fields']['stamp']['label'] = 'Date & time';
  $handler->display->display_options['fields']['stamp']['date_format'] = 'medium';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Workflow: Previous state */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'workflow_node_history';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = 'Transitioned to';
  $handler->display->display_options['fields']['sid']['hide_empty'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'By';
  /* Field: Workflow: Previous comment */
  $handler->display->display_options['fields']['comment']['id'] = 'comment';
  $handler->display->display_options['fields']['comment']['table'] = 'workflow_node_history';
  $handler->display->display_options['fields']['comment']['field'] = 'comment';
  $handler->display->display_options['fields']['comment']['label'] = 'Transition comment';
  $handler->display->display_options['fields']['comment']['alter']['path'] = 'workflow-log/[hid]?destination=workflow-history/[nid]';
  $handler->display->display_options['fields']['comment']['alter']['alt'] = 'Edit this comment';
  $handler->display->display_options['fields']['comment']['hide_empty'] = TRUE;
  /* Field: Workflow: Edit comment */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'workflow_node_history';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['hide_empty'] = TRUE;
  /* Sort criterion: Workflow: Hid */
  $handler->display->display_options['sorts']['hid']['id'] = 'hid';
  $handler->display->display_options['sorts']['hid']['table'] = 'workflow_node_history';
  $handler->display->display_options['sorts']['hid']['field'] = 'hid';
  $handler->display->display_options['sorts']['hid']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Workflow history for "%1"';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = '  return arg(1);';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Filter criterion: Workflow: Hid */
  $handler->display->display_options['filters']['hid']['id'] = 'hid';
  $handler->display->display_options['filters']['hid']['table'] = 'workflow_node_history';
  $handler->display->display_options['filters']['hid']['field'] = 'hid';
  $handler->display->display_options['filters']['hid']['operator'] = '>';
  $handler->display->display_options['filters']['hid']['value']['value'] = '0';
  $handler->display->display_options['filters']['hid']['group'] = '0';
  $handler->display->display_options['filters']['hid']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'workflow-history';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Workflow history';
  $handler->display->display_options['menu']['description'] = 'Workflow history';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Workflow history across all nodes or just the currently viewed node';
  $translatables['workflow_history'] = array(
    t('Defaults'),
    t('Workflow history'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('State transitioner'),
    t('Nid'),
    t('Hid'),
    t('.'),
    t(','),
    t('Date & time'),
    t('Title'),
    t('Transitioned to'),
    t('By'),
    t('Transition comment'),
    t('Edit this comment'),
    t('Edit comment'),
    t('All'),
    t('Workflow history for "%1"'),
    t('Page'),
    t('Block'),
    t('Workflow history across all nodes or just the currently viewed node'),
  );
  $views[$view->name] = $view;

  return $views;
}
