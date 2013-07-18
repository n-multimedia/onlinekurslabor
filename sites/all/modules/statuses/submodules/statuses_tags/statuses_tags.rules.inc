<?php

/**
 * @file
 *   Rules integration.
 */

/**
 * Implements hook_rules_event_info().
 */
function statuses_tags_rules_event_info() {
  return array(
    'statuses_tags_user_was_tagged' => array(
      'label' => t('User was tagged in a status'),
      'group' => t('Statuses'),
      'variables' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status.'),
        ),
        'account' => array(
          'type' => 'user',
          'label' => t('The user who was tagged in the status.'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function statuses_tags_rules_condition_info() {
  return array(
    'statuses_tags_has_tags_condition' => array(
      'label' => t('Status has tags'),
      'arguments' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status'),
        ),
        'type' => array(
          'type' => 'text',
          'label' => t('Tag type'),
          'restriction' => 'input',
          'options list' => 'statuses_tags_types_list',
          'description' =>  t('The type of tag allowed for this condition to be true.'),
        ),
      ),
      'group' => t('Statuses'),
    ),
    'statuses_tags_has_specific_tag_condition' => array(
      'label' => t('Status has specific tag'),
      'arguments' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status'),
        ),
        'type' => array(
          'type' => 'text',
          'label' => t('Tag type'),
          'restriction' => 'input',
          'options list' => 'statuses_tags_types_list',
          'description' =>  t('The type of tag allowed for this condition to be true.'),
        ),
        'tag' => array(
          'type' => 'text',
          'label' => t('Tag'),
          'restriction' => 'input',
          'description' =>  t('Do not include the identifying hash (#) or "at" symbol (@).'),
        ),
      ),
      'group' => t('Statuses'),
    ),
  );
}

/**
 * Determines whether a status has tags of a given type.
 */
function statuses_tags_has_tags_condition($status, $type) {
  return (bool) statuses_tags_has_tags($status->sid, $type);
}

/**
 * Generate the tag types options
 */
function statuses_tags_types_list() {
  return array(
      'user' => t('User @mention'),
      'term' => t('Term #hashtag'),
  );
}

/**
 * Determines whether a status has a specific tag of a given type.
 */
function statuses_tags_has_specific_tag_condition($status, $type, $tag) {
  return (bool) statuses_tags_status_has_tag_by_name($status->sid, $tag, $type);
}
