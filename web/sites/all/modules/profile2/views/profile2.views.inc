<?php

/**
 *  Implements hook_views_data_alter().
 */
function profile2_views_data_alter(&$data) {

  $data['profile_revision']['pid'] = array(
    'title' => t('Profile item ID'),
    'help' => t('ID of the profile item of the revision'),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Revision profile'),
      'help' => t('Relate to revision\'s profile'),
      'handler' => 'views_handler_relationship',
      'base' => 'profile',
      'base field' => 'pid',
      'label' => t('Revision profile'),
    ),
  );

  $data['profile_revision']['authorid'] = array(
    'title' => t('Author ID'),
    'help' => t('The user ID of the author of the revision'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name',
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Revision author'),
      'help' => t('Relate to revision\'s author'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('Revision author'),
    ),
  );

  $data['profile_revision']['log'] = array(
    'title' => t('Log message'),
    'help' => t('Revision log message.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['profile_revision']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t('Timestamp when revision was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
}

