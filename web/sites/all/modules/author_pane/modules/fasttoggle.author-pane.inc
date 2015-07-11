<?php
/**
 * @file
 * This file provides a preprocess function on behalf of the fasttoggle module.
 */

/**
 * Implements hook_preprocess_author_pane().
 */
function fasttoggle_preprocess_author_pane(&$variables) {
  // Check if this preprocess needs to be run given who's calling it.
  if (!author_pane_run_preprocess('fasttoggle', $variables['caller'])) {
    return;
  }

  // Do not show fasttoggle links for anonymous users.
  if ($variables['account']->uid != 0) {
    $variables['fasttoggle_links'] = theme('links', array('links' => fasttoggle_link('user', $variables['account']), 'attributes' => array('class' => 'links inline')));
  }
}

/**
 * Implements hook_author_pane_allow_preprocess_disable().
 */
function fasttoggle_author_pane_allow_preprocess_disable() {
  return array('fasttoggle' => 'Fasttoggle');
}
