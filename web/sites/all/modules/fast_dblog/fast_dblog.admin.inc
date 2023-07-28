<?php

/**
 * @file
 * Administrative page callbacks for the fast_dblog module.
 */

/**
 * Menu callback; displays a listing of log messages.
 *
 * Messages are truncated at 56 chars. Full-length message could be viewed at
 * the message details page.
 *
 * @ingroup logging_severity_levels
 */
function fast_dblog_overview() {
  drupal_add_css(drupal_get_path('module', 'fast_dblog') . '/css/fast_dblog.css');

  $filter = fast_dblog_build_filter_query();
  $rows = array();
  $classes = array(
    WATCHDOG_DEBUG     => 'fast-dblog-debug',
    WATCHDOG_INFO      => 'fast-dblog-info',
    WATCHDOG_NOTICE    => 'fast-dblog-notice',
    WATCHDOG_WARNING   => 'fast-dblog-warning',
    WATCHDOG_ERROR     => 'fast-dblog-error',
    WATCHDOG_CRITICAL  => 'fast-dblog-critical',
    WATCHDOG_ALERT     => 'fast-dblog-alert',
    WATCHDOG_EMERGENCY => 'fast-dblog-emerg',
  );

  $build['fast_dblog_filter_form'] = drupal_get_form('fast_dblog_filter_form');
  $build['fast_dblog_clear_log_form'] = drupal_get_form('fast_dblog_clear_log_form');

  $header = array(
    '', // Icon column.
    array('data' => t('Type'), 'field' => 'w.type'),
    array('data' => t('Date'), 'field' => 'w.wid', 'sort' => 'desc'),
    t('Message'),
    array('data' => t('User'), 'field' => 'u.name'),
    array('data' => t('Operations')),
  );

  $query = db_select('fast_watchdog', 'w')->extend('PagerDefault')->extend('TableSort');
  $query->leftJoin('users', 'u', 'w.uid = u.uid');
  $query
    ->fields('w', array('wid', 'uid', 'severity', 'type', 'timestamp', 'message', 'variables', 'link'))
    ->addField('u', 'name');
  if (!empty($filter['where'])) {
    $query->where($filter['where'], $filter['args']);
  }
  $result = $query
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  foreach ($result as $dblog) {
    $rows[] = array(
      'data' => array(
        // Cells.
        array('class' => 'icon'),
        t($dblog->type),
        format_date($dblog->timestamp, 'custom', 'Y-m-d H:i'),
        theme('fast_dblog_message', array('event' => $dblog, 'link' => TRUE)),
        theme('username', array('account' => $dblog)),
        filter_xss($dblog->link),
      ),
      // Attributes for tr.
      'class' => array(drupal_html_class('fast-dblog-' . $dblog->type), $classes[$dblog->severity]),
    );
  }

  $build['fast_dblog_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#attributes' => array('id' => 'admin-fast-dblog'),
    '#empty' => t('No log messages available.'),
  );
  $build['fast_dblog_pager'] = array('#theme' => 'pager');

  return $build;
}

/**
 * Menu callback; generic function to display a page of the most frequent events.
 *
 * Messages are not truncated because events from this page have no detail view.
 *
 * @param string $type
 *   Type of dblog events to display.
 */
function fast_dblog_top($type) {
  drupal_add_css(drupal_get_path('module', 'fast_dblog') . '/css/fast_dblog.css');

  $header = array(
    array('data' => t('Count'), 'field' => 'count', 'sort' => 'desc'),
    array('data' => t('Message'), 'field' => 'message')
  );
  $count_query = db_select('fast_watchdog');
  $count_query->addExpression('COUNT(DISTINCT(message))');
  $count_query->condition('type', $type);

  $query = db_select('fast_watchdog', 'w')->extend('PagerDefault')->extend('TableSort');
  $query->addExpression('COUNT(wid)', 'count');
  $query = $query
    ->fields('w', array('message', 'variables'))
    ->condition('w.type', $type)
    ->groupBy('message')
    ->groupBy('variables')
    ->limit(30)
    ->orderByHeader($header);
  $query->setCountQuery($count_query);
  $result = $query->execute();

  $rows = array();
  foreach ($result as $dblog) {
    $rows[] = array($dblog->count, theme('fast_dblog_message', array('event' => $dblog)));
  }

  $build['fast_dblog_top_table']  = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No log messages available.'),
  );
  $build['fast_dblog_top_pager'] = array('#theme' => 'pager');

  return $build;
}

/**
 * Menu callback; displays details about a log message.
 */
function fast_dblog_event($id) {
  drupal_add_css(drupal_get_path('module', 'fast_dblog') . '/css/fast_dblog.css');

  $severity = watchdog_severity_levels();
  $result = db_query('SELECT w.*, u.name, u.uid FROM {fast_watchdog} w INNER JOIN {users} u ON w.uid = u.uid WHERE w.wid = :id', array(':id' => $id))->fetchObject();
  if ($dblog = $result) {
    $rows = array(
      array(
        array('data' => t('Type'), 'header' => TRUE),
        t($dblog->type),
      ),
      array(
        array('data' => t('Date'), 'header' => TRUE),
        format_date($dblog->timestamp, 'long'),
      ),
      array(
        array('data' => t('User'), 'header' => TRUE),
        theme('username', array('account' => $dblog)),
      ),
      array(
        array('data' => t('Location'), 'header' => TRUE),
        l($dblog->location, $dblog->location),
      ),
      array(
        array('data' => t('Referrer'), 'header' => TRUE),
        l($dblog->referer, $dblog->referer),
      ),
      array(
        array('data' => t('Message'), 'header' => TRUE),
        theme('fast_dblog_message', array('event' => $dblog)),
      ),
      array(
        array('data' => t('Severity'), 'header' => TRUE),
        $severity[$dblog->severity],
      ),
      array(
        array('data' => t('Hostname'), 'header' => TRUE),
        check_plain($dblog->hostname),
      ),
      array(
        array('data' => t('Operations'), 'header' => TRUE),
        $dblog->link,
      ),
    );
    $build['fast_dblog_table'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
      '#attributes' => array('class' => array('dblog-event')),
    );
    return $build;
  }
  else {
    return '';
  }
}

/**
 * Build query for fast_dblog administration filters based on session.
 */
function fast_dblog_build_filter_query() {
  if (empty($_SESSION['fast_dblog_overview_filter'])) {
    return;
  }

  $filters = fast_dblog_filters();

  // Build query.
  $where = $args = array();
  foreach ($_SESSION['fast_dblog_overview_filter'] as $key => $filter) {
    $filter_where = array();
    foreach ($filter as $value) {
      $filter_where[] = $filters[$key]['where'];
      $args[] = $value;
    }
    if (!empty($filter_where)) {
      $where[] = '(' . implode(' OR ', $filter_where) . ')';
    }
  }
  $where = !empty($where) ? implode(' AND ', $where) : '';

  return array(
    'where' => $where,
    'args' => $args,
  );
}


/**
 * List fast_dblog administration filters that can be applied.
 */
function fast_dblog_filters() {
  $filters = array();

  foreach (_fast_dblog_get_message_types() as $type) {
    $types[$type] = t($type);
  }

  if (!empty($types)) {
    $filters['type'] = array(
      'title' => t('Type'),
      'where' => "w.type = ?",
      'options' => $types,
    );
  }

  $filters['severity'] = array(
    'title' => t('Severity'),
    'where' => 'w.severity = ?',
    'options' => watchdog_severity_levels(),
  );

  return $filters;
}

/**
 * Returns HTML for a log message.
 *
 * @param array $variables
 *   An associative array containing:
 *   - event: An object with at least the message and variables properties.
 *   - link: (optional) Format message as link, event->wid is required.
 *
 * @ingroup themeable
 */
function theme_fast_dblog_message($variables) {
  $output = '';
  $event = $variables['event'];
  // Check for required properties.
  if (isset($event->message) && isset($event->variables)) {
    // Messages without variables or user specified text.
    if ($event->variables === 'N;') {
      $output = $event->message;
    }
    // Message to translate with injected variables.
    else {
      $output = t($event->message, unserialize($event->variables));
    }
    if ($variables['link'] && isset($event->wid)) {
      // Truncate message to 56 chars.
      $output = truncate_utf8(filter_xss($output, array()), 56, TRUE, TRUE);
      $output = l($output, 'admin/reports/fast-event/' . $event->wid, array('html' => TRUE));
    }
  }
  return $output;
}

/**
 * Return form for fast_dblog administration filters.
 *
 * @ingroup forms
 * @see fast_dblog_filter_form_submit()
 * @see fast_dblog_filter_form_validate()
 */
function fast_dblog_filter_form($form) {
  $filters = fast_dblog_filters();

  $form['filters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter log messages'),
    '#collapsible' => TRUE,
    '#collapsed' => empty($_SESSION['fast_dblog_overview_filter']),
  );
  foreach ($filters as $key => $filter) {
    $form['filters']['status'][$key] = array(
      '#title' => filter_xss($filter['title']),
      '#type' => 'select',
      '#multiple' => TRUE,
      '#size' => 8,
      '#options' => $filter['options'],
    );
    if (!empty($_SESSION['fast_dblog_overview_filter'][$key])) {
      $form['filters']['status'][$key]['#default_value'] = $_SESSION['fast_dblog_overview_filter'][$key];
    }
  }

  $form['filters']['actions'] = array(
    '#type' => 'actions',
    '#attributes' => array('class' => array('container-inline')),
  );
  $form['filters']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );
  if (!empty($_SESSION['fast_dblog_overview_filter'])) {
    $form['filters']['actions']['reset'] = array(
      '#type' => 'submit',
      '#value' => t('Reset'),
    );
  }

  return $form;
}

/**
 * Validate result from fast_dblog administration filter form.
 */
function fast_dblog_filter_form_validate($form, &$form_state) {
  if ($form_state['values']['op'] == t('Filter') && empty($form_state['values']['type']) && empty($form_state['values']['severity'])) {
    form_set_error('type', t('You must select something to filter by.'));
  }
}

/**
 * Process result from fast_dblog administration filter form.
 */
function fast_dblog_filter_form_submit($form, &$form_state) {
  $op = $form_state['values']['op'];
  $filters = fast_dblog_filters();
  switch ($op) {
    case t('Filter'):
      foreach ($filters as $name => $filter) {
        if (isset($form_state['values'][$name])) {
          $_SESSION['fast_dblog_overview_filter'][$name] = $form_state['values'][$name];
        }
      }
      break;

    case t('Reset'):
      $_SESSION['fast_dblog_overview_filter'] = array();
      break;
  }
  return 'admin/reports/fast-dblog';
}

/**
 * Return form for fast_dblog clear button.
 *
 * @ingroup forms
 * @see fast_dblog_clear_log_submit()
 */
function fast_dblog_clear_log_form($form) {
  $form['fast_dblog_clear'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clear log messages'),
    '#description' => t('This will permanently remove the log messages from the database.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['fast_dblog_clear']['clear'] = array(
    '#type' => 'submit',
    '#value' => t('Clear log messages'),
    '#submit' => array('fast_dblog_clear_log_submit'),
  );

  return $form;
}

/**
 * Submit callback: clear database with log messages.
 */
function fast_dblog_clear_log_submit() {
  $_SESSION['fast_dblog_overview_filter'] = array();
  db_delete('fast_watchdog')->execute();
  drupal_set_message(t('Database log cleared.'));
}
