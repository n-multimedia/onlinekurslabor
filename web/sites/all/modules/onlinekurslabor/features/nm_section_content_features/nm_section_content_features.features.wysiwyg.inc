<?php

/**
 * @file
 * nm_section_content_features.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function nm_section_content_features_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html.
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'JustifyBlock' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Image' => 1,
          'Blockquote' => 1,
          'PasteFromWord' => 1,
          'RemoveFormat' => 1,
          'Styles' => 1,
          'Table' => 1,
        ),
        'custom_general_plugin' => array(
          'biblio_button' => 1,
        ),
        'footnotes' => array(
          'footnotes' => 1,
        ),
        'h5p_integration' => array(
          'h5p_button' => 1,
        ),
        'section_content_task_plugin' => array(
          'tasks_button' => 1,
        ),
        'drupal_path' => array(
          'Link' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'theme' => 'advanced',
      'language' => 'de',
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'theme',
      'css_theme' => '',
      'css_path' => '',
      'stylesSet' => '',
      'block_formats' => 'p,h2,h3,h4,h5,h6,div,address,pre',
      'forcePasteAsPlainText' => 0,
      'pasteFromWordPromptCleanup' => 0,
      'pasteFromWordRemoveFontStyles' => 1,
    ),
    'preferences' => array(
      'add_to_summaries' => FALSE,
      'default' => 1,
      'show_toggle' => 1,
      'user_choose' => 0,
      'version' => '4.12.1.64749bb245',
    ),
    'name' => 'formatfiltered_html',
    'rdf_mapping' => array(),
  );

  return $profiles;
}
