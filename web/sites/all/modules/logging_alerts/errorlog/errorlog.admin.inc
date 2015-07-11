<?php

/**
 * @file
 * Admin callbacks for the Web Server Logging and Alerts module.
 */

/**
 * Returns admin settings form.
 */
function errorlog_admin_settings() {
  $form['errorlog'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Error logging for each severity level.'),
    '#description'  => t('Check each severity level you want to get logged to the error log.'),
  );
  foreach (watchdog_severity_levels() as $severity => $description) {
    $key = 'errorlog_' . $severity;
    $form['errorlog'][$key] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Severity: @description', array('@description' => drupal_ucfirst($description))),
      '#default_value' => variable_get($key, FALSE),
    );
  }
  return system_settings_form($form);
}
