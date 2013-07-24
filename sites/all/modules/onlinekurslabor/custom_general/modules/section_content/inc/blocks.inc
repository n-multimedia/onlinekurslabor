<?php

/**
 * Custom function to assemble renderable array for block content.
 * Returns a renderable array with the block content.
 * @return
 *   returns a renderable array of block content.
 */
function _section_content_node_tabs_view() {

  $block = "";
  if (section_content_authors_tools_access()) {
    $nav_items_single = array();
    $nav_items_single['overview'] = "Ansicht";
    $nav_items_single['course'] = "Bearbeiten";
    $nav_items_single['sub_chapter'] = "Unterkapitel hinzufügen";

    $single_links = array();

    /*
      $group = og_context();
      $group_get_id = isset($_GET['og_group_ref']) ? $_GET['og_group_ref'] : NULL;
      $group_id = $group ? $group['gid'] : $group_get_id;
      $group = node_load($group_id); */

    $group = _section_content_get_active_domain();

    foreach ($nav_items_single as $si) {
      $text_link = _section_content_navtext_to_link($group, $si);
      if ($si != $text_link) {
        $single_links[] = array('link' => $text_link);
      }
    }

    if (count($single_links) < 1)
      return array();

    $output_single = _custom_general_theme_tools_block($single_links, "content_node_tabs", "btn-group");

    // Block output in HTML with div wrapper
    $block = $output_single;
  }

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
    'attributes' => array(
      'class' => array('btn'),
    ),
    'query' => array(
      'og_group_ref' => $domain_nid,
      ));

  if ((arg(0) == 'domain') && (is_numeric(arg(2)))) {
    $node = node_load(arg(2));
  }

  //break if no node object found to operate on
  if (empty($node)) {
    return $result;
  }

  $node_nid = $node->nid;

  switch ($text) {
    case "Ansicht":
      $result = l($text, "domain/text/" . $node_nid, $options);
      break;
    case "Bearbeiten":
      $result = l($text, "domain/edit/" . $node_nid, $options);
      break;
    case "Unterkapitel hinzufügen":
      $mlid = isset($node->book) ? $node->book['mlid'] : 0;
      $options['query'] += array(
        'parent' => $mlid,
      );
      if ($mlid != 0) {
        $result = l($text, 'domain/add/' . $domain->nid . '/' . NM_CONTENT_CHAPTER, $options);
      }
      break;

    default:
  }

  return $result;
}

/**
 * Theme Authors's Tools Block 
 * 
 * @param type $variables
 * @return type
 */
function _section_content_theme_authors_tools($variables = NULL) {

  $output = "";

  if (section_content_authors_tools_access()) {

    $tool_links = _section_courses_get_authors_tools();

    //$output = '<div class="row-fluid">';
    $output = _custom_general_theme_tools_block($tool_links, "authors_tools", "btn-group btn-group-vertical", 1);
    //$output .= '</div">';
  }

  return $output;
}

function section_content_authors_tools_access() {
  global $user;
  $active_domain = _section_content_get_active_domain();
  if (!$active_domain) {
    return FALSE;
  }

  if (!og_is_member('node', $active_domain->nid)) {
    return FALSE;
  }

  $one_of_needed_roles = array_intersect($user->roles, array(NM_ROLE_ADMIN, NM_ROLE_AUTOR));

  return !empty($one_of_needed_roles);
}

/**
 * get link Items for Author's Tools Block
 * 
 * @global type $user
 * @return string
 */
function _section_courses_get_authors_tools() {
  global $user;

  $group_tmp = og_context();

  $group_get_id = isset($_GET['og_group_ref']) ? $_GET['og_group_ref'] : NULL;

  $group_id = !empty($group_tmp['gid']) ? $group_tmp['gid'] : $group_get_id;

  $group = node_load($group_id);

  if (!$group_id || $group->type != NM_COURSE) {
    $domain = _section_content_get_active_domain();

    if ($domain)
      $group_id = $domain->nid;
  }

  $default_options = array(
    'query' => array(
      'og_group_ref' => $group_id,
    ),
    'attributes' => array(
      'title' => '',
      ));

  $active_node = NULL;
  if (arg(0) == 'domain' && (arg(1) == 'text' || arg(1) == 'edit' || arg(1) == 'media' || arg(1) == 'biblio' || arg(1) == 'add') && is_numeric(arg(2))) {
    $active_node = node_load(arg(2));
    $mlid = isset($active_node->book) ? $active_node->book['mlid'] : NULL;
    $bid = isset($active_node->book) ? $active_node->book['bid'] : $group_id;
    $plid = isset($active_node->book) ? $active_node->book['plid'] : NULL;
    $plid = ($plid == 0 || $plid == NULL) ? $mlid : $plid;

    $add_chapter_options = $default_options;
    $add_chapter_options['query']['parent'] = $plid;

    //disable subchapter creatin, if mlid == plid
    if ($plid != $mlid) {
      $add_subchapter_options = $default_options;
      $add_subchapter_options['query']['parent'] = $mlid;
    }
  }
  else {
    
  }

  $links = array();

  $links['author_chapter_add']['label'] = "Kapitel";
  $links['author_subchapter_add']['label'] = "Unter-kapitel";

  $links['author_chapter_order']['label'] = "Reihenfolge";
  $links['author_biblio_overview']['label'] = "Biblio";
  $links['author_biblio_add']['label'] = "Biblio";

  $links['author_media_overview']['label'] = "Medien";
  $links['author_tasks_overview']['label'] = "Aufgaben";

  $links['author_tasks_mc_add']['label'] = "Multiple Choice";
  $links['author_tasks_qaa_add']['label'] = "Frage und Antwort";

  //Groups
  $links['author_chapter_add']['group']['gid'] = 1;
  $links['author_chapter_add']['group']['root'] = TRUE;
  $links['author_subchapter_add']['group']['gid'] = 1;

  $links['author_chapter_order']['group']['gid'] = 2;
  $links['author_chapter_order']['group']['root'] = TRUE;
  //$links['instr_add_news']['group']['gid'] = 2;
  //$links['instr_add_docs']['group']['gid'] = 2;

  $links['author_biblio_overview']['group']['gid'] = 3;
  $links['author_biblio_overview']['group']['root'] = TRUE;
  $links['author_biblio_add']['group']['gid'] = 3;

  $links['author_media_overview']['group']['gid'] = 4;
  $links['author_media_overview']['group']['root'] = TRUE;

  $links['author_tasks_overview']['group']['gid'] = 5;
  $links['author_tasks_overview']['group']['root'] = TRUE;
  $links['author_tasks_mc_add']['group']['gid'] = 5;
  $links['author_tasks_qaa_add']['group']['gid'] = 5;

  /*
    $groups = array();
    $groups[1] = array();
    $groups[1][] = $links['instr_overview_members'];
    $groups[1][] = $links['instr_add_members'];
    $groups[2] = array();
    $groups[2][] = $links['instr_overview_groups'];
    $groups[2][] = $links['instr_add_groups'];
    $groups[3] = array();
    $groups[3][] = $links['instr_overview_forums'];
    $groups[4] = array();
    $groups[4][] = $links['instr_course_settings']; */


  //$links['instr_course_settings2'] = "Kurseinstellungen";
  //$links['instr_course_settings3'] = "Kurseinstellungen";
  //$links['instr_course_settings4'] = "Kurseinstellungen";
  //$links['instr_course_settings5'] = "Kurseinstellungen";

  /*
    $links['instr_view_members'] = "Teilnehmer";
    $links['instr_view_groups'] = "Kursgruppen";' */

  if (og_is_member('node', $group_id)) {


    $id = 'author_chapter_add';
    $label = $links[$id]['label'];
    if (!empty($add_chapter_options)) {
      $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_CHAPTER;
      $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $add_chapter_options);
    }
    else {
      $links[$id] += _custom_general_get_structered_tool_link($id, $label, "/", array('attributes' => array('class' => array('disabled'))));
    }

    $id = 'author_subchapter_add';
    $label = $links[$id]['label'];
    if (!empty($add_subchapter_options)) {
      $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_CHAPTER;
      $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $add_subchapter_options);
    }
    else {
      $links[$id] += _custom_general_get_structered_tool_link($id, $label, "/", array('attributes' => array('class' => array('disabled'))));
    }

    $path = 'admin/content/book/' . $group_id;
    $id = 'author_chapter_order';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'domain/biblio/' . $group_id;
    $id = 'author_biblio_overview';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'domain/add/' . $group_id . '/' . NM_BIBLIO;
    $id = 'author_biblio_add';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);


    $path = 'domain/media/' . $group_id;
    $id = 'author_media_overview';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'domain/tasks/' . $group_id;
    $id = 'author_tasks_overview';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_MULTIPLE_CHOICE;
    $id = 'author_tasks_mc_add';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_QUESTION_AND_ANSWER;
    $id = 'author_tasks_qaa_add';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);
  }

  $result = array();
  foreach ($links as $name => $link) {
    $attributes = array('attributes' => array('id' => $name, 'class' => array('btn')));
    if (isset($link['path']))
      custom_general_addpend_active_class(($link['path']), $attributes);

    $group = isset($link['group']) ? $link['group'] : NULL;
    $link = isset($link['link']) ? $link['link'] : NULL;
    $result[] = array('link' => $link, 'group' => $group, 'attributes' => $attributes['attributes']);
  }


  return $result;
}