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
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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
    'title' => 'Dashboard',
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
          'name' => 'string_length',
          'settings' => array(
            'operator' => '=',
            'length' => '0',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span6span3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
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
    'override_title_text' => '',
    'override_title_heading' => 'h2',
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
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '15',
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
    'override_title_text' => 'Aktivität',
    'override_title_heading' => 'h2',
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
    'title' => 'Inhalt',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'inhalt',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'content',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'navigation' => NULL,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8d61a498-1efd-47c7-a6b1-48018039a31e';
  $display->content['new-8d61a498-1efd-47c7-a6b1-48018039a31e'] = $pane;
  $display->panels['center'][0] = 'new-8d61a498-1efd-47c7-a6b1-48018039a31e';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-administration:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-administration',
    'parent_mlid' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
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
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'administration-exposed-filter',
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
    'title' => 'Kurse',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'kurse',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'courses',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'navigation' => NULL,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '80b3037b-c714-4ee0-ae27-a6600142701a';
  $display->content['new-80b3037b-c714-4ee0-ae27-a6600142701a'] = $pane;
  $display->panels['center'][0] = 'new-80b3037b-c714-4ee0-ae27-a6600142701a';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-administration:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-administration',
    'parent_mlid' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
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
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'administration-exposed-filter',
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
    'title' => 'Semester',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'semester',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'semester',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'navigation' => NULL,
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
  $pane->pid = 'new-a5c5dd35-a73b-4ec4-8fd2-990c453d2a21';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Set current semester',
    'title' => 'Aktuelles Semester festlegen',
    'title_heading' => 'h2',
    'body' => '<?php
/*rendert form, um  aktuelles semester festzulegen */
$form_set_default_sem = drupal_get_form(\'section_courses_get_config_form_default_semester\');
print drupal_render($form_set_default_sem);
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
  $pane->uuid = 'a5c5dd35-a73b-4ec4-8fd2-990c453d2a21';
  $display->content['new-a5c5dd35-a73b-4ec4-8fd2-990c453d2a21'] = $pane;
  $display->panels['center'][0] = 'new-a5c5dd35-a73b-4ec4-8fd2-990c453d2a21';
  $pane = new stdClass();
  $pane->pid = 'new-b90c7c26-3cb3-4a7a-9bdd-5824c456638e';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'add-new-semester',
    'title' => 'Neues Semester',
    'title_heading' => 'h2',
    'body' => '<?php

/* lädt form, um neues semester anzulegen */
if ($semester_vocabulary = taxonomy_vocabulary_machine_name_load(\'semester\')) {
    module_load_include(\'inc\', \'taxonomy\', \'taxonomy.admin\');
    $form_edit_var = array();
    $taxonomy_create_form = drupal_get_form(\'taxonomy_form_term\', $form_edit_var, $semester_vocabulary);
 

    $create_fieldset = array();
    $create_fieldset[\'create_new\'] = array(
        \'#type\' => \'fieldset\',
        \'#title\' => t(\'Create semester\'),
        \'#collapsible\' => true,
        \'#collapsed\' => true,
        \'content\' => array(\'#type\' => \'markup\', \'#markup\' => drupal_render($taxonomy_create_form))
    );
    echo drupal_render($create_fieldset);
}
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
  $pane->uuid = 'b90c7c26-3cb3-4a7a-9bdd-5824c456638e';
  $display->content['new-b90c7c26-3cb3-4a7a-9bdd-5824c456638e'] = $pane;
  $display->panels['center'][1] = 'new-b90c7c26-3cb3-4a7a-9bdd-5824c456638e';
  $pane = new stdClass();
  $pane->pid = 'new-578bec4e-99cc-4ebe-be2d-47208ee2b4d3';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'form-semester-sort',
    'title' => 'Semester-Reihenfolge ändern',
    'title_heading' => 'h2',
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
    'parent' => 'menu-administration:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-administration',
    'parent_mlid' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
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
    'title' => 'Benutzer',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'benutzer',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'users',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'navigation' => NULL,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '840743b4-d905-482f-b49d-4c349ccf8ea6';
  $display->content['new-840743b4-d905-482f-b49d-4c349ccf8ea6'] = $pane;
  $display->panels['center'][0] = 'new-840743b4-d905-482f-b49d-4c349ccf8ea6';
  $pane = new stdClass();
  $pane->pid = 'new-a3b10c57-cd41-4203-b01b-1b53336c8dd5';
  $pane->panel = 'navigation';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-administration';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-administration:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-administration',
    'parent_mlid' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
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
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'administration-exposed-filter',
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
  $pages['administration'] = $page;

  return $pages;

}
