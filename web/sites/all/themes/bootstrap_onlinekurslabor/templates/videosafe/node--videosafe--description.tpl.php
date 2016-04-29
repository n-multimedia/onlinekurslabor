<?/*
foreach ($node->field_exclusive_access[LANGUAGE_NONE] as $exclusive_entry) {
    $persons_name = realname_load($exclusive_entry['entity']);
    $exclusive_persons[] = l($persons_name, drupal_get_path_alias('user/' . $exclusive_entry['entity']->uid));
}*/
foreach ($node->field_video[LANGUAGE_NONE] as $file_entry) {
    $urls[] = '<li>' . file_create_url($file_entry['file']->uri) . '</li>';
}
?>


<small><i><?= t('Created by'); ?> <?= realname_load(user_load($node->uid)); ?></i></small>
<br>
<?php
print render($content['body']);
if ($node->type == 'videosafe_video') {

    print render(file_view($node->field_video[LANGUAGE_NONE][0]['file']));
    ;
    ?><div class="urls"><b>URLs:</b>
        <?=  implode('', $urls) ?>
    </div><?
    print render($content['field_available_in']);
    print render($content['field_exclusive_access']);
} else if ($node->type == 'videosafe_folder') {
    ?>
    <a href="/node/add/videosafe-folder?field_parent_folder=<?=$node->nid ?>">Unterordner erstellen</a>
    <br>
    <a href="/node/add/videosafe-video?field_parent_folder=<?=$node->nid ?>&field_available_in=<?=$_SESSION['videosafe_prepoulate_domain']?>">Video hochladen</a><?
}