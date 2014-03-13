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
  $display->uuid = '88520b40-d167-45a5-bd8e-0b52cc461c4e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-26063065-546f-463b-ab6e-59e19ee97c2e';
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
    $pane->uuid = '26063065-546f-463b-ab6e-59e19ee97c2e';
    $display->content['new-26063065-546f-463b-ab6e-59e19ee97c2e'] = $pane;
    $display->panels['center'][0] = 'new-26063065-546f-463b-ab6e-59e19ee97c2e';
    $pane = new stdClass();
    $pane->pid = 'new-14f46f06-3700-4d09-931a-30098528e2ab';
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
    $pane->uuid = '14f46f06-3700-4d09-931a-30098528e2ab';
    $display->content['new-14f46f06-3700-4d09-931a-30098528e2ab'] = $pane;
    $display->panels['center'][1] = 'new-14f46f06-3700-4d09-931a-30098528e2ab';
    $pane = new stdClass();
    $pane->pid = 'new-7e69f3b9-e2c1-42d8-af0f-1495c59b715a';
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
    $pane->uuid = '7e69f3b9-e2c1-42d8-af0f-1495c59b715a';
    $display->content['new-7e69f3b9-e2c1-42d8-af0f-1495c59b715a'] = $pane;
    $display->panels['center'][2] = 'new-7e69f3b9-e2c1-42d8-af0f-1495c59b715a';
    $pane = new stdClass();
    $pane->pid = 'new-90e757e7-229f-48ef-ae0c-bba9aebcc719';
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
    $pane->uuid = '90e757e7-229f-48ef-ae0c-bba9aebcc719';
    $display->content['new-90e757e7-229f-48ef-ae0c-bba9aebcc719'] = $pane;
    $display->panels['outline'][0] = 'new-90e757e7-229f-48ef-ae0c-bba9aebcc719';
    $pane = new stdClass();
    $pane->pid = 'new-74e5d65b-b0f2-4d41-9181-1b90dd89cf92';
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
    $pane->uuid = '74e5d65b-b0f2-4d41-9181-1b90dd89cf92';
    $display->content['new-74e5d65b-b0f2-4d41-9181-1b90dd89cf92'] = $pane;
    $display->panels['tools'][0] = 'new-74e5d65b-b0f2-4d41-9181-1b90dd89cf92';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-14f46f06-3700-4d09-931a-30098528e2ab';
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
  $display->uuid = '19fd7c72-a242-45d2-8aaf-24ebfd068481';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c8322680-35ac-479d-afbd-0a39588d0d8c';
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
    $pane->uuid = 'c8322680-35ac-479d-afbd-0a39588d0d8c';
    $display->content['new-c8322680-35ac-479d-afbd-0a39588d0d8c'] = $pane;
    $display->panels['center'][0] = 'new-c8322680-35ac-479d-afbd-0a39588d0d8c';
    $pane = new stdClass();
    $pane->pid = 'new-e1ac9f6a-aa72-4be0-bc69-04881ab9c63d';
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
    $pane->uuid = 'e1ac9f6a-aa72-4be0-bc69-04881ab9c63d';
    $display->content['new-e1ac9f6a-aa72-4be0-bc69-04881ab9c63d'] = $pane;
    $display->panels['center'][1] = 'new-e1ac9f6a-aa72-4be0-bc69-04881ab9c63d';
    $pane = new stdClass();
    $pane->pid = 'new-9eef04a2-7d1a-41ea-9a6d-a046ccb64548';
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
    $pane->uuid = '9eef04a2-7d1a-41ea-9a6d-a046ccb64548';
    $display->content['new-9eef04a2-7d1a-41ea-9a6d-a046ccb64548'] = $pane;
    $display->panels['outline'][0] = 'new-9eef04a2-7d1a-41ea-9a6d-a046ccb64548';
    $pane = new stdClass();
    $pane->pid = 'new-41484fd6-5829-4ea7-acb9-d3be2e69a942';
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
    $pane->uuid = '41484fd6-5829-4ea7-acb9-d3be2e69a942';
    $display->content['new-41484fd6-5829-4ea7-acb9-d3be2e69a942'] = $pane;
    $display->panels['tools'][0] = 'new-41484fd6-5829-4ea7-acb9-d3be2e69a942';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e1ac9f6a-aa72-4be0-bc69-04881ab9c63d';
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
  $display->uuid = '26dace11-1fde-4820-a165-f190a7b5c042';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-11a2199a-053d-48b1-87db-ba680c3dc224';
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
    $pane->uuid = '11a2199a-053d-48b1-87db-ba680c3dc224';
    $display->content['new-11a2199a-053d-48b1-87db-ba680c3dc224'] = $pane;
    $display->panels['center'][0] = 'new-11a2199a-053d-48b1-87db-ba680c3dc224';
    $pane = new stdClass();
    $pane->pid = 'new-956978e0-a14d-4843-9e82-7222427dc1ec';
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
    $pane->uuid = '956978e0-a14d-4843-9e82-7222427dc1ec';
    $display->content['new-956978e0-a14d-4843-9e82-7222427dc1ec'] = $pane;
    $display->panels['outline'][0] = 'new-956978e0-a14d-4843-9e82-7222427dc1ec';
    $pane = new stdClass();
    $pane->pid = 'new-fb7a325e-3ea9-49f8-9127-bb1e4a6baf04';
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
    $pane->uuid = 'fb7a325e-3ea9-49f8-9127-bb1e4a6baf04';
    $display->content['new-fb7a325e-3ea9-49f8-9127-bb1e4a6baf04'] = $pane;
    $display->panels['tools'][0] = 'new-fb7a325e-3ea9-49f8-9127-bb1e4a6baf04';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fb7a325e-3ea9-49f8-9127-bb1e4a6baf04';
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
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer book outlines',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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
  $display->uuid = 'aab8cebb-62e9-4d81-ae60-a0c0aaf94628';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-29b81275-bb59-4295-a9eb-ebbadf73866f';
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
    $pane->uuid = '29b81275-bb59-4295-a9eb-ebbadf73866f';
    $display->content['new-29b81275-bb59-4295-a9eb-ebbadf73866f'] = $pane;
    $display->panels['center'][0] = 'new-29b81275-bb59-4295-a9eb-ebbadf73866f';
    $pane = new stdClass();
    $pane->pid = 'new-e6c149f4-4e08-4300-bb3b-bfded12d62b8';
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
    $pane->uuid = 'e6c149f4-4e08-4300-bb3b-bfded12d62b8';
    $display->content['new-e6c149f4-4e08-4300-bb3b-bfded12d62b8'] = $pane;
    $display->panels['center'][1] = 'new-e6c149f4-4e08-4300-bb3b-bfded12d62b8';
    $pane = new stdClass();
    $pane->pid = 'new-a3b72c49-5d76-4a39-b1e6-ef1fb17e37dc';
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
    $pane->uuid = 'a3b72c49-5d76-4a39-b1e6-ef1fb17e37dc';
    $display->content['new-a3b72c49-5d76-4a39-b1e6-ef1fb17e37dc'] = $pane;
    $display->panels['outline'][0] = 'new-a3b72c49-5d76-4a39-b1e6-ef1fb17e37dc';
    $pane = new stdClass();
    $pane->pid = 'new-4d85d8a4-dca8-4f11-b2ca-aa12a6f8e580';
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
    $pane->uuid = '4d85d8a4-dca8-4f11-b2ca-aa12a6f8e580';
    $display->content['new-4d85d8a4-dca8-4f11-b2ca-aa12a6f8e580'] = $pane;
    $display->panels['tools'][0] = 'new-4d85d8a4-dca8-4f11-b2ca-aa12a6f8e580';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d85d8a4-dca8-4f11-b2ca-aa12a6f8e580';
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
  $display->uuid = '5dd40633-a7ae-4899-a2e4-005b058a9f01';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ec96d61f-3edd-4071-a53a-c32ab6a63eae';
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
    $pane->uuid = 'ec96d61f-3edd-4071-a53a-c32ab6a63eae';
    $display->content['new-ec96d61f-3edd-4071-a53a-c32ab6a63eae'] = $pane;
    $display->panels['center'][0] = 'new-ec96d61f-3edd-4071-a53a-c32ab6a63eae';
    $pane = new stdClass();
    $pane->pid = 'new-b1906c7c-cb03-43a9-971b-1c2a547326bc';
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
    $pane->uuid = 'b1906c7c-cb03-43a9-971b-1c2a547326bc';
    $display->content['new-b1906c7c-cb03-43a9-971b-1c2a547326bc'] = $pane;
    $display->panels['outline'][0] = 'new-b1906c7c-cb03-43a9-971b-1c2a547326bc';
    $pane = new stdClass();
    $pane->pid = 'new-f0955600-26da-4a2c-a2b2-c513d4af1eac';
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
    $pane->uuid = 'f0955600-26da-4a2c-a2b2-c513d4af1eac';
    $display->content['new-f0955600-26da-4a2c-a2b2-c513d4af1eac'] = $pane;
    $display->panels['tools'][0] = 'new-f0955600-26da-4a2c-a2b2-c513d4af1eac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f0955600-26da-4a2c-a2b2-c513d4af1eac';
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
  $display->uuid = '292d7269-23b4-4523-9c69-ff798109ee30';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-df832109-df5e-4bb2-99bc-fcd5a86b1740';
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
    $pane->uuid = 'df832109-df5e-4bb2-99bc-fcd5a86b1740';
    $display->content['new-df832109-df5e-4bb2-99bc-fcd5a86b1740'] = $pane;
    $display->panels['center'][0] = 'new-df832109-df5e-4bb2-99bc-fcd5a86b1740';
    $pane = new stdClass();
    $pane->pid = 'new-7a867ebe-092c-4369-a1f6-0cba5f0f7ea1';
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
    $pane->uuid = '7a867ebe-092c-4369-a1f6-0cba5f0f7ea1';
    $display->content['new-7a867ebe-092c-4369-a1f6-0cba5f0f7ea1'] = $pane;
    $display->panels['center'][1] = 'new-7a867ebe-092c-4369-a1f6-0cba5f0f7ea1';
    $pane = new stdClass();
    $pane->pid = 'new-9a529c2c-b238-4010-912f-03ef6b986cbb';
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
    $pane->uuid = '9a529c2c-b238-4010-912f-03ef6b986cbb';
    $display->content['new-9a529c2c-b238-4010-912f-03ef6b986cbb'] = $pane;
    $display->panels['outline'][0] = 'new-9a529c2c-b238-4010-912f-03ef6b986cbb';
    $pane = new stdClass();
    $pane->pid = 'new-ca1790ff-c3c9-4c13-bd40-1bc7f2514b25';
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
    $pane->uuid = 'ca1790ff-c3c9-4c13-bd40-1bc7f2514b25';
    $display->content['new-ca1790ff-c3c9-4c13-bd40-1bc7f2514b25'] = $pane;
    $display->panels['tools'][0] = 'new-ca1790ff-c3c9-4c13-bd40-1bc7f2514b25';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ca1790ff-c3c9-4c13-bd40-1bc7f2514b25';
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
  $display->uuid = '1b322b32-d5b9-4281-b313-841993bc8626';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-38b49b50-6023-4828-b7bd-199dbf2030bf';
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
echo \'<p><a class="btn" href="/node/add/content-domain">Neues Thema anlegen</a></p>\';

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
    $pane->uuid = '38b49b50-6023-4828-b7bd-199dbf2030bf';
    $display->content['new-38b49b50-6023-4828-b7bd-199dbf2030bf'] = $pane;
    $display->panels['center'][0] = 'new-38b49b50-6023-4828-b7bd-199dbf2030bf';
    $pane = new stdClass();
    $pane->pid = 'new-e71e6d06-382a-4024-bfb9-74cb35f16ab3';
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
    $pane->uuid = 'e71e6d06-382a-4024-bfb9-74cb35f16ab3';
    $display->content['new-e71e6d06-382a-4024-bfb9-74cb35f16ab3'] = $pane;
    $display->panels['center'][1] = 'new-e71e6d06-382a-4024-bfb9-74cb35f16ab3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e71e6d06-382a-4024-bfb9-74cb35f16ab3';
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
  $page->path = 'domain/text/%1';
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
  $display->uuid = '83deac03-51f2-46e2-8e39-72e28a25433c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-02e708d9-b45f-4712-b97e-2ceeb73a19ff';
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
    $pane->uuid = '02e708d9-b45f-4712-b97e-2ceeb73a19ff';
    $display->content['new-02e708d9-b45f-4712-b97e-2ceeb73a19ff'] = $pane;
    $display->panels['center'][0] = 'new-02e708d9-b45f-4712-b97e-2ceeb73a19ff';
    $pane = new stdClass();
    $pane->pid = 'new-775f4099-bfdf-4082-b320-60327c673ba4';
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
    $pane->uuid = '775f4099-bfdf-4082-b320-60327c673ba4';
    $display->content['new-775f4099-bfdf-4082-b320-60327c673ba4'] = $pane;
    $display->panels['center'][1] = 'new-775f4099-bfdf-4082-b320-60327c673ba4';
    $pane = new stdClass();
    $pane->pid = 'new-dccd4393-c031-4329-bc40-fffd09cc5c70';
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
    $pane->uuid = 'dccd4393-c031-4329-bc40-fffd09cc5c70';
    $display->content['new-dccd4393-c031-4329-bc40-fffd09cc5c70'] = $pane;
    $display->panels['outline'][0] = 'new-dccd4393-c031-4329-bc40-fffd09cc5c70';
    $pane = new stdClass();
    $pane->pid = 'new-6bc53d1b-230a-42cf-8a21-393e3a14645e';
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
    $pane->uuid = '6bc53d1b-230a-42cf-8a21-393e3a14645e';
    $display->content['new-6bc53d1b-230a-42cf-8a21-393e3a14645e'] = $pane;
    $display->panels['tools'][0] = 'new-6bc53d1b-230a-42cf-8a21-393e3a14645e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6bc53d1b-230a-42cf-8a21-393e3a14645e';
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
  $display->uuid = '94ae2849-d5b3-43fb-8753-c4e2c7589a69';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a27d8aa9-dee2-44a3-b0d6-fef4a54dd7a6';
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
    $pane->uuid = 'a27d8aa9-dee2-44a3-b0d6-fef4a54dd7a6';
    $display->content['new-a27d8aa9-dee2-44a3-b0d6-fef4a54dd7a6'] = $pane;
    $display->panels['center'][0] = 'new-a27d8aa9-dee2-44a3-b0d6-fef4a54dd7a6';
    $pane = new stdClass();
    $pane->pid = 'new-b943f0d8-100a-41db-88f0-d193bb5d90b6';
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
    $pane->uuid = 'b943f0d8-100a-41db-88f0-d193bb5d90b6';
    $display->content['new-b943f0d8-100a-41db-88f0-d193bb5d90b6'] = $pane;
    $display->panels['center'][1] = 'new-b943f0d8-100a-41db-88f0-d193bb5d90b6';
    $pane = new stdClass();
    $pane->pid = 'new-f4982cf3-2dc8-4d02-bc5c-885396738a0b';
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
    $pane->uuid = 'f4982cf3-2dc8-4d02-bc5c-885396738a0b';
    $display->content['new-f4982cf3-2dc8-4d02-bc5c-885396738a0b'] = $pane;
    $display->panels['outline'][0] = 'new-f4982cf3-2dc8-4d02-bc5c-885396738a0b';
    $pane = new stdClass();
    $pane->pid = 'new-25b1c222-30aa-4b8d-9ca9-b36e37106b11';
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
    $pane->uuid = '25b1c222-30aa-4b8d-9ca9-b36e37106b11';
    $display->content['new-25b1c222-30aa-4b8d-9ca9-b36e37106b11'] = $pane;
    $display->panels['tools'][0] = 'new-25b1c222-30aa-4b8d-9ca9-b36e37106b11';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tasks_in_domain'] = $page;

  return $pages;

}
