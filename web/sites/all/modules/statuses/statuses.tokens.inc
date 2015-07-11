<?php

/**
 * @file
 * Builds placeholder replacement tokens for status-related data.
 */

/**
 * Implements of hook_token_info().
 */
function statuses_token_info() {
  $types = array();
  $tokens = array();

  // Statuses tokens.
  $types['statuses'] = array(
    'name' => t('Statuses'),
    'description' => t('Tokens related to Status'),
    'needs-data' => 'statuses',
  );
  $tokens['statuses']['recipient-type-name'] = array(
    'name' => t('Recipient type (Machine name)'),
    'description' => t('The machine name of the stream type of the recipient.'),
  );
  $tokens['statuses']['recipient-type-title'] = array(
    'name' => t('Recipient type'),
    'description' => t('The readable name of the stream type of the recipient.'),
  );
  $tokens['statuses']['recipient-link'] = array(
    'name' => t('Recipient link'),
    'description' => t('A link to the recipient.'),
  );
  $tokens['statuses']['recipient-name'] = array(
    'name' => t('Recipient name'),
    'description' => t('The name of the recipient of the status message.'),
  );
  $tokens['statuses']['recipient-id'] = array(
    'name' => t('Recipient user ID'),
    'description' => t('The ID of the recipient of the status message.'),
  );
  $tokens['statuses']['message-unformatted'] = array(
    'name' => t('Unformatted message'),
    'description' => t('The status text.'),
  );
  $tokens['statuses']['message-formatted'] = array(
    'name' => t('Formatted message'),
    'description' => t('The status text completely themed.'),
  );
  $tokens['statuses']['status-themed'] = array(
    'name' => t('Themed status'),
    'description' => t('The new status completely themed, including usernames and times.'),
  );
  $tokens['statuses']['status-id'] = array(
    'name' => t('Status ID'),
    'description' => t('The Status ID.'),
  );
  $tokens['statuses']['status-url'] = array(
    'name' => t('Status URL'),
    'description' => t('The URL of the status message.'),
  );
  $tokens['statuses']['status-edit'] = array(
    'name' => t('Edit link'),
    'description' => t('Edit status link.'),
  );
  $tokens['statuses']['status-delete'] = array(
    'name' => t('Delete link'),
    'description' => t('Delete status link.'),
  );
  // Chained tokens for nodes.
  $tokens['statuses']['sender'] = array(
    'name' => t('Sender'),
    'description' => t('User who posted the status message.'),
    'type' => 'user',
  );
  $tokens['statuses']['created'] = array(
    'name' => t('Status created time'),
    'description' => t('The themed time the status was submitted.'),
    'type' => 'date',
  );
  if (module_exists('fbss_comments')) {
    // FBSS comments tokens.
    $tokens['statuses']['status-comment-count'] = array(
      'name' => t('Comment count'),
      'description' => t('The number of comments on the status.'),
    );
    $tokens['statuses']['comments-email'] = array(
      'name' => t('Email suitable comments'),
      'description' => t('The comments with inline styling suitable for emails.'),
    );
  }

  return array(
    'types' => $types,
    'tokens' => $tokens,
  );
}

/**
 * Implements hook_tokens().
 */
function statuses_tokens($type, $tokens, array $data = array(), array $options = array()) {
  if ($type != 'statuses' || empty($data['statuses'])) {
    return;
  }
  $sanitize = !empty($options['sanitize']);
  $replacements = array();
  $status = $data['statuses'];
  $context = statuses_determine_context($status->type);

  $sender = user_load($status->sender);
  $recipient = $context['handler']->load_recipient($status->recipient);

  foreach ($tokens as $name => $original) {
    switch ($name) {
      case 'recipient-type-name':
        $replacements[$original] = $status->type;
        break;
      case 'recipient-type-title':
        $replacements[$original] = $context['title'];
        break;
      case 'recipient-link':
        $replacements[$original] = $context['handler']->recipient_link($recipient);
        break;
      case 'recipient-name':
        $replacements[$original] = $sanitize ? check_plain($context['handler']->recipient_name($recipient)) : $context['handler']->recipient_name($recipient);
        break;
      case 'recipient-id':
        $replacements[$original] = $context['handler']->recipient_id($recipient);
        break;
      case 'message-unformatted':
        $replacements[$original] = $sanitize ? check_plain($status->message) : $status->message;
        break;
      case 'message-formatted':
        $message_formatted = _statuses_run_filter($status->message);
        if (variable_get('statuses_nl2br', 0)) {
          $message_formatted = nl2br($message_formatted);
        }
        $replacements[$original] = $message_formatted;
        break;
      case 'status-themed':
        $replacements[$original] = statuses_show($status);
        break;
      case 'status-id':
        $replacements[$original] = $status->sid;
        break;
      case 'status-url':
        $url = url('statuses/'. $status->sid, array('absolute' => TRUE));
        $replacements[$original] = $url;
        break;
      case 'status-edit':
        $edit = '';
        if (statuses_user_access('edit', $status)) {
          $edit = '<span class="statuses-edit-link statuses-action-link">' . l(t('Edit'), 'statuses/' . $status->sid . '/edit') . '</span>';
        }
        $replacements[$original] = $edit;
        break;
      case 'status-delete':
        $delete = '';
        if (statuses_user_access('delete', $status)) {
          $delete = '<span class="statuses-delete-link statuses-action-link">' .  l(t('Delete'), 'statuses/' . $status->sid . '/delete') . '</span>';
        }
        $replacements[$original] = $delete;
        break;
      // Default value for the chained token.
      case 'sender':
        $name = format_username($sender);
        $replacements[$original] = $sanitize ? check_plain($name) : name;
        break;
      case 'created':
        $replacements[$original] = format_date($status->created, 'short');
        break;
      // Tokens related to status comment
      case 'status-comment-count':
        $replacements[$original] = module_exists('fbss_comments') ? fbss_comments_count_comments($status->sid) : 0;
        break;
      case 'comments-email':
        $replacements[$original] = module_exists('fbss_comments') ? theme('fbss_comments_items_email', array('comments' => fbss_comments_get_comments($status->sid, TRUE), 'destination' => $url)) : '';
        break;
    }
  }
  if ($created_tokens = token_find_with_prefix($tokens, 'created')) {
    $replacements += token_generate('date', $created_tokens, array('date' => $status->created), $options);
  }

  if (($sender_tokens = token_find_with_prefix($tokens, 'sender'))) {
    $replacements += token_generate('user', $sender_tokens, array('user' => $sender), $options);
  }
  return $replacements;
}
