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
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'start';
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
  $handler->name = 'page_home_layout_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home_layout';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'logged-in-user',
          'name' => 'role',
          'not' => TRUE,
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
        ),
        1 => array(
          'name' => 'php',
          'not' => TRUE,
          'settings' => array(
            'description' => 'module schullabor active',
            'php' => 'return module_exists(\'schullabor\');',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => 'home_loggedout',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'loggedout_okl',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
        ),
        'class' => 'home-layout-container',
        'column_class' => '',
        'column_separation' => '0.5em',
        'contains' => 'column',
        'fixed_width' => '',
        'no_scale' => FALSE,
        'parent' => NULL,
        'region_class' => '',
        'region_separation' => '0.5em',
        'row_class' => '',
        'row_separation' => '0.5em',
        'type' => 'row',
      ),
      'lehrender' => array(
        'class' => 'col-xs-12 col-md-4',
        'parent' => 'main-row',
        'title' => 'lehrender',
        'type' => 'region',
        'width' => '26.88529876382778',
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
        ),
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'main-row' => array(
        'children' => array(
          0 => 'student',
          1 => 'lehrender',
          2 => 'partner_',
        ),
        'class' => 'row column-region',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      'okl-description' => array(
        'class' => 'col-xs-12 col-md-6 col-lg-7',
        'parent' => '1',
        'title' => 'Titel_OKL',
        'type' => 'region',
        'width' => '64.94139740527254',
        'width_type' => '%',
      ),
      'okl-video' => array(
        'class' => 'col-xs-12 col-md-6 col-lg-5',
        'parent' => '1',
        'title' => 'Image-Video',
        'type' => 'region',
        'width' => 35.058602594728,
        'width_type' => '%',
      ),
      'partner' => array(
        'class' => 'home-container-partner',
        'parent' => '2',
        'title' => 'Förderer',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'partner_' => array(
        'class' => 'col-xs-12 col-md-4',
        'parent' => 'main-row',
        'title' => 'Partner',
        'type' => 'region',
        'width' => '26.893250953042525',
        'width_type' => '%',
      ),
      'student' => array(
        'class' => 'col-xs-12 col-md-4',
        'parent' => 'main-row',
        'title' => 'Student',
        'type' => 'region',
        'width' => '26.83567332159516',
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 'okl-description',
          1 => 'okl-video',
        ),
        'class' => 'row',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      2 => array(
        'children' => array(
          0 => 'partner',
        ),
        'class' => 'row',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $display->panel_settings = array(
    'bild_partner' => array(
      'style' => '-1',
    ),
    'media' => array(
      'style' => '-1',
    ),
    'studierende' => array(
      'style' => '-1',
    ),
    'style_settings' => array(
      'bild_lehrende' => NULL,
      'bild_partner' => NULL,
      'bild_studierende' => NULL,
      'bilder' => NULL,
      'center' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'col3' => NULL,
      'default' => NULL,
      'image_video' => NULL,
      'left' => NULL,
      'lehrender' => NULL,
      'media' => NULL,
      'middle' => NULL,
      'okl-description' => NULL,
      'okl-description_' => NULL,
      'okl-video' => NULL,
      'okl-video_' => NULL,
      'okl-video__' => NULL,
      'okl-video___' => NULL,
      'partner' => NULL,
      'partner_' => NULL,
      'right' => NULL,
      'student' => NULL,
      'studierende' => NULL,
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
    'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_lehrender.png" style="width:100%;"    />\';
$vars[\'description\'] = "Informationen für Hochschullehrende";
$vars[\'link\'] = "informationen?mode=lehrende";

return theme(\'nm_fancy_box\', $vars);

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => 'startpage-okl-description-dozent',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '875794f9-d9c8-416f-a60a-06600be3b6f9';
  $display->content['new-875794f9-d9c8-416f-a60a-06600be3b6f9'] = $pane;
  $display->panels['lehrender'][0] = 'new-875794f9-d9c8-416f-a60a-06600be3b6f9';
  $pane = new stdClass();
  $pane->pid = 'new-70609a2f-52b9-4e16-b881-1c2c87d28eb8';
  $pane->panel = 'okl-description';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Einführungstext',
    'body' => '<h2 style="color: #EB690B;">Onlinekurslabor</h2><p style="text-align: justify;">Das Onlinekurslabor ist eine digitale Lernplattform des Medienlabors für Studierende, Hochschullehrende und Partnerorganisationen. Zielgruppe des Angebots sind hauptsächlich Mitglieder der Universität Augsburg. </p><p style="text-align: justify;">Im Fokus liegen insbesondere erfahrungsorientiertes und forschendes Lernen in realen Projekten. Hier werden Ihnen virtuelle Werkzeuge zur Begleitung der Präsenzlehre, zur Erstellung von E-Learning-Kursen und zur Organisation von Projektseminaren bereitgestellt.</p><p>&nbsp;</p>',
    'format' => 'filtered_html',
    'substitute' => TRUE,
    'title' => '',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-md-12',
    'css_id' => 'startpage-okl-description',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '70609a2f-52b9-4e16-b881-1c2c87d28eb8';
  $display->content['new-70609a2f-52b9-4e16-b881-1c2c87d28eb8'] = $pane;
  $display->panels['okl-description'][0] = 'new-70609a2f-52b9-4e16-b881-1c2c87d28eb8';
  $pane = new stdClass();
  $pane->pid = 'new-fa88a807-8049-45e2-8aab-a4e36639ae7b';
  $pane->panel = 'okl-video';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Video',
    'body' => '<?php echo _custom_general_get_rendered_html5_video_tag("https://onlinekurslabor.phil.uni-augsburg.de/sites/default/files/imagefilm_onlinekurslabor.mp4", "/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/fakevideo2.png"); ?>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title' => '',
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => 'startpage-okl-video',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fa88a807-8049-45e2-8aab-a4e36639ae7b';
  $display->content['new-fa88a807-8049-45e2-8aab-a4e36639ae7b'] = $pane;
  $display->panels['okl-video'][0] = 'new-fa88a807-8049-45e2-8aab-a4e36639ae7b';
  $pane = new stdClass();
  $pane->pid = 'new-e5330c0c-4c13-4df3-a353-92107fee92b7';
  $pane->panel = 'partner';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<a href="http://www.bmas.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_BMAS.png" style="float:right" /></a>
<a href="https://www.bmbf.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_BMBF.png" style="float:right" /></a>
<a href="https://www.stiftung-mercator.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_mercator.png" style="float:right" /></a>
<a href="http://www.uni-augsburg.de/de/projekte/lehet/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_lehet.png" style="float:right" /></a>
<a href="http://www.uni-augsburg.de/projekte/bildung-durch-verantwortung" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_bdv.png" style="float:right" /></a>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-md-12',
    'css_id' => 'startpage-okl-description-foerderer',
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
    'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_partner.png" style="width:100%;"   />\';
$vars[\'description\'] = "Informationen für Partnerorganisationen";
$vars[\'link\'] = "informationen?mode=partner";

return theme(\'nm_fancy_box\', $vars);

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
  $pane->css = array(
    'css_class' => '',
    'css_id' => 'startpage-okl-description-partner',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c38e1c99-7f8e-406c-8368-1804779f25bf';
  $display->content['new-c38e1c99-7f8e-406c-8368-1804779f25bf'] = $pane;
  $display->panels['partner_'][0] = 'new-c38e1c99-7f8e-406c-8368-1804779f25bf';
  $pane = new stdClass();
  $pane->pid = 'new-b656ed25-75c4-4397-97e4-243d47158514';
  $pane->panel = 'student';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_student.png" style="width:100%;"    />\';
$vars[\'description\'] = "Informationen für Studierende";
$vars[\'link\'] = "/informationen?mode=studierende";

return theme(\'nm_fancy_box\', $vars);

?>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => '',
    'css_id' => 'startpage-okl-description-student',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b656ed25-75c4-4397-97e4-243d47158514';
  $display->content['new-b656ed25-75c4-4397-97e4-243d47158514'] = $pane;
  $display->panels['student'][0] = 'new-b656ed25-75c4-4397-97e4-243d47158514';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_layout__loggedout_osl';
  $handler->task = 'page';
  $handler->subtask = 'home_layout';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'logged-in-user',
          'name' => 'role',
          'not' => TRUE,
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
        ),
        1 => array(
          'name' => 'php',
          'not' => FALSE,
          'settings' => array(
            'description' => 'module schullabor active',
            'php' => 'return module_exists(\'schullabor\');',
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => 'home_loggedout',
    'name' => 'loggedout_osl',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(),
    'title' => 'loggedout_osl',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
        ),
        'class' => 'home-layout-container',
        'column_class' => '',
        'column_separation' => '0.5em',
        'contains' => 'column',
        'fixed_width' => '',
        'no_scale' => FALSE,
        'parent' => NULL,
        'region_class' => '',
        'region_separation' => '0.5em',
        'row_class' => '',
        'row_separation' => '0.5em',
        'type' => 'row',
      ),
      'info' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '1',
        'title' => 'info',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'main' => array(
        'children' => array(
          0 => 1,
          1 => 2,
        ),
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
      ),
      'partner' => array(
        'class' => 'home-container-partner',
        'parent' => '2',
        'title' => 'Förderer',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      1 => array(
        'children' => array(
          0 => 'info',
        ),
        'class' => 'row',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
      2 => array(
        'children' => array(
          0 => 'partner',
        ),
        'class' => 'row',
        'contains' => 'region',
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $display->panel_settings = array(
    'bild_partner' => array(
      'style' => '-1',
    ),
    'media' => array(
      'style' => '-1',
    ),
    'studierende' => array(
      'style' => '-1',
    ),
    'style_settings' => array(
      'bild_lehrende' => NULL,
      'bild_partner' => NULL,
      'bild_studierende' => NULL,
      'bilder' => NULL,
      'center' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'col3' => NULL,
      'default' => NULL,
      'image_video' => NULL,
      'info' => NULL,
      'left' => NULL,
      'lehrender' => NULL,
      'media' => NULL,
      'middle' => NULL,
      'okl-description' => NULL,
      'okl-description_' => NULL,
      'okl-video' => NULL,
      'okl-video_' => NULL,
      'okl-video__' => NULL,
      'okl-video___' => NULL,
      'partner' => NULL,
      'partner_' => NULL,
      'right' => NULL,
      'student' => NULL,
      'studierende' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5b7b8396-726b-4f00-8c15-16d56daff70d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_layout__loggedout_osl';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ba76461d-1024-4693-8d57-a1064b9b259f';
  $pane->panel = 'info';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'admin-info',
    'body' => 'Das Modul SCHULLABOR muss aktiv sein, damit diese Seite angezeigt wird.',
    'format' => 'plain_text',
    'substitute' => TRUE,
    'title' => 'admin-info',
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
  $pane->uuid = 'ba76461d-1024-4693-8d57-a1064b9b259f';
  $display->content['new-ba76461d-1024-4693-8d57-a1064b9b259f'] = $pane;
  $display->panels['info'][0] = 'new-ba76461d-1024-4693-8d57-a1064b9b259f';
  $pane = new stdClass();
  $pane->pid = 'new-4482c5a9-ebce-4010-886a-6c27f03f568a';
  $pane->panel = 'info';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'osl-box-description',
    'body' => '<div class="front-wrapper-osl" >
<div class="container" >
<div class="text-container">
Das Onlineschullabor ist die digitale Lernplattform des Medienlabors der Universität Augsburg. Sie richtet sich an Lehrende und Lernende der Schule. 
<br><br> Im Fokus liegen erfahrungsorientiertes und spielerisches Lernen. Virtuelle Elemente begleiten den Unterricht und unterstützen den schulischen Lernprozess. 
</div>
</div>
</div>',
    'format' => 'full_html',
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
  $pane->uuid = '4482c5a9-ebce-4010-886a-6c27f03f568a';
  $display->content['new-4482c5a9-ebce-4010-886a-6c27f03f568a'] = $pane;
  $display->panels['info'][1] = 'new-4482c5a9-ebce-4010-886a-6c27f03f568a';
  $pane = new stdClass();
  $pane->pid = 'new-e5330c0c-4c13-4df3-a353-92107fee92b7';
  $pane->panel = 'partner';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'body' => '<a href="http://www.bmas.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_BMAS.png" style="float:right" /></a>
<a href="https://www.bmbf.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_BMBF.png" style="float:right" /></a>
<a href="https://www.stiftung-mercator.de/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_mercator.png" style="float:right" /></a>
<a href="http://www.uni-augsburg.de/de/projekte/lehet/" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_lehet.png" style="float:right" /></a>
<a href="http://www.uni-augsburg.de/projekte/bildung-durch-verantwortung" target="_blank" ><img src="/sites/all/themes/bootstrap_onlinekurslabor/images/logos/logo_bdv.png" style="float:right" /></a>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'col-md-12',
    'css_id' => 'startpage-okl-description-foerderer',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e5330c0c-4c13-4df3-a353-92107fee92b7';
  $display->content['new-e5330c0c-4c13-4df3-a353-92107fee92b7'] = $pane;
  $display->panels['partner'][0] = 'new-e5330c0c-4c13-4df3-a353-92107fee92b7';
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
  $handler->weight = 0;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'logged-in-user',
          'name' => 'role',
          'not' => FALSE,
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(
      0 => array(
        'id' => 1,
        'identifier' => 'Benutzer',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
      ),
    ),
    'css' => '',
    'css_id' => 'home_loggedin',
    'name' => 'loggedin',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'context_user_1',
        'id' => 1,
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'master',
      ),
    ),
    'title' => 'loggedin',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'children' => array(
          0 => 'main',
        ),
        'class' => 'row',
        'column_class' => '',
        'column_separation' => '0.5em',
        'contains' => 'column',
        'fixed_width' => '',
        'no_scale' => FALSE,
        'parent' => NULL,
        'region_class' => '',
        'region_separation' => '0.5em',
        'row_class' => '',
        'row_separation' => '0.5em',
        'type' => 'row',
      ),
      'main' => array(
        'children' => array(
          0 => 10,
          1 => 15,
          2 => 16,
        ),
        'class' => '',
        'hide_empty' => 0,
        'parent' => 'canvas',
        'type' => 'column',
        'width' => 100.00000000000061,
        'width_type' => '%',
      ),
      'main_' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '14',
        'title' => 'main',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'picture_' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '13',
        'title' => 'space-left md2',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      'tabs_' => array(
        'class' => '',
        'hide_empty' => 0,
        'parent' => '15',
        'title' => 'tabbed output',
        'type' => 'region',
        'width' => 100,
        'width_type' => '%',
      ),
      10 => array(
        'children' => array(
          0 => 11,
          1 => 12,
        ),
        'class' => 'top',
        'contains' => 'column',
        'hide_empty' => 0,
        'parent' => 'main',
        'type' => 'row',
      ),
      11 => array(
        'children' => array(
          0 => 13,
        ),
        'class' => 'col-md-2',
        'hide_empty' => 0,
        'parent' => '10',
        'type' => 'column',
        'width' => '17.92246792246792',
        'width_type' => '%',
      ),
      12 => array(
        'children' => array(
          0 => 14,
        ),
        'class' => 'col-md-10',
        'hide_empty' => 0,
        'parent' => '10',
        'type' => 'column',
        'width' => '82.07753207753208',
        'width_type' => '%',
      ),
      13 => array(
        'children' => array(
          0 => 'picture_',
        ),
        'class' => '',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => '11',
        'type' => 'row',
      ),
      14 => array(
        'children' => array(
          0 => 'main_',
        ),
        'class' => '',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => '12',
        'type' => 'row',
      ),
      15 => array(
        'children' => array(
          0 => 'tabs_',
        ),
        'class' => 'row',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => 'main',
        'type' => 'row',
      ),
      16 => array(
        'children' => array(),
        'class' => 'row',
        'contains' => 'region',
        'hide_empty' => 0,
        'parent' => 'main',
        'type' => 'row',
      ),
    ),
  );
  $display->panel_settings = array(
    'bild_partner' => array(
      'style' => '-1',
    ),
    'media' => array(
      'style' => '-1',
    ),
    'studierende' => array(
      'style' => '-1',
    ),
    'style_settings' => array(
      'bild_lehrende' => NULL,
      'bild_partner' => NULL,
      'bild_studierende' => NULL,
      'bilder' => NULL,
      'center' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'col3' => NULL,
      'default' => NULL,
      'image_video' => NULL,
      'left' => NULL,
      'lehrender' => NULL,
      'main_' => NULL,
      'media' => NULL,
      'middle' => NULL,
      'okl-description' => NULL,
      'okl-description_' => NULL,
      'okl-video' => NULL,
      'okl-video_' => NULL,
      'okl-video__' => NULL,
      'okl-video___' => NULL,
      'partner' => NULL,
      'partner_' => NULL,
      'picture_' => NULL,
      'right' => NULL,
      'student' => NULL,
      'studierende' => NULL,
      'tabs_' => array(
        'region_bootstraptabs' => array(
          'alignment' => 'left',
        ),
      ),
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
    'body' => '<div class="col-md-4 col-md-push-8 col-xs-12"><?php echo _section_home_getRenderedActivity(); ?></div>
<div class="col-md-8  col-md-pull-4 col-xs-12 pane-nm-stream"><?php echo _section_home_getRenderedStream(); ?></div>',
    'format' => 'php_code',
    'substitute' => 1,
    'title' => 'Aktivität',
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
    'body' => '<div class="col-md-4 col-md-push-8 col-xs-12"> <?php echo _section_home_getRenderedDomains() ?></div>
<div class="col-md-8 col-md-pull-4 col-xs-12" ><?php echo _section_home_getRenderedCourses() ?> </div>',
    'format' => 'php_code',
    'substitute' => 1,
    'title' => 'Meine Veranstaltungen',
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
    'override_title_heading' => 'h2',
    'override_title_text' => 'Neue Nachrichten',
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
