<?php

/**
 * @file
 * Themeable function callbacks for profile2_diff.module.
 */

/**
 * Display inline diff metadata.
 */
function theme_profile2_diff_inline_metadata($vars) {
  drupal_add_css(drupal_get_path('module', 'diff') .'/diff.css');
  $profile = $vars['profile'];
  $user = user_load($profile->authorid);

  $output = "<div class='diff-inline-metadata clear-block'>";
  $output .= "<div class='diff-inline-byline'>";
  $output .= t('Updated by !name on @date', array(
    '!name' => theme('username', array('account' => $user)),
    '@date' => format_date($profile->revision_timestamp, 'small'),
  ));
  $output .= "</div>";
  $output .= "<div class='diff-inline-legend clear-block'>";
  $output .= "<label>". t('Legend') ."</label>";
  $output .= theme('diff_inline_chunk', array('text' => t('Added'), 'type' => 'add'));
  $output .= theme('diff_inline_chunk', array('text' => t('Changed'), 'type' => 'change'));
  $output .= theme('diff_inline_chunk', array('text' => t('Deleted'), 'type' => 'relete'));
  $output .= "</div>";
  $output .= "</div>";
  return $output;
}
