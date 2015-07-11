<?php
/**
 * Nodetitle plugin for Freelinking
 *
 * @file
 * Allows for a link like [[nodetitle:Freelinking filter]] to be expanded to
 * a link to the node titled "Freelinking filter" or a link to create the node.
 */

$freelinking['nodetitle'] = array(
  'indicator' => '/nt|nodetitle|title/',
  'callback' => 'freelinking_nodetitle_callback',
  'tip' => t('Link to a local node by title'),
  'run on view' => TRUE,
);

/**
 * Replacement callback for nodetitle plugin
 */
function freelinking_nodetitle_callback($target, $plugin) {
  $node = freelinking_nodetitle_nid_from_title($target);

  // if no node was found, identify proceed with configured failover
  if (!$node) {
    return _freelinking_nodetitle_failure($target);
  }

  // construct values for link
  $title = $target['text'] ? $target['text'] : $node->title;

  if (!$target['tooltip']) {
    $target['tooltip'] = freelinking_internal_tooltip('node', $node->nid);
  }
  // return link structure
  return array($title, 'node/' . $node->nid, array(
      'attributes' => array('title' => $target['tooltip']),
      'language' => $node->language,
  ));
}

/**
 * Nodetitle Settings Callback
 */
function freelinking_nodetitle_settings() {
  // Restrict nodetitle plugin to search specified content type
  $form['freelinking_nodetitle_searchcontenttype'] = array(
    '#title' => t('Restrict freelinks to this content type'),
    '#type' => 'select',
    '#options' => array_merge(array('none' => t('No restriction')), node_type_get_names()),
    '#default_value' => variable_get('freelinking_nodetitle_searchcontenttype', 'none'),
    '#description' => t('Lookup by title to find a freelink will be restricted to this content type only.'),
  );

  $failover_option['none'] = t('Do nothing');

  $extra_description = '';

  // if Create Node plugin is available, it's an option!
  if (module_exists('freelinking_prepopulate')) {
    $failover_option['create'] = t('Add a link to create content. (Without Permission: Access Denied)');
  }
  else {
    $extra_description .= '<br /><strong>'
      . t('Note: Enable %module for Content Creation option.', array('%module' => 'Freelinking Create'))
      . '</strong>';
  }

  // if search is available, have a search failover
  if (module_exists('search')) {
    $failover_option['search'] = t('Add a link to Search Content');
  }
  else {
    $extra_description .= '<br /><strong>'
      . t('Note: Enable the %module module for internal search option.', array('%module' => 'Search'))
      . '</strong>';
    // if search is unavailable offer it's own (applicable)search fallback. [Google, etc]
    if (($search_plugin = variable_get('freelinking_search_failover', 'error')) != 'error') {
      $failover_option['search'] = t('Add a link to %search Search Content.',
        array('%search' => drupal_ucfirst($search_plugin)));
    }
  }
  $failover_option['error'] = t('Insert an error message');

  $failover_option['showtext'] = t('Show text');

  $form['freelinking_nodetitle_failover'] = array(
    '#title' => t('If a suitable content is not found'),
    '#type' => 'select',
    '#options' => $failover_option,
    '#default_value' => variable_get('freelinking_nodetitle_failover',
      _freelinking_nodetitle_default_failover()),
    '#description' => t('What should freelinking do when the page is not found?')
      . $extra_description,
  );
  return $form;
} // endfunction freelinking_freelinking_settings()

/**
 * Grab the nid associated with the title.
 * Attempt some degree of language sensibility
 */
function freelinking_nodetitle_nid_from_title(&$target) {
  $title = $target['dest'];

  // get any content type restriction
  if (isset($target['type'])) {
    $type = check_plain($target['type']);
  }
  else {
    $type = variable_get('freelinking_nodetitle_searchcontenttype', 'none');
  }

  $sql = "SELECT title, nid, language FROM {node} WHERE title = :title";
  $params = array(':title' => $title);
  if ($type != 'none') {
    $sql .= " AND type = :type";
    $params[':type'] = $type;
  }
  $result = db_query($sql, $params);
  $set = array();
  foreach ($result as $record) {
    $set[] = $record;
  }

  if (empty($set)) {
    return NULL;
  }

  // language restriction. Includes next-best-language logic.
  $language = array(language_default('language'), '');
  if (module_exists('locale')) {
    if (isset($target['language'])) {
      array_unshift($language, $target['language']);
    }
    foreach ($language as $priority) {
      foreach ($set as $node) {
        if ($priority == $node->language) {
          $retn = $node;
          break 2;
        }
      }
    }
  }
  else {
    $retn = $set[0];
  }
  return $retn;
}

/**
 * Determining the proper failure response per plugin configuration
 */
function _freelinking_nodetitle_failure($target) {
  $failover = variable_get('freelinking_nodetitle_failover',
    _freelinking_nodetitle_default_failover());

  switch ($failover) {
    case 'create':
      return array('failover' => 'createnode', 'target' => $target);
    case 'showtext':
      return array('failover' => 'showtext', 'target' => $target);
    case 'search':
      return array('failover' => 'search', 'target' => $target);
    case 'error':
      return array('failover' => 'error', 'message' => t('%title not found',
        array('%title' => $target['dest'])));

  }
  // do nothing
  return FALSE;
}

/**
 * Find the best default failover
 */
function _freelinking_nodetitle_default_failover() {
  if (module_exists('freelinking_prepopulate')) {
    return 'create node';
  }
  elseif (module_exists('search')) {
    return 'search';
  }
  return 'none';
}
