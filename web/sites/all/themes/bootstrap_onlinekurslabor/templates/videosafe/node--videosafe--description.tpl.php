<?
/*
  foreach ($node->field_exclusive_access[LANGUAGE_NONE] as $exclusive_entry) {
  $persons_name = realname_load($exclusive_entry['entity']);
  $exclusive_persons[] = l($persons_name, drupal_get_path_alias('user/' . $exclusive_entry['entity']->uid));
  } */
if ($node->nid != _videosafe_get_root_directory()->nid)
    $node_edit_button = '<li class="btn btn-default" id=""><a title="bearbeiten" href="/node/' . $node->nid . '/edit">bearbeiten</a></li>';
else
    $node_edit_button = '';
if ($node->type == 'videosafe_video') {
    foreach (_videosafe_get_video_urls($node->nid) as $url) {
        $urls[] = '<li>' . $url . '</li>'; #'<li>' . file_create_url($file_entry['file']->uri) . '</li>';
    }

    /* errechnet den string, wo das video verwendet wird
     */
    $h5ps = _videosafe_get_usage($node);
    $h5p_refs = array();
    foreach ($h5ps as $h5p) {
        $h5p_refs = array_merge($h5p_refs, _videosafe_h5p_get_refs($h5p));
    }
    $h5p_refs = array_unique($h5p_refs, SORT_REGULAR);
    foreach ($h5p_refs as $h5p_ref) {
        $h5p_ref_strings[] = l($h5p_ref->title, 'node/' . $h5p_ref->nid);
    }
    foreach ($h5ps as $h5p) {
        $h5p_strings[] = l($h5p->title, 'node/' . $h5p->nid);
    }
    $video_referenced_in_string = ' - ohne - ';
    if (count($h5p_ref_strings))
        $video_referenced_in_string = ((count($h5p_strings)>1)?'den Texten: ':'dem Text: ') . implode(', ', $h5p_ref_strings);
    if (count($h5p_strings))
        $video_referenced_in_string .= ((count($h5p_strings)>1)?'<br>in den interaktiven Inhalten: ':'<br>im interaktiven Inhalt: ') . implode(', ', $h5p_strings);
}
?>

<small><? print render($content['body']); ?></small>
<small><i><?= t('Created by'); ?> <?= realname_load(user_load($node->uid)); ?></i></small>
<br>
<?php
if ($node->type == 'videosafe_video') {
    $content['field_exclusive_access']['#title']='Sperrvermerk, einsehbar für';
?>
    <div class="media-element-container media-media_6">
        <?print render(file_view(file_load($node->field_video[LANGUAGE_NONE][0]['fid']), 'media_6'));?>
    </div>
    <div class="urls"><b>URLs zum Kopieren:</b>
        <ul><?= implode('', $urls) ?></ul>
    </div>

    <? print render($content['field_exclusive_access']); ?>

    <br><b>Verwendung in </b><br>

    <?= $video_referenced_in_string; ?>
    <br><br>
    <?= $node_edit_button ?>
    <?
} else if ($node->type == 'videosafe_folder') {
    ?>
    <ul>
        <? echo $node_edit_button;?>
        <li class="btn btn-default" id=""><a title="Unterordner erstellen" href="/node/add/videosafe-folder?field_parent_folder=<?= $node->nid ?>">Unterordner erstellen</a></li>
        <?php if ($node->nid != _videosafe_get_root_directory()->nid): ?>
            <li class="btn btn-default" id=""><a title="Video hochladen" href="/node/add/videosafe-video?field_parent_folder=<?= $node->nid ?>">Video hochladen</a></li>
        <?php endif; ?>    
    </ul>
    <?
}