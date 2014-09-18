<div class="single_activity  <?=$activity_unread?'unseen':'seen'?>">

    <div class="title">
        <div class="userimage"> <?= $user_image ?></div>
        <div class="activity_description">

            <b><?= l($user_realname, $user_path) ?></b>
            hat


            <?
            switch ($activity_type)
            {
                case NM_COURSE_FORUMTOPIC:
                    echo "ein Forenthema";
                    break;
                case NM_COURSE_DOCS:
                    echo "ein Kursdokument";
                    break;
                case NM_COURSE_GROUP:
                    echo "eine Kursgruppe";
                    break;
                case NM_COURSE_GENERIC_TASK:
                    echo"eine Aufgabe";
                    break;
                case NM_COURSE_GENERIC_TASK_SOLUTION:
                    echo "eine Lösung";
                    break;
                case NM_COURSE_NEWS:
                    echo "eine Ankündigung";
                    break;
            }
            ?>

            angelegt

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
 