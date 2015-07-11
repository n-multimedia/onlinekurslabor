<?php
/**
 * @file
 * nm_login_vhb_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nm_login_vhb_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nm_login_vhb';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'nm_login_vhb';
  $view->human_name = 'NM_Login_VHB';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'matrikelnummer' => 'matrikelnummer',
    'created' => 'created',
    'archivated' => 'archivated',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'matrikelnummer' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'archivated' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: NM Login VHB: user relationship */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'nm_login_vhb';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Feld: Bulk operations: NM Login VHB */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::nm_login_vhb_archivate_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
  );
  /* Feld: NM Login VHB: uid field */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['separator'] = '';
  /* Feld: NM Login VHB: archivated */
  $handler->display->display_options['fields']['archivated']['id'] = 'archivated';
  $handler->display->display_options['fields']['archivated']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['archivated']['field'] = 'archivated';
  $handler->display->display_options['fields']['archivated']['exclude'] = TRUE;
  $handler->display->display_options['fields']['archivated']['separator'] = '';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: NM Login VHB: Matrikelnummer field */
  $handler->display->display_options['fields']['matrikelnummer']['id'] = 'matrikelnummer';
  $handler->display->display_options['fields']['matrikelnummer']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['matrikelnummer']['field'] = 'matrikelnummer';
  $handler->display->display_options['fields']['matrikelnummer']['label'] = 'Matrikelnummer';
  /* Feld: NM Login VHB: Timestamp field */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created on';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Contextual filter: NM Login VHB: archivated */
  $handler->display->display_options['arguments']['archivated']['id'] = 'archivated';
  $handler->display->display_options['arguments']['archivated']['table'] = 'nm_login_vhb';
  $handler->display->display_options['arguments']['archivated']['field'] = 'archivated';
  $handler->display->display_options['arguments']['archivated']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['archivated']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['archivated']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['archivated']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['archivated']['summary_options']['items_per_page'] = '25';
  $translatables['nm_login_vhb'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
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
    t('Benutzer'),
    t('NM Login VHB'),
    t('- Choose an operation -'),
    t('uid field'),
    t('.'),
    t('archivated'),
    t('Name'),
    t('Matrikelnummer'),
    t('Created on'),
    t('Alle'),
  );
  $export['nm_login_vhb'] = $view;

  return $export;
}
