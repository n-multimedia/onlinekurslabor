<?php

/**
 * 08.09.2013 - 14:23 - SN
 * remove fieldset from date fields
 * @param type $variables
 * @return type
 */
function bootstrap_onlinekurslabor_combo($variables) {
  return theme('form_element', $variables);
}

function bootstrap_onlinekurslabor_date_combo($variables) {
  $element = $variables['element'];
  $field = field_info_field($element['#field_name']);
  $instance = field_info_instance($element['#entity_type'], $element['#field_name'], $element['#bundle']);

  // Group start/end items together in fieldset.
  /* $fieldset = array(
    '#title' => t($element['#title']) . ' ' . ($element['#delta'] > 0 ? intval($element['#delta'] + 1) : ''),
    '#value' => '',
    '#description' => !empty($element['#fieldset_description']) ? $element['#fieldset_description'] : '',
    '#attributes' => array(),
    '#children' => $element['#children'],
    ); */

  $output = '<label for="' . $element["#id"] . '" class="control-label">' . $element['#title'] . '</label>';
  $output .= $element['#children'];
  return $output;
}

function bootstrap_onlinekurslabor_mark($variables) {
  $output = "";
  switch ($variables['type']) {
    case 1:
      $output = ' <span class="badge badge-important">' . t('new') . '</span>';
      break;
    case 2:
      $output = ' <span class="badge badge-important">' . t('updated') . '</span>';
      break;
  }


  return $output;
}

/**
 * Returns HTML for an image using a specific image style.
 *
 * @param $variables
 *   An associative array containing:
 *   - style_name: The name of the style to be used to alter the original image.
 *   - path: The path of the image file relative to the Drupal files directory.
 *     This function does not work with images outside the files directory nor
 *     with remotely hosted images. This should be in a format such as
 *     'images/image.jpg', or using a stream wrapper such as
 *     'public://images/image.jpg'.
 *   - width: The width of the source image (if known).
 *   - height: The height of the source image (if known).
 *   - alt: The alternative text for text-based browsers.
 *   - title: The title text is displayed when the image is hovered in some
 *     popular browsers.
 *   - attributes: Associative array of attributes to be placed in the img tag.
 *
 * @ingroup themeable
 */
function bootstrap_onlinekurslabor_image_style($variables) {
  // Determine the dimensions of the styled image.
  $dimensions = array(
    'width' => $variables['width'],
    'height' => $variables['height'],
  );

  image_style_transform_dimensions($variables['style_name'], $dimensions);

  $variables['width'] = $dimensions['width'];
  $variables['height'] = $dimensions['height'];

  //29.07.2013 - 16:37 - SN
  if (stristr($variables['style_name'], 'media_')) {
    $num = str_replace('media_', '', $variables['style_name']);
    if (is_numeric($num)) {
      if (isset($variables['attributes']['class'])) {
        $variables['attributes']['class'][] = 'span' . $num;
      }
      else {
        $variables['attributes']['class'] = array('span' . str_replace('media_', '', $variables['style_name']));
      }
    }
  }

  // Determine the URL for the styled image.
  $variables['path'] = image_style_url($variables['style_name'], $variables['path']);
  return theme('image', $variables);
}

/**
 * @file template.php
 */
function bootstrap_onlinekurslabor_panels_flexible($vars) {
  global $user;

  $css_id = $vars['css_id'];
  $content = $vars['content'];
  $settings = $vars['settings'];
  $display = $vars['display'];
  $layout = $vars['layout'];
  $handler = $vars['renderer'];

  $layout_temp = $layout;

  //needed for course text section
  //span3span8span1 layout contains a row wich is used to display admin tools
  //normal users do'n have to see it,so it gets hided here
  //in case we don't need the last 1-span row, we swtich from span3span8span1 tp span4span8 layout
  //dpm($content);
  //3-8-1 Layouts wich need to be switched
  if ((!section_courses_instructors_tools_access() && !section_content_authors_tools_access()) && $layout['name'] == 'flexible:span3span8span1') {
    //override here
    $layout = panels_get_layout('flexible:span4span8');
    $content['navigation'] = $content['outline'];
    //dpm($layout_temp['layout']->settings['items']['outline']);
    //$layout['layout']->settings['items']['outline'] = $layout_temp['layout']->settings['items']['outline'];
    //dpm($layout['layout']->settings['items']);
    //need check if task section is active
    //change layout for feedback stage
  }
  else if ((!section_courses_instructors_tools_access() && !section_content_authors_tools_access()) && $layout['name'] == 'flexible:span11span1') {
    $layout = panels_get_layout('flexible:span12');
    //$content['test'] = $content['center'];
  }
  else if ($layout['name'] == 'flexible:span8span4') {
    if (arg(1) == 'tasks' && arg(4) == 'solution') {
      //get active task
      $task_nid = is_numeric(arg(3)) ? arg(3) : 0;
      if ($task_nid) {
        $solutions = custom_general_get_task_solutions($task_nid, $user->uid);
        if (count($solutions) > 0) {
          $solution = current($solutions);
          $current_state = workflow_node_current_state($solution);
          if ($current_state >= NM_COURSES_TASK_WORKFLOW_SUBMITTED) {
            $content['left'] = $content['news'];
            $content['center'] = $content['tools'];
            $layout = panels_get_layout('flexible:span6span6');
          }
        }
      }
    }
  }

  panels_flexible_convert_settings($settings, $layout);


  $renderer = panels_flexible_create_renderer(FALSE, $css_id, $content, $settings, $display, $layout, $handler);


  // CSS must be generated because it reports back left/middle/right
  // positions.
  $css = panels_flexible_render_css($renderer);

  if (!empty($renderer->css_cache_name) && empty($display->editing_layout)) {
    ctools_include('css');
    // Generate an id based upon rows + columns:
    $filename = ctools_css_retrieve($renderer->css_cache_name);
    if (!$filename) {
      $filename = ctools_css_store($renderer->css_cache_name, $css, FALSE);
    }

    // Give the CSS to the renderer to put where it wants.
    if ($handler) {
      $handler->add_css($filename, 'module', 'all', FALSE);
    }
    else {
      drupal_add_css($filename);
    }
  }
  else {
    // If the id is 'new' we can't reliably cache the CSS in the filesystem
    // because the display does not truly exist, so we'll stick it in the
    // head tag. We also do this if we've been told we're in the layout
    // editor so that it always gets fresh CSS.
    drupal_add_css($css, array('type' => 'inline', 'preprocess' => FALSE));
  }

  // Also store the CSS on the display in case the live preview or something
  // needs it
  $display->add_css = $css;

  $output = "<div class=\"panel-flexible " . $renderer->base['canvas'] . " clearfix\" $renderer->id_str>\n";
  $output .= "<div class=\"panel-flexible-inside " . $renderer->base['canvas'] . "-inside\">\n";

  $output .= panels_flexible_render_items($renderer, $settings['items']['canvas']['children'], $renderer->base['canvas']);

  // Wrap the whole thing up nice and snug
  $output .= "</div>\n</div>\n";

  return $output;
}

function bootstrap_onlinekurslabor_menu_tree(&$variables) {
  return '<ul class="menu nav nav-list">' . $variables['tree'] . '</ul>';
}

function bootstrap_onlinekurslabor_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {

    // Prevent dropdown functions from being added to management menu as to not affect navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    else {
      // Add our own wrapper
      unset($element['#below']['#theme_wrappers']);
      //$sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $sub_menu = '<ul class="nav nav-list">' . drupal_render($element['#below']) . '</ul>';
      //$element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      //$element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
      // Check if this element is nested within another
      if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
        // Generate as dropdown submenu
        //$element['#attributes']['class'][] = 'dropdown-submenu';
        //$element['#localized_options']['html'] = TRUE;
        //$element['#title'] .= '<i class="icon-chevron-right"></i>';
      }
      else {
        // Generate as standard dropdown
        //$element['#attributes']['class'][] = 'dropdown';
        $element['#localized_options']['html'] = TRUE;
        //$element['#title'] .= ' <span class="caret"></span>';
        //$element['#title'] .= '<i class="icon-chevron-right"></i>';
      }

      // Set dropdown trigger element to # to prevent inadvertant page loading with submenu click
      $element['#localized_options']['attributes']['data-target'] = '#';
    }
  }
  // Issue #1896674 - On primary navigation menu, class 'active' is not set on active menu item.
  // @see http://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']) || $element['#localized_options']['language']->language == $language_url->language)) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function bootstrap_onlinekurslabor_theme(&$existing, $type, $theme, $path) {
  // If we are auto-rebuilding the theme registry, warn about the feature.
  return array(
    'nm_fancy_box' => array(
      'variables' => array(
        'image' => NULL,
        'description' => NULL,
        'middle' => NULL,
        'bottom' => NULL
      ),
      'template' => 'nm_fancy_box',
      'path' => drupal_get_path('theme', 'bootstrap_onlinekurslabor') . '/templates/onlinekurslabor'
    ),
    'nm_course_list_item' => array(
      'variables' => array(
        'image' => NULL,
        'title' => NULL,
        'description' => NULL,
      ),
      'template' => 'nm_course_list_item',
      'path' => drupal_get_path('theme', 'bootstrap_onlinekurslabor') . '/templates/onlinekurslabor'
    )
  );
}

function bootstrap_onlinekurslabor_preprocess_html(&$vars) {
  if (drupal_is_front_page()) {
    $vars['classes_array'][] = 'okl-home-container';
  }
}
