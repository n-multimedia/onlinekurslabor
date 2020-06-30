<?php

/**
 * @file
 * nm_section_content_features.features.media_wysiwyg.inc
 */

/**
 * Implements hook_media_wysiwyg_defaults().
 */
function nm_section_content_features_media_wysiwyg_defaults() {
  $media_wysiwyg = array();

  // Restricted view modes for image files.
  $media_wysiwyg['image_wysiwyg_restrict_wysiwyg'] = FALSE;
  $media_wysiwyg['image_file_icon_restrict_wysiwyg'] = TRUE;

  // Restricted view modes for audio files.
  $media_wysiwyg['audio_wysiwyg_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['audio_file_icon_restrict_wysiwyg'] = TRUE;

  // Restricted view modes for document files.
  $media_wysiwyg['document_wysiwyg_restrict_wysiwyg'] = TRUE;
  $media_wysiwyg['document_file_icon_restrict_wysiwyg'] = TRUE;

  // Restricted view modes for application files.
  $media_wysiwyg['application_wysiwyg_restrict_wysiwyg'] = FALSE;

  return $media_wysiwyg;
}
