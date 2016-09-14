<?php/**
 * Erstellt mehrere Varianten eines Videos mit sichtbar für kleine- bzw mittlere+ Bildschirmgrößen
 * siehe _custom_general_get_html5_video_tag()
**/
?>
<? foreach ($video_definition as $video_infos): ?>
    <div class="<?= $video_infos['bootstrap']['class'] ?>">
        <div class="<?= $video_infos['bootstrap']['hidden_class'] ?>">
            <video width="100%" controls="controls" poster="<?= $video_infos['poster'] ?>">
                <? foreach ($video_infos['videos'] as $video_info): ?>
                    <source src="<?= $video_info['url'] ?>" type="<?= $video_info['type'] ?>">
                <? endforeach ?>
                Your browser does not support the video tag.
            </video> 
        </div>
    </div>
<? endforeach ?>