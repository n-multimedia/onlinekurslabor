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
  // TODO: When a stable release of user_badges exists.
  // - Check if this if-case is necessary to use?
  //   user_badges_for_uid, right now, returns "NULL" if $uid is 0.
  // - Static cache is not necessary, user_badges_for_uid has it right now.
  if ($variables['account']->uid != 0) {
    $variables['user_badges'] = user_badges_for_uid($variables['account']->uid);
  }
}

/**
 * Implements hook_author_pane_allow_preprocess_disable().
 */
function user_badges_author_pane_allow_preprocess_disable() {
  return array('user_badges' => 'User Badges');
}
