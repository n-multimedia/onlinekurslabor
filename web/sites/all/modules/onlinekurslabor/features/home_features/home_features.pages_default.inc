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
  $handler->weight = -2;
  $handler->conf = array(
    'title' => 'loggedout_okl',
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
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'module schullabor active',
            'php' => 'return module_exists(\'schullabor\');',
          ),
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
          0 => 'okl-description',
          1 => 'okl-video',
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
      'okl-description' => array(
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
      'okl-video' => array(
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
      'okl-description' => NULL,
      'bilder' => NULL,
      'partner' => NULL,
      'bild_studierende' => NULL,
      'bild_lehrende' => NULL,
      'okl-video' => NULL,
      'okl-video_' => NULL,
      'okl-video__' => NULL,
      'okl-video___' => NULL,
      'partner_' => NULL,
      'bild_partner' => NULL,
      'studierende' => NULL,
      'okl-description_' => NULL,
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
  $pane->pid = 'new-70609a2f-52b9-4e16-b881-1c2c87d28eb8';
  $pane->panel = 'okl-description';
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
    'title' => 'loggedout_osl',
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
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'module schullabor active',
            'php' => 'return module_exists(\'schullabor\');',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'loggedout_osl',
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
          1 => 2,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'info',
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
      'partner' => array(
        'type' => 'region',
        'title' => 'Förderer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'home-container-partner',
      ),
      'info' => array(
        'type' => 'region',
        'title' => 'info',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
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
      'okl-description' => NULL,
      'bilder' => NULL,
      'partner' => NULL,
      'bild_studierende' => NULL,
      'bild_lehrende' => NULL,
      'okl-video' => NULL,
      'okl-video_' => NULL,
      'okl-video__' => NULL,
      'okl-video___' => NULL,
      'partner_' => NULL,
      'bild_partner' => NULL,
      'studierende' => NULL,
      'okl-description_' => NULL,
      'right' => NULL,
      'middle' => NULL,
      'lehrender' => NULL,
      'student' => NULL,
      'image_video' => NULL,
      'info' => NULL,
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
    'title' => 'admin-info',
    'title_heading' => 'h2',
    'body' => 'Das Modul SCHULLABOR muss aktiv sein, damit diese Seite angezeigt wird.',
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
    'title' => '',
    'title_heading' => 'h2',
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
      'okl-description' => NULL,
      'bilder' => NULL,
      'partner' => NULL,
      'bild_studierende' => NULL,
      'bild_lehrende' => NULL,
      'okl-video' => NULL,
      'okl-video_' => NULL,
      'okl-video__' => NULL,
      'okl-video___' => NULL,
      'partner_' => NULL,
      'bild_partner' => NULL,
      'studierende' => NULL,
      'okl-description_' => NULL,
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
