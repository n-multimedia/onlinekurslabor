<?php
/**
 * @file
 * This file provides a preprocess function on behalf of the User Badges module.
 */

/**
 * Implements hook_preprocess_author_pane().
 */
function user_badges_preprocess_author_pane(&$variables) {
  // Check if this preprocess needs to be run given who's calling it.
  if (!author_pane_run_preprocess('user_badges', $variables['caller'])) {
    return;
  }

  // Anonymous users has no user badges.
  if ($variables['account']->uid != 0) {

    // Only display the badges according badge limit
    if (isset($variables['account']->badges)) {
      $variables['user_badges'] = '';

      // Loop through and add only the badges that are within the limit,
      // $variables['account']->badges, stores the badges within the limit
      foreach ($variables['account']->badges as $badge) {
        $variables['user_badges'] .= theme('user_badge', array('badge' => $badge));
      }
    }
  }
}

/**
 * Implements hook_author_pane_allow_preprocess_disable().
 */
function user_badges_author_pane_allow_preprocess_disable() {
  return array('user_badges' => 'User Badges');
}
