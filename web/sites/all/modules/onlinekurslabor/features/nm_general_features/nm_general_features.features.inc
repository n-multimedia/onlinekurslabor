<?php
/**
 * @file
 * nm_general_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nm_general_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nm_general_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nm_general_features_image_default_styles() {
  $styles = array();

  // Exported image style: profile_main_thumbnail.
  $styles['profile_main_thumbnail'] = array(
    'label' => 'profile_main_thumbnail',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_mini_thumbnail.
  $styles['profile_mini_thumbnail'] = array(
    'label' => 'profile_mini_thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 32,
          'height' => 32,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_nano_thumbnail.
  $styles['profile_nano_thumbnail'] = array(
    'label' => 'profile_nano_thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 25,
          'height' => 25,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'canvasactions_roundedcorners',
        'data' => array(
          'radius' => 12,
          'independent_corners_set' => array(
            'independent_corners' => 0,
            'radii' => array(
              'tl' => 0,
              'tr' => 0,
              'bl' => 0,
              'br' => 0,
            ),
          ),
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'coloractions_convert',
        'data' => array(
          'format' => 'image/png',
          'quality' => 95,
        ),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function nm_general_features_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Einfache Seite'),
      'base' => 'node_content',
      'description' => t('Benutzen Sie <em>Einfache Seiten</em> für statischen Inhalt, wie z.B. eine „Über uns“ Seite.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'plattform_log' => array(
      'name' => t('Plattform Log'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function nm_general_features_default_profile2_type() {
  $items = array();
  $items['data'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "data",
    "label" : "Data",
    "weight" : "0",
    "data" : {
      "registration" : 0,
      "roles" : {
        "30037204" : "30037204",
        "2" : "2",
        "197637936" : "197637936",
        "16675960" : "16675960",
        "106505419" : "106505419",
        "126456107" : "126456107",
        "66784200" : "66784200",
        "24708420" : "24708420",
        "140204299" : "140204299"
      }
    },
    "rdf_mapping" : []
  }');
  $items['master'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "master",
    "label" : "Master Data",
    "weight" : "0",
    "data" : { "registration" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
