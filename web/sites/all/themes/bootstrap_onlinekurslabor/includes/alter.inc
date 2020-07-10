<?php


define('BootstrapCDNToLocal_ALTER_INCLUDED', TRUE);
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



/**
 * Implements hook_css_alter().
 */
function bootstrap_onlinekurslabor_css_alter(&$css) {
    if (!theme_get_setting('localizejsdelivr')) {
        return;
    }
    _bootstrap_onlinekurslabor_alter_assets($css);
}

/**
 * implements hook_js_alter(&$javascript) 
 * @param array $javascript
 */
function bootstrap_onlinekurslabor_js_alter(&$javascript) {
    
    if (!theme_get_setting('localizejsdelivr')) {
        return;
    }
    _bootstrap_onlinekurslabor_alter_assets($javascript);
}

/**
 * schiebt js/css-assets aufs CDN
 * @param type $assets
 */
function _bootstrap_onlinekurslabor_alter_assets(&$assets) {

 
    foreach ($assets as $index => $asset) {

        if (pathinfo($index, PATHINFO_EXTENSION)) {

            if (is_string($asset['data'])) {

                if (url_is_external($asset['data'])) {
                    $new_url = _bootstrap_onlinekurslabor_proxify_cdn_url($asset['data']);
                    unset($assets[$index]);
                    $asset['data'] = $new_url;
                    $assets[$new_url] = $asset;
                }
            }
        }
    }
}

function _bootstrap_onlinekurslabor_proxify_cdn_url($url) {
    //ersetze HOST durch $base/PFAD
    $base = BOOTSTRAPCDNTOLOCAL_FILESYSTEM_PATH; 
    $replcd = preg_replace('/https{0,1}:\/\/([a-zA-Z0-9\.-]*\/)/i', $base . '/$1', $url);
    $full_url = file_create_url($replcd);
    return $full_url;
}
