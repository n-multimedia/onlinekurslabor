<?php

/**
 * @file
 *   The handler for the Privacy filter.
 */

/**
 * Controls whether private statuses are included in the View results.
 */
class fbss_privacy_views_handler_filter extends views_handler_filter {
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'radios',
      '#default_value' => isset($this->value) ? $this->value : '',
      '#required' => TRUE,
      '#options' => array(
        0 => t('Show only non-private status messages'),
        1 => t('Show only private status messages'),
        'all' => t('Show private and non-private status messages'),
      ),
      '#description' => t('If you choose an option that shows private messages, only private status messages which the user is permitted to see will be shown.'),
    );
  }
  function query() {
    global $user;
    $table_alias = $this->ensure_my_table();
    // This selects only statuses in which the current user participated.
    $subquery = db_or()
      ->condition("$table_alias.sender", $user->uid)
      ->condition(db_and()->condition("$table_alias.recipient", $user->uid)->condition("$table_alias.type", 'user'));
    // Show only private or only non-private status messages.
    if (is_numeric($this->value)) {
      // If we're showing only private messages, only show the ones in which the current user participated, unless the current user has permission to see all private messages.
      if ($this->value && !user_access('view all private status messages')) {
        $this->query->add_where('fbss_privacy', db_and()->condition("$table_alias.private", $this->value)->condition($subquery));
      }
      else {
        $this->query->add_where('fbss_privacy', "$table_alias.private", $this->value);
      }
    }
    // Show private and non-private messages.
    else {
      // Only show private messages in which the current user participated, unless the current user has permission to see all private messages.
      if (user_access('view all private status messages')) {
        $this->query->add_where('fbss_privacy', db_or()->condition("$table_alias.private", 0)->condition("$table_alias.private", 1));
      }
      else {
        $this->query->add_where('fbss_privacy', db_or()
          ->condition("$table_alias.private", 0)
          ->condition(db_and()->condition("$table_alias.private", 1)->condition($subquery))
        );
      }
    }
  }
}
