<?php

function nm_stream_node_access($op, $node) {

}

function nm_stream_node_access_records($node) {
  $grants = array();
  // handle the Section node itself

  if ($node->type == 'nm_stream') {
    $privacy = $node->field_nm_privacy [LANGUAGE_NONE][0]['value'];
    //if ($context->type == NM_COURSE_GROUP) {

    switch ($privacy) {
      case NM_STREAM_PRIVATE:
        $grants[] = array(
          'realm' => 'all',
          'gid' => 0,
          'grant_view' => 0,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 1,
        );
        $grants[] = array(
          'realm' => 'nm_stream_private',
          'gid' => $node->uid,
          'grant_view' => 1,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 1,
        );
        break;
      case NM_STREAM_TEAM:

        $context_nid = $node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        $context_type = _custom_general_get_node_type($context_nid);
        switch ($context_type) {
          case NM_COURSE_GROUP:
            $grants[] = array(
              'realm' => 'all',
              'gid' => 0,
              'grant_view' => 0,
              'grant_update' => 0,
              'grant_delete' => 0,
              'priority' => 1,
            );
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

            $grants[] = array(
              'realm' => 'all',
              'gid' => 0,
              'grant_view' => 0,
              'grant_update' => 0,
              'grant_delete' => 0,
              'priority' => 1,
            );
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

  if ($op != 'view') {
    return;
  }
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
    }
    if (_custom_general_get_node_type($ugn) == NM_COURSE_GROUP) {
      $user_groups[] = $ugn;
      $grants['nm_stream_team'][] = $ugn;
    }
  }

  //dpm($grants);
  return !empty($grants) ? $grants : array();
}
