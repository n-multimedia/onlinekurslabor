<?php
/**
 * @file
 * nm_section_content_features.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function nm_section_content_features_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:content_domain:add user'
  $permissions['node:content_domain:add user'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:administer group'
  $permissions['node:content_domain:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:approve and deny subscription'
  $permissions['node:content_domain:approve and deny subscription'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:create biblio content'
  $permissions['node:content_domain:create biblio content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create content_chapter content'
  $permissions['node:content_domain:create content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create content_multiple_choice content'
  $permissions['node:content_domain:create content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create content_question_and_answer content'
  $permissions['node:content_domain:create content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:create forum content'
  $permissions['node:content_domain:create forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:delete any biblio content'
  $permissions['node:content_domain:delete any biblio content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any content_chapter content'
  $permissions['node:content_domain:delete any content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any content_multiple_choice content'
  $permissions['node:content_domain:delete any content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any content_question_and_answer content'
  $permissions['node:content_domain:delete any content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete any forum content'
  $permissions['node:content_domain:delete any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:delete own biblio content'
  $permissions['node:content_domain:delete own biblio content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own content_chapter content'
  $permissions['node:content_domain:delete own content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own content_multiple_choice content'
  $permissions['node:content_domain:delete own content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own content_question_and_answer content'
  $permissions['node:content_domain:delete own content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:delete own forum content'
  $permissions['node:content_domain:delete own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:edit any master profile'
  $permissions['node:content_domain:edit any master profile'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:manage members'
  $permissions['node:content_domain:manage members'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:manage permissions'
  $permissions['node:content_domain:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:manage roles'
  $permissions['node:content_domain:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:subscribe'
  $permissions['node:content_domain:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:subscribe without approval'
  $permissions['node:content_domain:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:unsubscribe'
  $permissions['node:content_domain:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any biblio content'
  $permissions['node:content_domain:update any biblio content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any content_chapter content'
  $permissions['node:content_domain:update any content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any content_multiple_choice content'
  $permissions['node:content_domain:update any content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any content_question_and_answer content'
  $permissions['node:content_domain:update any content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update any forum content'
  $permissions['node:content_domain:update any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:update body field'
  $permissions['node:content_domain:update body field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_answer field'
  $permissions['node:content_domain:update field_answer field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_attachments field'
  $permissions['node:content_domain:update field_attachments field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_chapter_text field'
  $permissions['node:content_domain:update field_chapter_text field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_domain_description field'
  $permissions['node:content_domain:update field_domain_description field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_domain_picture field'
  $permissions['node:content_domain:update field_domain_picture field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_file_image_alt_text field'
  $permissions['node:content_domain:update field_file_image_alt_text field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_file_image_title_text field'
  $permissions['node:content_domain:update field_file_image_title_text field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_mc_solution field'
  $permissions['node:content_domain:update field_mc_solution field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_mc_task field'
  $permissions['node:content_domain:update field_mc_task field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_qaa_answer field'
  $permissions['node:content_domain:update field_qaa_answer field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_qaa_question field'
  $permissions['node:content_domain:update field_qaa_question field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update field_tableofcontents field'
  $permissions['node:content_domain:update field_tableofcontents field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update group'
  $permissions['node:content_domain:update group'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update group_group field'
  $permissions['node:content_domain:update group_group field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:update og_group_ref field'
  $permissions['node:content_domain:update og_group_ref field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update og_user_node field'
  $permissions['node:content_domain:update og_user_node field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:update own biblio content'
  $permissions['node:content_domain:update own biblio content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own content_chapter content'
  $permissions['node:content_domain:update own content_chapter content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own content_multiple_choice content'
  $permissions['node:content_domain:update own content_multiple_choice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own content_question_and_answer content'
  $permissions['node:content_domain:update own content_question_and_answer content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:update own forum content'
  $permissions['node:content_domain:update own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:update taxonomy_forums field'
  $permissions['node:content_domain:update taxonomy_forums field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:view any master profile'
  $permissions['node:content_domain:view any master profile'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:content_domain:view body field'
  $permissions['node:content_domain:view body field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_answer field'
  $permissions['node:content_domain:view field_answer field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_attachments field'
  $permissions['node:content_domain:view field_attachments field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_chapter_text field'
  $permissions['node:content_domain:view field_chapter_text field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_domain_description field'
  $permissions['node:content_domain:view field_domain_description field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_domain_picture field'
  $permissions['node:content_domain:view field_domain_picture field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_file_image_alt_text field'
  $permissions['node:content_domain:view field_file_image_alt_text field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_file_image_title_text field'
  $permissions['node:content_domain:view field_file_image_title_text field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_mc_solution field'
  $permissions['node:content_domain:view field_mc_solution field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_mc_task field'
  $permissions['node:content_domain:view field_mc_task field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_qaa_answer field'
  $permissions['node:content_domain:view field_qaa_answer field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_qaa_question field'
  $permissions['node:content_domain:view field_qaa_question field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view field_tableofcontents field'
  $permissions['node:content_domain:view field_tableofcontents field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:content_domain:view group_group field'
  $permissions['node:content_domain:view group_group field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view og_group_ref field'
  $permissions['node:content_domain:view og_group_ref field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view og_user_node field'
  $permissions['node:content_domain:view og_user_node field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:content_domain:view taxonomy_forums field'
  $permissions['node:content_domain:view taxonomy_forums field'] = array(
    'roles' => array(),
  );

  return $permissions;
}
