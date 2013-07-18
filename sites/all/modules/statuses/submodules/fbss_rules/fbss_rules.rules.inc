<?php

/**
 * @file
 *   Rules integration.
 */

/**
 * Implements hook_rules_event_info().
 */
function fbss_rules_rules_event_info() {
  return array(
    'statuses_delete' => array(
      'label' => t('User deletes a status'),
      'group' => t('Statuses'),
      'variables' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status.'),
        ),
      ),
    ),
    'statuses_edit' => array(
      'label' => t('User edits a status'),
      'group' => t('Statuses'),
      'variables' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status.'),
        ),
      ),
    ),
    'statuses_save' => array(
      'label' => t('User saves a status'),
      'group' => t('Statuses'),
      'variables' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status.'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function fbss_rules_rules_condition_info() {
  return array(
    'fbss_rules_is_self' => array(
      'label' => t('Status was posted to own profile'),
      'arguments' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status'),
        ),
      ),
      'group' => t('Statuses'),
    ),
    'fbss_rules_can_post' => array(
      'label' => t('User has permission to send a status message'),
      'arguments' => array(
        'recipient' => array(
          'type' => 'user',
          'label' => t('The ID of the object to which the status will be posted.'),
        ),
        'recipient_type' => array(
          'type' => 'text',
          'label' => t('Recipient type'),
          'restriction' => 'input',
          'options list' => 'fbss_can_post_recipient_types',
          'optional' => TRUE,
          'description' =>  t('The types of recipients allowed for this condition to be true.'),
        ),
        'sender' => array(
          'type' => 'user',
          'label' => t('Sender'),
        ),
      ),
      'group' => 'Statuses',
    ),
    'fbss_rules_rules_condition_can_edit' => array(
      'label' => t('User has permission to edit a status'),
      'arguments' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status'),
        ),
      ),
      'group' => 'Statuses',
    ),
    'fbss_rules_rules_condition_can_delete' => array(
      'label' => t('User has permission to delete a status'),
      'arguments' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status'),
        ),
      ),
      'group' => 'Statuses',
    ),
    'fbss_rules_rules_condition_is_type' => array(
      'label' => t('Status recipient is a certain type'),
      'arguments' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status'),
        ),
        'recipient_types' => array(
          'type' => 'list<text>',
          'label' => t('Recipient type'),
          'restriction' => 'input',
          'options list' => 'fbss_recipient_types',
          'optional' => TRUE,
          'description' =>  t('The types of recipients allowed for this condition to be true.'),
        ),
      ),
      'group' => 'Statuses',
    ),
  );
}

/**
 * Checks if the status was posted to the user's own profile.
 */
function fbss_rules_is_self($status) {
  return $status->sender == $status->recipient && $status->type == 'user';
}

/**
 * Generates the options for the fbss_rules_rules_condition_is_type condition.
 */
function fbss_recipient_types() {
  $contexts = statuses_all_contexts();
  $options = array();
  foreach ($contexts as $key => $context) {
    $options[$key] = $context['title'];
  }
  return  $options;
}

/**
 * Generate the options for the fbss_rules_can_post condition
 */
function fbss_can_post_recipient_types() {
  $options = array('auto' => t('Automatically determined'));
  return array_merge($options, fbss_recipient_types());
}

/**
 * Checks if the user is allowed to post a status.
 */
function fbss_rules_can_post($recipient, $recipient_type, $sender) {
  if ($recipient_type == 'auto') {
    $context = statuses_determine_context();
    $recipient_type = $context['handler']->type();
  }
  return statuses_user_access('add', $recipient, $recipient_type, $sender);
}

/**
 * Checks if the status recipient is one of a specified type.
 */
function fbss_rules_rules_condition_is_type($status, $recipient_types) {
  if (empty($recipient_types)) {
    return FALSE;
  }
  return !empty($recipient_types[$status->type]);
}

/**
 * Checks if the current user can edit the status.
 */
function fbss_rules_rules_condition_can_edit($status) {
  return statuses_user_access('edit', $status);
}

/**
 * Checks if the current user can delete the status.
 */
function fbss_rules_rules_condition_can_delete($status) {
  return statuses_user_access('delete', $status);
}

/**
 * Implements hook_rules_action_info().
 */
function fbss_rules_rules_action_info() {
  return array(
    'fbss_rules_load_action' => array(
      'label' => t('Load a status'),
      'new variables' => array(
        'status_loaded' => array(
          'type' => 'statuses',
          'label' => t('Loaded status'),
        ),
      ),
      'help' => t('Enter the Status ID of a status to load.'),
      'group' => t('Statuses'),
      'parameter' => array(
        'sid' => array(
          'type' => 'integer',
          'label' => t('Status ID'),
          'description' => t("Enter the Status ID of a status to load."),
        ),
      ),
    ),
    'fbss_rules_edit_action' => array(
      'label' => t('Edit a status'),
      'help' => t('Enter the Status ID of the status to edit and the text you wish to replace the status.'),
      'group' => t('Statuses'),
      'parameter' => array(
        'sid' => array(
          'type' => 'integer',
          'label' => t('Status ID'),
          'description' => t("Enter the Status ID of a status to edit."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("Enter the message for the status."),
          'optional' => TRUE,
        ),
      ),
    ),
    'fbss_rules_delete_action' => array(
      'label' => t('Delete a status'),
      'help' => t('Enter the Status ID of the status to delete.'),
      'group' => t('Statuses'),
      'parameter' => array(
        'sid' => array(
          'type' => 'integer',
          'label' => t('Status ID'),
          'description' => t("Enter the Status ID of a status to load."),
        ),
      ),
    ),
    'fbss_rules_add_action' => array(
      'label' => t('Add a status'),
      'help' => t('Enter the status text and the ID and type of the recipient to which the status will be posted.'),
      'group' => t('Statuses'),
      'parameter' => array(
        'sender' => array(
          'type' => 'user',
          'label' => t('Sender name'),
          'description' => t("Enter the Sender name."),
        ),
        'recipient' => array(
          'type' => 'integer',
          'label' => t('Rcipient ID'),
          'description' => t("Enter the Recipient ID."),
        ),
        'recipient_types' => array(
          'type' => 'text',
          'label' => t('Recipient type'),
          'restriction' => 'input',
          'options list' => 'fbss_recipient_types',
          'description' =>  t('Enter the type for the new Status'),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("Enter the message for the status."),
        ),
      ),
    ),
  );
}

/**
 * Loads a status.
 */
function fbss_rules_load_action($sid) {
  return array('status_loaded' => statuses_load($sid));
}

/**
 * Edits a status.
 */
function fbss_rules_edit_action($sid, $message) {
  statuses_edit_status(statuses_load($sid), $message);
}

/**
 * Deletes a status.
 */
function fbss_rules_delete_action($sid) {
  statuses_delete_status($sid);
}

/**
 * Adds a status.
 */
function fbss_rules_add_action($sender, $recipient, $recipient_type, $message) {
  $context = statuses_determine_context($recipient_type);
  $recipient = $context['handler']->load_recipient($recipient);
  statuses_save_status($recipient, $recipient_type, $message, $sender);
}

/**
 * Implements hook_rules_data_type_info().
 */
function fbss_rules_rules_data_type_info() {
  return array(
    'statuses' => array(
      'label' => t('Statuses'),
      'wrapper class' => 'StatusesRulesDataWrapper',
      'wrap' => TRUE,
    ),
  );
}

/**
 * Defines the rules node data type.
 */
class StatusesRulesDataWrapper extends RulesIdentifiableDataWrapper implements RulesDataWrapperSavableInterface {
  public function save() {
    $status = $this->value();
    $context = statuses_determine_context($status->type);
    $recipient = $context['handler']->load_recipient($status->recipient);
    $sender = user_load($status->sender);
    statuses_save_status($recipient, $status->type, $status->message, $sender);
    return TRUE;
  }
  protected function load($sid) {
    return statuses_load($sid);
  }
  protected function extractIdentifier($status) {
    return $status->sid;
  }
}
