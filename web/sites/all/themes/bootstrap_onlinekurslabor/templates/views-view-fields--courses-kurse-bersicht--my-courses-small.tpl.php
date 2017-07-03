<?php
/*
 * home: meine kurse ansicht
 */
$nid = $fields['nid']->raw;

$node_path = url('node/' . $nid);

$node = node_load($nid);

unset($fields['nid']);

$my_membership = og_get_membership('node', $nid, 'user', $user->uid);
  
$items = field_get_items('node', $node, 'field_description'); 
/*dozenten-output*/
$kurs_dozent_objects =  custom_general_get_users_in_group_by_role_real($nid, 'kurs-dozent');
foreach ($kurs_dozent_objects as $dozent_acc) {
     $dozent_realname = realname_load($dozent_acc);
   #$pic  =  _nm_stream_get_user_pic($dozent_acc);
      $dozenten_profile = profile2_load_by_user($dozent_acc, 'master');
    $dozenten_acc_pic = "";
    if (isset($dozenten_profile->field_photo)) {
      $dozenten_acc_picture_field = field_view_field('profile2', $dozenten_profile, 'field_photo', 'value');
      $dozenten_acc_pic = '<img src="'.(image_style_url('profile_mini_thumbnail', $dozenten_acc_picture_field['#items'][0]['uri'])).'" style="padding:2px;" class="courseitem_image_hover_transp" title="'.$dozent_realname.'"/>';
      $kurs_dozenten[] = $dozenten_acc_pic;
    }
  # l($name, drupal_get_path_alias('user/' . $dozent_acc->uid));
}

$field_view = field_view_field('node', $node, 'field_course_picture', array('settings' => array('image_style' => 'course_overview_image')));

$uri = $field_view['#items'][0]['uri'];
$url = image_style_url('course_overview_image', $uri);

$path = $url;

$node_titel = trim($node->title);
#   if(strlen($node_titel) >35)
# $node_titel = substr($node_titel, 0, 31).'...';
 
$start_text = '';
$end_text = '';
$percent = _section_courses_get_timespan_percentage($node, $start_text, $end_text);
 
?>

<div class="nm-stream-node-container  nm_stream">
    <a href="<?php echo $node_path; ?>" class="home_course_item">
        <div class="nm-stream-node row">
            <?php if ($node->status === '0'): ?>
                <div class="view_courses_label draft badge">
                    <?=t('Draft')?>
                </div>
            <?php endif ?>
            <?php if ((int)($my_membership->state) ===   OG_STATE_PENDING): ?>
                <div class="view_courses_label unconfirmed badge">
                     <?=t('unconfirmed')?>
                </div>
            <?php endif?>
            <div class="col-sm-6">
                 <div  class="progress_circle_container"><?php echo section_courses_theme_progressbar($node, 120, FALSE); ?></div>
                 <img src="<?= $url ?>" class="courseitem_image_hover_transp courseitem_courselogo"> 
            </div>
            <div class="col-sm-6">
                <h5> <?= $node_titel ?></h5>
                <div class="hidden-xs"><?= implode("", $kurs_dozenten) ?></div>


            </div>

        </div>
    </a>
</div>
