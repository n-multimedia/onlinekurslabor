<?php
/**
 * @file
 * videosafe_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function videosafe_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'videosafe';
  $page->task = 'page';
  $page->admin_title = 'videosafe';
  $page->admin_description = 'Video Safe';
  $page->path = 'videosafe/%node';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 30037204,
            1 => 197637936,
            2 => 16675960,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_videosafe__panel-videosafe-folder';
  $handler->task = 'page';
  $handler->subtask = 'videosafe';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Videosafe - Folder',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel-videosafe-folder',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'videosafe_folder' => 'videosafe_folder',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span6span6';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'news' => NULL,
      'tools' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd88f085d-a956-44a8-a6b5-bb0f2e073824';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9f2e7de4-6b17-4d21-b099-b23167c2edee';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'videosafe_folderview-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '0',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'arguments' => array(
        'field_parent_folder_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9f2e7de4-6b17-4d21-b099-b23167c2edee';
    $display->content['new-9f2e7de4-6b17-4d21-b099-b23167c2edee'] = $pane;
    $display->panels['center'][0] = 'new-9f2e7de4-6b17-4d21-b099-b23167c2edee';
    $pane = new stdClass();
    $pane->pid = 'new-98f219be-1347-4c7b-b525-98ee17afce86';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'videosafe_folderview-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '0',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'arguments' => array(
        'field_parent_folder_target_id' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '98f219be-1347-4c7b-b525-98ee17afce86';
    $display->content['new-98f219be-1347-4c7b-b525-98ee17afce86'] = $pane;
    $display->panels['center'][1] = 'new-98f219be-1347-4c7b-b525-98ee17afce86';
    $pane = new stdClass();
    $pane->pid = 'new-735300d5-d8fb-419d-9398-b02308008c59';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'videosafe_folderview-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'span12',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '735300d5-d8fb-419d-9398-b02308008c59';
    $display->content['new-735300d5-d8fb-419d-9398-b02308008c59'] = $pane;
    $display->panels['left'][0] = 'new-735300d5-d8fb-419d-9398-b02308008c59';
    $pane = new stdClass();
    $pane->pid = 'new-e687ecd6-4117-40bb-8f3a-c47c6ce6fc82';
    $pane->panel = 'left';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '@0',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => 'videosafedescription',
      'build_mode' => 'videosafe_description',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e687ecd6-4117-40bb-8f3a-c47c6ce6fc82';
    $display->content['new-e687ecd6-4117-40bb-8f3a-c47c6ce6fc82'] = $pane;
    $display->panels['left'][1] = 'new-e687ecd6-4117-40bb-8f3a-c47c6ce6fc82';
    $pane = new stdClass();
    $pane->pid = 'new-ae59bdad-52bb-4140-9019-6d2d41624b45';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'videosafe_folderview-panel_pane_5';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'node_is_videosafe_root',
            'php' => '$arg = array_values($contexts);
return $arg[0]->argument == _videosafe_get_root_directory()->nid;',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ae59bdad-52bb-4140-9019-6d2d41624b45';
    $display->content['new-ae59bdad-52bb-4140-9019-6d2d41624b45'] = $pane;
    $display->panels['left'][2] = 'new-ae59bdad-52bb-4140-9019-6d2d41624b45';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_videosafe__panel';
  $handler->task = 'page';
  $handler->subtask = 'videosafe';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Videosafe - Video',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'videosafe_video' => 'videosafe_video',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span6span6';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'news' => NULL,
      'tools' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd88f085d-a956-44a8-a6b5-bb0f2e073824';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9f2e7de4-6b17-4d21-b099-b23167c2edee';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'videosafe_folderview-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '0',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'arguments' => array(
        'field_parent_folder_target_id' => '%node:field-parent-folder:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9f2e7de4-6b17-4d21-b099-b23167c2edee';
    $display->content['new-9f2e7de4-6b17-4d21-b099-b23167c2edee'] = $pane;
    $display->panels['center'][0] = 'new-9f2e7de4-6b17-4d21-b099-b23167c2edee';
    $pane = new stdClass();
    $pane->pid = 'new-98f219be-1347-4c7b-b525-98ee17afce86';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'videosafe_folderview-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '0',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'arguments' => array(
        'field_parent_folder_target_id' => '%node:field-parent-folder:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '98f219be-1347-4c7b-b525-98ee17afce86';
    $display->content['new-98f219be-1347-4c7b-b525-98ee17afce86'] = $pane;
    $display->panels['center'][1] = 'new-98f219be-1347-4c7b-b525-98ee17afce86';
    $pane = new stdClass();
    $pane->pid = 'new-735300d5-d8fb-419d-9398-b02308008c59';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'videosafe_folderview-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '735300d5-d8fb-419d-9398-b02308008c59';
    $display->content['new-735300d5-d8fb-419d-9398-b02308008c59'] = $pane;
    $display->panels['left'][0] = 'new-735300d5-d8fb-419d-9398-b02308008c59';
    $pane = new stdClass();
    $pane->pid = 'new-e687ecd6-4117-40bb-8f3a-c47c6ce6fc82';
    $pane->panel = 'left';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '@0',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'videosafe_description',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e687ecd6-4117-40bb-8f3a-c47c6ce6fc82';
    $display->content['new-e687ecd6-4117-40bb-8f3a-c47c6ce6fc82'] = $pane;
    $display->panels['left'][1] = 'new-e687ecd6-4117-40bb-8f3a-c47c6ce6fc82';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['videosafe'] = $page;

  return $pages;

}
