<?php

/**
 * Field handler to present a link to edit a workflow log comment.
 */
class workflow_extensions_handler_field_workflow_comment_link_edit extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['hid'] = 'hid';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array(
      'default' => '',
      'translatable' => TRUE,
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    if (!user_access('edit workflow log')) {
      return;
    }
    $hid = $values->{$this->aliases['hid']};
    $text = empty($this->options['text']) ? t('edit comment') : $this->options['text'];
    return l($text, "workflow-log/$hid", array('query' => drupal_get_destination()));
  }
}

