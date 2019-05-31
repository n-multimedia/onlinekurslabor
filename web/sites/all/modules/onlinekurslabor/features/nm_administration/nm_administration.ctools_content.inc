<?php

/**
 * @file
 * nm_administration.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function nm_administration_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'administration_fieldset_addnew';
  $content->admin_title = 'administration-fieldset-addnew';
  $content->admin_description = 'Der Add-New-Bereich, der in manchen bereichen der moderator-verwaltungsoberfläche erscheint';
  $content->category = 'administration (Moderator)';
  $content->settings = array(
    'admin_title' => 'administration-fieldset-addnew',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
echo _section_administration_get_RenderedAddNewFieldset("%section:raw");
?>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $export['administration_fieldset_addnew'] = $content;

  return $export;
}
