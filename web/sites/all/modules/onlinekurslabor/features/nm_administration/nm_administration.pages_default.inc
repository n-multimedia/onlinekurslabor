<?php
/**
 * @file
 * nm_administration.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nm_administration_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'administration';
  $page->task = 'page';
  $page->admin_title = 'Administration';
  $page->admin_description = '';
  $page->path = 'administration/!section';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'section' => array(
      'id' => 1,
      'identifier' => 'Zeichenkette',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_administration__panel';
  $handler->task = 'page';
  $handler->subtask = 'administration';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Dashboard',
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
          'name' => 'string_length',
          'settings' => array(
            'operator' => '=',
            'length' => '0',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span6span3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '812cb22d-b415-448a-b0ba-d177e188680d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_administration__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-67b87b5f-b524-446c-a573-d3dd9a7cd6ec';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'administration_newest_content-pane_administration_newest_conent';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '67b87b5f-b524-446c-a573-d3dd9a7cd6ec';
  $display->content['new-67b87b5f-b524-446c-a573-d3dd9a7cd6ec'] = $pane;
  $display->panels['center'][0] = 'new-67b87b5f-b524-446c-a573-d3dd9a7cd6ec';
  $pane = new stdClass();
  $pane->pid = 'new-7b299223-2518-4223-bbba-4c287e11290d';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'administration_active_users-pane_administration_active_users';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7b299223-2518-4223-bbba-4c287e11290d';
  $display->content['new-7b299223-2518-4223-bbba-4c287e11290d'] = $pane;
  $display->panels['center'][1] = 'new-7b299223-2518-4223-bbba-4c287e11290d';
  $pane = new stdClass();
  $pane->pid = 'new-9a366edd-bb77-4ce9-a0b0-d1d823561bf3';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9a366edd-bb77-4ce9-a0b0-d1d823561bf3';
  $display->content['new-9a366edd-bb77-4ce9-a0b0-d1d823561bf3'] = $pane;
  $display->panels['left'][0] = 'new-9a366edd-bb77-4ce9-a0b0-d1d823561bf3';
  $pane = new stdClass();
  $pane->pid = 'new-52a30671-fdeb-45c2-a3c0-7c1b94c11cea';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'nm_activity_stream';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '15',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => 'Aktivität',
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
  $pane->uuid = '52a30671-fdeb-45c2-a3c0-7c1b94c11cea';
  $display->content['new-52a30671-fdeb-45c2-a3c0-7c1b94c11cea'] = $pane;
  $display->panels['right'][0] = 'new-52a30671-fdeb-45c2-a3c0-7c1b94c11cea';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-52a30671-fdeb-45c2-a3c0-7c1b94c11cea';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_administration__inhalt';
  $handler->task = 'page';
  $handler->subtask = 'administration';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Inhalt',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'inhalt',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'content',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'navigation' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '812cb22d-b415-448a-b0ba-d177e188680d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_administration__inhalt';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8d61a498-1efd-47c7-a6b1-48018039a31e';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'administration_content-panel_administration_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8d61a498-1efd-47c7-a6b1-48018039a31e';
  $display->content['new-8d61a498-1efd-47c7-a6b1-48018039a31e'] = $pane;
  $display->panels['center'][0] = 'new-8d61a498-1efd-47c7-a6b1-48018039a31e';
  $pane = new stdClass();
  $pane->pid = 'new-9a366edd-bb77-4ce9-a0b0-d1d823561bf3';
  $pane->panel = 'navigation';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9a366edd-bb77-4ce9-a0b0-d1d823561bf3';
  $display->content['new-9a366edd-bb77-4ce9-a0b0-d1d823561bf3'] = $pane;
  $display->panels['navigation'][0] = 'new-9a366edd-bb77-4ce9-a0b0-d1d823561bf3';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['administration'] = $page;

  return $pages;

}
