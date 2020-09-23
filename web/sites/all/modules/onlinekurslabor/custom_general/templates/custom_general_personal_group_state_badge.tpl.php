<?php
/**
 * prints a tiny badge showing the membership state in a group
 */

if(!$state)
{ 
  $membership_state_css = 'badge-light';
  $membership_state_written = t('No member');
}
elseif ($state == OG_STATE_ACTIVE) {
  $membership_state_css = 'badge-info';
  $membership_state_written = t('Member');
}
elseif ($state == OG_STATE_PENDING) {
  $membership_state_css = 'badge-warning';
  $membership_state_written = t('unconfirmed');
}
elseif ($state == OG_STATE_BLOCKED) {
  $membership_state_css = 'badge-danger';
  $membership_state_written = t('blocked');
}
?>


<div class="group_label <?php echo $membership_state_css ?> badge">
<?php echo $membership_state_written ?>
</div>

