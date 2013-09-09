<?php
/**
 * @file
 * nm_statuses_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nm_statuses_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'onlinekurslabor_statuses_stream';
  $view->description = 'Displays status updates that match the current recipient context.';
  $view->tag = 'Statuses';
  $view->base_table = 'statuses';
  $view->human_name = 'onlinekurslabor_statuses_stream';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all statuses';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['total_pages'] = '0';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Benutzer: Profil */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'master' => 'master',
  );
  /* Feld: Statuses: Status ID */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'statuses';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  /* Feld: Statuses: HTML classes */
  $handler->display->display_options['fields']['classes']['id'] = 'classes';
  $handler->display->display_options['fields']['classes']['table'] = 'statuses';
  $handler->display->display_options['fields']['classes']['field'] = 'classes';
  $handler->display->display_options['fields']['classes']['label'] = '';
  $handler->display->display_options['fields']['classes']['exclude'] = TRUE;
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<span class="statuses-sender">[name]</span>';
  /* Feld: Profil: Foto */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => 'profile_mini_thumbnail',
    'image_link' => '',
  );
  /* Feld: Statuses: Sender picture */
  $handler->display->display_options['fields']['sender_pic']['id'] = 'sender_pic';
  $handler->display->display_options['fields']['sender_pic']['table'] = 'statuses';
  $handler->display->display_options['fields']['sender_pic']['field'] = 'sender_pic';
  $handler->display->display_options['fields']['sender_pic']['label'] = '';
  $handler->display->display_options['fields']['sender_pic']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sender_pic']['element_label_colon'] = FALSE;
  /* Feld: Statuses: Statusmeldung */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'statuses';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = '';
  $handler->display->display_options['fields']['message']['exclude'] = TRUE;
  /* Feld: Statuses: Bearbeiten */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'statuses';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['label'] = '';
  $handler->display->display_options['fields']['edit']['exclude'] = TRUE;
  /* Feld: Statuses: Löschen */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'statuses';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = '';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  /* Feld: Statuses: Re-post */
  $handler->display->display_options['fields']['repost']['id'] = 'repost';
  $handler->display->display_options['fields']['repost']['table'] = 'statuses';
  $handler->display->display_options['fields']['repost']['field'] = 'repost';
  $handler->display->display_options['fields']['repost']['label'] = '';
  $handler->display->display_options['fields']['repost']['exclude'] = TRUE;
  /* Feld: Statuses: Created time */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'statuses';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['path'] = 'statuses/[sid]';
  /* Feld: Statuses: Status comment box */
  $handler->display->display_options['fields']['comment-box']['id'] = 'comment-box';
  $handler->display->display_options['fields']['comment-box']['table'] = 'statuses';
  $handler->display->display_options['fields']['comment-box']['field'] = 'comment-box';
  $handler->display->display_options['fields']['comment-box']['exclude'] = TRUE;
  /* Feld: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div id="statuses-item-[sid]" class="[classes] row-fluid">
  <div class="status_author span1">
  [field_photo]
  </div>
  <div class="content span11">
    <div class="statuses-participants">[name]</div>
    [message]
    <div class="statuses-details">
      <div class="statuses-links">[edit] [delete] [repost]</div> [created]
    </div>
    <!-- meta -->
   [comment-box]
  </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Statuses: Status ID */
  $handler->display->display_options['sorts']['sid']['id'] = 'sid';
  $handler->display->display_options['sorts']['sid']['table'] = 'statuses';
  $handler->display->display_options['sorts']['sid']['field'] = 'sid';
  $handler->display->display_options['sorts']['sid']['order'] = 'DESC';
  /* Filter criterion: Statuses: Statusmeldung */
  $handler->display->display_options['filters']['message']['id'] = 'message';
  $handler->display->display_options['filters']['message']['table'] = 'statuses';
  $handler->display->display_options['filters']['message']['field'] = 'message';
  $handler->display->display_options['filters']['message']['operator'] = '!=';
  $handler->display->display_options['filters']['message']['group'] = '0';
  $handler->display->display_options['filters']['message']['expose']['operator'] = FALSE;
  /* Filter criterion: Statuses: Use current context */
  $handler->display->display_options['filters']['auto-type']['id'] = 'auto-type';
  $handler->display->display_options['filters']['auto-type']['table'] = 'statuses';
  $handler->display->display_options['filters']['auto-type']['field'] = 'auto-type';
  $handler->display->display_options['filters']['auto-type']['group'] = '0';
  $handler->display->display_options['filters']['auto-type']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['block_description'] = 'Statuses: Context-sensitive stream';
  $translatables['onlinekurslabor_statuses_stream'] = array(
    t('Defaults'),
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
    t('Profil'),
    t('<span class="statuses-sender">[name]</span>'),
    t('Share'),
    t('Status comment box'),
    t('<div id="statuses-item-[sid]" class="[classes] row-fluid">
  <div class="status_author span1">
  [field_photo]
  </div>
  <div class="content span11">
    <div class="statuses-participants">[name]</div>
    [message]
    <div class="statuses-details">
      <div class="statuses-links">[edit] [delete] [repost]</div> [created]
    </div>
    <!-- meta -->
   [comment-box]
  </div>
</div>'),
    t('Block'),
    t('Statuses: Context-sensitive stream'),
  );
  $export['onlinekurslabor_statuses_stream'] = $view;

  return $export;
}
