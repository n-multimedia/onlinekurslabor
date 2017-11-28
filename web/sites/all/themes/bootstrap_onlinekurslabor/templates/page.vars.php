<?php
/**
 * @file
 * Stub file for "page" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_preprocess
*/
function bootstrap_onlinekurslabor_preprocess_page(&$variables) {
    //nur ein kleiner teil der bootstrap-config. fuer alle optionen siehe original-file
    $variables['navbar_classes_array'] = array('navbar');
    if (bootstrap_setting('navbar_inverse')) {
        $variables['navbar_classes_array'][] = 'navbar-inverse';
    } else {
        $variables['navbar_classes_array'][] = 'navbar-default';
    }
}

/**
 * Processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_process
 */
function bootstrap_onlinekurslabor_process_page(&$variables) {
  $variables['navbar_classes'] = implode(' ', $variables['navbar_classes_array']);
}
