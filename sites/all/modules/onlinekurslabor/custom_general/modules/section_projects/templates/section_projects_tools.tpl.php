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


  <!--
  <?php if (!empty($context_items)): ?>
    <?php echo $context_items['title'] ?>
    <ul>
      <?php foreach ($context_items['items'] as $item): ?>
        <li><?php echo $item; ?></li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
</div>
  -->
<?php

  //prepare array for the structure needed by _custom_general_theme_tools_block
  $tool_links = array();
  $count = 0;
  foreach($context_items['items'] as $item){

    $attributes = array('attributes' => array('id' => $item['name'], 'class' => array('btn')));

    if (isset($item['path'])) {
      custom_general_append_active_class(($item['path']), $attributes);
    }
    $tool_link['group']['gid'] = $count++;
    $tool_link['group']['root'] = true;
    $tool_link['link'] = $item['link'];
    $tool_link['attributes'] = $attributes['attributes'];


    $tool_links[] = $tool_link;

  }

 echo _custom_general_theme_tools_block($tool_links, "projects_tools", "btn-group btn-group-vertical", 1);
?>

