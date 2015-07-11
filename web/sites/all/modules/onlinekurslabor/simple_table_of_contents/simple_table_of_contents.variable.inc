<?php

/**
 * @file
 * Variables for the Simple Table of Contents module.
 */

/**
 * Implements hook_variable_group_info().
 */
function simple_table_of_contents_variable_group_info() {
  $groups['simple_table_of_contents'] = array(
    'title' => t('Simple Table of Contents'),
    'description' => t('Simple Table of Contents settings.'),
    'path' => array('admin/config/system/simple-table-of-contents'),
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function simple_table_of_contents_variable_info($options) {
  $variable['simple_table_of_contents_title'] = array(
    'type' => 'string',
    'title' => t('Table of contents title', array(), $options),
    'description' => t('Title that will be used as a heading for the table of contents.'),
    'default' => 'Table of Contents',
    'group' => 'simple_table_of_contents',
  );

  return $variable;
}
