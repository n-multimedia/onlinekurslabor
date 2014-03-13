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
  $page->access = array();
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
  $display->layout = 'flexible:home_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'media' => NULL,
      'left' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'col3' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '86898dd0-d910-46af-af43-626ec11c663e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-efb26dd4-c360-495f-9453-b4412ac052f0';
    $pane->panel = 'col1';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/1_lehrende_oT.png" class="span12"  />\';
$vars[\'description\'] = "für Hochschullehrende";
$vars[\'middle\'] = "Nutzen Sie unseren KursCreator<sup>&trade;</sup>, um Kurse mit innovativer Didaktik anzubieten, die Studierenden wertvolle Erfahrungen in Projekten ermöglichen!";
$vars[\'bottom\'] = \'<a href="/courses">Eigenen Kurs gestalten</a>\';

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
    $pane->uuid = 'efb26dd4-c360-495f-9453-b4412ac052f0';
    $display->content['new-efb26dd4-c360-495f-9453-b4412ac052f0'] = $pane;
    $display->panels['col1'][0] = 'new-efb26dd4-c360-495f-9453-b4412ac052f0';
    $pane = new stdClass();
    $pane->pid = 'new-81e9d1b5-8391-49ef-a010-f52a73e31a45';
    $pane->panel = 'col2';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/2_studierende_oT.png"  class="span12" />\';
$vars[\'description\'] = \'für Studierende\';
$vars[\'middle\'] = \'Belegen Sie Kurse, in denen Sie konkrete Projekte machen, die Ihren Kompetenzerwerb mit gesellschaftlichem Engagement verbinden!\';
$vars[\'bottom\'] = \'<a href="/courses">Kürsübersicht anzeigen</a>\';

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
    $pane->uuid = '81e9d1b5-8391-49ef-a010-f52a73e31a45';
    $display->content['new-81e9d1b5-8391-49ef-a010-f52a73e31a45'] = $pane;
    $display->panels['col2'][0] = 'new-81e9d1b5-8391-49ef-a010-f52a73e31a45';
    $pane = new stdClass();
    $pane->pid = 'new-5a2dab09-b2ad-4e9a-9145-c75d310fe634';
    $pane->panel = 'col3';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
$vars = array();
$vars[\'image\'] = \'<img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/3_partner_oT.png" class="span12" />\';
$vars[\'description\'] = "für Partner vor Ort";
$vars[\'middle\'] = "Gewinnen Sie Studierende für Ihre gemeinwohlorientierten Projekte, um von deren Ideen und fachlichem Know-How zu profitieren!";
$vars[\'bottom\'] = \'<a href="#">Projektvorschlag einreichen</a>\';

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
    $pane->uuid = '5a2dab09-b2ad-4e9a-9145-c75d310fe634';
    $display->content['new-5a2dab09-b2ad-4e9a-9145-c75d310fe634'] = $pane;
    $display->panels['col3'][0] = 'new-5a2dab09-b2ad-4e9a-9145-c75d310fe634';
    $pane = new stdClass();
    $pane->pid = 'new-4a185140-2c09-4025-b136-9b0b4423aa92';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h3>Werden Sie Teil des</h3><h2><a href="/">Online-Kurslabors!</a></h2><p>Das Online-Kurslabor ist ein Ort zur Förderung von Engagement in Studium und Lehre. Zeitgemäße Hochschullehre nutzt digitale Medien und ermöglicht den Studierenden erfahrungsorientiertes Lernen in echten Projekten.</p><p>Wir bieten Ihnen ein einfach zu bedienendes Werkzeug zur Erstellung und Nutzung von Online-Kursen, das für <a class="nm_home_sh" href="#"> verschiedene Zielgruppen </a> optimiert ist.</p><p>&nbsp;</p><div class="nm_fancy_box_bottom"><a href="/user/register">Jetzt kostenlos anmelden</a></div>',
      'format' => 'filtered_html',
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
    $pane->uuid = '4a185140-2c09-4025-b136-9b0b4423aa92';
    $display->content['new-4a185140-2c09-4025-b136-9b0b4423aa92'] = $pane;
    $display->panels['left'][0] = 'new-4a185140-2c09-4025-b136-9b0b4423aa92';
    $pane = new stdClass();
    $pane->pid = 'new-b1e9df3b-3c80-4fd9-b6b3-5e563987e872';
    $pane->panel = 'media';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><img alt="" src="/sites/all/themes/bootstrap_onlinekurslabor/images/homepage/fakevideo.png"  class="span12"/></p>',
      'format' => 'filtered_html',
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
    $pane->uuid = 'b1e9df3b-3c80-4fd9-b6b3-5e563987e872';
    $display->content['new-b1e9df3b-3c80-4fd9-b6b3-5e563987e872'] = $pane;
    $display->panels['media'][0] = 'new-b1e9df3b-3c80-4fd9-b6b3-5e563987e872';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-b1e9df3b-3c80-4fd9-b6b3-5e563987e872';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_layout'] = $page;

  return $pages;

}
