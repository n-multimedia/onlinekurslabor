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
    //$nav_items_single['sub_chapter'] = "Unterkapitel hinzufügen";
    $nav_items_single['revisions'] = "Versionen";

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
  $optional_group = null;
  $result = $text;

  //break if domain argument is not set
  if (empty($domain)) {
    return $result;
  }

  $domain_nid = $domain->nid;

  $options = array(
    'attributes' => array(
      'class' => array('btn','btn-default'),
    ),
    'query' => array(
      'og_group_ref' => $domain_nid,
  ));

  //optionale group domain/text/3/1152/
  if ((arg(0) == 'domain') && (is_numeric(arg(3)))) {
    $node = node_load(arg(3));
    $optional_group =  node_load(arg(2));
  }
  //normalmodus domain/text/3
 elseif ((arg(0) == 'domain') && (is_numeric(arg(2)))) {
    $node = node_load(arg(2));
  }




  //break if no node object found to operate on
  if (empty($node)) {
    return $result;
  }

  $node_nid = $node->nid;

  switch ($text) {
    case "Ansicht":
      $result = l($text, "domain/text/".($optional_group?$optional_group->nid.'/':'') . $node_nid, $options);
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
    case "Versionen":
      $result = l($text, "domain/text/" . $node_nid . '/revisions', $options);
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
  return $output;

  if (section_content_authors_tools_access()) {

    $tool_links = _section_courses_get_authors_tools();

    //$output = '<div class="row">';
    $output = _custom_general_theme_tools_block($tool_links, "authors_tools", "btn-group btn-group-vertical", 1);
    //$output .= '</div">';
  }

  return $output;
}

/**
 * used for block "content_text_outline"
 * @param type $vars
 */
function _section_content_block_text_outline($vars = NULL)
{
    /**
     * functions in COURSE are slightly different :((
     */
    if(  _section_courses_get_active_course())
    {
        return section_courses_text_outline();
    }
    else
    {
        return section_content_text_outline();
    }
    
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

    if ($domain) {
      $group_id = $domain->nid;
    }
  }

  $default_options = [
    'query' => [
      'og_group_ref' => $group_id,
    ],
    'attributes' => [
      'title' => '',
    ],
  ];

  $active_node = NULL;
  $subchapter_disabled = FALSE;
  //wenn man in /domain ist und im unterbereich text,edit, übersicht media etc lade den aktuellen node
  if (arg(0) == 'domain' && (arg(1) == 'text' || arg(1) == 'edit' || arg(1) == 'media' || arg(1) == 'biblio' ||arg(1) == 'members' || arg(1) == 'h5p' || arg(1) == 'tasks' || arg(1) == 'add') && is_numeric(arg(2))) {
    $active_node = node_load(arg(2));
    if (isset($active_node->type) && in_array($active_node->type, [
        NM_CONTENT_MULTIPLE_CHOICE,
        NM_CONTENT_QUESTION_AND_ANSWER,
        NM_INTERACTIVE_CONTENT,
      ])) {   //falls kein kapitel sondern domain-content, versuche hauptgroup zu laden
      $an_group_nid = @($active_node->og_group_ref[LANGUAGE_NONE][0]['target_id']);
      if ($an_group_nid) {
        $active_node = node_load($an_group_nid);
      }
    }

    $mlid = isset($active_node->book) ? $active_node->book['mlid'] : NULL;
    $bid = isset($active_node->book) ? $active_node->book['bid'] : $group_id;
    $plid = isset($active_node->book) ? $active_node->book['plid'] : NULL;
    $plid = ($plid == 0 || $plid == NULL) ? $mlid : $plid;

    $add_chapter_options = NULL;
    //wenn parent gefunden, um kapitel einzusortieren (sonst würds im nirvana landen)
    if ($plid) {
      $add_chapter_options = $default_options;
      $add_chapter_options['query']['parent'] = $plid;
    }

    //disable subchapter creation, if mlid == plid
    $subchapter_disabled = FALSE;
    if ($plid != $mlid) {
      $add_subchapter_options = $default_options;
      $add_subchapter_options['query']['parent'] = $mlid;
    }
    else {
      $subchapter_disabled = TRUE;
    }
  }

  //plid, mlid nicht kalkulierbar => subchapter abschalten
  else {
    $subchapter_disabled = TRUE;
  }


  $links = [];

  $links['author_category_chapter']['label'] = "Kapitel";
  $links['author_category_chapter']['label_long'] = "Kapitel";
  $links['author_chapter_add']['label'] = "Kapitel";
  $links['author_chapter_add']['label_long'] = "Kapitel hinzufügen";
  $links['author_subchapter_add']['label'] = "Unter-kapitel";
  $links['author_subchapter_add']['label_long'] = "Unterkapitel hinzufügen";
  $links['author_chapter_order']['label'] = "Reihenfolge";
  $links['author_chapter_order']['label_long'] = "Reihenfolge ändern";

  $links['author_category_biblio']['label'] = "Biblio";
  $links['author_category_biblio']['label_long'] = "Biblio";
  $links['author_biblio_add']['label'] = "Biblio";
  $links['author_biblio_add']['label_long'] = "Biblio hinzufügen";
  $links['author_biblio_overview']['label'] = "Biblio";
  $links['author_biblio_overview']['label_long'] = "Biblio verwalten";


  $links['author_category_interactive']['label'] = "Interaktiv";
  $links['author_category_interactive']['label_long'] = "Interaktive Inhalte";
  $links['author_h5p_add']['label'] = "H5P";
  $links['author_h5p_add']['label_long'] = "H5P hinzufügen";
  if (module_exists('annvid')) {
    $links['author_annvid_add']['label'] = "AnnVid";
    $links['author_annvid_add']['label_long'] = "AnnVid hinzufügen";
  }
  $links['author_interactive_overview']['label'] = "Interaktiv";
  $links['author_interactive_overview']['label_long'] = "Interaktive Inhalte verwalten";

  $links['author_category_tasks']['label'] = "Aufgaben";
  $links['author_category_tasks']['label_long'] = "Aufgaben";
  $links['author_tasks_mc_add']['label'] = "Multiple Choice";
  $links['author_tasks_mc_add']['label_long'] = "Multiple Choice hinzufügen";
  $links['author_tasks_qaa_add']['label'] = "Frage und Antwort";
  $links['author_tasks_qaa_add']['label_long'] = "Frage und Antwort hinzufügen";

  $links['author_tasks_overview']['label'] = "Aufgaben";
  $links['author_tasks_overview']['label_long'] = "Aufgaben verwalten";

  $links['author_category_config']['label'] = "Lehrtext";
  $links['author_category_config']['label_long'] = "Lehrtextkonfiguration";
  
  $links['auth_domain_stats']['label'] = "LT-Stat";
  $links['auth_domain_stats']['label_long'] = "Statistik & Info";
  
  $links['auth_domain_members']['label'] = "Mitglieder";
  $links['auth_domain_members']['label_long'] = "Mitglieder verwalten";
  
  $links['auth_domain_settings']['label'] = "Lehrtext";
  $links['auth_domain_settings']['label_long'] = "Lehrtexteinstellungen";

  
  //Groups
  $links['author_category_chapter']['group']['gid'] = 1;
  $links['author_category_chapter']['group']['root'] = TRUE;
  $links['author_chapter_add']['group']['gid'] = 1;
  $links['author_subchapter_add']['group']['gid'] = 1;
  $links['author_chapter_order']['group']['gid'] = 1;

  $links['author_category_biblio']['group']['gid'] = 3;
  $links['author_category_biblio']['group']['root'] = TRUE;
  $links['author_biblio_add']['group']['gid'] = 3;
  $links['author_biblio_overview']['group']['gid'] = 3;

  $links['author_category_tasks']['group']['gid'] = 4;
  $links['author_category_tasks']['group']['root'] = TRUE;
  $links['author_tasks_mc_add']['group']['gid'] = 4;
  $links['author_tasks_qaa_add']['group']['gid'] = 4;
  $links['author_tasks_overview']['group']['gid'] = 4;

  $links['author_category_interactive']['group']['gid'] = 5;
  $links['author_category_interactive']['group']['root'] = TRUE;
  $links['author_interactive_overview']['group']['gid'] = 5;
  $links['author_h5p_add']['group']['gid'] = 5;
  if (module_exists('annvid')) {
    $links['author_annvid_add']['group']['gid'] = 5;
  }

  $links['author_category_config']['group']['gid'] = 6;
  $links['author_category_config']['group']['root'] = TRUE;
  $links['auth_domain_stats']['group']['gid'] = 6;
  $links['auth_domain_members']['group']['gid'] = 6;
  $links['auth_domain_settings']['group']['gid'] = 6;


  $path = 'domain/text/' . $group_id . '/rearrange';
  $id = 'author_category_chapter';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $id = 'author_chapter_add';
  if (!empty($add_chapter_options)) {
    $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_CHAPTER;
    $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $add_chapter_options);
  }
  else {
    $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], "/", ['attributes' => ['class' => ['disabled']]]);
  }


  $id = 'author_subchapter_add';
  if (!$subchapter_disabled) {
    $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_CHAPTER;
    $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $add_subchapter_options);
  }
  else {
    unset($links[$id]);
  }


  $path = 'domain/text/' . $group_id . '/rearrange';
  $id = 'author_chapter_order';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'domain/biblio/' . $group_id;
  $id = 'author_category_biblio';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);


  $biblio_options = $default_options;
  //überschreibe default og-group-ref-query auf aktuelle node
  $biblio_options['query'] = ['return_to' => $active_node->nid];
  $path = 'domain/add/' . $group_id . '/' . NM_BIBLIO;
  $id = 'author_biblio_add';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $biblio_options);


  $path = 'domain/biblio/' . $group_id;
  $id = 'author_biblio_overview';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'domain/h5p/' . $group_id;
  $id = 'author_category_interactive';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'domain/add/' . $group_id . '/' . NM_INTERACTIVE_CONTENT;
  $id = 'author_h5p_add';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  if (module_exists('annvid')) {
    $path = 'domain/add/' . $group_id . '/' . ANNVID_CONTENTTYPE;
    $id = 'author_annvid_add';
    if (!$subchapter_disabled) {
      $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $add_subchapter_options);
    }
    elseif (!empty($add_chapter_options)) {
      $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $add_chapter_options);
    }
    else {
      $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);
    }
  }
  $path = 'domain/h5p/' . $group_id;
  $id = 'author_interactive_overview';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);


  $path = 'domain/tasks/' . $group_id;
  $id = 'author_category_tasks';
  $label = $links[$id];
  $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

  $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_MULTIPLE_CHOICE;
  $id = 'author_tasks_mc_add';
  $label = $links[$id];
  $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

  $path = 'domain/add/' . $group_id . '/' . NM_CONTENT_QUESTION_AND_ANSWER;
  $id = 'author_tasks_qaa_add';
  $label = $links[$id];
  $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

  $path = 'domain/tasks/' . $group_id;
  $id = 'author_tasks_overview';
  $label = $links[$id];
  $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

  
  //Lehrtext-Konfiguration
  $path = 'domain/edit/' . $group_id;
  $id = 'author_category_config';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'domain/stats/' . $group_id;
  $id = 'auth_domain_stats';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  
  $path = 'domain/members/' . $group_id;
  $id = 'auth_domain_members';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);


  //settings
  $path = 'domain/edit/' . $group_id;
  $id = 'auth_domain_settings';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);


  $result = [];
  foreach ($links as $name => $item) {
    $attributes = [
      'attributes' => [
        'id' => $name,
        'class' => ['btn', 'btn-default'],
      ],
    ];
    if (isset($item['path'])) {
      custom_general_append_active_class(($item['path']), $attributes);
    }

    $group = isset($item['group']) ? $item['group'] : NULL;
    $link = isset($item['link']) ? $item['link'] : NULL;
    $link_long = isset($item['link_long']) ? $item['link_long'] : NULL;
    $result[$name] = [
      'link' => $link,
      'link_long' => $link_long,
      'group' => $group,
      'attributes' => $attributes['attributes'],
    ];
  }

  return $result;
}
