<?php

/**
 * @file
 *   Integrates Statuses Private Statuses with Views.
 */

/**
 * Implements hook_views_query_alter().
 */
function fbss_privacy_views_query_alter(&$view, &$query) {
  global $user;
  // Alter any view that shows status updates and exclude private statuses (unless we've already set a related filter).
  foreach ($query->table_queue as $table) {
    if ($table['table'] == 'statuses' && !isset($query->where['fbss_privacy']) && !user_access('view all private status messages')) {
      $table_alias = $table['alias'];
      $db_or = db_or()
        ->condition("$table_alias.sender", $user->uid)
        ->condition("$table_alias.private", 0);
      $db_and = db_and()
        ->condition("$table_alias.recipient", $user->uid)
        ->condition("$table_alias.type", 'user');
      $query->add_where('fbss_privacy', db_or()
        ->condition($db_or)
        ->condition($db_and));
      break;
    }
  }
}

/**
 * Implements hook_views_data().
 */
function fbss_privacy_views_data() {
  $data = array();
  $data['statuses']['private'] = array(
    'title' => t('Show private status messages'),
    'help' => t('Enable showing private status messages in this view'),
    'field' => array(
      'handler' => 'fbss_privacy_views_handler_field',
      'title' => t('The word "<em>(Private)</em>" if the status message is private'),
      'help' => t('Distinguish between private and non-private messages'),
    ),
    'filter' => array(
      'handler' => 'fbss_privacy_views_handler_filter',
      'label' => t('Show private status messages'),
    ),
    'argument' => array(
      'handler' => 'fbss_privacy_views_handler_argument',
      'label' => t('Show private status messages'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
      'title' => t('Private messages first'),
      'help' => t('Choose "Descending" to float private messages to the top of the list.'),
    ),
  );
  return $data;
}
