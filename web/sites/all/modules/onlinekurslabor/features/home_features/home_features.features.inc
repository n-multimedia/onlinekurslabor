<?php
/**
 * @file
 * home_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function home_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function home_features_image_default_styles() {
  $styles = array();

  // Exported image style: homescreen_course_header.
  $styles['homescreen_course_header'] = array(
    'label' => 'homescreen_course_header',
    'effects' => array(
      31 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 819,
          'height' => 140,
          'anchor' => 'left-top',
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: homescreen_profile.
  $styles['homescreen_profile'] = array(
    'label' => 'homescreen_profile',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 180,
          'height' => 180,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: homescreen_profile_background.
  $styles['homescreen_profile_background'] = array(
    'label' => 'homescreen_profile_background',
    'effects' => array(
      24 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 278,
          'height' => 278,
        ),
        'weight' => -9,
      ),
      25 => array(
        'name' => 'canvasactions_blur',
        'data' => array(
          'intensity' => 100,
        ),
        'weight' => 2,
      ),
      28 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 278,
          'height' => 180,
          'anchor' => 'center-center',
        ),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}
