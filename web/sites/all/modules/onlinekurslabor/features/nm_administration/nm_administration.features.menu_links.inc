<?php
/**
 * @file
 * nm_administration.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nm_administration_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-administration_dashboard:administration.
  $menu_links['menu-administration_dashboard:administration'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'administration',
    'router_path' => 'administration',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_dashboard:administration',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-administration_inhalt:administration/content.
  $menu_links['menu-administration_inhalt:administration/content'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'administration/content',
    'router_path' => 'administration',
    'link_title' => 'Inhalt',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_inhalt:administration/content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-administration_kurse:administration/courses.
  $menu_links['menu-administration_kurse:administration/courses'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'administration/courses',
    'router_path' => 'administration',
    'link_title' => 'Kurse',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_kurse:administration/courses',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-administration_semester:administration/semester.
  $menu_links['menu-administration_semester:administration/semester'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'administration/semester',
    'router_path' => 'administration',
    'link_title' => 'Semester',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-administration_semester:administration/semester',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard');
  t('Inhalt');
  t('Kurse');
  t('Semester');

  return $menu_links;
}
