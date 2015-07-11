<?php
/**
 * @file
 *   Constructs freelinking & module admin forms.
 */

/**
 * Build admin/settings page.
 */
function freelinking_settings($form, &$form_state) {
  $form = array();

  $plugins = freelinking_get_plugins();
  foreach ($plugins as $plugin => $definition) {
    $available_plugins[$plugin] = drupal_ucfirst($plugin);
    if (function_exists($definition['settings']) || isset($definition['token'])) {
      $plugin_with_settings[$plugin] = $definition['settings'];
    }
  }

  // set the default plugin
  $form['freelinking_default'] = array(
    '#title' => t('Plugin to use when not indicated in the freelink'),
    '#type' => 'select',
    '#multiple' => FALSE,
    '#options' => $available_plugins,
    '#default_value' => variable_get('freelinking_default', 'nodetitle'),
    '#description' => t('Default plugin to use when not specified in text. "Nodetitle" mimics previous versions of Freelinking.'),
  );

  $syntax['double_bracket'] = t('Standard') . ' - [[plugin:target|Title]]';
  $syntax['single_bracket'] = t('Single Bracket') . ' - [plugin:target|Title]';
  $syntax['markdown'] = 'Markdown - [Title](plugin:target)';

  $form['freelinking_match_syntax'] = array(
    '#title' => t('Match Syntax Mode'),
    '#type' => 'select',
    '#default_value' => variable_get('freelinking_match_syntax', 'double_bracket'),
    '#options' => $syntax,
    '#description' => t('What syntax to use in identifying freelinks.'),
  );

  $form['freelinking_cache'] = array(
    '#title' => t('Disable filter cache'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('freelinking_cache', FALSE),
    '#description' => t('The filter cache may be disabled even if this box is not checked.'),
  );

  // loop through plugin settings functions, adding a fieldset for each
  foreach ($plugin_with_settings as $plugin => $callback) {
    $form[$plugin] = array(
      '#title' => t('!plugin Plugin Settings', array('!plugin' => drupal_ucfirst($plugin))),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form[$plugin]['settings'] = call_user_func($callback);

    // If failover is already defined, let it be.
    $failover = 'freelinking_' . $plugin . '_failover';
    //    if (empty($form[$plugin]['settings'][$failover])) {
    _freelinking_failover_form($form, $plugin, $plugins[$plugin], $failover);
    //    }
  } // endforeach looping through plugins with settings

  return system_settings_form($form);
} // endfunction freelinking_settings (admin settings)

function _freelinking_failover_form(&$form, $plugin_name, $plugin, $setting_name) {
  if (isset($plugin['failover']) && is_array($plugin['failover'])) {
    foreach ($plugin['failover'] as $option) {
      $options[$option] = t('Use plugin !plugin', array('!plugin' => $option));
    }
    $options = array_merge($options, array('error' => t('Error Message'), 'none' => t('Do Nothing')));
    $form[$plugin_name]['settings'][$setting_name] = array(
      '#title' => t('Plugin Fallback Action'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => variable_get($setting_name, 'none'),
    );
  }
  elseif (isset($plugin['failover'])) {
    $form[$plugin_name]['settings'][$setting_name] = array(
      '#title' => t('Plugin Fallback Action'),
      '#type' => 'textfield',
      '#value' => variable_get($setting_name, $plugin['failover']),
      '#size' => 20,
      '#disabled' => TRUE,
    );
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 * Used to add Vertical Tabs enhancement to admin page
 */
function freelinking_form_freelinking_settings_alter(&$form, &$form_state) {
  if (module_exists('vertical_tabs') &&
    function_exists('vertical_tabs_add_vertical_tabs')) {
    vertical_tabs_add_vertical_tabs($form);
  }
}

// vim: tw=300 nowrap syn=php
