<?php

/**
 * @file
 * Footnotes field admin file.
 */

/**
 * Renders admin form.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   The form state array.
 */
function _footnotes_field_admin_form($form, &$form_state) {
  $content_types = _footnotes_get_content_types();
  $settings = _footnotes_field_get_settings();

  if (module_exists('ds')) {
    $form['content_types'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Content types'),
      '#options' => $content_types,
      '#default_value' => !empty($settings['content_types']) ? $settings['content_types'] : array(),
      '#description' => t('Select the content types you want to enable the footnotes field for. This will expose an extra field on the "manage display" page of the selected content types. The footnotes will be stripped from the node text fields and will be added in this custom field.'),
    );
  }
  else {
    $form['content_types'] = array(
      '#markup' => '<div class="messages warning">' . t('If you want to expose the footnotes as a field you have to install <a href="!url">Display Suite</a>.', array('!url' => url('https://www.drupal.org/project/ds'))) . '</div>',
    );
  }

  $form['expose_block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Expose footnotes as block'),
    '#default_value' => !empty($settings['expose_block']) ? $settings['expose_block'] : 0,
    '#description' => t('This will expose a block which you can add on a node detail page. The footnotes will be stripped from the node text fields and will be added in this block.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  if (module_exists('ds')) {
    $form['info'] = array(
      '#markup' => '<div class="messages warning">' . t('Saving this form will clear all caches to expose a Display Suite field.') . '</div>',
    );
  }
  return $form;
}

/**
 * Submit handler.
 *
 * @param array $form
 *   Form array.
 * @param array $form_state
 *   Form_state array.
 */
function _footnotes_field_admin_form_submit($form, &$form_state) {
  $content_types = NULL;
  if (isset($form_state['values']['content_types'])) {
    $content_types = $form_state['values']['content_types'];
  }
  $expose_block = $form_state['values']['expose_block'];

  variable_set('footnotes_field_settings',
      array(
        'content_types' => $content_types,
        'expose_block' => $expose_block,
      ));

  if (module_exists('ds')) {
    drupal_flush_all_caches();
  }
  drupal_set_message(t('Your settings have been saved.'));
}

/**
 * Fetches option mist with all content types.
 */
function _footnotes_get_content_types() {
  $options = array();
  $content_types = node_type_get_types();

  foreach ($content_types as $key => $content_type) {
    $options[$key] = $content_type->name;
  }

  return $options;
}
