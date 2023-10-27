<?php

/**
 * @file
 * nm_h5p_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nm_h5p_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_thema_h5p';
  $page->task = 'page';
  $page->admin_title = 'Content - Thema - H5P';
  $page->admin_description = '';
  $page->path = 'domain/h5p/%1';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'name' => 'node_access',
        'not' => FALSE,
        'settings' => array(
          'type' => 'view',
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
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
  $handler->name = 'page_content_thema_h5p_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_thema_h5p';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_type',
          'not' => FALSE,
          'settings' => array(
            'type' => array(
              'content_domain' => 'content_domain',
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span4span8';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'navigation' => NULL,
      'outline' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = 'd4aabcd3-d5f6-46c6-865c-87d3d71d0f1d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_thema_h5p_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-69d90d4f-16d5-4369-900c-90aa3320037d';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2>Interaktives</h2>',
    'format' => 'filtered_html',
    'substitute' => 1,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '69d90d4f-16d5-4369-900c-90aa3320037d';
  $display->content['new-69d90d4f-16d5-4369-900c-90aa3320037d'] = $pane;
  $display->panels['center'][0] = 'new-69d90d4f-16d5-4369-900c-90aa3320037d';
  $pane = new stdClass();
  $pane->pid = 'new-ab840438-01bd-4ca9-84c5-813c59110e4a';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'content_h5p_overview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'default',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '25',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h3',
    'override_title_text' => 'H5P-Inhalte',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ab840438-01bd-4ca9-84c5-813c59110e4a';
  $display->content['new-ab840438-01bd-4ca9-84c5-813c59110e4a'] = $pane;
  $display->panels['center'][1] = 'new-ab840438-01bd-4ca9-84c5-813c59110e4a';
  $pane = new stdClass();
  $pane->pid = 'new-30d9dee4-6bfa-428e-ad1f-23e2f2812a28';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'content_annvid_overview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'default',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '25',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h3',
    'override_title_text' => 'AnnVid-Player',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '30d9dee4-6bfa-428e-ad1f-23e2f2812a28';
  $display->content['new-30d9dee4-6bfa-428e-ad1f-23e2f2812a28'] = $pane;
  $display->panels['center'][2] = 'new-30d9dee4-6bfa-428e-ad1f-23e2f2812a28';
  $pane = new stdClass();
  $pane->pid = 'new-4d72689a-5d05-4d7b-b094-d7e8c2cea1c5';
  $pane->panel = 'navigation';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_text_outline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4d72689a-5d05-4d7b-b094-d7e8c2cea1c5';
  $display->content['new-4d72689a-5d05-4d7b-b094-d7e8c2cea1c5'] = $pane;
  $display->panels['navigation'][0] = 'new-4d72689a-5d05-4d7b-b094-d7e8c2cea1c5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_thema_h5p'] = $page;

  return $pages;

}
