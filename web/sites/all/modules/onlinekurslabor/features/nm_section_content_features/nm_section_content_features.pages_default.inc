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
  $page->path = 'domain/media/%1';
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
  $handler->name = 'page__thema_medien_panel_context';
  $handler->task = 'page';
  $handler->subtask = '_thema_medien';
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
    'title' => '',
    'body' => '<h2>Medien</h2>',
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
    'title' => 'Medien hochladen',
    'body' => '<?php
/*
$output = drupal_get_form(\'file_entity_add_upload\');
echo drupal_render($output);

*/

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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '84216daa-f867-4920-88f6-847fcd8a6d45';
  $display->content['new-84216daa-f867-4920-88f6-847fcd8a6d45'] = $pane;
  $display->panels['center'][2] = 'new-84216daa-f867-4920-88f6-847fcd8a6d45';
  $pane = new stdClass();
  $pane->pid = 'new-e1b1670f-b0fb-4df1-828d-b0baf8a86fab';
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
  $pane->uuid = 'e1b1670f-b0fb-4df1-828d-b0baf8a86fab';
  $display->content['new-e1b1670f-b0fb-4df1-828d-b0baf8a86fab'] = $pane;
  $display->panels['outline'][0] = 'new-e1b1670f-b0fb-4df1-828d-b0baf8a86fab';
  $pane = new stdClass();
  $pane->pid = 'new-961ca31d-d4f2-4923-a3d0-b6dc9634f504';
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
  $pane->uuid = '961ca31d-d4f2-4923-a3d0-b6dc9634f504';
  $display->content['new-961ca31d-d4f2-4923-a3d0-b6dc9634f504'] = $pane;
  $display->panels['tools'][0] = 'new-961ca31d-d4f2-4923-a3d0-b6dc9634f504';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1372a02f-af1a-4a17-969e-dea5cc505e38';
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
  $handler->name = 'page_bibliografie_in_thema__panel_context';
  $handler->task = 'page';
  $handler->subtask = 'bibliografie_in_thema_';
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
    'title' => '',
    'body' => '<h2>Bibliografie</h2>',
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
  $pane->pid = 'new-db7daf2d-d362-426f-b256-9a3133b00a76';
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
  $pane->uuid = 'db7daf2d-d362-426f-b256-9a3133b00a76';
  $display->content['new-db7daf2d-d362-426f-b256-9a3133b00a76'] = $pane;
  $display->panels['outline'][0] = 'new-db7daf2d-d362-426f-b256-9a3133b00a76';
  $pane = new stdClass();
  $pane->pid = 'new-adc381d0-24d8-44ca-8e44-bc4fcd0417a3';
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
  $pane->uuid = 'adc381d0-24d8-44ca-8e44-bc4fcd0417a3';
  $display->content['new-adc381d0-24d8-44ca-8e44-bc4fcd0417a3'] = $pane;
  $display->panels['tools'][0] = 'new-adc381d0-24d8-44ca-8e44-bc4fcd0417a3';
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
    'plugins' => array(
      0 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'create',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_node_add_1',
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
  $pane->pid = 'new-e324dd83-0a9e-4832-8a05-ad617efea05a';
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
  $pane->uuid = 'e324dd83-0a9e-4832-8a05-ad617efea05a';
  $display->content['new-e324dd83-0a9e-4832-8a05-ad617efea05a'] = $pane;
  $display->panels['outline'][0] = 'new-e324dd83-0a9e-4832-8a05-ad617efea05a';
  $pane = new stdClass();
  $pane->pid = 'new-757da329-e12e-4824-9680-fe9dddadb05b';
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
  $pane->uuid = '757da329-e12e-4824-9680-fe9dddadb05b';
  $display->content['new-757da329-e12e-4824-9680-fe9dddadb05b'] = $pane;
  $display->panels['tools'][0] = 'new-757da329-e12e-4824-9680-fe9dddadb05b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-757da329-e12e-4824-9680-fe9dddadb05b';
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
    'plugins' => array(
      1 => array(
        'name' => 'og_perm',
        'settings' => array(
          'perm' => 'update group',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
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
  $handler->name = 'page_content_domain_book_rearrange_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_book_rearrange';
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
    'title' => '',
    'body' => '<h2>Kapitelreihenfolge bearbeiten</h2>',
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
    'title' => '',
    'body' => '<?php 
module_load_include(\'inc\', \'book\', \'book.admin\');
$active_domain =  _section_content_get_active_domain();
echo (drupal_render(drupal_get_form(\'book_admin_edit\', $active_domain)));
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dc98c7d8-1ef4-41f2-8654-f1531033f066';
  $display->content['new-dc98c7d8-1ef4-41f2-8654-f1531033f066'] = $pane;
  $display->panels['center'][1] = 'new-dc98c7d8-1ef4-41f2-8654-f1531033f066';
  $pane = new stdClass();
  $pane->pid = 'new-661e451d-fe04-41b3-8b89-ef10905ff04b';
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
  $pane->uuid = '661e451d-fe04-41b3-8b89-ef10905ff04b';
  $display->content['new-661e451d-fe04-41b3-8b89-ef10905ff04b'] = $pane;
  $display->panels['outline'][0] = 'new-661e451d-fe04-41b3-8b89-ef10905ff04b';
  $pane = new stdClass();
  $pane->pid = 'new-cca1e15e-a0c4-4ca6-8d32-6673c6fbd39f';
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
  $pane->uuid = 'cca1e15e-a0c4-4ca6-8d32-6673c6fbd39f';
  $display->content['new-cca1e15e-a0c4-4ca6-8d32-6673c6fbd39f'] = $pane;
  $display->panels['tools'][0] = 'new-cca1e15e-a0c4-4ca6-8d32-6673c6fbd39f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cca1e15e-a0c4-4ca6-8d32-6673c6fbd39f';
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
    'plugins' => array(
      0 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'delete',
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
  $handler->name = 'page_content_domain_delete_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_delete_node';
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
    'title' => '',
    'body' => '<?php
module_load_include(\'inc\', \'node\', \'node.pages\');
echo drupal_render(drupal_get_form(\'node_delete_confirm\', node_load(arg(2))));

?>
',
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
  $pane->uuid = '88eeea87-22f2-4f4d-a0da-258d8c8a64c8';
  $display->content['new-88eeea87-22f2-4f4d-a0da-258d8c8a64c8'] = $pane;
  $display->panels['center'][0] = 'new-88eeea87-22f2-4f4d-a0da-258d8c8a64c8';
  $pane = new stdClass();
  $pane->pid = 'new-9cbf59ec-a9d6-43aa-a0cf-05d246da4672';
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
  $pane->uuid = '9cbf59ec-a9d6-43aa-a0cf-05d246da4672';
  $display->content['new-9cbf59ec-a9d6-43aa-a0cf-05d246da4672'] = $pane;
  $display->panels['outline'][0] = 'new-9cbf59ec-a9d6-43aa-a0cf-05d246da4672';
  $pane = new stdClass();
  $pane->pid = 'new-853759d6-71ae-43d9-9836-554b4bc5e322';
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
  $pane->uuid = '853759d6-71ae-43d9-9836-554b4bc5e322';
  $display->content['new-853759d6-71ae-43d9-9836-554b4bc5e322'] = $pane;
  $display->panels['tools'][0] = 'new-853759d6-71ae-43d9-9836-554b4bc5e322';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-853759d6-71ae-43d9-9836-554b4bc5e322';
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
    'plugins' => array(
      0 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'update',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_node_edit_1',
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
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $pane->pid = 'new-f5f4a298-c9a6-4eec-983f-1d415ea2bd35';
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
  $pane->uuid = 'f5f4a298-c9a6-4eec-983f-1d415ea2bd35';
  $display->content['new-f5f4a298-c9a6-4eec-983f-1d415ea2bd35'] = $pane;
  $display->panels['outline'][0] = 'new-f5f4a298-c9a6-4eec-983f-1d415ea2bd35';
  $pane = new stdClass();
  $pane->pid = 'new-2cec5631-5771-45df-9d74-f68761d2351f';
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
  $pane->uuid = '2cec5631-5771-45df-9d74-f68761d2351f';
  $display->content['new-2cec5631-5771-45df-9d74-f68761d2351f'] = $pane;
  $display->panels['tools'][0] = 'new-2cec5631-5771-45df-9d74-f68761d2351f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2cec5631-5771-45df-9d74-f68761d2351f';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_edit_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_overview';
  $page->task = 'page';
  $page->admin_title = 'content-domain-overview';
  $page->admin_description = '';
  $page->path = 'domains';
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
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = 'Themenübersicht';
  $display->uuid = 'c934c2f1-88da-4a44-b94a-7c1236afb18e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_overview_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f9870e43-99cb-4682-9489-c5d7330bb5fa';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<?php
if(section_content_authors_tools_access())
echo \'<p><a class="btn btn-default" href="/node/add/content-domain">Neues Thema anlegen</a></p>\';

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f9870e43-99cb-4682-9489-c5d7330bb5fa';
  $display->content['new-f9870e43-99cb-4682-9489-c5d7330bb5fa'] = $pane;
  $display->panels['center'][0] = 'new-f9870e43-99cb-4682-9489-c5d7330bb5fa';
  $pane = new stdClass();
  $pane->pid = 'new-0ccd70ae-f992-4272-a657-c4be449d7458';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'content_gebiete_bersicht';
  $pane->shown = TRUE;
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
  $pane->uuid = '0ccd70ae-f992-4272-a657-c4be449d7458';
  $display->content['new-0ccd70ae-f992-4272-a657-c4be449d7458'] = $pane;
  $display->panels['center'][1] = 'new-0ccd70ae-f992-4272-a657-c4be449d7458';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0ccd70ae-f992-4272-a657-c4be449d7458';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['content_domain_overview'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'content_domain_text';
  $page->task = 'page';
  $page->admin_title = 'content-domain-text';
  $page->admin_description = '';
  $page->path = 'domain/text/%1/!optional_nid';
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
    'optional_nid' => array(
      'id' => 2,
      'identifier' => 'Beitrag: optional',
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
              'h5p_content' => 'h5p_content',
              'content_chapter' => 'content_chapter',
              'content_domain' => 'content_domain',
              'content_multiple_choice' => 'content_multiple_choice',
              'content_question_and_answer' => 'content_question_and_answer',
              'biblio' => 'biblio',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '0',
          ),
          'context' => 'argument_entity_id:node_2',
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
  $display->title = '';
  $display->uuid = '876d0461-4391-48e4-8124-1844f2f67393';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_content_domain_text_panel_context';
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
  $display->panels['center'][1] = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane = new stdClass();
  $pane->pid = 'new-95b7d045-3914-40d0-bd3e-93b99fd176e9';
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
  $pane->uuid = '95b7d045-3914-40d0-bd3e-93b99fd176e9';
  $display->content['new-95b7d045-3914-40d0-bd3e-93b99fd176e9'] = $pane;
  $display->panels['outline'][0] = 'new-95b7d045-3914-40d0-bd3e-93b99fd176e9';
  $pane = new stdClass();
  $pane->pid = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
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
  $pane->uuid = '9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $display->content['new-9631f371-ad25-408f-81bf-f6c21c2b28c0'] = $pane;
  $display->panels['tools'][0] = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
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
    'title' => 'Panel: optional NID',
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
        2 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'biblio' => 'biblio',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'panel_with_optional_nid',
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
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_2',
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
  $pane->uuid = '87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $display->content['new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b'] = $pane;
  $display->panels['center'][1] = 'new-87c73d1d-3012-4ded-9ce6-95ea4bf9852b';
  $pane = new stdClass();
  $pane->pid = 'new-95b7d045-3914-40d0-bd3e-93b99fd176e9';
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
  $pane->uuid = '95b7d045-3914-40d0-bd3e-93b99fd176e9';
  $display->content['new-95b7d045-3914-40d0-bd3e-93b99fd176e9'] = $pane;
  $display->panels['outline'][0] = 'new-95b7d045-3914-40d0-bd3e-93b99fd176e9';
  $pane = new stdClass();
  $pane->pid = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
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
  $pane->uuid = '9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $display->content['new-9631f371-ad25-408f-81bf-f6c21c2b28c0'] = $pane;
  $display->panels['tools'][0] = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9631f371-ad25-408f-81bf-f6c21c2b28c0';
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
  $handler->name = 'page_content_domain_text_revisions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'content_domain_text_revisions';
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
              'content_chapter' => 'content_chapter',
              'content_domain' => 'content_domain',
              'content_multiple_choice' => 'content_multiple_choice',
              'content_question_and_answer' => 'content_question_and_answer',
              'biblio' => 'biblio',
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
  $pane->pid = 'new-c5066bf3-6e70-4261-95be-e3e91d6c9caa';
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
  $pane->uuid = 'c5066bf3-6e70-4261-95be-e3e91d6c9caa';
  $display->content['new-c5066bf3-6e70-4261-95be-e3e91d6c9caa'] = $pane;
  $display->panels['outline'][0] = 'new-c5066bf3-6e70-4261-95be-e3e91d6c9caa';
  $pane = new stdClass();
  $pane->pid = 'new-d636fad1-9cf2-4a4c-8da0-d48efd2e21de';
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
  $pane->uuid = 'd636fad1-9cf2-4a4c-8da0-d48efd2e21de';
  $display->content['new-d636fad1-9cf2-4a4c-8da0-d48efd2e21de'] = $pane;
  $display->panels['tools'][0] = 'new-d636fad1-9cf2-4a4c-8da0-d48efd2e21de';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d636fad1-9cf2-4a4c-8da0-d48efd2e21de';
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
  $handler->name = 'page_tasks_in_domain_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'tasks_in_domain';
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
    'title' => '',
    'body' => '<h2>Lernzielkontrollaufgaben</h2>',
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
  $pane->pid = 'new-96b8ba3f-ee7f-4a8a-84cf-5e39a12f2552';
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
  $pane->uuid = '96b8ba3f-ee7f-4a8a-84cf-5e39a12f2552';
  $display->content['new-96b8ba3f-ee7f-4a8a-84cf-5e39a12f2552'] = $pane;
  $display->panels['outline'][0] = 'new-96b8ba3f-ee7f-4a8a-84cf-5e39a12f2552';
  $pane = new stdClass();
  $pane->pid = 'new-5bc1aff9-809f-4eef-9e26-0d7101eaf5e2';
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
  $pane->uuid = '5bc1aff9-809f-4eef-9e26-0d7101eaf5e2';
  $display->content['new-5bc1aff9-809f-4eef-9e26-0d7101eaf5e2'] = $pane;
  $display->panels['tools'][0] = 'new-5bc1aff9-809f-4eef-9e26-0d7101eaf5e2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tasks_in_domain'] = $page;

  return $pages;

}
