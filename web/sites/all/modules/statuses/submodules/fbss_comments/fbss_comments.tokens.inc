<?php

/**
 * @file
 * Builds placeholder replacement tokens for status comment-related data.
 */

/**
 * Implements of hook_token_info().
 */
function fbss_comments_token_info() {
  $types = array();
  $tokens = array();

  // Statuses Comments tokens.
  $types['fbss_comment'] = array(
    'name' => t('Statuses Comments'),
    'description' => t('Tokens related to Status Comment'),
    'needs-data' => 'fbss_comment',
  );
  $tokens['fbss_comment']['message-unformatted'] = array(
    'name' => t('Unformatted comment'),
    'description' => t('The comment text.'),
  );
  $tokens['fbss_comment']['message-formatted'] = array(
    'name' => t('Formatted comment'),
    'description' => t('The formatted comment text.'),
  );
  $tokens['fbss_comment']['comment-themed'] = array(
    'name' => t('Themed comment'),
    'description' => t('The new comment completely themed, including usernames and times.'),
  );
  $tokens['fbss_comment']['comment-id'] = array(
    'name' => t('Comment ID'),
    'description' => t('The Comment ID.'),
  );
  $tokens['fbss_comment']['comment-status-id'] = array(
    'name' => t('Status ID'),
    'description' => t('The Status ID of the releated status message.'),
  );
  $tokens['fbss_comment']['comment-status-url'] = array(
    'name' => t('Recipient link'),
    'description' => t('The URL of the related status message.'),
  );
  $tokens['fbss_comment']['comment-edit'] = array(
    'name' => t('Edit link'),
    'description' => t('Edit comment link.'),
  );
  $tokens['fbss_comment']['comment-delete'] = array(
    'name' => t('Delete link'),
    'description' => t('Delete comment link.'),
  );
  // Chained tokens for nodes.
  $tokens['fbss_comment']['commenter'] = array(
    'name' => t('Commenter'),
    'description' => t('User who posted the status comment.'),
    'type' => 'user',
  );
  $tokens['fbss_comment']['comment-created'] = array(
    'name' => t('Comment submitted time'),
    'description' => t('The themed time the comment was submitted.'),
    'type' => 'date',
  );

  return array(
    'types' => $types,
    'tokens' => $tokens,
  );
}

/**
 * Implements hook_tokens().
 */
function fbss_comments_tokens($type, $tokens, array $data = array(), array $options = array()) {
  if ($type != 'fbss_comment' || empty($data['fbss_comment'])) {
    return;
  }
  $sanitize = !empty($options['sanitize']);
  $replacements = array();
  $comment = $data['fbss_comment'];
  $account = user_load($comment->uid);

  foreach ($tokens as $name => $original) {
    switch ($name) {
      case 'message-unformatted':
        $replacements[$original] = $sanitize ? check_plain($comment->comment) : $comment->comment;
        break;
      case 'message-formatted':
        $replacements[$original] = nl2br(_statuses_run_filter($comment->comment));
        break;
      case 'comment-themed':
        $replacements[$original] = theme('fbss_comments_item', array('comment' => $comment, 'classes' => array(), 'destination' => $_GET['q']));
        break;
      case 'comment-id':
        $replacements[$original] = $comment->cid;
        break;
      case 'comment-status-id':
        $replacements[$original] = $comment->sid;
        break;
      case 'comment-status-url':
        $replacements[$original] = url('statuses/' . $comment->sid, array('absolute' => TRUE));
        break;
      case 'comment-edit':
        $edit = '';
        if (fbss_comments_can('edit', $comment)) {
          $edit = '<span class="fbss-comments-edit-delete">' .
            l(t('Edit'), 'statuses/comment/' . $comment->cid . '/edit', array('query' => array('destination' => $_GET['q'])))
            . '</span>';
        }
        $replacements[$original] = $edit;
        break;
      case 'comment-delete':
        $delete = '';
        if (fbss_comments_can('delete', $comment)) {
          $delete = '<span class="fbss-comments-edit-delete">' .
            l(t('Delete'), 'statuses/comment/' . $comment->cid . '/delete', array('query' => array('destination' => $_GET['q'])))
            . '</span>';
        }
        $replacements[$original] = $delete;
        break;
      // Default value for the chained token.
      case 'commenter':
        $name = format_username($account);
        $replacements[$original] = $sanitize ? check_plain($name) : $name;
        break;
      case 'comment-created':
        $replacements[$original] = format_date($comment->created, 'short');
        break;
    }
  }
  if ($created_tokens = token_find_with_prefix($tokens, 'comment-created')) {
    $replacements += token_generate('date', $created_tokens, array('date' => $comment->created), $options);
  }

  if (($sender_tokens = token_find_with_prefix($tokens, 'commenter'))) {
    $replacements += token_generate('user', $sender_tokens, array('user' => $account), $options);
  }
  return $replacements;
}
