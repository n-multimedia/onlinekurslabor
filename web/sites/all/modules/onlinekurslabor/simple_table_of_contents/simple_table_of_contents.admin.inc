<?php

/**
 * @file
 * Generate configuration form and save settings.
 */

/**
 * Configuration form for table of contents options.
 */
function simple_table_of_contents_configuration_form($form, &$form_state) {
  $form['simple_table_of_contents_position'] = array(
    '#type' => 'select',
    '#title' => t('Position'),
    '#options' => array(
      'above' => t('Above'),
      'below' => t('Below'),
    ),
    '#default_value' => variable_get('simple_table_of_contents_position', 'top'),
    '#description' => t('Determines whether the table of contents is displayed above or below body content.'),
  );
  $form['simple_table_of_contents_minimum_heading'] = array(
    '#type' => 'select',
    '#title' => t('Minimum heading'),
    '#options' => array(
      1 => t('H2'),
      2 => t('H3'),
      3 => t('H4'),
      4 => t('H5'),
      5 => t('H6'),
    ),
    '#default_value' => variable_get('simple_table_of_contents_minimum_heading', 5),
    '#description' => t('Select the minimum heading displayed in the table of contents.'),
  );
  $form['simple_table_of_contents_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('simple_table_of_contents_title', t('Table of Contents')),
    '#description' => t('The title of the table of contents. Leave blank for no title.'),
  );

  return system_settings_form($form);
}
