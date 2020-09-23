<?php
/**
 * FILE for link to LEHRTEXT on /domains
 */
//dpm($row);
$node = node_load($row->nid);
$users_state_for_domain = _custom_general_get_user_state_in_group($node);
if($users_state_for_domain == OG_STATE_ACTIVE)
{
  echo l($row->node_title, '/node/'.$row->nid);
}
elseif($users_state_for_domain == OG_STATE_PENDING)
{
  ?>
<div class="group_label unconfirmed badge">
                     <?=t('unconfirmed')?>
</div>
<?php
  echo $row->node_title;
}
else
{
   echo $row->node_title;
}
