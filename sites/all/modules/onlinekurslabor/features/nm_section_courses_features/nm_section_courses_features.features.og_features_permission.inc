<?php
/**
 * @file
 * nm_section_courses_features.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function nm_section_courses_features_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:courses_course:add user'
  $permissions['node:courses_course:add user'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:administer group'
  $permissions['node:courses_course:administer group'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:approve and deny subscription'
  $permissions['node:courses_course:approve and deny subscription'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_docs content'
  $permissions['node:courses_course:create courses_docs content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_generic_task content'
  $permissions['node:courses_course:create courses_generic_task content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_generic_task_solution content'
  $permissions['node:courses_course:create courses_generic_task_solution content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_group content'
  $permissions['node:courses_course:create courses_group content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:create courses_news content'
  $permissions['node:courses_course:create courses_news content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:create forum content'
  $permissions['node:courses_course:create forum content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_docs content'
  $permissions['node:courses_course:delete any courses_docs content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_generic_task content'
  $permissions['node:courses_course:delete any courses_generic_task content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_generic_task_solution content'
  $permissions['node:courses_course:delete any courses_generic_task_solution content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_group content'
  $permissions['node:courses_course:delete any courses_group content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any courses_news content'
  $permissions['node:courses_course:delete any courses_news content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete any forum content'
  $permissions['node:courses_course:delete any forum content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_docs content'
  $permissions['node:courses_course:delete own courses_docs content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_generic_task content'
  $permissions['node:courses_course:delete own courses_generic_task content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_generic_task_solution content'
  $permissions['node:courses_course:delete own courses_generic_task_solution content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_group content'
  $permissions['node:courses_course:delete own courses_group content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own courses_news content'
  $permissions['node:courses_course:delete own courses_news content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:delete own forum content'
  $permissions['node:courses_course:delete own forum content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:manage members'
  $permissions['node:courses_course:manage members'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:manage permissions'
  $permissions['node:courses_course:manage permissions'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:manage roles'
  $permissions['node:courses_course:manage roles'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:moderate'
  $permissions['node:courses_course:moderate'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:subscribe'
  $permissions['node:courses_course:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:subscribe without approval'
  $permissions['node:courses_course:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:unsubscribe'
  $permissions['node:courses_course:unsubscribe'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_docs content'
  $permissions['node:courses_course:update any courses_docs content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_generic_task content'
  $permissions['node:courses_course:update any courses_generic_task content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_generic_task_solution content'
  $permissions['node:courses_course:update any courses_generic_task_solution content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_group content'
  $permissions['node:courses_course:update any courses_group content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update any courses_news content'
  $permissions['node:courses_course:update any courses_news content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update any forum content'
  $permissions['node:courses_course:update any forum content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update body field'
  $permissions['node:courses_course:update body field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_attachments field'
  $permissions['node:courses_course:update field_attachments field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_course_docs field'
  $permissions['node:courses_course:update field_course_docs field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_course_header field'
  $permissions['node:courses_course:update field_course_header field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_course:update field_course_picture field'
  $permissions['node:courses_course:update field_course_picture field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_file_image_alt_text field'
  $permissions['node:courses_course:update field_file_image_alt_text field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_file_image_title_text field'
  $permissions['node:courses_course:update field_file_image_title_text field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_long_description field'
  $permissions['node:courses_course:update field_long_description field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_short_description field'
  $permissions['node:courses_course:update field_short_description field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_subtitle field'
  $permissions['node:courses_course:update field_subtitle field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_task_type field'
  $permissions['node:courses_course:update field_task_type field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_time_span field'
  $permissions['node:courses_course:update field_time_span field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_vhb_lvnr field'
  $permissions['node:courses_course:update field_vhb_lvnr field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update field_workload field'
  $permissions['node:courses_course:update field_workload field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update group'
  $permissions['node:courses_course:update group'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update group_access field'
  $permissions['node:courses_course:update group_access field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update group_group field'
  $permissions['node:courses_course:update group_group field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update og_group_ref field'
  $permissions['node:courses_course:update og_group_ref field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_docs content'
  $permissions['node:courses_course:update own courses_docs content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_generic_task content'
  $permissions['node:courses_course:update own courses_generic_task content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_generic_task_solution content'
  $permissions['node:courses_course:update own courses_generic_task_solution content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_group content'
  $permissions['node:courses_course:update own courses_group content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update own courses_news content'
  $permissions['node:courses_course:update own courses_news content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:update own forum content'
  $permissions['node:courses_course:update own forum content'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:update taxonomy_forums field'
  $permissions['node:courses_course:update taxonomy_forums field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:view body field'
  $permissions['node:courses_course:view body field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_attachments field'
  $permissions['node:courses_course:view field_attachments field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_collaborative_features field'
  $permissions['node:courses_course:view field_collaborative_features field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_course_docs field'
  $permissions['node:courses_course:view field_course_docs field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_course_header field'
  $permissions['node:courses_course:view field_course_header field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_course_picture field'
  $permissions['node:courses_course:view field_course_picture field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_long_description field'
  $permissions['node:courses_course:view field_long_description field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_short_description field'
  $permissions['node:courses_course:view field_short_description field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_subtitle field'
  $permissions['node:courses_course:view field_subtitle field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_task_handling_period field'
  $permissions['node:courses_course:view field_task_handling_period field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_task_type field'
  $permissions['node:courses_course:view field_task_type field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_time_span field'
  $permissions['node:courses_course:view field_time_span field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_vhb_lvnr field'
  $permissions['node:courses_course:view field_vhb_lvnr field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_course:view field_workload field'
  $permissions['node:courses_course:view field_workload field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view group_access field'
  $permissions['node:courses_course:view group_access field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
    ),
  );

  // Exported og permission: 'node:courses_course:view group_group field'
  $permissions['node:courses_course:view group_group field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_course:view taxonomy_forums field'
  $permissions['node:courses_course:view taxonomy_forums field'] = array(
    'roles' => array(
      'course-administrator' => 'course-administrator',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:add user'
  $permissions['node:courses_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:administer group'
  $permissions['node:courses_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:approve and deny subscription'
  $permissions['node:courses_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:create courses_docs content'
  $permissions['node:courses_group:create courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create courses_generic_task content'
  $permissions['node:courses_group:create courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create courses_generic_task_solution content'
  $permissions['node:courses_group:create courses_generic_task_solution content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:create courses_group content'
  $permissions['node:courses_group:create courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create courses_news content'
  $permissions['node:courses_group:create courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:create forum content'
  $permissions['node:courses_group:create forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_docs content'
  $permissions['node:courses_group:delete any courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_generic_task content'
  $permissions['node:courses_group:delete any courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_generic_task_solution content'
  $permissions['node:courses_group:delete any courses_generic_task_solution content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_group content'
  $permissions['node:courses_group:delete any courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any courses_news content'
  $permissions['node:courses_group:delete any courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete any forum content'
  $permissions['node:courses_group:delete any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_docs content'
  $permissions['node:courses_group:delete own courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_generic_task content'
  $permissions['node:courses_group:delete own courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_generic_task_solution content'
  $permissions['node:courses_group:delete own courses_generic_task_solution content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_group content'
  $permissions['node:courses_group:delete own courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own courses_news content'
  $permissions['node:courses_group:delete own courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:delete own forum content'
  $permissions['node:courses_group:delete own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:manage members'
  $permissions['node:courses_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:manage permissions'
  $permissions['node:courses_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:manage roles'
  $permissions['node:courses_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:moderate'
  $permissions['node:courses_group:moderate'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:subscribe'
  $permissions['node:courses_group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:subscribe without approval'
  $permissions['node:courses_group:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:unsubscribe'
  $permissions['node:courses_group:unsubscribe'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:update any courses_docs content'
  $permissions['node:courses_group:update any courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any courses_generic_task content'
  $permissions['node:courses_group:update any courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any courses_generic_task_solution content'
  $permissions['node:courses_group:update any courses_generic_task_solution content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:update any courses_group content'
  $permissions['node:courses_group:update any courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any courses_news content'
  $permissions['node:courses_group:update any courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update any forum content'
  $permissions['node:courses_group:update any forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update body field'
  $permissions['node:courses_group:update body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update field_answer field'
  $permissions['node:courses_group:update field_answer field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update field_attachments field'
  $permissions['node:courses_group:update field_attachments field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update field_course_docs field'
  $permissions['node:courses_group:update field_course_docs field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update field_course_header field'
  $permissions['node:courses_group:update field_course_header field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update field_course_picture field'
  $permissions['node:courses_group:update field_course_picture field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update field_short_description field'
  $permissions['node:courses_group:update field_short_description field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update field_subtitle field'
  $permissions['node:courses_group:update field_subtitle field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update field_task_handling_period field'
  $permissions['node:courses_group:update field_task_handling_period field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update field_task_type field'
  $permissions['node:courses_group:update field_task_type field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update field_time_span field'
  $permissions['node:courses_group:update field_time_span field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update field_vhb_lvnr field'
  $permissions['node:courses_group:update field_vhb_lvnr field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update field_workload field'
  $permissions['node:courses_group:update field_workload field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update group'
  $permissions['node:courses_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update group_access field'
  $permissions['node:courses_group:update group_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update group_group field'
  $permissions['node:courses_group:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update og_group_ref field'
  $permissions['node:courses_group:update og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:courses_group:update own courses_docs content'
  $permissions['node:courses_group:update own courses_docs content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own courses_generic_task content'
  $permissions['node:courses_group:update own courses_generic_task content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own courses_generic_task_solution content'
  $permissions['node:courses_group:update own courses_generic_task_solution content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:courses_group:update own courses_group content'
  $permissions['node:courses_group:update own courses_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own courses_news content'
  $permissions['node:courses_group:update own courses_news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update own forum content'
  $permissions['node:courses_group:update own forum content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:update taxonomy_forums field'
  $permissions['node:courses_group:update taxonomy_forums field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:view body field'
  $permissions['node:courses_group:view body field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:view field_attachments field'
  $permissions['node:courses_group:view field_attachments field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:view field_collaborative_features field'
  $permissions['node:courses_group:view field_collaborative_features field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:view field_course_docs field'
  $permissions['node:courses_group:view field_course_docs field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:view field_course_header field'
  $permissions['node:courses_group:view field_course_header field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:courses_group:view field_course_picture field'
  $permissions['node:courses_group:view field_course_picture field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:view og_group_ref field'
  $permissions['node:courses_group:view og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:courses_group:view taxonomy_forums field'
  $permissions['node:courses_group:view taxonomy_forums field'] = array(
    'roles' => array(),
  );

  return $permissions;
}
