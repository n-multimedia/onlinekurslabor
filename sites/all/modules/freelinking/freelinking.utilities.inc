<?php

/**
 * Freelinking 3 Utilities
 *
 * @file
 *  Provides toolkit functions for Freelinking plugin developers.
 */

/**
 * Process the target text into a link with the specified plugin.
 *
 * @param $plugin
 *   The name of the plugin to be used to render the link.
 *
 * @param $target
 *   The target text extracted from the freelink. Array.
 *
 * @param $format
 *   The format id currently invoking the Freelinking filter. Might be used in
 * the future to tweak plugin behavior.
 *
 * @param $rendered
 *   Boolean value. If true, link will be returned as rendered HTML. If false,
 * link will be returned as arguments for l().
 *
 * @return
 *   An array as per the arguments of l() or a string of HTML markup.
 *
 * @see l()
 */
function freelinking_get_freelink($plugin, $target, $format = 'all', $rendered = TRUE) {
  $plugins = freelinking_get_plugins($format);
  $link = _freelinking_build_freelink($plugins, $plugin, $target);

  if (!$rendered || !is_array($link)) {
    return $link;
  }
  if (isset($link['failover'])) {
    if ($link['failover'] == 'error') {
      return theme('freelink_error', array('plugin' => $plugin, 'message' => $link['message']));
    }
    if ($link['failover'] == 'none') {
      return FALSE;
    }
  }
  if (isset($link['error'])) {
    return theme('freelink_error', array('plugin' => $plugin, 'message' => $link['error']));
  }
  
  if (function_exists('theme_freelink_' . $plugin)) {
    // TODO Please change this theme call to use an associative array for the $variables parameter.
    return theme('freelink_' . $plugin, array('link' => $link));
  }
  return theme('freelink', array('plugin' => $plugin, 'link' => $link));
}

/**
 * Invoke hook_freelinking() to validate & sort available FL plugins.
 *
 * This function is necessary to build any sort of interface involving plugin
 * configuration. It is not the function to use in the creation of new
 * plugins or overriding existing plugins. For that you want hook_freelinking().
 *
 * Internal Note: Currently the plugins are generated for each plugin on
 * the idea that different formats might have a number of configuration
 * overrides. If this turns out to not be the case a single cached version of
 * the plugins might be better.
 *
 * @param $format
 *   The Text Format ID of the currently processed piece of text. Allows
 * format-specific plugin overrides such as disabling certain plugins in a given
 * format. The default 'all' refers to the plugins as provided by hook_freelinking().
 *
 * @param $reset
 *   (Default: FALSE) Reset the static cache.
 * @return
 *   An array of all plugins. Each plugin is itself an array.
 *
 * @see PLUGINS.txt
 */
function freelinking_get_plugins($format = 'all', $reset = FALSE) {
  static $plugins;

  if (empty($plugins[$format]) || $reset) {
    $freelinking = module_invoke_all('freelinking');

    // Validate & standardize plugins.
    foreach ($freelinking as $name => &$plugin) {
      // Confirm correct structure in plugin
      if (!isset($plugin['indicator'])
         || (!isset($plugin['replacement']) && !isset($plugin['callback']))
         || (isset($plugin['callback']) && !function_exists($plugin['callback']))) {
        drupal_set_message(t('Freelinking plugin "!plugin" is invalid.',
            array('!plugin' => $name)), 'warning');
        watchdog('filter', 'Freelinking plugin "!plugin" is invalid.',
            array('!plugin' => $name), WATCHDOG_WARNING);
      } // end if

      // Set "enabled" by format when explicitly set in format configuration..
      $plugin_enabled = variable_get(
        'freelinking_' . $name . '_enabled_format_' . $format, ''
      );
      if ($plugin_enabled) {
        $plugin['enabled'] = $plugin_enabled;
      }

      // Rearrange weight scheme to use core comparison function.
      if (isset($plugin['weight'])) {
        $plugin['#weight'] = $plugin['weight'];
        unset($plugin['weight']);
      }
      // Set explicit defaults.
      $plugin += array(
        'enabled' => TRUE,
        'html' => TRUE,
      );
    } // end foreach

    // element_sort() uses '#weight', the hash is added above to support this.
    uasort($freelinking, 'element_sort');

    $plugins[$format] = $freelinking;
  }

  return $plugins[$format];
} // end freelinking_get_plugins()

/**
 * Build a tooltip for internal content.
 *
 * Attempts to use description metatag, truncated to 200 characters.
 *
 * @param $type
 *   Type of the Drupal object- such as node, comment, block.
 *
 * @param $id
 *   ID of the Drupal object. Useful for querying.
 */
function freelinking_internal_tooltip($type, $id) {
  switch ($type) {
    case 'node':
      if (module_exists('nodewords')) {
        if (function_exists('nodewords_get_tags')) {
          $metatags = nodewords_get_tags('node', $id);
          $description = check_url($metatags['description']);
          return truncate_utf8($description, 200, FALSE, TRUE);
        }
      }
      break;
  }
}

/**
 * Get a configuration value for the current text being processed.
 * Configuration values may vary by format, or fall back to a general default.
 *
 * This allows the current value to be accessed without bouncing $format into
 * every plugin.
 *
 * @param $name
 *   Get the setting from those tracked in freelinking_set_conf().
 *
 * @return
 *   A string of the value.
 *
 * @see freelinking_set_conf()
 */
function freelinking_get_conf($name) {
  return freelinking_set_conf($name);
}

/**
 * Calculate a configuration value based on a precedence of existing variables.
 * Format-specific before Freelinking before Drupal-wide.
 *
 * @param $name
 *   Set the named setting. Examples:
 *   - 'cache': boolean. True indicates the filter cache should be turned on.
 *   - 'default_match': String. Mode of default syntax for freelinking.
 *
 * @param $format
 *   Calculate the setting for the specified format. If the format is not specified,
 *   will return the value from memory without calculating.
 *
 * @return
 *   String of the computed value.
 */
function freelinking_set_conf($name, $format = NULL, $reset = FALSE) {
  static $conf;

  if ($conf[$name] && !$format) {
    return $conf[$name];
  }

  // Specific format -> Freelinking Global -> Format Settings
  if ($name == 'cache') {
    $conf[$name] = variable_get('freelinking_' . $name . '_format_' . $format,
      variable_get('freelinking_' . $name, filter_format_allowcache($format)));
  }
  else {
    $conf[$name] = variable_get('freelinking_' . $name . '_format_' . $format,
      variable_get('freelinking_' . $name, FALSE));
  }

  return $conf[$name];
}
