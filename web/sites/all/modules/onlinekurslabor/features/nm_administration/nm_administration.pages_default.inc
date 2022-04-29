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
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'context' => 'logged-in-user',
        'name' => 'perm',
        'not' => FALSE,
        'settings' => array(
          'perm' => 'bypass node access',
        ),
      ),
    ),
    'settings' => NULL,
    'type' => 'none',
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
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_length',
          'not' => FALSE,
          'settings' => array(
            'length' => '0',
            'operator' => '=',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Dashboard',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span6span3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'left' => NULL,
      'main_' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'tabs_' => NULL,
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
    'args' => '',
    'display' => 'default',
    'feed_icons' => 0,
    'link_to_view' => 0,
    'more_link' => 0,
    'nodes_per_page' => '15',
    'offset' => '0',
    'override_pager_settings' => 0,
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => 'Aktivität',
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
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'content',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'inhalt',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Inhalt',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'left' => NULL,
      'main_' => NULL,
      'navigation' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'tabs_' => NULL,
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
  $pane->pid = 'new-cb630f5f-aa2f-414a-8677-592d9f659c60';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '',
    'format' => 'filtered_html',
    'name' => 'administration_fieldset_addnew',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cb630f5f-aa2f-414a-8677-592d9f659c60';
  $display->content['new-cb630f5f-aa2f-414a-8677-592d9f659c60'] = $pane;
  $display->panels['center'][0] = 'new-cb630f5f-aa2f-414a-8677-592d9f659c60';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8d61a498-1efd-47c7-a6b1-48018039a31e';
  $display->content['new-8d61a498-1efd-47c7-a6b1-48018039a31e'] = $pane;
  $display->panels['center'][1] = 'new-8d61a498-1efd-47c7-a6b1-48018039a31e';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'follow' => 0,
    'level' => '1',
    'menu_name' => 'menu-administration',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'parent' => 'menu-administration:0',
    'parent_mlid' => '0',
    'sort' => 0,
    'title_link' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->content['new-a3b10c57-cd41-4203-b01b-1b53336c8dd5'] = $pane;
  $display->panels['navigation'][0] = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane = new stdClass();
  $pane->pid = 'new-91994c19-1372-4249-b82f-aa10b1352b58';
  $pane->panel = 'navigation';
  $pane->type = 'block';
  $pane->subtype = 'views-812df940c9e9bba8d7b25f89e1e04058';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_class' => 'administration-exposed-filter',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '91994c19-1372-4249-b82f-aa10b1352b58';
  $display->content['new-91994c19-1372-4249-b82f-aa10b1352b58'] = $pane;
  $display->panels['navigation'][1] = 'new-91994c19-1372-4249-b82f-aa10b1352b58';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_administration__kurse';
  $handler->task = 'page';
  $handler->subtask = 'administration';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'courses',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'kurse',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Kurse',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'left' => NULL,
      'main_' => NULL,
      'navigation' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'tabs_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '812cb22d-b415-448a-b0ba-d177e188680d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_administration__kurse';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bf952f00-13df-4757-9422-6228bbc0d151';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'administration_fieldset_addnew';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '',
    'format' => 'filtered_html',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bf952f00-13df-4757-9422-6228bbc0d151';
  $display->content['new-bf952f00-13df-4757-9422-6228bbc0d151'] = $pane;
  $display->panels['center'][0] = 'new-bf952f00-13df-4757-9422-6228bbc0d151';
  $pane = new stdClass();
  $pane->pid = 'new-80b3037b-c714-4ee0-ae27-a6600142701a';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'administration_courses-panel_administration_courses';
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
  $pane->uuid = '80b3037b-c714-4ee0-ae27-a6600142701a';
  $display->content['new-80b3037b-c714-4ee0-ae27-a6600142701a'] = $pane;
  $display->panels['center'][1] = 'new-80b3037b-c714-4ee0-ae27-a6600142701a';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'follow' => 0,
    'level' => '1',
    'menu_name' => 'menu-administration',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'parent' => 'menu-administration:0',
    'parent_mlid' => '0',
    'sort' => 0,
    'title_link' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->content['new-a3b10c57-cd41-4203-b01b-1b53336c8dd5'] = $pane;
  $display->panels['navigation'][0] = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane = new stdClass();
  $pane->pid = 'new-27e7d0b9-28ff-489b-942f-4217f10a35b7';
  $pane->panel = 'navigation';
  $pane->type = 'block';
  $pane->subtype = 'views-763cab687ee29a5f0e5ef1d2b722c705';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'administration-exposed-filter',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '27e7d0b9-28ff-489b-942f-4217f10a35b7';
  $display->content['new-27e7d0b9-28ff-489b-942f-4217f10a35b7'] = $pane;
  $display->panels['navigation'][1] = 'new-27e7d0b9-28ff-489b-942f-4217f10a35b7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_administration__semester';
  $handler->task = 'page';
  $handler->subtask = 'administration';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'semester',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'semester',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Semester',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'left' => NULL,
      'main_' => NULL,
      'navigation' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'tabs_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '812cb22d-b415-448a-b0ba-d177e188680d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_administration__semester';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0c411d76-2425-43af-84e9-2160a7ecfcb3';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'administration_fieldset_addnew';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '',
    'format' => 'filtered_html',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0c411d76-2425-43af-84e9-2160a7ecfcb3';
  $display->content['new-0c411d76-2425-43af-84e9-2160a7ecfcb3'] = $pane;
  $display->panels['center'][0] = 'new-0c411d76-2425-43af-84e9-2160a7ecfcb3';
  $pane = new stdClass();
  $pane->pid = 'new-a5c5dd35-a73b-4ec4-8fd2-990c453d2a21';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Set current semester',
    'body' => '<?php
/*rendert form, um  aktuelles semester festzulegen */
$form_set_default_sem = drupal_get_form(\'section_courses_get_config_form_default_semester\');
print drupal_render($form_set_default_sem);
?>',
    'format' => 'php_code',
    'substitute' => 0,
    'title' => 'Aktuelles Semester festlegen',
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
  $pane->uuid = 'a5c5dd35-a73b-4ec4-8fd2-990c453d2a21';
  $display->content['new-a5c5dd35-a73b-4ec4-8fd2-990c453d2a21'] = $pane;
  $display->panels['center'][1] = 'new-a5c5dd35-a73b-4ec4-8fd2-990c453d2a21';
  $pane = new stdClass();
  $pane->pid = 'new-578bec4e-99cc-4ebe-be2d-47208ee2b4d3';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'form-semester-sort',
    'body' => '<?php
/*lädt die form von admin/structure/taxonomy/semester*/
if ($vocabulary = taxonomy_vocabulary_machine_name_load(\'semester\')) {
  module_load_include(\'inc\', \'taxonomy\', \'taxonomy.admin\');
  $edit = array();
  $taxonomy_form = drupal_get_form(\'taxonomy_overview_terms\',$vocabulary);
  echo drupal_render($taxonomy_form);
}
?>',
    'format' => 'php_code',
    'substitute' => 1,
    'title' => 'Semester-Reihenfolge ändern',
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
  $pane->uuid = '578bec4e-99cc-4ebe-be2d-47208ee2b4d3';
  $display->content['new-578bec4e-99cc-4ebe-be2d-47208ee2b4d3'] = $pane;
  $display->panels['center'][2] = 'new-578bec4e-99cc-4ebe-be2d-47208ee2b4d3';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'follow' => 0,
    'level' => '1',
    'menu_name' => 'menu-administration',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'parent' => 'menu-administration:0',
    'parent_mlid' => '0',
    'sort' => 0,
    'title_link' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->content['new-a3b10c57-cd41-4203-b01b-1b53336c8dd5'] = $pane;
  $display->panels['navigation'][0] = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_administration__benutzer';
  $handler->task = 'page';
  $handler->subtask = 'administration';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'users',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'benutzer',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Benutzer',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'left' => NULL,
      'main_' => NULL,
      'navigation' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'tabs_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '812cb22d-b415-448a-b0ba-d177e188680d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_administration__benutzer';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-52ac27dd-cb62-4237-b99e-d3f021354fe8';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'administration_fieldset_addnew';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '',
    'format' => 'filtered_html',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '52ac27dd-cb62-4237-b99e-d3f021354fe8';
  $display->content['new-52ac27dd-cb62-4237-b99e-d3f021354fe8'] = $pane;
  $display->panels['center'][0] = 'new-52ac27dd-cb62-4237-b99e-d3f021354fe8';
  $pane = new stdClass();
  $pane->pid = 'new-840743b4-d905-482f-b49d-4c349ccf8ea6';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'administration_active_users-panel_pane_administration_users';
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
  $pane->uuid = '840743b4-d905-482f-b49d-4c349ccf8ea6';
  $display->content['new-840743b4-d905-482f-b49d-4c349ccf8ea6'] = $pane;
  $display->panels['center'][1] = 'new-840743b4-d905-482f-b49d-4c349ccf8ea6';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'follow' => 0,
    'level' => '1',
    'menu_name' => 'menu-administration',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'parent' => 'menu-administration:0',
    'parent_mlid' => '0',
    'sort' => 0,
    'title_link' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->content['new-a3b10c57-cd41-4203-b01b-1b53336c8dd5'] = $pane;
  $display->panels['navigation'][0] = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane = new stdClass();
  $pane->pid = 'new-aa2daaa3-2aff-4e79-a1c4-39bd8231644a';
  $pane->panel = 'navigation';
  $pane->type = 'block';
  $pane->subtype = 'views-2b8760e6fd1ce3d6bd9721b10f82a9ca';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'administration-exposed-filter',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'aa2daaa3-2aff-4e79-a1c4-39bd8231644a';
  $display->content['new-aa2daaa3-2aff-4e79-a1c4-39bd8231644a'] = $pane;
  $display->panels['navigation'][1] = 'new-aa2daaa3-2aff-4e79-a1c4-39bd8231644a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_administration__dateien';
  $handler->task = 'page';
  $handler->subtask = 'administration';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'files',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'dateien',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Dateien',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'left' => NULL,
      'main_' => NULL,
      'navigation' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'tabs_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '812cb22d-b415-448a-b0ba-d177e188680d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_administration__dateien';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-52ac27dd-cb62-4237-b99e-d3f021354fe8';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'administration_fieldset_addnew';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '',
    'format' => 'filtered_html',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '52ac27dd-cb62-4237-b99e-d3f021354fe8';
  $display->content['new-52ac27dd-cb62-4237-b99e-d3f021354fe8'] = $pane;
  $display->panels['center'][0] = 'new-52ac27dd-cb62-4237-b99e-d3f021354fe8';
  $pane = new stdClass();
  $pane->pid = 'new-f9f66a77-4321-4fb6-ae5e-902d7dffc410';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'administration_files-pane_files';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '50',
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
  $pane->uuid = 'f9f66a77-4321-4fb6-ae5e-902d7dffc410';
  $display->content['new-f9f66a77-4321-4fb6-ae5e-902d7dffc410'] = $pane;
  $display->panels['center'][1] = 'new-f9f66a77-4321-4fb6-ae5e-902d7dffc410';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'follow' => 0,
    'level' => '1',
    'menu_name' => 'menu-administration',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'parent' => 'menu-administration:0',
    'parent_mlid' => '0',
    'sort' => 0,
    'title_link' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->content['new-a3b10c57-cd41-4203-b01b-1b53336c8dd5'] = $pane;
  $display->panels['navigation'][0] = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane = new stdClass();
  $pane->pid = 'new-3c27706a-2da2-4cd0-b8db-941647f8f9db';
  $pane->panel = 'navigation';
  $pane->type = 'block';
  $pane->subtype = 'views-cf1228deb1b0419112086af77a22ad51';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'administration-exposed-filter',
    'css_id' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3c27706a-2da2-4cd0-b8db-941647f8f9db';
  $display->content['new-3c27706a-2da2-4cd0-b8db-941647f8f9db'] = $pane;
  $display->panels['navigation'][1] = 'new-3c27706a-2da2-4cd0-b8db-941647f8f9db';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_administration__videosafe';
  $handler->task = 'page';
  $handler->subtask = 'administration';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_string_1',
          'name' => 'string_equal',
          'not' => FALSE,
          'settings' => array(
            'case' => 0,
            'operator' => '=',
            'value' => 'videosafe',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'videosafe',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'Videosafe',
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span6span3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'center' => NULL,
      'default' => NULL,
      'left' => NULL,
      'main_' => NULL,
      'navigation' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'tabs_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '812cb22d-b415-448a-b0ba-d177e188680d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_administration__videosafe';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9975bba5-9d04-40d8-9ecb-7f808e464863';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<h4><a href="/videosafe">Direkt zum Videosafe</a></h4><p>&nbsp;</p><p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - oder -&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</p><p>&nbsp;</p>',
    'format' => 'filtered_html',
    'substitute' => 1,
    'title' => '',
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
  $pane->uuid = '9975bba5-9d04-40d8-9ecb-7f808e464863';
  $display->content['new-9975bba5-9d04-40d8-9ecb-7f808e464863'] = $pane;
  $display->panels['center'][0] = 'new-9975bba5-9d04-40d8-9ecb-7f808e464863';
  $pane = new stdClass();
  $pane->pid = 'new-0ff6d3c7-89ff-498d-8301-9ba0a6d71d7f';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'videosafe_folderview-panel_pane_5';
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
  $pane->uuid = '0ff6d3c7-89ff-498d-8301-9ba0a6d71d7f';
  $display->content['new-0ff6d3c7-89ff-498d-8301-9ba0a6d71d7f'] = $pane;
  $display->panels['center'][1] = 'new-0ff6d3c7-89ff-498d-8301-9ba0a6d71d7f';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'follow' => 0,
    'level' => '1',
    'menu_name' => 'menu-administration',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'parent' => 'menu-administration:0',
    'parent_mlid' => '0',
    'sort' => 0,
    'title_link' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->content['new-a3b10c57-cd41-4203-b01b-1b53336c8dd5'] = $pane;
  $display->panels['left'][0] = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['administration'] = $page;

  return $pages;

}
