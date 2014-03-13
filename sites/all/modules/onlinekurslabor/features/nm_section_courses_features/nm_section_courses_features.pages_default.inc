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
  $display->uuid = '4fe2dae8-3383-4596-afa7-a85009eab5e2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cf2f5c88-067d-4b95-8fcd-6108510be87d';
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
    $pane->uuid = 'cf2f5c88-067d-4b95-8fcd-6108510be87d';
    $display->content['new-cf2f5c88-067d-4b95-8fcd-6108510be87d'] = $pane;
    $display->panels['news'][0] = 'new-cf2f5c88-067d-4b95-8fcd-6108510be87d';
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
  $display->uuid = '8a2faa78-ac35-4840-8659-95c734515c5d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3b33852d-6afd-4173-870c-c344211453bb';
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
    $pane->uuid = '3b33852d-6afd-4173-870c-c344211453bb';
    $display->content['new-3b33852d-6afd-4173-870c-c344211453bb'] = $pane;
    $display->panels['center'][0] = 'new-3b33852d-6afd-4173-870c-c344211453bb';
    $pane = new stdClass();
    $pane->pid = 'new-8029a80f-8447-42f1-a1c5-bd26164b8046';
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
    $pane->uuid = '8029a80f-8447-42f1-a1c5-bd26164b8046';
    $display->content['new-8029a80f-8447-42f1-a1c5-bd26164b8046'] = $pane;
    $display->panels['left'][0] = 'new-8029a80f-8447-42f1-a1c5-bd26164b8046';
    $pane = new stdClass();
    $pane->pid = 'new-d8944c8f-5c19-4aa8-8423-87123677a585';
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
    $pane->uuid = 'd8944c8f-5c19-4aa8-8423-87123677a585';
    $display->content['new-d8944c8f-5c19-4aa8-8423-87123677a585'] = $pane;
    $display->panels['left'][1] = 'new-d8944c8f-5c19-4aa8-8423-87123677a585';
    $pane = new stdClass();
    $pane->pid = 'new-9d85f73a-6874-4f7c-80bd-1f417ad64aa8';
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
    $pane->uuid = '9d85f73a-6874-4f7c-80bd-1f417ad64aa8';
    $display->content['new-9d85f73a-6874-4f7c-80bd-1f417ad64aa8'] = $pane;
    $display->panels['left'][2] = 'new-9d85f73a-6874-4f7c-80bd-1f417ad64aa8';
    $pane = new stdClass();
    $pane->pid = 'new-29310576-eecf-4e5b-9b00-5cbcb629c2cb';
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
    $pane->uuid = '29310576-eecf-4e5b-9b00-5cbcb629c2cb';
    $display->content['new-29310576-eecf-4e5b-9b00-5cbcb629c2cb'] = $pane;
    $display->panels['left'][3] = 'new-29310576-eecf-4e5b-9b00-5cbcb629c2cb';
    $pane = new stdClass();
    $pane->pid = 'new-6304fc0f-70eb-4eb1-93b4-c51f2bab5ea0';
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
    $pane->uuid = '6304fc0f-70eb-4eb1-93b4-c51f2bab5ea0';
    $display->content['new-6304fc0f-70eb-4eb1-93b4-c51f2bab5ea0'] = $pane;
    $display->panels['right'][0] = 'new-6304fc0f-70eb-4eb1-93b4-c51f2bab5ea0';
    $pane = new stdClass();
    $pane->pid = 'new-e8c65cd1-8747-4168-9c86-caa5571d52b1';
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
    $pane->uuid = 'e8c65cd1-8747-4168-9c86-caa5571d52b1';
    $display->content['new-e8c65cd1-8747-4168-9c86-caa5571d52b1'] = $pane;
    $display->panels['right'][1] = 'new-e8c65cd1-8747-4168-9c86-caa5571d52b1';
    $pane = new stdClass();
    $pane->pid = 'new-ec9a0f57-540c-4c33-a796-8f5e31068fd6';
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
    $pane->uuid = 'ec9a0f57-540c-4c33-a796-8f5e31068fd6';
    $display->content['new-ec9a0f57-540c-4c33-a796-8f5e31068fd6'] = $pane;
    $display->panels['right'][2] = 'new-ec9a0f57-540c-4c33-a796-8f5e31068fd6';
    $pane = new stdClass();
    $pane->pid = 'new-6fa76f19-2640-4fb0-abd3-7f19098659de';
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
    $pane->uuid = '6fa76f19-2640-4fb0-abd3-7f19098659de';
    $display->content['new-6fa76f19-2640-4fb0-abd3-7f19098659de'] = $pane;
    $display->panels['right'][3] = 'new-6fa76f19-2640-4fb0-abd3-7f19098659de';
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
  $display->uuid = 'f0253675-8e44-4860-b6ff-29ae753167c1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e99dd3e-37df-437e-a9d6-2b818bfd4e5d';
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
    $pane->uuid = '8e99dd3e-37df-437e-a9d6-2b818bfd4e5d';
    $display->content['new-8e99dd3e-37df-437e-a9d6-2b818bfd4e5d'] = $pane;
    $display->panels['center'][0] = 'new-8e99dd3e-37df-437e-a9d6-2b818bfd4e5d';
    $pane = new stdClass();
    $pane->pid = 'new-d27c50a2-e049-4612-9748-154f09b14f09';
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
    $pane->uuid = 'd27c50a2-e049-4612-9748-154f09b14f09';
    $display->content['new-d27c50a2-e049-4612-9748-154f09b14f09'] = $pane;
    $display->panels['center'][1] = 'new-d27c50a2-e049-4612-9748-154f09b14f09';
    $pane = new stdClass();
    $pane->pid = 'new-68e515fa-d005-40f3-bd38-a3c0785cacb4';
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
    $pane->uuid = '68e515fa-d005-40f3-bd38-a3c0785cacb4';
    $display->content['new-68e515fa-d005-40f3-bd38-a3c0785cacb4'] = $pane;
    $display->panels['left'][0] = 'new-68e515fa-d005-40f3-bd38-a3c0785cacb4';
    $pane = new stdClass();
    $pane->pid = 'new-8ce4127e-5e74-44a1-a27d-4f798c44d56e';
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
    $pane->uuid = '8ce4127e-5e74-44a1-a27d-4f798c44d56e';
    $display->content['new-8ce4127e-5e74-44a1-a27d-4f798c44d56e'] = $pane;
    $display->panels['left'][1] = 'new-8ce4127e-5e74-44a1-a27d-4f798c44d56e';
    $pane = new stdClass();
    $pane->pid = 'new-2980b881-f91d-4c8e-b1e3-0f34e91bfba3';
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
    $pane->uuid = '2980b881-f91d-4c8e-b1e3-0f34e91bfba3';
    $display->content['new-2980b881-f91d-4c8e-b1e3-0f34e91bfba3'] = $pane;
    $display->panels['left'][2] = 'new-2980b881-f91d-4c8e-b1e3-0f34e91bfba3';
    $pane = new stdClass();
    $pane->pid = 'new-0c5df583-7dbe-4d55-8e58-7e4b160b053f';
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
    $pane->uuid = '0c5df583-7dbe-4d55-8e58-7e4b160b053f';
    $display->content['new-0c5df583-7dbe-4d55-8e58-7e4b160b053f'] = $pane;
    $display->panels['right'][0] = 'new-0c5df583-7dbe-4d55-8e58-7e4b160b053f';
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
  $display->uuid = 'c642a101-858f-4701-a26c-a2387761e3da';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5e717173-5739-4d54-ae59-7d138431e085';
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
    $pane->uuid = '5e717173-5739-4d54-ae59-7d138431e085';
    $display->content['new-5e717173-5739-4d54-ae59-7d138431e085'] = $pane;
    $display->panels['center'][0] = 'new-5e717173-5739-4d54-ae59-7d138431e085';
    $pane = new stdClass();
    $pane->pid = 'new-07bf2809-ca94-4a55-a46e-5bb35dffe2c0';
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
    $pane->uuid = '07bf2809-ca94-4a55-a46e-5bb35dffe2c0';
    $display->content['new-07bf2809-ca94-4a55-a46e-5bb35dffe2c0'] = $pane;
    $display->panels['left'][0] = 'new-07bf2809-ca94-4a55-a46e-5bb35dffe2c0';
    $pane = new stdClass();
    $pane->pid = 'new-9f9323f1-98a9-464b-81d4-d2b4cbc9becb';
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
    $pane->uuid = '9f9323f1-98a9-464b-81d4-d2b4cbc9becb';
    $display->content['new-9f9323f1-98a9-464b-81d4-d2b4cbc9becb'] = $pane;
    $display->panels['left'][1] = 'new-9f9323f1-98a9-464b-81d4-d2b4cbc9becb';
    $pane = new stdClass();
    $pane->pid = 'new-6b9f650b-4c20-43ff-a872-fdde6e27f1a0';
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
    $pane->uuid = '6b9f650b-4c20-43ff-a872-fdde6e27f1a0';
    $display->content['new-6b9f650b-4c20-43ff-a872-fdde6e27f1a0'] = $pane;
    $display->panels['left'][2] = 'new-6b9f650b-4c20-43ff-a872-fdde6e27f1a0';
    $pane = new stdClass();
    $pane->pid = 'new-6636f3d0-d5a1-4b55-97bb-9f076a367d52';
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
    $pane->uuid = '6636f3d0-d5a1-4b55-97bb-9f076a367d52';
    $display->content['new-6636f3d0-d5a1-4b55-97bb-9f076a367d52'] = $pane;
    $display->panels['left'][3] = 'new-6636f3d0-d5a1-4b55-97bb-9f076a367d52';
    $pane = new stdClass();
    $pane->pid = 'new-76fcbfb1-5f6a-425e-aae6-b573cd31d78c';
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
    $pane->uuid = '76fcbfb1-5f6a-425e-aae6-b573cd31d78c';
    $display->content['new-76fcbfb1-5f6a-425e-aae6-b573cd31d78c'] = $pane;
    $display->panels['right'][0] = 'new-76fcbfb1-5f6a-425e-aae6-b573cd31d78c';
    $pane = new stdClass();
    $pane->pid = 'new-f4a31a31-2c55-420d-9b29-f8f103bd56e5';
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
    $pane->uuid = 'f4a31a31-2c55-420d-9b29-f8f103bd56e5';
    $display->content['new-f4a31a31-2c55-420d-9b29-f8f103bd56e5'] = $pane;
    $display->panels['right'][1] = 'new-f4a31a31-2c55-420d-9b29-f8f103bd56e5';
    $pane = new stdClass();
    $pane->pid = 'new-8e3e2624-d407-45be-bc01-d73c01708ed1';
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
    $pane->uuid = '8e3e2624-d407-45be-bc01-d73c01708ed1';
    $display->content['new-8e3e2624-d407-45be-bc01-d73c01708ed1'] = $pane;
    $display->panels['right'][2] = 'new-8e3e2624-d407-45be-bc01-d73c01708ed1';
    $pane = new stdClass();
    $pane->pid = 'new-722e05de-e752-420c-b9ad-79882d840e53';
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
    $pane->uuid = '722e05de-e752-420c-b9ad-79882d840e53';
    $display->content['new-722e05de-e752-420c-b9ad-79882d840e53'] = $pane;
    $display->panels['right'][3] = 'new-722e05de-e752-420c-b9ad-79882d840e53';
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
  $display->uuid = '3c915959-73bc-4c7c-9a07-04aad8eae504';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b4f13f39-8a71-4d7c-9294-cbc29b189fba';
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
    $pane->uuid = 'b4f13f39-8a71-4d7c-9294-cbc29b189fba';
    $display->content['new-b4f13f39-8a71-4d7c-9294-cbc29b189fba'] = $pane;
    $display->panels['center'][0] = 'new-b4f13f39-8a71-4d7c-9294-cbc29b189fba';
    $pane = new stdClass();
    $pane->pid = 'new-48b78832-db94-4300-9fcf-7419065a642c';
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
    $pane->uuid = '48b78832-db94-4300-9fcf-7419065a642c';
    $display->content['new-48b78832-db94-4300-9fcf-7419065a642c'] = $pane;
    $display->panels['outline'][0] = 'new-48b78832-db94-4300-9fcf-7419065a642c';
    $pane = new stdClass();
    $pane->pid = 'new-54e74927-2130-433f-906e-b911e0052d1d';
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
    $pane->uuid = '54e74927-2130-433f-906e-b911e0052d1d';
    $display->content['new-54e74927-2130-433f-906e-b911e0052d1d'] = $pane;
    $display->panels['outline'][1] = 'new-54e74927-2130-433f-906e-b911e0052d1d';
    $pane = new stdClass();
    $pane->pid = 'new-4d311e41-3c67-4a29-95ff-225eaf302810';
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
    $pane->uuid = '4d311e41-3c67-4a29-95ff-225eaf302810';
    $display->content['new-4d311e41-3c67-4a29-95ff-225eaf302810'] = $pane;
    $display->panels['tools'][0] = 'new-4d311e41-3c67-4a29-95ff-225eaf302810';
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
  $display->uuid = '0e163902-24af-43bd-84ae-51b278acd60f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-973fc8aa-71a4-40f4-a4fb-f162c35f30fe';
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
    $pane->uuid = '973fc8aa-71a4-40f4-a4fb-f162c35f30fe';
    $display->content['new-973fc8aa-71a4-40f4-a4fb-f162c35f30fe'] = $pane;
    $display->panels['center'][0] = 'new-973fc8aa-71a4-40f4-a4fb-f162c35f30fe';
    $pane = new stdClass();
    $pane->pid = 'new-ddb8d52d-207f-4435-9416-75e306f5ac0e';
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
    $pane->uuid = 'ddb8d52d-207f-4435-9416-75e306f5ac0e';
    $display->content['new-ddb8d52d-207f-4435-9416-75e306f5ac0e'] = $pane;
    $display->panels['tools'][0] = 'new-ddb8d52d-207f-4435-9416-75e306f5ac0e';
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
  $display->uuid = '065b9452-1d1d-426f-846b-c70160ee0819';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e9263c69-a517-4aef-ae9e-b235bd3a2401';
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
    $pane->uuid = 'e9263c69-a517-4aef-ae9e-b235bd3a2401';
    $display->content['new-e9263c69-a517-4aef-ae9e-b235bd3a2401'] = $pane;
    $display->panels['news'][0] = 'new-e9263c69-a517-4aef-ae9e-b235bd3a2401';
    $pane = new stdClass();
    $pane->pid = 'new-3f9f4d94-f6d6-4d39-b613-7a39c87586f6';
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
    $pane->uuid = '3f9f4d94-f6d6-4d39-b613-7a39c87586f6';
    $display->content['new-3f9f4d94-f6d6-4d39-b613-7a39c87586f6'] = $pane;
    $display->panels['tools'][0] = 'new-3f9f4d94-f6d6-4d39-b613-7a39c87586f6';
    $pane = new stdClass();
    $pane->pid = 'new-82aacc52-acbc-492f-b910-086101b25a2e';
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
    $pane->uuid = '82aacc52-acbc-492f-b910-086101b25a2e';
    $display->content['new-82aacc52-acbc-492f-b910-086101b25a2e'] = $pane;
    $display->panels['tools'][1] = 'new-82aacc52-acbc-492f-b910-086101b25a2e';
    $pane = new stdClass();
    $pane->pid = 'new-4c20af77-8bc0-44d4-9e0b-c044874eeb60';
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
    $pane->uuid = '4c20af77-8bc0-44d4-9e0b-c044874eeb60';
    $display->content['new-4c20af77-8bc0-44d4-9e0b-c044874eeb60'] = $pane;
    $display->panels['tools'][2] = 'new-4c20af77-8bc0-44d4-9e0b-c044874eeb60';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e9263c69-a517-4aef-ae9e-b235bd3a2401';
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
  $display->uuid = 'f8422ad2-2fdd-4ece-98a9-faec314f6381';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-217ba9df-8175-418d-b122-7fe617368019';
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
    $pane->uuid = '217ba9df-8175-418d-b122-7fe617368019';
    $display->content['new-217ba9df-8175-418d-b122-7fe617368019'] = $pane;
    $display->panels['news'][0] = 'new-217ba9df-8175-418d-b122-7fe617368019';
    $pane = new stdClass();
    $pane->pid = 'new-974fc840-c6c8-495c-b38a-692b3d0c0791';
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
    $pane->uuid = '974fc840-c6c8-495c-b38a-692b3d0c0791';
    $display->content['new-974fc840-c6c8-495c-b38a-692b3d0c0791'] = $pane;
    $display->panels['tools'][0] = 'new-974fc840-c6c8-495c-b38a-692b3d0c0791';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-217ba9df-8175-418d-b122-7fe617368019';
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
  $display->uuid = '7ecd1f9e-caf5-468e-8558-a03fd9b62cd6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-56411ac5-2dc4-4cc7-9ff3-65c41d9c7863';
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
    $pane->uuid = '56411ac5-2dc4-4cc7-9ff3-65c41d9c7863';
    $display->content['new-56411ac5-2dc4-4cc7-9ff3-65c41d9c7863'] = $pane;
    $display->panels['news'][0] = 'new-56411ac5-2dc4-4cc7-9ff3-65c41d9c7863';
    $pane = new stdClass();
    $pane->pid = 'new-ccb875ef-7143-489b-8a94-802b60d05558';
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
    $pane->uuid = 'ccb875ef-7143-489b-8a94-802b60d05558';
    $display->content['new-ccb875ef-7143-489b-8a94-802b60d05558'] = $pane;
    $display->panels['news'][1] = 'new-ccb875ef-7143-489b-8a94-802b60d05558';
    $pane = new stdClass();
    $pane->pid = 'new-29a34fdf-4843-41ff-aed8-ec463c5f04a9';
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
    $pane->uuid = '29a34fdf-4843-41ff-aed8-ec463c5f04a9';
    $display->content['new-29a34fdf-4843-41ff-aed8-ec463c5f04a9'] = $pane;
    $display->panels['tools'][0] = 'new-29a34fdf-4843-41ff-aed8-ec463c5f04a9';
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
  $display->uuid = '5a9afba4-25d1-45dc-9c65-4db8e0798d82';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-60fd4492-445d-469e-b97b-aacaa255e8e6';
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
    $pane->uuid = '60fd4492-445d-469e-b97b-aacaa255e8e6';
    $display->content['new-60fd4492-445d-469e-b97b-aacaa255e8e6'] = $pane;
    $display->panels['news'][0] = 'new-60fd4492-445d-469e-b97b-aacaa255e8e6';
    $pane = new stdClass();
    $pane->pid = 'new-c5f77087-537d-451a-a588-8e8c53d35e71';
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
    $pane->uuid = 'c5f77087-537d-451a-a588-8e8c53d35e71';
    $display->content['new-c5f77087-537d-451a-a588-8e8c53d35e71'] = $pane;
    $display->panels['news'][1] = 'new-c5f77087-537d-451a-a588-8e8c53d35e71';
    $pane = new stdClass();
    $pane->pid = 'new-b0b83bf3-b30c-4e45-93a2-3fbc9959ef0c';
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
    $pane->uuid = 'b0b83bf3-b30c-4e45-93a2-3fbc9959ef0c';
    $display->content['new-b0b83bf3-b30c-4e45-93a2-3fbc9959ef0c'] = $pane;
    $display->panels['news'][2] = 'new-b0b83bf3-b30c-4e45-93a2-3fbc9959ef0c';
    $pane = new stdClass();
    $pane->pid = 'new-4dff5632-486b-44a3-a173-910b9cc2a15c';
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
    $pane->uuid = '4dff5632-486b-44a3-a173-910b9cc2a15c';
    $display->content['new-4dff5632-486b-44a3-a173-910b9cc2a15c'] = $pane;
    $display->panels['tools'][0] = 'new-4dff5632-486b-44a3-a173-910b9cc2a15c';
    $pane = new stdClass();
    $pane->pid = 'new-0f501fe6-726e-43df-a2cb-2a6656734f92';
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
    $pane->uuid = '0f501fe6-726e-43df-a2cb-2a6656734f92';
    $display->content['new-0f501fe6-726e-43df-a2cb-2a6656734f92'] = $pane;
    $display->panels['tools'][1] = 'new-0f501fe6-726e-43df-a2cb-2a6656734f92';
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
  $display->uuid = '80382ff5-bb58-4246-84c6-4ab41d41c55b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0c728995-51fc-4269-8d15-bbc63d1ba02b';
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
    $pane->uuid = '0c728995-51fc-4269-8d15-bbc63d1ba02b';
    $display->content['new-0c728995-51fc-4269-8d15-bbc63d1ba02b'] = $pane;
    $display->panels['content'][0] = 'new-0c728995-51fc-4269-8d15-bbc63d1ba02b';
    $pane = new stdClass();
    $pane->pid = 'new-35447870-9aeb-4a61-862c-db8189be0ccb';
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
    $pane->uuid = '35447870-9aeb-4a61-862c-db8189be0ccb';
    $display->content['new-35447870-9aeb-4a61-862c-db8189be0ccb'] = $pane;
    $display->panels['links'][0] = 'new-35447870-9aeb-4a61-862c-db8189be0ccb';
    $pane = new stdClass();
    $pane->pid = 'new-c0259f76-1f49-497a-9c93-18968f8f827d';
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
    $pane->uuid = 'c0259f76-1f49-497a-9c93-18968f8f827d';
    $display->content['new-c0259f76-1f49-497a-9c93-18968f8f827d'] = $pane;
    $display->panels['links'][1] = 'new-c0259f76-1f49-497a-9c93-18968f8f827d';
    $pane = new stdClass();
    $pane->pid = 'new-34a86de2-9ec4-41b4-ab2f-90e2ee592043';
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
    $pane->uuid = '34a86de2-9ec4-41b4-ab2f-90e2ee592043';
    $display->content['new-34a86de2-9ec4-41b4-ab2f-90e2ee592043'] = $pane;
    $display->panels['links'][2] = 'new-34a86de2-9ec4-41b4-ab2f-90e2ee592043';
    $pane = new stdClass();
    $pane->pid = 'new-d0b6c1ab-007d-45da-a972-0c79d0141f7d';
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
    $pane->uuid = 'd0b6c1ab-007d-45da-a972-0c79d0141f7d';
    $display->content['new-d0b6c1ab-007d-45da-a972-0c79d0141f7d'] = $pane;
    $display->panels['links'][3] = 'new-d0b6c1ab-007d-45da-a972-0c79d0141f7d';
    $pane = new stdClass();
    $pane->pid = 'new-b9134913-b0cc-46b8-a9de-374b5556df64';
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
    $pane->uuid = 'b9134913-b0cc-46b8-a9de-374b5556df64';
    $display->content['new-b9134913-b0cc-46b8-a9de-374b5556df64'] = $pane;
    $display->panels['links_'][0] = 'new-b9134913-b0cc-46b8-a9de-374b5556df64';
    $pane = new stdClass();
    $pane->pid = 'new-bf9bcd9d-096a-4452-9d66-896d6a7d6a7d';
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
    $pane->uuid = 'bf9bcd9d-096a-4452-9d66-896d6a7d6a7d';
    $display->content['new-bf9bcd9d-096a-4452-9d66-896d6a7d6a7d'] = $pane;
    $display->panels['links_'][1] = 'new-bf9bcd9d-096a-4452-9d66-896d6a7d6a7d';
    $pane = new stdClass();
    $pane->pid = 'new-a50c783d-d6a9-496a-8176-5b5cf53ac9f0';
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
    $pane->uuid = 'a50c783d-d6a9-496a-8176-5b5cf53ac9f0';
    $display->content['new-a50c783d-d6a9-496a-8176-5b5cf53ac9f0'] = $pane;
    $display->panels['links_'][2] = 'new-a50c783d-d6a9-496a-8176-5b5cf53ac9f0';
    $pane = new stdClass();
    $pane->pid = 'new-91c50639-ea96-4f8a-a3aa-ab47d35151e2';
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
    $pane->uuid = '91c50639-ea96-4f8a-a3aa-ab47d35151e2';
    $display->content['new-91c50639-ea96-4f8a-a3aa-ab47d35151e2'] = $pane;
    $display->panels['rechts'][0] = 'new-91c50639-ea96-4f8a-a3aa-ab47d35151e2';
    $pane = new stdClass();
    $pane->pid = 'new-92166c45-90f5-4d41-a42a-d122a6ab7980';
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
    $pane->uuid = '92166c45-90f5-4d41-a42a-d122a6ab7980';
    $display->content['new-92166c45-90f5-4d41-a42a-d122a6ab7980'] = $pane;
    $display->panels['rechts_'][0] = 'new-92166c45-90f5-4d41-a42a-d122a6ab7980';
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
  $display->uuid = '733da025-d045-4b8f-81f0-1863e2266b4a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-facc5cc5-5a1b-4bbc-ab58-57cd021a0d05';
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
    $pane->uuid = 'facc5cc5-5a1b-4bbc-ab58-57cd021a0d05';
    $display->content['new-facc5cc5-5a1b-4bbc-ab58-57cd021a0d05'] = $pane;
    $display->panels['center'][0] = 'new-facc5cc5-5a1b-4bbc-ab58-57cd021a0d05';
    $pane = new stdClass();
    $pane->pid = 'new-98409b31-5f57-4efd-9161-372495730abd';
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
    $pane->uuid = '98409b31-5f57-4efd-9161-372495730abd';
    $display->content['new-98409b31-5f57-4efd-9161-372495730abd'] = $pane;
    $display->panels['tools'][0] = 'new-98409b31-5f57-4efd-9161-372495730abd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-facc5cc5-5a1b-4bbc-ab58-57cd021a0d05';
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
  $display->uuid = 'a418ea3b-a90e-4d5f-928a-aeca4b4a839a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-86233bdc-f08c-4172-b588-401b6102a408';
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
    $pane->uuid = '86233bdc-f08c-4172-b588-401b6102a408';
    $display->content['new-86233bdc-f08c-4172-b588-401b6102a408'] = $pane;
    $display->panels['news'][0] = 'new-86233bdc-f08c-4172-b588-401b6102a408';
    $pane = new stdClass();
    $pane->pid = 'new-9059de55-c19e-4935-8246-e0ac9baafa07';
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
    $pane->uuid = '9059de55-c19e-4935-8246-e0ac9baafa07';
    $display->content['new-9059de55-c19e-4935-8246-e0ac9baafa07'] = $pane;
    $display->panels['news'][1] = 'new-9059de55-c19e-4935-8246-e0ac9baafa07';
    $pane = new stdClass();
    $pane->pid = 'new-e6ae0385-0329-4dd2-bd11-3283823e776c';
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
    $pane->uuid = 'e6ae0385-0329-4dd2-bd11-3283823e776c';
    $display->content['new-e6ae0385-0329-4dd2-bd11-3283823e776c'] = $pane;
    $display->panels['tools'][0] = 'new-e6ae0385-0329-4dd2-bd11-3283823e776c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9059de55-c19e-4935-8246-e0ac9baafa07';
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
  $display->uuid = 'e6d11755-7c12-48d5-8d30-3eeddf0e2af1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6eb2a8bf-788c-4a98-96f0-21f3dc2c5d80';
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
    $pane->uuid = '6eb2a8bf-788c-4a98-96f0-21f3dc2c5d80';
    $display->content['new-6eb2a8bf-788c-4a98-96f0-21f3dc2c5d80'] = $pane;
    $display->panels['center'][0] = 'new-6eb2a8bf-788c-4a98-96f0-21f3dc2c5d80';
    $pane = new stdClass();
    $pane->pid = 'new-d19024d1-ce3f-46e1-ba4e-7e5b5bc58550';
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
    $pane->uuid = 'd19024d1-ce3f-46e1-ba4e-7e5b5bc58550';
    $display->content['new-d19024d1-ce3f-46e1-ba4e-7e5b5bc58550'] = $pane;
    $display->panels['tools'][0] = 'new-d19024d1-ce3f-46e1-ba4e-7e5b5bc58550';
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
  $display->uuid = 'baeaa68e-14a0-48b4-837c-2a332e56a668';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6cc7841a-0b48-4602-9e20-931150f7192b';
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
    $pane->uuid = '6cc7841a-0b48-4602-9e20-931150f7192b';
    $display->content['new-6cc7841a-0b48-4602-9e20-931150f7192b'] = $pane;
    $display->panels['center'][0] = 'new-6cc7841a-0b48-4602-9e20-931150f7192b';
    $pane = new stdClass();
    $pane->pid = 'new-9f0508bc-10ba-4bd5-af46-8185745ee60c';
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
    $pane->uuid = '9f0508bc-10ba-4bd5-af46-8185745ee60c';
    $display->content['new-9f0508bc-10ba-4bd5-af46-8185745ee60c'] = $pane;
    $display->panels['tools'][0] = 'new-9f0508bc-10ba-4bd5-af46-8185745ee60c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6cc7841a-0b48-4602-9e20-931150f7192b';
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
  $display->uuid = '3fd44b9d-29a3-466e-9b82-3c26d452dfbd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f28e2e89-8ea0-4e47-b070-49bf78163174';
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
    $pane->uuid = 'f28e2e89-8ea0-4e47-b070-49bf78163174';
    $display->content['new-f28e2e89-8ea0-4e47-b070-49bf78163174'] = $pane;
    $display->panels['news'][0] = 'new-f28e2e89-8ea0-4e47-b070-49bf78163174';
    $pane = new stdClass();
    $pane->pid = 'new-b95ffa6f-38a1-45fe-97cd-f38683e42613';
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
    $pane->uuid = 'b95ffa6f-38a1-45fe-97cd-f38683e42613';
    $display->content['new-b95ffa6f-38a1-45fe-97cd-f38683e42613'] = $pane;
    $display->panels['tools'][0] = 'new-b95ffa6f-38a1-45fe-97cd-f38683e42613';
    $pane = new stdClass();
    $pane->pid = 'new-b0b96b4b-aebf-41a4-8446-a4099fecf466';
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
    $pane->uuid = 'b0b96b4b-aebf-41a4-8446-a4099fecf466';
    $display->content['new-b0b96b4b-aebf-41a4-8446-a4099fecf466'] = $pane;
    $display->panels['tools'][1] = 'new-b0b96b4b-aebf-41a4-8446-a4099fecf466';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f28e2e89-8ea0-4e47-b070-49bf78163174';
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
  $display->uuid = 'd53c3cc7-14b7-4d06-bcbc-a8bbfd6628c5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e14e481e-a4a4-4aab-9d40-a8fca58396b2';
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
    $pane->uuid = 'e14e481e-a4a4-4aab-9d40-a8fca58396b2';
    $display->content['new-e14e481e-a4a4-4aab-9d40-a8fca58396b2'] = $pane;
    $display->panels['center'][0] = 'new-e14e481e-a4a4-4aab-9d40-a8fca58396b2';
    $pane = new stdClass();
    $pane->pid = 'new-4b9621af-f19a-482c-a2d7-72ae66093254';
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
    $pane->uuid = '4b9621af-f19a-482c-a2d7-72ae66093254';
    $display->content['new-4b9621af-f19a-482c-a2d7-72ae66093254'] = $pane;
    $display->panels['center'][1] = 'new-4b9621af-f19a-482c-a2d7-72ae66093254';
    $pane = new stdClass();
    $pane->pid = 'new-a43222b7-9e55-4b60-9e41-b1660e00010c';
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
    $pane->uuid = 'a43222b7-9e55-4b60-9e41-b1660e00010c';
    $display->content['new-a43222b7-9e55-4b60-9e41-b1660e00010c'] = $pane;
    $display->panels['center'][2] = 'new-a43222b7-9e55-4b60-9e41-b1660e00010c';
    $pane = new stdClass();
    $pane->pid = 'new-d1ddc2f6-5ee0-4710-bde0-25d9cc9a8004';
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
    $pane->uuid = 'd1ddc2f6-5ee0-4710-bde0-25d9cc9a8004';
    $display->content['new-d1ddc2f6-5ee0-4710-bde0-25d9cc9a8004'] = $pane;
    $display->panels['center'][3] = 'new-d1ddc2f6-5ee0-4710-bde0-25d9cc9a8004';
    $pane = new stdClass();
    $pane->pid = 'new-7fcebac2-371a-473a-9639-ffa2d0b2152c';
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
    $pane->uuid = '7fcebac2-371a-473a-9639-ffa2d0b2152c';
    $display->content['new-7fcebac2-371a-473a-9639-ffa2d0b2152c'] = $pane;
    $display->panels['center'][4] = 'new-7fcebac2-371a-473a-9639-ffa2d0b2152c';
    $pane = new stdClass();
    $pane->pid = 'new-d899665a-8768-49a1-97eb-c36daae349b5';
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
    $pane->uuid = 'd899665a-8768-49a1-97eb-c36daae349b5';
    $display->content['new-d899665a-8768-49a1-97eb-c36daae349b5'] = $pane;
    $display->panels['tools'][0] = 'new-d899665a-8768-49a1-97eb-c36daae349b5';
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
  $display->uuid = 'df0a6537-e4bb-42da-aebd-4ac78cb19b4a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce59f241-51c5-4407-a5ab-c5332d77d8c8';
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
    $pane->uuid = 'ce59f241-51c5-4407-a5ab-c5332d77d8c8';
    $display->content['new-ce59f241-51c5-4407-a5ab-c5332d77d8c8'] = $pane;
    $display->panels['center'][0] = 'new-ce59f241-51c5-4407-a5ab-c5332d77d8c8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ce59f241-51c5-4407-a5ab-c5332d77d8c8';
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
  $display->uuid = '3c7f95d3-96c6-4400-b6e8-731b1261c9cc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f132dd08-be90-41ef-90a2-668c405c58e4';
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
    $pane->uuid = 'f132dd08-be90-41ef-90a2-668c405c58e4';
    $display->content['new-f132dd08-be90-41ef-90a2-668c405c58e4'] = $pane;
    $display->panels['center'][0] = 'new-f132dd08-be90-41ef-90a2-668c405c58e4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f132dd08-be90-41ef-90a2-668c405c58e4';
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
  $display->uuid = 'c24637a9-b859-4406-81dd-800fedd2eff4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2706ff80-9a6e-4e8f-a74e-480604063193';
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
    $pane->uuid = '2706ff80-9a6e-4e8f-a74e-480604063193';
    $display->content['new-2706ff80-9a6e-4e8f-a74e-480604063193'] = $pane;
    $display->panels['center'][0] = 'new-2706ff80-9a6e-4e8f-a74e-480604063193';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2706ff80-9a6e-4e8f-a74e-480604063193';
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
  $display->uuid = 'd20f3a7c-7cae-4682-8074-f54ea8b863b9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5faf7b96-4411-40c2-8d38-36b74950ce5b';
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
    $pane->uuid = '5faf7b96-4411-40c2-8d38-36b74950ce5b';
    $display->content['new-5faf7b96-4411-40c2-8d38-36b74950ce5b'] = $pane;
    $display->panels['center'][0] = 'new-5faf7b96-4411-40c2-8d38-36b74950ce5b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5faf7b96-4411-40c2-8d38-36b74950ce5b';
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
  $display->uuid = '2dc67777-7c2a-4c69-800f-596cdbbe66a5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-75753f56-9781-459a-b49d-7d8e69a1083a';
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
    $pane->uuid = '75753f56-9781-459a-b49d-7d8e69a1083a';
    $display->content['new-75753f56-9781-459a-b49d-7d8e69a1083a'] = $pane;
    $display->panels['center'][0] = 'new-75753f56-9781-459a-b49d-7d8e69a1083a';
    $pane = new stdClass();
    $pane->pid = 'new-bf366d88-1c5e-4758-aa22-5b3d97d2b95c';
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
    $pane->uuid = 'bf366d88-1c5e-4758-aa22-5b3d97d2b95c';
    $display->content['new-bf366d88-1c5e-4758-aa22-5b3d97d2b95c'] = $pane;
    $display->panels['center'][1] = 'new-bf366d88-1c5e-4758-aa22-5b3d97d2b95c';
    $pane = new stdClass();
    $pane->pid = 'new-b68cc929-aa26-4be0-951d-7f8ee1583471';
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
    $pane->uuid = 'b68cc929-aa26-4be0-951d-7f8ee1583471';
    $display->content['new-b68cc929-aa26-4be0-951d-7f8ee1583471'] = $pane;
    $display->panels['center'][2] = 'new-b68cc929-aa26-4be0-951d-7f8ee1583471';
    $pane = new stdClass();
    $pane->pid = 'new-d3262fa1-eda6-4f93-a6db-7a6f8c786f57';
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
    $pane->uuid = 'd3262fa1-eda6-4f93-a6db-7a6f8c786f57';
    $display->content['new-d3262fa1-eda6-4f93-a6db-7a6f8c786f57'] = $pane;
    $display->panels['center'][3] = 'new-d3262fa1-eda6-4f93-a6db-7a6f8c786f57';
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
  $display->uuid = '66b38e68-9373-40c6-8806-157f862160c9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0dba2b9d-e5c2-466a-a334-a96b4fba23f9';
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
    $pane->uuid = '0dba2b9d-e5c2-466a-a334-a96b4fba23f9';
    $display->content['new-0dba2b9d-e5c2-466a-a334-a96b4fba23f9'] = $pane;
    $display->panels['center'][0] = 'new-0dba2b9d-e5c2-466a-a334-a96b4fba23f9';
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
  $display->uuid = '5b22c4b2-8171-4f8f-93f6-3fc417beb591';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67974069-e8bd-49b4-8a71-d70bdc42332e';
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
    $pane->uuid = '67974069-e8bd-49b4-8a71-d70bdc42332e';
    $display->content['new-67974069-e8bd-49b4-8a71-d70bdc42332e'] = $pane;
    $display->panels['center'][0] = 'new-67974069-e8bd-49b4-8a71-d70bdc42332e';
    $pane = new stdClass();
    $pane->pid = 'new-4392be1d-c486-4780-bfd1-c86822d27e32';
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
    $pane->uuid = '4392be1d-c486-4780-bfd1-c86822d27e32';
    $display->content['new-4392be1d-c486-4780-bfd1-c86822d27e32'] = $pane;
    $display->panels['center'][1] = 'new-4392be1d-c486-4780-bfd1-c86822d27e32';
    $pane = new stdClass();
    $pane->pid = 'new-03abb020-f21d-4f19-9499-721c1ee99161';
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
    $pane->uuid = '03abb020-f21d-4f19-9499-721c1ee99161';
    $display->content['new-03abb020-f21d-4f19-9499-721c1ee99161'] = $pane;
    $display->panels['tools'][0] = 'new-03abb020-f21d-4f19-9499-721c1ee99161';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4392be1d-c486-4780-bfd1-c86822d27e32';
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
  $display->uuid = 'a2cf8c0b-4370-4462-83f0-c868eedb4f78';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f1df5112-91b3-42c3-9716-d4ab76496dd3';
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
    $pane->uuid = 'f1df5112-91b3-42c3-9716-d4ab76496dd3';
    $display->content['new-f1df5112-91b3-42c3-9716-d4ab76496dd3'] = $pane;
    $display->panels['center'][0] = 'new-f1df5112-91b3-42c3-9716-d4ab76496dd3';
    $pane = new stdClass();
    $pane->pid = 'new-9dca3f8a-8e5f-4eb8-a96a-f1b1b3b0a8be';
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
    $pane->uuid = '9dca3f8a-8e5f-4eb8-a96a-f1b1b3b0a8be';
    $display->content['new-9dca3f8a-8e5f-4eb8-a96a-f1b1b3b0a8be'] = $pane;
    $display->panels['tools'][0] = 'new-9dca3f8a-8e5f-4eb8-a96a-f1b1b3b0a8be';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f1df5112-91b3-42c3-9716-d4ab76496dd3';
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
  $display->uuid = '4cef1c21-6f8f-40bf-8998-61a531fd47e5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ff7f5d68-2df2-409b-97a6-3bd68d8450e5';
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
    $pane->uuid = 'ff7f5d68-2df2-409b-97a6-3bd68d8450e5';
    $display->content['new-ff7f5d68-2df2-409b-97a6-3bd68d8450e5'] = $pane;
    $display->panels['center'][0] = 'new-ff7f5d68-2df2-409b-97a6-3bd68d8450e5';
    $pane = new stdClass();
    $pane->pid = 'new-109ca971-813d-4662-aa9d-c3db09639ad8';
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
    $pane->uuid = '109ca971-813d-4662-aa9d-c3db09639ad8';
    $display->content['new-109ca971-813d-4662-aa9d-c3db09639ad8'] = $pane;
    $display->panels['outline'][0] = 'new-109ca971-813d-4662-aa9d-c3db09639ad8';
    $pane = new stdClass();
    $pane->pid = 'new-830b477d-a2a5-4da4-aa04-8b0f54a42a6b';
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
    $pane->uuid = '830b477d-a2a5-4da4-aa04-8b0f54a42a6b';
    $display->content['new-830b477d-a2a5-4da4-aa04-8b0f54a42a6b'] = $pane;
    $display->panels['outline'][1] = 'new-830b477d-a2a5-4da4-aa04-8b0f54a42a6b';
    $pane = new stdClass();
    $pane->pid = 'new-ca8cbced-b1df-451a-bad5-53a3d7950466';
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
    $pane->uuid = 'ca8cbced-b1df-451a-bad5-53a3d7950466';
    $display->content['new-ca8cbced-b1df-451a-bad5-53a3d7950466'] = $pane;
    $display->panels['tools'][0] = 'new-ca8cbced-b1df-451a-bad5-53a3d7950466';
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
  $display->uuid = '37eec56e-ae93-4f7a-8bca-dc57ce25e40a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-837e9449-4fbc-4a2b-a798-b4e61af74e5e';
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
    $pane->uuid = '837e9449-4fbc-4a2b-a798-b4e61af74e5e';
    $display->content['new-837e9449-4fbc-4a2b-a798-b4e61af74e5e'] = $pane;
    $display->panels['news'][0] = 'new-837e9449-4fbc-4a2b-a798-b4e61af74e5e';
    $pane = new stdClass();
    $pane->pid = 'new-5f3a8238-2671-4ddb-b87e-bf7028e99262';
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
    $pane->uuid = '5f3a8238-2671-4ddb-b87e-bf7028e99262';
    $display->content['new-5f3a8238-2671-4ddb-b87e-bf7028e99262'] = $pane;
    $display->panels['tools'][0] = 'new-5f3a8238-2671-4ddb-b87e-bf7028e99262';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-837e9449-4fbc-4a2b-a798-b4e61af74e5e';
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
