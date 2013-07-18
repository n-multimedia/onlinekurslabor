<?php

/**
 * @file
 *   Integrates Rules with the Statuses Domain Access module.
 */

/**
 * Implements hook_rules_condition_info().
 */
function fbss_domain_rules_condition_info() {
  return array(
    'fbss_domain_uses_domain' => array(
      'label' => t('Status was posted in a specific domain'),
      'arguments' => array(
        'status' => array(
          'type' => 'statuses',
          'label' => t('The status')
        ),
        'domain_id' => array(
          'type' => 'list<integer>',
          'label' => t('Status is associated with domain'),
          'options list' => 'fbss_domain_get_domain_options',
        ),
      ),
      'group' => t('Statuses'),
    ),
  );
}

/**
 * Generate the options for uses_domain condition
 */
function fbss_domain_get_domain_options(){
  $options = array();
  foreach (domain_domains() as $data) {
    // Cannot pass zero in checkboxes.
    ($data['domain_id'] == 0) ? $key = -1 : $key = $data['domain_id'];
    // The domain must be valid.
    if ($data['valid'] || user_access('access inactive domains')) {
      // Checkboxes must be filtered, select lists should not.
      $options[$key] = empty($format) ? check_plain($data['sitename']) : $data['sitename'];
    }
  }
  return $options;
}

/**
 * Checks if the status is associated with one of the chosen domains.
 */
function fbss_domain_uses_domain($status, $domain_ids) {
  $domains = array_filter($domain_ids);
  if (isset($domains[-1])) {
    $domains[0] = 0;
    unset($domains[-1]);
  }
  $domain_id = db_select('fbss_domain')
    ->fields('fbss_domain', array('domain_id'))
    ->condition('sid', $status->sid)
    ->execute()
    ->fetchField();
  return in_array($domain_id, $domains);
}
