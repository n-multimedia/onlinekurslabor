<?php
/* 
 * da im onlinekurslabor kein profilpicture hinterlegt ist, wird hier profile2 genutzt
 */

    $profile = profile2_load_by_user($account, 'master');
         print theme_image_style(
                array(     
                    'style_name' => 'thumbnail',
                    'path' =>  $profile->field_photo[LANGUAGE_NONE][0]['uri'] ,
                    'attributes' => array(
                    'class' => 'avatar'
                    ),
                'width' => NULL,
                'height' => NULL,       
                )
            );  