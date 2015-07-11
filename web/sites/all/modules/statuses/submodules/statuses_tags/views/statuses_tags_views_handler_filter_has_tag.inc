<?php

/**
 * @file
 *   Filter to statuses containing tags.
 */

/**
 * Filter handler to select statuses containing tags.
 */
class statuses_tags_views_handler_filter_has_tag extends views_handler_filter {
  function option_definition() {
    $options = parent::option_definition();
    $options['statuses_tags_has_tags'] = array(
      'default' => 1,
      'translatable' => FALSE,
    );
    $options['statuses_tags_type'] = array(
      'default' => array(),
      'translatable' => FALSE,
    );
    return $options;
  }
  function options_form(&$form, &$form_state) {
    $opt = array('user' => t('Users'));
    if (module_exists('taxonomy')) {
      $opt['term'] = t('Terms');
    }
    $options = $this->options;
    $form['warning'] = array(
      '#value' => t('Warning: this filter can be slow.'),
    );
    $form['statuses_tags_has_tags'] = array(
      '#title' => t('Has tags?'),
      '#type' => 'checkbox',
      '#default_value' => $options['statuses_tags_has_tags'],
    );
    $form['statuses_tags_type'] = array(
      '#title' => t('Tag types'),
      '#type' => 'checkboxes',
      '#required' => TRUE,
      '#options' => $opt,
      '#default_value' => $options['statuses_tags_type'],
    );
  }
  function query() {
    $op = ($this->options['statuses_tags_has_tags']) ? 'IN' : 'NOT IN';
    $options = $this->options['statuses_tags_type'];
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'));
    $db_or = db_or();
    if (count($options) > 0) {
      foreach ($options as $type => $val) {
        if ($val) {
          $db_or->condition('type', $type);
        }
      }
    }
    $query->condition($db_or);
    $this->query->add_where(0, 'sid', $query, $op);
  }
}
