<?php
/**
 * @file
 * integration with the views module.
 */

/**
 * Implements hook_views_data().
 */
function message_ui_views_data() {
  $data['message']['delete'] = array(
    'title' => t('Delete message'),
    'help' => t('Link to delete the message instance.'),
    'field' => array(
      'handler' => 'message_ui_delete_button',
    ),
  );
  $data['message']['edit'] = array(
    'title' => t('Edit message'),
    'help' => t('Link to edit the message instance.'),
    'field' => array(
      'handler' => 'message_ui_edit_button',
    ),
  );
  $data['message']['view'] = array(
    'title' => t('View message'),
    'help' => t('Link to view the message instance.'),
    'field' => array(
      'handler' => 'message_ui_view_button',
    ),
  );
  return $data;
}

/**
 * Implements hook_views_default_views_alter().
 */
function message_ui_views_default_views_alter(&$views) {
  if (!in_array('message', array_keys($views))) {
    return;
  }

  $handler =& $views['message']->display['default']->handler;

  /* Field: Message: Edit message */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'message';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['label'] = '';
  $handler->display->display_options['fields']['edit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit']['element_label_colon'] = FALSE;
  /* Field: Message: Delete message */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'message';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = '';
  $handler->display->display_options['fields']['delete']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete']['element_label_colon'] = FALSE;
  /* Field: Message: View message */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'message';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operation';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view] [edit] [delete]';
}
