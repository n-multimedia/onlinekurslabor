<?php
/*
 * Tabelle mit User-Details im Profil
 */
$user = user_load($uid);
?>
 
<div class="row" >
    <div class="col-md-12"  id="section_profile-detailinfos">


        <table width="100%;">
            <? foreach (_section_profile_get_profile_data($user) as $title => $info): ?>
                <tr>
                    <td width="35%;" valign="top">
                        <?= $title ?>
                    </td>
                    <td width="65%;"   align="right">
                        <?= $info ?>
                    </td>
                </tr>
            <? endforeach; ?>

        </table>
    </div>
</div>