<?php

/**
 * @file
 *   Provide Views data and handlers for the FBSS Flag module.
 */

/**
 * Implements hook_views_data().
 */
function fbss_flag_views_data() {
  $data = array();

  $data['statuses']['user-flag-plus-current'] = array(
    'title' => t('Content from flagged users or the current user'),
    'help' => t('Shows content from only flagged users or the current user.'),
    'filter' => array(
      'field' => 'sender',
      'handler' => 'statuses_views_handler_filter_flagged_user',
    ),
  );
  $data['statuses']['user-flag-plus-arg'] = array(
    'title' => t('Content from flagged users or the argument user'),
    'help' => t('Shows content from only flagged users or the argument user.'),
    'argument' => array(
      'field' => 'sender',
      'handler' => 'statuses_views_handler_argument_flagged_user',
    ),
  );

  return $data;
}