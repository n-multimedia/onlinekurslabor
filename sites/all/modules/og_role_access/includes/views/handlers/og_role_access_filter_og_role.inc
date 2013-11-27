<?php

/**
 * @file
 * Contains the group filter for field group audience - role.
 */

/**
 * Field group audience - "role" filter handler.
 */
class og_role_access_filter_og_role extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Group member role');
      $this->value_options = og_role_access_og_get_all_roles();
    }
  }

}
