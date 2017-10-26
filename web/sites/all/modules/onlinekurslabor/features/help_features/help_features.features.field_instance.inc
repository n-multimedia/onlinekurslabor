<?php
/**
 * @file
 * help_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function help_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-book-field_navigation_icon'.
  $field_instances['node-book-field_navigation_icon'] = array(
    'bundle' => 'book',
    'deleted' => 0,
    'description' => 'Auf der Hauptseite eines Buchs (wie z.B. Hilfe) wird manchmal eine Navigation gerendert. Wenn diese Seite darin gelistet werden soll,benötigt sie ein Icon. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'nm_stream' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_navigation_icon',
    'label' => 'Navigations-Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'navigation_icons',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'feed' => 0,
          'http' => 0,
          'https' => 0,
          'oembed' => 0,
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'application' => 0,
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'domain_media--media_browser_1' => 0,
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'remote_file' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Auf der Hauptseite eines Buchs (wie z.B. Hilfe) wird manchmal eine Navigation gerendert. Wenn diese Seite darin gelistet werden soll,benötigt sie ein Icon. ');
  t('Navigations-Icon');

  return $field_instances;
}
