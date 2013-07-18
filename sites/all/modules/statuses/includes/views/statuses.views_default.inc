<?php

/**
 * @file
 *   Provides default Views for the Statuses module.
 */

/**
 * Implementation of hook_views_default_views().
 */
function statuses_views_default_views() {
  /*
   * View 'statuses_all'
   */
  $view = new view;
  $view->name = 'statuses_all';
  $view->description = 'Displays all status updates.';
  $view->tag = 'Statuses';
  $view->view_php = '';
  $view->base_table = 'statuses';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'sid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'sid',
      'table' => 'statuses',
      'field' => 'sid',
      'relationship' => 'none',
    ),
    'classes' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'classes',
      'table' => 'statuses',
      'field' => 'classes',
      'relationship' => 'none',
    ),
    'sender_pic' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'sender_pic',
      'table' => 'statuses',
      'field' => 'sender_pic',
      'relationship' => 'none',
    ),
    'user_contextual' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'user_contextual',
      'table' => 'statuses',
      'field' => 'user_contextual',
      'relationship' => 'none',
    ),
    'message' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'message',
      'table' => 'statuses',
      'field' => 'message',
      'relationship' => 'none',
    ),
    'edit' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'edit',
      'table' => 'statuses',
      'field' => 'edit',
      'relationship' => 'none',
    ),
    'delete' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'delete',
      'table' => 'statuses',
      'field' => 'delete',
      'relationship' => 'none',
    ),
    'repost' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'repost_text' => 'Share',
      'exclude' => 1,
      'id' => 'repost',
      'table' => 'statuses',
      'field' => 'repost',
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'statuses/[sid]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'themed',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'created',
      'table' => 'statuses',
      'field' => 'created',
      'relationship' => 'none',
    ),
    'nothing' => array(
      'label' => '',
      'alter' => array(
        'text' => '<div id="statuses-item-[sid]" class="[classes]">
  [sender_pic]
  <div class="content">
    <div class="statuses-participants">[user_contextual]</div>
    [message]
    <div class="statuses-details">
      <div class="statuses-links">[edit] [delete] [repost]</div> [created]
    </div>
    <!-- meta -->
  </div>
</div>',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'sid' => array(
      'order' => 'DESC',
      'id' => 'sid',
      'table' => 'statuses',
      'field' => 'sid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'message' => array(
      'operator' => '!=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'message',
      'table' => 'statuses',
      'field' => 'message',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'view all statuses',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'statuses/all');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('block_description', 'Statuses: All Statuses');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->override_option('style_plugin', 'rss');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
  ));
  $handler->override_option('row_plugin', 'statuses_rss');
  $handler->override_option('path', 'statuses/all/feed');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array(
    'page_1' => 'page_1',
    'default' => 0,
    'block_1' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);
  $views[$view->name] = $view;

  /*
   * View 'statuses_conversation'
   */
  $view = new view;
  $view->name = 'statuses_conversation';
  $view->description = 'Displays the conversation in status messages between two users.';
  $view->tag = 'Statuses';
  $view->base_table = 'statuses';
  $view->human_name = 'Statuses Conversation';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Statuses Conversation';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all statuses';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Statuses: Status ID */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'statuses';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['label'] = '';
  $handler->display->display_options['fields']['sid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sid']['empty_zero'] = 0;
  /* Field: Statuses: HTML classes */
  $handler->display->display_options['fields']['classes']['id'] = 'classes';
  $handler->display->display_options['fields']['classes']['table'] = 'statuses';
  $handler->display->display_options['fields']['classes']['field'] = 'classes';
  $handler->display->display_options['fields']['classes']['label'] = '';
  $handler->display->display_options['fields']['classes']['exclude'] = TRUE;
  $handler->display->display_options['fields']['classes']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['classes']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['classes']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['classes']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['classes']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['classes']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['classes']['alter']['html'] = 0;
  $handler->display->display_options['fields']['classes']['hide_empty'] = 0;
  $handler->display->display_options['fields']['classes']['empty_zero'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<span class="statuses-sender">[name]</span>';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Statuses: Sender picture */
  $handler->display->display_options['fields']['sender_pic']['id'] = 'sender_pic';
  $handler->display->display_options['fields']['sender_pic']['table'] = 'statuses';
  $handler->display->display_options['fields']['sender_pic']['field'] = 'sender_pic';
  $handler->display->display_options['fields']['sender_pic']['label'] = '';
  $handler->display->display_options['fields']['sender_pic']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sender_pic']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sender_pic']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sender_pic']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sender_pic']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sender_pic']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sender_pic']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sender_pic']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sender_pic']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sender_pic']['empty_zero'] = 0;
  /* Field: Statuses: Status message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'statuses';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = '';
  $handler->display->display_options['fields']['message']['exclude'] = TRUE;
  $handler->display->display_options['fields']['message']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['message']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['message']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['message']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['message']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['message']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['message']['alter']['html'] = 0;
  $handler->display->display_options['fields']['message']['hide_empty'] = 0;
  $handler->display->display_options['fields']['message']['empty_zero'] = 0;
  /* Field: Statuses: Edit */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'statuses';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['label'] = '';
  $handler->display->display_options['fields']['edit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit']['empty_zero'] = 0;
  /* Field: Statuses: Delete */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'statuses';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = '';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete']['empty_zero'] = 0;
  /* Field: Statuses: Created time */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'statuses';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['created']['alter']['path'] = 'statuses/[sid]';
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div id="statuses-item-[sid]" class="[classes]">
    [sender_pic]
    <div class="content">
      <div class="statuses-participants">[name]</div>
      [message]
      <div class="statuses-details">
        <div class="statuses-links">[edit] [delete] [repost]</div> [created]
      </div>
      <!-- meta -->
    </div>
  </div>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  /* Sort criterion: Statuses: Status ID */
  $handler->display->display_options['sorts']['sid']['id'] = 'sid';
  $handler->display->display_options['sorts']['sid']['table'] = 'statuses';
  $handler->display->display_options['sorts']['sid']['field'] = 'sid';
  $handler->display->display_options['sorts']['sid']['order'] = 'DESC';
  /* Contextual filter: Statuses: User is sender or recipient */
  $handler->display->display_options['arguments']['participant']['id'] = 'participant';
  $handler->display->display_options['arguments']['participant']['table'] = 'statuses';
  $handler->display->display_options['arguments']['participant']['field'] = 'participant';
  $handler->display->display_options['arguments']['participant']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['participant']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['participant']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['participant']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['participant']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['participant']['validate']['type'] = 'user';
  /* Contextual filter: Statuses: User is sender or recipient */
  $handler->display->display_options['arguments']['participant_1']['id'] = 'participant_1';
  $handler->display->display_options['arguments']['participant_1']['table'] = 'statuses';
  $handler->display->display_options['arguments']['participant_1']['field'] = 'participant';
  $handler->display->display_options['arguments']['participant_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['participant_1']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['participant_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['participant_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['participant_1']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['participant_1']['validate']['type'] = 'user';
  /* Filter criterion: Statuses: Status message */
  $handler->display->display_options['filters']['message']['id'] = 'message';
  $handler->display->display_options['filters']['message']['table'] = 'statuses';
  $handler->display->display_options['filters']['message']['field'] = 'message';
  $handler->display->display_options['filters']['message']['operator'] = '!=';
  $handler->display->display_options['filters']['message']['group'] = '0';
  $handler->display->display_options['filters']['message']['expose']['operator'] = FALSE;
  /* Filter criterion: Statuses: Recipient type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'statuses';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'user' => 'user',
  );
  $views[$view->name] = $view;

  /*
   * View 'statuses_stream'
   */
  $view = new view;
  $view->name = 'statuses_stream';
  $view->description = 'Displays status updates that match the current recipient context.';
  $view->tag = 'Statuses';
  $view->view_php = '';
  $view->base_table = 'statuses';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'sid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'sid',
      'table' => 'statuses',
      'field' => 'sid',
      'relationship' => 'none',
    ),
    'classes' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'classes',
      'table' => 'statuses',
      'field' => 'classes',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 1,
        'text' => '<span class="statuses-sender">[name]</span>',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 1,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'sender_pic' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'sender_pic',
      'table' => 'statuses',
      'field' => 'sender_pic',
      'relationship' => 'none',
    ),
    'message' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'message',
      'table' => 'statuses',
      'field' => 'message',
      'relationship' => 'none',
    ),
    'edit' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'edit',
      'table' => 'statuses',
      'field' => 'edit',
      'relationship' => 'none',
    ),
    'delete' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'delete',
      'table' => 'statuses',
      'field' => 'delete',
      'relationship' => 'none',
    ),
    'repost' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'repost_text' => 'Share',
      'exclude' => 1,
      'id' => 'repost',
      'table' => 'statuses',
      'field' => 'repost',
      'relationship' => 'none',
    ),
    'created' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'statuses/[sid]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'themed',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'created',
      'table' => 'statuses',
      'field' => 'created',
      'relationship' => 'none',
    ),
    'nothing' => array(
      'label' => '',
      'alter' => array(
        'text' => '<div id="statuses-item-[sid]" class="[classes]">
  [sender_pic]
  <div class="content">
    <div class="statuses-participants">[name]</div>
    [message]
    <div class="statuses-details">
      <div class="statuses-links">[edit] [delete] [repost]</div> [created]
    </div>
    <!-- meta -->
  </div>
</div>',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'sid' => array(
      'order' => 'DESC',
      'id' => 'sid',
      'table' => 'statuses',
      'field' => 'sid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'message' => array(
      'operator' => '!=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'message',
      'table' => 'statuses',
      'field' => 'message',
      'relationship' => 'none',
    ),
    'auto-type' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'auto-type',
      'table' => 'statuses',
      'field' => 'auto-type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'view all statuses',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('block_description', 'Statuses: Context-sensitive stream');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

  if (module_exists('user_relationship_views')) {
    module_load_include('inc', 'statuses', 'includes/views/fbss_user_relationships.views_default');
    $ur_views = fbss_user_relationships_views_default_views();
    $views = array_merge($views, $ur_views);
  }

  return $views;
}
