<?php

/**
 * @file
 * nm_administration.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nm_administration_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-administration.
  $menus['menu-administration'] = array(
    'menu_name' => 'menu-administration',
    'title' => 'Administration',
    'description' => 'Onlinekurslabor Administration',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Administration');
  t('Onlinekurslabor Administration');

  return $menus;
}
