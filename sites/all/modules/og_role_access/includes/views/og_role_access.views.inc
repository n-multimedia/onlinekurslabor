<?php

/**
* Override views_data().
*/
function og_role_access_views_data() {
	
	//$data['og_role']['og_role_access_rel']['filter']['handler'] = 'og_role_access_filter_og_role';
	
	$data['og_users_roles']['table']['group'] = t('OG Role Access: OG Users Roles');
	$data['og_users_roles']['table']['join'] = array(
		'users' => array(
			'left_field' => 'uid', 
			'field' => 'uid',
		),
	);
	$data['og_users_roles']['table']['join'] = array(
		'og_role' => array(
			'left_field' => 'rid', 
			'field' => 'rid',
		),
	);
	$data['og_users_roles']['table']['join'] = array(
		'node' => array(
			'left_field' => 'nid', 
			'field' => 'gid',
		),
	);
	
	$data['og_users_roles']['uid'] = array(
		'title' => t('Referenced User ID'), 
		'help' => t('The user id referenced in the og_users_roles table.'),
		'relationship' => array(
			'base' => 'users',  
			'field' => 'uid', 
			'handler' => 'views_handler_relationship', 
			'label' => t('Referenced User ID'),
		),
		'argument' => array(
			'handler' => 'views_handler_argument', 
			'name field' => 'name', 
			'numeric' => TRUE, 
			'validate type' => 'uid' 
		), 
		'filter' => array(
			'handler' => 'views_handler_filter_numeric' 
		), 
		'sort' => array(
			'handler' => 'views_handler_sort' 
		),
	);
	$data['og_users_roles']['rid'] = array(
		'title' => t('Referenced Role ID'), 
		'help' => t('The role id referenced in the og_users_roles table.'),
		'relationship' => array(
			'base' => 'og_role',  
			'field' => 'rid', 
			'handler' => 'views_handler_relationship', 
			'label' => t('Referenced Role ID'),
		),
		'argument' => array(
			'handler' => 'views_handler_argument', 
			'name field' => 'name', 
			'numeric' => TRUE, 
			'validate type' => 'rid' 
		), 
		'filter' => array(
			'handler' => 'og_role_access_filter_og_role' 
		), 
		'sort' => array(
			'handler' => 'views_handler_sort' 
		),
	);
	$data['og_users_roles']['gid'] = array(
		'title' => t('Referenced Group ID'), 
		'help' => t('The group id referenced in the og_users_roles table.'),
		'relationship' => array(
			'base' => 'node',  
			'field' => 'gid', 
			'handler' => 'views_handler_relationship', 
			'label' => t('Referenced Group ID'),
		),
		'argument' => array(
			'handler' => 'views_handler_argument', 
			'name field' => 'title', 
			'numeric' => TRUE, 
			'validate type' => 'gid' 
		), 
		'filter' => array(
			'handler' => 'views_handler_filter_numeric' 
		), 
		'sort' => array(
			'handler' => 'views_handler_sort' 
		),
	);
	$data['og_users_roles']['group_type'] = array(
		'title' => t('OG Users Roles Group Type'), 
		'help' => t('The Group type.'), 
		'field' => array(
			'handler' => 'views_handler_field', 
			'click sortable' => TRUE, // This is use by the table display plugin.
		), 
		'sort' => array(
		'handler' => 'views_handler_sort',
		), 
		'filter' => array(
		'handler' => 'views_handler_filter_string',
		), 
		'argument' => array(
		'handler' => 'views_handler_argument_string',
		),
	);
	
	/*$data['og_role']['table']['group'] = t('OG Role Access: OG Roles');
	$data['og_role']['table']['base'] = array(
		'field' => 'rid', 
		'title' => t('OG Roles'), 
		'help' => t('The OG Roles.'), 
		'weight' => -10,
	);
	$data['og_role']['table']['join'] = array(
		'node' => array(
			'left_field' => 'nid', 
			'field' => 'gid',
		),
	);
	$data['og_role']['rid'] = array(
		'title' => t('OG Role ID'), 
		'help' => t('The OG Role ID.'), 
		'field' => array(
		'handler' => 'views_handler_field_numeric', 
		'click sortable' => TRUE,
		), 
		'filter' => array(
		'handler' => 'views_handler_filter_numeric',
		), 
		'sort' => array(
		'handler' => 'views_handler_sort',
		),
	);
	$data['og_role']['gid'] = array(
		'title' => t('Role Referenced Group ID'), 
		'help' => t('The group id referenced in the og_role table.'),
		'relationship' => array(
		'base' => 'node',  
		'field' => 'gid', 
		'handler' => 'views_handler_relationship', 
		'label' => t('Role Referenced Group ID'),
		),
	);
	$data['og_role']['name'] = array(
		'title' => t('OG Role Name'), 
		'help' => t('The role name.'), 
		'field' => array(
			'handler' => 'views_handler_field', 
			'click sortable' => TRUE, // This is use by the table display plugin.
		), 
		'sort' => array(
		'handler' => 'views_handler_sort',
		), 
		'filter' => array(
		'handler' => 'views_handler_filter_string',
		), 
		'argument' => array(
		'handler' => 'views_handler_argument_string',
		),
	);*/
	
	return $data;
}

function og_role_access_views_data_alter(&$data) {

  $data['og_role']['table']['group'] = t('OG Role Access: OG Roles');
  $data['og_role']['table']['base'] = array(
    'field' => 'rid',
    'title' => t('OG Roles'),
    'help' => t('The OG Roles.'),
    'weight' => -10,
  );
  $data['og_role']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'gid',
    ),
  );
  $data['og_role']['gid'] = array(
    'title' => t('Role Referenced Group ID'),
    'help' => t('The group id referenced in the og_role table.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'gid',
      'handler' => 'views_handler_relationship',
      'label' => t('Role Referenced Group ID'),
    ),
  );
	
	$data['users']['og_role_access_rel'] = array(
      'group' => t('OG Role Access'),
      'title' => t('OG Users Roles from User'),
      'help' => t('The OG Users Roles associated with the User.'),
      'relationship' => array(
        'entity' => 'user',
        'handler' => 'views_handler_relationship',
        'label' => t('OG Users Roles from User'),
        'base' => 'og_users_roles',
        'base field' => 'uid',
        'relationship field' => 'uid',
      ),
    );
	
	$data['node']['og_role_access_rel'] = array(
      'group' => t('OG Role Access'),
      'title' => t('OG Users Roles from Group node'),
      'help' => t('The OG Users Roles associated with the Group node.'),
      'relationship' => array(
        'entity' => 'node',
        'handler' => 'views_handler_relationship',
        'label' => t('OG Users Roles from Group node'),
        'base' => 'og_users_roles',
        'base field' => 'gid',
        'relationship field' => 'nid',
      ),
    );
	
    $data['og_users_roles']['og_users_roles_related_users'] = array(
      'group' => t('OG Role Access'),
      'title' => t('User from OG Users Roles'),
      'help' => t('The User that is associated with the OG Users Roles.'),
      'relationship' => array(
        'handler' => 'views_handler_relationship',
        'label' => t('User from OG Users Roles'),
        'base' => 'user',
        'base field' => 'uid',
        'relationship field' => 'uid',
      ),
    );
	
	$data['og_users_roles']['og_users_roles_related_node'] = array(
      'group' => t('OG Role Access'),
      'title' => t('Group node from OG Users Roles'),
      'help' => t('The Group node that is associated with the OG Users Roles.'),
      'relationship' => array(
        'handler' => 'views_handler_relationship',
        'label' => t('Group node from OG Users Roles'),
        'base' => 'node',
        'base field' => 'nid',
        'relationship field' => 'gid',
      ),
    );
	
	 $data['og_users_roles']['og_users_roles_related_roles'] = array(
      'group' => t('OG Role Access'),
      'title' => t('Role from OG Users Roles'),
      'help' => t('The Role that is associated with the OG Users Roles.'),
      'relationship' => array(
        'handler' => 'views_handler_relationship',
        'label' => t('Role from OG Users Roles'),
        'base' => 'og_role',
        'base field' => 'rid',
        'relationship field' => 'rid',
      ),
    );
}

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implements hook_views_plugins().
 */
function og_role_access_views_plugins() {
  return array(
    'access' => array(
	  'og_role_access' => array(
        'title' => t('OG role'),
		'help' => t('Access will be granted to users with any of the specified OG roles.'),
        'handler' => 'og_role_access_plugin_access_og_role',
        'uses options' => TRUE,
      ),
    ),
  );
}