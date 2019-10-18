<?php

/**
 * @file
 * nm_section_content_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nm_section_content_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access biblio content'.
  $permissions['access biblio content'] = array(
    'name' => 'access biblio content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access printer-friendly version'.
  $permissions['access printer-friendly version'] = array(
    'name' => 'access printer-friendly version',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'book',
  );

  // Exported permission: 'add content to books'.
  $permissions['add content to books'] = array(
    'name' => 'add content to books',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'book',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Student' => 'Student',
      'administrator' => 'administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer biblio'.
  $permissions['administer biblio'] = array(
    'name' => 'administer biblio',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'administer book outlines'.
  $permissions['administer book outlines'] = array(
    'name' => 'administer book outlines',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'book',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(),
    'module' => 'media',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create biblio content'.
  $permissions['create biblio content'] = array(
    'name' => 'create biblio content',
    'roles' => array(
      'Autor' => 'Autor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create content_chapter content'.
  $permissions['create content_chapter content'] = array(
    'name' => 'create content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create content_domain content'.
  $permissions['create content_domain content'] = array(
    'name' => 'create content_domain content',
    'roles' => array(
      'Autor' => 'Autor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create content_multiple_choice content'.
  $permissions['create content_multiple_choice content'] = array(
    'name' => 'create content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create content_question_and_answer content'.
  $permissions['create content_question_and_answer content'] = array(
    'name' => 'create content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create new books'.
  $permissions['create new books'] = array(
    'name' => 'create new books',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'book',
  );

  // Exported permission: 'delete any biblio content'.
  $permissions['delete any biblio content'] = array(
    'name' => 'delete any biblio content',
    'roles' => array(
      'Autor' => 'Autor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any content_chapter content'.
  $permissions['delete any content_chapter content'] = array(
    'name' => 'delete any content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any content_domain content'.
  $permissions['delete any content_domain content'] = array(
    'name' => 'delete any content_domain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any content_multiple_choice content'.
  $permissions['delete any content_multiple_choice content'] = array(
    'name' => 'delete any content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any content_question_and_answer content'.
  $permissions['delete any content_question_and_answer content'] = array(
    'name' => 'delete any content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own biblio content'.
  $permissions['delete own biblio content'] = array(
    'name' => 'delete own biblio content',
    'roles' => array(
      'Autor' => 'Autor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own content_chapter content'.
  $permissions['delete own content_chapter content'] = array(
    'name' => 'delete own content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own content_domain content'.
  $permissions['delete own content_domain content'] = array(
    'name' => 'delete own content_domain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own content_multiple_choice content'.
  $permissions['delete own content_multiple_choice content'] = array(
    'name' => 'delete own content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own content_question_and_answer content'.
  $permissions['delete own content_question_and_answer content'] = array(
    'name' => 'delete own content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any biblio content'.
  $permissions['edit any biblio content'] = array(
    'name' => 'edit any biblio content',
    'roles' => array(
      'Autor' => 'Autor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any content_chapter content'.
  $permissions['edit any content_chapter content'] = array(
    'name' => 'edit any content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any content_domain content'.
  $permissions['edit any content_domain content'] = array(
    'name' => 'edit any content_domain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any content_multiple_choice content'.
  $permissions['edit any content_multiple_choice content'] = array(
    'name' => 'edit any content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any content_question_and_answer content'.
  $permissions['edit any content_question_and_answer content'] = array(
    'name' => 'edit any content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit biblio authors'.
  $permissions['edit biblio authors'] = array(
    'name' => 'edit biblio authors',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'edit by all biblio authors'.
  $permissions['edit by all biblio authors'] = array(
    'name' => 'edit by all biblio authors',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'edit own biblio content'.
  $permissions['edit own biblio content'] = array(
    'name' => 'edit own biblio content',
    'roles' => array(
      'Autor' => 'Autor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own content_chapter content'.
  $permissions['edit own content_chapter content'] = array(
    'name' => 'edit own content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own content_domain content'.
  $permissions['edit own content_domain content'] = array(
    'name' => 'edit own content_domain content',
    'roles' => array(
      'Autor' => 'Autor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own content_multiple_choice content'.
  $permissions['edit own content_multiple_choice content'] = array(
    'name' => 'edit own content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own content_question_and_answer content'.
  $permissions['edit own content_question_and_answer content'] = array(
    'name' => 'edit own content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'import from file'.
  $permissions['import from file'] = array(
    'name' => 'import from file',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'show download links'.
  $permissions['show download links'] = array(
    'name' => 'show download links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'show export links'.
  $permissions['show export links'] = array(
    'name' => 'show export links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'show filter tab'.
  $permissions['show filter tab'] = array(
    'name' => 'show filter tab',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message'.
  $permissions['show format selection for message'] = array(
    'name' => 'show format selection for message',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message_type'.
  $permissions['show format selection for message_type'] = array(
    'name' => 'show format selection for message_type',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message_type_category'.
  $permissions['show format selection for message_type_category'] = array(
    'name' => 'show format selection for message_type_category',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for og_membership'.
  $permissions['show format selection for og_membership'] = array(
    'name' => 'show format selection for og_membership',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for og_membership_type'.
  $permissions['show format selection for og_membership_type'] = array(
    'name' => 'show format selection for og_membership_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for profile2'.
  $permissions['show format selection for profile2'] = array(
    'name' => 'show format selection for profile2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for relation'.
  $permissions['show format selection for relation'] = array(
    'name' => 'show format selection for relation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show own download links'.
  $permissions['show own download links'] = array(
    'name' => 'show own download links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'show sort links'.
  $permissions['show sort links'] = array(
    'name' => 'show sort links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Autor' => 'Autor',
      'Dozent' => 'Dozent',
      'Moderator' => 'Moderator',
      'Student' => 'Student',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view full text'.
  $permissions['view full text'] = array(
    'name' => 'view full text',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Autor' => 'Autor',
      'Moderator' => 'Moderator',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
