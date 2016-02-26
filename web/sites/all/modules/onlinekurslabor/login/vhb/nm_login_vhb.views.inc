<?php

/**
 * Implement hook_views_data().
 *
 * Describe table "nm_login_vhb" so that it can be used by views
 */
function nm_login_vhb_views_data() {
  $data = array();
  $data['nm_login_vhb']['table']['group'] = t('NM Login VHB');

  // Define this as a base table – a table that can be described in itself by
  // views (and not just being brought in as a relationship). In reality this
  // is not very useful for this table, as it isn't really a distinct object of
  // its own, but it makes a good example.
  $data['nm_login_vhb']['table']['base'] = array(
    'field' => 'uid', // This is the identifier field for the view.
    'title' => t('NM Login (vhb)'),
    'help' => t('nm_login_vhb table containts information about archivated users.'),
    'weight' => -10,
  );

  // This table references the {users} table. The declaration below creates an
  // 'implicit' relationship to the node table, so that when 'users' is the base
  // table, the fields are automatically available.
  $data['nm_login_vhb']['table']['join'] = array(
    // Index this array by the table name to which this table refers.
    // 'left_field' is the primary key in the referenced table.
    // 'field' is the foreign key in this table.
    'node' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // User ID table field.
  $data['nm_login_vhb']['uid'] = array(
    'title' => t('uid field'),
    'help' => t('Arhive information that references to a user.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'users', // The name of the table to join with.
      'base field' => 'uid', // The name of the field on the joined table.
      // 'field' => 'nid' -- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('user'),
      'title' => t('user relationship'),
      'help' => t('...'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Example timestamp field.
  $data['nm_login_vhb']['created'] = array(
    'title' => t('Timestamp field'),
    'help' => t('Timestamp when user was added.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

// Example timestamp field.
  $data['nm_login_vhb']['login_uid'] = array(
    'title' => t('VHB LOGIN field'),
    'help' => t("user's vhb LOGIN"),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Example numeric text field.
  $data['nm_login_vhb']['archivated'] = array(
    'title' => t('archivated'),
    'help' => t('is archivated field'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );




  return $data;
}
