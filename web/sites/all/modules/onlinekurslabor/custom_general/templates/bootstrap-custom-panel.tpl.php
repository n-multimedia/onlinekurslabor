<?php
/**
 * Erstellt eine panel-group. Nicht bootstrap-theme-core &  theme('bootstrap_panel', array( 'element'=> $collapsed_element) ist buggy .
 * @see https://www.drupal.org/node/2729181
 * 
 * @param array $element
 * in der form array:
 * @param #title
 * @param #value
 * @param #id
 * @param #collapsible //derzeit ungenützt....
 * @param #collapsed
 * */
$html_id = $element['#id']? : "collapse_" . crc32($element["#title"]);
$body_classes = 'panel-collapse collapse '.($element['#collapsed']?'':'in');
?>
<div class="panel-group">
    <div class="panel panel-default">
        <div class="panel-heading">
            <h4 class="panel-title">
                <a data-toggle="collapse" href="#<?php echo $html_id ?>"><?php echo $element["#title"] ?></a>
            </h4>
        </div>
        <div id="<?php echo $html_id ?>" class="<?php echo $body_classes?>">
            <div class="panel-body"><?php echo $element["#value"] ?></div>

        </div>
    </div>
</div>
