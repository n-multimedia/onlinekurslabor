<?php
/** nid plugin for freelinking
 * Originially by [grayside](http://drupal.org/user/346868)
 * See http://drupal.org/node/486954
 *
 * @file
 * Allows for a link like [[node:<nid>]], [[n:<nid>]], or [[node:<nid>]] to be
 * expanded to a link to the node with the title associated with that nid.
 * A "could not find nid" message is displayed if the nid could not be found.
 */

$freelinking['nid'] = array(
  'indicator' => '/(n(id|ode)?)$/A',
  'callback' => 'freelinking_nid_callback',
  'tip' => t('Link to a local node by nid'),
  'run on view' => TRUE,
);

/**
 * Builds a link to a node in the site 
 * 
 * @return
 *   an array with node properties to build the link.
 */
function freelinking_nid_callback($target, $plugin) { // resolve $target into a link to the node or display failure
  if (!is_numeric($target['dest'])) {
    return array(
      'failover' => 'error',
      'message' => t('Invalid Node ID "!nid"', array('!nid' => $target['dest'])),
    );
  }
  $sql = 'SELECT title FROM {node} WHERE nid = "%s" ';
  $result = db_query('SELECT title FROM {node} WHERE nid = :nid ', array(':nid' => $target['dest']));

  foreach ($result as $node) { // should be only one
    $title = $node->title;
  } // endwhile looping through (one) node

  // Node not found for $nid.
  if (!$title) {
    return array(
      'failover' => 'error',
      'message' => t('Invalid Node ID "!nid"', array('!nid' => $target['dest'])),
    );
  }

  $title = $target['text'] ? $target['text'] : $title;
  if (!$target['tooltip']) {
    $target['tooltip'] = freelinking_internal_tooltip('node', $target['dest']);
  }

  return array($title, 'node/' . $target['dest'], array(
      'attributes' => array('title' => $target['tooltip']),
    ));
}

// vim:tw=300 nowrap syn=php

