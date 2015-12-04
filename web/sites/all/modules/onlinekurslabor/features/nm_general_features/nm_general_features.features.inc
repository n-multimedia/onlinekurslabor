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
    'name' => 'profile_main_thumbnail',
    'label' => 'profile_main_thumbnail',
    'effects' => array(
      2 => array(
        'label' => 'Skalieren und zuschneiden',
        'help' => 'Skalieren und zuschneiden wird das Seitenverhältnis des ursprünglichen Bildes erhalten, und dann die überstehenden Ränder entfernen. Dies ist besonders nützlich für die Erstellung von perfekt quadratischen Vorschaubildern ohne Verzerrung des Bildes.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'profile_mini_thumbnail',
    'label' => 'profile_mini_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Skalieren und zuschneiden',
        'help' => 'Skalieren und zuschneiden wird das Seitenverhältnis des ursprünglichen Bildes erhalten, und dann die überstehenden Ränder entfernen. Dies ist besonders nützlich für die Erstellung von perfekt quadratischen Vorschaubildern ohne Verzerrung des Bildes.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'profile_nano_thumbnail',
    'label' => 'profile_nano_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Skalieren und zuschneiden',
        'help' => 'Skalieren und zuschneiden wird das Seitenverhältnis des ursprünglichen Bildes erhalten, und dann die überstehenden Ränder entfernen. Dies ist besonders nützlich für die Erstellung von perfekt quadratischen Vorschaubildern ohne Verzerrung des Bildes.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 25,
          'height' => 25,
        ),
        'weight' => 1,
      ),
        
    2 => array(
      'label' => 'Rounded Corners',
      'help' => 'This is true cropping, not overlays, so the result <em>can</em> be transparent.',
      'effect callback' => 'canvasactions_roundedcorners_effect',
      'dimensions passthrough' => TRUE,
      'form callback' => 'canvasactions_roundedcorners_form',
      'summary theme' => 'canvasactions_roundedcorners_summary',
      'module' => 'imagecache_canvasactions',
      'name' => 'canvasactions_roundedcorners',
      'data' => array(
        'radius' => '12',
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
      'ieid' => '2',
      'isid' => '1',
      'weight' => '2',
    ),
    3 => array(
      'label' => 'Change file format',
      'help' => 'Choose to save the image as a different filetype.',
      'effect callback' => 'coloractions_convert_image',
      'dimensions passthrough' => TRUE,
      'form callback' => 'coloractions_convert_form',
      'summary theme' => 'coloractions_convert_summary',
      'module' => 'imagecache_coloractions',
      'name' => 'coloractions_convert',
      'data' => array(
        'format' => 'image/png',
        'quality' => '95',
      ),
      'ieid' => '3',
      'isid' => '1',
      'weight' => '3',
    )
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
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
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
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function nm_general_features_default_profile2_type() {
  $items = array();
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
