<?php
/**
 * @file
 * profile_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function profile_features_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context_4';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Autor Tutor Dozent Student',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'master',
        'context' => 'argument_entity_id:user_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
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
          0 => 1,
          1 => 'main',
          2 => 2,
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
        'width' => '26.3311842451191',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'col-xs-12 col-sm-3 col-sm-push-6',
        'hide_empty' => 0,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'column',
        'width' => '25.13203096959442',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 3,
        ),
        'class' => 'col-xs-12 col-sm-3 ',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'column',
        'width' => '48.53678478528647',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 4,
        ),
        'class' => 'col-xs-12 col-sm-6 col-sm-pull-3',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right',
        ),
        'parent' => '2',
        'class' => '',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'middle',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
    'left' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '8379bcdc-986a-4f10-9b67-3a850e77e04c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_view_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c2085304-126d-4ad9-934d-395ab5e1f73a';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'profile-header',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
print theme(\'profile_header\', array(\'uid\' => %user:uid));
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c2085304-126d-4ad9-934d-395ab5e1f73a';
  $display->content['new-c2085304-126d-4ad9-934d-395ab5e1f73a'] = $pane;
  $display->panels['middle'][0] = 'new-c2085304-126d-4ad9-934d-395ab5e1f73a';
  $pane = new stdClass();
  $pane->pid = 'new-5b3eac9d-a7b1-4a67-b379-b812dae22acf';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'profile-details',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
print theme(\'profile_details\', array(\'uid\' => %user:uid));
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
  $pane->uuid = '5b3eac9d-a7b1-4a67-b379-b812dae22acf';
  $display->content['new-5b3eac9d-a7b1-4a67-b379-b812dae22acf'] = $pane;
  $display->panels['middle'][1] = 'new-5b3eac9d-a7b1-4a67-b379-b812dae22acf';
  $pane = new stdClass();
  $pane->pid = 'new-7477aca2-5723-44c2-81ff-7eb7bed96596';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'courses_kurse_bersicht-my_courses_small';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '1',
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7477aca2-5723-44c2-81ff-7eb7bed96596';
  $display->content['new-7477aca2-5723-44c2-81ff-7eb7bed96596'] = $pane;
  $display->panels['middle'][2] = 'new-7477aca2-5723-44c2-81ff-7eb7bed96596';
  $pane = new stdClass();
  $pane->pid = 'new-996dd566-dbe0-4ab4-999d-1b919ea86f95';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 30037204,
            1 => 197637936,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $pane->configuration = array(
    'admin_title' => 'courses und lt',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="row">
<div class="col-sm-9">
<?php echo _section_home_getRenderedCourses() ; ?>
</div>
<div class="col-sm-3">
<?php echo  _section_home_getRenderedDomains() ; ?>
</div>
</div>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '996dd566-dbe0-4ab4-999d-1b919ea86f95';
  $display->content['new-996dd566-dbe0-4ab4-999d-1b919ea86f95'] = $pane;
  $display->panels['middle'][3] = 'new-996dd566-dbe0-4ab4-999d-1b919ea86f95';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context_4'] = $handler;

  return $export;
}
