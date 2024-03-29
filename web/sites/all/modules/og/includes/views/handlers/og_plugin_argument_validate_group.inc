<?php

/**
 * Validate whether an argument is a valid group.
 *
 * This supports numeric arguments (GID). This validator also sets the
 * argument's title to the group label, which is the main reason behind this
 * validator.
 */
class og_plugin_argument_validate_group extends views_plugin_argument_validate {

  /**
   * List the options relevant for this plugin.
   */
  function option_definition() {
    $options = parent::option_definition();
    $groups = og_get_all_group_entity();
    $options['group_type'] = array('default' => key($groups));

    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    $form['group_type'] = array(
      '#type' => 'select',
      '#title' => t('Group type'),
      '#description' => t('Select the group type.'),
      '#options' => og_get_all_group_entity(),
      '#default_value' => $this->options['group_type'],
      '#required' => og_get_all_group_entity(),
    );
  }

  function validate_argument($argument) {
    if (empty($argument)) {
      return;
    }
    $group_type = $this->options['group_type'];
    // Check if the $argument is a multiple arguments string.

    $ids = views_break_phrase($argument, $this);
    if ($ids->value == array(-1)) {
      // Malformed argument syntax. Invalidate.
      return FALSE;
    }
    $ids = $ids->value;

    if (!is_numeric($argument) && $ids) {
      $groups = entity_load($group_type, $ids);
      foreach ($groups as $entity) {
        if (!$entity || !og_is_group($group_type, $entity)) {
          return FALSE;
        }
        $entity_labels[] = entity_label($group_type, $entity);
      }

      // Resetting variables as strings once validated to be passed to views.
      $entity_labels = implode(' + ', $entity_labels);
      $this->argument->argument = $argument;
      $this->argument->validated_title = $entity_labels;
      return TRUE;
    }
    else {
      $entity = entity_load_single($group_type, $argument);
      if (!$entity || !og_is_group($group_type, $entity)) {
        return FALSE;
      }

      $this->argument->argument = $argument;
      $this->argument->validated_title = entity_label($group_type, $entity);
      return TRUE;
    }
  }
}
