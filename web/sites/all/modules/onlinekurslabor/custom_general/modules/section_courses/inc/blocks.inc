<?php

function _section_courses_text_biblio_view() {
  $active_course = _section_courses_get_active_course();
  $domain_id = _section_courses_course_get_domain_id($active_course);

  $options = array(
    'attributes' => array(),
    'html' => TRUE,
    'query' => array(
      'og_group_ref' => $active_course->nid,
  ));

  $path = NM_COURSE_BIBLIO_PATH . '/' . $active_course->nid . '/' . $domain_id;


  $active = (_section_course_biblio_visible()) ? 'active' : '';

  $output = '';
  $link_text = '<table><tbody><tr valign="top"><td><span class="badge">A</span></td> <td style="padding-left:5px;">';
  $link_text .= 'Bibliografie';
  $link_text .= '</td></tr></tbody></table>';
  $link = l($link_text, $path, $options);

  $output .= '<ul class="menu nav nav-list"><li class="' . $active . '">' . $link . '</li></ul>';

  return $output;
}

function _section_courses_forum_breadcrumb_view() {

  return custom_general_render_breadcrumb(section_courses_forum_get_breadcrumb_items());
}

/**
 * Custom function to assemble renderable array for block content.
 * Returns a renderable array with the block content.
 * @return
 *   returns a renderable array of block content.
 */
function _section_courses_node_tabs_view() {

  $block = '';
  /*
   * node controls
   */

  if (section_courses_instructors_tools_access()) {
    $nav_items_single = array();
    $nav_items_single['overview'] = "Ansicht";
    $nav_items_single['edit'] = "Bearbeiten";

    $single_links = array();

    $group = _section_courses_get_active_course();

    if ($group) {
      foreach ($nav_items_single as $si) {
        $text_link = _section_courses_navtext_to_link($group, $si);
        if ($si != $text_link['link']) {
          $single_links[] = array('link' => $text_link['link']);
        }
      }
    }

    if (count($single_links) < 1) {
      return array();
    }

    $output_single = _custom_general_theme_tools_block($single_links, "content_node_tabs", "btn-group");

    // Block output in HTML with div wrapper
    $block = $output_single;
  }

  return $block;
}

function _course_header_section_view() {
    global $user;
    $user_uid = $user->uid;

    $block = array();
    $active_course = _section_courses_get_active_course();

    if (!isset($active_course) || empty($active_course)) {
        return array();
    }



    $variables = array();
    $variables['course_state'] = array();
    $variables['course_state']['demo'] = $variables['course_state']['draft'] = $variables['course_state']['pending'] = false;
    
    if (section_courses_demo_mode()) {
        $variables['course_state']['demo'] = true;
        $variables['demo']['title'] = NM_COURSE_DEMO_LABEL;
        $variables['demo']['text'] = t('In demo-mode you can only access the course info and text.');
        $og_membership = og_get_membership('node', $active_course->nid, 'user', $user_uid);
        if ($og_membership && $og_membership->state != OG_STATE_ACTIVE) {
            $variables['course_state']['pending'] = true;
            $variables['demo']['pending_text'] = t('Your request is being processed');
        }


        $url = 'group/node/' . $active_course->nid . '/subscribe';
        $subscribe_link = l(t('Enroll in course'), $url, array('query' => array('destination' => 'course/home/' . $active_course->nid)));

        $variables['course_subscribe_link'] = t('!enroll_link to participate.', array('!enroll_link'=>$subscribe_link));
    }

    $variables['sponsors_links'] = array();
    $sponsors_tids = field_get_items('node', $active_course, 'field_field_courses_sponsors');
    if ($sponsors_tids) {
        $count_sponsors = 0;
        //simulate more
        /*
          $tt = array_pop($sponsors_tids);
          $sponsors_tids[] = $tt;
          $sponsors_tids[] = $tt;
          $sponsors_tids[] = $tt;
          $sponsors_tids[] = $tt;
          $sponsors_tids[] = $tt;
         */
        foreach (($sponsors_tids) as $tid_array) {
            $term = taxonomy_term_load($tid_array['tid']);
            $url = $term->field_sponsors_url[LANGUAGE_NONE][0]['value'];

            $field_view = field_view_field('taxonomy_term', $term, 'field_sponsors_image', array('settings' => array('image_style' => 'course_sponsor_logo')));

            $field_view['#label_display'] = 'hidden';
            $sponsor_img = drupal_render($field_view);

            $variables['sponsors_links'][] = l($sponsor_img, $url, array('html' => TRUE, 'target' => '_blank', 'attributes' => array('target' => '_blank')));
            $count_sponsors++;
        }
    }



    if (!$active_course->status) {
        $variables['course_state']['draft'] = true;
    }

    $variables['course_title'] = $active_course->title;



    //header here
    if (isset($active_course->field_course_header)) {
        $field_view = field_view_field('node', $active_course, 'field_course_header', array('settings' => array('image_style' => 'course_header')));
        $uri = $field_view['#items'][0]['uri'];

        $url = image_style_url('course_header', $uri);
        $variables['course_header_url'] = $url;
    }

    return theme('section_courses_course_header_theme', $variables);
}

/*
 * check if we are in course demo mode
 *
 * return boolean
 */

function section_courses_demo_mode($nid = 0) {

  if ($nid) {
    $active_course = node_load($nid);
    if ($active_course && !drupal_valid_path(NM_COURSE_HOME_PATH . '/' . $active_course->nid)) {
      return TRUE;
    }
  }
  else {
    $active_course = _section_courses_get_active_course();

    if ($active_course && !drupal_valid_path(NM_COURSE_HOME_PATH . '/' . $active_course->nid)) {
      return TRUE;
    }
  }


  return FALSE;
}

/**
 * Theme Instrucotr's Tools Block
 *
 * @param type $variables
 * @return type
 */
function _section_courses_theme_instructor_tools($variables = NULL) {

  // 12.07.2019 - 16:31 - SN
  // no more instructor toolbar > alpha14
  // todo remove from all panels using instructors toolbar
  $output = "";
  return $output;

  if (section_courses_instructors_tools_access()) {

    $tool_links = _section_courses_get_instructor_tools();

    //$output = '<div class="row">';
    $output = _custom_general_theme_tools_block($tool_links, "instructors_tools", "btn-group btn-group-vertical", 1);
    //$output .= '</div">';
  }

  return $output;
}

function section_courses_instructors_tools_access($reset = FALSE) {
  global $user;
  static $result = NULL;


  if(user_access("bypass node access")) {
    //super admin
    return TRUE;
  }

  if ($result === NULL || $reset) {
    $user_uid = $user->uid;

    $active_course = _section_courses_get_active_course();

    $one_of_needed_roles = NULL;
    if ($active_course) {
      //$og_membership = og_get_membership('node', $active_course->nid, 'user', $user_uid);
      $roles = og_get_user_roles('node', $active_course->nid, $user_uid);
      $one_of_needed_roles = array_intersect($roles, array(NM_COURSES_ROLE_ADMINISTRATOR, NM_COURSES_ROLE_TUTOR));
      //bypass for admin

      if (in_array(NM_ROLE_ADMIN, $user->roles)) {
        $one_of_needed_roles = array(NM_ROLE_ADMIN);
      }
    }

    $result = !empty($one_of_needed_roles);
  }

  if (!$result && _section_courses_instructors_tools_role_access()) {
    $result = TRUE;
  }


  return ($result === NULL || $result === FALSE) ? FALSE : TRUE;
}

function _section_courses_instructors_tools_role_access() {
  global $user;
  $one_of_needed_roles = array_intersect($user->roles, array(NM_ROLE_ADMIN));

  $active_course = _section_courses_get_active_course();
  //27.02.2014 - 10:51 - SN
  //access to tools on panel overview pages
  // courses overview /courses - add course button
  if (!$active_course) {
    $one_of_needed_roles = array_merge($one_of_needed_roles, array_intersect($user->roles, array(NM_ROLE_DOZENT)));
  }

  return !empty($one_of_needed_roles);
}

function section_courses_tutor_tools_access() {
  global $user;
  $one_of_needed_roles = array_intersect($user->roles, array(NM_ROLE_ADMIN, NM_ROLE_DOZENT, NM_ROLE_TUTOR));

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

  $links = array();

  $links['instr_category_members']['label'] = "Teilnehmende";
  $links['instr_category_members']['label_long'] = "Teilnehmende";
  $links['instr_add_members']['label'] = ".Teilnehm";
  $links['instr_add_members']['label_long'] = "Teilnehmende hinzufügen"; //obacht!
  $links['instr_settings_members']['label'] = "verwalten";
  $links['instr_settings_members']['label_long'] = "Teilnehmende verwalten";

  $links['instr_category_content']['label'] = "Kursinhalte";
  $links['instr_category_content']['label_long'] = "Kursinhalte";
  $links['instr_add_news']['label'] = "Ankündigung";
  $links['instr_add_news']['label_long'] = "Ankündigung hinzufügen";
  $links['instr_add_docs']['label'] = "Dokument";
  $links['instr_add_docs']['label_long'] = "Dokument hinzufügen";
  $links['instr_add_task']['label'] = "Aufgabe";
  $links['instr_add_task']['label_long'] = "Aufgabe hinzufügen";
  $links['instr_overview_content']['label'] = "Inhaltsübersicht";
  $links['instr_overview_content']['label_long'] = "Inhaltsübersicht";


  $links['instr_category_groups']['label'] = "Gruppen";
  $links['instr_category_groups']['label_long'] = "Kursgruppen";
  $links['instr_add_groups']['label'] = "Gruppe";
  $links['instr_add_groups']['label_long'] = "Gruppe hinzufügen";
  $links['instr_overview_groups']['label'] = "Gruppen";
  $links['instr_overview_groups']['label_long'] = "Gruppenübersicht";

  //kann man auch langsam raushauen ;-)
  $links['instr_overview_projects']['label'] = "Projekte";
  $links['instr_overview_projects']['label_long'] = "Projekte";

  $links['instr_overview_forums']['label'] = "Forum";
  $links['instr_overview_forums']['label_long'] = "Forum";

  $links['instr_course_settings']['label'] = "Kurs";
  $links['instr_course_settings']['label_long'] = "Kurseinstellungen";


  //Groups
  $links['instr_category_members']['group']['gid'] = 1;
  $links['instr_category_members']['group']['root'] = TRUE;
  $links['instr_add_members']['group']['gid'] = 1;
  $links['instr_settings_members']['group']['gid'] = 1;


  $links['instr_category_content']['group']['gid'] = 2;
  $links['instr_category_content']['group']['root'] = TRUE;
  $links['instr_add_news']['group']['gid'] = 2;
  $links['instr_add_docs']['group']['gid'] = 2;
  $links['instr_add_task']['group']['gid'] = 2;
  $links['instr_overview_content']['group']['gid'] = 2;


  $links['instr_category_groups']['group']['gid'] = 3;
  $links['instr_category_groups']['group']['root'] = TRUE;
  $links['instr_add_groups']['group']['gid'] = 3;
  $links['instr_overview_groups']['group']['gid'] = 3;

  $links['instr_overview_projects']['group']['gid'] = 4;
  $links['instr_overview_projects']['group']['root'] = TRUE;

  $links['instr_overview_forums']['group']['gid'] = 5;
  $links['instr_overview_forums']['group']['root'] = TRUE;

  $links['instr_course_settings']['group']['gid'] = 6;
  $links['instr_course_settings']['group']['root'] = TRUE;

  //categorization
  $path = 'course/admin/' . $group_id . '/members'; //fallback-path für "neuer tab"
  $id = 'instr_category_members';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/admin/' . $group_id . '/content';
  $id = 'instr_category_content';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options );

  $path = 'course/admin/' . $group_id . '/groups';
  $id = 'instr_category_groups';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  //settings
  $path = 'course/admin/' . $group_id . '/settings';
  $id = 'instr_course_settings';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/projects/' . $group_id; //todo
  $id = 'instr_overview_projects';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/admin/' . $group_id . '/forums';
  $id = 'instr_overview_forums';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  //overviews
  $path = 'course/admin/' . $group_id . '/members';
  $id = 'instr_settings_members';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/admin/' . $group_id . '/groups';
  $id = 'instr_overview_groups';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);


  $path = 'course/admin/' . $group_id . '/content';
  $id='instr_overview_content';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options );


  //adds
  $path = 'course/admin/' . $group_id . '/add/courses-news';
  $id = 'instr_add_news';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/admin/' . $group_id . '/add/courses-docs';
  $id = 'instr_add_docs';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/admin/' . $group_id . '/add/courses-generic-task';
  $id = 'instr_add_task';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/admin/' . $group_id . '/members/add';
  $id = 'instr_add_members';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $path = 'course/admin/' . $group_id . '/add/courses-group';
  $id = 'instr_add_groups';
  $links[$id] += _custom_general_get_structered_tool_link($id, $links[$id], $path, $default_options);

  $result = array();
  foreach ($links as $name => $item) {
    $attributes = array('attributes' => array('id' => $name, 'class' => array('btn','btn-default')));
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


/**
 * Custom function to assemble renderable array for block content.
 * Returns a renderable array with the block content.
 * @return
 *   returns a renderable array of block content.
 */
function _course_top_navigation_view() {
  $course = _section_courses_get_active_course();
  if (!isset($course) || empty($course)) {
    return [];
  }

  $nav_items_single = [];
  $nav_items_single['overview'] = "Aktuelles";
  $nav_items_single['course'] = "Lehrtext";
  $nav_items_single['documents'] = "Kursdokumente";
  $nav_items_single['information'] = "Kursinfo";

  $nav_items_collab = [];
  $nav_items_collab['tasks'] = "Aufgaben";
  $nav_items_collab['cours_groups'] = "Kursgruppe";
  $nav_items_collab['forum'] = "Forum";
  $nav_items_collab['members'] = "Teilnehmende";

  $nav_items_single_links = _section_courses_top_navigation_label_to_link($nav_items_single, $course);
  $nav_items_collab_links = _section_courses_top_navigation_label_to_link($nav_items_collab, $course);

  // administration
  $admin_tools = "";
  if(section_courses_instructors_tools_access()) {
    $instructor_tools = _section_courses_get_instructor_tools();
    $id = "mobile_instructors_tools";
    $class = "btn-group btn-group-vertical";
    $admin_tools = _custom_general_theme_tools_navbar_block($instructor_tools, $id, $class);
  }


  $variables['single_links'] = $nav_items_single_links;
  $variables['collab_links'] = $nav_items_collab_links;
  $variables['admin_tools'] = $admin_tools;

  return theme('section_courses_top_navigation', $variables);
}

/**
 * @param $nav_items_single
 * @param $course
 *
 * @return array
 */
function _section_courses_top_navigation_label_to_link($nav_items_single, $course) {
  $links = [];
  $unread_badge = '';
  foreach ($nav_items_single as $si) {
    $text_link = _section_courses_navtext_to_link($course, $si);

    // only render this item, if feature is turned on.
    // render as disabled button if no text is assigned
    if ($si == "Lehrtext" && !_section_courses_feature_active($course, NM_COURSE_FEATURE_TEXT)) {
      continue;
    }
    if (strtolower($si) != strtolower($text_link['link'])) {
      $options = [
        'link' => $text_link['link'],
        'text' => $text_link['text'],
        'path' => $text_link['path'],
        'data' => @$text_link['data'],
        'attributes' => ['class' => ['btn']],
      ];

      //disable path buttons user doesn't have access to
      if (!drupal_valid_path($options['path'])) {
        $options['path'] = '#';
        $options['link'] = '<a href="#">' . $si . '</a>';
        $options['attributes']['class'][] = 'disabled';
      }

      if(!empty($options['data']['unread']))
      {
        $unread_count = $options['data']['unread'];
        $unread_badge = '<div class="unread_tiny_box"><div style="" class="arrow-down"></div>' . $unread_count . '</div>';
      }

      $options['rendered_link'] = '<li class="' . _onlinekurslabor_misc_umlaut_to_text(strtolower($options['text'])) . '">'
        . l($options['text'] . ' ' . $unread_badge, $options['path'], [
          'fragment' => @$options['fragment'],
          'html' => TRUE,
          'attributes' => ['class' => $options['attributes']['class']],
        ])
        . '</li>';

      $options['attributes']['class'][] = drupal_html_class($si);
      $links[] = $options;
    }

  }
  return $links;
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
  $result['text'] = $text;
  $result['path'] = "";

  if (!$course)
    return $result;

  $course_nid = $course->nid;

  $options = array(
    'attributes' => array(),
    'query' => array(
      'og_group_ref' => $course_nid,
  ));

  $active_node = NULL;
  if ((arg(0) == 'course') && (is_numeric(arg(3)))) {
    $active_node = node_load(arg(3));
  }

  $active_node_nid = 0;
  if ($active_node) {
    $active_node_nid = $active_node->nid;
  }


  $text_temp = $text;
  $text = ($text);


  switch ($text_temp) {
    case "Aktuelles":
      $num_unread = _section_courses_course_get_num_unread_by_type($user->uid, NM_COURSE_NEWS);

      if (_section_course_course_news_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }

      $path = "course/home/" . $course_nid;
      $result['path'] = $path;
      $result['link'] = l($text, $path, $options);
      $result['data']['unread'] = $num_unread;
      _section_courses_theme_tiny_unread_box($result['link'], $num_unread);

      break;
    case "Kursdokumente":

      $num_unread = _section_courses_course_get_num_unread_by_type($user->uid, NM_COURSE_DOCS);

      if (_section_course_course_docs_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }
      $path = "course/docs/" . $course_nid;
      $result['path'] = $path;
      $result['link'] = l($text, $path, $options);
      $result['data']['unread'] = $num_unread;
      _section_courses_theme_tiny_unread_box($result['link'], $num_unread);

      break;
    case "Kursinfo":
      $path = "course/info/" . $course_nid;
      $result['path'] = $path;
      $result['link'] = l($text, $path, $options);

      break;
    case "Kursgruppe":
      if (_section_course_get_num_coursegroups($course)) {
        if (_section_course_course_group_visible()) {
          $options['attributes'] = array('class' => array('active'));
        }
        //get course group if available, else show overview
        $course_group_nid = _section_courses_student_get_coursegroup_gid();
        if (!$course_group_nid) {
          $course_group_nid = $course_nid;
        }

        $path = "course/groups/" . $course_nid . '/' . $course_group_nid;
        $result['path'] = $path;
        $result['link'] = l($text, $path, $options);
      }
      break;
    case "Teilnehmende":
      $path = "course/members/" . $course_nid;
      $result['path'] = $path;
      $result['link'] = l($text, $path, $options);
      break;
    case "Forum":
      if (_section_courses_feature_active($course, NM_COURSE_FEATURE_FORUM)) {
        if (_section_course_forum_visible()) {
          $options['attributes'] = array('class' => array('active'));
        }
        $forum_link = _section_courses_get_forum_href($course);

        $term = _section_courses_get_forum_term($course);

        if(empty($term) && _section_courses_user_can_edit_course($user, $course)){
          drupal_set_message('Das Forumfeature ist in diesem Kurs aktiv aber es konnte kein passender Eintrag gefunden werden.<br/>Bitte kontaktieren Sie den Support.', 'error');
          
        }
        if(empty($term))
        {
          break;
        }
        $num_unread = _section_courses_advanced_forum_get_num_unread($user->uid, $term->tid);

        $path = $forum_link;

        //get number of active forum containers and link to first container
        //directly if only one cotainer is available
        $forum_container = taxonomy_get_children($term->tid);
        if (count($forum_container) == 1) {
          $path = _section_courses_get_forum_href($course, current($forum_container)->tid);
        }

        $result['path'] = $path;
        $result['link'] = l($text, $path, $options);

        if ($num_unread > 0) {
            $result['data']['unread'] = $num_unread;
          _section_courses_theme_tiny_unread_box($result['link'], $num_unread);
        }
      }
      break;
    case "Lehrtext":
      if (_section_courses_feature_active($course, NM_COURSE_FEATURE_TEXT)) {
        if (_section_course_text_visible()) {
          $options['attributes'] = array('class' => array('active'));
        }
        if ($domain_ref = _section_courses_course_get_domain_id($course)) {

          $path = "course/text/" . $course_nid . '/' . $domain_ref;
          $result['path'] = $path;
          $result['link'] = l($text, $path, $options);
        }
      }
      break;
    case "Aufgaben":

      $num_unread = _section_courses_course_get_num_unread_by_type($user->uid, NM_COURSE_GENERIC_TASK);

      if (_section_course_course_tasks_visible()) {
        $options['attributes'] = array('class' => array('active'));
      }

      $path = "course/tasks/" . $course_nid;
      $result['path'] = $path;
      $result['link'] = l($text, $path, $options);
      $result['data']['unread'] = $num_unread;
      _section_courses_theme_tiny_unread_box($result['link'], $num_unread);
      break;
    case "Ansicht":
      if (is_numeric($active_node_nid)) {
        //active link not set properly, using url() function to avoid this probplem
        $options['attributes']['class'] = array('btn','btn-default');
        if (substr(url('node/' . $active_node_nid), 0, 1) == '/') {
          $path = substr(url('node/' . $active_node_nid), 1);
          $result['path'] = $path;
          $result['link'] = l($text, $path, $options);
        }
        else {
          $path = url('node/' . $active_node_nid);
          $result['path'] = $path;
          $result['link'] = l($text, $path, $options);
        }
      }
      break;
    case "Bearbeiten":
      if (is_numeric($active_node_nid)) {
        $options['attributes']['class'] = array('btn','btn-default');
        $path = 'course/admin/' . $course_nid . '/' . $active_node_nid . '/edit';
        $result['path'] = $path;
        $result['link'] = l($text, $path, $options);
      }
      break;
    default:
  }

  //link to upper case
  //$result['link'] = ($result['link']);

  return $result;
}

function _section_courses_theme_tiny_unread_box(&$result, $num_unread) {
  if ($num_unread > 0) {
    $result = substr($result, 0, strpos($result, '</a>'));
    $result .= '<div class="unread_tiny_box"><div class="arrow-down" style=""></div>' . $num_unread . '</div></a>';
  }
}

/*
 * TODO
 */

function section_courses_theme_progressbar($active_course = NULL, $size = 200, $label = TRUE) {
  if (!$active_course) {
    $active_course = _section_courses_get_active_course();
  }

  if (!isset($active_course->field_time_span[LANGUAGE_NONE]) || !isset($active_course->field_time_span[LANGUAGE_NONE][0]['value2'])) {
    return "";
  }

  $percent = _section_courses_get_timespan_percentage($active_course);

  $percent = number_format($percent, 0);

  $output = '<div class="nm_circle_progress_bar">';
  if ($label) {
    $output .= '<div class="nm_cb_title">';
    $output .= '<h5 class="nm_cb_title_1">zeitlicher Fortschritt</h5>';
    $output .= '<h1 class="nm_cb_title_2">' . $percent . '</h1>';
    $output .= '<h5 class="nm_cb_title_3">%</h5>';
    $output .= '</div>';
  }
  //$output .= '<div id="course_progressbar">' . $percent . '</div><div></div>';

  $output .= '<input class="knob" data-angleArc=360 data-fgColor="#333" data-thickness=".12" data-width="' . $size . '" disabled value="' . $percent . '">';

  $output .= '</div>';

  return $output;
}
