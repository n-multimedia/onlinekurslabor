<?php

/**
 * @file
 * nm_general_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nm_general_features_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_8cc74b1f-7b01-4772-9ae8-0a1dccc2e52a';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Forum',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
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
  $display->layout = 'flexible:span12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '368af4f3-b256-4f2c-b63d-6cbc234786ac';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_8cc74b1f-7b01-4772-9ae8-0a1dccc2e52a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-152e0c58-9d31-485d-ae6c-8032d339008c';
  $pane->panel = 'center';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
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
  $pane->uuid = '152e0c58-9d31-485d-ae6c-8032d339008c';
  $display->content['new-152e0c58-9d31-485d-ae6c-8032d339008c'] = $pane;
  $display->panels['center'][0] = 'new-152e0c58-9d31-485d-ae6c-8032d339008c';
  $pane = new stdClass();
  $pane->pid = 'new-76ed2890-74af-4af6-b12a-cc873e6bd41b';
  $pane->panel = 'center';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '76ed2890-74af-4af6-b12a-cc873e6bd41b';
  $display->content['new-76ed2890-74af-4af6-b12a-cc873e6bd41b'] = $pane;
  $display->panels['center'][1] = 'new-76ed2890-74af-4af6-b12a-cc873e6bd41b';
  $pane = new stdClass();
  $pane->pid = 'new-f88a6e16-f2cb-4d43-92f8-c8ded355539d';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Set Breadcrumb (Important: Position After Node View!)',
    'title' => '',
    'body' => '<?php
custom_general_forum_set_breadcrumb();
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f88a6e16-f2cb-4d43-92f8-c8ded355539d';
  $display->content['new-f88a6e16-f2cb-4d43-92f8-c8ded355539d'] = $pane;
  $display->panels['center'][2] = 'new-f88a6e16-f2cb-4d43-92f8-c8ded355539d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-152e0c58-9d31-485d-ae6c-8032d339008c';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_8cc74b1f-7b01-4772-9ae8-0a1dccc2e52a'] = $handler;

  return $export;
}
