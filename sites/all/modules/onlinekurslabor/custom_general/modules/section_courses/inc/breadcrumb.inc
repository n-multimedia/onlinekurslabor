<?php

function _section_courses_breadcrumb_alter(&$active_trail, $item) {

  //skip all breadcrumb modifications
  return;

//Check if the proper context is set first:
//Abort if context is wrong
  $context = context_get("context", "section_courses");
  if (empty($context))
    return;

  global $user;

  $active_node = menu_get_object();
  $active_node = !empty($active_node) ? $active_node : menu_get_object('file');
  $type = isset($active_node) ? $active_node->type : NULL;
  //adaption for every user
  //set type to file, if file id (fid) is set
  $entity_type = (isset($type) && !isset($active_node->fid)) ? 'node' : (isset($active_node->fid) ? 'file' : NULL);

  //&& (in_array($type, array(NM_DOMAIN, NM_CHAPTER, NM_BIBLIO)) || $entity_type == 'file') // redundant
  if (!empty($active_node)) {
    //for every user
    _section_courses_breadcrumb_append_from_entity_data($entity_type, $active_trail, $active_node);
  }
  else {
    //check if adaption any user role is necessary
    _section_courses_alter_breadcrumb_for_role($active_trail);
  }
}

function _section_courses_alter_breadcrumb_for_role(&$active_trail) {
  global $user;

//Check if user has role Autor or a certain path is beeing viewd (e.g. domain media)
  $path_match = strpos(request_uri(), NM_COURSE_DOCS_PATH);
  $path_match = strpos(request_uri(), NM_COURSE_HOME_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_NEWS_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_DOCS_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_INFO_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_GROUPS_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_TEXT_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_MEMBERS_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_FORUM_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_FORUMCONTENT_PATH) || $path_match;
  $path_match = strpos(request_uri(), NM_COURSE_ADMIN_PREFIX_PATH) || $path_match;

  if ((in_array(NM_ROLE_DOZENT, $user->roles) || $path_match)) {
    $b_items = _section_courses_get_course_breadcrumb_items();

    if ($b_items) {
      $active_trail = array_merge(array($b_items['domain_overview_item']), $b_items['active_domain_item']/* , array_slice($active_trail, -1) */);
    }
  }
}

//get breadcrumb items for domain by group id
function _section_courses_get_course_breadcrumb_items($group_get_id = NULL) {
//get active group id, passed as get param
  $tmp_gid = isset($_GET['og_group_ref']) ? $_GET['og_group_ref'] : NULL;
  $group_get_id = isset($group_get_id) ? $group_get_id : $tmp_gid;

//get from url because all path are build like /courses/media/%1 /domain/media/%1
  $group_get_id = (empty($group_get_id) && is_numeric(arg(2))) ? arg(2) : $group_get_id;


  if (!isset($group_get_id))
    return NULL;


//build query items for breadcrumb items, to keep important get information in the url
  $item_options = array(
    'absolute' => TRUE,
    'query' => array(
      'og_group_ref' => $group_get_id,
    )
  );
  $node_overview = node_load(NM_COURSES_OVERVIEW_ID);
  $node_course = node_load($group_get_id);


  $result = array();

  $courses_overview_item = array(
    'title' => $node_overview->title,
    'href' => check_url(url('node/' . $node_overview->nid, $item_options)),
    'localized_options' => array(),
  );
  $result['domain_overview_item'] = $courses_overview_item;


  $active_course_item = array(
    'title' => $node_course->title,
    'href' => check_url(url('node/' . $group_get_id, $item_options)),
    'localized_options' => array(),
  );
  $result['active_domain_item'] = array();
  $result['active_domain_item'][] = $active_course_item;

  //add forum breadcrumbs
  if (strpos(request_uri(), NM_COURSE_FORUM_PATH) || strpos(request_uri(), NM_COURSE_FORUMCONTENT_PATH)) {

    $active_course = _section_courses_get_active_course();
    $active_course_forum_name = _section_courses_get_forum_name($active_course);
    
    //$forum_term = taxonomy_term_load(arg(3));
    $active_topic = node_load(arg(3));
    if (!$active_topic || $active_topic->type != "forum") {
      $forum_term = taxonomy_term_load(arg(3));
      $active_topic = NULL;
    }
    else {
      $forum_term = taxonomy_term_load($active_topic->forum_tid);
    }

    $forum_term->parents = taxonomy_get_parents_all($forum_term->tid);
    $breadcrumb = array();
    $breadcrumb[] = array(
      'title' => "Forum",
      'href' => _section_courses_get_forum_href($active_course),
      'localized_options' => array(),
    );
    if (isset($forum_term->parents)) {
      $parents = array_reverse($forum_term->parents);

      if (!empty($parents)) {
//follow path from course_depth
//the depth is reached when Forum "Course Forum Name" is called
        $depth_flag = FALSE;
        $counter = 0;
        foreach ($parents as $p) {
//break in der Tiefe von Kursforen
          if ($p->name != $active_course_forum_name && !$depth_flag) {
            continue;
          }
          $depth_flag = TRUE;

          if ($counter++ == 0) {
            continue;
          }

          if ($p->tid != $forum_term->tid || $active_topic) {
            $breadcrumb[] = array(
              'title' => $p->name,
              'href' => url('course/forum/' . $active_course->nid . '/' . $p->tid, $item_options),
              'localized_options' => array(),
            );
          }
        }
      }
    }

    $result['active_domain_item'] = array_merge($result['active_domain_item'], $breadcrumb);
  }



  return $result;
}


//add domain overview as first breadcrumb item
function _section_courses_breadcrumb_append_from_entity_data($entity_type, &$active_trail, $active_entity = NULL) {
  global $user;

//adapt breadcrumb if content type domain or chapter are selected
  $c_node = node_load(NM_COURSES_OVERVIEW_ID);

//when Biblio node is selected
//For authors and admins, breadcrumb leading to source domain
//todo: for students.. breadcrumb leading to their course

  if (isset($active_entity) && (in_array($active_entity->type, array(NM_BIBLIO)) || $entity_type == 'file') && isset($active_entity->og_group_ref)) {
    /*
      $author_or_admin = in_array(NM_ROLE_AUTOR, $user->roles) || in_array(NM_ROLE_ADMIN, $user->roles);
      if ($author_or_admin) {
      $lang_og = field_language($entity_type, $active_entity, 'og_group_ref');

      if (!empty($active_entity->og_group_ref)) {
      $og_ref_val = $active_entity->og_group_ref[$lang_og][0]['target_id'];
      $b_items = _get_domain_breadcrumb_items($og_ref_val);

      $active_trail = array_merge(array($b_items['domain_overview_item']), array($b_items['active_domain_item']));
      }
      }
     */
  }
  else {
    $new_breadcrumb_items = array();

    $new_breadcrumb_items[] = array(
      'title' => $c_node->title,
      'href' => 'node/' . $c_node->nid,
      'localized_options' => array(),
    );

    if (in_array($active_entity->type, array(NM_COURSE_NEWS, NM_COURSE_DOCS, NM_COURSE_GROUP))) {
      $active_course = _section_courses_get_active_course(); //node_load(_custom_general_get_group($active_entity));
      $new_breadcrumb_items[] = array(
        'title' => $active_course->title,
        'href' => 'node/' . $active_course->nid,
        'localized_options' => array(),
      );
    }


    $active_trail = array_merge($new_breadcrumb_items, array_slice($active_trail, 1));
  }
}