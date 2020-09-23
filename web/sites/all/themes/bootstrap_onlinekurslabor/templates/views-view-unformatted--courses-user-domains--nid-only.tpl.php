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
      $users_state_for_domain = _custom_general_get_group_state_for_user($row_node);
      ?>
      <?php if ($users_state_for_domain != OG_STATE_ACTIVE): ?>
        <?php echo theme('custom_general_personal_group_state_badge', array('state' => $users_state_for_domain)); ?>
      <?php endif ?>
      <a href="/node/<?= $nid ?>" >
          <?php
          echo node_load($nid)->title;
          ?>
      </a>
  </span>

<?php endforeach; ?>
