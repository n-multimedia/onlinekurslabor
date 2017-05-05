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
  $pane->pid = 'new-875794f9-d9c8-416f-a60a-06600be3b6f9';
  $pane->panel = 'lehrender';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_lehrender.png" style="width:100%;"    />\';
$vars[\'description\'] = "Informationen für Hochschullehrende";
$vars[\'link\'] = "informationen?mode=lehrende";

return theme(\'nm_fancy_box\', $vars);

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'startpage-okl-description-dozent',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '875794f9-d9c8-416f-a60a-06600be3b6f9';
  $display->content['new-875794f9-d9c8-416f-a60a-06600be3b6f9'] = $pane;
  $display->panels['lehrender'][0] = 'new-875794f9-d9c8-416f-a60a-06600be3b6f9';
  $pane = new stdClass();
  $pane->pid = 'new-e5330c0c-4c13-4df3-a353-92107fee92b7';
  $pane->panel = 'partner';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<a href="http://www.bmas.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_BMAS.png" style="float:right" /></a>
<a href="https://www.bmbf.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_BMBF.png" style="float:right" /></a>
<a href="https://www.stiftung-mercator.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_mercator.png" style="float:right" /></a>
<a href="http://www.uni-augsburg.de/de/projekte/lehet/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_lehet.png" style="float:right" /></a>
<a href="http://www.uni-augsburg.de/projekte/bildung-durch-verantwortung" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_bdv.png" style="float:right" /></a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'startpage-okl-description-foerderer',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e5330c0c-4c13-4df3-a353-92107fee92b7';
  $display->content['new-e5330c0c-4c13-4df3-a353-92107fee92b7'] = $pane;
  $display->panels['partner'][0] = 'new-e5330c0c-4c13-4df3-a353-92107fee92b7';
  $pane = new stdClass();
  $pane->pid = 'new-c38e1c99-7f8e-406c-8368-1804779f25bf';
  $pane->panel = 'partner_';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_partner.png" style="width:100%;"   />\';
$vars[\'description\'] = "Informationen für Kooperationspartner";
$vars[\'link\'] = "informationen?mode=partner";

return theme(\'nm_fancy_box\', $vars);

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'startpage-okl-description-partner',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c38e1c99-7f8e-406c-8368-1804779f25bf';
  $display->content['new-c38e1c99-7f8e-406c-8368-1804779f25bf'] = $pane;
  $display->panels['partner_'][0] = 'new-c38e1c99-7f8e-406c-8368-1804779f25bf';
  $pane = new stdClass();
  $pane->pid = 'new-fa88a807-8049-45e2-8aab-a4e36639ae7b';
  $pane->panel = 'platzhalter';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Video',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php echo _custom_general_get_rendered_html5_video_tag("https://onlinekurslabor.phil.uni-augsburg.de/sites/default/files/imagefilm_onlinekurslabor.mp4", "/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/fakevideo2.png"); ?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'startpage-okl-video',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fa88a807-8049-45e2-8aab-a4e36639ae7b';
  $display->content['new-fa88a807-8049-45e2-8aab-a4e36639ae7b'] = $pane;
  $display->panels['platzhalter'][0] = 'new-fa88a807-8049-45e2-8aab-a4e36639ae7b';
  $pane = new stdClass();
  $pane->pid = 'new-b656ed25-75c4-4397-97e4-243d47158514';
  $pane->panel = 'student';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_student.png" style="width:100%;"    />\';
$vars[\'description\'] = "Informationen für Studierende";
$vars[\'link\'] = "/informationen?mode=studierende";

return theme(\'nm_fancy_box\', $vars);

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'startpage-okl-description-student',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b656ed25-75c4-4397-97e4-243d47158514';
  $display->content['new-b656ed25-75c4-4397-97e4-243d47158514'] = $pane;
  $display->panels['student'][0] = 'new-b656ed25-75c4-4397-97e4-243d47158514';
  $pane = new stdClass();
  $pane->pid = 'new-70609a2f-52b9-4e16-b881-1c2c87d28eb8';
  $pane->panel = 'test';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h2 style="color: #EB690B;">Onlinekurslabor</h2><p style="text-align: justify;">Das Onlinekurslabor ist eine digitale Lernplattform des Medienlabors für Studierende, Hochschullehrende und Partnerorganisationen.</p><p style="text-align: justify;">Im Fokus liegen insbesondere erfahrungsorientiertes und forschendes Lernen in realen Projekten. Hier werden Ihnen virtuelle Werkzeuge zur Begleitung der Präsenzlehre, zur Erstellung von E-Learning-Kursen und zur Organisation von Projektseminaren bereitgestellt.</p><p>&nbsp;</p>',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'startpage-okl-description',
    'css_class' => 'col-md-12',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '70609a2f-52b9-4e16-b881-1c2c87d28eb8';
  $display->content['new-70609a2f-52b9-4e16-b881-1c2c87d28eb8'] = $pane;
  $display->panels['test'][0] = 'new-70609a2f-52b9-4e16-b881-1c2c87d28eb8';
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
  $display->layout = 'flexible:profile_layout';
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
  $display->storage_id = 'page_home_layout__loggedin';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-43b97f8d-1724-43f1-9bcb-fe2380b51839';
  $pane->panel = 'center';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '43b97f8d-1724-43f1-9bcb-fe2380b51839';
  $display->content['new-43b97f8d-1724-43f1-9bcb-fe2380b51839'] = $pane;
  $display->panels['center'][0] = 'new-43b97f8d-1724-43f1-9bcb-fe2380b51839';
  $pane = new stdClass();
  $pane->pid = 'new-562ce51b-3ef1-4e7d-937f-46eb3e2314d2';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Erklärung',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>siehe section_start_field_formatter_view... Profilbild hat einen eigenen Formatter.</p>',
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
  $pane->uuid = '562ce51b-3ef1-4e7d-937f-46eb3e2314d2';
  $display->content['new-562ce51b-3ef1-4e7d-937f-46eb3e2314d2'] = $pane;
  $display->panels['left'][0] = 'new-562ce51b-3ef1-4e7d-937f-46eb3e2314d2';
  $pane = new stdClass();
  $pane->pid = 'new-fda5c3e9-ad75-404b-9825-16e81a718c7d';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_photo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'start_profile_picture',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = 'fda5c3e9-ad75-404b-9825-16e81a718c7d';
  $display->content['new-fda5c3e9-ad75-404b-9825-16e81a718c7d'] = $pane;
  $display->panels['left'][1] = 'new-fda5c3e9-ad75-404b-9825-16e81a718c7d';
  $pane = new stdClass();
  $pane->pid = 'new-802d6fa8-5335-49da-a3e0-dc33831cecf4';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_photo';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'homescreen_profile_background',
      'image_link' => '',
    ),
    'context' => 'relationship_profile2_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'home_profile_background',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '802d6fa8-5335-49da-a3e0-dc33831cecf4';
  $display->content['new-802d6fa8-5335-49da-a3e0-dc33831cecf4'] = $pane;
  $display->panels['left'][2] = 'new-802d6fa8-5335-49da-a3e0-dc33831cecf4';
  $pane = new stdClass();
  $pane->pid = 'new-c2e5bcbc-8ac5-46e6-8c2c-a864eb6701db';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_photo';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'homescreen_profile',
      'image_link' => '',
    ),
    'context' => 'relationship_profile2_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'home_profile_picture',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c2e5bcbc-8ac5-46e6-8c2c-a864eb6701db';
  $display->content['new-c2e5bcbc-8ac5-46e6-8c2c-a864eb6701db'] = $pane;
  $display->panels['left'][3] = 'new-c2e5bcbc-8ac5-46e6-8c2c-a864eb6701db';
  $pane = new stdClass();
  $pane->pid = 'new-d58d9eb9-9b01-4d7e-a3cf-26a849d7052d';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'hovers fuers profilbild',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
echo _section_start_getRenderedProfilePhotoHovers();
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'd58d9eb9-9b01-4d7e-a3cf-26a849d7052d';
  $display->content['new-d58d9eb9-9b01-4d7e-a3cf-26a849d7052d'] = $pane;
  $display->panels['left'][4] = 'new-d58d9eb9-9b01-4d7e-a3cf-26a849d7052d';
  $pane = new stdClass();
  $pane->pid = 'new-810d7edf-0a67-46af-879f-7b8251c0b917';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'courses_user_courses';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '7',
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
    'override_title_text' => 'Kurse',
    'override_title_heading' => 'h3',
    'context' => array(
      0 => 'context_user_1.uid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '810d7edf-0a67-46af-879f-7b8251c0b917';
  $display->content['new-810d7edf-0a67-46af-879f-7b8251c0b917'] = $pane;
  $display->panels['left'][5] = 'new-810d7edf-0a67-46af-879f-7b8251c0b917';
  $pane = new stdClass();
  $pane->pid = 'new-d16e11ba-02cb-4679-9548-f5c87ab41d4f';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'courses_user_domains';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '7',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => 'Lehrtexte',
    'override_title_heading' => 'h2',
    'context' => array(
      0 => 'context_user_1.uid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd16e11ba-02cb-4679-9548-f5c87ab41d4f';
  $display->content['new-d16e11ba-02cb-4679-9548-f5c87ab41d4f'] = $pane;
  $display->panels['left'][6] = 'new-d16e11ba-02cb-4679-9548-f5c87ab41d4f';
  $pane = new stdClass();
  $pane->pid = 'new-06e56185-0ec3-4ce9-b515-723a4186a397';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'nm_stream-panel_pane_1';
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
  $pane->uuid = '06e56185-0ec3-4ce9-b515-723a4186a397';
  $display->content['new-06e56185-0ec3-4ce9-b515-723a4186a397'] = $pane;
  $display->panels['right'][0] = 'new-06e56185-0ec3-4ce9-b515-723a4186a397';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_layout'] = $page;

  return $pages;

}
