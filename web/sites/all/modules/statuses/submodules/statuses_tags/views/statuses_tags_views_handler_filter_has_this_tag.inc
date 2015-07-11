<?php

/**
 * @file
 *   Filters to statuses containing a specific tag.
 */

/**
 * Filter handler to select statuses containing a specific tag.
 */
class statuses_tags_views_handler_filter_has_this_tag extends views_handler_filter_string {
  function option_definition() {
    $options = parent::option_definition();
    $options['statuses_tags_type'] = array(
      'default' => array(),
      'translatable' => FALSE,
    );
    return $options;
  }
  function options_form(&$form, &$form_state) {
    $options = parent::options_form($form, $form_state);
    $opt = array('user' => t('Users'));
    if (module_exists('taxonomy')) {
      $opt['term'] = t('Terms');
    }
    $options = $this->options;
    $form['warning'] = array(
      '#value' => t('Warning: this filter can be slow.'),
      '#weight' => -100,
    );
    $form['statuses_tags_type'] = array(
      '#title' => t('Tag types'),
      '#type' => 'checkboxes',
      '#required' => TRUE,
      '#options' => $opt,
      '#default_value' => $options['statuses_tags_type'],
    );
  }
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    if (variable_get('statuses_tags_vid', -1) != -1) {
      $form['value']['#autocomplete_path'] = 'admin/views/ajax/autocomplete/taxonomy/' . variable_get('statuses_tags_vid', -1);
    }
  }
  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    $options = $this->options['statuses_tags_type'];
    $db_or = db_or();
    if (count($options) > 0) {
      foreach ($options as $type => $val) {
        if ($val) {
          $db_or->condition('type', $type);
        }
      }
    }
    $info = $this->operators();
    if (!empty($info[$this->operator]['method'])) {
      $this->{$info[$this->operator]['method']}($field, $db_or);
    }
  }
  function op_equal($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', $this->value, $this->operator)
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_contains($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', '%' . db_like($this->value) . '%', 'LIKE')
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_word($field, $db_or) {
    $where = $this->operator == 'word' ? db_or() : db_and();
    // Don't filter on empty strings.
    if (empty($this->value)) {
      return;
    }
    preg_match_all('/ (-?)("[^"]+"|[^" ]+)/i', ' ' . $this->value, $matches, PREG_SET_ORDER);
    foreach ($matches as $match) {
      $phrase = FALSE;
      if ($match[2]{0} == '"') {
        $match[2] = drupal_substr($match[2], 1, -1);
        $phrase = TRUE;
      }
      $words = trim($match[2], ',?!();:-');
      $words = $phrase ? array($words) : preg_split('/ /', $words, -1, PREG_SPLIT_NO_EMPTY);
      foreach ($words as $word) {
        $placeholder = $this->placeholder();
        $where->condition('name', '%' . db_like(trim($word, " ,!?")) . '%', 'LIKE');
      }
    }
    if (!$where) {
      return;
    }
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition($db_or)
      ->condition($where);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_starts($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', db_like($this->value) . '%', 'LIKE')
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_not_starts($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', db_like($this->value) . '%', 'NOT LIKE')
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_ends($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', '%' . db_like($this->value), 'LIKE')
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_not_ends($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', '%' . db_like($this->value), 'NOT LIKE')
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_not($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', '%' . db_like($this->value) . '%', 'NOT LIKE')
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_shorter($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->where("LENGTH(name) < :length", array(':length' => $this->value))
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_longer($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->where("LENGTH(name) > :length", array(':length' => $this->value))
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }

  function op_regex($field, $db_or) {
    $query = db_select('statuses_tags')
      ->fields('statuses_tags', array('sid'))
      ->condition('name', $this->value, 'RLIKE')
      ->condition($db_or);
    $this->query->add_where($this->options['group'], $field, $query, 'IN');
  }
}
