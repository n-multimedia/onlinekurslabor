<?php
/**
 * FILE for link to LEHRTEXT on /domains / profile / HOME
 */
//dpm($row);
global $user;
//if we're viewing a different user
$affected_user_uid = $view->argument['uid']->argument;
$user_for_state = $user;
if($affected_user_uid)
{
  $user_for_state = user_load($affected_user_uid);
}

$node = node_load($row->nid);
$users_state_for_domain = _custom_general_get_group_state_for_user($node,$user_for_state);
?>

<?php if($users_state_for_domain > OG_STATE_ACTIVE): ?>
<?php echo theme('custom_general_personal_group_state_badge', array('state'=>$users_state_for_domain));?>
<?php endif?>
<?php echo l($row->node_title, '/node/'.$row->nid);?>