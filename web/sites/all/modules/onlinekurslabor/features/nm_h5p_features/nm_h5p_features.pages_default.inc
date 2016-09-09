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
    'plugins' => array(
      0 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'view',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
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
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'content_domain' => 'content_domain',
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
  $display->layout = 'flexible:span3span8span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
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
    'title' => '',
    'body' => '<h2>Interaktives</h2>',
    'format' => 'filtered_html',
    'substitute' => 1,
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
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 1,
    'override_title_text' => 'H5P-Inhalte',
    'override_title_heading' => 'h3',
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
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 1,
    'override_title_text' => 'AnnVid-Player',
    'override_title_heading' => 'h3',
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
  $pane->pid = 'new-a1c743fc-3dd6-4e8d-8350-f02358f08561';
  $pane->panel = 'outline';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<?php 
echo section_content_text_outline();
?>',
    'format' => 'php_code',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a1c743fc-3dd6-4e8d-8350-f02358f08561';
  $display->content['new-a1c743fc-3dd6-4e8d-8350-f02358f08561'] = $pane;
  $display->panels['outline'][0] = 'new-a1c743fc-3dd6-4e8d-8350-f02358f08561';
  $pane = new stdClass();
  $pane->pid = 'new-c5a71284-2b49-4419-9a2b-bf7e750b8285';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_authors_tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
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
  $pane->uuid = 'c5a71284-2b49-4419-9a2b-bf7e750b8285';
  $display->content['new-c5a71284-2b49-4419-9a2b-bf7e750b8285'] = $pane;
  $display->panels['tools'][0] = 'new-c5a71284-2b49-4419-9a2b-bf7e750b8285';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_thema_h5p'] = $page;

  return $pages;

}
