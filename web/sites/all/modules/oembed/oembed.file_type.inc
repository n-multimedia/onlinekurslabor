<?php

/**
 * Implements hook_file_default_types_alter().
 */
function oembed_file_default_types_alter(&$types) {
  //das wird 2x aufgerufen: 1x mit normal [image, video, etc] und dann einmal mit [application] und das raucht dann bei php8
  if (!empty($types['image'])) {
    $types['image']->mimetypes[] = 'image/oembed';
    $types['image']->streams[] = 'oembed';
  }
  if (!empty($types['video'])) {
    $types['video']->mimetypes[] = 'video/oembed';
    $types['video']->streams[] = 'oembed';
  }

  if (!empty($types['document'])) {
    $types['document']->mimetypes[] = 'text/oembed';
    $types['document']->streams[] = 'oembed';
  } 

  if (!empty($types['audio'])) {
    $types['audio']->mimetypes[] = 'audio/oembed';
    $types['audio']->streams[] = 'oembed';
  }
}
