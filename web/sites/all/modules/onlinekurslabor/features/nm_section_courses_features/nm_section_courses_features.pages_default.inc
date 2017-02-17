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
  $display->uuid = 'bae68106-8056-4354-aadf-8d646dd29a98';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_edit_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-df961a10-10be-4faa-a01d-ca9f92c26ebf';
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
  $pane->uuid = 'df961a10-10be-4faa-a01d-ca9f92c26ebf';
  $display->content['new-df961a10-10be-4faa-a01d-ca9f92c26ebf'] = $pane;
  $display->panels['news'][0] = 'new-df961a10-10be-4faa-a01d-ca9f92c26ebf';
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
    'relationships' => array(),
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
  $display->uuid = 'e5d28afc-8c87-4207-bde9-49f7826ec6d2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-90b30581-91b8-4240-90ea-2fed182a3d79';
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
  $pane->uuid = '90b30581-91b8-4240-90ea-2fed182a3d79';
  $display->content['new-90b30581-91b8-4240-90ea-2fed182a3d79'] = $pane;
  $display->panels['center'][0] = 'new-90b30581-91b8-4240-90ea-2fed182a3d79';
  $pane = new stdClass();
  $pane->pid = 'new-e6efca4b-7261-40eb-911c-470487862428';
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
  $pane->uuid = 'e6efca4b-7261-40eb-911c-470487862428';
  $display->content['new-e6efca4b-7261-40eb-911c-470487862428'] = $pane;
  $display->panels['left'][0] = 'new-e6efca4b-7261-40eb-911c-470487862428';
  $pane = new stdClass();
  $pane->pid = 'new-040d7151-b887-4283-83cc-002f8dee1ee7';
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
  $pane->uuid = '040d7151-b887-4283-83cc-002f8dee1ee7';
  $display->content['new-040d7151-b887-4283-83cc-002f8dee1ee7'] = $pane;
  $display->panels['left'][1] = 'new-040d7151-b887-4283-83cc-002f8dee1ee7';
  $pane = new stdClass();
  $pane->pid = 'new-35ad4056-6b4f-456a-8b63-ca4a825990d8';
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
  $pane->uuid = '35ad4056-6b4f-456a-8b63-ca4a825990d8';
  $display->content['new-35ad4056-6b4f-456a-8b63-ca4a825990d8'] = $pane;
  $display->panels['left'][2] = 'new-35ad4056-6b4f-456a-8b63-ca4a825990d8';
  $pane = new stdClass();
  $pane->pid = 'new-11ece18e-0ecb-4673-a6c7-44c6224efc33';
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
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => 'Meine Kurse',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
    ),
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
  $pane->uuid = '11ece18e-0ecb-4673-a6c7-44c6224efc33';
  $display->content['new-11ece18e-0ecb-4673-a6c7-44c6224efc33'] = $pane;
  $display->panels['left'][3] = 'new-11ece18e-0ecb-4673-a6c7-44c6224efc33';
  $pane = new stdClass();
  $pane->pid = 'new-5020e69c-0387-488d-8699-1e0a1e76958a';
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
  $pane->uuid = '5020e69c-0387-488d-8699-1e0a1e76958a';
  $display->content['new-5020e69c-0387-488d-8699-1e0a1e76958a'] = $pane;
  $display->panels['right'][0] = 'new-5020e69c-0387-488d-8699-1e0a1e76958a';
  $pane = new stdClass();
  $pane->pid = 'new-de2a8900-4d23-4638-bfcb-66acdb97a97a';
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
  $pane->uuid = 'de2a8900-4d23-4638-bfcb-66acdb97a97a';
  $display->content['new-de2a8900-4d23-4638-bfcb-66acdb97a97a'] = $pane;
  $display->panels['right'][1] = 'new-de2a8900-4d23-4638-bfcb-66acdb97a97a';
  $pane = new stdClass();
  $pane->pid = 'new-e73f16bd-a90f-452b-aa71-2fb5d821ccce';
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
  $pane->uuid = 'e73f16bd-a90f-452b-aa71-2fb5d821ccce';
  $display->content['new-e73f16bd-a90f-452b-aa71-2fb5d821ccce'] = $pane;
  $display->panels['right'][2] = 'new-e73f16bd-a90f-452b-aa71-2fb5d821ccce';
  $pane = new stdClass();
  $pane->pid = 'new-1e7cf0b7-9996-4461-b157-3063bdfc780f';
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
  $pane->uuid = '1e7cf0b7-9996-4461-b157-3063bdfc780f';
  $display->content['new-1e7cf0b7-9996-4461-b157-3063bdfc780f'] = $pane;
  $display->panels['right'][3] = 'new-1e7cf0b7-9996-4461-b157-3063bdfc780f';
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
  $display->uuid = '19615f50-db07-48c7-9e98-57cc97e70488';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a2575693-1fe6-4861-9255-b43af73ddb43';
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
  $pane->uuid = 'a2575693-1fe6-4861-9255-b43af73ddb43';
  $display->content['new-a2575693-1fe6-4861-9255-b43af73ddb43'] = $pane;
  $display->panels['center'][0] = 'new-a2575693-1fe6-4861-9255-b43af73ddb43';
  $pane = new stdClass();
  $pane->pid = 'new-a8053283-21d4-4e08-98cd-e3b31a98bc70';
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
  $pane->uuid = 'a8053283-21d4-4e08-98cd-e3b31a98bc70';
  $display->content['new-a8053283-21d4-4e08-98cd-e3b31a98bc70'] = $pane;
  $display->panels['center'][1] = 'new-a8053283-21d4-4e08-98cd-e3b31a98bc70';
  $pane = new stdClass();
  $pane->pid = 'new-730e1093-d789-4603-bca8-364bdec23d77';
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
  $pane->uuid = '730e1093-d789-4603-bca8-364bdec23d77';
  $display->content['new-730e1093-d789-4603-bca8-364bdec23d77'] = $pane;
  $display->panels['left'][0] = 'new-730e1093-d789-4603-bca8-364bdec23d77';
  $pane = new stdClass();
  $pane->pid = 'new-5d4162ea-bcfa-400b-b4f6-8c5280ce3e74';
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
  $pane->uuid = '5d4162ea-bcfa-400b-b4f6-8c5280ce3e74';
  $display->content['new-5d4162ea-bcfa-400b-b4f6-8c5280ce3e74'] = $pane;
  $display->panels['left'][1] = 'new-5d4162ea-bcfa-400b-b4f6-8c5280ce3e74';
  $pane = new stdClass();
  $pane->pid = 'new-b6432393-fe59-4556-a667-3e9d771b73df';
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
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
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
  $pane->uuid = 'b6432393-fe59-4556-a667-3e9d771b73df';
  $display->content['new-b6432393-fe59-4556-a667-3e9d771b73df'] = $pane;
  $display->panels['left'][2] = 'new-b6432393-fe59-4556-a667-3e9d771b73df';
  $pane = new stdClass();
  $pane->pid = 'new-70c901a2-03d7-4b10-982c-3cb1eacf4cd5';
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
  $pane->uuid = '70c901a2-03d7-4b10-982c-3cb1eacf4cd5';
  $display->content['new-70c901a2-03d7-4b10-982c-3cb1eacf4cd5'] = $pane;
  $display->panels['right'][0] = 'new-70c901a2-03d7-4b10-982c-3cb1eacf4cd5';
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
  $display->layout = 'flexible:profile_layout';
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
  $pane->pid = 'new-23bd63a6-75a3-4260-91e4-650f12dda391';
  $pane->panel = 'center';
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
  $pane->uuid = '23bd63a6-75a3-4260-91e4-650f12dda391';
  $display->content['new-23bd63a6-75a3-4260-91e4-650f12dda391'] = $pane;
  $display->panels['center'][0] = 'new-23bd63a6-75a3-4260-91e4-650f12dda391';
  $pane = new stdClass();
  $pane->pid = 'new-db1f5baa-0c9c-434d-9ac2-bfa41eb62ee9';
  $pane->panel = 'center';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'db1f5baa-0c9c-434d-9ac2-bfa41eb62ee9';
  $display->content['new-db1f5baa-0c9c-434d-9ac2-bfa41eb62ee9'] = $pane;
  $display->panels['center'][1] = 'new-db1f5baa-0c9c-434d-9ac2-bfa41eb62ee9';
  $pane = new stdClass();
  $pane->pid = 'new-3f11ef8c-763b-4cd3-9299-e8f7721ce31c';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'nm_activity_stream';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '15',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => 'Aktivität',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3f11ef8c-763b-4cd3-9299-e8f7721ce31c';
  $display->content['new-3f11ef8c-763b-4cd3-9299-e8f7721ce31c'] = $pane;
  $display->panels['center'][2] = 'new-3f11ef8c-763b-4cd3-9299-e8f7721ce31c';
  $pane = new stdClass();
  $pane->pid = 'new-3125f2f0-5c95-4957-96cf-ece6cc14d914';
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
  $pane->uuid = '3125f2f0-5c95-4957-96cf-ece6cc14d914';
  $display->content['new-3125f2f0-5c95-4957-96cf-ece6cc14d914'] = $pane;
  $display->panels['left'][0] = 'new-3125f2f0-5c95-4957-96cf-ece6cc14d914';
  $pane = new stdClass();
  $pane->pid = 'new-193f4165-7698-44bc-a7cb-cc20140926a8';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'User\'s roles',
    'title' => '',
    'body' => '(<?
$usrobj = user_load("%user:uid"); 
$roles = $usrobj->roles ;
$to_remove = array(\'authenticated user\');
$roles = array_diff($roles , $to_remove);
echo implode($roles , \', \');
?>)',
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
  $pane->uuid = '193f4165-7698-44bc-a7cb-cc20140926a8';
  $display->content['new-193f4165-7698-44bc-a7cb-cc20140926a8'] = $pane;
  $display->panels['left'][1] = 'new-193f4165-7698-44bc-a7cb-cc20140926a8';
  $pane = new stdClass();
  $pane->pid = 'new-c0ca5bbc-d035-46f3-89d8-51a878d5c6b4';
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
  $pane->uuid = 'c0ca5bbc-d035-46f3-89d8-51a878d5c6b4';
  $display->content['new-c0ca5bbc-d035-46f3-89d8-51a878d5c6b4'] = $pane;
  $display->panels['left'][2] = 'new-c0ca5bbc-d035-46f3-89d8-51a878d5c6b4';
  $pane = new stdClass();
  $pane->pid = 'new-ac85c33c-cb1c-44f4-8797-e7e1fc404021';
  $pane->panel = 'left';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ac85c33c-cb1c-44f4-8797-e7e1fc404021';
  $display->content['new-ac85c33c-cb1c-44f4-8797-e7e1fc404021'] = $pane;
  $display->panels['left'][3] = 'new-ac85c33c-cb1c-44f4-8797-e7e1fc404021';
  $pane = new stdClass();
  $pane->pid = 'new-a6cc2dea-c2c3-49a6-9105-3a6106d13c78';
  $pane->panel = 'left';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a6cc2dea-c2c3-49a6-9105-3a6106d13c78';
  $display->content['new-a6cc2dea-c2c3-49a6-9105-3a6106d13c78'] = $pane;
  $display->panels['left'][4] = 'new-a6cc2dea-c2c3-49a6-9105-3a6106d13c78';
  $pane = new stdClass();
  $pane->pid = 'new-a82c3cb9-d48d-407e-968e-cfd780de3415';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a82c3cb9-d48d-407e-968e-cfd780de3415';
  $display->content['new-a82c3cb9-d48d-407e-968e-cfd780de3415'] = $pane;
  $display->panels['left'][5] = 'new-a82c3cb9-d48d-407e-968e-cfd780de3415';
  $pane = new stdClass();
  $pane->pid = 'new-d9928861-fa03-4d13-adc6-863fb73d81b7';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'private_msg_button',
    'title' => '',
    'body' => '<?php
echo private_msg_get_profile_btn();
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd9928861-fa03-4d13-adc6-863fb73d81b7';
  $display->content['new-d9928861-fa03-4d13-adc6-863fb73d81b7'] = $pane;
  $display->panels['left'][6] = 'new-d9928861-fa03-4d13-adc6-863fb73d81b7';
  $pane = new stdClass();
  $pane->pid = 'new-5776b9d0-5e3b-4d95-8345-be9310efa02e';
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
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => 'Meine Kurse',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
    ),
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '5776b9d0-5e3b-4d95-8345-be9310efa02e';
  $display->content['new-5776b9d0-5e3b-4d95-8345-be9310efa02e'] = $pane;
  $display->panels['left'][7] = 'new-5776b9d0-5e3b-4d95-8345-be9310efa02e';
  $pane = new stdClass();
  $pane->pid = 'new-a5665709-cfee-4eba-90f6-38e8bda3b148';
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
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'a5665709-cfee-4eba-90f6-38e8bda3b148';
  $display->content['new-a5665709-cfee-4eba-90f6-38e8bda3b148'] = $pane;
  $display->panels['left'][8] = 'new-a5665709-cfee-4eba-90f6-38e8bda3b148';
  $pane = new stdClass();
  $pane->pid = 'new-a4e17017-5635-4f91-9f66-6d66f0c6e1bd';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'nm_stream';
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
    'override_title' => 1,
    'override_title_text' => 'Stream',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a4e17017-5635-4f91-9f66-6d66f0c6e1bd';
  $display->content['new-a4e17017-5635-4f91-9f66-6d66f0c6e1bd'] = $pane;
  $display->panels['right'][0] = 'new-a4e17017-5635-4f91-9f66-6d66f0c6e1bd';
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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = '066921f7-f62e-4495-b3b2-433d502bdbb3';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_biblio_in_kurs__panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3b0c085e-85c9-465b-be3e-fbd604c75c4b';
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
  $pane->uuid = '3b0c085e-85c9-465b-be3e-fbd604c75c4b';
  $display->content['new-3b0c085e-85c9-465b-be3e-fbd604c75c4b'] = $pane;
  $display->panels['center'][0] = 'new-3b0c085e-85c9-465b-be3e-fbd604c75c4b';
  $pane = new stdClass();
  $pane->pid = 'new-236b5613-32fb-4a5b-ab7c-4d0deeb37e68';
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
  $pane->uuid = '236b5613-32fb-4a5b-ab7c-4d0deeb37e68';
  $display->content['new-236b5613-32fb-4a5b-ab7c-4d0deeb37e68'] = $pane;
  $display->panels['outline'][0] = 'new-236b5613-32fb-4a5b-ab7c-4d0deeb37e68';
  $pane = new stdClass();
  $pane->pid = 'new-ee641611-2ffa-4e44-a25b-de6c9ee5c709';
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
  $pane->uuid = 'ee641611-2ffa-4e44-a25b-de6c9ee5c709';
  $display->content['new-ee641611-2ffa-4e44-a25b-de6c9ee5c709'] = $pane;
  $display->panels['outline'][1] = 'new-ee641611-2ffa-4e44-a25b-de6c9ee5c709';
  $pane = new stdClass();
  $pane->pid = 'new-c3fb50ad-abdb-420d-a6d3-74c224de324e';
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
  $pane->uuid = 'c3fb50ad-abdb-420d-a6d3-74c224de324e';
  $display->content['new-c3fb50ad-abdb-420d-a6d3-74c224de324e'] = $pane;
  $display->panels['tools'][0] = 'new-c3fb50ad-abdb-420d-a6d3-74c224de324e';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
        'class' => 'col-md-8',
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
        'class' => 'col-md-4',
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
  $display->uuid = 'c3753c99-df30-45d9-a4b0-e095c5807d0c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_course_admin_add_member_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a9432128-769f-44a9-a00c-01675f65cd26';
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
  $pane->uuid = 'a9432128-769f-44a9-a00c-01675f65cd26';
  $display->content['new-a9432128-769f-44a9-a00c-01675f65cd26'] = $pane;
  $display->panels['center'][0] = 'new-a9432128-769f-44a9-a00c-01675f65cd26';
  $pane = new stdClass();
  $pane->pid = 'new-d365041b-60c0-486f-857a-630317889bb4';
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
  $pane->uuid = 'd365041b-60c0-486f-857a-630317889bb4';
  $display->content['new-d365041b-60c0-486f-857a-630317889bb4'] = $pane;
  $display->panels['tools'][0] = 'new-d365041b-60c0-486f-857a-630317889bb4';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_course_admin_settings_panel_context';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = '4cf6417e-9fc2-4f4c-b809-7d631a5f21df';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_course_groups_in_course_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b0cd8769-9c77-4e19-98d2-6e6aee43f7da';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'section_projects-projects_course_group_actions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'title' => array(
        'element' => '0',
        'attributes' => array(
          'id' => '',
          'class' => '',
        ),
      ),
      'content' => array(
        'element' => 'h4',
        'attributes' => array(
          'id' => '',
          'class' => 'visible-xs-block  visible-sm-block ',
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
  $pane->uuid = 'b0cd8769-9c77-4e19-98d2-6e6aee43f7da';
  $display->content['new-b0cd8769-9c77-4e19-98d2-6e6aee43f7da'] = $pane;
  $display->panels['news'][0] = 'new-b0cd8769-9c77-4e19-98d2-6e6aee43f7da';
  $pane = new stdClass();
  $pane->pid = 'new-2d20025c-456b-4685-b55c-682553f848f4';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'section_courses-course_node_tabs';
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
  $pane->uuid = '2d20025c-456b-4685-b55c-682553f848f4';
  $display->content['new-2d20025c-456b-4685-b55c-682553f848f4'] = $pane;
  $display->panels['news'][1] = 'new-2d20025c-456b-4685-b55c-682553f848f4';
  $pane = new stdClass();
  $pane->pid = 'new-38bc2fbf-7423-4f4c-9285-de4672e0e60f';
  $pane->panel = 'news';
  $pane->type = 'block';
  $pane->subtype = 'nm_stream-nm_stream_form_add_edit';
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
  $pane->uuid = '38bc2fbf-7423-4f4c-9285-de4672e0e60f';
  $display->content['new-38bc2fbf-7423-4f4c-9285-de4672e0e60f'] = $pane;
  $display->panels['news'][2] = 'new-38bc2fbf-7423-4f4c-9285-de4672e0e60f';
  $pane = new stdClass();
  $pane->pid = 'new-56d682cf-6bbf-4b6c-b569-0df094188e3b';
  $pane->panel = 'news';
  $pane->type = 'views';
  $pane->subtype = 'nm_stream';
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
    'override_title' => 1,
    'override_title_text' => '',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
      1 => 'argument_entity_id:node_2.nid',
    ),
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '56d682cf-6bbf-4b6c-b569-0df094188e3b';
  $display->content['new-56d682cf-6bbf-4b6c-b569-0df094188e3b'] = $pane;
  $display->panels['news'][3] = 'new-56d682cf-6bbf-4b6c-b569-0df094188e3b';
  $pane = new stdClass();
  $pane->pid = 'new-7df02c0e-55e2-4bde-b98a-87e4a4459587';
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
  $pane->uuid = '7df02c0e-55e2-4bde-b98a-87e4a4459587';
  $display->content['new-7df02c0e-55e2-4bde-b98a-87e4a4459587'] = $pane;
  $display->panels['tools'][0] = 'new-7df02c0e-55e2-4bde-b98a-87e4a4459587';
  $pane = new stdClass();
  $pane->pid = 'new-9539c4f8-70de-4a28-a09f-c9b83b577dc0';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9539c4f8-70de-4a28-a09f-c9b83b577dc0';
  $display->content['new-9539c4f8-70de-4a28-a09f-c9b83b577dc0'] = $pane;
  $display->panels['tools'][1] = 'new-9539c4f8-70de-4a28-a09f-c9b83b577dc0';
  $pane = new stdClass();
  $pane->pid = 'new-af4736c1-c79e-4870-9dfa-a2c429006297';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'af4736c1-c79e-4870-9dfa-a2c429006297';
  $display->content['new-af4736c1-c79e-4870-9dfa-a2c429006297'] = $pane;
  $display->panels['tools'][2] = 'new-af4736c1-c79e-4870-9dfa-a2c429006297';
  $pane = new stdClass();
  $pane->pid = 'new-262a01c1-785f-41fc-8965-51fa6bfb146b';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '262a01c1-785f-41fc-8965-51fa6bfb146b';
  $display->content['new-262a01c1-785f-41fc-8965-51fa6bfb146b'] = $pane;
  $display->panels['tools'][3] = 'new-262a01c1-785f-41fc-8965-51fa6bfb146b';
  $pane = new stdClass();
  $pane->pid = 'new-36d8976c-8a6d-4cbc-8c93-57b7b36bc709';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_projects-projects_course_group_actions';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '36d8976c-8a6d-4cbc-8c93-57b7b36bc709';
  $display->content['new-36d8976c-8a6d-4cbc-8c93-57b7b36bc709'] = $pane;
  $display->panels['tools'][4] = 'new-36d8976c-8a6d-4cbc-8c93-57b7b36bc709';
  $pane = new stdClass();
  $pane->pid = 'new-aeb10b6f-d2f3-4e92-9a61-97560efdbded';
  $pane->panel = 'tools';
  $pane->type = 'block';
  $pane->subtype = 'section_projects-projects_course_group_userlink';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'aeb10b6f-d2f3-4e92-9a61-97560efdbded';
  $display->content['new-aeb10b6f-d2f3-4e92-9a61-97560efdbded'] = $pane;
  $display->panels['tools'][5] = 'new-aeb10b6f-d2f3-4e92-9a61-97560efdbded';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
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
        'class' => 'col-md-8',
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
        'class' => 'col-md-4',
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
  $display->uuid = '13e598f2-c0f0-4c77-b80f-c264880f297b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_course_groups_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ffdd8704-3fed-4ef2-bb6a-b5b0c0f9bb3e';
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
  $pane->uuid = 'ffdd8704-3fed-4ef2-bb6a-b5b0c0f9bb3e';
  $display->content['new-ffdd8704-3fed-4ef2-bb6a-b5b0c0f9bb3e'] = $pane;
  $display->panels['news'][0] = 'new-ffdd8704-3fed-4ef2-bb6a-b5b0c0f9bb3e';
  $pane = new stdClass();
  $pane->pid = 'new-864e4bd4-2a45-4808-8417-06d08086fb03';
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
  $pane->uuid = '864e4bd4-2a45-4808-8417-06d08086fb03';
  $display->content['new-864e4bd4-2a45-4808-8417-06d08086fb03'] = $pane;
  $display->panels['tools'][0] = 'new-864e4bd4-2a45-4808-8417-06d08086fb03';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ffdd8704-3fed-4ef2-bb6a-b5b0c0f9bb3e';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = '27adf0f1-3633-4a04-ba0c-29b964f89b06';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_course_single_doc_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fc93e900-33d9-4e00-8af4-25d45b8c5a8d';
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
  $pane->uuid = 'fc93e900-33d9-4e00-8af4-25d45b8c5a8d';
  $display->content['new-fc93e900-33d9-4e00-8af4-25d45b8c5a8d'] = $pane;
  $display->panels['news'][0] = 'new-fc93e900-33d9-4e00-8af4-25d45b8c5a8d';
  $pane = new stdClass();
  $pane->pid = 'new-ca94eac8-7e2b-4f1d-aa03-3ceff1053424';
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
  $pane->uuid = 'ca94eac8-7e2b-4f1d-aa03-3ceff1053424';
  $display->content['new-ca94eac8-7e2b-4f1d-aa03-3ceff1053424'] = $pane;
  $display->panels['news'][1] = 'new-ca94eac8-7e2b-4f1d-aa03-3ceff1053424';
  $pane = new stdClass();
  $pane->pid = 'new-c873ab04-5bdf-4bfc-8a04-856644a0c47f';
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
  $pane->uuid = 'c873ab04-5bdf-4bfc-8a04-856644a0c47f';
  $display->content['new-c873ab04-5bdf-4bfc-8a04-856644a0c47f'] = $pane;
  $display->panels['tools'][0] = 'new-c873ab04-5bdf-4bfc-8a04-856644a0c47f';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = '49db32e8-f4c0-4cfa-b87f-093fcb6e3e86';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_course_tasks_solution_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0edd414b-2039-48c9-9c4b-2c2b9d5990b4';
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
  $pane->uuid = '0edd414b-2039-48c9-9c4b-2c2b9d5990b4';
  $display->content['new-0edd414b-2039-48c9-9c4b-2c2b9d5990b4'] = $pane;
  $display->panels['news'][0] = 'new-0edd414b-2039-48c9-9c4b-2c2b9d5990b4';
  $pane = new stdClass();
  $pane->pid = 'new-990de6ea-3ee2-49e5-920c-9c040316dd6d';
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
  $pane->uuid = '990de6ea-3ee2-49e5-920c-9c040316dd6d';
  $display->content['new-990de6ea-3ee2-49e5-920c-9c040316dd6d'] = $pane;
  $display->panels['news'][1] = 'new-990de6ea-3ee2-49e5-920c-9c040316dd6d';
  $pane = new stdClass();
  $pane->pid = 'new-5b8f0c32-6c04-4e43-8eeb-3152f04a9e84';
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
  $pane->uuid = '5b8f0c32-6c04-4e43-8eeb-3152f04a9e84';
  $display->content['new-5b8f0c32-6c04-4e43-8eeb-3152f04a9e84'] = $pane;
  $display->panels['news'][2] = 'new-5b8f0c32-6c04-4e43-8eeb-3152f04a9e84';
  $pane = new stdClass();
  $pane->pid = 'new-38a71211-e95d-4e6b-8ed3-871fd11e0d39';
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
  $pane->uuid = '38a71211-e95d-4e6b-8ed3-871fd11e0d39';
  $display->content['new-38a71211-e95d-4e6b-8ed3-871fd11e0d39'] = $pane;
  $display->panels['tools'][0] = 'new-38a71211-e95d-4e6b-8ed3-871fd11e0d39';
  $pane = new stdClass();
  $pane->pid = 'new-442c300e-334c-4206-ad96-1849169ba7fe';
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
  $pane->uuid = '442c300e-334c-4206-ad96-1849169ba7fe';
  $display->content['new-442c300e-334c-4206-ad96-1849169ba7fe'] = $pane;
  $display->panels['tools'][1] = 'new-442c300e-334c-4206-ad96-1849169ba7fe';
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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
        'class' => 'col-md-11 course-info',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'links',
          1 => 'rechts',
        ),
        'parent' => 'main',
        'class' => 'header row',
      ),
      'links' => array(
        'type' => 'region',
        'title' => 'header_left',
        'width' => '65.40245299300852',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'header_left col-md-8',
      ),
      'rechts' => array(
        'type' => 'region',
        'title' => 'header_right',
        'width' => '34.597547006991476',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'header_right col-md-4',
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
        'class' => 'subheader_left col-md-8',
      ),
      'rechts_' => array(
        'type' => 'region',
        'title' => 'subheader_right',
        'width' => '34.59754794162703',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'subheader_right col-md-4',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'content',
        ),
        'parent' => 'main',
        'class' => 'content row',
      ),
      'content' => array(
        'type' => 'region',
        'title' => 'Content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'col-md-12',
      ),
      3 => array(
        'type' => 'column',
        'width' => '23.733995473125905',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 4,
        ),
        'class' => 'col-md-1',
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
  $display->uuid = 'dc0d0009-e4d9-4e03-b9aa-05ff00c3bb9e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courseinformation_in_course__panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-44a3a1c7-faf8-420a-954d-6a6712e90af1';
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
  $pane->uuid = '44a3a1c7-faf8-420a-954d-6a6712e90af1';
  $display->content['new-44a3a1c7-faf8-420a-954d-6a6712e90af1'] = $pane;
  $display->panels['content'][0] = 'new-44a3a1c7-faf8-420a-954d-6a6712e90af1';
  $pane = new stdClass();
  $pane->pid = 'new-61853739-1101-437c-8dce-d577b47f09d9';
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
  $pane->uuid = '61853739-1101-437c-8dce-d577b47f09d9';
  $display->content['new-61853739-1101-437c-8dce-d577b47f09d9'] = $pane;
  $display->panels['links'][0] = 'new-61853739-1101-437c-8dce-d577b47f09d9';
  $pane = new stdClass();
  $pane->pid = 'new-12660a6b-4636-4f11-b6cc-7aa9e1074924';
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
  $pane->uuid = '12660a6b-4636-4f11-b6cc-7aa9e1074924';
  $display->content['new-12660a6b-4636-4f11-b6cc-7aa9e1074924'] = $pane;
  $display->panels['links'][1] = 'new-12660a6b-4636-4f11-b6cc-7aa9e1074924';
  $pane = new stdClass();
  $pane->pid = 'new-fe6e761f-8466-4f28-85bd-e7f16fd4572f';
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
  $pane->uuid = 'fe6e761f-8466-4f28-85bd-e7f16fd4572f';
  $display->content['new-fe6e761f-8466-4f28-85bd-e7f16fd4572f'] = $pane;
  $display->panels['links'][2] = 'new-fe6e761f-8466-4f28-85bd-e7f16fd4572f';
  $pane = new stdClass();
  $pane->pid = 'new-fe3cfc56-5d97-4cdf-acef-57e21bbb06b0';
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
  $pane->uuid = 'fe3cfc56-5d97-4cdf-acef-57e21bbb06b0';
  $display->content['new-fe3cfc56-5d97-4cdf-acef-57e21bbb06b0'] = $pane;
  $display->panels['links'][3] = 'new-fe3cfc56-5d97-4cdf-acef-57e21bbb06b0';
  $pane = new stdClass();
  $pane->pid = 'new-1bceb5e9-99be-4a6b-b852-2446d50565f3';
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
  $pane->uuid = '1bceb5e9-99be-4a6b-b852-2446d50565f3';
  $display->content['new-1bceb5e9-99be-4a6b-b852-2446d50565f3'] = $pane;
  $display->panels['links_'][0] = 'new-1bceb5e9-99be-4a6b-b852-2446d50565f3';
  $pane = new stdClass();
  $pane->pid = 'new-820b4468-b869-497b-95e8-b59868c287e0';
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
  $pane->uuid = '820b4468-b869-497b-95e8-b59868c287e0';
  $display->content['new-820b4468-b869-497b-95e8-b59868c287e0'] = $pane;
  $display->panels['links_'][1] = 'new-820b4468-b869-497b-95e8-b59868c287e0';
  $pane = new stdClass();
  $pane->pid = 'new-39a1c91f-57d5-4597-8e4a-6082a675d5e3';
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
  $pane->uuid = '39a1c91f-57d5-4597-8e4a-6082a675d5e3';
  $display->content['new-39a1c91f-57d5-4597-8e4a-6082a675d5e3'] = $pane;
  $display->panels['links_'][2] = 'new-39a1c91f-57d5-4597-8e4a-6082a675d5e3';
  $pane = new stdClass();
  $pane->pid = 'new-e3f317fe-a4d8-444d-8d0a-1e4c4865e8eb';
  $pane->panel = 'rechts';
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
  $pane->uuid = 'e3f317fe-a4d8-444d-8d0a-1e4c4865e8eb';
  $display->content['new-e3f317fe-a4d8-444d-8d0a-1e4c4865e8eb'] = $pane;
  $display->panels['rechts'][0] = 'new-e3f317fe-a4d8-444d-8d0a-1e4c4865e8eb';
  $pane = new stdClass();
  $pane->pid = 'new-232f45f6-5565-4819-99aa-ce8314c3779e';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '232f45f6-5565-4819-99aa-ce8314c3779e';
  $display->content['new-232f45f6-5565-4819-99aa-ce8314c3779e'] = $pane;
  $display->panels['rechts'][1] = 'new-232f45f6-5565-4819-99aa-ce8314c3779e';
  $pane = new stdClass();
  $pane->pid = 'new-3fbf1e35-6b7d-4fee-9ddf-e4d3ec9db14b';
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
  $pane->uuid = '3fbf1e35-6b7d-4fee-9ddf-e4d3ec9db14b';
  $display->content['new-3fbf1e35-6b7d-4fee-9ddf-e4d3ec9db14b'] = $pane;
  $display->panels['rechts_'][0] = 'new-3fbf1e35-6b7d-4fee-9ddf-e4d3ec9db14b';
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
            0 => 'administrator member',
            1 => 'kurs-dozent',
            2 => 'kurs-tutor',
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
        'class' => 'col-md-11',
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
        'class' => 'col-md-1',
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
  $display->uuid = '1fa1cee7-8d7b-4ffc-8271-eee9ed5ab49e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_admin_add_node_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-94323719-a6fe-4925-b209-42f5273131a0';
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
  $pane->uuid = '94323719-a6fe-4925-b209-42f5273131a0';
  $display->content['new-94323719-a6fe-4925-b209-42f5273131a0'] = $pane;
  $display->panels['center'][0] = 'new-94323719-a6fe-4925-b209-42f5273131a0';
  $pane = new stdClass();
  $pane->pid = 'new-bf8b8a4f-b14c-448c-9271-8c3a5959ed16';
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
  $pane->uuid = 'bf8b8a4f-b14c-448c-9271-8c3a5959ed16';
  $display->content['new-bf8b8a4f-b14c-448c-9271-8c3a5959ed16'] = $pane;
  $display->panels['tools'][0] = 'new-bf8b8a4f-b14c-448c-9271-8c3a5959ed16';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-94323719-a6fe-4925-b209-42f5273131a0';
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
    'type' => 'none',
    'settings' => NULL,
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
        'class' => 'col-md-11',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 3,
          1 => 2,
        ),
        'parent' => 'main',
        'class' => 'row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 4,
        ),
        'class' => 'col-md-1',
      ),
      2 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 6,
        ),
        'class' => 'col-md-6',
      ),
      3 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 5,
        ),
        'class' => 'col-md-6',
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_admin_content_panel_context';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = 'fb5218c5-156b-405d-acdd-6843b4bc6d53';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_admin_edit_node_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3de3ea61-23f3-4448-a4d3-34b81de84939';
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
  $pane->uuid = '3de3ea61-23f3-4448-a4d3-34b81de84939';
  $display->content['new-3de3ea61-23f3-4448-a4d3-34b81de84939'] = $pane;
  $display->panels['news'][0] = 'new-3de3ea61-23f3-4448-a4d3-34b81de84939';
  $pane = new stdClass();
  $pane->pid = 'new-0cd7c74f-294f-410e-81b3-761bdcb1416a';
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
  $pane->uuid = '0cd7c74f-294f-410e-81b3-761bdcb1416a';
  $display->content['new-0cd7c74f-294f-410e-81b3-761bdcb1416a'] = $pane;
  $display->panels['news'][1] = 'new-0cd7c74f-294f-410e-81b3-761bdcb1416a';
  $pane = new stdClass();
  $pane->pid = 'new-7c638452-e250-4ae4-a9e8-3b2db13ffa23';
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
  $pane->uuid = '7c638452-e250-4ae4-a9e8-3b2db13ffa23';
  $display->content['new-7c638452-e250-4ae4-a9e8-3b2db13ffa23'] = $pane;
  $display->panels['tools'][0] = 'new-7c638452-e250-4ae4-a9e8-3b2db13ffa23';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0cd7c74f-294f-410e-81b3-761bdcb1416a';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
  $display->uuid = '58df806a-85db-4513-b6ab-f447a5aea1d7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_admin_forums_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-90afa9d5-35b8-449c-8200-d9b080275427';
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
  $pane->uuid = '90afa9d5-35b8-449c-8200-d9b080275427';
  $display->content['new-90afa9d5-35b8-449c-8200-d9b080275427'] = $pane;
  $display->panels['center'][0] = 'new-90afa9d5-35b8-449c-8200-d9b080275427';
  $pane = new stdClass();
  $pane->pid = 'new-abd1e078-f8d8-4725-80ba-0e489c81c8e2';
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
  $pane->uuid = 'abd1e078-f8d8-4725-80ba-0e489c81c8e2';
  $display->content['new-abd1e078-f8d8-4725-80ba-0e489c81c8e2'] = $pane;
  $display->panels['tools'][0] = 'new-abd1e078-f8d8-4725-80ba-0e489c81c8e2';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
        'class' => 'col-md-11',
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
        'class' => 'col-md-1',
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
  $display->uuid = '8dec6129-22c3-4ff5-8de8-aab5c51c645f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_admin_groups_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-77d7dfa5-522e-4432-b88b-3f829c558e15';
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
  $pane->uuid = '77d7dfa5-522e-4432-b88b-3f829c558e15';
  $display->content['new-77d7dfa5-522e-4432-b88b-3f829c558e15'] = $pane;
  $display->panels['center'][0] = 'new-77d7dfa5-522e-4432-b88b-3f829c558e15';
  $pane = new stdClass();
  $pane->pid = 'new-c5c8edca-00cd-4492-b2b3-34513d6168ae';
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
  $pane->uuid = 'c5c8edca-00cd-4492-b2b3-34513d6168ae';
  $display->content['new-c5c8edca-00cd-4492-b2b3-34513d6168ae'] = $pane;
  $display->panels['tools'][0] = 'new-c5c8edca-00cd-4492-b2b3-34513d6168ae';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-77d7dfa5-522e-4432-b88b-3f829c558e15';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_admin_members_panel_context';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = '75f4b5c9-faf5-4b62-b773-9f71858e7994';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_course_home_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1ed5406a-9021-49e7-bd7d-74b3a7c56d64';
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
  $pane->uuid = '1ed5406a-9021-49e7-bd7d-74b3a7c56d64';
  $display->content['new-1ed5406a-9021-49e7-bd7d-74b3a7c56d64'] = $pane;
  $display->panels['news'][0] = 'new-1ed5406a-9021-49e7-bd7d-74b3a7c56d64';
  $pane = new stdClass();
  $pane->pid = 'new-5d61e5a4-4920-40bf-859b-bb5a17e0e753';
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
  $pane->uuid = '5d61e5a4-4920-40bf-859b-bb5a17e0e753';
  $display->content['new-5d61e5a4-4920-40bf-859b-bb5a17e0e753'] = $pane;
  $display->panels['tools'][0] = 'new-5d61e5a4-4920-40bf-859b-bb5a17e0e753';
  $pane = new stdClass();
  $pane->pid = 'new-1d593bf2-5130-4953-9a57-d17bdefaf819';
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
  $pane->uuid = '1d593bf2-5130-4953-9a57-d17bdefaf819';
  $display->content['new-1d593bf2-5130-4953-9a57-d17bdefaf819'] = $pane;
  $display->panels['tools'][1] = 'new-1d593bf2-5130-4953-9a57-d17bdefaf819';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1ed5406a-9021-49e7-bd7d-74b3a7c56d64';
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
  $page->path = 'courses/!archive';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'archive' => array(
      'id' => 1,
      'identifier' => 'archive',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
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
  $handler->name = 'page_courses_course_overview_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_course_overview';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'allgemein',
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
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '!=',
            'value' => 'archive',
            'case' => 1,
          ),
          'context' => 'argument_string_1',
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
        'class' => 'col-md-11',
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
        'title' => 'main',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-11',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-1',
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
  $display->uuid = '532d2f69-94b7-4a1d-be7a-340653e8ed4c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_course_overview_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ccee1c33-9999-43ce-8788-04d026746e96';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'courses_kurse_bersicht-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => 'my_drafts',
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ccee1c33-9999-43ce-8788-04d026746e96';
  $display->content['new-ccee1c33-9999-43ce-8788-04d026746e96'] = $pane;
  $display->panels['center'][0] = 'new-ccee1c33-9999-43ce-8788-04d026746e96';
  $pane = new stdClass();
  $pane->pid = 'new-6abe3379-f868-49d8-aaff-095a06ec9af6';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'courses_kurse_bersicht-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => 'my_courses',
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6abe3379-f868-49d8-aaff-095a06ec9af6';
  $display->content['new-6abe3379-f868-49d8-aaff-095a06ec9af6'] = $pane;
  $display->panels['center'][1] = 'new-6abe3379-f868-49d8-aaff-095a06ec9af6';
  $pane = new stdClass();
  $pane->pid = 'new-54b42ae9-c113-4615-af7e-70a6ead03f8d';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'courses_kurse_bersicht-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => 'courses_offer',
    'items_per_page' => '15',
    'exposed' => array(
      'sort_by' => 'field_time_span_value',
      'sort_order' => 'ASC',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->uuid = '54b42ae9-c113-4615-af7e-70a6ead03f8d';
  $display->content['new-54b42ae9-c113-4615-af7e-70a6ead03f8d'] = $pane;
  $display->panels['center'][2] = 'new-54b42ae9-c113-4615-af7e-70a6ead03f8d';
  $pane = new stdClass();
  $pane->pid = 'new-274a2ed2-b09c-476b-aebc-2fcbf594ab31';
  $pane->panel = 'tools';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'platzhalter',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>&nbsp;</h1>
',
    'format' => 'full_html',
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
  $pane->uuid = '274a2ed2-b09c-476b-aebc-2fcbf594ab31';
  $display->content['new-274a2ed2-b09c-476b-aebc-2fcbf594ab31'] = $pane;
  $display->panels['tools'][0] = 'new-274a2ed2-b09c-476b-aebc-2fcbf594ab31';
  $pane = new stdClass();
  $pane->pid = 'new-605e0f6d-45cc-409c-82a6-ee4bcb5732fe';
  $pane->panel = 'tools';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'neuerkurs-link',
    'title' => '',
    'body' => '<?php
if(section_courses_instructors_tools_access())
echo \'<p><a class="btn btn-default" href="/node/add/courses-course">Neuen Kurs anlegen</a></p>\';

?>',
    'format' => 'php_code',
    'substitute' => 1,
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
  $pane->uuid = '605e0f6d-45cc-409c-82a6-ee4bcb5732fe';
  $display->content['new-605e0f6d-45cc-409c-82a6-ee4bcb5732fe'] = $pane;
  $display->panels['tools'][1] = 'new-605e0f6d-45cc-409c-82a6-ee4bcb5732fe';
  $pane = new stdClass();
  $pane->pid = 'new-88bd3aab-a455-4967-84a5-b41da40aabb9';
  $pane->panel = 'tools';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'kursarchiv-link',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a class="btn btn-link" href="/courses/archive">
<?=t(\'archivated courses\');?>
</a>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '88bd3aab-a455-4967-84a5-b41da40aabb9';
  $display->content['new-88bd3aab-a455-4967-84a5-b41da40aabb9'] = $pane;
  $display->panels['tools'][2] = 'new-88bd3aab-a455-4967-84a5-b41da40aabb9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_courses_course_overview__archive';
  $handler->task = 'page';
  $handler->subtask = 'courses_course_overview';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'archive',
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
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'archive',
            'case' => 1,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'archive',
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
  $display->title = 'Kursarchiv';
  $display->uuid = '532d2f69-94b7-4a1d-be7a-340653e8ed4c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_course_overview_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d983b15a-4dc7-47ed-bdf2-728071399f6a';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'courses_kurse_bersicht-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '15',
    'exposed' => array(
      'sort_by' => 'field_time_span_value',
      'sort_order' => 'DESC',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd983b15a-4dc7-47ed-bdf2-728071399f6a';
  $display->content['new-d983b15a-4dc7-47ed-bdf2-728071399f6a'] = $pane;
  $display->panels['center'][0] = 'new-d983b15a-4dc7-47ed-bdf2-728071399f6a';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
  $display->uuid = 'e784bdfd-660e-401f-9f88-c7decd7f2d86';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_forum_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6a546994-9091-4afd-8fcd-1d04949f0b22';
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
  $pane->uuid = '6a546994-9091-4afd-8fcd-1d04949f0b22';
  $display->content['new-6a546994-9091-4afd-8fcd-1d04949f0b22'] = $pane;
  $display->panels['center'][0] = 'new-6a546994-9091-4afd-8fcd-1d04949f0b22';
  $pane = new stdClass();
  $pane->pid = 'new-bbd862f2-66bb-42a8-8c1b-98f608bc8fbd';
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
  $pane->uuid = 'bbd862f2-66bb-42a8-8c1b-98f608bc8fbd';
  $display->content['new-bbd862f2-66bb-42a8-8c1b-98f608bc8fbd'] = $pane;
  $display->panels['center'][1] = 'new-bbd862f2-66bb-42a8-8c1b-98f608bc8fbd';
  $pane = new stdClass();
  $pane->pid = 'new-bd6000b6-dec9-4f16-91f4-9c6e053bae79';
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
  $pane->uuid = 'bd6000b6-dec9-4f16-91f4-9c6e053bae79';
  $display->content['new-bd6000b6-dec9-4f16-91f4-9c6e053bae79'] = $pane;
  $display->panels['center'][2] = 'new-bd6000b6-dec9-4f16-91f4-9c6e053bae79';
  $pane = new stdClass();
  $pane->pid = 'new-7e1c012e-8b7c-4035-ad81-7e79c5ecdc2e';
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
  $pane->uuid = '7e1c012e-8b7c-4035-ad81-7e79c5ecdc2e';
  $display->content['new-7e1c012e-8b7c-4035-ad81-7e79c5ecdc2e'] = $pane;
  $display->panels['center'][3] = 'new-7e1c012e-8b7c-4035-ad81-7e79c5ecdc2e';
  $pane = new stdClass();
  $pane->pid = 'new-6017a486-e6ff-4907-a5aa-8eb270c7f574';
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
  $pane->uuid = '6017a486-e6ff-4907-a5aa-8eb270c7f574';
  $display->content['new-6017a486-e6ff-4907-a5aa-8eb270c7f574'] = $pane;
  $display->panels['center'][4] = 'new-6017a486-e6ff-4907-a5aa-8eb270c7f574';
  $pane = new stdClass();
  $pane->pid = 'new-c376d448-a2d5-46d3-a88d-52d662b7588e';
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
  $pane->uuid = 'c376d448-a2d5-46d3-a88d-52d662b7588e';
  $display->content['new-c376d448-a2d5-46d3-a88d-52d662b7588e'] = $pane;
  $display->panels['tools'][0] = 'new-c376d448-a2d5-46d3-a88d-52d662b7588e';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = 'd0b259cc-ec8e-4157-a155-083d474c1d67';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_forumcontent_add_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cffdbc18-b95e-498e-a7d8-c7acb30c8838';
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
  $pane->uuid = 'cffdbc18-b95e-498e-a7d8-c7acb30c8838';
  $display->content['new-cffdbc18-b95e-498e-a7d8-c7acb30c8838'] = $pane;
  $display->panels['center'][0] = 'new-cffdbc18-b95e-498e-a7d8-c7acb30c8838';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cffdbc18-b95e-498e-a7d8-c7acb30c8838';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = '60126cd8-fe7c-4a13-bb92-0f48d86e19d6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_forumcontent_delete_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-866ee208-9f90-408a-9f2b-2844c286075e';
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
  $pane->uuid = '866ee208-9f90-408a-9f2b-2844c286075e';
  $display->content['new-866ee208-9f90-408a-9f2b-2844c286075e'] = $pane;
  $display->panels['center'][0] = 'new-866ee208-9f90-408a-9f2b-2844c286075e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-866ee208-9f90-408a-9f2b-2844c286075e';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = 'f43b5a4c-ed02-4e7a-ba71-f639a7116338';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_forumcontent_edit_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f322cb83-22b2-40a7-9e63-bf68c3e7e9f6';
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
  $pane->uuid = 'f322cb83-22b2-40a7-9e63-bf68c3e7e9f6';
  $display->content['new-f322cb83-22b2-40a7-9e63-bf68c3e7e9f6'] = $pane;
  $display->panels['center'][0] = 'new-f322cb83-22b2-40a7-9e63-bf68c3e7e9f6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f322cb83-22b2-40a7-9e63-bf68c3e7e9f6';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = 'ae03abde-987f-4bbe-ba2b-7aab66e5c908';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_forumcontent_editcomment_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d60b12b9-8f9e-4ef5-a5e9-7477f0611f48';
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
  $pane->uuid = 'd60b12b9-8f9e-4ef5-a5e9-7477f0611f48';
  $display->content['new-d60b12b9-8f9e-4ef5-a5e9-7477f0611f48'] = $pane;
  $display->panels['center'][0] = 'new-d60b12b9-8f9e-4ef5-a5e9-7477f0611f48';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d60b12b9-8f9e-4ef5-a5e9-7477f0611f48';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
  $display->uuid = '25c1076a-b303-4012-99cb-35f1b48b2842';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_forumcontent_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e345bd71-a268-4d53-afd3-8190b7310224';
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
  $pane->uuid = 'e345bd71-a268-4d53-afd3-8190b7310224';
  $display->content['new-e345bd71-a268-4d53-afd3-8190b7310224'] = $pane;
  $display->panels['center'][0] = 'new-e345bd71-a268-4d53-afd3-8190b7310224';
  $pane = new stdClass();
  $pane->pid = 'new-c84c51ce-6a94-4c68-b795-2f7d007aff24';
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
  $pane->uuid = 'c84c51ce-6a94-4c68-b795-2f7d007aff24';
  $display->content['new-c84c51ce-6a94-4c68-b795-2f7d007aff24'] = $pane;
  $display->panels['center'][1] = 'new-c84c51ce-6a94-4c68-b795-2f7d007aff24';
  $pane = new stdClass();
  $pane->pid = 'new-b360abb7-1b19-4969-982d-5ba4a523ee9f';
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
  $pane->uuid = 'b360abb7-1b19-4969-982d-5ba4a523ee9f';
  $display->content['new-b360abb7-1b19-4969-982d-5ba4a523ee9f'] = $pane;
  $display->panels['center'][2] = 'new-b360abb7-1b19-4969-982d-5ba4a523ee9f';
  $pane = new stdClass();
  $pane->pid = 'new-65da5f79-d601-442c-8dda-e542342c461c';
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
  $pane->uuid = '65da5f79-d601-442c-8dda-e542342c461c';
  $display->content['new-65da5f79-d601-442c-8dda-e542342c461c'] = $pane;
  $display->panels['center'][3] = 'new-65da5f79-d601-442c-8dda-e542342c461c';
  $pane = new stdClass();
  $pane->pid = 'new-4210d271-826a-498f-94dc-28f3ee7fb567';
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
  $pane->uuid = '4210d271-826a-498f-94dc-28f3ee7fb567';
  $display->content['new-4210d271-826a-498f-94dc-28f3ee7fb567'] = $pane;
  $display->panels['tools'][0] = 'new-4210d271-826a-498f-94dc-28f3ee7fb567';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->uuid = 'e9153794-e34b-4e8a-be04-f99095045b3d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_forumcontent_reply_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3845c905-c6ee-464e-9332-d8be1953433d';
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
  $pane->uuid = '3845c905-c6ee-464e-9332-d8be1953433d';
  $display->content['new-3845c905-c6ee-464e-9332-d8be1953433d'] = $pane;
  $display->panels['center'][0] = 'new-3845c905-c6ee-464e-9332-d8be1953433d';
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
    'type' => 'none',
    'settings' => NULL,
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
  $display->layout = 'flexible:span11span1_adminonly';
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
  $display->uuid = '92d5a183-acac-4ad1-a50c-4b6fd0813227';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_news_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-aeb5a737-2e60-4f47-9395-2fa070a45e6a';
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
  $pane->uuid = 'aeb5a737-2e60-4f47-9395-2fa070a45e6a';
  $display->content['new-aeb5a737-2e60-4f47-9395-2fa070a45e6a'] = $pane;
  $display->panels['center'][0] = 'new-aeb5a737-2e60-4f47-9395-2fa070a45e6a';
  $pane = new stdClass();
  $pane->pid = 'new-c75e6148-cead-4ea2-af5c-0d67ffbd03a7';
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
  $pane->uuid = 'c75e6148-cead-4ea2-af5c-0d67ffbd03a7';
  $display->content['new-c75e6148-cead-4ea2-af5c-0d67ffbd03a7'] = $pane;
  $display->panels['center'][1] = 'new-c75e6148-cead-4ea2-af5c-0d67ffbd03a7';
  $pane = new stdClass();
  $pane->pid = 'new-868f6a73-0d07-4077-9047-c62985347bbe';
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
  $pane->uuid = '868f6a73-0d07-4077-9047-c62985347bbe';
  $display->content['new-868f6a73-0d07-4077-9047-c62985347bbe'] = $pane;
  $display->panels['tools'][0] = 'new-868f6a73-0d07-4077-9047-c62985347bbe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c75e6148-cead-4ea2-af5c-0d67ffbd03a7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_news_in_course'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'courses_projects';
  $page->task = 'page';
  $page->admin_title = 'Courses - Projects';
  $page->admin_description = '';
  $page->path = 'course/projects/%1';
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
            1 => 'administrator member',
            2 => 'kurs-tutor',
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
    'type' => 'none',
    'settings' => NULL,
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
  $handler->name = 'page_courses_projects_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'courses_projects';
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
  $display->layout = 'flexible:span11span1_adminonly';
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
  $display->uuid = '1555d657-8e9e-4803-8e7d-c011fa8d3c5a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_projects_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7505661b-7887-49dc-bdc6-7fb44b7aa973';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<?php
  echo drupal_render(drupal_get_form(\'section_courses_group_projects_form\'));
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
  $pane->uuid = '7505661b-7887-49dc-bdc6-7fb44b7aa973';
  $display->content['new-7505661b-7887-49dc-bdc6-7fb44b7aa973'] = $pane;
  $display->panels['center'][0] = 'new-7505661b-7887-49dc-bdc6-7fb44b7aa973';
  $pane = new stdClass();
  $pane->pid = 'new-a3a34a48-0e11-448f-9239-a7fac8404a13';
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
  $pane->uuid = 'a3a34a48-0e11-448f-9239-a7fac8404a13';
  $display->content['new-a3a34a48-0e11-448f-9239-a7fac8404a13'] = $pane;
  $display->panels['tools'][0] = 'new-a3a34a48-0e11-448f-9239-a7fac8404a13';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a3a34a48-0e11-448f-9239-a7fac8404a13';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['courses_projects'] = $page;

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
    'type' => 'none',
    'settings' => NULL,
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
        'class' => 'col-md-8',
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
        'class' => 'col-md-4',
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
  $display->uuid = 'db6de0bb-41a3-47d0-9e2b-da58339b40de';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_courses_tasks_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bed6ecf9-9160-4ad7-8b76-c030266c2b17';
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
  $pane->uuid = 'bed6ecf9-9160-4ad7-8b76-c030266c2b17';
  $display->content['new-bed6ecf9-9160-4ad7-8b76-c030266c2b17'] = $pane;
  $display->panels['center'][0] = 'new-bed6ecf9-9160-4ad7-8b76-c030266c2b17';
  $pane = new stdClass();
  $pane->pid = 'new-02feeaeb-57ba-443e-8f06-43132dd80ab1';
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
  $pane->uuid = '02feeaeb-57ba-443e-8f06-43132dd80ab1';
  $display->content['new-02feeaeb-57ba-443e-8f06-43132dd80ab1'] = $pane;
  $display->panels['tools'][0] = 'new-02feeaeb-57ba-443e-8f06-43132dd80ab1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bed6ecf9-9160-4ad7-8b76-c030266c2b17';
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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'view',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_2',
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
              'annvid' => 'annvid',
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
  $display->uuid = '66dbe875-2d78-4243-bcf6-dce00d46273c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_domain_text_in_course_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fa24f570-f5a3-438f-9984-898feaec3bfd';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Edit Course Text Link',
    'title' => '<none>',
    'body' => '<?php 

  $active_course = _section_courses_get_active_course();
  if ($active_course) {
    //$nid = _section_courses_course_get_domain_id($active_course);
    if (arg(0) == \'course\' && arg(1) == \'text\' && is_numeric(arg(3))) {
      $nid = arg(3);
      if (node_access(\'update\', node_load($nid))) {
        echo \'<a class="btn btn-default" href="/domain/edit/\' . $nid . \'">Lehrtext bearbeiten (Themenbereich)</a>\';
      }
    }
  }

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
  $pane->uuid = 'fa24f570-f5a3-438f-9984-898feaec3bfd';
  $display->content['new-fa24f570-f5a3-438f-9984-898feaec3bfd'] = $pane;
  $display->panels['center'][0] = 'new-fa24f570-f5a3-438f-9984-898feaec3bfd';
  $pane = new stdClass();
  $pane->pid = 'new-d9b72f36-2b7e-46e0-bacf-00cc5c23ac5c';
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
  $pane->uuid = 'd9b72f36-2b7e-46e0-bacf-00cc5c23ac5c';
  $display->content['new-d9b72f36-2b7e-46e0-bacf-00cc5c23ac5c'] = $pane;
  $display->panels['center'][1] = 'new-d9b72f36-2b7e-46e0-bacf-00cc5c23ac5c';
  $pane = new stdClass();
  $pane->pid = 'new-d445add9-630c-48d1-b4e6-375b2d616005';
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
  $pane->uuid = 'd445add9-630c-48d1-b4e6-375b2d616005';
  $display->content['new-d445add9-630c-48d1-b4e6-375b2d616005'] = $pane;
  $display->panels['outline'][0] = 'new-d445add9-630c-48d1-b4e6-375b2d616005';
  $pane = new stdClass();
  $pane->pid = 'new-34bfc27b-c755-4677-a814-91555cdd9e92';
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
  $pane->uuid = '34bfc27b-c755-4677-a814-91555cdd9e92';
  $display->content['new-34bfc27b-c755-4677-a814-91555cdd9e92'] = $pane;
  $display->panels['outline'][1] = 'new-34bfc27b-c755-4677-a814-91555cdd9e92';
  $pane = new stdClass();
  $pane->pid = 'new-c2665aae-6b87-4bb0-af15-295aa2e40f87';
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
  $pane->uuid = 'c2665aae-6b87-4bb0-af15-295aa2e40f87';
  $display->content['new-c2665aae-6b87-4bb0-af15-295aa2e40f87'] = $pane;
  $display->panels['tools'][0] = 'new-c2665aae-6b87-4bb0-af15-295aa2e40f87';
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
    'type' => 'none',
    'settings' => NULL,
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
        'class' => 'col-md-8',
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
        'class' => 'col-md-4',
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
  $display->uuid = '728d6767-c85d-47c1-8938-6a608cc82baf';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_kursdokumente_in_kurs__panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6d5f5932-34cd-428b-9717-03b5c2b33e25';
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
  $pane->uuid = '6d5f5932-34cd-428b-9717-03b5c2b33e25';
  $display->content['new-6d5f5932-34cd-428b-9717-03b5c2b33e25'] = $pane;
  $display->panels['news'][0] = 'new-6d5f5932-34cd-428b-9717-03b5c2b33e25';
  $pane = new stdClass();
  $pane->pid = 'new-b372d922-dfb1-4cb5-aa5d-31969c655573';
  $pane->panel = 'news';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'kursdokumente-help',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p><em>Um die Kursdokumente zu sortieren, klicken Sie jeweils auf die obige Bezeichnung.</em></p>',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '300',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b372d922-dfb1-4cb5-aa5d-31969c655573';
  $display->content['new-b372d922-dfb1-4cb5-aa5d-31969c655573'] = $pane;
  $display->panels['news'][1] = 'new-b372d922-dfb1-4cb5-aa5d-31969c655573';
  $pane = new stdClass();
  $pane->pid = 'new-2c3766a5-4fa7-4741-815f-ebab25e174e9';
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
  $pane->uuid = '2c3766a5-4fa7-4741-815f-ebab25e174e9';
  $display->content['new-2c3766a5-4fa7-4741-815f-ebab25e174e9'] = $pane;
  $display->panels['tools'][0] = 'new-2c3766a5-4fa7-4741-815f-ebab25e174e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6d5f5932-34cd-428b-9717-03b5c2b33e25';
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
    'type' => 'none',
    'settings' => NULL,
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
        'class' => 'col-md-8',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-md-4',
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
        'class' => 'row',
      ),
      4 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 7,
        ),
        'class' => 'col-md-6',
      ),
      5 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 6,
        ),
        'class' => 'col-md-6',
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
        'class' => 'row',
      ),
      'main_' => array(
        'type' => 'region',
        'title' => 'main',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => 'col-md-12',
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_members_in_course_panel_context';
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
