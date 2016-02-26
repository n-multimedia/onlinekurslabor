<?php

//22.04.2013 - 23:50 - SN
//helper function - special cases when Section Content should be active

function _section_domain_active($group) {

  //$node = menu_get_object();
  //_custom_general_get_group($group);
  //

  $section_content = _section_domain_author_section_active();

  if ($section_content) {
    return TRUE;
  }

  return FALSE;
}

function _section_course_active($group) {

  //$node = menu_get_object();
  //_custom_general_get_group($group);
  //

  $section_content = _section_course_instructor_section_active();

  if ($section_content) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Determines if user is viewing a content section which belongs to the backend
 *
 * @return boolean
 */
function _section_domain_author_section_active() {
  $book_active = (arg(0) == 'admin' && arg(1) == 'content' && arg(2) == 'book' );
  $biblio_active = (arg(0) == 'node' && arg(1) == 'add' && arg(2) == 'biblio' ); //not necessary ?
  $media_active = (arg(0) == 'domain' && arg(1) == 'media');
  $biblio_overview_active = (arg(0) == 'domain' && arg(1) == 'biblio');
  $tasks_overview_active = (arg(0) == 'domain' && arg(1) == 'tasks');
  $h5p_overview_active = (arg(0) == 'domain' && arg(1) == 'h5p');
  $domain_text_active = (arg(0) == 'domain' && arg(1) == 'text');
  $domain_add_active = (arg(0) == 'domain' && arg(1) == 'add');
  $domain_edit_active = (arg(0) == 'domain' && arg(1) == 'edit');
  $domain_delete_active = (arg(0) == 'domain' && arg(1) == 'delete');

  //ajax
  $ajax_linkit_tasks = (arg(0) == 'section_content' && arg(1) == 'tasks' && arg(2) == 'autocomplete');
  $ajax_linkit_h5p = (arg(0) == 'h5p_integration' && arg(1) == 'item' && arg(2) == 'autocomplete');

  return $biblio_active || $biblio_overview_active ||
      $media_active || $book_active ||
      $tasks_overview_active || $domain_text_active ||
      $domain_add_active || $domain_edit_active ||
      $domain_delete_active || $h5p_overview_active || $ajax_linkit_tasks ||
      $ajax_linkit_h5p;
}

/**
 * Determines if user is viewing a course section which belongs to the instructor's backend
 *
 * @return boolean
 */
function _section_course_instructor_section_active() {
  /*
    $gc = og_context();
    $type_visible = FALSE;

    if($gc)
    {
    $active_node = node_load($gc['gid']);

    if(in_array($active_node->type, array(NM_COURSE, NM_COURSE_GROUP)))
    {
    $type_visible = TRUE;
    }
    }
   */
  $docs_visible = _section_course_course_docs_visible();
  $info_visible = (arg(0) == 'course' && arg(1) == 'info');
  $text_visible = _section_course_text_visible();
  $groups_visible = _section_course_course_group_visible();
  $members_visible = (arg(0) == 'course' && arg(1) == 'members');
  $forum_visible = _section_course_forum_visible();
  $tasks_visible = _section_course_course_tasks_visible();
  $admin_section_visible = (arg(0) == 'course' && arg(1) == 'admin');
  $home_visible = (arg(0) == 'course' && arg(1) == 'home');
  $news_visible = (arg(0) == 'course' && arg(1) == 'news');
  $projects_visible = (arg(0) == 'course' && arg(1) == 'projects');
  $biblio_visible = _section_course_biblio_visible();

  //ajax
  $ajax_linkit_tasks = (arg(0) == 'section_content' && arg(1) == 'tasks' && arg(2) == 'autocomplete');
  $ajax_linkit_h5p = (arg(0) == 'h5p_integration' && arg(1) == 'item' && arg(2) == 'autocomplete');


  $section_courses = $docs_visible || $info_visible ||
      $groups_visible || $members_visible ||
      $text_visible || $forum_visible ||
      $admin_section_visible ||
      $home_visible || $tasks_visible || $biblio_visible ||
      $news_visible || $projects_visible ||
      $ajax_linkit_tasks || $ajax_linkit_h5p;


  if ($section_courses) {
    return TRUE;
  }

  return FALSE;
}

function _section_course_text_visible() {
  return $text_visible = (arg(0) == 'course' && arg(1) == 'text');
}

function _section_course_biblio_visible() {
  $biblio_visible = (arg(0) == 'course' && arg(1) == 'biblio');

  if (_section_course_text_visible()) {
    $node_nid = arg(3);
    $node = node_load($node_nid);

    if ($node->type == NM_BIBLIO) {
      $biblio_visible = TRUE;
    }
  }

  return $biblio_visible;
}

function _section_course_forum_visible() {
  $forum_visible = (arg(0) == 'course' && arg(1) == 'forum');
  $forum_visible = (arg(0) == 'course' && arg(1) == 'forumcontent') || $forum_visible;

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    if (_custom_general_get_node_type(arg(1)) == NM_COURSE_FORUMTOPIC) {
      $forum_visible = TRUE;
    }
  }

  return $forum_visible;
}

function _section_course_course_group_visible($path = NULL) {
  $text_visible = (arg(0, $path) == 'course' && arg(1, $path) == 'groups');
  return $text_visible;
}

function _section_course_course_news_visible($path = NULL) {
  $text_visible = (arg(0, $path) == 'course' && arg(1, $path) == 'news');
  return $text_visible;
}

function _section_course_course_docs_visible($path = NULL) {
  $text_visible = (arg(0, $path) == 'course' && (arg(1, $path) == 'docs' || arg(1, $path) == 'doc' ));
  return $text_visible;
}

function _section_course_course_tasks_visible($path = NULL) {
  $text_visible = (arg(0, $path) == 'course' && arg(1, $path) == 'tasks');
  return $text_visible;
}


function _section_projects_cockpit_visible($path = NULL) {
  $text_visible = (arg(0, $path) == 'projects' && arg(4, $path) == 'cockpit');
  return $text_visible;
}

/**
 * Get node type from the Database without overhead
 * @param type $nid
 * @return null
 */
function _custom_general_get_node_type($nid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->propertyCondition('nid', $nid);
  $results = $query->execute();

  if (count($results) > 0) {
    $node = current($results['node']);
    if (isset($node) && isset($node->type)) {
      return $node->type;
    }
  }
  return NULL;
}

/*
 * get num of new / unread content
 */

/**
 * Calculates the number of unread replies for each forum and returns the
 * count for the requested forum.
 */

/**
 * todo - choose course forum first
 * get unread num of posts in a forum
 *
 * @staticvar null $result_cache
 * @param $uid user id
 * @param $uid term id
 * @return array
 */
function _section_courses_advanced_forum_get_num_unread($uid, $tid) {
  static $result_cache = NULL;

  $num_total = 0;

  //sum up
  $child_forums = array_keys(taxonomy_get_children($tid));

  if (is_null($result_cache)) {
    $result_cache = array();

    //comments
    $query = db_select("comment", "c");
    $f_alias = $query->join("forum", "f", "c.nid = f.nid");
    //$n_alias = $query->join("node", "n", "f.vid = n.vid");
    $h_alias = $query->leftJoin("history", "h", "c.nid = h.nid AND h.uid = :uid", array(":uid" => $uid));
    $query->addExpression("COUNT(DISTINCT(c.cid))", "count");
    $query->addField($f_alias, "tid");

    //forum name here...
    $query->condition("c.status", COMMENT_PUBLISHED);
    //fid
    if (!empty($child_forums)) {
      $query->condition("f.tid", $child_forums, 'IN');
    }
    $query->condition("c.changed", NODE_NEW_LIMIT, ">")
        ->condition(db_or()->where("c.changed > {$h_alias}.timestamp")->isNull("h.timestamp"))
        ->groupBy("{$f_alias}.tid");
    //->addTag("node_access");

    $result = $query->execute();

    foreach ($result as $row) {
      $result_cache[$row->tid] = $row->count;
    }


    //topics
    $query = db_select("node", "n");
    $f_alias = $query->join("forum", "f", "n.nid = f.nid");
    //$n_alias = $query->join("node", "n", "f.vid = n.vid");
    $h_alias = $query->leftJoin("history", "h", "n.nid = h.nid AND h.uid = :uid", array(":uid" => $uid));
    $query->addExpression("COUNT(DISTINCT(n.nid))", "count");
    $query->addField($f_alias, "tid");

    //forum name here...
    $query->condition("n.status", NODE_PUBLISHED);
    //fid
    if (!empty($child_forums)) {
      $query->condition("f.tid", $child_forums, 'IN');
    }

    $query->condition("n.changed", NODE_NEW_LIMIT, ">")
        ->condition(db_or()->where("n.changed > {$h_alias}.timestamp")->isNull("{$h_alias}.timestamp"))
        ->groupBy("{$f_alias}.tid")
        ->addTag("node_access");

    $result = $query->execute();

    //sum up
    foreach ($result as $row) {
      if (isset($result_cache[$row->tid])) {
        $result_cache[$row->tid] += $row->count;
      }
      else {
        $result_cache[$row->tid] = $row->count;
      }
    }
  }

  foreach ($result_cache as $key => $row) {
    if (in_array($key, $child_forums)) {
      $num_total += $row;
    }
  }

  return $num_total;
}

function _custom_general_get_num_unread($uid = NULL, $nid) {

  static $result_cache = array();
  if (!$uid) {
    global $user;
    $uid = $user->uid;
  }

  if (empty($result_cache[$nid])) {
    //get group's news entities
    //$query = db_select("node", "n");

    $query = db_select("node", "n");

    $query->condition('n.nid', $nid);

    $h_alias = $query->leftJoin("history", "h", "n.nid = h.nid AND h.uid = :uid", array(":uid" => $uid));
    //$query->addField("h", "timestamp");
    //$query->addField("n", "changed");
    $query->addExpression("COUNT(n.nid)", "count");
    $query->condition("n.status", NODE_PUBLISHED)
        //fid
        ->condition("n.changed", NODE_NEW_LIMIT, ">")
        ->condition(db_or()->where("n.changed > {$h_alias}.timestamp")->isNull("h.timestamp"))
        //->groupBy("{$f_alias}.tid")
        ->addTag("node_access");

    $result = $query->execute();

    //dpm($result->fetchAll());
    $result_cache[$nid] = current($result->fetchAll())->count;
  }

  return $result_cache[$nid];

  //check history entries for every entity found
  //return unread
}

function _section_courses_course_get_num_unread_by_type($uid, $type, $nid = NULL) {

  static $result_cache = array();
  if (!$uid) {
    global $user;
    $uid = $user->uid;
  }

  if (empty($result_cache[$type][$nid])) {
    //get group's news entities
    //$query = db_select("node", "n");
    $active_course = _section_courses_get_active_course();
    if (!$active_course)
      return NULL;
    $query = db_select("og_membership", "ogm");
    $query->condition("ogm.gid", $active_course->nid, "=");
    //$query->fields("ogm", array("entity_type", "etid"));
    $query->condition("ogm.entity_type", 'node', "=");
    $query->innerJoin("node", "n", "ogm.etid = n.nid");
    //$query->addField("ogm", "gid");
    //$query->addField("n", "nid");
    $query->condition('n.type', $type);

    if ($nid && is_numeric($nid)) {
      $query->condition('n.nid', $nid);
    }
    //history
    $h_alias = $query->leftJoin("history", "h", "n.nid = h.nid AND h.uid = :uid", array(":uid" => $uid));
    //$query->addField("h", "timestamp");
    //$query->addField("n", "changed");
    $query->addExpression("COUNT(n.nid)", "count");
    $query->condition("n.status", NODE_PUBLISHED)
        //fid
        ->condition("n.changed", NODE_NEW_LIMIT, ">")
        ->condition(db_or()->where("n.changed > {$h_alias}.timestamp")->isNull("h.timestamp"))
        //->groupBy("{$f_alias}.tid")
        ->addTag("node_access");

    $result = $query->execute();

    //dpm($result->fetchAll());
    $result_cache[$type][$nid] = current($result->fetchAll())->count;
  }

  return $result_cache[$type][$nid];

  //check history entries for every entity found
  //return unread
}

function custom_general_node_ids_by_type($type) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $type);
  $results = $query->execute();
  return (array_keys($results['node']));
}

function custom_general_get_course_by_lvnr($lvnr) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', NM_COURSE)
      ->propertyCondition('status', 1)
      ->fieldCondition('field_vhb_lvnr', 'value', $lvnr, '=');

  $result = $query->execute();

  return isset($result['node']) ? $result['node'] : NULL;
}

/**
 * get user's solution of a tasks
 * @param type $tid
 * @param type $uid
 * @return type
 */
function custom_general_get_task_solutions_by_uid($tid, $uid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', NM_COURSE_GENERIC_TASK_SOLUTION)
      ->propertyCondition('status', 1)
      ->propertyCondition('uid', $uid)
      ->fieldCondition('field_generic_task', 'target_id', $tid, '=');

  $result = $query->execute();

  return isset($result['node']) ? $result['node'] : NULL;
}

/**
 * get user's solution of a tasks
 * @param type $tid
 * @param type $uid
 * @return type
 */
function custom_general_get_all_task_solutions_by_uid($uid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', NM_COURSE_GENERIC_TASK_SOLUTION)
    ->propertyCondition('status', 1)
    ->propertyCondition('uid', $uid);

  $result = $query->execute();

  return isset($result['node']) ? $result['node'] : NULL;
}

/**
 * get user's solution of a tasks
 * dynamicly selection of user, depending on query arguments
 *
 * @param type $tid
 * @param type $uid
 */
function custom_general_get_task_solutions($tid, $uid) {
  static $result = array();
  if (!$uid) {
    global $user;
    $uid = $user->uid;
  }


  if (!$result || !isset($result[$tid][$uid])) {
    $uid_tmp = arg(5);
    if (!empty($uid_tmp) && is_numeric($uid_tmp)) {
      $account = user_load($uid_tmp);
      if ($account) {
        $uid = $account->uid;
      }
    }

    $account = user_load($uid);

    /*
     * differentiate between single and group tasks
     */
    $node_wrapper = entity_metadata_wrapper('node', $tid);
    $task_type = $node_wrapper->field_task_type->value();

    //0 single | 1 group
    //if group task and student
    if ($task_type == 1 && array_intersect(array(NM_ROLE_STUDENT, NM_ROLE_TEST_STUDENT), $account->roles)) {
      //get course group
      $cg_gid = _section_courses_get_coursegroup_gid($uid);

      //get all group members
      $cg_members = custom_general_get_users_in_group($cg_gid);

      //if user is not in a course group, fill array with his uid to get a solution
      if (empty($cg_members)) {
        $cg_members = array((object) array('uid' => $uid));
      }

      $solutions = array();

      // Loop through and load each user
      foreach ($cg_members AS $member) {
        // Load the user object if necessary
        $account = user_load($member->uid);

        if (!array_intersect(array(NM_ROLE_STUDENT, NM_ROLE_TEST_STUDENT), $account->roles))
          continue;

        // Do whatever else you need to
        $tmp_sol = custom_general_get_task_solutions_by_uid($tid, $account->uid);

        if ($tmp_sol) {
          $solutions[] = $tmp_sol;
        }
      }

      if (!empty($solutions)) {
        $result[$tid][$uid] = current($solutions);
        return $result[$tid][$uid];
      }
      else {
        $result[$tid][$uid] = $solutions;
        return $result[$tid][$uid];
      }

      //collect solutions
      //return solutions
    }//single
    else {
      $solutions = custom_general_get_task_solutions_by_uid($tid, $uid);
      $result[$tid][$uid] = $solutions;
      return $result[$tid][$uid];
    }
  }
  else {
    return $result[$tid][$uid];
  }
}

function _custom_general_get_structered_tool_link($id, $label, $path, $options = array()) {
  $result = array();

  $item_options = $options;

  if (empty($item_options['attributes']['title'])) {
    $item_options['attributes']['title'] = ($label);
  }

  if (!empty($path)) {
    //convert label to upper case
    $link = l($label, $path, $item_options);
  }
  else {
    $link = $label;
  }
  $result['path'] = $path;
  $result['link'] = $link;

  return $result;
}

function _custom_general_book_get_parents(&$subtree_pointer, $active_mlid) {
  $parents = array();
  if (!is_array($subtree_pointer))
    return $parents;
  foreach (array_keys($subtree_pointer) as $key) {
    if ($subtree_pointer[$key]['link']['mlid'] == $active_mlid) {
      $parents[] = $subtree_pointer[$key]['link']['p1'];
      $parents[] = $subtree_pointer[$key]['link']['p2'];
      $parents[] = $subtree_pointer[$key]['link']['p3'];
      $parents[] = $subtree_pointer[$key]['link']['p4'];
      $parents[] = $subtree_pointer[$key]['link']['p5'];
      $parents[] = $subtree_pointer[$key]['link']['p6'];
      $parents[] = $subtree_pointer[$key]['link']['p7'];
      $parents[] = $subtree_pointer[$key]['link']['p8'];
      $parents[] = $subtree_pointer[$key]['link']['p9'];
      break;
    }
    $res = _custom_general_book_get_parents($subtree_pointer[$key]['below'], $active_mlid);
    $parents = !empty($res) ? $res : $parents;
  }

  return $parents;
}

/**
 * Get all users of a group
 */
function custom_general_get_users_in_group($gid) {
  $query = db_select('users', 'u');

  $query->condition('u.uid', 0, '<>')
      ->condition('u.status', 1, '=')
      ->fields('u', array('uid', 'name'))
      ->join('og_membership', 'ogm', "ogm.gid = :gid AND u.uid = ogm.etid AND ogm.entity_type = 'user'", array(':gid' => $gid));

  $result = $query->execute();

  return $result->fetchAll();
}

function custom_general_get_users_in_group_by_role($gid, $roles) {
  $query = db_select('users', 'u');

  $query->condition('u.uid', 0, '<>')
      ->condition('u.status', 1, '=')
      ->fields('u', array('uid', 'name'))
      ->join('og_membership', 'ogm', "ogm.gid = :gid AND u.uid = ogm.etid AND ogm.entity_type = 'user'", array(':gid' => $gid));
  $query->join('og_users_roles', 'ogur', "ogm.etid = ogur.uid");
  $query->innerJoin('og_role', 'ogr', "ogur.rid = ogr.rid");

  $query->condition('ogr.name', $roles, 'IN');

  $result = $query->execute();

  return $result->fetchAll();
}

function _section_course_get_coursegroups($course) {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
      ->condition('n.status', 1, '=')
      ->condition('n.type', NM_COURSE_GROUP)
      ->fields('n', array('nid', 'title', 'type'))
      ->join('og_membership', 'ogm', "ogm.gid = :gid AND n.nid = ogm.etid AND ogm.entity_type = 'node'", array(':gid' => $course->nid));

  $result = $query->execute();


  return $result->fetchAll();
}

/**
 * get all kurs-dokumente of a course -object
 *
 * @param StdClass  $course object
 * @return mixed
 */
function _section_course_get_documents($course) {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
      ->condition('n.status', 1, '=')
      ->condition('n.type', NM_COURSE_DOCS)
      ->fields('n', array('nid', 'title', 'type'))
      ->join('og_membership', 'ogm', "ogm.gid = :gid AND n.nid = ogm.etid AND ogm.entity_type = 'node'", array(':gid' => $course->nid));

  $result = $query->execute();


  return $result->fetchAll();
}
function _section_course_get_solutions($course) {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
    ->condition('n.status', 1, '=')
    ->condition('n.type', NM_COURSE_GENERIC_TASK_SOLUTION)
    ->fields('n', array('nid', 'title', 'type'))
    ->join('og_membership', 'ogm', "ogm.gid = :gid AND n.nid = ogm.etid AND ogm.entity_type = 'node'", array(':gid' => $course->nid));

  $result = $query->execute();


  return $result->fetchAll();
}

function _section_course_get_tasks($course) {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
    ->condition('n.status', 1, '=')
    ->condition('n.type', NM_COURSE_GENERIC_TASK)
    ->fields('n', array('nid', 'title', 'type'))
    ->join('og_membership', 'ogm', "ogm.gid = :gid AND n.nid = ogm.etid AND ogm.entity_type = 'node'", array(':gid' => $course->nid));

  $result = $query->execute();


  return $result->fetchAll();
}

function _section_course_get_news($course) {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
      ->condition('n.status', 1, '=')
      ->condition('n.type', NM_COURSE_NEWS)
      ->fields('n', array('nid', 'title', 'type'))
      ->join('og_membership', 'ogm', "ogm.gid = :gid AND n.nid = ogm.etid AND ogm.entity_type = 'node'", array(':gid' => $course->nid));

  $result = $query->execute();


  return $result->fetchAll();
}

function _section_course_get_courses() {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
      //->condition('n.status', 1, '=')
      ->condition('n.type', NM_COURSE)
      ->fields('n', array('nid', 'title', 'type'));

  $result = $query->execute();

  return $result->fetchAll();
}

/**
 * get all courses a user is member of by uid
 *
 * @param $uid
 * @return mixed
 */
function _section_course_get_courses_by_uid($uid) {
//more efficient way
  $query = db_select('og_membership', 'om')
    ->fields('n', array('nid', 'title', 'type'))
    ->condition('om.type', 'og_membership_type_default')
    ->condition('om.entity_type', 'user')
    ->condition('om.state',OG_STATE_ACTIVE)
    ->condition('om.etid', $uid)
    ->condition('n.type', NM_COURSE);
  $query->leftJoin('node', 'n', 'n.nid = om.gid');
  $results = $query->execute()->fetchAll();

  return $results;

}

/**
 * get a course-object // e.g. drupal-node-object
 *
 * @param int $course_id
 * @return StdClass
 */
function _section_course_get_course($course_id)
{
    return  node_load($course_id);
}

/**
 * get the written name of a semester for a course
 *
 * @param StdClass / int $course - the course-object or just the id
 * @return String name
 */
function _section_course_get_Semestername($course)
 {
    if (!is_object($course))
        $course = _section_course_get_course($course);

    $semester_id = $course->field_semester[LANGUAGE_NONE][0]['tid'];

    $term = taxonomy_term_load($semester_id);
    $name = $term->name;
    return $name;
}

/**
 * get all courses a user with $user_uid may edit
 *
 * @param String $user_uid
 * @return array node_object $courses
 */
function _section_course_get_courses_for_course_admin($user_uid, $sort_field='')
{
   /*some odd actions*/
    $field = field_info_field('og_group_ref');
$instance = field_info_instance('node', 'og_group_ref', 'courses_news');
$refs = entityreference_get_selection_handler($field , $instance)->getReferencableEntities();
#dpm($refs);
$courses = $refs['courses_course'];

$real_courses = array();
foreach($courses as $course_id => $bla)
{
   $a_course = _section_course_get_course($course_id);
     if (node_access('update', $a_course))
              $real_courses[$course_id] = $a_course;
}
  

if($sort_field)
    usort($real_courses, create_function('$a, $b', 'return _section_course_sort_courses_by_field($a, $b, "'.$sort_field.'");'));

return $real_courses;
}
/**
 * needed for usort, dont touch this. 
 *
 * @param node_object course $a
 * @param node_object course $b
 * 
 * @return in -1 ,0 , 1
 */
function _section_course_sort_courses_by_field($a, $b, $name_of_field)
{
    
    //flatten the array withouth the need for foreaches or array_keys
     $it1 = new RecursiveIteratorIterator(new RecursiveArrayIterator($a->$name_of_field));
     $it2 = new RecursiveIteratorIterator(new RecursiveArrayIterator($b->$name_of_field));
   
     $var1 = iterator_to_array($it1, false);
     $var2 = iterator_to_array($it2, false);
     $var1 = $var1[0];
     $var2 = $var2[0];
     //sort the int
        return ($var1 - $var2);
        
}

function _section_course_get_num_coursegroups($course) {

  return count(_section_course_get_coursegroups($course));
}

/**
 * theme breadcrumb array
 *
 * @param type $breadcrumb
 * @return type
 */
function custom_general_render_breadcrumb($breadcrumb) {

  $result = array();

  foreach ($breadcrumb as $parent) {
    if (current_path() == $parent['href']) {
      $result[] = $parent['title'];
    }
    else {
      $result[] = '<b>' . l($parent['title'], $parent['href'], $parent['localized_options']) . '</b>';
    }
  }


  return implode(' » ', $result);
}

/**
 * access check by role
 * @return boolean
 */
function custom_general_user_is_okl_admin($roles = array()) {
  global $user;

  foreach ($roles as $role) {
    if (in_array($role, $user->roles)) {
      return TRUE;
    }
  }
  return FALSE;
}

function _section_content_get_domains() {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
    //->condition('n.status', 1, '=')
    ->condition('n.type', NM_CONTENT_DOMAIN)
    ->fields('n', array('nid', 'title', 'type'));

  $result = $query->execute();

  return $result->fetchAll();
}



function _section_courses_fix_solution_og(){
  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
    ->condition('n.status', 1, '=')
    ->condition('n.type', NM_COURSE_GENERIC_TASK_SOLUTION)
    ->fields('n', array('nid'))
    ->leftJoin('og_membership', 'ogm', "n.nid = ogm.etid AND ogm.entity_type = 'node'");
  $query->isNull('ogm.gid');

  $result = $query->execute()->fetchAll();


  foreach($result as $n){

    /*
    $solution = node_load($node->nid);
    dpm(format_date($solution->created, 'short'));
    dpm($solution);
    */

    $node = node_load($n->nid);
    if(empty($node->og_group_ref[LANGUAGE_NONE][0]['target_id']) && !empty($node->field_generic_task[LANGUAGE_NONE][0]['target_id'])) {
      $tid = $node->field_generic_task[LANGUAGE_NONE][0]['target_id'];
      $task = node_load($tid);
      $course_nid = $task->og_group_ref[LANGUAGE_NONE][0]['target_id'];
      $node->og_group_ref[LANGUAGE_NONE][0]['target_id'] = $course_nid;
      node_save($node);
    }
  }

}
