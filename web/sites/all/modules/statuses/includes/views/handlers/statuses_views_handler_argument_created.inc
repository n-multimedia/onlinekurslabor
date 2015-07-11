<?php

/**
 * Adds an argument for status creation time.
 */
class statuses_views_handler_argument_created extends views_handler_argument_date {
  /**
   * Add an option to set the default value to the current date.
   * Override the default, which adds node-specific options.
   */
  function default_argument_form(&$form, &$form_state) {
    parent::default_argument_form($form, $form_state);
    $form['default_argument_type']['#options'] += array('date' => t('Current date'));
  }

  /**
   * Constructor implementation
   */
  function construct() {
    parent::construct();
    $this->format = 'F j, Y';
    $this->arg_format = 'Ymd';
    $this->formula = views_date_sql_format($this->arg_format, "***table***.$this->real_field");
  }

  /**
   * Provide a link to the next level of the view
   */
  function summary_name($data) {
    $created = $data->{$this->name_alias};
    return format_date(strtotime($created . " 00:00:00 UTC"), 'custom', $this->format, 'UTC');
  }

  /**
   * Provide a link to the next level of the view
   */
  function title() {
    return format_date(strtotime($this->argument . " 00:00:00 UTC"), 'custom', $this->format, 'UTC');
  }
}
