<?php
/**
 * @file
 * Rules for session data.
 */

/**
 * Implements hook_rules_action_info().
 */
function rules_session_vars_rules_action_info() {
  return array(
    'add_data_to_session' => array(
      'label' => t('Store value to $_SESSION'),
      'parameter' => array(
        'data_key' => array(
          'type' => 'token',
          'label' => t('Key to identify your data'),
          'description' => t('Note: if the data with this key already exists in the $_SESSION array, it will be overwritten!'),
          'default mode' => 'input',
        ),
        'data_value' => array(
          'type' => array(
            'text',
            'integer',
            'decimal',
            'date',
            'boolean',
            'list',
          ),
          'label' => t('Data to be saved with the key provided'),
          'default mode' => 'input',
        ),
      ),
      'group' => t('Rules Session'),
      'callbacks' => array('execute' => '_rules_session_vars_save_data_to_session'),
    ),
    'load_data_from_session' => array(
      'label' => t('Load value from $_SESSION'),
      'parameter' => array(
        'data_key' => array(
          'type' => 'token',
          'label' => t('Key to identify data'),
          'default mode' => 'input',
        ),
      ),
      'group' => t('Rules Session'),
      'provides' => array(
        'loaded_session_data' => array(
          'label' => t('Loaded session data.'),
          'type' => 'text',
        ),
      ),
      'callbacks' => array('execute' => '_rules_session_vars_load_data_from_session'),
    ),
    'remove_data_from_session' => array(
      'label' => t('Remove value from $_SESSION'),
      'parameter' => array(
        'data_key' => array(
          'type' => 'token',
          'label' => t('Key to identify your data'),
          'default mode' => 'input',
        ),
      ),
      'group' => t('Rules Session'),
      'callbacks' => array('execute' => '_rules_session_vars_remove_data_from_session'),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function rules_session_vars_rules_condition_info() {
  return array(
    'session_key_exists' => array(
      'label' => t('$_SESSION key exists'),
      'parameter' => array(
        'data_key' => array(
          'type' => 'token',
          'label' => t('$_SESSION key to check'),
          'default mode' => 'input',
        ),
      ),
      'callbacks' => array('execute' => '_rules_session_vars_key_exists'),
      'group' => t('Rules Session'),
    ),
  );
}

/**
 * Saves data into session.
 * 
 * @param string $data_key
 *   Key in session.
 * @param string $data_value
 *   Value in session.
 * @param array $settings
 *   Settings array.
 * 
 * @return array
 *   Returns the new session data.
 */
function _rules_session_vars_save_data_to_session($data_key, $data_value, $settings) {
  $_SESSION[$data_key] = $data_value;
  return array('session_data' => array($data_key => $data_value));
}

/**
 * Loads data from session.
 * 
 * @param string $data_key
 *   Key in session.
 * @param array $settings
 *   Settings array.
 *
 * @return array
 *   Returns the session data.
 */
function _rules_session_vars_load_data_from_session($data_key, $settings) {
  if (isset($_SESSION[$data_key])) {
    return array('loaded_session_data' => $_SESSION[$data_key]);
  }
  return FALSE;
}

/**
 * Removes data from session.
 *
 * @param string $data_key
 *   Key in session.
 * @param array $settings
 *   Settings array.
 */
function _rules_session_vars_remove_data_from_session($data_key, $settings) {
  if (isset($_SESSION[$data_key])) {
    unset($_SESSION[$data_key]);
  }
}

/**
 * Checks for existence of data in session.
 *
 * @param string $data_key
 *   Key in session.
 * @param array $settings
 *   Settings array.
 * 
 * @return bool
 *   TRUE if the session key exists otherwise FALSE.
 */
function _rules_session_vars_key_exists($data_key, $data_value, $settings) {
  if (isset($_SESSION[$data_key])) {
    return TRUE;
  }
  return FALSE;
}
