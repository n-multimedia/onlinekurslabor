<?php
/**
 * @file
 * File plugin. Builds links to files in the file system
 */

$freelinking['file'] = array(
  'indicator' => '/^file$/i',
  'callback' => 'freelinking_file_file_callback',
  'settings' => 'freelinking_file_file_settings',
);

/**
 * File plugin callback.
 * Builds a link to a file. 
 * 
 * @return
 *   array with link settings.
 */
function freelinking_file_file_callback($target, $plugin) {
  // Remove slash if it's present at first character
  $path = preg_replace('/^\//', '', $target['dest']);
  if (isset($target['other']['file_path'])) {
    $path = $target['other']['file_path'] . '/' . $path;
  }
  else {
    $path = variable_get('freelinking_file_file_path', file_default_scheme() . '://') . $path;
  }
  
  // Verify directory existance
  if (!$url = file_create_url($path)) {
    return array(
      'failover' => 'error',
      'message' => t('File Not Found'),
    );
  }
  
  // Build link
  if ($target['text']) {
    $title = $target['text'];
  }
  else {
    $title = basename($path);
  }

  return array($title, $url);
}

/**
 * Form settings for file plugin
 * 
 * @return
 *   array form structure
 */
function freelinking_file_file_settings() {
  $path = file_default_scheme() . '://';
  $form['freelinking_file_file_path'] = array(
    '#title' => t('File Basepath'),
    '#type' => 'textfield',
    '#default_value' => variable_get('freelinking_file_file_basepath', $path),
    '#description' => t('Set the base path for files. Files should usually begin with !path',
      array('!path' => $path)),
  );
  return $form;
}
