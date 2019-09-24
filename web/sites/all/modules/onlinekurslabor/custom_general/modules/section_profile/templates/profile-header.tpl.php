<?php
/*
 * Profil-Header: Bild, Name, Kontakt-Button,...
 */
$user = user_load($uid);
?>

<div class="row" id="section_profile-header-bg">

    <div class="col-md-3 col-xs-4 " id="section_profile-avatar">
        <?php
        $profile = profile2_load_by_user($user, 'master');
        $user_pic = "";
        if (isset($profile->field_photo)) {
            $user_picture_field = field_view_field('profile2', $profile, 'field_photo', 'value');
            $user_pic = '<img src="' . (image_style_url('profile_medium', $user_picture_field['#items'][0]['uri'])) . '" id="section_profile_avatar-img" />';
        }
        echo $user_pic;
        ?>
        <h1 id="section_profile_user-realname"><?php echo realname_load($user) ?></h1>
    </div>
    <div class="col-md-6 col-xs-2">
        <!--platzhalter-->
    </div>
    <div class="col-md-3  col-xs-6"  id="section_profile-actions">
        <?php echo _section_profile_get_profile_edit_btn($uid); ?>
        <?php if (module_exists('privatemsg_okl')): ?>
            <?php echo privatemsg_okl_get_profile_btn(); ?>
        <?php endif ?>
        <?php if(user_access('switch users')):?>
            <?php echo _section_profile_get_user_switch_btn($uid); ?>
        <?php endif ?>
    </div>
</div>
