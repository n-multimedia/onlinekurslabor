<?php

/**
 * @file
 *   This file provides a preprocess function on behalf of the OG module.
 */

/**
 * Implements hook_preprocess_author_pane().
 */
function og_preprocess_author_pane(&$variables) {
  // Check if this preprocess needs to be run given who's calling it.
  if (!author_pane_run_preprocess('og', $variables['caller'])) {
    return;
  }

  $account = $variables['account'];
  $account_id = $variables['account']->uid;

  if (isset($account->og_groups) && !empty($account->og_groups)) {
    $groups = array();

    // Implement static caching for cases where this Author Pane appears more
    // than once on a given page.
    static $cached_og_groups_array;
    static $cached_og_groups;

    if (isset($cached_og_groups[$account_id])) {
      $variables['og_groups_array'] = $cached_og_groups_array[$account_id];
      $variables['og_groups'] = $cached_og_groups[$account_id];
    }
    else {
      // Check if there is the potential for private groups on the site to
      // avoid needless node loads on sites with no private gorups.
      $has_private = module_exists('og_access');
      foreach ($account->og_groups as $og_id => $og) {
        if ($has_private) {
          $og_node = node_load($og['nid']) ;
          if (!$og_node->og_private) {
            $groups[] = l($og['title'], 'node/' . $og['nid']);
          }
        }
        else {
          $groups[] = l($og['title'], 'node/' . $og['nid']);
        }
      }

      $variables['og_groups_array'] = $groups;
      $cached_og_groups_array[$account_id] = $groups;

      $variables['og_groups'] = implode(', ', $groups);
      $cached_og_groups[$account_id] = $variables['og_groups'];
    }
  }
  else {
    $variables['og_groups'] = t('None');
  }
}

/**
 * Implements hook_author_pane_allow_preprocess_disable().
 */
function og_author_pane_allow_preprocess_disable() {
  return array('og' => 'Organic Groups');
}
