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
    <a href="/domain/text/<?= $nid ?>" >
        <?php
        echo node_load($nid)->title;
        ?>
    </a>
<?php endforeach; ?>
