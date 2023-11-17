<?php

/**
 * @file
 * section_projects_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function section_projects_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'partners_partner_projektvorschlag';
  $page->task = 'page';
  $page->admin_title = 'Partners - Partner - Projektvorschlag';
  $page->admin_description = '';
  $page->path = 'projects/partners/%1/%2';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 3,
      'identifier' => 'Beitrag: ID 3',
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
  $handler->name = 'page_partners_partner_projektvorschlag_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'partners_partner_projektvorschlag';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
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
  $display->layout = 'flexible:col_md_8col_md_3col_md_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'col_md_1' => NULL,
      'default' => NULL,
      'left' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '27782dc8-0dbd-490f-85ce-b640a29991f7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_partners_partner_projektvorschlag_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9c33d91c-9df5-4006-bf02-e7187bcb5026';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_proposal_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_3',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Kontakt',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9c33d91c-9df5-4006-bf02-e7187bcb5026';
  $display->content['new-9c33d91c-9df5-4006-bf02-e7187bcb5026'] = $pane;
  $display->panels['center'][0] = 'new-9c33d91c-9df5-4006-bf02-e7187bcb5026';
  $pane = new stdClass();
  $pane->pid = 'new-2da4c5d1-d487-40b4-81f3-8552a8b3baa4';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_proposal_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_3',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'list_default',
    'formatter_settings' => array(),
    'label' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Mitarbeit',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2da4c5d1-d487-40b4-81f3-8552a8b3baa4';
  $display->content['new-2da4c5d1-d487-40b4-81f3-8552a8b3baa4'] = $pane;
  $display->panels['center'][1] = 'new-2da4c5d1-d487-40b4-81f3-8552a8b3baa4';
  $pane = new stdClass();
  $pane->pid = 'new-c042c272-103d-45e7-837e-f59af6407354';
  $pane->panel = 'col_md_1';
  $pane->type = 'block';
  $pane->subtype = 'section_projects-projects_po_tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'c042c272-103d-45e7-837e-f59af6407354';
  $display->content['new-c042c272-103d-45e7-837e-f59af6407354'] = $pane;
  $display->panels['col_md_1'][0] = 'new-c042c272-103d-45e7-837e-f59af6407354';
  $pane = new stdClass();
  $pane->pid = 'new-ccbe9fc6-19fb-4bbb-a66a-e50e50445c50';
  $pane->panel = 'left';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'build_mode' => 'full',
    'identifier' => '',
    'leave_node_title' => 0,
    'link_node_title' => 0,
    'links' => 0,
    'nid' => '%3',
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
  $pane->uuid = 'ccbe9fc6-19fb-4bbb-a66a-e50e50445c50';
  $display->content['new-ccbe9fc6-19fb-4bbb-a66a-e50e50445c50'] = $pane;
  $display->panels['left'][0] = 'new-ccbe9fc6-19fb-4bbb-a66a-e50e50445c50';
  $pane = new stdClass();
  $pane->pid = 'new-485db5de-e1f7-4966-aa98-5573472036c0';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_3',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'title',
    'override_title' => 1,
    'override_title_text' => 'Beschreibung',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '485db5de-e1f7-4966-aa98-5573472036c0';
  $display->content['new-485db5de-e1f7-4966-aa98-5573472036c0'] = $pane;
  $display->panels['left'][1] = 'new-485db5de-e1f7-4966-aa98-5573472036c0';
  $pane = new stdClass();
  $pane->pid = 'new-572042dc-fbff-4d42-9fbc-1fb76d2c9681';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'projects_cooperation_agreements-pane_cooperation_agreements';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_ca_proposal_ref_target_id' => '%2:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '572042dc-fbff-4d42-9fbc-1fb76d2c9681';
  $display->content['new-572042dc-fbff-4d42-9fbc-1fb76d2c9681'] = $pane;
  $display->panels['left'][2] = 'new-572042dc-fbff-4d42-9fbc-1fb76d2c9681';
  $pane = new stdClass();
  $pane->pid = 'new-5f4057bb-31f2-4d68-adc3-c5be42a2dbe2';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'projects_cp_proposals_overview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_2.nid',
    ),
    'display' => 'default',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_text' => 'Weitere Projektvorschläge',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '5f4057bb-31f2-4d68-adc3-c5be42a2dbe2';
  $display->content['new-5f4057bb-31f2-4d68-adc3-c5be42a2dbe2'] = $pane;
  $display->panels['left'][3] = 'new-5f4057bb-31f2-4d68-adc3-c5be42a2dbe2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['partners_partner_projektvorschlag'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'partners_partner_projektvorschlag_cockpit';
  $page->task = 'page';
  $page->admin_title = 'Partners - Partner - Projektvorschlag - Cockpit';
  $page->admin_description = '';
  $page->path = 'projects/partners/%1/%2/cockpit/%3';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_4',
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
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 3,
      'identifier' => 'Beitrag: ID 3',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    3 => array(
      'id' => 4,
      'identifier' => 'Beitrag: ID 4',
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
  $handler->name = 'page_partners_partner_projektvorschlag_cockpit_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'partners_partner_projektvorschlag_cockpit';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
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
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '27782dc8-0dbd-490f-85ce-b640a29991f7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_partners_partner_projektvorschlag_cockpit_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e1849d41-b2d5-422f-bee5-b628ef15a3c4';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'section_projects-project_cockpit_main';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'pane-nm-stream',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e1849d41-b2d5-422f-bee5-b628ef15a3c4';
  $display->content['new-e1849d41-b2d5-422f-bee5-b628ef15a3c4'] = $pane;
  $display->panels['news'][0] = 'new-e1849d41-b2d5-422f-bee5-b628ef15a3c4';
  $pane = new stdClass();
  $pane->pid = 'new-c042c272-103d-45e7-837e-f59af6407354';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_projects-projects_po_tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'c042c272-103d-45e7-837e-f59af6407354';
  $display->content['new-c042c272-103d-45e7-837e-f59af6407354'] = $pane;
  $display->panels['tools'][0] = 'new-c042c272-103d-45e7-837e-f59af6407354';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['partners_partner_projektvorschlag_cockpit'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects_admin_add_node';
  $page->task = 'page';
  $page->admin_title = 'Projects Admin Add Node';
  $page->admin_description = '';
  $page->path = 'projects/admin/add/%1';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'not' => FALSE,
        'settings' => array(
          'description' => 'Node access',
          'php' => 'global $user;
$account = clone $user;
$tmp_node = (object)array(\'nid\' =>0, \'type\'=>arg(3));
//dpm(node_access(\'create\', $tmp_node));
//dpm(og_node_access( $tmp_node, \'create\', $account ) );
//return og_node_access( $tmp_node, \'create\', $account ) == NODE_ACCESS_ALLOW ?  TRUE : FALSE ;
return node_access(\'create\', $tmp_node);',
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
      'identifier' => 'Node add form: node type',
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
  $handler->name = 'page_projects_admin_add_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'projects_admin_add_node';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(),
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
  $display->layout = 'flexible:span11span1_adminonly';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'contains' => 'column',
        'parent' => NULL,
        'type' => 'row',
      ),
      'center' => array(
        'parent' => 'main-row',
        'title' => 'Zentriert',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 'main-row',
        ),
        'class' => 'col-md-11',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '67.94595703225146',
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'center',
        ),
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'tools' => array(
        'class' => '',
        'parent' => '2',
        'title' => 'Tools',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-1',
        'parent' => 'canvas',
        'type' => 'column',
        'width' => '32.05404296774855',
        'width_type' => '%',
      ),
      2 => array(
        'children' => array(
          0 => 'tools',
        ),
        'class' => '',
        'contains' => 'region',
        'parent' => '1',
        'type' => 'row',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1fa1cee7-8d7b-4ffc-8271-eee9ed5ab49e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_projects_admin_add_node_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-94323719-a6fe-4925-b209-42f5273131a0';
  $pane->panel = 'center';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_add_1',
    'override_title' => 1,
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
  $pane->uuid = '94323719-a6fe-4925-b209-42f5273131a0';
  $display->content['new-94323719-a6fe-4925-b209-42f5273131a0'] = $pane;
  $display->panels['center'][0] = 'new-94323719-a6fe-4925-b209-42f5273131a0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-94323719-a6fe-4925-b209-42f5273131a0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects_admin_add_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects_admin_edit_node';
  $page->task = 'page';
  $page->admin_title = 'Projects Admin Edit Node';
  $page->admin_description = '';
  $page->path = 'projects/admin/%1/edit';
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
          'type' => 'update',
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
  $handler->name = 'page_projects_admin_edit_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'projects_admin_edit_node';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
        'identifier' => 'Node edit form from node',
        'keyword' => 'node_form',
        'name' => 'node_edit_form_from_node',
      ),
    ),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fb5218c5-156b-405d-acdd-6843b4bc6d53';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_projects_admin_edit_node_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-242346f3-a705-4dd7-aded-c13a2f90fb36';
  $pane->panel = 'news';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Node Tabs',
    'body' => '<?php
$node = node_load(arg(2));
echo _section_projects_render_node_tabs($node);
?>',
    'format' => 'php_code',
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
  $pane->uuid = '242346f3-a705-4dd7-aded-c13a2f90fb36';
  $display->content['new-242346f3-a705-4dd7-aded-c13a2f90fb36'] = $pane;
  $display->panels['news'][0] = 'new-242346f3-a705-4dd7-aded-c13a2f90fb36';
  $pane = new stdClass();
  $pane->pid = 'new-0cd7c74f-294f-410e-81b3-761bdcb1416a';
  $pane->panel = 'news';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
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
  $pane->uuid = '0cd7c74f-294f-410e-81b3-761bdcb1416a';
  $display->content['new-0cd7c74f-294f-410e-81b3-761bdcb1416a'] = $pane;
  $display->panels['news'][1] = 'new-0cd7c74f-294f-410e-81b3-761bdcb1416a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0cd7c74f-294f-410e-81b3-761bdcb1416a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects_admin_edit_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects_partners';
  $page->task = 'page';
  $page->admin_title = 'Projects- Partners';
  $page->admin_description = '';
  $page->path = 'projects/partners';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects_partners_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'projects_partners';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
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
  $display->layout = 'flexible:span12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Partnerorganisationen';
  $display->uuid = '2eb99b41-7005-45d0-b6c6-0e08b7fcc1eb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_projects_partners_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ed9ad104-2fc6-44b9-8338-b21a61db20d1';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Create Partnerorganisation Button',
    'body' => '<?php
if(user_access(\'create projects_organization content\'))
echo \'<p><a class="btn btn-default" href="/node/add/projects-organization">Neue Partnerorganisation anlegen</a></p>\';

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
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
  $pane->uuid = 'ed9ad104-2fc6-44b9-8338-b21a61db20d1';
  $display->content['new-ed9ad104-2fc6-44b9-8338-b21a61db20d1'] = $pane;
  $display->panels['center'][0] = 'new-ed9ad104-2fc6-44b9-8338-b21a61db20d1';
  $pane = new stdClass();
  $pane->pid = 'new-63afec16-590e-4eba-8b93-136849b63f1d';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'projects_po_overview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'default',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '15',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->uuid = '63afec16-590e-4eba-8b93-136849b63f1d';
  $display->content['new-63afec16-590e-4eba-8b93-136849b63f1d'] = $pane;
  $display->panels['center'][1] = 'new-63afec16-590e-4eba-8b93-136849b63f1d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-63afec16-590e-4eba-8b93-136849b63f1d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects_partners'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects_partners_partner';
  $page->task = 'page';
  $page->admin_title = 'Projects - Partners - Partner';
  $page->admin_description = '';
  $page->path = 'projects/partners/%node';
  $page->access = array(
    'settings' => NULL,
    'type' => 'none',
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
  $handler->name = 'page_projects_partners_partner_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'projects_partners_partner';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
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
  $display->layout = 'flexible:col_md_8col_md_3col_md_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'col_md_1' => NULL,
      'default' => NULL,
      'left' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '27782dc8-0dbd-490f-85ce-b640a29991f7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_projects_partners_partner_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fc656e11-48ff-48b1-bca3-6f6514d3b84e';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_po_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'text_default',
    'formatter_settings' => array(),
    'label' => 'title',
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
  $pane->uuid = 'fc656e11-48ff-48b1-bca3-6f6514d3b84e';
  $display->content['new-fc656e11-48ff-48b1-bca3-6f6514d3b84e'] = $pane;
  $display->panels['center'][0] = 'new-fc656e11-48ff-48b1-bca3-6f6514d3b84e';
  $pane = new stdClass();
  $pane->pid = 'new-cbff1145-c9b3-4e09-b4a5-9a52ae4962fc';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_field_po_contact_person';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter' => 'og_list_default',
    'formatter_settings' => array(
      'links' => 1,
      'view_mode' => 'default',
    ),
    'label' => 'title',
    'override_title' => 1,
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
  $pane->uuid = 'cbff1145-c9b3-4e09-b4a5-9a52ae4962fc';
  $display->content['new-cbff1145-c9b3-4e09-b4a5-9a52ae4962fc'] = $pane;
  $display->panels['center'][1] = 'new-cbff1145-c9b3-4e09-b4a5-9a52ae4962fc';
  $pane = new stdClass();
  $pane->pid = 'new-c042c272-103d-45e7-837e-f59af6407354';
  $pane->panel = 'col_md_1';
  $pane->type = 'block';
  $pane->subtype = 'section_projects-projects_po_tools';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'c042c272-103d-45e7-837e-f59af6407354';
  $display->content['new-c042c272-103d-45e7-837e-f59af6407354'] = $pane;
  $display->panels['col_md_1'][0] = 'new-c042c272-103d-45e7-837e-f59af6407354';
  $pane = new stdClass();
  $pane->pid = 'new-d53c2ce6-e222-46b5-827f-10af1ab6b711';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_operational_area';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter' => 'ds_taxonomy_separator',
    'formatter_settings' => array(),
    'label' => 'title',
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
  $pane->uuid = 'd53c2ce6-e222-46b5-827f-10af1ab6b711';
  $display->content['new-d53c2ce6-e222-46b5-827f-10af1ab6b711'] = $pane;
  $display->panels['left'][0] = 'new-d53c2ce6-e222-46b5-827f-10af1ab6b711';
  $pane = new stdClass();
  $pane->pid = 'new-274648dc-8585-41cf-856b-bb28cf5f0056';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_task_area';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter' => 'ds_taxonomy_separator',
    'formatter_settings' => array(),
    'label' => 'title',
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
  $pane->uuid = '274648dc-8585-41cf-856b-bb28cf5f0056';
  $display->content['new-274648dc-8585-41cf-856b-bb28cf5f0056'] = $pane;
  $display->panels['left'][1] = 'new-274648dc-8585-41cf-856b-bb28cf5f0056';
  $pane = new stdClass();
  $pane->pid = 'new-069cf23b-7bf1-41c0-8a31-717dac0aa9e7';
  $pane->panel = 'left';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '069cf23b-7bf1-41c0-8a31-717dac0aa9e7';
  $display->content['new-069cf23b-7bf1-41c0-8a31-717dac0aa9e7'] = $pane;
  $display->panels['left'][2] = 'new-069cf23b-7bf1-41c0-8a31-717dac0aa9e7';
  $pane = new stdClass();
  $pane->pid = 'new-5f4057bb-31f2-4d68-adc3-c5be42a2dbe2';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'projects_cp_proposals_overview';
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
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_text' => 'Projektvorschläge',
    'pager_id' => '0',
    'panel_args' => 0,
    'url' => '',
    'use_pager' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '5f4057bb-31f2-4d68-adc3-c5be42a2dbe2';
  $display->content['new-5f4057bb-31f2-4d68-adc3-c5be42a2dbe2'] = $pane;
  $display->panels['left'][3] = 'new-5f4057bb-31f2-4d68-adc3-c5be42a2dbe2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects_partners_partner'] = $page;

  return $pages;

}
