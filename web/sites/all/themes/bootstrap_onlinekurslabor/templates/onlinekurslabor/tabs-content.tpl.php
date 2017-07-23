<?php
/**
 * @file
 * rendert Bootstrap-Tabs-Content. Nur in Verbindung mit tabs sinnvoll.
 * Benötigt gleiche Variablen wie "tabs"  
 */
$first = true;
?>
<div class="tab-content">
    <?php foreach ($elements as $e_id => $elm): ?>
        <div id="tab-<?= $e_id ?>" class="tab-pane fade <?= ($first ? 'in active' : '') ?>">
            <?= $elm['content'] ?>  
            <?php
            $first = false;
            ?>
        </div>
    <?php endforeach ?>
</div>