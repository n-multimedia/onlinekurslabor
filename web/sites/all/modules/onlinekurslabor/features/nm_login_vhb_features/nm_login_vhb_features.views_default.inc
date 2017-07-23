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
  $handler->display->display_options['title'] = 'Große Liste.';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'uid_2' => 'uid_2',
    'archivated_1' => 'archivated_1',
    'name' => 'name',
    'mail' => 'mail',
    'matrikelnummer_1' => 'matrikelnummer_1',
    'created' => 'created',
    'access' => 'access',
    'status' => 'status',
    'edit_node' => 'edit_node',
    'login' => 'login',
    'archivated' => 'archivated',
    'matrikelnummer' => 'matrikelnummer',
    'uid_1' => 'uid_1',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'archivated_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'matrikelnummer_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'archivated' => array(
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
    'uid_1' => array(
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
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'student' => 'student',
  );
  /* Field: Bulk operations: NM Login VHB */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_nm_login_vhb_entry';
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
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: NM Login VHB: uid field */
  $handler->display->display_options['fields']['uid_2']['id'] = 'uid_2';
  $handler->display->display_options['fields']['uid_2']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['uid_2']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_2']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Profile: Matrikelnummer */
  $handler->display->display_options['fields']['field_matrikelnummer_varchar']['id'] = 'field_matrikelnummer_varchar';
  $handler->display->display_options['fields']['field_matrikelnummer_varchar']['table'] = 'field_data_field_matrikelnummer_varchar';
  $handler->display->display_options['fields']['field_matrikelnummer_varchar']['field'] = 'field_matrikelnummer_varchar';
  $handler->display->display_options['fields']['field_matrikelnummer_varchar']['relationship'] = 'profile';
  /* Field: NM Login VHB: Timestamp field */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created on';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['relationship'] = 'uid';
  $handler->display->display_options['fields']['access']['label'] = 'Letzter Zugriff';
  $handler->display->display_options['fields']['access']['date_format'] = 'long';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'long';
  /* Field: NM Login VHB: VHB LOGIN field */
  $handler->display->display_options['fields']['login_uid']['id'] = 'login_uid';
  $handler->display->display_options['fields']['login_uid']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['login_uid']['field'] = 'login_uid';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['relationship'] = 'uid';
  $handler->display->display_options['fields']['login']['label'] = 'Letzte Anmeldung';
  $handler->display->display_options['fields']['login']['date_format'] = 'medium';
  $handler->display->display_options['fields']['login']['second_date_format'] = 'long';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'uid';
  /* Field: NM Login VHB: archivated */
  $handler->display->display_options['fields']['archivated']['id'] = 'archivated';
  $handler->display->display_options['fields']['archivated']['table'] = 'nm_login_vhb';
  $handler->display->display_options['fields']['archivated']['field'] = 'archivated';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'uid';
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
    t('Große Liste.'),
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
    t('user'),
    t('Profile'),
    t('NM Login VHB'),
    t('- Choose an operation -'),
    t('uid field'),
    t('.'),
    t('Name'),
    t('E-mail'),
    t('Matrikelnummer'),
    t('Created on'),
    t('Letzter Zugriff'),
    t('VHB LOGIN field'),
    t('Letzte Anmeldung'),
    t('Active'),
    t('archivated'),
    t(','),
    t('Edit link'),
    t('Alle'),
  );
  $export['nm_login_vhb'] = $view;

  return $export;
}
