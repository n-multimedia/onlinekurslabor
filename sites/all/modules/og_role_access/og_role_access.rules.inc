<?php

/**
 * @file
 * Rules integration for the Organic groups module.
 *
 * @ogrole rules
 * @{
 */

/**
 * Implementation of hook_rules_event_info().
 *
 * Adds some additional event that make reacting on user subscriptions easier.
 */
function og_role_access_rules_event_info() {
  $events = array();

  if(module_exists('og')){
    $events['og_role_access_og_role_add'] = array(
      'label' => t('An OG role has been added to a member'),
      'group' => t('OG role'),
      'help' => t("An OG role has been assigned to a user in their group membership."),
      'variables' => array(
        'og_role_id' => array(
          'label' => t('OG Role ID'),
          'type' => 'integer',
          ),
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
          ),
        ),
      );
    $events['og_role_access_og_role_remove'] = array(
      'label' => t('An OG role has been removed from a member'),
      'group' => t('OG role'),
      'help' => t("An OG role has been removed from a user in their group membership."),
      'variables' => array(
        'og_role_id' => array(
          'label' => t('OG Role ID'),
          'type' => 'integer',
          ),
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
          ),
        ),
      );
  }
  return $events;
}

/**
 * @}
 */
