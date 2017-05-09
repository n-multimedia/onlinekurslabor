<?php
/*
 * home: meine kurse ansicht
 */
$nid = $fields['nid']->raw;

$node_path = url('node/' . $nid);

$node = node_load($nid);

unset($fields['nid']);


$field_view = field_view_field('node', $node, 'field_course_header', array('settings' => array('image_style' => 'course_header')));

$uri = $field_view['#items'][0]['uri'];
$url = image_style_url('homescreen_course_header', $uri);

$path = $url;

$node_titel = trim($node->title);
#   if(strlen($node_titel) >35)
# $node_titel = substr($node_titel, 0, 31).'...';
?>

<div class="row">
    <a href="<?php echo $node_path; ?>" class="home_course_item"  title="<?php echo trim($node->title); ?>">
        <div class="col-md-12 home_course_preview" style="background-image:url(<?php echo $path; ?>); "></div>
        <div class="col-md-12 home_course_preview-hover_box home_background_black_transp"><?= $node_titel ?></div>


    </a>
</div>