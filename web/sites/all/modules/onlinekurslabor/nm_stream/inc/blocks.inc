<?php

function _nm_stream_form_add_edit_view($type='nm_stream') {

  //$type = 'nm_stream';

  //$output = drupal_render(drupal_get_form('nm_stream_add_edit_form', null, $type));
  $output = '';
  $node = new stdClass();
  $node->nid = 0;
  $node->type = $type;
  if(node_access('create', $node)) {
    $output = theme('nm_stream_stream_node_form');
  }

  return $output;
}

/*
  function nm_stream_add_edit_form($node, &$form_state) {

  $form = array();
  $type = $form_state['build_info']['args'][1];

  $form['container'] = array(
  '#type' => 'container',
  '#prefix' => '<div class="row">',
  '#suffix' => '</div>',
  '#attributes' => array('class' => array('col-md-12'))
  );

  $form['container']['body'] = array(
  '#type' => 'textarea',
  );

  $options = _nm_stream_privacy_options();

  $form['container']['controls'] = array(
  '#type' => 'container',
  '#prefix' => '<div class="row">',
  '#suffix' => '</div>',
  );
  $form['container']['controls']['privacy'] = array(
  '#type' => 'select',
  '#options' => $options['items'],
  '#prefix' => '<div class="col-md-offset-5 col-md-5">',
  '#suffix' => '</div>',
  '#default_value' => $options['default'],
  //'#title' => t('Privacy settings'),
  );
  $form['container']['controls']['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Post'),
  '#prefix' => '<div class="buttons col-md-2">',
  '#suffix' => '</div>',
  '#attributes' => array('class' => array('btn', 'btn-primary')),
  );

  //node type need to be set
  //set which node tpye we want to add/edit
  $form['container']['type'] = array(
  '#type' => 'hidden',
  '#value' => $type
  );

  //todo: validate if content type is valid

  return $form;
  }
 */
/*
function nm_stream_add_edit_form_submit(&$form_state) {
  global $user;

  $type = $form_state['type']['#value'];
  $body = $form_state['body']['#value'];
  $privacy = $form_state['privacy']['#value'];

  $node = new stdClass();
  $node->title = time();
  $node->type = $type;
  $node->body[LANGUAGE_NONE][0]['value'] = $body;
  node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
  $node->language = 'de';
  $node->uid = $user->uid;
  $node->status = 1; //(1 or 0): published or not
  $node->promote = 0; //(1 or 0): promoted to front page
  $node->comment = 2; // 0 = comments disabled, 1 = read only, 2 = read/write
  //todo add og context!

  $node = node_submit($node); // Prepare node for saving
  node_save($node);
}
*/
