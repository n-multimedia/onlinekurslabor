<?php

/**
 * @file
 * nm_general_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nm_general_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer_datenschutzerklrung:https://www.uni-augsburg.de/datenschutz.html.
  $menu_links['menu-footer_datenschutzerklrung:https://www.uni-augsburg.de/datenschutz.html'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'https://www.uni-augsburg.de/datenschutz.html',
    'router_path' => '',
    'link_title' => 'Datenschutzerklärung',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_datenschutzerklrung:https://www.uni-augsburg.de/datenschutz.html',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Datenschutzerklärung');

  return $menu_links;
}
