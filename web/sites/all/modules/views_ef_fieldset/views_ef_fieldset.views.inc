<?php
/**
 * @file
 * Adds Views3 support.
 *
 */

/**
 * Implements hook_views_plugins().
 */
function views_ef_fieldset_views_plugins() {
  return array(
    'display_extender' => array(
      'views_ef_fieldset' => array(
        'title' => t('Views Exposed Forms Fieldset'),
        'help' => t('Allow exposed filters to be wrapped in a fieldset'),
        'handler' => 'views_ef_fieldset_display_extender_plugin',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'help topic' => 'exposed-form-basic',
        'type' => 'normal',
        'parent' => 'basic',
      ),
    ),
  );
}
