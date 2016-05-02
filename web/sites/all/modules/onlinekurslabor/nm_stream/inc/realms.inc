<?php

function nm_stream_node_access($op, $node) {

}

function nm_stream_node_access_records($node) {
  $grants = array();
  // handle the Section node itself

  if ($node->type == 'nm_stream') {
    $privacy = $node->field_nm_privacy [LANGUAGE_NONE][0]['value'];

    //always set private realm for view and edit purpose!
    $grants[] = array(
      'realm' => 'nm_stream_private',
      'gid' => $node->uid,
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 0,
      'priority' => 1,
    );

    switch ($privacy) {
      case NM_STREAM_PRIVATE:
        //always set private realm for view and edit purpose!
        break;
      case NM_STREAM_TEAM:
        $context_nid = $node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        $context_type = _custom_general_get_node_type($context_nid);
        switch ($context_type) {
          case NM_COURSE_GROUP:
            /*$grants[] = array(
              'realm' => 'all',
              'gid' => 0,
              'grant_view' => 0,
              'grant_update' => 0,
              'grant_delete' => 0,
              'priority' => 1,
            );*/
            $grants[] = array(
              'realm' => 'nm_stream_team',
              'gid' => $context_nid,
              'grant_view' => 1,
              'grant_update' => 0,
              'grant_delete' => 0,
              'priority' => 1,
            );
            break;
        }
        break;

      case NM_STREAM_COURSE:
        $context_nid = $node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        $context_type = _custom_general_get_node_type($context_nid);
        switch ($context_type) {
          case NM_COURSE_GROUP:
            //get course which this course group is assigned to
            $course_nid = _custom_general_get_group(node_load($context_nid));
            $entities = og_get_entity_groups('node', $course_nid);
            if (!empty($entities)) {
              $course_nid = current(current($entities));
            }

            /*$grants[] = array(
              'realm' => 'all',
              'gid' => 0,
              'grant_view' => 0,
              'grant_update' => 0,
              'grant_delete' => 0,
              'priority' => 1,
            );*/
            $grants[] = array(
              'realm' => 'nm_stream_course',
              'gid' => $course_nid,
              'grant_view' => 1,
              'grant_update' => 0,
              'grant_delete' => 0,
              'priority' => 1,
            );
            break;
        }
        break;
      case NM_STREAM_PUBLIC:
        $grants[] = array(
          'realm' => 'nm_stream_public',
          'gid' => 1,
          'grant_view' => 1,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 0,
        );
        break;
      default:
        //private
        break;
    }
    //}
  }


  return !empty($grants) ? $grants : array();
}

/**
 * Implements hook_node_grants().
 */
function nm_stream_node_grants($account, $op) {

  /*
  if ($op != 'view') {
    return;
  }*/
  $grants = array();

  //_section_courses_get_coursegroup_gid($uid);

  $grants['nm_stream_private'][] = $account->uid;
  $grants['nm_stream_public'][] = 1;

  //get users courses
  $user_group_nids = og_get_groups_by_user($account, 'node');

  if (empty($user_group_nids)) {
    return $grants;
  }

  //dpm($account->uid);
  $user_courses = array();
  $user_groups = array();
  foreach ($user_group_nids as $ugn) {
    if (_custom_general_get_node_type($ugn) == NM_COURSE) {
      $user_courses[] = $ugn;
      $grants['nm_stream_course'][] = $ugn;

      $course = node_load($ugn);
      //give access to all coursegroups for administratos and tutors
      //course groups for instructors
      $course_groups = _section_course_get_coursegroups($course);
      if(!empty($course_groups)) {
        $og_membership = og_get_membership('node', $course->nid, 'user', $account->uid);

        $roles = og_get_user_roles('node', $og_membership->gid, $account->uid, true, ($og_membership->state < OG_STATE_BLOCKED));

        foreach ($roles as $key => $value) {
          //grant permission for dozenz and tutor only
          if (in_array($value, array(NM_COURSES_ROLE_ADMINISTRATOR, NM_COURSES_ROLE_TUTOR))) {
            foreach($course_groups as $course_group){
              $grants["nm_stream_team"][] = $course_group->nid;
              $grants["nm_stream_course"][] = $course_group->nid;
            }
            break;
          }
        }
      }
    }
    if (_custom_general_get_node_type($ugn) == NM_COURSE_GROUP) {
      $user_groups[] = $ugn;
      $grants['nm_stream_team'][] = $ugn;
    }
  }

  //dpm($grants);
  return !empty($grants) ? $grants : array();
}


/**
 * override nm stream create, update and delete permissions
 * @param $perm
 * @param $context
 */
function nm_stream_og_user_access_alter(&$perm, $context) {

  global $user;
  $account = clone $user;

  /**
   *  Dozent and Tutor in his own course
   */
  if ($context['group']->type == NM_COURSE_GROUP) {
    $course_group = $context['group'];
    $course = node_load($course_group->og_group_ref[LANGUAGE_NONE][0]['target_id']);
    if($course_group) {
      $og_membership = og_get_membership('node', $course->nid, 'user', $account->uid);

      //$roles = og_roles('node', NM_COURSE, $og_membership->gid);
      $roles = og_get_user_roles('node', $og_membership->gid, $account->uid, true, ($og_membership->state < OG_STATE_BLOCKED));

      foreach ($roles as $key => $value) {
        //grant permission for dozenz and tutor only
        if (in_array($value, array(NM_COURSES_ROLE_ADMINISTRATOR, NM_COURSES_ROLE_TUTOR))) {
          $perm['update own ' . "nm_stream" . ' content'] = TRUE;
          //$perm['update any ' . "nm_stream" . ' content'] = TRUE;
          $perm['create ' . "nm_stream" . ' content'] = TRUE;
          $perm['delete own ' . "nm_stream" . ' content'] = TRUE;
          $perm['delete any ' . "nm_stream" . ' content'] = TRUE;
          break;
        }
      }
    }
  }
}