<?php
/**
 * @file
 * nm_general_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nm_general_features_default_page_manager_pages() {
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
        'class' => 'row-fluid column-region',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'test',
        ),
        'parent' => 'main',
        'class' => 'row-fluid',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'partner',
        ),
        'parent' => 'main',
        'class' => 'row-fluid',
      ),
      'test' => array(
        'type' => 'region',
        'title' => 'Titel_OKL',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'Titel_OKL',
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
        'class' => 'span4',
      ),
      'partner_' => array(
        'type' => 'region',
        'title' => 'Partner',
        'width' => '26.893250953042525',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'span4',
      ),
      'student' => array(
        'type' => 'region',
        'title' => 'Student',
        'width' => '26.83567332159516',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'span4',
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
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_lehrender.png" class="span12"  />\';
$vars[\'description\'] = "Informationen für Hochschullehrende";
$vars[\'link\'] = "registrieren?mode=lehrende";

return theme(\'nm_fancy_box\', $vars);

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
      'css_id' => '',
      'css_class' => 'span12',
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
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_partner.png" class="span12"  />\';
$vars[\'description\'] = "Informationen für Kooperationspartner";
$vars[\'link\'] = "registrieren?mode=partner";

return theme(\'nm_fancy_box\', $vars);

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
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/logo_student.png" class="span12"  />\';
$vars[\'description\'] = "Informationen für Studierende";
$vars[\'link\'] = "/registrieren?mode=studierende";

return theme(\'nm_fancy_box\', $vars);

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
      'body' => '<h3 style="text-align: center;"><a href="/onlinekurslabor">Onlinekurslabor</a></h3><h4 style="text-align: center;">Das Lernportal des Medienlabors</h4><p>&nbsp;</p><p>&nbsp;</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'span12',
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
  $pages['home_layout'] = $page;

  return $pages;

}
