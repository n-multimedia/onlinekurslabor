<?php
/**
 * @file
 * home_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function home_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home_layout';
  $page->task = 'page';
  $page->admin_title = 'Home Layout';
  $page->admin_description = '';
  $page->path = 'onlinekurslabor';
  $page->access = array(
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
  $handler->name = 'page_home_layout_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home_layout';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'loggedout',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'home_loggedout',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'home-layout-container',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'student',
          1 => 'lehrender',
          2 => 'partner_',
        ),
        'parent' => 'main',
        'class' => 'row column-region',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'test',
          1 => 'platzhalter',
        ),
        'parent' => 'main',
        'class' => 'row',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'partner',
        ),
        'parent' => 'main',
        'class' => 'row',
      ),
      'test' => array(
        'type' => 'region',
        'title' => 'Titel_OKL',
        'width' => '64.94139740527254',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-xs-12 col-md-6 col-lg-7',
      ),
      'partner' => array(
        'type' => 'region',
        'title' => 'Förderer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'home-container-partner',
      ),
      'lehrender' => array(
        'type' => 'region',
        'title' => 'lehrender',
        'width' => '26.88529876382778',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-md-4',
      ),
      'partner_' => array(
        'type' => 'region',
        'title' => 'Partner',
        'width' => '26.893250953042525',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-md-4',
      ),
      'student' => array(
        'type' => 'region',
        'title' => 'Student',
        'width' => '26.83567332159516',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-xs-12 col-md-4',
      ),
      'platzhalter' => array(
        'type' => 'region',
        'title' => 'Image-Video',
        'width' => 35.058602594728001,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-xs-12 col-md-6 col-lg-5',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'media' => NULL,
      'left' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'col3' => NULL,
      'center' => NULL,
      'test' => NULL,
      'bilder' => NULL,
      'partner' => NULL,
      'bild_studierende' => NULL,
      'bild_lehrende' => NULL,
      'platzhalter' => NULL,
      'platzhalter_' => NULL,
      'platzhalter__' => NULL,
      'platzhalter___' => NULL,
      'partner_' => NULL,
      'bild_partner' => NULL,
      'studierende' => NULL,
      'test_' => NULL,
      'right' => NULL,
      'middle' => NULL,
      'lehrender' => NULL,
      'student' => NULL,
      'image_video' => NULL,
    ),
    'media' => array(
      'style' => '-1',
    ),
    'bild_partner' => array(
      'style' => '-1',
    ),
    'studierende' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5b7b8396-726b-4f00-8c15-16d56daff70d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_layout_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-74653578-95b4-4d0e-99ce-277ae39c529f';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Admin-Hinweis',
    'title' => '',
    'title_heading' => 'h2',
    'body' => 'Das mini-panel home_loggedout-minipanel ist nicht Teil des Releases sondern muss bei Bedarf händisch erstellt / per export-import in die Umgebung gebracht werden',
    'format' => 'plain_text',
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
  $pane->uuid = '74653578-95b4-4d0e-99ce-277ae39c529f';
  $display->content['new-74653578-95b4-4d0e-99ce-277ae39c529f'] = $pane;
  $display->panels['middle'][0] = 'new-74653578-95b4-4d0e-99ce-277ae39c529f';
  $pane = new stdClass();
  $pane->pid = 'new-f17bcabf-5aad-4eb3-b142-be64ccb108c0';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'home_loggedout_minipanel';
  $pane->shown = TRUE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f17bcabf-5aad-4eb3-b142-be64ccb108c0';
  $display->content['new-f17bcabf-5aad-4eb3-b142-be64ccb108c0'] = $pane;
  $display->panels['middle'][1] = 'new-f17bcabf-5aad-4eb3-b142-be64ccb108c0';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_layout__loggedin';
  $handler->task = 'page';
  $handler->subtask = 'home_layout';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'loggedin',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'home_loggedin',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Benutzer',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'master',
        'context' => 'context_user_1',
        'id' => 1,
      ),
    ),
    'name' => 'loggedin',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'row',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100.00000000000061,
        'width_type' => '%',
        'children' => array(
          0 => 10,
          1 => 15,
          2 => 16,
        ),
        'parent' => 'canvas',
        'class' => '',
        'hide_empty' => 0,
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 11,
          1 => 12,
        ),
        'parent' => 'main',
        'class' => 'top',
        'hide_empty' => 0,
      ),
      11 => array(
        'type' => 'column',
        'width' => '17.92246792246792',
        'width_type' => '%',
        'parent' => '10',
        'children' => array(
          0 => 13,
        ),
        'class' => 'col-md-2',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'column',
        'width' => '82.07753207753208',
        'width_type' => '%',
        'parent' => '10',
        'children' => array(
          0 => 14,
        ),
        'class' => 'col-md-10',
        'hide_empty' => 0,
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'picture_',
        ),
        'parent' => '11',
        'class' => '',
        'hide_empty' => 0,
      ),
      'picture_' => array(
        'type' => 'region',
        'title' => 'space-left md2',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
        'hide_empty' => 0,
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'main_',
        ),
        'parent' => '12',
        'class' => '',
        'hide_empty' => 0,
      ),
      'main_' => array(
        'type' => 'region',
        'title' => 'main',
        'width' => 100,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
        'hide_empty' => 0,
      ),
      15 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tabs_',
        ),
        'parent' => 'main',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      'tabs_' => array(
        'type' => 'region',
        'title' => 'tabbed output',
        'width' => 100,
        'width_type' => '%',
        'parent' => '15',
        'class' => '',
        'hide_empty' => 0,
      ),
      16 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => 'main',
        'class' => 'row',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'media' => NULL,
      'left' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'col3' => NULL,
      'center' => NULL,
      'test' => NULL,
      'bilder' => NULL,
      'partner' => NULL,
      'bild_studierende' => NULL,
      'bild_lehrende' => NULL,
      'platzhalter' => NULL,
      'platzhalter_' => NULL,
      'platzhalter__' => NULL,
      'platzhalter___' => NULL,
      'partner_' => NULL,
      'bild_partner' => NULL,
      'studierende' => NULL,
      'test_' => NULL,
      'right' => NULL,
      'middle' => NULL,
      'lehrender' => NULL,
      'student' => NULL,
      'image_video' => NULL,
      'picture_' => NULL,
      'main_' => NULL,
      'tabs_' => array(
        'region_bootstraptabs' => array(
          'alignment' => 'left',
        ),
      ),
    ),
    'media' => array(
      'style' => '-1',
    ),
    'bild_partner' => array(
      'style' => '-1',
    ),
    'studierende' => array(
      'style' => '-1',
    ),
    'tabs_' => array(
      'style' => 'bootstrap-tabs',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5b7b8396-726b-4f00-8c15-16d56daff70d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_layout__loggedin';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-86a1604f-cc2c-4133-8f81-397a7236e5a9';
  $pane->panel = 'tabs_';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Aktivität',
    'title' => 'Aktivität',
    'title_heading' => 'h2',
    'body' => '<div class="col-md-4 col-md-push-8 col-xs-12"><?php echo _section_home_getRenderedActivity(); ?></div>
<div class="col-md-8  col-md-pull-4 col-xs-12 pane-nm-stream"><?php echo _section_home_getRenderedStream(); ?></div>',
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
  $pane->uuid = '86a1604f-cc2c-4133-8f81-397a7236e5a9';
  $display->content['new-86a1604f-cc2c-4133-8f81-397a7236e5a9'] = $pane;
  $display->panels['tabs_'][0] = 'new-86a1604f-cc2c-4133-8f81-397a7236e5a9';
  $pane = new stdClass();
  $pane->pid = 'new-e4193e12-6c11-4745-9026-b47e6a69ae4d';
  $pane->panel = 'tabs_';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Events',
    'title' => 'Meine Veranstaltungen',
    'title_heading' => 'h2',
    'body' => '<div class="col-md-4 col-md-push-8 col-xs-12"> <?php echo _section_home_getRenderedDomains() ?></div>
<div class="col-md-8 col-md-pull-4 col-xs-12" ><?php echo _section_home_getRenderedCourses() ?> </div>',
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
  $pane->uuid = 'e4193e12-6c11-4745-9026-b47e6a69ae4d';
  $display->content['new-e4193e12-6c11-4745-9026-b47e6a69ae4d'] = $pane;
  $display->panels['tabs_'][1] = 'new-e4193e12-6c11-4745-9026-b47e6a69ae4d';
  $pane = new stdClass();
  $pane->pid = 'new-9f27a1bd-5814-43c3-8e77-cd22d96800d3';
  $pane->panel = 'tabs_';
  $pane->type = 'views_panes';
  $pane->subtype = 'messages_list-messages_unread';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Neue Nachrichten',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9f27a1bd-5814-43c3-8e77-cd22d96800d3';
  $display->content['new-9f27a1bd-5814-43c3-8e77-cd22d96800d3'] = $pane;
  $display->panels['tabs_'][2] = 'new-9f27a1bd-5814-43c3-8e77-cd22d96800d3';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_layout'] = $page;

  return $pages;

}
