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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
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
    $display->content['new-1'] = $pane;
    $display->panels['news'][0] = 'new-1';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2';
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
    $display->content['new-2'] = $pane;
    $display->panels['center'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
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
    $display->content['new-3'] = $pane;
    $display->panels['left'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
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
    $display->content['new-4'] = $pane;
    $display->panels['left'][1] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
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
    $display->content['new-5'] = $pane;
    $display->panels['left'][2] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
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
    $display->content['new-6'] = $pane;
    $display->panels['left'][3] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
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
    $display->content['new-7'] = $pane;
    $display->panels['right'][0] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
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
    $display->content['new-8'] = $pane;
    $display->panels['right'][1] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
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
    $display->content['new-9'] = $pane;
    $display->panels['right'][2] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
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
    $display->content['new-10'] = $pane;
    $display->panels['right'][3] = 'new-10';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-11';
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
    $display->content['new-11'] = $pane;
    $display->panels['center'][0] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
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
    $display->content['new-12'] = $pane;
    $display->panels['center'][1] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
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
    $display->content['new-13'] = $pane;
    $display->panels['left'][0] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
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
    $display->content['new-14'] = $pane;
    $display->panels['left'][1] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
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
    $display->content['new-15'] = $pane;
    $display->panels['left'][2] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
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
    $display->content['new-16'] = $pane;
    $display->panels['right'][0] = 'new-16';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-17';
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
    $display->content['new-17'] = $pane;
    $display->panels['center'][0] = 'new-17';
    $pane = new stdClass();
    $pane->pid = 'new-18';
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
    $display->content['new-18'] = $pane;
    $display->panels['left'][0] = 'new-18';
    $pane = new stdClass();
    $pane->pid = 'new-19';
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
    $display->content['new-19'] = $pane;
    $display->panels['left'][1] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
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
    $display->content['new-20'] = $pane;
    $display->panels['left'][2] = 'new-20';
    $pane = new stdClass();
    $pane->pid = 'new-21';
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
    $display->content['new-21'] = $pane;
    $display->panels['left'][3] = 'new-21';
    $pane = new stdClass();
    $pane->pid = 'new-22';
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
    $display->content['new-22'] = $pane;
    $display->panels['right'][0] = 'new-22';
    $pane = new stdClass();
    $pane->pid = 'new-23';
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
    $display->content['new-23'] = $pane;
    $display->panels['right'][1] = 'new-23';
    $pane = new stdClass();
    $pane->pid = 'new-24';
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
    $display->content['new-24'] = $pane;
    $display->panels['right'][2] = 'new-24';
    $pane = new stdClass();
    $pane->pid = 'new-25';
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
    $display->content['new-25'] = $pane;
    $display->panels['right'][3] = 'new-25';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
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
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
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
    $display->content['new-2'] = $pane;
    $display->panels['outline'][0] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
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
    $display->content['new-3'] = $pane;
    $display->panels['outline'][1] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
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
    $display->content['new-4'] = $pane;
    $display->panels['tools'][0] = 'new-4';
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
            0 => 3,
            1 => 19,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5';
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
    $display->content['new-5'] = $pane;
    $display->panels['center'][0] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
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
    $display->content['new-6'] = $pane;
    $display->panels['tools'][0] = 'new-6';
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
            0 => 3,
            1 => 19,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7';
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
    $display->content['new-7'] = $pane;
    $display->panels['center'][0] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
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
    $display->content['new-8'] = $pane;
    $display->panels['tools'][0] = 'new-8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9';
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
    $display->content['new-9'] = $pane;
    $display->panels['news'][0] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
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
    $display->content['new-10'] = $pane;
    $display->panels['tools'][0] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
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
    $display->content['new-11'] = $pane;
    $display->panels['tools'][1] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
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
    $display->content['new-12'] = $pane;
    $display->panels['tools'][2] = 'new-12';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-13';
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
    $display->content['new-13'] = $pane;
    $display->panels['news'][0] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
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
    $display->content['new-14'] = $pane;
    $display->panels['tools'][0] = 'new-14';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-13';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-15';
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
    $display->content['new-15'] = $pane;
    $display->panels['news'][0] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
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
    $display->content['new-16'] = $pane;
    $display->panels['news'][1] = 'new-16';
    $pane = new stdClass();
    $pane->pid = 'new-17';
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
    $display->content['new-17'] = $pane;
    $display->panels['tools'][0] = 'new-17';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-18';
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
    $display->content['new-18'] = $pane;
    $display->panels['news'][0] = 'new-18';
    $pane = new stdClass();
    $pane->pid = 'new-19';
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
    $display->content['new-19'] = $pane;
    $display->panels['news'][1] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
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
    $display->content['new-20'] = $pane;
    $display->panels['news'][2] = 'new-20';
    $pane = new stdClass();
    $pane->pid = 'new-21';
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
    $display->content['new-21'] = $pane;
    $display->panels['tools'][0] = 'new-21';
    $pane = new stdClass();
    $pane->pid = 'new-22';
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
    $display->content['new-22'] = $pane;
    $display->panels['tools'][1] = 'new-22';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-23';
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
    $display->content['new-23'] = $pane;
    $display->panels['content'][0] = 'new-23';
    $pane = new stdClass();
    $pane->pid = 'new-24';
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
    $display->content['new-24'] = $pane;
    $display->panels['links'][0] = 'new-24';
    $pane = new stdClass();
    $pane->pid = 'new-25';
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
    $display->content['new-25'] = $pane;
    $display->panels['links'][1] = 'new-25';
    $pane = new stdClass();
    $pane->pid = 'new-26';
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
    $display->content['new-26'] = $pane;
    $display->panels['links'][2] = 'new-26';
    $pane = new stdClass();
    $pane->pid = 'new-27';
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
    $display->content['new-27'] = $pane;
    $display->panels['links'][3] = 'new-27';
    $pane = new stdClass();
    $pane->pid = 'new-28';
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
    $display->content['new-28'] = $pane;
    $display->panels['links_'][0] = 'new-28';
    $pane = new stdClass();
    $pane->pid = 'new-29';
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
    $display->content['new-29'] = $pane;
    $display->panels['links_'][1] = 'new-29';
    $pane = new stdClass();
    $pane->pid = 'new-30';
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
    $display->content['new-30'] = $pane;
    $display->panels['links_'][2] = 'new-30';
    $pane = new stdClass();
    $pane->pid = 'new-31';
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
    $display->content['new-31'] = $pane;
    $display->panels['rechts'][0] = 'new-31';
    $pane = new stdClass();
    $pane->pid = 'new-32';
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
    $display->content['new-32'] = $pane;
    $display->panels['rechts_'][0] = 'new-32';
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
            0 => 3,
            1 => 19,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-33';
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
    $display->content['new-33'] = $pane;
    $display->panels['center'][0] = 'new-33';
    $pane = new stdClass();
    $pane->pid = 'new-34';
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
    $display->content['new-34'] = $pane;
    $display->panels['tools'][0] = 'new-34';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-33';
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
            0 => 3,
            1 => 19,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-35';
    $pane->panel = 'main_left';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_content';
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
      'args' => '%2/courses_news',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
        1 => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Ankündigungen',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-35'] = $pane;
    $display->panels['main_left'][0] = 'new-35';
    $pane = new stdClass();
    $pane->pid = 'new-36';
    $pane->panel = 'main_left';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_content';
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
      'args' => '%2/courses_generic_task',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
        1 => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Aufgaben',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-36'] = $pane;
    $display->panels['main_left'][1] = 'new-36';
    $pane = new stdClass();
    $pane->pid = 'new-37';
    $pane->panel = 'main_right';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_content';
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
      'args' => '%2/courses_docs',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
        1 => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Kursdokumente',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-37'] = $pane;
    $display->panels['main_right'][0] = 'new-37';
    $pane = new stdClass();
    $pane->pid = 'new-38';
    $pane->panel = 'main_right';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_content';
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
      'args' => '%2/forum',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
        1 => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Forenthemen',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-38'] = $pane;
    $display->panels['main_right'][1] = 'new-38';
    $pane = new stdClass();
    $pane->pid = 'new-39';
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
    $display->content['new-39'] = $pane;
    $display->panels['tools'][0] = 'new-39';
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
            0 => 3,
            1 => 19,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-40';
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
    $display->content['new-40'] = $pane;
    $display->panels['news'][0] = 'new-40';
    $pane = new stdClass();
    $pane->pid = 'new-41';
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
    $display->content['new-41'] = $pane;
    $display->panels['news'][1] = 'new-41';
    $pane = new stdClass();
    $pane->pid = 'new-42';
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
    $display->content['new-42'] = $pane;
    $display->panels['tools'][0] = 'new-42';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-41';
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
            0 => 3,
            1 => 20,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-43';
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
    $display->content['new-43'] = $pane;
    $display->panels['center'][0] = 'new-43';
    $pane = new stdClass();
    $pane->pid = 'new-44';
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
    $display->content['new-44'] = $pane;
    $display->panels['tools'][0] = 'new-44';
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
            0 => 3,
            1 => 19,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-45';
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
    $display->content['new-45'] = $pane;
    $display->panels['center'][0] = 'new-45';
    $pane = new stdClass();
    $pane->pid = 'new-46';
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
    $display->content['new-46'] = $pane;
    $display->panels['tools'][0] = 'new-46';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-45';
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
            0 => 3,
            1 => 19,
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-47';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
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
      'args' => '',
      'url' => '',
      'display' => 'bl_1',
      'context' => array(
        0 => '',
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
    $display->content['new-47'] = $pane;
    $display->panels['center'][0] = 'new-47';
    $pane = new stdClass();
    $pane->pid = 'new-48';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
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
      'args' => '',
      'url' => '',
      'display' => 'bl_2',
      'context' => array(
        0 => '',
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
    $display->content['new-48'] = $pane;
    $display->panels['center'][1] = 'new-48';
    $pane = new stdClass();
    $pane->pid = 'new-49';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
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
      'args' => '',
      'url' => '',
      'display' => 'bl_3',
      'context' => array(
        0 => '',
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
    $display->content['new-49'] = $pane;
    $display->panels['center'][2] = 'new-49';
    $pane = new stdClass();
    $pane->pid = 'new-50';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
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
      'args' => '',
      'url' => '',
      'display' => 'bl_4',
      'context' => array(
        0 => '',
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
    $display->content['new-50'] = $pane;
    $display->panels['center'][3] = 'new-50';
    $pane = new stdClass();
    $pane->pid = 'new-51';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
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
      'args' => '',
      'url' => '',
      'display' => 'bl_5',
      'context' => array(
        0 => '',
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
    $display->content['new-51'] = $pane;
    $display->panels['center'][4] = 'new-51';
    $pane = new stdClass();
    $pane->pid = 'new-52';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_admin_members';
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
      'args' => '',
      'url' => '',
      'display' => 'bl_6',
      'context' => array(
        0 => '',
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
    $display->content['new-52'] = $pane;
    $display->panels['center'][5] = 'new-52';
    $pane = new stdClass();
    $pane->pid = 'new-53';
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
    $display->content['new-53'] = $pane;
    $display->panels['tools'][0] = 'new-53';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-53';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-54';
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
    $display->content['new-54'] = $pane;
    $display->panels['news'][0] = 'new-54';
    $pane = new stdClass();
    $pane->pid = 'new-55';
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
    $display->content['new-55'] = $pane;
    $display->panels['tools'][0] = 'new-55';
    $pane = new stdClass();
    $pane->pid = 'new-56';
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
    $display->content['new-56'] = $pane;
    $display->panels['tools'][1] = 'new-56';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-54';
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
  $display->title = 'Kursübersicht';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-57';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'courses_kurse_bersicht';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
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
      'override_title_text' => 'Kurseübersicht',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-57'] = $pane;
    $display->panels['center'][0] = 'new-57';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-57';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-58';
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
    $display->content['new-58'] = $pane;
    $display->panels['center'][0] = 'new-58';
    $pane = new stdClass();
    $pane->pid = 'new-59';
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
    $display->content['new-59'] = $pane;
    $display->panels['center'][1] = 'new-59';
    $pane = new stdClass();
    $pane->pid = 'new-60';
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
    $display->content['new-60'] = $pane;
    $display->panels['center'][2] = 'new-60';
    $pane = new stdClass();
    $pane->pid = 'new-61';
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
    $display->content['new-61'] = $pane;
    $display->panels['center'][3] = 'new-61';
    $pane = new stdClass();
    $pane->pid = 'new-62';
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
    $display->content['new-62'] = $pane;
    $display->panels['center'][4] = 'new-62';
    $pane = new stdClass();
    $pane->pid = 'new-63';
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
    $display->content['new-63'] = $pane;
    $display->panels['tools'][0] = 'new-63';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-64';
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
    $display->content['new-64'] = $pane;
    $display->panels['center'][0] = 'new-64';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-64';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-65';
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
    $display->content['new-65'] = $pane;
    $display->panels['center'][0] = 'new-65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-65';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-66';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $display->content['new-66'] = $pane;
    $display->panels['center'][0] = 'new-66';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-66';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67';
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
    $display->content['new-67'] = $pane;
    $display->panels['center'][0] = 'new-67';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-67';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-68';
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
    $display->content['new-68'] = $pane;
    $display->panels['center'][0] = 'new-68';
    $pane = new stdClass();
    $pane->pid = 'new-69';
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
    $display->content['new-69'] = $pane;
    $display->panels['center'][1] = 'new-69';
    $pane = new stdClass();
    $pane->pid = 'new-70';
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
    $display->content['new-70'] = $pane;
    $display->panels['center'][2] = 'new-70';
    $pane = new stdClass();
    $pane->pid = 'new-71';
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
    $display->content['new-71'] = $pane;
    $display->panels['center'][3] = 'new-71';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-72';
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
    $display->content['new-72'] = $pane;
    $display->panels['center'][0] = 'new-72';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-73';
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
    $display->content['new-73'] = $pane;
    $display->panels['center'][0] = 'new-73';
    $pane = new stdClass();
    $pane->pid = 'new-74';
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
    $display->content['new-74'] = $pane;
    $display->panels['center'][1] = 'new-74';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-74';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-75';
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
    $display->content['new-75'] = $pane;
    $display->panels['center'][0] = 'new-75';
    $pane = new stdClass();
    $pane->pid = 'new-76';
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
    $display->content['new-76'] = $pane;
    $display->panels['tools'][0] = 'new-76';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-75';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-77';
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
    $display->content['new-77'] = $pane;
    $display->panels['center'][0] = 'new-77';
    $pane = new stdClass();
    $pane->pid = 'new-78';
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
    $display->content['new-78'] = $pane;
    $display->panels['outline'][0] = 'new-78';
    $pane = new stdClass();
    $pane->pid = 'new-79';
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
    $display->content['new-79'] = $pane;
    $display->panels['outline'][1] = 'new-79';
    $pane = new stdClass();
    $pane->pid = 'new-80';
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
    $display->content['new-80'] = $pane;
    $display->panels['tools'][0] = 'new-80';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-81';
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
    $display->content['new-81'] = $pane;
    $display->panels['news'][0] = 'new-81';
    $pane = new stdClass();
    $pane->pid = 'new-82';
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
    $display->content['new-82'] = $pane;
    $display->panels['tools'][0] = 'new-82';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-81';
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
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-83';
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
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_3',
      'context' => array(
        0 => '',
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
    $display->content['new-83'] = $pane;
    $display->panels['left'][0] = 'new-83';
    $pane = new stdClass();
    $pane->pid = 'new-84';
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
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'context' => array(
        0 => '',
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
    $display->content['new-84'] = $pane;
    $display->panels['main_'][0] = 'new-84';
    $pane = new stdClass();
    $pane->pid = 'new-85';
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
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_4',
      'context' => array(
        0 => '',
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
    $display->content['new-85'] = $pane;
    $display->panels['right'][0] = 'new-85';
    $pane = new stdClass();
    $pane->pid = 'new-86';
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
    $display->content['new-86'] = $pane;
    $display->panels['tools'][0] = 'new-86';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['members_in_course'] = $page;

  return $pages;

}
