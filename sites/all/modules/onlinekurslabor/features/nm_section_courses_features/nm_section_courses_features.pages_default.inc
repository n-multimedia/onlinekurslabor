<?php
/**
 * @file
 * nm_section_courses_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nm_section_courses_features_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_edit_panel_context';
  $handler->task = 'user_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Student',
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
        'type' => 'student',
        'context' => 'argument_user_edit_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Profile2 from user 2',
        'keyword' => 'profile2_2',
        'name' => 'profile2',
        'type' => 'master',
        'context' => 'argument_user_edit_1',
        'id' => 2,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 66784200,
            ),
          ),
          'context' => 'argument_user_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4826b7a5-e483-486b-9d3b-f9558f5b4563';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-21c58b1e-5195-485b-883b-6c3528633cb8';
    $pane->panel = 'news';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Form',
      'title' => '',
      'body' => '<?php

$form_id = \'user_profile_form\';
$form_state = array();
//passing arguments to form.
$form_state[\'build_info\'][\'args\'] = array(user_load(%user:uid), \'account\');

form_load_include($form_state, \'inc\', \'user\', \'user.pages\');

$form = drupal_build_form($form_id, $form_state);


if (($type = profile2_get_types(\'master\')) && $type->userCategory) {
    if (empty($form_state[\'profiles\'])) {

      $profile = profile2_load_by_user($form[\'#user\'], \'master\');
      if (empty($profile)) {
        $profile = profile_create(array(\'type\' => \'master\', \'uid\' => $form[\'#user\']->uid));
      }
      $form_state[\'profiles\'][$profile->type] = $profile;
    }
    profile2_attach_form($form, $form_state);
}

return drupal_render($form);

?>',
      'format' => 'ds_code',
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
    $pane->uuid = '21c58b1e-5195-485b-883b-6c3528633cb8';
    $display->content['new-21c58b1e-5195-485b-883b-6c3528633cb8'] = $pane;
    $display->panels['news'][0] = 'new-21c58b1e-5195-485b-883b-6c3528633cb8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_edit_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Student',
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
              0 => 66784200,
              1 => 24708420,
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
  $display->layout = 'flexible:span3span6span3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
    'left' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = 'b0caec2f-46b1-423e-8cd3-2f7381977ef6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a4b1d640-c1a3-49bd-9f0a-0ea37e2297af';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'statuses-statuses';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Stream',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a4b1d640-c1a3-49bd-9f0a-0ea37e2297af';
    $display->content['new-a4b1d640-c1a3-49bd-9f0a-0ea37e2297af'] = $pane;
    $display->panels['center'][0] = 'new-a4b1d640-c1a3-49bd-9f0a-0ea37e2297af';
    $pane = new stdClass();
    $pane->pid = 'new-726087c7-69da-4760-b513-e8ffb976acdf';
    $pane->panel = 'left';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => 'h2',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '726087c7-69da-4760-b513-e8ffb976acdf';
    $display->content['new-726087c7-69da-4760-b513-e8ffb976acdf'] = $pane;
    $display->panels['left'][0] = 'new-726087c7-69da-4760-b513-e8ffb976acdf';
    $pane = new stdClass();
    $pane->pid = 'new-3f0db36e-d71f-47d4-b2c2-013c59e8b5fa';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_node_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3f0db36e-d71f-47d4-b2c2-013c59e8b5fa';
    $display->content['new-3f0db36e-d71f-47d4-b2c2-013c59e8b5fa'] = $pane;
    $display->panels['left'][1] = 'new-3f0db36e-d71f-47d4-b2c2-013c59e8b5fa';
    $pane = new stdClass();
    $pane->pid = 'new-402dcedc-3102-4fed-a48c-5b3cd0d43554';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'profile_main_thumbnail',
        'image_link' => '',
      ),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '402dcedc-3102-4fed-a48c-5b3cd0d43554';
    $display->content['new-402dcedc-3102-4fed-a48c-5b3cd0d43554'] = $pane;
    $display->panels['left'][2] = 'new-402dcedc-3102-4fed-a48c-5b3cd0d43554';
    $pane = new stdClass();
    $pane->pid = 'new-6dc1e235-84fc-4183-bdea-d84d7dbbba11';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'courses_user_courses';
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
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '%1',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => 'Meine Kurse',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6dc1e235-84fc-4183-bdea-d84d7dbbba11';
    $display->content['new-6dc1e235-84fc-4183-bdea-d84d7dbbba11'] = $pane;
    $display->panels['left'][3] = 'new-6dc1e235-84fc-4183-bdea-d84d7dbbba11';
    $pane = new stdClass();
    $pane->pid = 'new-87ceb3f7-7bf1-4420-aaa6-b9f15621754e';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_birthday';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'short',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 1,
      'override_title_text' => 'Persönliche Informationen',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '87ceb3f7-7bf1-4420-aaa6-b9f15621754e';
    $display->content['new-87ceb3f7-7bf1-4420-aaa6-b9f15621754e'] = $pane;
    $display->panels['right'][0] = 'new-87ceb3f7-7bf1-4420-aaa6-b9f15621754e';
    $pane = new stdClass();
    $pane->pid = 'new-920d703f-ff27-4fa6-8ffb-7499deb0ef6e';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_hochschule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '920d703f-ff27-4fa6-8ffb-7499deb0ef6e';
    $display->content['new-920d703f-ff27-4fa6-8ffb-7499deb0ef6e'] = $pane;
    $display->panels['right'][1] = 'new-920d703f-ff27-4fa6-8ffb-7499deb0ef6e';
    $pane = new stdClass();
    $pane->pid = 'new-49f2b61b-db9d-4327-92c1-9a9c9190a256';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_studienfach';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '49f2b61b-db9d-4327-92c1-9a9c9190a256';
    $display->content['new-49f2b61b-db9d-4327-92c1-9a9c9190a256'] = $pane;
    $display->panels['right'][2] = 'new-49f2b61b-db9d-4327-92c1-9a9c9190a256';
    $pane = new stdClass();
    $pane->pid = 'new-4bd639bd-3897-4d1d-bd80-264f7b3f8151';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_about_me';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4bd639bd-3897-4d1d-bd80-264f7b3f8151';
    $display->content['new-4bd639bd-3897-4d1d-bd80-264f7b3f8151'] = $pane;
    $display->panels['right'][3] = 'new-4bd639bd-3897-4d1d-bd80-264f7b3f8151';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context_2';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Autor',
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
              0 => 16675960,
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
  $display->layout = 'flexible:span3span6span3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
    'left' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '26b41ae7-7b48-4d3b-a3b4-26d29b58e748';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-da687858-3ea5-418a-8ffc-57285f64531a';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_about_me';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'da687858-3ea5-418a-8ffc-57285f64531a';
    $display->content['new-da687858-3ea5-418a-8ffc-57285f64531a'] = $pane;
    $display->panels['center'][0] = 'new-da687858-3ea5-418a-8ffc-57285f64531a';
    $pane = new stdClass();
    $pane->pid = 'new-3e1bbd72-9cc3-4ae2-92ec-aa0f8d8c514c';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'statuses-statuses';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Stream',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3e1bbd72-9cc3-4ae2-92ec-aa0f8d8c514c';
    $display->content['new-3e1bbd72-9cc3-4ae2-92ec-aa0f8d8c514c'] = $pane;
    $display->panels['center'][1] = 'new-3e1bbd72-9cc3-4ae2-92ec-aa0f8d8c514c';
    $pane = new stdClass();
    $pane->pid = 'new-53ff4b04-79b4-402d-97c1-3d04a985d5ee';
    $pane->panel = 'left';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => 'h2',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '53ff4b04-79b4-402d-97c1-3d04a985d5ee';
    $display->content['new-53ff4b04-79b4-402d-97c1-3d04a985d5ee'] = $pane;
    $display->panels['left'][0] = 'new-53ff4b04-79b4-402d-97c1-3d04a985d5ee';
    $pane = new stdClass();
    $pane->pid = 'new-9701b873-7c52-4fa5-b47a-42bc17083451';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'profile_main_thumbnail',
        'image_link' => '',
      ),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9701b873-7c52-4fa5-b47a-42bc17083451';
    $display->content['new-9701b873-7c52-4fa5-b47a-42bc17083451'] = $pane;
    $display->panels['left'][1] = 'new-9701b873-7c52-4fa5-b47a-42bc17083451';
    $pane = new stdClass();
    $pane->pid = 'new-246395a3-b782-459e-a3ef-4709c591a327';
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
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '%1',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Meine Themen',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '246395a3-b782-459e-a3ef-4709c591a327';
    $display->content['new-246395a3-b782-459e-a3ef-4709c591a327'] = $pane;
    $display->panels['left'][2] = 'new-246395a3-b782-459e-a3ef-4709c591a327';
    $pane = new stdClass();
    $pane->pid = 'new-61b04d72-f09e-4cfc-ab63-52b6ba2b635f';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_birthday';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'short',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 1,
      'override_title_text' => 'Persönliche Informationen',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '61b04d72-f09e-4cfc-ab63-52b6ba2b635f';
    $display->content['new-61b04d72-f09e-4cfc-ab63-52b6ba2b635f'] = $pane;
    $display->panels['right'][0] = 'new-61b04d72-f09e-4cfc-ab63-52b6ba2b635f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context_4';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Tutor',
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
              0 => 126456107,
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
  $display->layout = 'flexible:span3span6span3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
    'left' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '8ec8e78a-b094-410c-a734-57d378443600';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8b2f44b1-0ca4-43ff-88c2-546246d7f5d5';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'statuses-statuses';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Stream',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8b2f44b1-0ca4-43ff-88c2-546246d7f5d5';
    $display->content['new-8b2f44b1-0ca4-43ff-88c2-546246d7f5d5'] = $pane;
    $display->panels['center'][0] = 'new-8b2f44b1-0ca4-43ff-88c2-546246d7f5d5';
    $pane = new stdClass();
    $pane->pid = 'new-826d6b81-63b1-4e5e-8567-f951b460f3ed';
    $pane->panel = 'left';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => 'h2',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '826d6b81-63b1-4e5e-8567-f951b460f3ed';
    $display->content['new-826d6b81-63b1-4e5e-8567-f951b460f3ed'] = $pane;
    $display->panels['left'][0] = 'new-826d6b81-63b1-4e5e-8567-f951b460f3ed';
    $pane = new stdClass();
    $pane->pid = 'new-7b3e3732-cedd-45ae-a281-ab12c7c3c9d7';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_node_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7b3e3732-cedd-45ae-a281-ab12c7c3c9d7';
    $display->content['new-7b3e3732-cedd-45ae-a281-ab12c7c3c9d7'] = $pane;
    $display->panels['left'][1] = 'new-7b3e3732-cedd-45ae-a281-ab12c7c3c9d7';
    $pane = new stdClass();
    $pane->pid = 'new-e662e7e9-14e4-4e6b-9293-19b5b3d04db5';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'profile_main_thumbnail',
        'image_link' => '',
      ),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e662e7e9-14e4-4e6b-9293-19b5b3d04db5';
    $display->content['new-e662e7e9-14e4-4e6b-9293-19b5b3d04db5'] = $pane;
    $display->panels['left'][2] = 'new-e662e7e9-14e4-4e6b-9293-19b5b3d04db5';
    $pane = new stdClass();
    $pane->pid = 'new-b52d7d93-5f85-41ed-8d58-488b8614caf4';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'courses_user_courses';
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
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '%1',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => 'Meine Kurse',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b52d7d93-5f85-41ed-8d58-488b8614caf4';
    $display->content['new-b52d7d93-5f85-41ed-8d58-488b8614caf4'] = $pane;
    $display->panels['left'][3] = 'new-b52d7d93-5f85-41ed-8d58-488b8614caf4';
    $pane = new stdClass();
    $pane->pid = 'new-fb8a22a8-eec2-4e2a-ad7d-11c23df4942a';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_birthday';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'short',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 1,
      'override_title_text' => 'Persönliche Informationen',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'title' => array(
          'element' => 'h3',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'content' => array(
          'element' => '',
          'attributes' => array(
            'id' => '',
            'class' => '',
          ),
        ),
        'theme' => 0,
      ),
      'style' => 'wrapper_element',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb8a22a8-eec2-4e2a-ad7d-11c23df4942a';
    $display->content['new-fb8a22a8-eec2-4e2a-ad7d-11c23df4942a'] = $pane;
    $display->panels['right'][0] = 'new-fb8a22a8-eec2-4e2a-ad7d-11c23df4942a';
    $pane = new stdClass();
    $pane->pid = 'new-f2e6184e-365d-4010-8b0a-a3d578d45f35';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_hochschule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f2e6184e-365d-4010-8b0a-a3d578d45f35';
    $display->content['new-f2e6184e-365d-4010-8b0a-a3d578d45f35'] = $pane;
    $display->panels['right'][1] = 'new-f2e6184e-365d-4010-8b0a-a3d578d45f35';
    $pane = new stdClass();
    $pane->pid = 'new-d3c93e7b-620b-4cda-b9d6-f9ad5add3cd0';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_studienfach';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_profile2_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd3c93e7b-620b-4cda-b9d6-f9ad5add3cd0';
    $display->content['new-d3c93e7b-620b-4cda-b9d6-f9ad5add3cd0'] = $pane;
    $display->panels['right'][2] = 'new-d3c93e7b-620b-4cda-b9d6-f9ad5add3cd0';
    $pane = new stdClass();
    $pane->pid = 'new-5d4e0e93-dfa0-48f3-a92b-235a4e8deea3';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_about_me';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '5d4e0e93-dfa0-48f3-a92b-235a4e8deea3';
    $display->content['new-5d4e0e93-dfa0-48f3-a92b-235a4e8deea3'] = $pane;
    $display->panels['right'][3] = 'new-5d4e0e93-dfa0-48f3-a92b-235a4e8deea3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context_4'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function nm_section_courses_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'biblio_in_kurs_';
  $page->task = 'page';
  $page->admin_title = 'Biblio in: (Kurs)';
  $page->admin_description = '';
  $page->path = 'course/biblio/%1/%2';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_biblio_in_kurs__panel_context';
  $handler->task = 'page';
  $handler->subtask = 'biblio_in_kurs_';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Bibliografie in: %1',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'content_domain' => 'content_domain',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span8span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'outline' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '313656db-7eab-4208-a85b-052bda35f705';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1380141d-820b-4957-a180-bbf315144f01';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'domain_biblio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '%3',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Bibliografie',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1380141d-820b-4957-a180-bbf315144f01';
    $display->content['new-1380141d-820b-4957-a180-bbf315144f01'] = $pane;
    $display->panels['center'][0] = 'new-1380141d-820b-4957-a180-bbf315144f01';
    $pane = new stdClass();
    $pane->pid = 'new-ee146fe2-8ff9-453e-95a4-9d421b8b1869';
    $pane->panel = 'outline';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
return section_courses_text_outline();
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
    $pane->uuid = 'ee146fe2-8ff9-453e-95a4-9d421b8b1869';
    $display->content['new-ee146fe2-8ff9-453e-95a4-9d421b8b1869'] = $pane;
    $display->panels['outline'][0] = 'new-ee146fe2-8ff9-453e-95a4-9d421b8b1869';
    $pane = new stdClass();
    $pane->pid = 'new-5fabd75b-70a8-446b-88f2-53d63090bf50';
    $pane->panel = 'outline';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_text_biblio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5fabd75b-70a8-446b-88f2-53d63090bf50';
    $display->content['new-5fabd75b-70a8-446b-88f2-53d63090bf50'] = $pane;
    $display->panels['outline'][1] = 'new-5fabd75b-70a8-446b-88f2-53d63090bf50';
    $pane = new stdClass();
    $pane->pid = 'new-25714d38-922e-4cca-aef6-6afd35361c29';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '25714d38-922e-4cca-aef6-6afd35361c29';
    $display->content['new-25714d38-922e-4cca-aef6-6afd35361c29'] = $pane;
    $display->panels['tools'][0] = 'new-25714d38-922e-4cca-aef6-6afd35361c29';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['biblio_in_kurs_'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'course_admin_add_member';
  $page->task = 'page';
  $page->admin_title = 'Course - Admin - Studenten anlegen';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/members/add';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_admin_add_member_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'course_admin_add_member';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'span8',
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
        'title' => 'Zentriert',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'span4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'Tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Teilnehmer anlegen';
  $display->uuid = '7ba68c20-7b25-40df-8f33-3f8deb231bbb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2c30f2da-ad10-49f8-8f28-643e49184e14';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
   echo drupal_render(drupal_get_form(\'section_courses_student_registration_form\'));
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
    $pane->uuid = '2c30f2da-ad10-49f8-8f28-643e49184e14';
    $display->content['new-2c30f2da-ad10-49f8-8f28-643e49184e14'] = $pane;
    $display->panels['center'][0] = 'new-2c30f2da-ad10-49f8-8f28-643e49184e14';
    $pane = new stdClass();
    $pane->pid = 'new-2411cdde-a5db-4dc4-a5a9-38744616137f';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2411cdde-a5db-4dc4-a5a9-38744616137f';
    $display->content['new-2411cdde-a5db-4dc4-a5a9-38744616137f'] = $pane;
    $display->panels['tools'][0] = 'new-2411cdde-a5db-4dc4-a5a9-38744616137f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['course_admin_add_member'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'course_admin_settings';
  $page->task = 'page';
  $page->admin_title = 'Course - Admin - Settings';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/settings';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_node_edit_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Node edit form: node ID',
      'name' => 'node_edit',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_admin_settings_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'course_admin_settings';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'bd02776a-cabf-4484-962d-02eba6786d10';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce6f8ed2-841d-425a-8bc8-e5a9e2f6f971';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce6f8ed2-841d-425a-8bc8-e5a9e2f6f971';
    $display->content['new-ce6f8ed2-841d-425a-8bc8-e5a9e2f6f971'] = $pane;
    $display->panels['center'][0] = 'new-ce6f8ed2-841d-425a-8bc8-e5a9e2f6f971';
    $pane = new stdClass();
    $pane->pid = 'new-ca019006-96ec-48b1-9433-e2e9cf55244a';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ca019006-96ec-48b1-9433-e2e9cf55244a';
    $display->content['new-ca019006-96ec-48b1-9433-e2e9cf55244a'] = $pane;
    $display->panels['tools'][0] = 'new-ca019006-96ec-48b1-9433-e2e9cf55244a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ce6f8ed2-841d-425a-8bc8-e5a9e2f6f971';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['course_admin_settings'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'course_groups_in_course';
  $page->task = 'page';
  $page->admin_title = 'Kursgruppen in: (Kurs)';
  $page->admin_description = '';
  $page->path = 'course/groups/%1/%2';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_groups_in_course_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'course_groups_in_course';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Kursgruppe',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_group' => 'courses_group',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'tools',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Zentriert',
        'width' => '74.99327088820641',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'tools',
        'width' => '25.006729111793597',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
      'news' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3b5949a4-3d32-421c-bfa5-2ee37a8778d3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c3ca9007-70eb-4968-bd27-93254fa6d8c2';
    $pane->panel = 'news';
    $pane->type = 'block';
    $pane->subtype = 'statuses-statuses';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c3ca9007-70eb-4968-bd27-93254fa6d8c2';
    $display->content['new-c3ca9007-70eb-4968-bd27-93254fa6d8c2'] = $pane;
    $display->panels['news'][0] = 'new-c3ca9007-70eb-4968-bd27-93254fa6d8c2';
    $pane = new stdClass();
    $pane->pid = 'new-02635efd-e850-41ca-aa6f-cdaedc7661cc';
    $pane->panel = 'tools';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_2',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '02635efd-e850-41ca-aa6f-cdaedc7661cc';
    $display->content['new-02635efd-e850-41ca-aa6f-cdaedc7661cc'] = $pane;
    $display->panels['tools'][0] = 'new-02635efd-e850-41ca-aa6f-cdaedc7661cc';
    $pane = new stdClass();
    $pane->pid = 'new-3376aaa8-0ebc-4213-8f32-475167b833f1';
    $pane->panel = 'tools';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_course_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'context' => array(
        0 => 'argument_entity_id:node_2.nid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3376aaa8-0ebc-4213-8f32-475167b833f1';
    $display->content['new-3376aaa8-0ebc-4213-8f32-475167b833f1'] = $pane;
    $display->panels['tools'][1] = 'new-3376aaa8-0ebc-4213-8f32-475167b833f1';
    $pane = new stdClass();
    $pane->pid = 'new-84f9e961-3ae9-4635-8a4e-487d63d3db8a';
    $pane->panel = 'tools';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:group_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'og_group_subscribe',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_name' => '0',
      ),
      'context' => 'argument_entity_id:node_2',
      'override_title' => 1,
      'override_title_text' => 'Kursgruppe',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '84f9e961-3ae9-4635-8a4e-487d63d3db8a';
    $display->content['new-84f9e961-3ae9-4635-8a4e-487d63d3db8a'] = $pane;
    $display->panels['tools'][2] = 'new-84f9e961-3ae9-4635-8a4e-487d63d3db8a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c3ca9007-70eb-4968-bd27-93254fa6d8c2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_groups_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'course_groups_in_course';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Kursgruppen Übersicht',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'span8',
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
        'title' => 'Zentriert',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'span4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'Tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
      'news' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c4372bbe-f8f1-4cde-95f8-fa02db3ea52a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8822711e-1148-4680-8e6f-e1aed6c181ef';
    $pane->panel = 'news';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_course_groups-panel_pane_1';
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
    $pane->uuid = '8822711e-1148-4680-8e6f-e1aed6c181ef';
    $display->content['new-8822711e-1148-4680-8e6f-e1aed6c181ef'] = $pane;
    $display->panels['news'][0] = 'new-8822711e-1148-4680-8e6f-e1aed6c181ef';
    $pane = new stdClass();
    $pane->pid = 'new-26a96f20-05fa-45dc-8c7e-66bf50b9e235';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '26a96f20-05fa-45dc-8c7e-66bf50b9e235';
    $display->content['new-26a96f20-05fa-45dc-8c7e-66bf50b9e235'] = $pane;
    $display->panels['tools'][0] = 'new-26a96f20-05fa-45dc-8c7e-66bf50b9e235';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8822711e-1148-4680-8e6f-e1aed6c181ef';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['course_groups_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'course_single_doc';
  $page->task = 'page';
  $page->admin_title = 'Course Single Doc';
  $page->admin_description = '';
  $page->path = 'course/doc/%1/%2';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_single_doc_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'course_single_doc';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_docs' => 'courses_docs',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '133fd409-6a12-4659-a41a-27c28ddf3d59';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a65bff2b-ee28-4e51-bacd-52fdb034e155';
    $pane->panel = 'news';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_node_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a65bff2b-ee28-4e51-bacd-52fdb034e155';
    $display->content['new-a65bff2b-ee28-4e51-bacd-52fdb034e155'] = $pane;
    $display->panels['news'][0] = 'new-a65bff2b-ee28-4e51-bacd-52fdb034e155';
    $pane = new stdClass();
    $pane->pid = 'new-9f309872-a290-478e-985c-88bce5e6da2e';
    $pane->panel = 'news';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9f309872-a290-478e-985c-88bce5e6da2e';
    $display->content['new-9f309872-a290-478e-985c-88bce5e6da2e'] = $pane;
    $display->panels['news'][1] = 'new-9f309872-a290-478e-985c-88bce5e6da2e';
    $pane = new stdClass();
    $pane->pid = 'new-0a743fe1-d4b4-4a96-8213-0a6f5947d0b6';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0a743fe1-d4b4-4a96-8213-0a6f5947d0b6';
    $display->content['new-0a743fe1-d4b4-4a96-8213-0a6f5947d0b6'] = $pane;
    $display->panels['tools'][0] = 'new-0a743fe1-d4b4-4a96-8213-0a6f5947d0b6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['course_single_doc'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'course_tasks_solution';
  $page->task = 'page';
  $page->admin_title = 'Course - Tasks - Solution';
  $page->admin_description = '';
  $page->path = 'course/tasks/%1/%2/solution';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_course_tasks_solution_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'course_tasks_solution';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_generic_task' => 'courses_generic_task',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'rechts',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Zentriert',
        'width' => '74.35863055332082',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'rechts' => array(
        'type' => 'region',
        'title' => 'Rechts',
        'width' => '25.641369446679185',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'rechts' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1d457142-665a-4438-9d5b-58c78732864b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1529000e-d78b-4384-946f-e11f38bbfbad';
    $pane->panel = 'news';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_node_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1529000e-d78b-4384-946f-e11f38bbfbad';
    $display->content['new-1529000e-d78b-4384-946f-e11f38bbfbad'] = $pane;
    $display->panels['news'][0] = 'new-1529000e-d78b-4384-946f-e11f38bbfbad';
    $pane = new stdClass();
    $pane->pid = 'new-d082ba96-322f-411d-8917-7b687b7b2ec0';
    $pane->panel = 'news';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_tasks_generic_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd082ba96-322f-411d-8917-7b687b7b2ec0';
    $display->content['new-d082ba96-322f-411d-8917-7b687b7b2ec0'] = $pane;
    $display->panels['news'][1] = 'new-d082ba96-322f-411d-8917-7b687b7b2ec0';
    $pane = new stdClass();
    $pane->pid = 'new-d8ad8c86-c9f9-4f8d-b84d-17d93fe6b990';
    $pane->panel = 'news';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_tasks_generic_solution';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd8ad8c86-c9f9-4f8d-b84d-17d93fe6b990';
    $display->content['new-d8ad8c86-c9f9-4f8d-b84d-17d93fe6b990'] = $pane;
    $display->panels['news'][2] = 'new-d8ad8c86-c9f9-4f8d-b84d-17d93fe6b990';
    $pane = new stdClass();
    $pane->pid = 'new-a848db66-c79e-44b7-ac3e-e6c55e849c08';
    $pane->panel = 'tools';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_task_solutions-panel_pane_1';
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
    $pane->uuid = 'a848db66-c79e-44b7-ac3e-e6c55e849c08';
    $display->content['new-a848db66-c79e-44b7-ac3e-e6c55e849c08'] = $pane;
    $display->panels['tools'][0] = 'new-a848db66-c79e-44b7-ac3e-e6c55e849c08';
    $pane = new stdClass();
    $pane->pid = 'new-e75b50e4-3729-45bd-966e-b26054945c7d';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_tasks_generic_tips';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e75b50e4-3729-45bd-966e-b26054945c7d';
    $display->content['new-e75b50e4-3729-45bd-966e-b26054945c7d'] = $pane;
    $display->panels['tools'][1] = 'new-e75b50e4-3729-45bd-966e-b26054945c7d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['course_tasks_solution'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courseinformation_in_course_';
  $page->task = 'page';
  $page->admin_title = 'Kursinformationen in: (Kurs) ';
  $page->admin_description = '';
  $page->path = 'course/info/%1';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courseinformation_in_course__panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'courseinformation_in_course_';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Kursinformationen',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:course_information';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 3,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '76.2660045268741',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
        'class' => 'span11 course-info',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'links',
          1 => 'rechts',
        ),
        'parent' => 'main',
        'class' => 'header row-fluid',
      ),
      'links' => array(
        'type' => 'region',
        'title' => 'header_left',
        'width' => '65.40245299300852',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'header_left span8',
      ),
      'rechts' => array(
        'type' => 'region',
        'title' => 'header_right',
        'width' => '34.597547006991476',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'header_right span4',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'links_',
          1 => 'rechts_',
        ),
        'parent' => 'main',
        'class' => 'subheader',
      ),
      'links_' => array(
        'type' => 'region',
        'title' => 'subheader_left',
        'width' => '65.40245205837297',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'subheader_left span8',
      ),
      'rechts_' => array(
        'type' => 'region',
        'title' => 'subheader_right',
        'width' => '34.59754794162703',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'subheader_right span4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'content',
        ),
        'parent' => 'main',
        'class' => 'content row-fluid',
      ),
      'content' => array(
        'type' => 'region',
        'title' => 'Content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'span12',
      ),
      3 => array(
        'type' => 'column',
        'width' => '23.733995473125905',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 4,
        ),
        'class' => 'span1',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '3',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'Tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'links' => NULL,
      'rechts' => NULL,
      'links_' => NULL,
      'rechts_' => NULL,
      'content' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '644324ff-4973-48e2-8fc3-6a3636a24ba2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-39e62316-0628-4446-9444-e8e5b4b0d17b';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_long_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Beschreibung des Kurses',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39e62316-0628-4446-9444-e8e5b4b0d17b';
    $display->content['new-39e62316-0628-4446-9444-e8e5b4b0d17b'] = $pane;
    $display->panels['content'][0] = 'new-39e62316-0628-4446-9444-e8e5b4b0d17b';
    $pane = new stdClass();
    $pane->pid = 'new-e83cd5e5-beee-491c-8c79-345bdf8d055d';
    $pane->panel = 'links';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e83cd5e5-beee-491c-8c79-345bdf8d055d';
    $display->content['new-e83cd5e5-beee-491c-8c79-345bdf8d055d'] = $pane;
    $display->panels['links'][0] = 'new-e83cd5e5-beee-491c-8c79-345bdf8d055d';
    $pane = new stdClass();
    $pane->pid = 'new-c4d8726d-2e21-4561-9b39-b999d36b83be';
    $pane->panel = 'links';
    $pane->type = 'views';
    $pane->subtype = 'courses_instructors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '%1',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c4d8726d-2e21-4561-9b39-b999d36b83be';
    $display->content['new-c4d8726d-2e21-4561-9b39-b999d36b83be'] = $pane;
    $display->panels['links'][1] = 'new-c4d8726d-2e21-4561-9b39-b999d36b83be';
    $pane = new stdClass();
    $pane->pid = 'new-5c32c04d-d29b-4e48-aa20-8f7b0ecca03e';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5c32c04d-d29b-4e48-aa20-8f7b0ecca03e';
    $display->content['new-5c32c04d-d29b-4e48-aa20-8f7b0ecca03e'] = $pane;
    $display->panels['links'][2] = 'new-5c32c04d-d29b-4e48-aa20-8f7b0ecca03e';
    $pane = new stdClass();
    $pane->pid = 'new-c75c558c-fb77-4f58-ab0e-5e6e255ca112';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_short_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c75c558c-fb77-4f58-ab0e-5e6e255ca112';
    $display->content['new-c75c558c-fb77-4f58-ab0e-5e6e255ca112'] = $pane;
    $display->panels['links'][3] = 'new-c75c558c-fb77-4f58-ab0e-5e6e255ca112';
    $pane = new stdClass();
    $pane->pid = 'new-94f9a035-9982-4b51-b450-5987edf03aff';
    $pane->panel = 'links_';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_time_span';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'short',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '94f9a035-9982-4b51-b450-5987edf03aff';
    $display->content['new-94f9a035-9982-4b51-b450-5987edf03aff'] = $pane;
    $display->panels['links_'][0] = 'new-94f9a035-9982-4b51-b450-5987edf03aff';
    $pane = new stdClass();
    $pane->pid = 'new-84b9101c-08ad-43d8-bf49-f7decff273c9';
    $pane->panel = 'links_';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_workload';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '84b9101c-08ad-43d8-bf49-f7decff273c9';
    $display->content['new-84b9101c-08ad-43d8-bf49-f7decff273c9'] = $pane;
    $display->panels['links_'][1] = 'new-84b9101c-08ad-43d8-bf49-f7decff273c9';
    $pane = new stdClass();
    $pane->pid = 'new-6d6b7749-f492-4467-954b-208326b6acea';
    $pane->panel = 'links_';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:group_group';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'og_group_subscribe',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_name' => '0',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6d6b7749-f492-4467-954b-208326b6acea';
    $display->content['new-6d6b7749-f492-4467-954b-208326b6acea'] = $pane;
    $display->panels['links_'][2] = 'new-6d6b7749-f492-4467-954b-208326b6acea';
    $pane = new stdClass();
    $pane->pid = 'new-1c7a2261-864b-4045-894e-e079b7439fe9';
    $pane->panel = 'rechts';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_course_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'large',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1c7a2261-864b-4045-894e-e079b7439fe9';
    $display->content['new-1c7a2261-864b-4045-894e-e079b7439fe9'] = $pane;
    $display->panels['rechts'][0] = 'new-1c7a2261-864b-4045-894e-e079b7439fe9';
    $pane = new stdClass();
    $pane->pid = 'new-88327f40-c42d-4013-af57-b4279a92f71e';
    $pane->panel = 'rechts_';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
if(is_numeric(arg(2))){
$course= node_load(arg(2));
echo section_courses_render_course_link($course);
}
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
    $pane->uuid = '88327f40-c42d-4013-af57-b4279a92f71e';
    $display->content['new-88327f40-c42d-4013-af57-b4279a92f71e'] = $pane;
    $display->panels['rechts_'][0] = 'new-88327f40-c42d-4013-af57-b4279a92f71e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courseinformation_in_course_'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_admin_add_node';
  $page->task = 'page';
  $page->admin_title = 'Courses Admin Add Node';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/add/%2';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 1,
      'identifier' => 'Node add form: node type',
      'name' => 'node_add',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_admin_add_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_admin_add_node';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '67.94595703225146',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'span11',
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
        'title' => 'Zentriert',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '32.05404296774855',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'span1',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'Tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '63b915e2-8f29-4cf2-a135-48137d1b30ed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9d853486-f6b2-4089-be99-f01f7b40fa38';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_add_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9d853486-f6b2-4089-be99-f01f7b40fa38';
    $display->content['new-9d853486-f6b2-4089-be99-f01f7b40fa38'] = $pane;
    $display->panels['center'][0] = 'new-9d853486-f6b2-4089-be99-f01f7b40fa38';
    $pane = new stdClass();
    $pane->pid = 'new-bf46912a-3c6d-47d6-a1fc-531da70fc323';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bf46912a-3c6d-47d6-a1fc-531da70fc323';
    $display->content['new-bf46912a-3c6d-47d6-a1fc-531da70fc323'] = $pane;
    $display->panels['tools'][0] = 'new-bf46912a-3c6d-47d6-a1fc-531da70fc323';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9d853486-f6b2-4089-be99-f01f7b40fa38';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_admin_add_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_admin_content';
  $page->task = 'page';
  $page->admin_title = 'Courses Admin Content';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/content';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_admin_content_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_admin_content';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'span11',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 3,
          1 => 2,
        ),
        'parent' => 'main',
        'class' => 'row-fluid',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 4,
        ),
        'class' => 'span1',
      ),
      2 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 6,
        ),
        'class' => 'span6',
      ),
      3 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 5,
        ),
        'class' => 'span6',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'main_left',
        ),
        'parent' => '3',
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'main_right',
        ),
        'parent' => '2',
        'class' => '',
      ),
      'main_left' => array(
        'type' => 'region',
        'title' => 'main-left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
      ),
      'main_right' => array(
        'type' => 'region',
        'title' => 'main-right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
      'main_left' => NULL,
      'main_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Inhalte';
  $display->uuid = '2afafb77-4b31-4281-8162-381c7355f109';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c0bbac52-8bac-4d6f-9c60-6dce768d582f';
    $pane->panel = 'main_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_admin_content-panel_pane_1';
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
    $pane->uuid = 'c0bbac52-8bac-4d6f-9c60-6dce768d582f';
    $display->content['new-c0bbac52-8bac-4d6f-9c60-6dce768d582f'] = $pane;
    $display->panels['main_left'][0] = 'new-c0bbac52-8bac-4d6f-9c60-6dce768d582f';
    $pane = new stdClass();
    $pane->pid = 'new-85db39d3-448c-4d54-80e8-7d3b323d53a3';
    $pane->panel = 'main_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_admin_content-panel_pane_3';
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
    $pane->uuid = '85db39d3-448c-4d54-80e8-7d3b323d53a3';
    $display->content['new-85db39d3-448c-4d54-80e8-7d3b323d53a3'] = $pane;
    $display->panels['main_left'][1] = 'new-85db39d3-448c-4d54-80e8-7d3b323d53a3';
    $pane = new stdClass();
    $pane->pid = 'new-32b67992-5f9c-48eb-b674-1af3d0497ecd';
    $pane->panel = 'main_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_admin_content-panel_pane_2';
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
    $pane->uuid = '32b67992-5f9c-48eb-b674-1af3d0497ecd';
    $display->content['new-32b67992-5f9c-48eb-b674-1af3d0497ecd'] = $pane;
    $display->panels['main_right'][0] = 'new-32b67992-5f9c-48eb-b674-1af3d0497ecd';
    $pane = new stdClass();
    $pane->pid = 'new-5e097dea-0404-492b-874c-8139cbbd038f';
    $pane->panel = 'main_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_admin_content-panel_pane_4';
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
    $pane->uuid = '5e097dea-0404-492b-874c-8139cbbd038f';
    $display->content['new-5e097dea-0404-492b-874c-8139cbbd038f'] = $pane;
    $display->panels['main_right'][1] = 'new-5e097dea-0404-492b-874c-8139cbbd038f';
    $pane = new stdClass();
    $pane->pid = 'new-e47bcd0e-46a5-456a-be8c-f57980847f62';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e47bcd0e-46a5-456a-be8c-f57980847f62';
    $display->content['new-e47bcd0e-46a5-456a-be8c-f57980847f62'] = $pane;
    $display->panels['tools'][0] = 'new-e47bcd0e-46a5-456a-be8c-f57980847f62';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_admin_content'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_admin_edit_node';
  $page->task = 'page';
  $page->admin_title = 'Courses Admin Edit Node';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/%2/edit';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 1,
      'identifier' => 'Node edit form: node ID',
      'name' => 'node_edit',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_admin_edit_node_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_admin_edit_node';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
              'courses_docs' => 'courses_docs',
              'courses_generic_task' => 'courses_generic_task',
              'courses_generic_task_solution' => 'courses_generic_task_solution',
              'courses_group' => 'courses_group',
              'courses_news' => 'courses_news',
              'forum' => 'forum',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e6769333-90d6-4ad3-afc8-ddade2fab8bf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0fbaa18a-d7ba-48b6-b377-5b0de963b33b';
    $pane->panel = 'news';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_node_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0fbaa18a-d7ba-48b6-b377-5b0de963b33b';
    $display->content['new-0fbaa18a-d7ba-48b6-b377-5b0de963b33b'] = $pane;
    $display->panels['news'][0] = 'new-0fbaa18a-d7ba-48b6-b377-5b0de963b33b';
    $pane = new stdClass();
    $pane->pid = 'new-1e64759c-d003-45c4-be68-b397626c73fb';
    $pane->panel = 'news';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1e64759c-d003-45c4-be68-b397626c73fb';
    $display->content['new-1e64759c-d003-45c4-be68-b397626c73fb'] = $pane;
    $display->panels['news'][1] = 'new-1e64759c-d003-45c4-be68-b397626c73fb';
    $pane = new stdClass();
    $pane->pid = 'new-0e4d44cc-516a-48fb-a510-5d0547b943a2';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0e4d44cc-516a-48fb-a510-5d0547b943a2';
    $display->content['new-0e4d44cc-516a-48fb-a510-5d0547b943a2'] = $pane;
    $display->panels['tools'][0] = 'new-0e4d44cc-516a-48fb-a510-5d0547b943a2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1e64759c-d003-45c4-be68-b397626c73fb';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_admin_edit_node'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_admin_forums';
  $page->task = 'page';
  $page->admin_title = 'Courses Admin Forums';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/forums';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_admin_forums_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_admin_forums';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Forum';
  $display->uuid = 'ad907e3e-c0f4-44e6-b187-ed77c9da219a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f51ab282-726a-430a-8dfe-e974d4715bbf';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Die Funktionalität &quot;Forumstruktur bearbeiten&quot; ist noch nicht verfügbar.</p><p><span style="line-height: 1.538em;">Bitte wenden Sie sich an den Administrator der Seite, damit dieser die gewünschten Änderungen für Sie einpflegen kann.</span></p>',
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
    $pane->uuid = 'f51ab282-726a-430a-8dfe-e974d4715bbf';
    $display->content['new-f51ab282-726a-430a-8dfe-e974d4715bbf'] = $pane;
    $display->panels['center'][0] = 'new-f51ab282-726a-430a-8dfe-e974d4715bbf';
    $pane = new stdClass();
    $pane->pid = 'new-23efa673-b12a-4d84-8207-3940382a60bd';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '23efa673-b12a-4d84-8207-3940382a60bd';
    $display->content['new-23efa673-b12a-4d84-8207-3940382a60bd'] = $pane;
    $display->panels['tools'][0] = 'new-23efa673-b12a-4d84-8207-3940382a60bd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_admin_forums'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_admin_groups';
  $page->task = 'page';
  $page->admin_title = 'Courses Admin Groups';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/groups';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_admin_groups_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_admin_groups';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'span11',
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
        'title' => 'Zentriert',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'span1',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'Tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Kursgruppen';
  $display->uuid = 'c2911da3-54b6-44ba-8dcd-1ece1e821a11';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fe23a550-a43f-438c-8ade-c587d6fe6484';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_groups';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fe23a550-a43f-438c-8ade-c587d6fe6484';
    $display->content['new-fe23a550-a43f-438c-8ade-c587d6fe6484'] = $pane;
    $display->panels['center'][0] = 'new-fe23a550-a43f-438c-8ade-c587d6fe6484';
    $pane = new stdClass();
    $pane->pid = 'new-6451f9f8-7169-4e6d-8218-0bdf79e9c54b';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6451f9f8-7169-4e6d-8218-0bdf79e9c54b';
    $display->content['new-6451f9f8-7169-4e6d-8218-0bdf79e9c54b'] = $pane;
    $display->panels['tools'][0] = 'new-6451f9f8-7169-4e6d-8218-0bdf79e9c54b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fe23a550-a43f-438c-8ade-c587d6fe6484';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_admin_groups'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_admin_members';
  $page->task = 'page';
  $page->admin_title = 'Courses Admin Members';
  $page->admin_description = '';
  $page->path = 'course/admin/%1/members';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_role',
        'settings' => array(
          'og_rids' => array(
            0 => 'kurs-dozent',
            1 => 'kurs-tutor',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_admin_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_admin_members';
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
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
    'center' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7f1b6d29-0b18-4887-8092-ad702c25e998';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c5a2632c-25f3-49d4-b4a1-880acbd48cc2';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'bl_1',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Angefragt/Gesperrt',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c5a2632c-25f3-49d4-b4a1-880acbd48cc2';
    $display->content['new-c5a2632c-25f3-49d4-b4a1-880acbd48cc2'] = $pane;
    $display->panels['center'][0] = 'new-c5a2632c-25f3-49d4-b4a1-880acbd48cc2';
    $pane = new stdClass();
    $pane->pid = 'new-d641ea21-0f57-45e0-9db9-41a8a4ebd2a8';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'bl_2',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Studenten',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd641ea21-0f57-45e0-9db9-41a8a4ebd2a8';
    $display->content['new-d641ea21-0f57-45e0-9db9-41a8a4ebd2a8'] = $pane;
    $display->panels['center'][1] = 'new-d641ea21-0f57-45e0-9db9-41a8a4ebd2a8';
    $pane = new stdClass();
    $pane->pid = 'new-0373d4ab-8a57-40ec-83c5-54a9dc11137a';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'bl_3',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Tutoren',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0373d4ab-8a57-40ec-83c5-54a9dc11137a';
    $display->content['new-0373d4ab-8a57-40ec-83c5-54a9dc11137a'] = $pane;
    $display->panels['center'][2] = 'new-0373d4ab-8a57-40ec-83c5-54a9dc11137a';
    $pane = new stdClass();
    $pane->pid = 'new-34ab6bd0-8150-4750-8ccf-bef4ea54e2ad';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'bl_4',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Dozenten',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '34ab6bd0-8150-4750-8ccf-bef4ea54e2ad';
    $display->content['new-34ab6bd0-8150-4750-8ccf-bef4ea54e2ad'] = $pane;
    $display->panels['center'][3] = 'new-34ab6bd0-8150-4750-8ccf-bef4ea54e2ad';
    $pane = new stdClass();
    $pane->pid = 'new-d51702d1-a285-4efa-8ada-d0a0722303bf';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'bl_5',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Gast/Test Studenten',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'd51702d1-a285-4efa-8ada-d0a0722303bf';
    $display->content['new-d51702d1-a285-4efa-8ada-d0a0722303bf'] = $pane;
    $display->panels['center'][4] = 'new-d51702d1-a285-4efa-8ada-d0a0722303bf';
    $pane = new stdClass();
    $pane->pid = 'new-e9a53f02-3c66-4d8b-b028-5b54af3204f3';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'bl_6',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Alle Mitglieder',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'e9a53f02-3c66-4d8b-b028-5b54af3204f3';
    $display->content['new-e9a53f02-3c66-4d8b-b028-5b54af3204f3'] = $pane;
    $display->panels['center'][5] = 'new-e9a53f02-3c66-4d8b-b028-5b54af3204f3';
    $pane = new stdClass();
    $pane->pid = 'new-3cd7fb23-b9c6-4ba8-9fd4-f06b774a8231';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3cd7fb23-b9c6-4ba8-9fd4-f06b774a8231';
    $display->content['new-3cd7fb23-b9c6-4ba8-9fd4-f06b774a8231'] = $pane;
    $display->panels['tools'][0] = 'new-3cd7fb23-b9c6-4ba8-9fd4-f06b774a8231';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3cd7fb23-b9c6-4ba8-9fd4-f06b774a8231';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_admin_members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_course_home';
  $page->task = 'page';
  $page->admin_title = 'Courses - Course - Home';
  $page->admin_description = '';
  $page->path = 'course/home/%1';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_course_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_course_home';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'news' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '83557864-f13b-4b0d-b352-00718d863399';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-18acb524-f72a-4653-93f8-d3110ea03364';
    $pane->panel = 'news';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_course_news-panel_pane_1';
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
    $pane->uuid = '18acb524-f72a-4653-93f8-d3110ea03364';
    $display->content['new-18acb524-f72a-4653-93f8-d3110ea03364'] = $pane;
    $display->panels['news'][0] = 'new-18acb524-f72a-4653-93f8-d3110ea03364';
    $pane = new stdClass();
    $pane->pid = 'new-272d00ed-04f6-4ad5-bf6f-cbd5f90551a1';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '272d00ed-04f6-4ad5-bf6f-cbd5f90551a1';
    $display->content['new-272d00ed-04f6-4ad5-bf6f-cbd5f90551a1'] = $pane;
    $display->panels['tools'][0] = 'new-272d00ed-04f6-4ad5-bf6f-cbd5f90551a1';
    $pane = new stdClass();
    $pane->pid = 'new-05132d38-6666-45c6-89f5-1a2ad381320b';
    $pane->panel = 'tools';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
echo section_courses_theme_progressbar();
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
    $pane->uuid = '05132d38-6666-45c6-89f5-1a2ad381320b';
    $display->content['new-05132d38-6666-45c6-89f5-1a2ad381320b'] = $pane;
    $display->panels['tools'][1] = 'new-05132d38-6666-45c6-89f5-1a2ad381320b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-18acb524-f72a-4653-93f8-d3110ea03364';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_course_home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_course_overview';
  $page->task = 'page';
  $page->admin_title = 'courses-course-overview';
  $page->admin_description = '';
  $page->path = 'courses';
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
  $handler->name = 'page_courses_course_overview_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_course_overview';
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
  $display->layout = 'flexible:span12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '532d2f69-94b7-4a1d-be7a-340653e8ed4c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-605e0f6d-45cc-409c-82a6-ee4bcb5732fe';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
if(section_courses_instructors_tools_access())
echo \'<p><a class="btn" href="/node/add/courses-course">Neuen Kurs anlegen</a></p>\';

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
    $pane->uuid = '605e0f6d-45cc-409c-82a6-ee4bcb5732fe';
    $display->content['new-605e0f6d-45cc-409c-82a6-ee4bcb5732fe'] = $pane;
    $display->panels['center'][0] = 'new-605e0f6d-45cc-409c-82a6-ee4bcb5732fe';
    $pane = new stdClass();
    $pane->pid = 'new-ccee1c33-9999-43ce-8788-04d026746e96';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_kurse_bersicht-panel_pane_4';
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
    $pane->uuid = 'ccee1c33-9999-43ce-8788-04d026746e96';
    $display->content['new-ccee1c33-9999-43ce-8788-04d026746e96'] = $pane;
    $display->panels['center'][1] = 'new-ccee1c33-9999-43ce-8788-04d026746e96';
    $pane = new stdClass();
    $pane->pid = 'new-6abe3379-f868-49d8-aaff-095a06ec9af6';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_kurse_bersicht-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6abe3379-f868-49d8-aaff-095a06ec9af6';
    $display->content['new-6abe3379-f868-49d8-aaff-095a06ec9af6'] = $pane;
    $display->panels['center'][2] = 'new-6abe3379-f868-49d8-aaff-095a06ec9af6';
    $pane = new stdClass();
    $pane->pid = 'new-54b42ae9-c113-4615-af7e-70a6ead03f8d';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_kurse_bersicht-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '54b42ae9-c113-4615-af7e-70a6ead03f8d';
    $display->content['new-54b42ae9-c113-4615-af7e-70a6ead03f8d'] = $pane;
    $display->panels['center'][3] = 'new-54b42ae9-c113-4615-af7e-70a6ead03f8d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_course_overview'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_forum_in_course';
  $page->task = 'page';
  $page->admin_title = 'Kursforum in: (Kurs)';
  $page->admin_description = '';
  $page->path = 'course/forum/%1/%2';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Forum: ID',
      'name' => 'forum_id',
      'settings' => array(
        'breadcrumb' => 1,
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
  $handler->name = 'page_courses_forum_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_forum_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '75fbad92-97fb-4a47-83e3-eab8926c24c3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a2e4937b-04f2-4cfe-a5f6-5ef9eded79c1';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_forum_breadcrumbs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a2e4937b-04f2-4cfe-a5f6-5ef9eded79c1';
    $display->content['new-a2e4937b-04f2-4cfe-a5f6-5ef9eded79c1'] = $pane;
    $display->panels['center'][0] = 'new-a2e4937b-04f2-4cfe-a5f6-5ef9eded79c1';
    $pane = new stdClass();
    $pane->pid = 'new-9a9c14be-f928-4f85-b764-17ae2c5a688d';
    $pane->panel = 'center';
    $pane->type = 'forum_node_create_list';
    $pane->subtype = 'forum_node_create_list';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'forum_container',
          'settings' => array(
            'container' => '1',
            'rids' => NULL,
          ),
          'context' => 'argument_forum_id_2',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_forum_id_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9a9c14be-f928-4f85-b764-17ae2c5a688d';
    $display->content['new-9a9c14be-f928-4f85-b764-17ae2c5a688d'] = $pane;
    $display->panels['center'][1] = 'new-9a9c14be-f928-4f85-b764-17ae2c5a688d';
    $pane = new stdClass();
    $pane->pid = 'new-da0cb824-5e82-41e0-b73c-b222d4682b43';
    $pane->panel = 'center';
    $pane->type = 'forum_list';
    $pane->subtype = 'forum_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_forum_id_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'da0cb824-5e82-41e0-b73c-b222d4682b43';
    $display->content['new-da0cb824-5e82-41e0-b73c-b222d4682b43'] = $pane;
    $display->panels['center'][2] = 'new-da0cb824-5e82-41e0-b73c-b222d4682b43';
    $pane = new stdClass();
    $pane->pid = 'new-7a7bcaf8-50c9-449c-b816-9afde3231143';
    $pane->panel = 'center';
    $pane->type = 'forum_topic_list';
    $pane->subtype = 'forum_topic_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'show_sort' => 0,
      'context' => 'argument_forum_id_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '7a7bcaf8-50c9-449c-b816-9afde3231143';
    $display->content['new-7a7bcaf8-50c9-449c-b816-9afde3231143'] = $pane;
    $display->panels['center'][3] = 'new-7a7bcaf8-50c9-449c-b816-9afde3231143';
    $pane = new stdClass();
    $pane->pid = 'new-9d30ce9d-fc47-4f48-b312-d0cd3a5d8a1c';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'advanced_forum_new_topics';
    $pane->shown = FALSE;
    $pane->access = array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'forum_container',
          'settings' => array(
            'container' => '0',
            'rids' => NULL,
          ),
          'context' => 'argument_forum_id_2',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
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
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9d30ce9d-fc47-4f48-b312-d0cd3a5d8a1c';
    $display->content['new-9d30ce9d-fc47-4f48-b312-d0cd3a5d8a1c'] = $pane;
    $display->panels['center'][4] = 'new-9d30ce9d-fc47-4f48-b312-d0cd3a5d8a1c';
    $pane = new stdClass();
    $pane->pid = 'new-54e35c93-f872-44e9-93b2-e65321ea0774';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '54e35c93-f872-44e9-93b2-e65321ea0774';
    $display->content['new-54e35c93-f872-44e9-93b2-e65321ea0774'] = $pane;
    $display->panels['tools'][0] = 'new-54e35c93-f872-44e9-93b2-e65321ea0774';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_forum_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_forumcontent_add_in_course';
  $page->task = 'page';
  $page->admin_title = 'courses_forumcontent_add_in_course';
  $page->admin_description = '';
  $page->path = 'course/forumcontent/%1/%2/add';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 1,
      'identifier' => 'Forum: ID',
      'name' => 'forum_id',
      'settings' => array(
        'breadcrumb' => 0,
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
  $handler->name = 'page_courses_forumcontent_add_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_forumcontent_add_in_course';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Node add form',
        'keyword' => 'node_add',
        'name' => 'node_add_form',
        'type' => 'forum',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
            ),
          ),
          'context' => 'context_node_add_form_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '210e822a-3dc9-43ec-9a7e-20abbb0a42ab';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-03efec39-bfcc-4413-a233-8b95064c8c27';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_node_add_form_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '03efec39-bfcc-4413-a233-8b95064c8c27';
    $display->content['new-03efec39-bfcc-4413-a233-8b95064c8c27'] = $pane;
    $display->panels['center'][0] = 'new-03efec39-bfcc-4413-a233-8b95064c8c27';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-03efec39-bfcc-4413-a233-8b95064c8c27';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_forumcontent_add_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_forumcontent_delete_in_course';
  $page->task = 'page';
  $page->admin_title = 'courses_forumcontent_delete_in_course';
  $page->admin_description = '';
  $page->path = 'course/forumcontent/%1/%2/%3/delete';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 106505419,
            1 => 197637936,
            2 => 30037204,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 1,
      'identifier' => 'Forum: ID',
      'name' => 'forum_id',
      'settings' => array(
        'breadcrumb' => 1,
      ),
    ),
    3 => array(
      'id' => 1,
      'identifier' => 'Kommentar: ID',
      'name' => 'entity_id:comment',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_forumcontent_delete_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_forumcontent_delete_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '51721ad8-6f7e-4bbd-85ab-a80a977a283f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-137003ac-bafa-4c19-920d-bb76dd0e566a';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
module_load_include(\'inc\', \'comment\', \'comment.admin\');
echo drupal_render(comment_confirm_delete_page(arg(4)));

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
    $pane->uuid = '137003ac-bafa-4c19-920d-bb76dd0e566a';
    $display->content['new-137003ac-bafa-4c19-920d-bb76dd0e566a'] = $pane;
    $display->panels['center'][0] = 'new-137003ac-bafa-4c19-920d-bb76dd0e566a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-137003ac-bafa-4c19-920d-bb76dd0e566a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_forumcontent_delete_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_forumcontent_edit_in_course';
  $page->task = 'page';
  $page->admin_title = 'courses_forumcontent_edit_in_course';
  $page->admin_description = '';
  $page->path = 'course/forumcontent/%1/%2/edit';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 1,
      'identifier' => 'Node edit form: node ID',
      'name' => 'node_edit',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_forumcontent_edit_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_forumcontent_edit_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e7cb6de4-6a56-43c7-b0ff-5397614a6678';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6ce53063-4c8c-4e2c-8272-071215a0e4b9';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6ce53063-4c8c-4e2c-8272-071215a0e4b9';
    $display->content['new-6ce53063-4c8c-4e2c-8272-071215a0e4b9'] = $pane;
    $display->panels['center'][0] = 'new-6ce53063-4c8c-4e2c-8272-071215a0e4b9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6ce53063-4c8c-4e2c-8272-071215a0e4b9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_forumcontent_edit_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_forumcontent_editcomment_in_course';
  $page->task = 'page';
  $page->admin_title = 'courses_forumcontent_editcomment_in_course';
  $page->admin_description = '';
  $page->path = 'course/forumcontent/%1/%2/%3/edit';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 1,
      'identifier' => 'Forum: ID',
      'name' => 'forum_id',
      'settings' => array(
        'breadcrumb' => 1,
      ),
    ),
    3 => array(
      'id' => 1,
      'identifier' => 'Kommentar: ID',
      'name' => 'entity_id:comment',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_forumcontent_editcomment_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_forumcontent_editcomment_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9f8287dd-2434-4095-8cea-f93faefd135e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-465a6fed-8c6f-4927-8a2e-5bcebb7f0dc6';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
$comment = comment_load(arg(4));
echo drupal_render(drupal_get_form("comment_node_forum_form",$comment));

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
    $pane->uuid = '465a6fed-8c6f-4927-8a2e-5bcebb7f0dc6';
    $display->content['new-465a6fed-8c6f-4927-8a2e-5bcebb7f0dc6'] = $pane;
    $display->panels['center'][0] = 'new-465a6fed-8c6f-4927-8a2e-5bcebb7f0dc6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-465a6fed-8c6f-4927-8a2e-5bcebb7f0dc6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_forumcontent_editcomment_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_forumcontent_in_course';
  $page->task = 'page';
  $page->admin_title = 'courses_forumcontent_in_course';
  $page->admin_description = '';
  $page->path = 'course/forumcontent/%1/%2';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_forumcontent_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_forumcontent_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4f70a756-56b7-4276-a244-e20c5e0b6c72';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b6809148-70eb-4d8f-a709-4140381ae812';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_forum_breadcrumbs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b6809148-70eb-4d8f-a709-4140381ae812';
    $display->content['new-b6809148-70eb-4d8f-a709-4140381ae812'] = $pane;
    $display->panels['center'][0] = 'new-b6809148-70eb-4d8f-a709-4140381ae812';
    $pane = new stdClass();
    $pane->pid = 'new-234d2462-19df-4851-b0a7-763b8099fc30';
    $pane->panel = 'center';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '234d2462-19df-4851-b0a7-763b8099fc30';
    $display->content['new-234d2462-19df-4851-b0a7-763b8099fc30'] = $pane;
    $display->panels['center'][1] = 'new-234d2462-19df-4851-b0a7-763b8099fc30';
    $pane = new stdClass();
    $pane->pid = 'new-276a8bf0-5427-4b0f-a897-2d89bd6d59d9';
    $pane->panel = 'center';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
      'context' => 'argument_entity_id:node_2',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '276a8bf0-5427-4b0f-a897-2d89bd6d59d9';
    $display->content['new-276a8bf0-5427-4b0f-a897-2d89bd6d59d9'] = $pane;
    $display->panels['center'][2] = 'new-276a8bf0-5427-4b0f-a897-2d89bd6d59d9';
    $pane = new stdClass();
    $pane->pid = 'new-b75751b9-d756-4104-9fd8-24c0d82323a7';
    $pane->panel = 'center';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'argument_entity_id:node_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b75751b9-d756-4104-9fd8-24c0d82323a7';
    $display->content['new-b75751b9-d756-4104-9fd8-24c0d82323a7'] = $pane;
    $display->panels['center'][3] = 'new-b75751b9-d756-4104-9fd8-24c0d82323a7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_forumcontent_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_forumcontent_reply_in_course';
  $page->task = 'page';
  $page->admin_title = 'courses_forumcontent_reply_in_course';
  $page->admin_description = '';
  $page->path = 'course/forumcontent/%1/%2/%3/reply';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    3 => array(
      'id' => 1,
      'identifier' => 'Kommentar: ID',
      'name' => 'entity_id:comment',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_forumcontent_reply_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_forumcontent_reply_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3fefc907-89d6-412b-98f3-6aefa6d2732f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-dc0acb6a-a923-4abe-8d16-6dd816c0b77f';
    $pane->panel = 'center';
    $pane->type = 'comment_reply_form';
    $pane->subtype = 'comment_reply_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => FALSE,
      'context' => array(
        0 => 'argument_entity_id:node_2',
        1 => 'argument_entity_id:comment_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'dc0acb6a-a923-4abe-8d16-6dd816c0b77f';
    $display->content['new-dc0acb6a-a923-4abe-8d16-6dd816c0b77f'] = $pane;
    $display->panels['center'][0] = 'new-dc0acb6a-a923-4abe-8d16-6dd816c0b77f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_forumcontent_reply_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_news_in_course';
  $page->task = 'page';
  $page->admin_title = 'Course News';
  $page->admin_description = '';
  $page->path = 'course/news/%1/%2';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_news_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_news_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_news' => 'courses_news',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span11span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ccf54e63-a802-42c5-a47c-6dbd0a09f0b1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ca53d47b-7089-48db-87f3-9628022f8c0e';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_node_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ca53d47b-7089-48db-87f3-9628022f8c0e';
    $display->content['new-ca53d47b-7089-48db-87f3-9628022f8c0e'] = $pane;
    $display->panels['center'][0] = 'new-ca53d47b-7089-48db-87f3-9628022f8c0e';
    $pane = new stdClass();
    $pane->pid = 'new-2a40ca88-5d71-4fdb-bc5e-987f21650671';
    $pane->panel = 'center';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2a40ca88-5d71-4fdb-bc5e-987f21650671';
    $display->content['new-2a40ca88-5d71-4fdb-bc5e-987f21650671'] = $pane;
    $display->panels['center'][1] = 'new-2a40ca88-5d71-4fdb-bc5e-987f21650671';
    $pane = new stdClass();
    $pane->pid = 'new-04fb8609-d595-4ff0-b468-1ef9f9d2adbf';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '04fb8609-d595-4ff0-b468-1ef9f9d2adbf';
    $display->content['new-04fb8609-d595-4ff0-b468-1ef9f9d2adbf'] = $pane;
    $display->panels['tools'][0] = 'new-04fb8609-d595-4ff0-b468-1ef9f9d2adbf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2a40ca88-5d71-4fdb-bc5e-987f21650671';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_news_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_tasks_in_course';
  $page->task = 'page';
  $page->admin_title = 'Courses - Tasks';
  $page->admin_description = '';
  $page->path = 'course/tasks/%1';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_tasks_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_tasks_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'span8',
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
        'title' => 'Zentriert',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'span4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'Tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '67ab4d9d-b677-4ad6-baab-570f1a258047';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-faa80935-4478-4978-b08a-8aab669fa85a';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_tasks-panel_pane_1';
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
    $pane->uuid = 'faa80935-4478-4978-b08a-8aab669fa85a';
    $display->content['new-faa80935-4478-4978-b08a-8aab669fa85a'] = $pane;
    $display->panels['center'][0] = 'new-faa80935-4478-4978-b08a-8aab669fa85a';
    $pane = new stdClass();
    $pane->pid = 'new-215a0dff-7399-41ca-b51b-0f9796a99b78';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '215a0dff-7399-41ca-b51b-0f9796a99b78';
    $display->content['new-215a0dff-7399-41ca-b51b-0f9796a99b78'] = $pane;
    $display->panels['tools'][0] = 'new-215a0dff-7399-41ca-b51b-0f9796a99b78';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-faa80935-4478-4978-b08a-8aab669fa85a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_tasks_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'domain_text_in_course';
  $page->task = 'page';
  $page->admin_title = 'Studientext in: (Kurs)';
  $page->admin_description = '';
  $page->path = 'course/text/%1/%2';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    2 => array(
      'id' => 2,
      'identifier' => 'Beitrag: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_domain_text_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'domain_text_in_course';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Studientext in: %1',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'content_chapter' => 'content_chapter',
              'content_domain' => 'content_domain',
              'biblio' => 'biblio',
            ),
          ),
          'context' => 'argument_entity_id:node_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span3span8span1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'outline' => NULL,
      'tools' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ffc98fe6-ba93-439d-9ecc-5361724a98b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1ce494d9-ef6a-44cf-a7ee-33de7816ea21';
    $pane->panel = 'center';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1ce494d9-ef6a-44cf-a7ee-33de7816ea21';
    $display->content['new-1ce494d9-ef6a-44cf-a7ee-33de7816ea21'] = $pane;
    $display->panels['center'][0] = 'new-1ce494d9-ef6a-44cf-a7ee-33de7816ea21';
    $pane = new stdClass();
    $pane->pid = 'new-29a51e8b-ceea-41c7-9792-7f6c69ae29e2';
    $pane->panel = 'outline';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
return section_courses_text_outline();
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
    $pane->uuid = '29a51e8b-ceea-41c7-9792-7f6c69ae29e2';
    $display->content['new-29a51e8b-ceea-41c7-9792-7f6c69ae29e2'] = $pane;
    $display->panels['outline'][0] = 'new-29a51e8b-ceea-41c7-9792-7f6c69ae29e2';
    $pane = new stdClass();
    $pane->pid = 'new-e8e191af-4fe0-4c5b-b346-a45e13ce764a';
    $pane->panel = 'outline';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_text_biblio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e8e191af-4fe0-4c5b-b346-a45e13ce764a';
    $display->content['new-e8e191af-4fe0-4c5b-b346-a45e13ce764a'] = $pane;
    $display->panels['outline'][1] = 'new-e8e191af-4fe0-4c5b-b346-a45e13ce764a';
    $pane = new stdClass();
    $pane->pid = 'new-f389f198-77b3-4f41-9e93-9840ee989359';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f389f198-77b3-4f41-9e93-9840ee989359';
    $display->content['new-f389f198-77b3-4f41-9e93-9840ee989359'] = $pane;
    $display->panels['tools'][0] = 'new-f389f198-77b3-4f41-9e93-9840ee989359';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['domain_text_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kursdokumente_in_kurs_';
  $page->task = 'page';
  $page->admin_title = 'Kursdokumente in: (Kurs) ';
  $page->admin_description = '';
  $page->path = 'course/docs/%1';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_kursdokumente_in_kurs__panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kursdokumente_in_kurs_';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Kursdokumente in: (Kurs) ',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:span8span4';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'span8',
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
        'title' => 'Zentriert',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'span4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'Tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
      'news' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9450df7c-f226-43ca-9e96-73881536ace9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6e1434ed-0cb1-41f3-b1a2-8b740feafa99';
    $pane->panel = 'news';
    $pane->type = 'views_panes';
    $pane->subtype = 'courses_course_docs-panel_pane_1';
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
    $pane->uuid = '6e1434ed-0cb1-41f3-b1a2-8b740feafa99';
    $display->content['new-6e1434ed-0cb1-41f3-b1a2-8b740feafa99'] = $pane;
    $display->panels['news'][0] = 'new-6e1434ed-0cb1-41f3-b1a2-8b740feafa99';
    $pane = new stdClass();
    $pane->pid = 'new-27a332d2-41f9-456b-bfb7-f253ce97f57d';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '27a332d2-41f9-456b-bfb7-f253ce97f57d';
    $display->content['new-27a332d2-41f9-456b-bfb7-f253ce97f57d'] = $pane;
    $display->panels['tools'][0] = 'new-27a332d2-41f9-456b-bfb7-f253ce97f57d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6e1434ed-0cb1-41f3-b1a2-8b740feafa99';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kursdokumente_in_kurs_'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'members_in_course';
  $page->task = 'page';
  $page->admin_title = 'Mitglieder in: (Kurs)';
  $page->admin_description = '';
  $page->path = 'course/members/%1';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    1 => array(
      'id' => 1,
      'identifier' => 'Beitrag: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_members_in_course_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'members_in_course';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'courses_course' => 'courses_course',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 3,
          1 => 8,
        ),
        'parent' => 'canvas',
        'class' => 'span8',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'span4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tools',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'tools' => array(
        'type' => 'region',
        'title' => 'tools',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 4,
          1 => 5,
        ),
        'parent' => 'main',
        'class' => 'row-fluid',
      ),
      4 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 7,
        ),
        'class' => 'span6',
      ),
      5 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 6,
        ),
        'class' => 'span6',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right',
        ),
        'parent' => '5',
        'class' => '',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
        ),
        'parent' => '4',
        'class' => '',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => '',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'main_',
        ),
        'parent' => 'main',
        'class' => 'row-fluid',
      ),
      'main_' => array(
        'type' => 'region',
        'title' => 'main',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => 'span12',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'tools' => NULL,
      'news' => NULL,
      'left' => NULL,
      'right' => NULL,
      'main_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Teilnehmer';
  $display->uuid = 'd988ae1d-0774-48c6-b979-61a8e1862276';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-44abcc24-ffcd-4a11-9b62-dd8cd7483efc';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'courses_course_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_3',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Dozenten',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '44abcc24-ffcd-4a11-9b62-dd8cd7483efc';
    $display->content['new-44abcc24-ffcd-4a11-9b62-dd8cd7483efc'] = $pane;
    $display->panels['left'][0] = 'new-44abcc24-ffcd-4a11-9b62-dd8cd7483efc';
    $pane = new stdClass();
    $pane->pid = 'new-3964d7d2-29f5-46c6-9275-25ff2fa10946';
    $pane->panel = 'main_';
    $pane->type = 'views';
    $pane->subtype = 'courses_course_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Studenten',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3964d7d2-29f5-46c6-9275-25ff2fa10946';
    $display->content['new-3964d7d2-29f5-46c6-9275-25ff2fa10946'] = $pane;
    $display->panels['main_'][0] = 'new-3964d7d2-29f5-46c6-9275-25ff2fa10946';
    $pane = new stdClass();
    $pane->pid = 'new-dd6c312b-1a7f-4df1-8b5b-9281d2565e53';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'courses_course_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_4',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 1,
      'override_title_text' => 'Tutoren',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'dd6c312b-1a7f-4df1-8b5b-9281d2565e53';
    $display->content['new-dd6c312b-1a7f-4df1-8b5b-9281d2565e53'] = $pane;
    $display->panels['right'][0] = 'new-dd6c312b-1a7f-4df1-8b5b-9281d2565e53';
    $pane = new stdClass();
    $pane->pid = 'new-6f337849-945b-4ad2-a064-461283baf871';
    $pane->panel = 'tools';
    $pane->type = 'block';
    $pane->subtype = 'section_courses-course_instructors_tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6f337849-945b-4ad2-a064-461283baf871';
    $display->content['new-6f337849-945b-4ad2-a064-461283baf871'] = $pane;
    $display->panels['tools'][0] = 'new-6f337849-945b-4ad2-a064-461283baf871';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['members_in_course'] = $page;

  return $pages;

}
