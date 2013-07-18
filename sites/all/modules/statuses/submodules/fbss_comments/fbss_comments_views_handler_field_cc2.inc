<?php

/**
 * @file
 *   Provides a "comment count" view field handler.
 */

/**
 * Implements the "comment count" field.
 */
class fbss_comments_views_handler_field_cc2 extends views_handler_field {
  function render($values) {
    $sid = $values->{$this->field_alias};
    $count_query = db_select('fbss_comments')
      ->condition('sid', $sid);
    $count_query->addExpression('COUNT(cid)');
    $count = $count_query->execute()
      ->fetchField();
    return format_plural($count, '1 comment', '@count comments');
  }
}
