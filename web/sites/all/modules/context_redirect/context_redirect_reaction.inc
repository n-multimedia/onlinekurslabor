<?php
/**
 * @file
 * Context redirect reaction plugin for Context API.
 */

class context_redirect_reaction extends context_reaction {
  /**
   * Implements options_form().
   */
  public function options_form($context) {
    $values = $this->fetch_from_context($context);
    $form['#tree'] = TRUE;
    $form['redirect_path'] = array(
      '#title' => t('Redirect URL or path'),
      '#type' => 'textfield',
      '#default_value' => isset($values['redirect_path']) ? $values['redirect_path'] : '',
      '#description' => t('Provide a valid internal URL (ie. node/1) or path (ie. company/about-us) or an external URL (ie. http://drupal.org). You may also use @front to redirect to the front page.', array('@front' => '<front>')),
    );

    $form['enable_message'] = array(
      '#title' => t('Display redirect message'),
      '#type' => 'checkbox',
      '#default_value' => isset($values['enable_message']) ? $values['enable_message'] : 0,
      '#description' => t('When enabled, this will display a message to the user saying they were redirected.'),
    );

    $form['redirect_message'] = array(
      '#title' => t('Redirect message'),
      '#type' => 'textfield',
      '#default_value' => isset($values['redirect_message']) ? $values['redirect_message'] : '',
      '#description' => t('The message displayed to the user after they are redirected.'),
      '#states' => array(
        'visible' => array(
          ':input[name="reactions[plugins][context_redirect][enable_message]"]' => array('checked' => TRUE),
        ),
      ),
    );
    
    $form['qsa'] = array(
      '#title' => t('Attach query string'),
      '#type' => 'checkbox',
      '#default_value' => isset($values['qsa']) ? $values['qsa'] : 0,
      '#description' => t('When enabled, append the original query string (GET values) to redirected URL.'),
    );

    $form['redirect_type'] = array(
      '#title' => t('Redirect type'),
      '#type' => 'select',
      '#default_value' => isset($values['redirect_type']) ? $values['redirect_type'] : 302,
      '#description' => t('The type of redirect to issue. You can !link.', array('!link' => l('review HTTP redirect codes here', 'http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3'))),
      '#options' => array(
        301 => '301: Moved Permanently',
        302 => '302: Found',
        303 => '303: See Other',
        307 => '307: Temporary Redirect',
      ),
    );

    $form['admin_key'] = array(
      '#title' => t('Admin Key'),
      '#type' => 'textfield',
      '#default_value' => isset($values['admin_key']) ? $values['admin_key'] : '',
      '#field_prefix' => url('', array('query' => array('admin_key' => ''), 'absolute' => TRUE)),
      '#description' => t('You can optionally provide an "admin key" which you can enter as a get variable in the page url to prevent the redirect triggering (eg. ?admin_key=no-redirect-please your admin key would be "no-redirect-please"). Leave blank to disable this.'),
    );

    return $form;
  }

  /**
   * Implements execute().
   */
  public function execute() {
    $contexts = $this->get_contexts();

    foreach ($contexts as $context) {
      if (!empty($context->reactions[$this->plugin])) {
        if ($url = $context->reactions[$this->plugin]['redirect_path']) {
          if ($this->context_redirect_validate_redirect($url, $context)) {
            if ($context->reactions[$this->plugin]['enable_message'] == 1) {
              drupal_set_message(t('@message', array('@message' => check_plain($context->reactions[$this->plugin]['redirect_message']))));
            }
            $options = array();
            if ($context->reactions[$this->plugin]['qsa'] == 1) {
              $options['query'] = drupal_get_query_parameters();
            }
            watchdog('context_redirect', 'User was redirected with the @context context, from @from to @destination.', array('@context' => $context->name, '@from' => current_path(), '@destination' => $url), WATCHDOG_NOTICE, l("Configure {$context->name} context", "admin/structure/context/list/{$context->name}"));
            drupal_goto($url, $options, isset($context->reactions[$this->plugin]['redirect_type']) ? $context->reactions[$this->plugin]['redirect_type'] : 302);
          }
        }
      }
    }
  }

  /**
   * Validate the redirection.
   *
   * Depending on the current page, the destination url and the context's
   * configuration we may not want to allow this redirection.
   *
   * @param string $url
   *   The candidate destination url to be validated.
   * @param object $context
   *   The context object provided by Context API.
   *
   * @return boolean
   *   TRUE if the redirect should be allowed, FALSE otherwise.
   */
  public function context_redirect_validate_redirect($url, $context) {
    $valid_redirect = TRUE;

    // If the url is not a valid path do nothing.
    if (!drupal_valid_path($url, FALSE)) {
      $valid_redirect = FALSE;
    }

    // If the current page is the destination url we'll get a redirect loop.
    if ($url == $_GET['q']) {
      $valid_redirect = FALSE;
    }
    elseif ($url == drupal_get_path_alias($_GET['q'])) {
      $valid_redirect = FALSE;
    }

    // Don't perform redirections on the context configuration screens.
    if ($_GET['q'] == "admin/structure/context/list/{$context->name}"
      || $_GET['q'] == "admin/structure/context/list") {
      $valid_redirect = FALSE;
    }

    // Admin key override.
    if ($admin_key = $context->reactions['context_redirect']['admin_key']) {
      if ($_GET['admin_key'] == $admin_key) {
        $valid_redirect = FALSE;
      }
    }

    // TODO - Invoke API so other modules can decide if redirect should happen.
    return $valid_redirect;
  }
}
