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

    $parameters = array(
        'active_trail' => array($parent['plid']),
        'expanded' => array($parent['mlid']),
        'only_active_trail' => true,
        'min_depth' => $parent['depth'] + 1,
        'max_depth' => $parent['depth'] + 1,
        'conditions' => array('plid' => $parent['mlid']),
    );
    $children = menu_build_tree($parent['menu_name'], $parameters);
    $menu_tree_render = menu_tree_output($children);
    $rendered_tree = drupal_render($menu_tree_render);
    //ich hab keine ahnung, was hier genau passiert ist, 
    //aber nun haben wir wieder die unterkapiteluebersicht unterhalb eines lehrtexts
    //die nummerierung fehlt noch, das hat mit der funktion book_preprocess(&$variables, $hook) { zu tun.
    $variables['tree'] = ($rendered_tree);
}
