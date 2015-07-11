<?php

function og_role_access_add_user_to_group_action_info() {
  return array('og_role_access_add_user_to_group_action' => array(
    'type' => 'user',
    'label' => t('Add user to group'),
    'configurable' => TRUE,
  ));
}

function og_role_access_add_user_to_group_action_form($context) {
	
  $og_groups = og_role_access_get_all_groups('node');
  //$og_roles = og_roles($group_type, $bundle, $gid, FALSE, FALSE);
  $og_roles = og_role_access_og_get_all_roles();
  $og_states = og_group_content_states();

  $form['add_groups'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Add to group'),
    '#description' => t('Choose one or more groups you would like to add the selected users to.'),
    '#options' => $og_groups,
    '#size' => 5
  );
  $form['add_roles'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Add roles'),
    '#description' => t('Choose one or more roles you would like to assign to the selected users.'),
    '#options' => $og_roles,
    '#size' => 5
  );
  $form['set_state'] = array(
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Set state'),
    '#description' => t('Choose the membership state you would like to set for the selected users.'),
    '#options' => $og_states,
    '#size' => 5
  );
  return $form;
}

function og_role_access_add_user_to_group_action_validate($form, $form_state) {
  if (!$form_state['values']['add_groups']) {
    form_set_error('add_groups', t('You have not chosen any groups to add the user to.'));
  }
  if (!$form_state['values']['add_roles']) {
    form_set_error('add_roles', t('You have not chosen any role to assign to the user.'));
  }
  if (!$form_state['values']['set_state']) {
    form_set_error('set_state', t('You have not chosen a membership state for the users.'));
  }
}

function og_role_access_add_user_to_group_action_submit($form, $form_state) {
  return array(
    'add_groups' => array_filter($form_state['values']['add_groups']),
    'add_roles' => array_filter($form_state['values']['add_roles']),
    'set_state' => $form_state['values']['set_state'],
  );
}

function og_role_access_add_user_to_group_action(&$user, $context) {
  $group_type = 'node';
  $entity_type = 'user';
  $etid = $user->uid;
  $values = array(
    'entity_type' => 'user',
    'entity' => $user->uid,
    'field_name' => 'og_user_group_ref',
    'state' => $context['set_state'],
    );

  foreach ($context['add_groups'] as $gid) {
    og_group($group_type, $gid, $values);

    if(og_get_membership($group_type, $gid, $entity_type, $etid)){
      foreach ($context['add_roles'] as $rid) {
        og_role_grant($group_type, $gid, $etid, $rid);
      }
    }
  } 
}
