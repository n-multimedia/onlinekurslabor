<?php

/**
 * Access plugin that provides role-based access control.
 */
class og_role_access_plugin_access_og_role extends views_plugin_access {
  function access($account) {
	//Access for block displays
	return og_role_access_og_user_check_roles($this->options['group_type'],'', array_filter($this->options['og_role']), $account);
  }

  function get_access_callback() {
	//Access for page displays
	return array('og_role_access_og_user_check_roles', array($this->options['group_type'],$this->options['group_id_arg'], array_filter($this->options['og_role'])));
  }

  function summary_title() {
    $count = count($this->options['og_role']);
	if ($this->options['group_id_arg'] != '') {
      $gid_arg = ' - group ID: arg(' . $this->options['group_id_arg'] . ')';
    }
	else{
		$gid_arg = '';	
	}
    if ($count < 1) {
      return t('No role(s) selected');
    }
    elseif ($count > 1) {
      return t('Multiple roles'.$gid_arg);
    }
    else {
	  $rids = og_role_access_og_get_all_roles();
	  $rid = reset($this->options['og_role']);
	  return check_plain($rids[$rid].$gid_arg);
    }
  }


  function option_definition() {
    $options = parent::option_definition();
    $options['og_role'] = array('default' => array());
	$options['group_type'] = array('default' => 'node');
    $options['group_id_arg'] = array('default' => '');
	
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['og_role'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Role'),
      '#default_value' => $this->options['og_role'],
      '#options' => array_map('check_plain', og_role_access_og_get_all_roles()),
      '#description' => t('Only the checked roles will be able to access this display. Note that users with "access all views" can see any view, regardless of role.'),
    );
	$form['group_type'] = array(
      '#type' => 'select',
      '#options' => og_get_all_group_entity(),
      '#title' => t('Group type'),
      '#default_value' => $this->options['group_type'],
      '#description' => t('Determine what entity type that group should be of.')
    );
    $form['group_id_arg'] = array(
      '#type' => 'textfield',
      '#title' => t('argument position for group ID'),
      '#size' => 1,
      '#default_value' => $this->options['group_id_arg'],
      '#description' => t('If this is a <strong>Page</strong> display, identify the argument position of the Group ID. For example, if your path is "node/%/group/%/overview" and you are using the second "%" for group ID, the argument position would be 3.<br>If this is a <strong>Block</strong> display, you can leave this field blank.'),
    );
  }

  function options_validate(&$form, &$form_state) {
    if (!array_filter($form_state['values']['access_options']['og_role'])) {
      form_error($form['og_role'], t('You must select at least one role if type is "by role"'));
    }
  }

  function options_submit(&$form, &$form_state) {
    $form_state['values']['access_options']['og_role'] = array_filter($form_state['values']['access_options']['og_role']);
  }
}
