<?php

/**
 * @file
 *   Handling for the sender's picture in Views.
 */

/**
 * Shows the profile picture for the user that sent the status.
 */
class statuses_views_handler_field_sender_pic extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    if (module_exists('imagecache_profiles')) {
      $options['imagecache_preset'] = array(
        'default' => variable_get('user_picture_imagecache_profiles_default', ''),
        'translatable' => FALSE,
      );
    }
    return $options;
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    if (module_exists('imagecache_profiles')) {
      $options = $this->options;
      $form['imagecache_preset'] = array(
        '#title' => t('Image style'),
        '#type'  => 'select',
        '#options' => image_style_options(TRUE),
        '#default_value' => $options['imagecache_preset'],
      );
    }
  }
  function render($values) {
    $account = user_load($values->{$this->field_alias});
    $options = $this->options;
    $preset = NULL;
    if (isset($options['imagecache_preset']) && $options['imagecache_preset']) {
      $preset = $options['imagecache_preset'];
    }
    $picture = statuses_display_user_picture($account, $preset);
    if (!empty($picture)) {
      return '<div class="statuses-sender-picture user-picture">'. $picture .'</div>';
    }
    return '';
  }
}
