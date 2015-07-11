<?php

/**
 * Implements hook_rules_event_info().
 */
function fbss_comments_rules_rules_event_info() {
  return array(
    'fbss_comments_save' => array(
      'label' => t('User saves a new comment on a status'),
      'group' => t('Statuses Comments'),
      'variables' => array(
        'comment' => array(
          'type' => 'fbss_comment',
          'label' => t('The status comment.'),
        ),
      ),
    ),
    'fbss_comments_edit' => array(
      'label' => t('User edits a comment on a status'),
      'group' => t('Statuses Comments'),
      'variables' => array(
        'comment' => array(
          'type' => 'fbss_comment',
          'label' => t('The status comment.'),
        ),
      ),
    ),
    'fbss_comments_delete' => array(
      'label' => t('User deletes a comment on a status'),
      'group' => t('Statuses Comments'),
      'variables' => array(
        'comment' => array(
          'type' => 'fbss_comment',
          'label' => t('The status comment.'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function fbss_comments_rules_rules_condition_info() {
  return array(
    'fbss_comments_rules_on_own' => array(
      'label' => t('Comment was posted on own status'),
      'arguments' => array(
        'comment' => array(
          'type' => 'fbss_comment',
          'label' => t('The status comment.'),
        ),
      ),
      'group' => t('Statuses Comments'),
    ),
    'fbss_comments_rules_can_post' => array(
      'label' => t('User has permission to send a status comment'),
      'arguments' => array(),
      'group' => t('Statuses Comments'),
    ),
    'fbss_comments_rules_can_edit' => array(
      'label' => t('User has permission to edit a status comment'),
      'arguments' => array(
        'comment' => array(
          'type' => 'fbss_comment',
          'label' => t('The status comment.'),
        ),
      ),
      'group' => t('Statuses Comments'),
    ),
    'fbss_comments_rules_can_delete' => array(
      'label' => t('User has permission to delete a status comment'),
      'arguments' => array(
        'comment' => array(
          'type' => 'fbss_comment',
          'label' => t('The status comment.'),
        ),
      ),
      'group' => t('Statuses Comments'),
    ),
  );
}

/**
 * Check if a comment was posted on a user's own status.
 */
function fbss_comments_rules_on_own($comment) {
  $status = statuses_load($comment->sid);
  return $comment->uid == $status->sender;
}

/**
 * Check if a user can comment on a status.
 */
function fbss_comments_rules_can_post() {
  return fbss_comments_can('post', NULL);
}

/**
 * Check if a user can edit a status comment.
 */
function fbss_comments_rules_can_edit($comment) {
  return fbss_comments_can('edit', $comment);
}

/**
 * Check if a user can delete a status comment.
 */
function fbss_comments_rules_can_delete($comment) {
  return fbss_comments_can('delete', $comment);
}

/**
 * Implements hook_rules_action_info().
 */
function fbss_comments_rules_rules_action_info() {
  return array(
    'fbss_comments_rules_load_action' => array(
      'label' => t('Load a status comment'),
      'new variables' => array(
        'comment_loaded' => array(
          'type' => 'fbss_comment',
          'label' => t('Loaded status comment'),
        ),
      ),
      'help' => t('Enter the Comment ID of a status comment to load.'),
      'group' => t('Statuses Comments'),
      'parameter' => array(
        'cid' => array(
          'type' => 'integer',
          'label' => t('Status Comment ID'),
          'description' => t("Enter the Comment ID of a status comment to load."),
        ),
      ),
    ),
    'fbss_comments_rules_edit_action' => array(
      'label' => t('Edit a status comment'),
      'help' => t('Enter the Status Comment ID of the status comment to edit and the text you wish to replace the comment.'),
      'group' => t('Statuses Comments'),
      'parameter' => array(
        'cid' => array(
          'type' => 'integer',
          'label' => t('Status Comment ID'),
          'description' => t("Enter the Comment ID of a status comment to edit."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Comment message'),
          'description' => t("Enter the message for the Comment."),
        ),
      ),
    ),
    'fbss_comments_rules_delete_action' => array(
      'label' => t('Delete a status comment'),
      'help' => t('Enter the Status Comment ID of the status comment to delete.'),
      'group' => t('Statuses Comments'),
      'parameter' => array(
        'cid' => array(
          'type' => 'integer',
          'label' => t('Status Comment ID'),
          'description' => t("Enter the Comment ID of the status comment to delete."),
        ),
      ),
    ),
    'fbss_comments_rules_add_action' => array(
      'label' => t('Add a status comment'),
      'help' => t('Enter the status comment text, the ID of the relevant status, and the user ID of the creator of the comment.'),
      'group' => t('Statuses Comments'),
      'parameter' => array(
        'sid' => array(
          'type' => 'integer',
          'label' => t('Status ID'),
          'description' => t("Enter the ID of the status on which this comment will be posted."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Comment message'),
          'description' => t("Enter the message for the Comment."),
        ),
        'uid' => array(
          'type' => 'integer',
          'label' => t('User ID'),
          'description' => t("Enter the ID of the user who created this comment."),
          'optional' => TRUE,
        ),
      ),
    ),
  );
}

/**
 * Loads a status.
 */
function fbss_comments_rules_load_action($cid) {
  return array('comment_loaded' => fbss_comments_load($cid));
}

/**
 * Edits a status.
 */
function fbss_comments_rules_edit_action($cid, $message) {
  db_update('fbss_comments')
  ->fields(array(
    'comment' => $message,
  ))
  ->condition('cid', $cid)
  ->execute();
  $c = fbss_comments_load($cid);
  module_invoke_all('fbss_comments_after_save', $c, TRUE);
}

/**
 * Deletes a status.
 */
function fbss_comments_rules_delete_action($cid) {
  fbss_comments_delete_comment($cid);
}

/**
 * Adds a status comment.
 */
function fbss_comments_rules_add_action($sid, $message, $uid) {
  fbss_comments_save_comment($sid, $message, empty($uid) ? $GLOBALS['user']->uid : $uid);
}

/**
 * Implements hook_rules_data_type_info().
 */
function fbss_comments_rules_rules_data_type_info() {
  return array(
    'fbss_comment' => array(
      'label' => t('Statuses Comment'),
      'wrapper class' => 'FBSSCommentRulesDataWrapper',
      'wrap' => TRUE,
    ),
  );
}

/**
 * Defines the rules node data type.
 */
class FBSSCommentRulesDataWrapper extends RulesIdentifiableDataWrapper implements RulesDataWrapperSavableInterface {
  public function save() {
    $comment = $this->value();
    fbss_comments_save_comment($comment->sid, $comment->comment, $comment->uid);
    return TRUE;
  }
  protected function load($cid) {
    return fbss_comments_load($cid);
  }
  protected function extractIdentifier($comment) {
    return $comment->cid;
  }
}
