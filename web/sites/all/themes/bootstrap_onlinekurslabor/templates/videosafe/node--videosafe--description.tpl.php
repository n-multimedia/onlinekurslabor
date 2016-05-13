<? /*
  foreach ($node->field_exclusive_access[LANGUAGE_NONE] as $exclusive_entry) {
  $persons_name = realname_load($exclusive_entry['entity']);
  $exclusive_persons[] = l($persons_name, drupal_get_path_alias('user/' . $exclusive_entry['entity']->uid));
  } */
$edit_button = '<li class="btn" id=""><a title="bearbeiten" href="/node/'.$node->nid.'/edit">bearbeiten</a></li>';
?>


<small><i><?= t('Created by'); ?> <?= realname_load(user_load($node->uid)); ?></i></small>
<br>
<?php
print render($content['body']);
if ($node->type == 'videosafe_video') {
    foreach (_videosafe_get_video_urls($node->nid) as $url) {
        $urls[] = '<li>' . $url . '</li>'; #'<li>' . file_create_url($file_entry['file']->uri) . '</li>';
    }

#echo '<div class="span6">';
//videoformater existiert noch nicht in GIT
    #   print render(file_view(file_load($node->field_video[LANGUAGE_NONE][0]['fid']),'file-media-9'));
    echo "@todo Videovorschau hier anzeigen;";
    #   echo '</div>';
    ?><div class="urls"><b>URLs:</b>
        <ul><?= implode('', $urls) ?></ul>
    </div><?
    $lehrtext_available = false;
    if (@$_SESSION['videosafe_prepoulate_domain']) {
        $chosen_lehrtext = $_SESSION['videosafe_prepoulate_domain'];
        foreach ($content['field_available_in']['#items'] as $available_field) {
            if ($available_field['target_id'] == $chosen_lehrtext) {
                $lehrtext_available = true;
                break;
            }
        }
        if ($lehrtext_available)
            print("<span class=\"label label-success\">OK</span><br>Video ist für den gewählten Lehrtext <i>" . node_load($chosen_lehrtext)->title . "</i> freigegeben");
        else
            print ("<span class=\"label label-warning\">Achtung</span><br>Nicht für den gewählten Lehrtext <i>" . node_load($chosen_lehrtext)->title . "</i> freigegeben!");
    }
    print render($content['field_available_in']);

    print render($content['field_exclusive_access']);
    print $edit_button;
} else if ($node->type == 'videosafe_folder') {
    ?>
<ul>
    <?=$edit_button?>
    <li class="btn" id=""><a title="Unterordner erstellen" href="/node/add/videosafe-folder?field_parent_folder=<?= $node->nid ?>">Unterordner erstellen</a></li>

    <li class="btn" id=""><a title="Video hochladen" href="/node/add/videosafe-video?field_parent_folder=<?= $node->nid ?>&field_available_in=<?= $_SESSION['videosafe_prepoulate_domain'] ?>">Video hochladen</a></li>
</ul>
<?
}