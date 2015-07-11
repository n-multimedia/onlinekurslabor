<?php
// $Id$

/**
 * @file
 * Provides a Rules integration for watchdog events.
 */

/**
 * Implements hook_rules_event_info().
 *
 * Register rules events used by this module.
 */
function watchdog_rules_rules_event_info() {
  $defaults = array(
    'group' => t('Watchdog'),
    'module' => 'watchdog_rules',
  );
  return array(
    'watchdog_rules' => $defaults + array(
      'label' => t('Watchdog logs an event'),
      'variables' => array(
        'watchdog_user' => array(
          'type' => 'user', 
          'label' => t('The logged in user when watchdog was called'),
        ),
        'watchdog_type' => array(
          'type' => 'text', 
          'label' => t('The watchdog log type'),
        ),
        'watchdog_request_uri' => array(
          'type' => 'text', 
          'label' => t('The watchdog log request URI'),
        ),
        'watchdog_referer' => array(
          'type' => 'text', 
          'label' => t('The watchdog log referer'),
        ),
        'watchdog_ip' => array(
          'type' => 'text', 
          'label' => t('The watchdog log ip'),
        ),
        'watchdog_timestamp' => array(
          'type' => 'text', 
          'label' => t('The watchdog log timestamp'),
        ),
        'watchdog_severity' => array(
          'type' => 'text', 
          'label' => t('The watchdog log severity'),
        ),
        'watchdog_link' => array(
          'type' => 'text', 
          'label' => t('The watchdog log link'),
        ),
        'watchdog_message' => array(
          'type' => 'text', 
          'label' => t('The watchdog log message'),
        ),
      ),
    ),
  );
}

