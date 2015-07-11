<?php

/**
 * Implements hook_file_formatter_info().
 */
function oembed_file_formatter_info() {
  $formatters['oembed'] = array(
    'label' => t('oEmbed'),
    'default settings' => array('width' => '560', 'height' => '340', 'wmode' => ''),
    'view callback' => 'oembed_file_formatter_view',
    'settings callback' => 'oembed_file_formatter_oembed_settings',
    'description' => t('All-purpose oEmbed formatter.'),
  );
  $formatters['oembed_thumbnail'] = array(
    'label' => t('oEmbed thumbnail'),
    'default settings' => array('width' => '180', 'height' => ''),
    'view callback' => 'oembed_file_formatter_view',
    'settings callback' => 'oembed_file_formatter_oembed_thumbnail_settings',
    'description' => t('oEmbed thumbnail media.'),
  );
  return $formatters;
}

/**
 * Implements hook_file_formatter_info_alter().
 */
function oembed_file_formatter_info_alter(&$info) {
  if (isset($info['file_image'])) {
    $info['oembed_image'] = array(
      'label' => t('oEmbed image'),
      'view callback' => 'oembed_remote_file_formatter_view',
      'description' => t('oEmbed photo or thumbnail is saved to local filesystem and transformed by image styles.'),
    ) + $info['file_image'];
  }
}

/**
 * Implements hook_file_mimetype_mapping_alter().
 */
function oembed_file_mimetype_mapping_alter(&$mapping) {
  $mapping['mimetypes'][] = 'video/oembed';
  $mapping['mimetypes'][] = 'image/oembed';
  $mapping['mimetypes'][] = 'text/oembed';
  $mapping['mimetypes'][] = 'audio/oembed';
}

/**
 * Implements hook_file_operations().
 */
function oembed_file_operation_info() {
  $operations = array(
    'refresh' => array(
      'label' => t('Refresh from source'),
      'callback' => 'oembed_cache_clear',
    ),
  );
  return $operations;
}

/**
 * Implements hook_file_presave().
 */
function oembed_file_presave(stdClass $file) {

  // For new oEmbed files, set the filename to the oEmbed response's title or calculated
  // alt attribute.
  if (empty($file->fid) && isset($file->oembed)) {
    $embed = $file->oembed;
    $file->filename = truncate_utf8(empty($embed['title']) ? oembed_alt_attr($embed) : $embed['title'], 255);
  }
}

/**
 * Implements hook_file_load().
 */
function oembed_file_load($files) {
  foreach ($files as $file) {
    $scheme = file_uri_scheme($file->uri);
    if ($scheme == 'oembed') {

      // Load plain oEmbed response onto file entity.
      $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
      $file->oembed = oembed_get_data($wrapper->getExternalUrl());

      // Retrieve any missing images dimensions.
      oembed_image_dimensions($file);
    }
  }
}

/**
 * Implements hook_file_insert().
 */
function oembed_file_insert($file) {
  oembed_image_dimensions($file, TRUE);
}

/**
 * Implements hook_file_insert().
 */
function oembed_file_update($file) {
  oembed_image_dimensions($file, TRUE);
}

function oembed_image_dimensions($file, $force = FALSE) {

  $scheme = file_uri_scheme($file->uri);
  if ($scheme != 'oembed') {
    return;
  }

  // Do not bother proceeding if this file does not have an image mime type.
  if (strpos($file->filemime, 'image/') !== 0) {
    return;
  }

  // Return the existing $file->image_dimensions unless a reload is forced.
  if (!$force && isset($file->image_dimensions)) {
    return $file->image_dimensions;
  }

  // We have a non-empty image file.
  $embed = $file->oembed;
  if ($embed && $embed['type'] == 'photo' && !empty($embed['width']) && !empty($embed['height'])) {
    $file->image_dimensions = array(
      'width' => $embed['width'],
      'height' => $embed['height'],
    );
    db_merge('image_dimensions')
      ->key(array('fid' => $file->fid))
      ->fields(array(
        'width' => $file->image_dimensions['width'],
        'height' => $file->image_dimensions['height'],
      ))
      ->execute();
  }
  else {
    // Fallback to NULL values.
    $file->image_dimensions = array(
      'width' => NULL,
      'height' => NULL,
    );
  }
}
