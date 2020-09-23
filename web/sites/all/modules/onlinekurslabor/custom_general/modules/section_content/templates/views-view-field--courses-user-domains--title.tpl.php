<?php
/**
 * FILE for link to LEHRTEXT on /domains
 */
//dpm($row);
$node = node_load($row->nid);
$users_state_for_domain = _custom_general_get_group_state_for_user($node);
?>

<?php if($users_state_for_domain > OG_STATE_ACTIVE): ?>
<?php echo theme('custom_general_personal_group_state_badge', array('state'=>$users_state_for_domain));?>
<?php endif?>
<?php echo l($row->node_title, '/node/'.$row->nid);?>