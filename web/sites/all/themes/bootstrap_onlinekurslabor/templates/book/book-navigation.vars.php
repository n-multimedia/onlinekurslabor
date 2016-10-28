<?php

/**
 * @file
 * Stub file for "book_navigation" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "book_navigation" theme hook.
 *
 * See template for list of available variables.
 *
 * @see book-navigation.tpl.php
 *
 * @ingroup theme_preprocess
 */
function bootstrap_onlinekurslabor_preprocess_book_navigation(&$variables) {

    $path = $variables['book_link']['link_path']; #bspw node/4291/;
    $parent = menu_link_get_preferred($path);

    $configuration = array(
        "menu_name" => $parent["menu_name"],
        "parent_mlid" => $parent["mlid"],
    );

    $tree = menu_tree_build($configuration);

    $tree['subject_array'] = array();
    $variables['tree'] = drupal_render($tree);

}
