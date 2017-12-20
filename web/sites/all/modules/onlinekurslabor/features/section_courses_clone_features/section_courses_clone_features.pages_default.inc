<?php
/**
 * @file
 * section_courses_clone_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function section_courses_clone_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'node_copy_something';
  $page->task = 'page';
  $page->admin_title = 'node-copy-something';
  $page->admin_description = 'this is a generalized page for copying nodes. 
Currently for courses only';
  $page->path = 'node/copy/%what';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 30037204,
            1 => 197637936,
            2 => 106505419,
            3 => 126456107,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'testest',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'what' => array(
      'id' => 1,
      'identifier' => ' form: node type',
      'name' => 'node_add',
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
  $handler->name = 'page_node_copy_something__panel';
  $handler->task = 'page';
  $handler->subtask = 'node_copy_something';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Courses - course',
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
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_node_add_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Courses - Kurs erstellen';
  $display->uuid = '6e1954ca-cfdc-4107-9050-f3533436a896';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_node_copy_something__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6be258df-1ec7-4dca-885d-ee71e4c740c5';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'nm_courses_clone-with_permission_check';
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
  $pane->uuid = '6be258df-1ec7-4dca-885d-ee71e4c740c5';
  $display->content['new-6be258df-1ec7-4dca-885d-ee71e4c740c5'] = $pane;
  $display->panels['middle'][0] = 'new-6be258df-1ec7-4dca-885d-ee71e4c740c5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6be258df-1ec7-4dca-885d-ee71e4c740c5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['node_copy_something'] = $page;

  return $pages;

}
