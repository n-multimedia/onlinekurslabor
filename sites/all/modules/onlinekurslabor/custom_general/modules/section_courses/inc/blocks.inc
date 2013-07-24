<?php

function _course_header_section_view() {

  $active_course = _section_courses_get_active_course();

  $output = '';

  if ($active_course) {
    $output .= '<div id="course_header" class="row-fluid">';
    $output .= '<div class="span12">';
    $output .= '<div id="course_header_title"><h1>';
    $output .= $active_course->title;
    $output .= '</h1></div>';
    //header here
    $header_pic = '';
    if (isset($active_course->field_course_header)) {
      $field_view = field_view_field('node', $active_course, 'field_course_header', array('settings' => array('image_style' => 'course_header')));
      $field_view['#label_display'] = 'hidden';
      $header_pic = drupal_render($field_view);
    }
    $output .= $header_pic;

    $output .= '</div>';
    $output .= '</div>';
  }

  return $output;
}

/**
 * Theme Instrucotr's Tools Block 
 * 
 * @param type $variables
 * @return type
 */
function _section_courses_theme_instructor_tools($variables = NULL) {

  $output = "";

  if (section_courses_instructors_tools_access()) {

    $tool_links = _section_courses_get_instructor_tools();

    //$output = '<div class="row-fluid">';
    $output = _custom_general_theme_tools_block($tool_links, "instructors_tools", "btn-group btn-group-vertical", 1);
    //$output .= '</div">';
  }

  return $output;
}

function section_courses_instructors_tools_access() {
  global $user;
  $one_of_needed_roles = array_intersect($user->roles, array(NM_ROLE_ADMIN, NM_ROLE_DOZENT));

  return !empty($one_of_needed_roles);
}

/**
 * get link Items for Insructor's Tools Block
 * 
 * @global type $user
 * @return string
 */
function _section_courses_get_instructor_tools() {
  global $user;

  $group = og_context();

  $group_get_id = isset($_GET['og_group_ref']) ? $_GET['og_group_ref'] : NULL;

  $group_id = !empty($group['gid']) ? $group['gid'] : $group_get_id;

  $group = node_load($group_id);

  if (!$group_id || $group->type != NM_COURSE) {
    $course = _section_courses_get_active_course();

    if ($course)
      $group_id = $course->nid;
  }

  $node = menu_get_object();

  $default_options = array(
    'query' => array(
      'og_group_ref' => $group_id,
    ),
    'attributes' => array(
      'title' => '',
      ));

  /*
  $members_overview_options = $default_options;
  $groups_overview_options = $news_options;

  $docs_options = $news_options;
  $members_options = $news_options;
  $groups_options = $news_options;
  $forums_overview_options = $news_options;
  $course_settings_options = $news_options;*/


  $links = array();


  $links['instr_overview_members']['label'] = "Teilnehmer";
  $links['instr_add_members']['label'] = "Teilnehmer";

  $links['instr_overview_content']['label'] = "Inhalte";
  $links['instr_add_news']['label'] = "Nachricht";
  $links['instr_add_docs']['label'] = "Dokument";

  $links['instr_overview_groups']['label'] = "Gruppe";
  $links['instr_add_groups']['label'] = "Gruppe";


  $links['instr_overview_forums']['label'] = "Forum";

  $links['instr_course_settings']['label'] = "Kurs";


  //Groups
  $links['instr_overview_members']['group']['gid'] = 1;
  $links['instr_overview_members']['group']['root'] = TRUE;
  $links['instr_add_members']['group']['gid'] = 1;

  $links['instr_overview_content']['group']['gid'] = 2;
  $links['instr_overview_content']['group']['root'] = TRUE;
  $links['instr_add_news']['group']['gid'] = 2;
  $links['instr_add_docs']['group']['gid'] = 2;

  $links['instr_overview_groups']['group']['gid'] = 3;
  $links['instr_overview_groups']['group']['root'] = TRUE;
  $links['instr_add_groups']['group']['gid'] = 3;

  $links['instr_overview_forums']['group']['gid'] = 4;
  $links['instr_overview_forums']['group']['root'] = TRUE;

  $links['instr_course_settings']['group']['gid'] = 5;
  $links['instr_course_settings']['group']['root'] = TRUE;



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

    //settings
    $path = 'course/admin/' . $group_id . '/settings';
    $id = 'instr_course_settings';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'course/admin/' . $group_id . '/forums';
    $id = 'instr_overview_forums';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    //overviews
    $path = 'course/admin/' . $group_id . '/members';
    $id = 'instr_overview_members';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'course/admin/' . $group_id . '/groups';
    $id = 'instr_overview_groups';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = "";
    $id = 'instr_overview_content';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    //adds
    $path = 'course/admin/' . $group_id . '/add/courses-news';
    $id = 'instr_add_news';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'course/admin/' . $group_id . '/add/courses-docs';
    $id = 'instr_add_docs';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'course/admin/' . $group_id . '/members/add';
    $id = 'instr_add_members';
    $label = $links[$id]['label'];
    $links[$id] += _custom_general_get_structered_tool_link($id, $label, $path, $default_options);

    $path = 'course/admin/' . $group_id . '/add/courses-group';
    $id = 'instr_add_groups';
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


/**
 * Custom function to assemble renderable array for block content.
 * Returns a renderable array with the block content.
 * @return
 *   returns a renderable array of block content.
 */
function _course_top_navigation_view() {
  $block = array();
  $course = _section_courses_get_active_course();

  if (!isset($course) || empty($course))
    return array();

  $nav_items_single = array();
  $nav_items_single['overview'] = "Aktuelles";
  $nav_items_single['course'] = "Lehrtext";
  $nav_items_single['documents'] = "Kursdokumente";
//$nav_items['notes'] = "Notizen";
  $nav_items_single['information'] = "Kursinfo";


  $nav_items_collab = array();
  $nav_items_collab['tasks'] = "Aufgaben";
  $nav_items_collab['cours_groups'] = "Kursgruppe";
  $nav_items_collab['forum'] = "Forum";
  $nav_items_collab['members'] = "Teilnehmer";
  $nav_items_collab['wiki'] = "Wiki";


//single links
  $single_links = array();
//$output_single = '';
//$output_single .= '<ul class="links inline clearfix">';
  foreach ($nav_items_single as $si) {
    $text_link = _section_courses_navtext_to_link($course, $si);
    $single_links[] = array('link' => $text_link['link'], 'attributes' => array('class' => array('btn')));
//$si_link = _section_courses_navtext_to_link($course, $si);
//$output_single .= "<li>" . $si_link . "</li>";
  }
//$output_single .= "</ul>";
//collaborative links
  $collab_links = array();
//$output_collab = '';
//$output_collab .= '<ul class="links inline clearfix">';
  foreach ($nav_items_collab as $si) {
    $text_link = _section_courses_navtext_to_link($course, $si);
    if (strtolower($si) != strtolower($text_link['link'])) {
      $collab_links[] = array('link' => $text_link['link'], 'attributes' => array('class' => array('btn')));
    }
//$si_link = _section_courses_navtext_to_link($course, $si);
//$output_collab .= '<li>' . $si_link . '</li>';
  }
//$output_collab .= '</ul>';

  $output_single = _custom_general_theme_tools_block($single_links, "course_top_nav_single");
  $output_collab = _custom_general_theme_tools_block($collab_links, "course_top_nav_collab");

// Block output in HTML with div wrapper
  $block = array(
    'prefix' => array(
      '#prefix' => '<div id="course_top_navigation" class="btn-toolbar row-fluid">',
      '#type' => 'markup',
      '#markup' => "",
    ),
    'single' => array(
      '#prefix' => '<div id="course_tools_single" class="btn-group span6">',
      '#type' => 'markup',
      '#markup' => $output_single,
      '#suffix' => '</div>',
    ),
    'collab' => array(
      '#prefix' => '<div id="course_tools_collab" class="btn-group span6">',
      '#type' => 'markup',
      '#markup' => $output_collab,
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

/**
 * returns a themed link item for the courses top navigation
 * 
 * @param type $course
 * @param type $text
 * @return string
 */
function _section_courses_navtext_to_link($course, $text) {
  global $user;
  $result = array();
  $result['link'] = $text;

  $course_nid = $course->nid;

  $options = array(
    'attributes' => array(),
    'query' => array(
      'og_group_ref' => $course_nid,
      ));

  $text_temp = $text;
  $text = ($text);

  switch ($text_temp) {
    case "Aktuelles":
      $num_unread = _section_courses_course_get_num_unread_by_type($user->uid, NM_COURSE_NEWS);

      if (_section_course_course_news_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }

      $path = "course/home/" . $course_nid;
      $result['link'] = l($text, $path, $options);

      _section_courses_theme_tiny_unread_box($result['link'], $num_unread);

      break;
    case "Kursdokumente":

      $num_unread = _section_courses_course_get_num_unread_by_type($user->uid, NM_COURSE_DOCS);
      
      if (_section_course_course_docs_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }
      $path = "course/docs/" . $course_nid;
      $result['link'] = l($text, $path, $options);

      _section_courses_theme_tiny_unread_box($result['link'], $num_unread);

      break;
    case "Kursinfo":
      $path = "course/info/" . $course_nid;
      $result['link'] = l($text, $path, $options);

      break;
    case "Kursgruppe":
      //todo students course -> direct course nid
      if (_section_course_course_group_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }
      //get course group if available, else show overview
      $course_group_nid = _section_courses_student_get_coursegroup_gid();
      if (!$course_group_nid) {
        $course_group_nid = $course_nid;
      }

      $path = "course/groups/" . $course_nid . '/' . $course_group_nid;
      $result['link'] = l($text, $path, $options);
      break;
    case "Teilnehmer":
      $path = "course/members/" . $course_nid;
      $result['link'] = l($text, $path, $options);
      break;
    case "Forum":
      if (_section_courses_feature_active($course, NM_COURSE_FEATURE_FORUM)) {
        if (_section_course_forum_visible()) {
          $options['attributes'] = array('class' => array('active'));
        }
        $forum_link = _section_courses_get_forum_href($course);

        $term = _section_courses_get_forum_term($course);

        $num_unread = _section_courses_advanced_forum_get_num_unread($user->uid, $term->tid);

        $path = $forum_link;
        $result['link'] = l($text, $path, $options);

        if ($num_unread > 0) {
          _section_courses_theme_tiny_unread_box($result['link'], $num_unread);
        }
      }
      break;
    case "Lehrtext":
      if (_section_course_text_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }
      if ($domain_ref = _section_courses_course_get_domain_id($course)) {

        $path = "course/text/" . $course_nid . '/' . $domain_ref;
        $result['link'] = l($text, $path, $options);
      }
      break;
    case "Aufgaben":
      if (_section_course_course_tasks_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }

      $path = "course/tasks/" . $course_nid;
      $result['link'] = l($text, $path, $options);
      break;
    default:
  }

  //link to upper case
  $result['link'] = ($result['link']);

  return $result;
}

function _section_courses_theme_tiny_unread_box(&$result, $num_unread) {
  if ($num_unread > 0) {
    $result .= '<div class="unread_tiny_box"><div class="arrow-down" style=""></div>' . $num_unread . '</div>';
  }
}

/*
 * TODO
 */

function section_courses_theme_progressbar() {
  $active_course = _section_courses_get_active_course();


  if (!isset($active_course->field_time_span[LANGUAGE_NONE]) || !isset($active_course->field_time_span[LANGUAGE_NONE][0]['value2'])) {
    return "";
  }

  $now = time();
  $start = $active_course->field_time_span[LANGUAGE_NONE][0]['value'];
  $end = $active_course->field_time_span[LANGUAGE_NONE][0]['value2'];

  $start = strtotime($start);
  $end = strtotime($end);

  $percent = 0;

  if ($now <= $start) {
    $percent = 0;
  }
  else if ($now >= $end) {
    $percent = 1;
  }
  else {
    $percent = (($now - $start) / ($end - $start));
  }

  $output = '<h2>Fortschritt (' . number_format($percent * 100, 0) . '%)</h2>';
  $output .= '<div id="course_progressbar">' . $percent . '</div><div></div>';

  return $output;
}
