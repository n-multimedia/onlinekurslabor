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
  $display->uuid = '5b7b8396-726b-4f00-8c15-16d56daff70d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a6cac502-08d2-48b6-a3e2-6ad16c61d7eb';
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
    $pane->uuid = 'a6cac502-08d2-48b6-a3e2-6ad16c61d7eb';
    $display->content['new-a6cac502-08d2-48b6-a3e2-6ad16c61d7eb'] = $pane;
    $display->panels['col1'][0] = 'new-a6cac502-08d2-48b6-a3e2-6ad16c61d7eb';
    $pane = new stdClass();
    $pane->pid = 'new-aefbc85a-eeb0-4fa7-8e74-8bb600a6e318';
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
    $pane->uuid = 'aefbc85a-eeb0-4fa7-8e74-8bb600a6e318';
    $display->content['new-aefbc85a-eeb0-4fa7-8e74-8bb600a6e318'] = $pane;
    $display->panels['col2'][0] = 'new-aefbc85a-eeb0-4fa7-8e74-8bb600a6e318';
    $pane = new stdClass();
    $pane->pid = 'new-e4d5cbbb-f92f-4352-9a4a-c7277e2bc077';
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
    $pane->uuid = 'e4d5cbbb-f92f-4352-9a4a-c7277e2bc077';
    $display->content['new-e4d5cbbb-f92f-4352-9a4a-c7277e2bc077'] = $pane;
    $display->panels['col3'][0] = 'new-e4d5cbbb-f92f-4352-9a4a-c7277e2bc077';
    $pane = new stdClass();
    $pane->pid = 'new-80d5d10a-5ab9-48d3-a886-6cd17d252f55';
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
    $pane->uuid = '80d5d10a-5ab9-48d3-a886-6cd17d252f55';
    $display->content['new-80d5d10a-5ab9-48d3-a886-6cd17d252f55'] = $pane;
    $display->panels['left'][0] = 'new-80d5d10a-5ab9-48d3-a886-6cd17d252f55';
    $pane = new stdClass();
    $pane->pid = 'new-b6ed1914-5b2f-4651-9469-31406f3dd63d';
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
    $pane->uuid = 'b6ed1914-5b2f-4651-9469-31406f3dd63d';
    $display->content['new-b6ed1914-5b2f-4651-9469-31406f3dd63d'] = $pane;
    $display->panels['media'][0] = 'new-b6ed1914-5b2f-4651-9469-31406f3dd63d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-b6ed1914-5b2f-4651-9469-31406f3dd63d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_layout'] = $page;

  return $pages;

}
