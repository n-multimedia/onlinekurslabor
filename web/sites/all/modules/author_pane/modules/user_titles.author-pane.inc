<?php

/**
 * @file
 *   Provides a preprocess function on behalf of the user titles module.
 */

/**
 * Implements hook_preprocess_author_pane().
 */
function user_titles_preprocess_author_pane(&$variables) {
  // Check if this preprocess needs to be run given who's calling it.
  if (!author_pane_run_preprocess('user_titles', $variables['caller'])) {
    return;
  }

  $account = $variables['account'];
  $account_id = $account->uid;

  if ($account_id != 0) {
    // Implement static caching for cases where this Author Pane appears more
    // than once on a given page.
    static $cached_user_title = array();
    static $cached_user_title_image = array();

    // Get text title (from cache, if set)
    if (isset($cached_user_title[$account_id])) {
      $variables['user_title'] = $cached_user_title[$account_id];
    }
    else {
      $variables['user_title'] = user_titles_get_user_title($account);
      $cached_user_title[$account_id] = $variables['user_title'];
    }

    // Get image title (from cache, if set)
    if (isset($cached_user_title_image[$account_id])) {
      $variables['user_title_image'] = $cached_user_title_image[$account_id];
    }
    else {
      $variables['user_title_image'] = user_titles_get_user_image($account);
      $cached_user_title_image[$account_id] = $variables['user_title_image'];
    }
  }
}

/**
 * Implements hook_author_pane_allow_preprocess_disable().
 */
function user_titles_author_pane_allow_preprocess_disable() {
  return array('user_titles' => 'User Titles');
}
