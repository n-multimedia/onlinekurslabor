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

 
      print render(file_view(file_load($node->field_video[LANGUAGE_NONE][0]['fid']),'media_6'));
   
    ?><div class="urls"><b>URLs:</b>
        <ul><?= implode('', $urls) ?></ul>
    </div><?
      

    print render($content['field_exclusive_access']);
    
    echo "@todo show usage";
    echo "<br>";
    //todo fuer die FILE-URLS und dann distinct etc
    _videosafe_get_h5p_usage($urls[0]);
    print $edit_button;
} else if ($node->type == 'videosafe_folder') {
    ?>
<ul>
    <?=$edit_button?>
    <li class="btn" id=""><a title="Unterordner erstellen" href="/node/add/videosafe-folder?field_parent_folder=<?= $node->nid ?>">Unterordner erstellen</a></li>

    <li class="btn" id=""><a title="Video hochladen" href="/node/add/videosafe-video?field_parent_folder=<?= $node->nid ?>">Video hochladen</a></li>
</ul>
<?
}