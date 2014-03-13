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
  $display->uuid = 'fdb480d6-6597-41aa-b0bf-351834fa11f0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0910b340-d2e6-4f3e-9e4c-2dab69e9d08d';
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
    $pane->uuid = '0910b340-d2e6-4f3e-9e4c-2dab69e9d08d';
    $display->content['new-0910b340-d2e6-4f3e-9e4c-2dab69e9d08d'] = $pane;
    $display->panels['col1'][0] = 'new-0910b340-d2e6-4f3e-9e4c-2dab69e9d08d';
    $pane = new stdClass();
    $pane->pid = 'new-2d90b419-4f56-4127-ad68-005c8bdf575e';
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
    $pane->uuid = '2d90b419-4f56-4127-ad68-005c8bdf575e';
    $display->content['new-2d90b419-4f56-4127-ad68-005c8bdf575e'] = $pane;
    $display->panels['col2'][0] = 'new-2d90b419-4f56-4127-ad68-005c8bdf575e';
    $pane = new stdClass();
    $pane->pid = 'new-6c07cb62-5713-41ba-9f1e-55dd7052e8fa';
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
    $pane->uuid = '6c07cb62-5713-41ba-9f1e-55dd7052e8fa';
    $display->content['new-6c07cb62-5713-41ba-9f1e-55dd7052e8fa'] = $pane;
    $display->panels['col3'][0] = 'new-6c07cb62-5713-41ba-9f1e-55dd7052e8fa';
    $pane = new stdClass();
    $pane->pid = 'new-cce76361-b5db-4868-9cce-447ee3ba8a47';
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
    $pane->uuid = 'cce76361-b5db-4868-9cce-447ee3ba8a47';
    $display->content['new-cce76361-b5db-4868-9cce-447ee3ba8a47'] = $pane;
    $display->panels['left'][0] = 'new-cce76361-b5db-4868-9cce-447ee3ba8a47';
    $pane = new stdClass();
    $pane->pid = 'new-9d05a92f-63b9-448f-97d2-1eef19a22b20';
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
    $pane->uuid = '9d05a92f-63b9-448f-97d2-1eef19a22b20';
    $display->content['new-9d05a92f-63b9-448f-97d2-1eef19a22b20'] = $pane;
    $display->panels['media'][0] = 'new-9d05a92f-63b9-448f-97d2-1eef19a22b20';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-9d05a92f-63b9-448f-97d2-1eef19a22b20';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home_layout'] = $page;

  return $pages;

}
