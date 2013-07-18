<?php
/**
 * Freelinking Path Plugin
 *
 * @file
 *   Supports the creation of links by url or internal path.
 *
 *   Syntax:
 *     [[path:/node/321]]
 *     [[path:breaking-news]]
 *     [[path:../../wiki/moderators/bill]]
 *
 *   Note that if the current path alias (or menu path) is changed,
 * relative links will not be updated to reflect the new location.
 *
 *   This plugin exposes page titles without regard for security.
 */
$freelinking['path'] = array(
  'indicator' => '/path|alias/i',
  'callback' => 'freelinking_path_callback',
  'settings' => 'freelinking_path_settings',
  'tip' => t('Link to a page by internal URL.'),
  'failover' => array('nodetitle', 'createnode', 'search'),
);

/**
 * Builds a link to an internal url 
 *
 * @return
 *   array with link properties
 */
function freelinking_path_callback($target, $plugin) {
  // the first character is not a forward slash
  $pos = strpos($target['dest'], '/');
  if ($pos === FALSE || $pos > 0) {
    $path = variable_get('freelinking_path_basepath', $_GET['q'])
      . '/' . $target['dest'];
  }
  elseif ($pos == 0) {
    // scrape off the starting slash that marks this as an unmodified path from site root.
    $path = substr($target['dest'], 1);
  }

  if (menu_get_item($path) == NULL) {
    $failover = variable_get('freelinking_path_failover', 'nodetitle');
    return array('failover' => $failover);
  }
  $title = $path;
  if ($target['text']) {
    $title = $target['text'];
  }
  else {
    $item = menu_get_item(drupal_get_normal_path($path));
    if ($item) {
      $title = $item['title'];
    }
  }

  return array($title, $path);
}

/**
 * Settings form for path module 
 * 
 * @return
 *   array form properties
 */
function freelinking_path_settings() {
  $form['freelinking_path_basepath'] = array(
    '#type' => 'textfield',
    '#title' => t('Starting Path for Relative Links'),
    '#default_value' => variable_get('freelinking_path_basepath', ''),
    '#description' => t('Set the "base directory" internal to the site that all relative path links will build from. (Relative path links have no initial slash or ending slash.)'),
  );

  return $form;
}
