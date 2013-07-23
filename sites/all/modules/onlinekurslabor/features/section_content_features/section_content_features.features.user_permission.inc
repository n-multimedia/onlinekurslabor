<?php
/**
 * @file
 * section_content_features.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function section_content_features_user_default_permissions() {
  $permissions = array();

  // Exported permission: create biblio content.
  $permissions['create biblio content'] = array(
    'name' => 'create biblio content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create content_chapter content.
  $permissions['create content_chapter content'] = array(
    'name' => 'create content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create content_domain content.
  $permissions['create content_domain content'] = array(
    'name' => 'create content_domain content',
    'roles' => array(
      'Autor' => 'Autor',
    ),
    'module' => 'node',
  );

  // Exported permission: create content_multiple_choice content.
  $permissions['create content_multiple_choice content'] = array(
    'name' => 'create content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create content_question_and_answer content.
  $permissions['create content_question_and_answer content'] = array(
    'name' => 'create content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any biblio content.
  $permissions['delete any biblio content'] = array(
    'name' => 'delete any biblio content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any content_chapter content.
  $permissions['delete any content_chapter content'] = array(
    'name' => 'delete any content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any content_domain content.
  $permissions['delete any content_domain content'] = array(
    'name' => 'delete any content_domain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any content_multiple_choice content.
  $permissions['delete any content_multiple_choice content'] = array(
    'name' => 'delete any content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any content_question_and_answer content.
  $permissions['delete any content_question_and_answer content'] = array(
    'name' => 'delete any content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own biblio content.
  $permissions['delete own biblio content'] = array(
    'name' => 'delete own biblio content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own content_chapter content.
  $permissions['delete own content_chapter content'] = array(
    'name' => 'delete own content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own content_domain content.
  $permissions['delete own content_domain content'] = array(
    'name' => 'delete own content_domain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own content_multiple_choice content.
  $permissions['delete own content_multiple_choice content'] = array(
    'name' => 'delete own content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own content_question_and_answer content.
  $permissions['delete own content_question_and_answer content'] = array(
    'name' => 'delete own content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any biblio content.
  $permissions['edit any biblio content'] = array(
    'name' => 'edit any biblio content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any content_chapter content.
  $permissions['edit any content_chapter content'] = array(
    'name' => 'edit any content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any content_domain content.
  $permissions['edit any content_domain content'] = array(
    'name' => 'edit any content_domain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any content_multiple_choice content.
  $permissions['edit any content_multiple_choice content'] = array(
    'name' => 'edit any content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any content_question_and_answer content.
  $permissions['edit any content_question_and_answer content'] = array(
    'name' => 'edit any content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own biblio content.
  $permissions['edit own biblio content'] = array(
    'name' => 'edit own biblio content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own content_chapter content.
  $permissions['edit own content_chapter content'] = array(
    'name' => 'edit own content_chapter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own content_domain content.
  $permissions['edit own content_domain content'] = array(
    'name' => 'edit own content_domain content',
    'roles' => array(
      'Autor' => 'Autor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own content_multiple_choice content.
  $permissions['edit own content_multiple_choice content'] = array(
    'name' => 'edit own content_multiple_choice content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own content_question_and_answer content.
  $permissions['edit own content_question_and_answer content'] = array(
    'name' => 'edit own content_question_and_answer content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
