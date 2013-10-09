<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php $last_key = end(array_keys($rows)); ?>
<div class="view-instructor-subtitle">
  <?php foreach ($rows as $id => $row): ?>

    <?php print $row; ?>

    <?php if ($last_key != $id) echo ", "; ?>

  <?php endforeach; ?>
</div>
