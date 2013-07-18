<?php

/**
 * @file
 *   Filters to statuses posted by "followed" users plus the current user.
 */

/**
 * Filter handler to select statuses from friends/followed + current user.
 */
class statuses_views_handler_filter_flagged_user extends views_handler_filter {
  function option_definition() {
    $options = parent::option_definition();
    $content_type = 'user';
    $flags = flag_get_flags($content_type);
    $flag = array_shift($flags);
    $default = $flag ? $flag->fid : NULL;
    $options['statuses_flag_type'] = array(
      'default' => $default,
      'translatable' => FALSE,
    );
    return $options;
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $flags = flag_get_flags('user');
    $options = array();
    foreach ($flags as $flag) {
      $options[$flag->fid] = $flag->get_title();
    }
    $form['warning'] = array(
      '#type' => 'markup',
      '#markup' => t('Warning: this filter can be slow.'),
      '#weight' => -100,
    );
    $form['statuses_flag_type'] = array(
      '#type' => 'radios',
      '#title' => t('Flag'),
      '#options' => $options,
      '#default_value' => $this->options['statuses_flag_type'],
      '#required' => TRUE,
    );
  }
  function query() {
    $query = db_select('flag_content')
      ->fields('flag_content', array('content_id'))
      ->condition('fid', $this->options['statuses_flag_type'])
      ->condition('uid', $GLOBALS['user']->uid);
    $this->query->add_where($this->options['group'], db_or()
      ->condition('sender', $query, 'IN')
      ->condition('sender', $GLOBALS['user']->uid));
  }
}