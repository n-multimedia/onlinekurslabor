<?php
/**
 * @file
 * rendert Bootstrap-Tabs.
 * Auch benötigt: tabs-content.tpl.php!
 * kA warum nicht Teil des Cores :(
 * übergebene Variablen: $elements[id]=>array [title],[content]
 * für Future-Versions kann man sich noch Angaben wie fade als Parameter überlegen (siehe tabs-content)
 */
$first = true;
?>

<ul class="nav nav-tabs">

    <?php foreach ($elements as $e_id => $elm): ?>
        <li class="<?= ($first ? 'active' : '') ?>"><a data-toggle="tab" href="#tab-<?= $e_id ?>"><?= $elm['title'] ?></a></li>
        <?php
        $first = false;
        ?>

    <?php endforeach ?>
</ul>