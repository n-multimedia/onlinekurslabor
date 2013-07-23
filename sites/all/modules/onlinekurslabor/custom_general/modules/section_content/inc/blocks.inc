<?php

/**
 * Custom function to assemble renderable array for block content.
 * Returns a renderable array with the block content.
 * @return
 *   returns a renderable array of block content.
 */
function _section_content_node_tabs_view() {

  $nav_items_single = array();
  $nav_items_single['overview'] = "Ansicht";
  $nav_items_single['course'] = "Bearbeiten";
  $nav_items_single['sub_chapter'] = "Unterkapitel hinzufügen";

  $single_links = array();

  $group = og_context();
  $group_get_id = isset($_GET['og_group_ref']) ? $_GET['og_group_ref'] : NULL;
  $group_id = $group ? $group['gid'] : $group_get_id;
  $group = node_load($group_id);

  foreach ($nav_items_single as $si) {
    $text_link = _section_content_navtext_to_link($group, $si);
    if ($si != $text_link) {
      $single_links[] = array('link' => $text_link);
    }
  }

  if (count($single_links) < 1)
    return array();

  $output_single = _custom_general_theme_tools_block($single_links, "content_top_tabs");



  // Block output in HTML with div wrapper
  $block = array(
    'prefix' => array(
      '#prefix' => '<div id="course_top_navigation">',
      '#type' => 'markup',
      '#markup' => "",
    ),
    'single' => array(
      '#prefix' => '<div id="section_content_tools">',
      '#type' => 'markup',
      '#markup' => $output_single,
      '#suffix' => '</div>',
    ),
    'suffix' => array(
      '#type' => 'markup',
      '#markup' => "",
      '#suffix' => '</div>',
    ),
  );


  return $block;
}

function _section_content_navtext_to_link($domain, $text) {
  global $user;
  $result = $text;

  //break if domain argument is not set
  if (empty($domain)) {
    return $result;
  }

  $domain_nid = $domain->nid;

  $options = array(
    'attributes' => array(),
    'query' => array(
      'og_group_ref' => $domain_nid,
      ));

  $node = menu_get_object();

  //break if no node object found to operate on
  if (empty($node)) {
    return $result;
  }
  
  $node_nid = $node->nid;

  switch ($text) {
    case "Ansicht":
      $result = l($text, "node/" . $node_nid, $options);
      break;
    case "Bearbeiten":
      $result = l($text, "node/" . $node_nid . "/edit", $options);
      break;
    case "Unterkapitel hinzufügen":
      $mlid = isset($node->book) ? $node->book['mlid'] : 0;
      $options['query'] += array(
        'parent' => $mlid,
      );
      if ($mlid != 0) {
        $result = l($text, "node/add/content-chapter", $options);
      }
      break;

    default:
  }

  return $result;
}