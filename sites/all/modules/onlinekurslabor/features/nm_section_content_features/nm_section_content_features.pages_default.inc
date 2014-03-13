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
  $display->uuid = 'bd9e011e-019e-4732-9f23-1e21473734d7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-12826a3c-0287-41f6-af4f-ef3b22c1bbf2';
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
    $pane->uuid = '12826a3c-0287-41f6-af4f-ef3b22c1bbf2';
    $display->content['new-12826a3c-0287-41f6-af4f-ef3b22c1bbf2'] = $pane;
    $display->panels['center'][0] = 'new-12826a3c-0287-41f6-af4f-ef3b22c1bbf2';
    $pane = new stdClass();
    $pane->pid = 'new-e614c849-1e32-4187-bbe6-a4ac16fc9ecd';
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
    $pane->uuid = 'e614c849-1e32-4187-bbe6-a4ac16fc9ecd';
    $display->content['new-e614c849-1e32-4187-bbe6-a4ac16fc9ecd'] = $pane;
    $display->panels['center'][1] = 'new-e614c849-1e32-4187-bbe6-a4ac16fc9ecd';
    $pane = new stdClass();
    $pane->pid = 'new-6feee378-754a-40a8-8616-120a2bda868f';
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
    $pane->uuid = '6feee378-754a-40a8-8616-120a2bda868f';
    $display->content['new-6feee378-754a-40a8-8616-120a2bda868f'] = $pane;
    $display->panels['center'][2] = 'new-6feee378-754a-40a8-8616-120a2bda868f';
    $pane = new stdClass();
    $pane->pid = 'new-ae0c5b0f-f2a5-4769-8706-6d9e775e3723';
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
    $pane->uuid = 'ae0c5b0f-f2a5-4769-8706-6d9e775e3723';
    $display->content['new-ae0c5b0f-f2a5-4769-8706-6d9e775e3723'] = $pane;
    $display->panels['outline'][0] = 'new-ae0c5b0f-f2a5-4769-8706-6d9e775e3723';
    $pane = new stdClass();
    $pane->pid = 'new-53582fb4-6df9-4c0c-adc0-b106e50be8df';
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
    $pane->uuid = '53582fb4-6df9-4c0c-adc0-b106e50be8df';
    $display->content['new-53582fb4-6df9-4c0c-adc0-b106e50be8df'] = $pane;
    $display->panels['tools'][0] = 'new-53582fb4-6df9-4c0c-adc0-b106e50be8df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e614c849-1e32-4187-bbe6-a4ac16fc9ecd';
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
  $display->uuid = '0758c82f-ef05-4f39-b0d4-c47ac9dc0da5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c3c4ab14-bffc-4af4-bd48-8d4c945874d9';
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
    $pane->uuid = 'c3c4ab14-bffc-4af4-bd48-8d4c945874d9';
    $display->content['new-c3c4ab14-bffc-4af4-bd48-8d4c945874d9'] = $pane;
    $display->panels['center'][0] = 'new-c3c4ab14-bffc-4af4-bd48-8d4c945874d9';
    $pane = new stdClass();
    $pane->pid = 'new-6746dd3a-5b2d-4706-b048-1c475cfb0963';
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
    $pane->uuid = '6746dd3a-5b2d-4706-b048-1c475cfb0963';
    $display->content['new-6746dd3a-5b2d-4706-b048-1c475cfb0963'] = $pane;
    $display->panels['center'][1] = 'new-6746dd3a-5b2d-4706-b048-1c475cfb0963';
    $pane = new stdClass();
    $pane->pid = 'new-19c89c48-1f22-46da-ad00-9cf785da35df';
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
    $pane->uuid = '19c89c48-1f22-46da-ad00-9cf785da35df';
    $display->content['new-19c89c48-1f22-46da-ad00-9cf785da35df'] = $pane;
    $display->panels['outline'][0] = 'new-19c89c48-1f22-46da-ad00-9cf785da35df';
    $pane = new stdClass();
    $pane->pid = 'new-0047b816-dc17-4806-b42a-026f0f6a9ef8';
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
    $pane->uuid = '0047b816-dc17-4806-b42a-026f0f6a9ef8';
    $display->content['new-0047b816-dc17-4806-b42a-026f0f6a9ef8'] = $pane;
    $display->panels['tools'][0] = 'new-0047b816-dc17-4806-b42a-026f0f6a9ef8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6746dd3a-5b2d-4706-b048-1c475cfb0963';
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
  $display->uuid = '0bda0900-c393-4e0f-b16f-380a4bbd3ad2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-02331630-7bd9-42d4-804b-16ab02741328';
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
    $pane->uuid = '02331630-7bd9-42d4-804b-16ab02741328';
    $display->content['new-02331630-7bd9-42d4-804b-16ab02741328'] = $pane;
    $display->panels['center'][0] = 'new-02331630-7bd9-42d4-804b-16ab02741328';
    $pane = new stdClass();
    $pane->pid = 'new-96098672-e2fa-45ad-875a-ac835971de76';
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
    $pane->uuid = '96098672-e2fa-45ad-875a-ac835971de76';
    $display->content['new-96098672-e2fa-45ad-875a-ac835971de76'] = $pane;
    $display->panels['outline'][0] = 'new-96098672-e2fa-45ad-875a-ac835971de76';
    $pane = new stdClass();
    $pane->pid = 'new-512503d2-c78e-4291-977c-1b212164f265';
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
    $pane->uuid = '512503d2-c78e-4291-977c-1b212164f265';
    $display->content['new-512503d2-c78e-4291-977c-1b212164f265'] = $pane;
    $display->panels['tools'][0] = 'new-512503d2-c78e-4291-977c-1b212164f265';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-512503d2-c78e-4291-977c-1b212164f265';
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
  $display->uuid = '8da7eb0f-5314-4afd-8c94-184e31fe32f3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-50616653-62ad-4703-9d3e-362f21e3fada';
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
    $pane->uuid = '50616653-62ad-4703-9d3e-362f21e3fada';
    $display->content['new-50616653-62ad-4703-9d3e-362f21e3fada'] = $pane;
    $display->panels['center'][0] = 'new-50616653-62ad-4703-9d3e-362f21e3fada';
    $pane = new stdClass();
    $pane->pid = 'new-3b105211-4063-4ed3-876c-53cd931fd782';
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
    $pane->uuid = '3b105211-4063-4ed3-876c-53cd931fd782';
    $display->content['new-3b105211-4063-4ed3-876c-53cd931fd782'] = $pane;
    $display->panels['center'][1] = 'new-3b105211-4063-4ed3-876c-53cd931fd782';
    $pane = new stdClass();
    $pane->pid = 'new-b3600e15-1a55-47f8-9df5-853476d22eec';
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
    $pane->uuid = 'b3600e15-1a55-47f8-9df5-853476d22eec';
    $display->content['new-b3600e15-1a55-47f8-9df5-853476d22eec'] = $pane;
    $display->panels['outline'][0] = 'new-b3600e15-1a55-47f8-9df5-853476d22eec';
    $pane = new stdClass();
    $pane->pid = 'new-fd3d092c-9323-4940-87f4-960d827cbddb';
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
    $pane->uuid = 'fd3d092c-9323-4940-87f4-960d827cbddb';
    $display->content['new-fd3d092c-9323-4940-87f4-960d827cbddb'] = $pane;
    $display->panels['tools'][0] = 'new-fd3d092c-9323-4940-87f4-960d827cbddb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fd3d092c-9323-4940-87f4-960d827cbddb';
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
  $display->uuid = '4aaa73b2-ebb8-47fd-9ca1-b0349c237d85';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-51b8b681-b550-46df-9a38-ded42d452dde';
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
    $pane->uuid = '51b8b681-b550-46df-9a38-ded42d452dde';
    $display->content['new-51b8b681-b550-46df-9a38-ded42d452dde'] = $pane;
    $display->panels['center'][0] = 'new-51b8b681-b550-46df-9a38-ded42d452dde';
    $pane = new stdClass();
    $pane->pid = 'new-75179cb7-38b4-41d5-9114-780a7341029e';
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
    $pane->uuid = '75179cb7-38b4-41d5-9114-780a7341029e';
    $display->content['new-75179cb7-38b4-41d5-9114-780a7341029e'] = $pane;
    $display->panels['outline'][0] = 'new-75179cb7-38b4-41d5-9114-780a7341029e';
    $pane = new stdClass();
    $pane->pid = 'new-e1c694f3-a5d3-4af9-8467-64cd796d53e6';
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
    $pane->uuid = 'e1c694f3-a5d3-4af9-8467-64cd796d53e6';
    $display->content['new-e1c694f3-a5d3-4af9-8467-64cd796d53e6'] = $pane;
    $display->panels['tools'][0] = 'new-e1c694f3-a5d3-4af9-8467-64cd796d53e6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e1c694f3-a5d3-4af9-8467-64cd796d53e6';
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
  $display->uuid = '198fad43-37db-4b2c-b5a3-344fd50ea145';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-09801f0d-2452-43f8-ac04-3517a809b08d';
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
    $pane->uuid = '09801f0d-2452-43f8-ac04-3517a809b08d';
    $display->content['new-09801f0d-2452-43f8-ac04-3517a809b08d'] = $pane;
    $display->panels['center'][0] = 'new-09801f0d-2452-43f8-ac04-3517a809b08d';
    $pane = new stdClass();
    $pane->pid = 'new-1040b744-1878-434a-a2db-99515c47d345';
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
    $pane->uuid = '1040b744-1878-434a-a2db-99515c47d345';
    $display->content['new-1040b744-1878-434a-a2db-99515c47d345'] = $pane;
    $display->panels['center'][1] = 'new-1040b744-1878-434a-a2db-99515c47d345';
    $pane = new stdClass();
    $pane->pid = 'new-3f6d84a6-f6ab-4c9f-a9d9-885bb3344d98';
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
    $pane->uuid = '3f6d84a6-f6ab-4c9f-a9d9-885bb3344d98';
    $display->content['new-3f6d84a6-f6ab-4c9f-a9d9-885bb3344d98'] = $pane;
    $display->panels['outline'][0] = 'new-3f6d84a6-f6ab-4c9f-a9d9-885bb3344d98';
    $pane = new stdClass();
    $pane->pid = 'new-1f778799-da28-48c8-b2f6-4c8ff22f4e4f';
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
    $pane->uuid = '1f778799-da28-48c8-b2f6-4c8ff22f4e4f';
    $display->content['new-1f778799-da28-48c8-b2f6-4c8ff22f4e4f'] = $pane;
    $display->panels['tools'][0] = 'new-1f778799-da28-48c8-b2f6-4c8ff22f4e4f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1f778799-da28-48c8-b2f6-4c8ff22f4e4f';
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
  $display->uuid = '6c29b0e4-4752-49f1-9597-db1e913fe51e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7e4fc767-fb16-4cd3-acb9-612ba12c7554';
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
    $pane->uuid = '7e4fc767-fb16-4cd3-acb9-612ba12c7554';
    $display->content['new-7e4fc767-fb16-4cd3-acb9-612ba12c7554'] = $pane;
    $display->panels['center'][0] = 'new-7e4fc767-fb16-4cd3-acb9-612ba12c7554';
    $pane = new stdClass();
    $pane->pid = 'new-f1d4fd0f-dcb0-4366-9093-e16ae95c8291';
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
    $pane->uuid = 'f1d4fd0f-dcb0-4366-9093-e16ae95c8291';
    $display->content['new-f1d4fd0f-dcb0-4366-9093-e16ae95c8291'] = $pane;
    $display->panels['center'][1] = 'new-f1d4fd0f-dcb0-4366-9093-e16ae95c8291';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f1d4fd0f-dcb0-4366-9093-e16ae95c8291';
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
  $display->uuid = 'f69ff26a-0c54-4bb0-aee6-17dd1cd25640';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ef3b88a7-4371-4c00-abdc-9c86586bf913';
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
    $pane->uuid = 'ef3b88a7-4371-4c00-abdc-9c86586bf913';
    $display->content['new-ef3b88a7-4371-4c00-abdc-9c86586bf913'] = $pane;
    $display->panels['center'][0] = 'new-ef3b88a7-4371-4c00-abdc-9c86586bf913';
    $pane = new stdClass();
    $pane->pid = 'new-aa3e96c8-e992-407d-8e07-9d2001624fe9';
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
    $pane->uuid = 'aa3e96c8-e992-407d-8e07-9d2001624fe9';
    $display->content['new-aa3e96c8-e992-407d-8e07-9d2001624fe9'] = $pane;
    $display->panels['center'][1] = 'new-aa3e96c8-e992-407d-8e07-9d2001624fe9';
    $pane = new stdClass();
    $pane->pid = 'new-d7dea0b3-64a0-4b3b-adff-62458db7450b';
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
    $pane->uuid = 'd7dea0b3-64a0-4b3b-adff-62458db7450b';
    $display->content['new-d7dea0b3-64a0-4b3b-adff-62458db7450b'] = $pane;
    $display->panels['outline'][0] = 'new-d7dea0b3-64a0-4b3b-adff-62458db7450b';
    $pane = new stdClass();
    $pane->pid = 'new-6ec2f72e-630d-44d0-8a4c-fc5ff55bbcab';
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
    $pane->uuid = '6ec2f72e-630d-44d0-8a4c-fc5ff55bbcab';
    $display->content['new-6ec2f72e-630d-44d0-8a4c-fc5ff55bbcab'] = $pane;
    $display->panels['tools'][0] = 'new-6ec2f72e-630d-44d0-8a4c-fc5ff55bbcab';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6ec2f72e-630d-44d0-8a4c-fc5ff55bbcab';
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
  $display->uuid = 'e3150a01-4f9c-4eaa-9e59-f51179636687';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-531fdb8d-66de-4ad5-a332-7888e879bdcf';
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
    $pane->uuid = '531fdb8d-66de-4ad5-a332-7888e879bdcf';
    $display->content['new-531fdb8d-66de-4ad5-a332-7888e879bdcf'] = $pane;
    $display->panels['center'][0] = 'new-531fdb8d-66de-4ad5-a332-7888e879bdcf';
    $pane = new stdClass();
    $pane->pid = 'new-c47b5776-ed8d-4f7e-856b-e4b5280136ef';
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
    $pane->uuid = 'c47b5776-ed8d-4f7e-856b-e4b5280136ef';
    $display->content['new-c47b5776-ed8d-4f7e-856b-e4b5280136ef'] = $pane;
    $display->panels['center'][1] = 'new-c47b5776-ed8d-4f7e-856b-e4b5280136ef';
    $pane = new stdClass();
    $pane->pid = 'new-7093b150-0c42-4813-b28c-33c16d496a60';
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
    $pane->uuid = '7093b150-0c42-4813-b28c-33c16d496a60';
    $display->content['new-7093b150-0c42-4813-b28c-33c16d496a60'] = $pane;
    $display->panels['outline'][0] = 'new-7093b150-0c42-4813-b28c-33c16d496a60';
    $pane = new stdClass();
    $pane->pid = 'new-cc5ee5e7-927b-4f16-8893-ba01c1e15491';
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
    $pane->uuid = 'cc5ee5e7-927b-4f16-8893-ba01c1e15491';
    $display->content['new-cc5ee5e7-927b-4f16-8893-ba01c1e15491'] = $pane;
    $display->panels['tools'][0] = 'new-cc5ee5e7-927b-4f16-8893-ba01c1e15491';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tasks_in_domain'] = $page;

  return $pages;

}
