<?php
/**
 * FILE for link to LEHRTEXT on /domains || profile ||  HOME
 */
// available vars:
// $row
// $users_state_for_domain
//  dpm($row);

?>

<?php if($users_state_for_domain > OG_STATE_ACTIVE): ?>
<?php echo theme('custom_general_personal_group_state_badge', array('state'=>$users_state_for_domain));?>
<?php endif?>
<?php echo l($row->node_title, '/node/'.$row->nid);?>