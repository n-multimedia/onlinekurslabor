<?php
/*
 * Profil-Header: Bild, Name, Kontakt-Button,...
 */
$user = user_load($uid);

?>
<div class="row" id="section_profile-header-bg">

    <div class="col-md-9"  >
        <div class="row  " id="section_profile-avatar">
            <div class="col-md-12"> 
                <?php
                $profile = profile2_load_by_user($user, 'master');
                $user_pic = "";
                if (isset($profile->field_photo)) {
                    $user_picture_field = field_view_field('profile2', $profile, 'field_photo', 'value');
                    $user_pic = '<img src="' . (image_style_url('profile_medium', $user_picture_field['#items'][0]['uri'])) . '" class="" align=" "/>';
                }
                echo $user_pic;
                ?>

                <span id="section_profile-name-username"><?php echo realname_load($user)?></span>
            </div>

        </div>
    </div>
    <div class="col-md-3"  id="section_profile-actions">
        <?php echo _section_profile_get_profile_edit_btn($uid); ?>
        <?php if(module_exists('privatemsg_okl')):?>
            <?php echo privatemsg_okl_get_profile_btn(); ?>
        <?php endif?>
    </div>
</div>
 