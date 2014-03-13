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
  $display->uuid = '44142f04-2f6c-4e54-b0d9-aa5efdb4b255';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f3da3b3a-a6a0-409b-ad83-70668dd0f9bf';
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
    $pane->uuid = 'f3da3b3a-a6a0-409b-ad83-70668dd0f9bf';
    $display->content['new-f3da3b3a-a6a0-409b-ad83-70668dd0f9bf'] = $pane;
    $display->panels['center'][0] = 'new-f3da3b3a-a6a0-409b-ad83-70668dd0f9bf';
    $pane = new stdClass();
    $pane->pid = 'new-e0d508d3-f8ef-4eca-a0e6-29aefe976e7e';
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
    $pane->uuid = 'e0d508d3-f8ef-4eca-a0e6-29aefe976e7e';
    $display->content['new-e0d508d3-f8ef-4eca-a0e6-29aefe976e7e'] = $pane;
    $display->panels['center'][1] = 'new-e0d508d3-f8ef-4eca-a0e6-29aefe976e7e';
    $pane = new stdClass();
    $pane->pid = 'new-151d6fbf-5878-434c-b37a-75f425f2605c';
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
    $pane->uuid = '151d6fbf-5878-434c-b37a-75f425f2605c';
    $display->content['new-151d6fbf-5878-434c-b37a-75f425f2605c'] = $pane;
    $display->panels['center'][2] = 'new-151d6fbf-5878-434c-b37a-75f425f2605c';
    $pane = new stdClass();
    $pane->pid = 'new-dc85c202-0b08-46bd-84cd-3feb3d5e4386';
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
    $pane->uuid = 'dc85c202-0b08-46bd-84cd-3feb3d5e4386';
    $display->content['new-dc85c202-0b08-46bd-84cd-3feb3d5e4386'] = $pane;
    $display->panels['outline'][0] = 'new-dc85c202-0b08-46bd-84cd-3feb3d5e4386';
    $pane = new stdClass();
    $pane->pid = 'new-0927a82a-8c3b-41dc-bcf8-8a6148fb0c59';
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
    $pane->uuid = '0927a82a-8c3b-41dc-bcf8-8a6148fb0c59';
    $display->content['new-0927a82a-8c3b-41dc-bcf8-8a6148fb0c59'] = $pane;
    $display->panels['tools'][0] = 'new-0927a82a-8c3b-41dc-bcf8-8a6148fb0c59';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e0d508d3-f8ef-4eca-a0e6-29aefe976e7e';
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
  $display->uuid = '6b5e80d4-b01d-4d71-8aad-f37f3c571dc5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-48924b99-32eb-44d3-bb82-b9766f573abf';
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
    $pane->uuid = '48924b99-32eb-44d3-bb82-b9766f573abf';
    $display->content['new-48924b99-32eb-44d3-bb82-b9766f573abf'] = $pane;
    $display->panels['center'][0] = 'new-48924b99-32eb-44d3-bb82-b9766f573abf';
    $pane = new stdClass();
    $pane->pid = 'new-0392b491-56be-4173-b4f3-b121b4624a4a';
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
    $pane->uuid = '0392b491-56be-4173-b4f3-b121b4624a4a';
    $display->content['new-0392b491-56be-4173-b4f3-b121b4624a4a'] = $pane;
    $display->panels['center'][1] = 'new-0392b491-56be-4173-b4f3-b121b4624a4a';
    $pane = new stdClass();
    $pane->pid = 'new-5e0a0c59-fbc5-4465-acda-721271cac3a4';
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
    $pane->uuid = '5e0a0c59-fbc5-4465-acda-721271cac3a4';
    $display->content['new-5e0a0c59-fbc5-4465-acda-721271cac3a4'] = $pane;
    $display->panels['outline'][0] = 'new-5e0a0c59-fbc5-4465-acda-721271cac3a4';
    $pane = new stdClass();
    $pane->pid = 'new-7531771c-a855-4a40-939b-714157db405f';
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
    $pane->uuid = '7531771c-a855-4a40-939b-714157db405f';
    $display->content['new-7531771c-a855-4a40-939b-714157db405f'] = $pane;
    $display->panels['tools'][0] = 'new-7531771c-a855-4a40-939b-714157db405f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0392b491-56be-4173-b4f3-b121b4624a4a';
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
  $display->uuid = 'e6e2e4ba-1579-4f80-a981-0126e17d8137';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f07c12cc-c8d3-445a-bb78-ea6e8e8c0250';
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
    $pane->uuid = 'f07c12cc-c8d3-445a-bb78-ea6e8e8c0250';
    $display->content['new-f07c12cc-c8d3-445a-bb78-ea6e8e8c0250'] = $pane;
    $display->panels['center'][0] = 'new-f07c12cc-c8d3-445a-bb78-ea6e8e8c0250';
    $pane = new stdClass();
    $pane->pid = 'new-cd88974f-b24a-4e20-b152-f337a733b321';
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
    $pane->uuid = 'cd88974f-b24a-4e20-b152-f337a733b321';
    $display->content['new-cd88974f-b24a-4e20-b152-f337a733b321'] = $pane;
    $display->panels['outline'][0] = 'new-cd88974f-b24a-4e20-b152-f337a733b321';
    $pane = new stdClass();
    $pane->pid = 'new-0d6a8c90-894c-42fc-b029-ac02a60ea42e';
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
    $pane->uuid = '0d6a8c90-894c-42fc-b029-ac02a60ea42e';
    $display->content['new-0d6a8c90-894c-42fc-b029-ac02a60ea42e'] = $pane;
    $display->panels['tools'][0] = 'new-0d6a8c90-894c-42fc-b029-ac02a60ea42e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0d6a8c90-894c-42fc-b029-ac02a60ea42e';
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
  $display->uuid = '82feb452-4968-4c54-816c-f0d99f765483';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9ea171be-c3b4-4ba1-ac3c-7ad3b2efe308';
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
    $pane->uuid = '9ea171be-c3b4-4ba1-ac3c-7ad3b2efe308';
    $display->content['new-9ea171be-c3b4-4ba1-ac3c-7ad3b2efe308'] = $pane;
    $display->panels['center'][0] = 'new-9ea171be-c3b4-4ba1-ac3c-7ad3b2efe308';
    $pane = new stdClass();
    $pane->pid = 'new-dddb7919-e801-4ebd-b657-68688b1c19cb';
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
    $pane->uuid = 'dddb7919-e801-4ebd-b657-68688b1c19cb';
    $display->content['new-dddb7919-e801-4ebd-b657-68688b1c19cb'] = $pane;
    $display->panels['center'][1] = 'new-dddb7919-e801-4ebd-b657-68688b1c19cb';
    $pane = new stdClass();
    $pane->pid = 'new-070da4ab-1858-4c41-a8cc-b3d9c7959d22';
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
    $pane->uuid = '070da4ab-1858-4c41-a8cc-b3d9c7959d22';
    $display->content['new-070da4ab-1858-4c41-a8cc-b3d9c7959d22'] = $pane;
    $display->panels['outline'][0] = 'new-070da4ab-1858-4c41-a8cc-b3d9c7959d22';
    $pane = new stdClass();
    $pane->pid = 'new-62cc3c85-235c-4d31-8112-02ab04b20bf6';
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
    $pane->uuid = '62cc3c85-235c-4d31-8112-02ab04b20bf6';
    $display->content['new-62cc3c85-235c-4d31-8112-02ab04b20bf6'] = $pane;
    $display->panels['tools'][0] = 'new-62cc3c85-235c-4d31-8112-02ab04b20bf6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-62cc3c85-235c-4d31-8112-02ab04b20bf6';
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
  $display->uuid = '868399b8-c7dd-4264-855a-f9c83a70305d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2e685ed8-6ad8-4260-9f3f-9c8855c704c1';
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
    $pane->uuid = '2e685ed8-6ad8-4260-9f3f-9c8855c704c1';
    $display->content['new-2e685ed8-6ad8-4260-9f3f-9c8855c704c1'] = $pane;
    $display->panels['center'][0] = 'new-2e685ed8-6ad8-4260-9f3f-9c8855c704c1';
    $pane = new stdClass();
    $pane->pid = 'new-e963a43f-28b2-4ddf-b047-cd7768b92e0b';
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
    $pane->uuid = 'e963a43f-28b2-4ddf-b047-cd7768b92e0b';
    $display->content['new-e963a43f-28b2-4ddf-b047-cd7768b92e0b'] = $pane;
    $display->panels['outline'][0] = 'new-e963a43f-28b2-4ddf-b047-cd7768b92e0b';
    $pane = new stdClass();
    $pane->pid = 'new-cdd4231b-4e70-457a-9067-7943eb66268a';
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
    $pane->uuid = 'cdd4231b-4e70-457a-9067-7943eb66268a';
    $display->content['new-cdd4231b-4e70-457a-9067-7943eb66268a'] = $pane;
    $display->panels['tools'][0] = 'new-cdd4231b-4e70-457a-9067-7943eb66268a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cdd4231b-4e70-457a-9067-7943eb66268a';
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
  $display->uuid = '8fa60e85-1dc5-4dd0-a6eb-2c35975dfee8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4bacc3f4-3894-44af-aa8c-ff61a000cba4';
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
    $pane->uuid = '4bacc3f4-3894-44af-aa8c-ff61a000cba4';
    $display->content['new-4bacc3f4-3894-44af-aa8c-ff61a000cba4'] = $pane;
    $display->panels['center'][0] = 'new-4bacc3f4-3894-44af-aa8c-ff61a000cba4';
    $pane = new stdClass();
    $pane->pid = 'new-8064f111-aea5-4b21-ac44-387791b0cb54';
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
    $pane->uuid = '8064f111-aea5-4b21-ac44-387791b0cb54';
    $display->content['new-8064f111-aea5-4b21-ac44-387791b0cb54'] = $pane;
    $display->panels['center'][1] = 'new-8064f111-aea5-4b21-ac44-387791b0cb54';
    $pane = new stdClass();
    $pane->pid = 'new-bcd6dd64-e458-48e5-8349-33cef5306e57';
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
    $pane->uuid = 'bcd6dd64-e458-48e5-8349-33cef5306e57';
    $display->content['new-bcd6dd64-e458-48e5-8349-33cef5306e57'] = $pane;
    $display->panels['outline'][0] = 'new-bcd6dd64-e458-48e5-8349-33cef5306e57';
    $pane = new stdClass();
    $pane->pid = 'new-a1c8a5e3-8e9a-4319-bc74-a7d98da4170b';
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
    $pane->uuid = 'a1c8a5e3-8e9a-4319-bc74-a7d98da4170b';
    $display->content['new-a1c8a5e3-8e9a-4319-bc74-a7d98da4170b'] = $pane;
    $display->panels['tools'][0] = 'new-a1c8a5e3-8e9a-4319-bc74-a7d98da4170b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a1c8a5e3-8e9a-4319-bc74-a7d98da4170b';
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
  $display->uuid = 'd6f56cc9-cf4a-4aab-9a05-0415510d51c1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-97148ed0-7316-4739-9ed9-e3db94e42778';
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
    $pane->uuid = '97148ed0-7316-4739-9ed9-e3db94e42778';
    $display->content['new-97148ed0-7316-4739-9ed9-e3db94e42778'] = $pane;
    $display->panels['center'][0] = 'new-97148ed0-7316-4739-9ed9-e3db94e42778';
    $pane = new stdClass();
    $pane->pid = 'new-52250006-62c5-4442-8d72-7351aaf43850';
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
    $pane->uuid = '52250006-62c5-4442-8d72-7351aaf43850';
    $display->content['new-52250006-62c5-4442-8d72-7351aaf43850'] = $pane;
    $display->panels['center'][1] = 'new-52250006-62c5-4442-8d72-7351aaf43850';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-52250006-62c5-4442-8d72-7351aaf43850';
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
  $display->uuid = 'd4a979b2-33e8-4fee-a97a-eb3fe23605ce';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-eaeb8b83-0240-4f16-b2a7-6cc70fbcc911';
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
    $pane->uuid = 'eaeb8b83-0240-4f16-b2a7-6cc70fbcc911';
    $display->content['new-eaeb8b83-0240-4f16-b2a7-6cc70fbcc911'] = $pane;
    $display->panels['center'][0] = 'new-eaeb8b83-0240-4f16-b2a7-6cc70fbcc911';
    $pane = new stdClass();
    $pane->pid = 'new-c6e4ae9a-d359-452c-9b5f-ce81f304a4bf';
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
    $pane->uuid = 'c6e4ae9a-d359-452c-9b5f-ce81f304a4bf';
    $display->content['new-c6e4ae9a-d359-452c-9b5f-ce81f304a4bf'] = $pane;
    $display->panels['center'][1] = 'new-c6e4ae9a-d359-452c-9b5f-ce81f304a4bf';
    $pane = new stdClass();
    $pane->pid = 'new-39fb8261-3e6c-4511-8254-883c54976fea';
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
    $pane->uuid = '39fb8261-3e6c-4511-8254-883c54976fea';
    $display->content['new-39fb8261-3e6c-4511-8254-883c54976fea'] = $pane;
    $display->panels['outline'][0] = 'new-39fb8261-3e6c-4511-8254-883c54976fea';
    $pane = new stdClass();
    $pane->pid = 'new-33f9532c-bf34-4ce3-8bc2-f4ba42d2a0ee';
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
    $pane->uuid = '33f9532c-bf34-4ce3-8bc2-f4ba42d2a0ee';
    $display->content['new-33f9532c-bf34-4ce3-8bc2-f4ba42d2a0ee'] = $pane;
    $display->panels['tools'][0] = 'new-33f9532c-bf34-4ce3-8bc2-f4ba42d2a0ee';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-33f9532c-bf34-4ce3-8bc2-f4ba42d2a0ee';
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
  $display->uuid = 'b3f57e55-6e55-47aa-8458-3dda4e299176';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-893e3063-6dee-4305-a422-90dd91fb0099';
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
    $pane->uuid = '893e3063-6dee-4305-a422-90dd91fb0099';
    $display->content['new-893e3063-6dee-4305-a422-90dd91fb0099'] = $pane;
    $display->panels['center'][0] = 'new-893e3063-6dee-4305-a422-90dd91fb0099';
    $pane = new stdClass();
    $pane->pid = 'new-bf4a8073-9ae7-4ad8-b35f-dfd1cf4137d7';
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
    $pane->uuid = 'bf4a8073-9ae7-4ad8-b35f-dfd1cf4137d7';
    $display->content['new-bf4a8073-9ae7-4ad8-b35f-dfd1cf4137d7'] = $pane;
    $display->panels['center'][1] = 'new-bf4a8073-9ae7-4ad8-b35f-dfd1cf4137d7';
    $pane = new stdClass();
    $pane->pid = 'new-2f72f0ce-66ca-4d7b-8686-9d42741bab35';
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
    $pane->uuid = '2f72f0ce-66ca-4d7b-8686-9d42741bab35';
    $display->content['new-2f72f0ce-66ca-4d7b-8686-9d42741bab35'] = $pane;
    $display->panels['outline'][0] = 'new-2f72f0ce-66ca-4d7b-8686-9d42741bab35';
    $pane = new stdClass();
    $pane->pid = 'new-4f800fa7-ee44-4ed0-91ab-a46e1024e0a3';
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
    $pane->uuid = '4f800fa7-ee44-4ed0-91ab-a46e1024e0a3';
    $display->content['new-4f800fa7-ee44-4ed0-91ab-a46e1024e0a3'] = $pane;
    $display->panels['tools'][0] = 'new-4f800fa7-ee44-4ed0-91ab-a46e1024e0a3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tasks_in_domain'] = $page;

  return $pages;

}
