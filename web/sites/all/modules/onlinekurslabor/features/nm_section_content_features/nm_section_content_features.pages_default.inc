<?php

/**
 * @file
 * nm_section_content_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nm_section_content_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = '_thema_medien';
  $page->task = 'page';
  $page->admin_title = 'content-domain-media';
  $page->admin_description = '';
  $page->path = 'domain/media/%1/!fid';
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
    'fid' => array(
      'id' => 1,
      'identifier' => 'Datei: ID',
      'name' => 'entity_id:file',
      'settings' => array(),
    ),
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
  $handler->name = 'page__thema_medien_panel_context';
  $handler->task = 'page';
  $handler->subtask = '_thema_medien';
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
        1 => array(
          'context' => 'argument_entity_id:file_1',
          'name' => 'context_exists',
          'not' => FALSE,
          'settings' => array(
            'exists' => '0',
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
    'title' => 'Overview All Media',
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
  $display->title = '';
  $display->uuid = '79fb8291-2d31-44cb-b8ea-24d04a55af19';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page__thema_medien_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-013c6315-7df0-4087-9b08-0c69085a5bf6';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2>Medien</h2>',
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
  $pane->uuid = '013c6315-7df0-4087-9b08-0c69085a5bf6';
  $display->content['new-013c6315-7df0-4087-9b08-0c69085a5bf6'] = $pane;
  $display->panels['center'][0] = 'new-013c6315-7df0-4087-9b08-0c69085a5bf6';
  $pane = new stdClass();
  $pane->pid = 'new-1372a02f-af1a-4a17-969e-dea5cc505e38';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'domain_media-panel_pane_1';
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
  $pane->uuid = '1372a02f-af1a-4a17-969e-dea5cc505e38';
  $display->content['new-1372a02f-af1a-4a17-969e-dea5cc505e38'] = $pane;
  $display->panels['center'][1] = 'new-1372a02f-af1a-4a17-969e-dea5cc505e38';
  $pane = new stdClass();
  $pane->pid = 'new-84216daa-f867-4920-88f6-847fcd8a6d45';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Add File',
    'body' => '<?php
/*
$output = drupal_get_form(\'file_entity_add_upload\');
echo drupal_render($output);

*/

?>',
    'format' => 'php_code',
    'substitute' => 1,
    'title' => 'Medien hochladen',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '84216daa-f867-4920-88f6-847fcd8a6d45';
  $display->content['new-84216daa-f867-4920-88f6-847fcd8a6d45'] = $pane;
  $display->panels['center'][2] = 'new-84216daa-f867-4920-88f6-847fcd8a6d45';
  $pane = new stdClass();
  $pane->pid = 'new-fa196b8a-7b48-4867-9332-81e6330ccd60';
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
  $pane->uuid = 'fa196b8a-7b48-4867-9332-81e6330ccd60';
  $display->content['new-fa196b8a-7b48-4867-9332-81e6330ccd60'] = $pane;
  $display->panels['navigation'][0] = 'new-fa196b8a-7b48-4867-9332-81e6330ccd60';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1372a02f-af1a-4a17-969e-dea5cc505e38';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page__thema_medien__media_entity';
  $handler->task = 'page';
  $handler->subtask = '_thema_medien';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
    'name' => 'media_entity',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Media_Entity',
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
  $display->title = '';
  $display->uuid = '79fb8291-2d31-44cb-b8ea-24d04a55af19';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page__thema_medien__media_entity';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-013c6315-7df0-4087-9b08-0c69085a5bf6';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2>Medien</h2>',
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
  $pane->uuid = '013c6315-7df0-4087-9b08-0c69085a5bf6';
  $display->content['new-013c6315-7df0-4087-9b08-0c69085a5bf6'] = $pane;
  $display->panels['center'][0] = 'new-013c6315-7df0-4087-9b08-0c69085a5bf6';
  $pane = new stdClass();
  $pane->pid = 'new-6512570a-dcd2-4c39-a45b-c43dd0eba63a';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'view_single_file';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:file_1.fid',
    ),
    'display' => 'default',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '0',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '6512570a-dcd2-4c39-a45b-c43dd0eba63a';
  $display->content['new-6512570a-dcd2-4c39-a45b-c43dd0eba63a'] = $pane;
  $display->panels['center'][1] = 'new-6512570a-dcd2-4c39-a45b-c43dd0eba63a';
  $pane = new stdClass();
  $pane->pid = 'new-19b421fe-f861-4464-a8eb-cabeefaf89a9';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'file usage',
    'body' => '<?php
echo _custom_general_get_rendered_file_usage_table(%fid:fid);
?>',
    'format' => 'php_code',
    'substitute' => 1,
    'title' => 'Dateiverwendung',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '19b421fe-f861-4464-a8eb-cabeefaf89a9';
  $display->content['new-19b421fe-f861-4464-a8eb-cabeefaf89a9'] = $pane;
  $display->panels['center'][2] = 'new-19b421fe-f861-4464-a8eb-cabeefaf89a9';
  $pane = new stdClass();
  $pane->pid = 'new-fa196b8a-7b48-4867-9332-81e6330ccd60';
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
  $pane->uuid = 'fa196b8a-7b48-4867-9332-81e6330ccd60';
  $display->content['new-fa196b8a-7b48-4867-9332-81e6330ccd60'] = $pane;
  $display->panels['navigation'][0] = 'new-fa196b8a-7b48-4867-9332-81e6330ccd60';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['_thema_medien'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'bibliografie_in_thema_';
  $page->task = 'page';
  $page->admin_title = 'content-domain-biblio';
  $page->admin_description = '';
  $page->path = 'domain/biblio/%1';
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
  $handler->name = 'page_bibliografie_in_thema__panel_context';
  $handler->task = 'page';
  $handler->subtask = 'bibliografie_in_thema_';
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
  $display->title = '';
  $display->uuid = 'd71c9f71-33fe-472f-8843-ea88a58ffd27';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_bibliografie_in_thema__panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0647741b-d9ad-4433-ace7-6d55c6a0c9d6';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2>Bibliografie</h2>',
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
  $pane->uuid = '0647741b-d9ad-4433-ace7-6d55c6a0c9d6';
  $display->content['new-0647741b-d9ad-4433-ace7-6d55c6a0c9d6'] = $pane;
  $display->panels['center'][0] = 'new-0647741b-d9ad-4433-ace7-6d55c6a0c9d6';
  $pane = new stdClass();
  $pane->pid = 'new-61cdc791-6138-4cfe-a276-06d50af301b6';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'domain_biblio-panel_pane_1';
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
  $pane->uuid = '61cdc791-6138-4cfe-a276-06d50af301b6';
  $display->content['new-61cdc791-6138-4cfe-a276-06d50af301b6'] = $pane;
  $display->panels['center'][1] = 'new-61cdc791-6138-4cfe-a276-06d50af301b6';
  $pane = new stdClass();
  $pane->pid = 'new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
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
  $pane->uuid = '8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
  $display->content['new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060'] = $pane;
  $display->panels['navigation'][0] = 'new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-61cdc791-6138-4cfe-a276-06d50af301b6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bibliografie_in_thema_'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_add_node';
  $page->task = 'page';
  $page->admin_title = 'content-domain-add-node';
  $page->admin_description = '';
  $page->path = 'domain/add/%1/%2';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_node_add_1',
        ),
        'name' => 'node_access',
        'not' => FALSE,
        'settings' => array(
          'type' => 'create',
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
    2 => array(
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
  $handler->name = 'page_content_domain_add_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_add_node';
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
  $display->title = '';
  $display->uuid = '0a11672e-752f-44e8-895b-535d51ea0266';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_add_node_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8f383689-e8bd-4823-adb3-3cd25988a415';
  $pane->panel = 'center';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_add_1',
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
  $pane->uuid = '8f383689-e8bd-4823-adb3-3cd25988a415';
  $display->content['new-8f383689-e8bd-4823-adb3-3cd25988a415'] = $pane;
  $display->panels['center'][0] = 'new-8f383689-e8bd-4823-adb3-3cd25988a415';
  $pane = new stdClass();
  $pane->pid = 'new-6d34e539-b095-40ed-ab47-a11f1a207185';
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
  $pane->uuid = '6d34e539-b095-40ed-ab47-a11f1a207185';
  $display->content['new-6d34e539-b095-40ed-ab47-a11f1a207185'] = $pane;
  $display->panels['navigation'][0] = 'new-6d34e539-b095-40ed-ab47-a11f1a207185';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_add_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_book_rearrange';
  $page->task = 'page';
  $page->admin_title = 'content-domain-book-rearrange';
  $page->admin_description = '';
  $page->path = 'domain/text/%1/rearrange';
  $page->access = array(
    'logic' => 'or',
    'plugins' => array(
      1 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'name' => 'og_perm',
        'not' => FALSE,
        'settings' => array(
          'perm' => 'update group',
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
  $handler->name = 'page_content_domain_book_rearrange_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_book_rearrange';
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
  $display->title = '<non>';
  $display->uuid = '20013950-44a5-47a6-9560-e5b46a323220';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_book_rearrange_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9dd85fef-5d5b-4150-90e3-024799d500da';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2>Kapitelreihenfolge bearbeiten</h2>',
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
  $pane->uuid = '9dd85fef-5d5b-4150-90e3-024799d500da';
  $display->content['new-9dd85fef-5d5b-4150-90e3-024799d500da'] = $pane;
  $display->panels['center'][0] = 'new-9dd85fef-5d5b-4150-90e3-024799d500da';
  $pane = new stdClass();
  $pane->pid = 'new-dc98c7d8-1ef4-41f2-8654-f1531033f066';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<?php 
module_load_include(\'inc\', \'book\', \'book.admin\');
$active_domain =  _section_content_get_active_domain();
echo (drupal_render(drupal_get_form(\'book_admin_edit\', $active_domain)));
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dc98c7d8-1ef4-41f2-8654-f1531033f066';
  $display->content['new-dc98c7d8-1ef4-41f2-8654-f1531033f066'] = $pane;
  $display->panels['center'][1] = 'new-dc98c7d8-1ef4-41f2-8654-f1531033f066';
  $pane = new stdClass();
  $pane->pid = 'new-97771bf0-74f2-4668-944f-2a0721801e6b';
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
  $pane->uuid = '97771bf0-74f2-4668-944f-2a0721801e6b';
  $display->content['new-97771bf0-74f2-4668-944f-2a0721801e6b'] = $pane;
  $display->panels['navigation'][0] = 'new-97771bf0-74f2-4668-944f-2a0721801e6b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_book_rearrange'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_delete_node';
  $page->task = 'page';
  $page->admin_title = 'content-domain-delete-node';
  $page->admin_description = '';
  $page->path = 'domain/delete/%1';
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
          'type' => 'delete',
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
  $handler->name = 'page_content_domain_delete_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_delete_node';
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
  $display->title = '';
  $display->uuid = '970468d9-3db3-43be-aece-d753032419f8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_delete_node_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-88eeea87-22f2-4f4d-a0da-258d8c8a64c8';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<?php
module_load_include(\'inc\', \'node\', \'node.pages\');
echo drupal_render(drupal_get_form(\'node_delete_confirm\', node_load(arg(2))));

?>
',
    'format' => 'php_code',
    'substitute' => 0,
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
  $pane->uuid = '88eeea87-22f2-4f4d-a0da-258d8c8a64c8';
  $display->content['new-88eeea87-22f2-4f4d-a0da-258d8c8a64c8'] = $pane;
  $display->panels['center'][0] = 'new-88eeea87-22f2-4f4d-a0da-258d8c8a64c8';
  $pane = new stdClass();
  $pane->pid = 'new-c52f81b3-9d71-48a5-851e-7690cc009bac';
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
  $pane->uuid = 'c52f81b3-9d71-48a5-851e-7690cc009bac';
  $display->content['new-c52f81b3-9d71-48a5-851e-7690cc009bac'] = $pane;
  $display->panels['navigation'][0] = 'new-c52f81b3-9d71-48a5-851e-7690cc009bac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_delete_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_edit_node';
  $page->task = 'page';
  $page->admin_title = 'content-domain-edit-node';
  $page->admin_description = '';
  $page->path = 'domain/edit/%1';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_node_edit_1',
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
      'identifier' => 'Node edit form: node ID',
      'name' => 'node_edit',
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
  $handler->name = 'page_content_domain_edit_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_edit_node';
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
  $display->title = '';
  $display->uuid = 'fb1e16d9-9de8-4748-9b34-6b5d9713dd9c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_edit_node_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d1fb77e7-0473-43a1-90cf-645be2ebae77';
  $pane->panel = 'center';
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
  $pane->uuid = 'd1fb77e7-0473-43a1-90cf-645be2ebae77';
  $display->content['new-d1fb77e7-0473-43a1-90cf-645be2ebae77'] = $pane;
  $display->panels['center'][0] = 'new-d1fb77e7-0473-43a1-90cf-645be2ebae77';
  $pane = new stdClass();
  $pane->pid = 'new-95605ba2-9131-48b1-a189-a9056090b1f6';
  $pane->panel = 'center';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = '95605ba2-9131-48b1-a189-a9056090b1f6';
  $display->content['new-95605ba2-9131-48b1-a189-a9056090b1f6'] = $pane;
  $display->panels['center'][1] = 'new-95605ba2-9131-48b1-a189-a9056090b1f6';
  $pane = new stdClass();
  $pane->pid = 'new-9c8cbca3-6f2f-4a77-8c68-60923c09f6d3';
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
  $pane->uuid = '9c8cbca3-6f2f-4a77-8c68-60923c09f6d3';
  $display->content['new-9c8cbca3-6f2f-4a77-8c68-60923c09f6d3'] = $pane;
  $display->panels['navigation'][0] = 'new-9c8cbca3-6f2f-4a77-8c68-60923c09f6d3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_edit_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_members';
  $page->task = 'page';
  $page->admin_title = 'content-domain-members';
  $page->admin_description = '';
  $page->path = 'domain/members/%1';
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
  $handler->name = 'page_content_domain_members__panel_context_b453014b-a458-4030-b714-58131c1556e2';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_members';
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
    'name' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span4span8';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'center' => array(
      'style' => 'tabs',
    ),
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'navigation' => NULL,
      'outline' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd71c9f71-33fe-472f-8843-ea88a58ffd27';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_members__panel_context_b453014b-a458-4030-b714-58131c1556e2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-787bff3f-bc9d-432a-a24d-9819ec40d958';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'content_admin_mitglieder_tabelle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'block',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '50',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Mitglieder',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '787bff3f-bc9d-432a-a24d-9819ec40d958';
  $display->content['new-787bff3f-bc9d-432a-a24d-9819ec40d958'] = $pane;
  $display->panels['center'][0] = 'new-787bff3f-bc9d-432a-a24d-9819ec40d958';
  $pane = new stdClass();
  $pane->pid = 'new-93be2e3b-fe65-463a-b22f-ea6e7480b084';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'content_admin_mitglieder_tabelle';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'display' => 'bl_1',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '50',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Anfragen',
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
  $pane->uuid = '93be2e3b-fe65-463a-b22f-ea6e7480b084';
  $display->content['new-93be2e3b-fe65-463a-b22f-ea6e7480b084'] = $pane;
  $display->panels['center'][1] = 'new-93be2e3b-fe65-463a-b22f-ea6e7480b084';
  $pane = new stdClass();
  $pane->pid = 'new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
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
  $pane->uuid = '8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
  $display->content['new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060'] = $pane;
  $display->panels['navigation'][0] = 'new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_overview';
  $page->task = 'page';
  $page->admin_title = 'content-domain-overview';
  $page->admin_description = '';
  $page->path = 'domains';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 30037204,
            1 => 197637936,
            2 => 16675960,
          ),
        ),
      ),
    ),
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
  $handler->name = 'page_content_domain_overview_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_overview';
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
  $display->layout = 'flexible:span8span4_mobile_bottom_up';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c934c2f1-88da-4a44-b94a-7c1236afb18e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_overview_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-59380199-5ffc-40f8-a68f-ee83ec0f49ce';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'views-39b270ef35cd36d59833b7fb869475ea';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_heading' => 'div',
    'override_title_text' => 'Nach Titel filtern',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '59380199-5ffc-40f8-a68f-ee83ec0f49ce';
  $display->content['new-59380199-5ffc-40f8-a68f-ee83ec0f49ce'] = $pane;
  $display->panels['news'][0] = 'new-59380199-5ffc-40f8-a68f-ee83ec0f49ce';
  $pane = new stdClass();
  $pane->pid = 'new-c64ae76c-2207-474a-ae5f-b85034a7a8fb';
  $pane->panel = 'news';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'admin-info',
    'body' => '<p>hier wird die exposed form für "meine lehrtexte" - filter: titel angezeigt admin/structure/views/view/courses_user_domains/edit/my_domains</p><p>dieser filter funktioniert zugleich für "alle lehrtexte", obwohl exposed form nicht dargestellt, da in der adresszeile der parameter ?title=... mitgegeben wird und der identifier für "meine lehrtexte" der gleiche wie für "alle lehrtexte"</p>',
    'format' => 'filtered_html',
    'substitute' => TRUE,
    'title' => 'Infos fürn Admin',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c64ae76c-2207-474a-ae5f-b85034a7a8fb';
  $display->content['new-c64ae76c-2207-474a-ae5f-b85034a7a8fb'] = $pane;
  $display->panels['news'][1] = 'new-c64ae76c-2207-474a-ae5f-b85034a7a8fb';
  $pane = new stdClass();
  $pane->pid = 'new-f9870e43-99cb-4682-9489-c5d7330bb5fa';
  $pane->panel = 'news';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<?php
if(section_content_authors_tools_access())
echo \'<p><a class="btn btn-default" href="/node/add/content-domain">Neuen Lehrtext anlegen</a></p>\';

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title' => '',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f9870e43-99cb-4682-9489-c5d7330bb5fa';
  $display->content['new-f9870e43-99cb-4682-9489-c5d7330bb5fa'] = $pane;
  $display->panels['news'][2] = 'new-f9870e43-99cb-4682-9489-c5d7330bb5fa';
  $pane = new stdClass();
  $pane->pid = 'new-cfbdaa96-1d4c-43ee-b8b2-d2013e01addb';
  $pane->panel = 'tools';
  $pane->type = 'views_panes';
  $pane->subtype = 'courses_user_domains-my_domains';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '10',
    'offset' => '0',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '0',
    'path' => '/domains',
    'use_pager' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cfbdaa96-1d4c-43ee-b8b2-d2013e01addb';
  $display->content['new-cfbdaa96-1d4c-43ee-b8b2-d2013e01addb'] = $pane;
  $display->panels['tools'][0] = 'new-cfbdaa96-1d4c-43ee-b8b2-d2013e01addb';
  $pane = new stdClass();
  $pane->pid = 'new-db9f76c7-c1b9-49bd-bfdf-96533f4ade51';
  $pane->panel = 'tools';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '<hr>',
    'body' => '<hr>',
    'format' => 'filtered_html',
    'name' => 'html_hr_line',
    'substitute' => TRUE,
    'title' => '',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'db9f76c7-c1b9-49bd-bfdf-96533f4ade51';
  $display->content['new-db9f76c7-c1b9-49bd-bfdf-96533f4ade51'] = $pane;
  $display->panels['tools'][1] = 'new-db9f76c7-c1b9-49bd-bfdf-96533f4ade51';
  $pane = new stdClass();
  $pane->pid = 'new-cab0dcbb-116b-4741-8d67-ed6aecb2fed2';
  $pane->panel = 'tools';
  $pane->type = 'views_panes';
  $pane->subtype = 'courses_user_domains-all_domains';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '40',
    'offset' => '0',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '2',
    'path' => '',
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
  $pane->uuid = 'cab0dcbb-116b-4741-8d67-ed6aecb2fed2';
  $display->content['new-cab0dcbb-116b-4741-8d67-ed6aecb2fed2'] = $pane;
  $display->panels['tools'][2] = 'new-cab0dcbb-116b-4741-8d67-ed6aecb2fed2';
  $pane = new stdClass();
  $pane->pid = 'new-0ccd70ae-f992-4272-a657-c4be449d7458';
  $pane->panel = 'tools';
  $pane->type = 'views';
  $pane->subtype = 'content_gebiete_bersicht';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'args' => '',
    'display' => 'default',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '30',
    'offset' => '0',
    'override_pager_settings' => 1,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'pager_id' => '1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '0ccd70ae-f992-4272-a657-c4be449d7458';
  $display->content['new-0ccd70ae-f992-4272-a657-c4be449d7458'] = $pane;
  $display->panels['tools'][3] = 'new-0ccd70ae-f992-4272-a657-c4be449d7458';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-0ccd70ae-f992-4272-a657-c4be449d7458';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_overview'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_preview';
  $page->task = 'page';
  $page->admin_title = 'content-domain-preview';
  $page->admin_description = '';
  $page->path = 'domain/preview/%1/!optional_nid';
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
      1 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 30037204,
            1 => 197637936,
            2 => 16675960,
          ),
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array(
    'optional_nid' => array(
      'id' => 2,
      'identifier' => 'Beitrag: optional',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
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
  $handler->name = 'page_content_domain_preview__panel_context_89d9b17c-90a5-4df8-82aa-65b76bf8b98e';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_preview';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
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
    'name' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span9span3_mobile_bottom_up';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'navigation' => NULL,
      'news' => NULL,
      'outline' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '876d0461-4391-48e4-8124-1844f2f67393';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_preview__panel_context_89d9b17c-90a5-4df8-82aa-65b76bf8b98e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-af5545fc-55ee-4251-adee-dedfe09d8f6a';
  $pane->panel = 'news';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'preview',
    'body' => '<p>Sie sehen eine Vorschau des Lehrtexts.</p>',
    'format' => 'filtered_html',
    'substitute' => 1,
    'title' => 'Lehrtextvorschau',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'af5545fc-55ee-4251-adee-dedfe09d8f6a';
  $display->content['new-af5545fc-55ee-4251-adee-dedfe09d8f6a'] = $pane;
  $display->panels['news'][0] = 'new-af5545fc-55ee-4251-adee-dedfe09d8f6a';
  $pane = new stdClass();
  $pane->pid = 'new-9e4b8000-18ca-451d-bfe0-dc2b9060d434';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_link_to_fulltext';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '9e4b8000-18ca-451d-bfe0-dc2b9060d434';
  $display->content['new-9e4b8000-18ca-451d-bfe0-dc2b9060d434'] = $pane;
  $display->panels['news'][1] = 'new-9e4b8000-18ca-451d-bfe0-dc2b9060d434';
  $pane = new stdClass();
  $pane->pid = 'new-125d30e0-ec3e-4772-bd79-dfb12f90333b';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'custom_general-custom_general_groupstate_badge';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Ihre Mitgliedschaft',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '125d30e0-ec3e-4772-bd79-dfb12f90333b';
  $display->content['new-125d30e0-ec3e-4772-bd79-dfb12f90333b'] = $pane;
  $display->panels['news'][2] = 'new-125d30e0-ec3e-4772-bd79-dfb12f90333b';
  $pane = new stdClass();
  $pane->pid = 'new-a8acea0a-a611-4853-b68b-f25bc9b71aa6';
  $pane->panel = 'news';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:group_group';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'og_group_subscribe',
    'formatter_settings' => array(
      'field_name' => '0',
    ),
    'label' => 'title',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a8acea0a-a611-4853-b68b-f25bc9b71aa6';
  $display->content['new-a8acea0a-a611-4853-b68b-f25bc9b71aa6'] = $pane;
  $display->panels['news'][3] = 'new-a8acea0a-a611-4853-b68b-f25bc9b71aa6';
  $pane = new stdClass();
  $pane->pid = 'new-c6a13a76-4fa5-4efd-82f1-9243340defe6';
  $pane->panel = 'news';
  $pane->type = 'token';
  $pane->subtype = 'node:group-access';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'sanitize' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c6a13a76-4fa5-4efd-82f1-9243340defe6';
  $display->content['new-c6a13a76-4fa5-4efd-82f1-9243340defe6'] = $pane;
  $display->panels['news'][4] = 'new-c6a13a76-4fa5-4efd-82f1-9243340defe6';
  $pane = new stdClass();
  $pane->pid = 'new-59cbc4ef-5476-4f27-86ac-9b299155d407';
  $pane->panel = 'news';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:group_access';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'list_key',
    'formatter_settings' => array(),
    'label' => 'title',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '59cbc4ef-5476-4f27-86ac-9b299155d407';
  $display->content['new-59cbc4ef-5476-4f27-86ac-9b299155d407'] = $pane;
  $display->panels['news'][5] = 'new-59cbc4ef-5476-4f27-86ac-9b299155d407';
  $pane = new stdClass();
  $pane->pid = 'new-59733ad4-8ece-43de-a299-d1410984ad0a';
  $pane->panel = 'news';
  $pane->type = 'token';
  $pane->subtype = 'node:group_access';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Sichtbarkeit',
    'sanitize' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '59733ad4-8ece-43de-a299-d1410984ad0a';
  $display->content['new-59733ad4-8ece-43de-a299-d1410984ad0a'] = $pane;
  $display->panels['news'][6] = 'new-59733ad4-8ece-43de-a299-d1410984ad0a';
  $pane = new stdClass();
  $pane->pid = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane->panel = 'tools';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $display->content['new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b'] = $pane;
  $display->panels['tools'][0] = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane = new stdClass();
  $pane->pid = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_node_tabs';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7553bf90-888a-42b2-bb62-77e02186f4fb';
  $display->content['new-7553bf90-888a-42b2-bb62-77e02186f4fb'] = $pane;
  $display->panels['tools'][1] = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane = new stdClass();
  $pane->pid = 'new-867a6f59-1ee3-4488-8d03-cee89a28c347';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_text_outline';
  $pane->shown = FALSE;
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '867a6f59-1ee3-4488-8d03-cee89a28c347';
  $display->content['new-867a6f59-1ee3-4488-8d03-cee89a28c347'] = $pane;
  $display->panels['tools'][2] = 'new-867a6f59-1ee3-4488-8d03-cee89a28c347';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_content_domain_preview__no_access_to_rest';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_preview';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_type',
          'not' => TRUE,
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
    'name' => 'no_access_to_rest',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'no_access_to_rest',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span9span3_mobile_bottom_up';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'navigation' => NULL,
      'news' => NULL,
      'outline' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '876d0461-4391-48e4-8124-1844f2f67393';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_preview__no_access_to_rest';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-95ba47fe-9f63-4a85-acda-79cb654ae271';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'custom_general-custom_general_groupstate_badge';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
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
  $pane->uuid = '95ba47fe-9f63-4a85-acda-79cb654ae271';
  $display->content['new-95ba47fe-9f63-4a85-acda-79cb654ae271'] = $pane;
  $display->panels['news'][0] = 'new-95ba47fe-9f63-4a85-acda-79cb654ae271';
  $pane = new stdClass();
  $pane->pid = 'new-a8acea0a-a611-4853-b68b-f25bc9b71aa6';
  $pane->panel = 'news';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:group_group';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter' => 'og_group_subscribe',
    'formatter_settings' => array(
      'field_name' => '0',
    ),
    'label' => 'title',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a8acea0a-a611-4853-b68b-f25bc9b71aa6';
  $display->content['new-a8acea0a-a611-4853-b68b-f25bc9b71aa6'] = $pane;
  $display->panels['news'][1] = 'new-a8acea0a-a611-4853-b68b-f25bc9b71aa6';
  $pane = new stdClass();
  $pane->pid = 'new-9e4b8000-18ca-451d-bfe0-dc2b9060d434';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_link_to_fulltext';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '9e4b8000-18ca-451d-bfe0-dc2b9060d434';
  $display->content['new-9e4b8000-18ca-451d-bfe0-dc2b9060d434'] = $pane;
  $display->panels['news'][2] = 'new-9e4b8000-18ca-451d-bfe0-dc2b9060d434';
  $pane = new stdClass();
  $pane->pid = 'new-45316a9c-20b7-4b35-a579-c37782f41b38';
  $pane->panel = 'tools';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'no access',
    'body' => '<p><strong>Kein Zugriff</strong></p><p>Nur Mitglieder haben Zugriff auf die Unterkapitel.</p>',
    'format' => 'filtered_html',
    'substitute' => 1,
    'title' => '%1:title',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '45316a9c-20b7-4b35-a579-c37782f41b38';
  $display->content['new-45316a9c-20b7-4b35-a579-c37782f41b38'] = $pane;
  $display->panels['tools'][0] = 'new-45316a9c-20b7-4b35-a579-c37782f41b38';
  $pane = new stdClass();
  $pane->pid = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_node_tabs';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7553bf90-888a-42b2-bb62-77e02186f4fb';
  $display->content['new-7553bf90-888a-42b2-bb62-77e02186f4fb'] = $pane;
  $display->panels['tools'][1] = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane = new stdClass();
  $pane->pid = 'new-867a6f59-1ee3-4488-8d03-cee89a28c347';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_text_outline';
  $pane->shown = FALSE;
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '867a6f59-1ee3-4488-8d03-cee89a28c347';
  $display->content['new-867a6f59-1ee3-4488-8d03-cee89a28c347'] = $pane;
  $display->panels['tools'][2] = 'new-867a6f59-1ee3-4488-8d03-cee89a28c347';
  $pane = new stdClass();
  $pane->pid = 'new-db8e6e72-0c53-4c4a-8d81-1cdbbbe9360f';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_link_to_lehrtext_home';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'db8e6e72-0c53-4c4a-8d81-1cdbbbe9360f';
  $display->content['new-db8e6e72-0c53-4c4a-8d81-1cdbbbe9360f'] = $pane;
  $display->panels['tools'][3] = 'new-db8e6e72-0c53-4c4a-8d81-1cdbbbe9360f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_preview'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_stats';
  $page->task = 'page';
  $page->admin_title = 'content-domain-stats';
  $page->admin_description = '';
  $page->path = 'domain/stats/%1';
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
  $handler->name = 'page_content_domain_stats__panel_context_21358ad9-b863-4179-9d58-c9bdcd7df271';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_stats';
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
    'name' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span4span8';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'center' => array(
      'style' => 'tabs',
    ),
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'navigation' => NULL,
      'outline' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd71c9f71-33fe-472f-8843-ea88a58ffd27';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_stats__panel_context_21358ad9-b863-4179-9d58-c9bdcd7df271';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-883ec0cd-5795-458a-a2a5-34707a60bd07';
  $pane->panel = 'center';
  $pane->type = 'token';
  $pane->subtype = 'node:group_access';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Zugriffsbeschränkung',
    'sanitize' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '883ec0cd-5795-458a-a2a5-34707a60bd07';
  $display->content['new-883ec0cd-5795-458a-a2a5-34707a60bd07'] = $pane;
  $display->panels['center'][0] = 'new-883ec0cd-5795-458a-a2a5-34707a60bd07';
  $pane = new stdClass();
  $pane->pid = 'new-6f4a2837-30bc-4c82-ae54-5f08ab895657';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_lt_usage_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '6f4a2837-30bc-4c82-ae54-5f08ab895657';
  $display->content['new-6f4a2837-30bc-4c82-ae54-5f08ab895657'] = $pane;
  $display->panels['center'][1] = 'new-6f4a2837-30bc-4c82-ae54-5f08ab895657';
  $pane = new stdClass();
  $pane->pid = 'new-45b86522-e0b3-4f55-85f6-e34fdfe5628b';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'domain_media-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Medienübersicht',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '45b86522-e0b3-4f55-85f6-e34fdfe5628b';
  $display->content['new-45b86522-e0b3-4f55-85f6-e34fdfe5628b'] = $pane;
  $display->panels['center'][2] = 'new-45b86522-e0b3-4f55-85f6-e34fdfe5628b';
  $pane = new stdClass();
  $pane->pid = 'new-da0b6e9e-7a2b-42d5-9ff2-3de7bff3a02d';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<p>[collapsible]</p><h2>Lehrtext selbst exportieren</h2><p>Sie können diesen Lehrtext auf einer einzelnen Seite ausgeben lassen und bspw. als PDF abspeichern.</p><p><em>Die Darstellung kann abweichen; interaktive Elemente wie Videos sowie andere Medien außer Bildern sind nicht enthalten</em></p><p><strong><a href="/book/export/html/%1:nid">Export starten</a></strong></p><p>[/collapsible]</p><p>[collapsible]</p><h2>Lehrtextexport anfordern</h2><p>Sie können außerdem einen Export Ihres Lehrtexts anfordern. Nach Bearbeitung (<em>diese kann bis zu vierzehn Werktage in Anspruch nehmen</em>) erhalten Sie Zugang zu einem verschlüsselten Download. Um diesen herunterzuladen, müssen Sie sich an der Universität Augsburg oder im VPN befinden.</p><p>Die Zip-Datei enthält:</p><ul><li>eine "Readme" mit Übersicht über Inhalte des Ordners</li><li>Ihren Lehrtext als Word- und HTML-Dokument</li><li>eingebettete Grafiken und die meisten anderen Medien</li><li>alle benutzten H5P-Elemente <em>ohne Videos.</em></li></ul><p>Auf Anfrage können u.U. auch die zugehörigen Videos exportiert werden</p><ul><li>hierbei wird eine Einzelfallprüfung vorgenommen</li><li>ergänzen Sie diesen Wunsch bei Ihrer Anfrage</li></ul><p>Um einen solchen Export anzufordern, klicken Sie jetzt rechts auf "<strong>Hilfe und Konktakt</strong>", wählen als Thema "<strong>Export dieses Lehrtexts anfordern</strong>", ergänzen die Anfrage und schicken diese ab.</p><p>[/collapsible]</p>',
    'format' => 'filtered_html',
    'substitute' => 1,
    'title' => 'Lehrtext exportieren',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'da0b6e9e-7a2b-42d5-9ff2-3de7bff3a02d';
  $display->content['new-da0b6e9e-7a2b-42d5-9ff2-3de7bff3a02d'] = $pane;
  $display->panels['center'][3] = 'new-da0b6e9e-7a2b-42d5-9ff2-3de7bff3a02d';
  $pane = new stdClass();
  $pane->pid = 'new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
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
  $pane->uuid = '8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
  $display->content['new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060'] = $pane;
  $display->panels['navigation'][0] = 'new-8f16e9aa-1e2a-44d6-b6ad-7cb278edc060';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_stats'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_text';
  $page->task = 'page';
  $page->admin_title = 'content-domain-text';
  $page->admin_description = '';
  $page->path = 'domain/text/%1/!optional_nid';
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
      1 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 30037204,
            1 => 197637936,
            2 => 16675960,
          ),
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
  );
  $page->menu = array();
  $page->arguments = array(
    'optional_nid' => array(
      'id' => 2,
      'identifier' => 'Beitrag: optional',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
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
  $handler->name = 'page_content_domain_text_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_text';
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
              'annvid' => 'annvid',
              'biblio' => 'biblio',
              'content_chapter' => 'content_chapter',
              'content_domain' => 'content_domain',
              'content_multiple_choice' => 'content_multiple_choice',
              'content_question_and_answer' => 'content_question_and_answer',
              'h5p_content' => 'h5p_content',
            ),
          ),
        ),
        1 => array(
          'context' => 'argument_entity_id:node_2',
          'name' => 'context_exists',
          'not' => FALSE,
          'settings' => array(
            'exists' => '0',
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
  $display->title = '';
  $display->uuid = '876d0461-4391-48e4-8124-1844f2f67393';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_text_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cfd931b2-7f37-45f6-9269-4946afa53d32';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_not_accessible_message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
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
  $pane->uuid = 'cfd931b2-7f37-45f6-9269-4946afa53d32';
  $display->content['new-cfd931b2-7f37-45f6-9269-4946afa53d32'] = $pane;
  $display->panels['center'][0] = 'new-cfd931b2-7f37-45f6-9269-4946afa53d32';
  $pane = new stdClass();
  $pane->pid = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane->panel = 'center';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7553bf90-888a-42b2-bb62-77e02186f4fb';
  $display->content['new-7553bf90-888a-42b2-bb62-77e02186f4fb'] = $pane;
  $display->panels['center'][1] = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane = new stdClass();
  $pane->pid = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane->panel = 'center';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'view_mode' => 'full',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $display->content['new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b'] = $pane;
  $display->panels['center'][2] = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane = new stdClass();
  $pane->pid = 'new-867a6f59-1ee3-4488-8d03-cee89a28c347';
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
  $pane->uuid = '867a6f59-1ee3-4488-8d03-cee89a28c347';
  $display->content['new-867a6f59-1ee3-4488-8d03-cee89a28c347'] = $pane;
  $display->panels['navigation'][0] = 'new-867a6f59-1ee3-4488-8d03-cee89a28c347';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_content_domain_text__panel_with_optional_nid';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_text';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
        2 => array(
          'context' => 'argument_entity_id:node_2',
          'name' => 'context_exists',
          'not' => FALSE,
          'settings' => array(
            'exists' => '1',
          ),
        ),
        3 => array(
          'context' => 'argument_entity_id:node_2',
          'name' => 'node_type',
          'not' => FALSE,
          'settings' => array(
            'type' => array(
              'biblio' => 'biblio',
              'h5p_content' => 'h5p_content',
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
    'name' => 'panel_with_optional_nid',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Panel: optional NID',
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
  $display->title = '';
  $display->uuid = '876d0461-4391-48e4-8124-1844f2f67393';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_text__panel_with_optional_nid';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane->panel = 'center';
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
  $display->panels['center'][0] = 'new-7553bf90-888a-42b2-bb62-77e02186f4fb';
  $pane = new stdClass();
  $pane->pid = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane->panel = 'center';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_2',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'view_mode' => 'full',
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
  $display->panels['center'][1] = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane = new stdClass();
  $pane->pid = 'new-340893dc-0a6f-4683-bfc8-ed9026b14b65';
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
  $pane->uuid = '340893dc-0a6f-4683-bfc8-ed9026b14b65';
  $display->content['new-340893dc-0a6f-4683-bfc8-ed9026b14b65'] = $pane;
  $display->panels['navigation'][0] = 'new-340893dc-0a6f-4683-bfc8-ed9026b14b65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_text'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_text_revisions';
  $page->task = 'page';
  $page->admin_title = 'content-domain-text-revisions';
  $page->admin_description = '';
  $page->path = 'domain/text/%1/revisions';
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
      1 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 30037204,
            1 => 197637936,
            2 => 16675960,
          ),
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
  $handler->name = 'page_content_domain_text_revisions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_text_revisions';
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
              'annvid' => 'annvid',
              'biblio' => 'biblio',
              'content_chapter' => 'content_chapter',
              'content_domain' => 'content_domain',
              'content_multiple_choice' => 'content_multiple_choice',
              'content_question_and_answer' => 'content_question_and_answer',
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
  $display->title = '';
  $display->uuid = '2a2093b3-c265-4b71-abf6-016a00158059';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_text_revisions_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f07abfde-9824-4f17-a814-613b125db986';
  $pane->panel = 'center';
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
  $pane->uuid = 'f07abfde-9824-4f17-a814-613b125db986';
  $display->content['new-f07abfde-9824-4f17-a814-613b125db986'] = $pane;
  $display->panels['center'][0] = 'new-f07abfde-9824-4f17-a814-613b125db986';
  $pane = new stdClass();
  $pane->pid = 'new-3397e13e-aece-446d-b91f-dc386ca2fed4';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'section_content-content_node_revisions';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3397e13e-aece-446d-b91f-dc386ca2fed4';
  $display->content['new-3397e13e-aece-446d-b91f-dc386ca2fed4'] = $pane;
  $display->panels['center'][1] = 'new-3397e13e-aece-446d-b91f-dc386ca2fed4';
  $pane = new stdClass();
  $pane->pid = 'new-c06451bc-25ee-4254-a668-d88fe38af2f9';
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
  $pane->uuid = 'c06451bc-25ee-4254-a668-d88fe38af2f9';
  $display->content['new-c06451bc-25ee-4254-a668-d88fe38af2f9'] = $pane;
  $display->panels['navigation'][0] = 'new-c06451bc-25ee-4254-a668-d88fe38af2f9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_text_revisions'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tasks_in_domain';
  $page->task = 'page';
  $page->admin_title = 'Content - Thema - Aufgaben';
  $page->admin_description = '';
  $page->path = 'domain/tasks/%1';
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
  $handler->name = 'page_tasks_in_domain_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'tasks_in_domain';
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
  $display->uuid = 'ebea8215-325a-410c-a628-699ddd4c3d20';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_tasks_in_domain_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-da54bf5d-558b-4fd1-a4d4-9d8748c29062';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h2>Lernzielkontrollaufgaben</h2>',
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
  $pane->uuid = 'da54bf5d-558b-4fd1-a4d4-9d8748c29062';
  $display->content['new-da54bf5d-558b-4fd1-a4d4-9d8748c29062'] = $pane;
  $display->panels['center'][0] = 'new-da54bf5d-558b-4fd1-a4d4-9d8748c29062';
  $pane = new stdClass();
  $pane->pid = 'new-f719189a-66e4-4a88-a496-4f2ea3943812';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'content_tasks_overview-panel_pane_1';
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
  $pane->uuid = 'f719189a-66e4-4a88-a496-4f2ea3943812';
  $display->content['new-f719189a-66e4-4a88-a496-4f2ea3943812'] = $pane;
  $display->panels['center'][1] = 'new-f719189a-66e4-4a88-a496-4f2ea3943812';
  $pane = new stdClass();
  $pane->pid = 'new-d3f97bf7-4f6a-4f90-abd0-b61b062232df';
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
  $pane->uuid = 'd3f97bf7-4f6a-4f90-abd0-b61b062232df';
  $display->content['new-d3f97bf7-4f6a-4f90-abd0-b61b062232df'] = $pane;
  $display->panels['navigation'][0] = 'new-d3f97bf7-4f6a-4f90-abd0-b61b062232df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tasks_in_domain'] = $page;

  return $pages;

}
