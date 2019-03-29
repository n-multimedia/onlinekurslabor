<?php

/**
 * @file
 * annvid_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function annvid_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_annvid';
  $page->task = 'page';
  $page->admin_title = 'content-domain-annvid';
  $page->admin_description = '';
  $page->path = 'domain/annvid/%1';
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
      1 => array(
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
  $handler->name = 'page_content_domain_annvid__panel_context_2641b2c4-b76f-4678-a84e-9cac86b491e8';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_annvid';
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
              'annvid' => 'annvid',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'outline' => NULL,
      'tools' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '876d0461-4391-48e4-8124-1844f2f67393';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_annvid__panel_context_2641b2c4-b76f-4678-a84e-9cac86b491e8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_node_tabs';
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
  $pane->uuid = '7553bf90-888a-42b2-bb62-77e02186f4fb';
  $display->content['new-7553bf90-888a-42b2-bb62-77e02186f4fb'] = $pane;
  $display->panels['middle'][0] = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane = new stdClass();
  $pane->pid = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $display->content['new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b'] = $pane;
  $display->panels['middle'][1] = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane = new stdClass();
  $pane->pid = 'new-95b7d045-3914-40d0-bd3e-93b99fd176e9';
  $pane->panel = 'middle';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '95b7d045-3914-40d0-bd3e-93b99fd176e9';
  $display->content['new-95b7d045-3914-40d0-bd3e-93b99fd176e9'] = $pane;
  $display->panels['middle'][2] = 'new-95b7d045-3914-40d0-bd3e-93b99fd176e9';
  $pane = new stdClass();
  $pane->pid = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $pane->panel = 'middle';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $display->content['new-9631f371-ad25-408f-81bf-f6c21c2b28c0'] = $pane;
  $display->panels['middle'][3] = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $pane = new stdClass();
  $pane->pid = 'new-8efabd74-e6c1-4e33-9eb8-007e0608758d';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'nm_stream-nm_stream_form_add_edit';
  $pane->shown = FALSE;
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '8efabd74-e6c1-4e33-9eb8-007e0608758d';
  $display->content['new-8efabd74-e6c1-4e33-9eb8-007e0608758d'] = $pane;
  $display->panels['middle'][4] = 'new-8efabd74-e6c1-4e33-9eb8-007e0608758d';
  $pane = new stdClass();
  $pane->pid = 'new-6bf7a136-75aa-4ea6-86cc-8e1bb33cc0bc';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'nm_stream';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '6bf7a136-75aa-4ea6-86cc-8e1bb33cc0bc';
  $display->content['new-6bf7a136-75aa-4ea6-86cc-8e1bb33cc0bc'] = $pane;
  $display->panels['middle'][5] = 'new-6bf7a136-75aa-4ea6-86cc-8e1bb33cc0bc';
  $pane = new stdClass();
  $pane->pid = 'new-234711af-45e6-411c-bdf1-cd61b3835246';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Render Stream V2',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
$container = node_load(%1:nid);
return nm_stream_api_v2_render_stream($container );
?>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '234711af-45e6-411c-bdf1-cd61b3835246';
  $display->content['new-234711af-45e6-411c-bdf1-cd61b3835246'] = $pane;
  $display->panels['middle'][6] = 'new-234711af-45e6-411c-bdf1-cd61b3835246';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_annvid'] = $page;

  return $pages;

}
