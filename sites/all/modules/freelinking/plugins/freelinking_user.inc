<?php
/**
 * Freelinking User Plugins
 *
 * @file
 *   Provides automatic link creation to user profile pages.
 */

$freelinking['user'] = array(
  'indicator' => '/(u|user|username|uid|userid)$/',
  'tip' => t('Link to a user profile by name or uid.'),
  'callback' => 'freelinking_user_callback',
  'failover' => array('search'),
);

/**
 * Builds a link to a user profile
 *
 * @return
 *   array to build the link
 */
function freelinking_user_callback($target, $plugin) {
  if (is_numeric($target['dest'])) {
    // TODO Convert "user_load" to "user_load_multiple" if "$target['dest']" is other than a uid.
    // To return a single user object, wrap "user_load_multiple" with "array_shift" or equivalent.
    // Example: array_shift(user_load_multiple(array(), $target['dest']))
    $user = user_load($target['dest']);
  }
  else {
    $user = array_shift(user_load_multiple(array(), array('name' => $target['dest'])));
  }

  if (!$user) {
    return array(
      'failover' => variable_get('freelinking_user_failover', 'error'),
      'message' => t('User "%user" not found', array('%user' => $target['dest'])),
    );
  }

  $title = $target['text'] ? $target['text'] : $user->name;
  $url = 'user/' . $user->uid;
  $tooltip = $target['tooltip'] ? $target['tooltip'] : t('View user profile.');

  return array($title, $url, array(
      'attributes' => array(
        'title' => $tooltip,
      ),
    ));
}
