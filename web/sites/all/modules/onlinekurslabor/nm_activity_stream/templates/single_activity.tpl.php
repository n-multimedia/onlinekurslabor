<div class="single_activity  <?=$activity_unread?'unseen':'seen'?>">

    <div class="title">
        <div class="userimage"> <?= $user_image ?></div>
        <div class="activity_description">

            <b><?= l($user_realname, $user_path) ?></b>
            <?echo ($activity_action);?>

            <div class="time seen_hidden">
                <a href="javascript:return false;" title="<?= date("d.m.Y H:i:s", $activity_timestamp_create); ?>">
                    <?= format_interval(time() - $activity_timestamp_create) ?>
                </a>
            </div>
        </div>
    </div>
    <div style="clear:both;"></div>

    <div class="detail seen_hidden">
        <?= l($activity_title, $activity_path) ?>
    </div>
</div>

