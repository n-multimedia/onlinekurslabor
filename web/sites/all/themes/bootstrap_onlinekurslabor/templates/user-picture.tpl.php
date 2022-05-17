<?php
/* 
 * da im onlinekurslabor kein profilpicture hinterlegt ist, wird hier profile2 genutzt
 */

    $profile = profile2_load_by_user($account, 'master');
    if(!empty($profile->field_photo))
    {
      $image_path = $profile->field_photo[LANGUAGE_NONE][0]['uri']; 
    }
    else
    {
      $image_path = null;
    }
         print theme_image_style(
                array(     
                    'style_name' => 'thumbnail',
                    'path' =>   $image_path,
                    'attributes' => array(
                    'class' => 'avatar'
                    ),
                'width' => NULL,
                'height' => NULL,       
                )
            );  