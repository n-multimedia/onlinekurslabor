<?php
/**
 * @file
 * This file provides a preprocess function on behalf of the Contact module.
 */

/**
 * Implements hook_preprocess_author_pane().
 *
 * @see _contact_personal_tab_acces()
 */
function contact_preprocess_author_pane(&$variables) {
  // Check if this preprocess needs to be run given who's calling it.
  if (!author_pane_run_preprocess('contact', $variables['caller'])) {
    return;
  }

  if (_contact_personal_tab_access($variables['account'])) {
    $variables['contact'] = l(t('Email'), 'user/' . $variables['account']->uid . '/contact', array('attributes' => array('class' => array('author-pane-link'))));
  }
}

/**
 * Implements hook_author_pane_allow_preprocess_disable().
 */
function contact_author_pane_allow_preprocess_disable() {
  return array('contact' => 'Contact');
}
