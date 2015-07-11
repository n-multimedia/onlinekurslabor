<?php
/**
 * Show text plugin for Freelinking
 *
 * @file
 * Provides a fallback to just show the text inside the linked text.
 */

$freelinking['showtext'] = array(
  'indicator' => '/showtext/',
  'translate' => array(' ' => '+'),
  'callback' => 'freelinking_showtext_callback',
  'tip' => t('showtext.'),
);

/**
 * Displays the linked title, if exists, or the link.
 *
 * @return
 *   an string with the title.
 */
function freelinking_showtext_callback($target, $plugin) {
  if (isset($target['text'])) {
    $text = $target['text'];
  }
  else {
    $text = $target['target'];
  }
return $text;
}

/**
 * Settings callback for Search plugin
 */
function freelinking_showtext_settings() {
  $form['freelinking_showtext_failover'] = array(
    '#type' => 'select',
    '#title' => t('Failover Option'),
    '#default_value' => variable_get('freelinking_showtext_failover', 'error'),
    '#options' => array(
      'error' => t('Error Message'),
    ),
    '#description' => t('If Search is disabled or inaccessible do something else.'),
  );
  return $form;
}
