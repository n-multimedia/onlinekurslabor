<?php
/**
 * @file
 *  view template to display "my domains" in a list 
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h5><?php print $title; ?></h5>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php $nid = trim($row); ?>
  <span>
  <?php
  $row_node = node_load($nid);
  $users_state_for_domain = _custom_general_get_user_state_in_group($row_node);
  if ($users_state_for_domain == OG_STATE_ACTIVE) {
    echo l($row_node->title, '/node/' . $row_node->nid);
  }
  elseif ($users_state_for_domain == OG_STATE_PENDING) {
    ?>
    <div class="group_label unconfirmed badge">
    <?= t('unconfirmed') ?>
    </div>
        <?php
        echo $row_node->title;
      }
      ?>
  </span>
<?php endforeach; ?>
