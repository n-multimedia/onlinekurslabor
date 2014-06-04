<?php ?>


<div class="section-projects-tools">
  <?php if (!empty($node_items)): ?>
    <?php echo $node_items['title'] ?>
    <ul>
      <?php foreach ($node_items['items'] as $item): ?>
        <li><?php echo $item; ?></li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>

  <?php if (!empty($context_items)): ?>
    <?php echo $context_items['title'] ?>
    <ul>
      <?php foreach ($context_items['items'] as $item): ?>
        <li><?php echo $item; ?></li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</div>