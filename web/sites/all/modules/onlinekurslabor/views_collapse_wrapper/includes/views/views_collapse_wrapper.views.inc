<?php


/**
 * Implements hook_views_plugins().
 */
function views_collapse_wrapper_views_plugins() {
  $path = drupal_get_path('module', 'views_collapse_wrapper') . '/includes/views';
  return array(
    'style' => array(
      'collapse_wrapper' => array(
        'parent' => 'table',
        'path' => $path,
        'title' => t('Collapse-wrapper'),
        'help' => t('Adds a wrapper to collapse the views content'),
        'handler' => 'views_collapse_wrapper_plugin_style_collapse_wrapper',
        'theme path' => drupal_get_path('module', 'views_collapse_wrapper') . '/includes',
        'theme file' => 'theme.inc',
        'theme' => 'views_view_collapse_wrapper',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => FALSE,
        'type' => 'normal',
      ),
    ),
  );
}
