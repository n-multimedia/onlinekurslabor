<?php
/**
 * Freelinking 3 API
 *
 * @file
 *   API for Freelinking 3. These functions are subject to change without
 * warning for all Alpha releases.
 */

/**
 * hook_freelinking() is used to define plugins or add new values to plugins.
 *
 * For more on creating or modifying plugins, check the documentation.
 *
 * @see http://drupal.org/node/???
 */
function hook_freelinking() {
  $plugins['myplugin'] = array(
    'indicator' => '/myplugin/',
    'translate' => array(' ' => '_'),
    'replacement' => 'http://example.com/node/%1',
  );
  return $plugins;
}

/**
 * hook_freelink_alter() is used to modify the array of link values
 * that are eventually passed on to the theme functions to become links.
 *
 * Error messages and strings returned from plugins are not processed by
 * this hook. Errors are directly themed and returned, and strings are
 * simply passed back to the text. (In the latter "mode", freelinking
 * could be used to generate something other than a link.)
 *
 * @param $link
 *  Array suitable for passing to l().
 *
 * @param $target
 *  Array of information from parsed linking syntax.
 *
 * @param $plugin_name
 *  String of the name of the freelinking plugin that created the current link.
 *
 * @plugin
 *  The plugin definition (array) of the freelinking plugin that created the
 * current link.
 *
 * @return
 *  Array suitable for passing to l().
 *
 * @see http://drupal.org/node/???
 */
function hook_freelink_alter(&$link, $target, $plugin_name, $plugin) {
  if ($plugin_name == 'stark_link') {
    unset($link[2]['attributes']['class']);
    unset($link[2]['attributes']['title']);
  }
  elseif ($plugin_name == 'green_link') {
    $link[2]['attributes']['class'][] = 'green';
  }
}

/**
 * Individual modules may implement a theme_freelink_pluginname().
 * Doing so will override the standard theme_freelink().
 * Modules must still implement hook_theme to declare their theme function.
 *
 * In this example, the "pluginname" plugin is themed to become an image
 * to the targeted URL, instead of a link.
 */
function theme_freelink_pluginname($variables) {
  $link = $variables['link'];
  // TODO: Should this theme freelink_pluginname be declared in hook_theme()?
  return theme('image', array('path' => $link[1], 'width' => $link[0], 'height' => $link[2]['attributes']['title']));
}
