<?php

/**
 * see annvid_node_access($node, $op, $account) too!
 */


/**
 * Hook: setzt die locks auf einen node des typs nm_stream
 * @param StdClass $node
 * @return array $records
 */
function nm_stream_node_access_records($node) {
  $record_template_view = [
    'realm' => null,
    'gid' => null,
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
    'priority' => 1,
  ];

  $record_template_update = [
    'realm' => null,
    'gid' => null,
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 0,
    'priority' => 1,
  ];

  $record_template_delete = [
    'realm' => null,
    'gid' => null,
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 1,
    'priority' => 1,
  ];
  //neuer realm zusätzlich zu den normalen.
  // Gewährt Lehrpersonen Zugriff auf Streams ohne alle einzelnen Kursgruppen durchzugehen
  //spart bis zu 30%
  $record_template_teacher_stream =  [
   'realm' => 'nm_stream_teacher_permission',
   'gid' => null,
   'grant_view' => 1,
   'grant_update' => 0,
   'grant_delete' => 1,
   'priority' => 1
  ];
  
  

  $records = [];
  // handle the Section node itself

  if ($node->type == 'nm_stream') {
    $privacy = $node->field_nm_privacy[LANGUAGE_NONE][0]['value'];

    //always set private realm for private
    $records[] = [
      'realm' => 'nm_stream_private',
      'gid' => $node->uid,
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
      'priority' => 1,
    ];
    $node_environment = _nm_stream_get_node_environment($node);
    switch ($node_environment['context']->type) {


      /* ============= CONTEXT COURSE ================== */
      case NM_COURSE: {
        switch ($node_environment['container']->type) {

          /* ============= container annvid ================== */
          case ANNVID_CONTENTTYPE: {
            switch ($privacy) {


              case NM_STREAM_COURSE:
                $records[] = [
                    'realm' => 'nm_stream_course',
                    'gid' => $node_environment['context']->nid,
                  ] + $record_template_view;
                $records[] = [
                    'realm' => 'nm_stream_course_update',
                    'gid' => $node_environment['context']->nid,
                  ] + $record_template_update;
                $records[] = [
                    'realm' => 'nm_stream_course_delete',
                    'gid' => $node_environment['context']->nid,
                  ] + $record_template_delete;
                break;
              case NM_STREAM_DOMAIN:
                $records[] = [
                    'realm' => 'nm_stream_domain',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_view;
                $records[] = [
                    'realm' => 'nm_stream_domain_update',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_update;
                $records[] = [
                    'realm' => 'nm_stream_domain_delete',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_delete;
                break;
            }
          }
            break;
          /* ============= container course group ================== */
          case NM_COURSE_GROUP: {
            switch ($privacy) {
              case NM_STREAM_TEAM:
                $records[] = [
                    'realm' => 'nm_stream_team',
                    'gid' => $node_environment['container']->nid,
                  ] + $record_template_view;
                $records[] = [
                    'realm' => 'nm_stream_course_update',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_update;
                $records[] = [
                    'realm' => 'nm_stream_course_delete',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_delete;
                
     
                break;

              case NM_STREAM_COURSE:
                $records[] = [
                    'realm' => 'nm_stream_course',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_view;
                $records[] = [
                    'realm' => 'nm_stream_course_update',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_update;
                $records[] = [
                    'realm' => 'nm_stream_course_delete',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_delete;
                break;
            }
             //in any case: add a new realm for dozent / tutor
            // except stream entry is private
              if ($privacy != NM_STREAM_PRIVATE) {                      
                                    $records[] = [
                                        'gid' => $node_environment['container']->parent->nid,
                                            ] + $record_template_teacher_stream;
                                }
            }
            break;
          /* ============= container koop agreement ================== */
          case NM_PROJECTS_KOOPERATIONSVEREINBARUNG: {
            switch ($privacy) {

              case NM_STREAM_TEAM:
                dpm("TODO JSFOIJH wie komm ich hier an coursegroup?");
                break;

              case NM_STREAM_PROJECT:
                $records[] = [
                    'realm' => 'nm_stream_project',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_view;
                $records[] = [
                    'realm' => 'nm_stream_project_update',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_update;
                $records[] = [
                    'realm' => 'nm_stream_project_delete',
                    'gid' => $node_environment['container']->parent->nid,
                  ] + $record_template_delete;
                break;
            }
          }
            break;
        }
      }
        break;
      /* ============= CONTEXT DOMAIN ================== */
      case NM_CONTENT_DOMAIN: {
        /* ============= container annvid ================== */
        if ($node_environment['container']->type == ANNVID_CONTENTTYPE) {

          switch ($privacy) {
            case NM_STREAM_DOMAIN:
              $records[] = [
                  'realm' => 'nm_stream_domain',
                  'gid' => $node_environment['context']->nid,
                ] + $record_template_view;
              $records[] = [
                  'realm' => 'nm_stream_domain_update',
                  'gid' => $node_environment['context']->nid,
                ] + $record_template_update;
              $records[] = [
                  'realm' => 'nm_stream_domain_delete',
                  'gid' => $node_environment['context']->nid,
                ] + $record_template_delete;
              break;
          }
        }
      }
        break;
      /* ============= CONTEXT PROJECT ================== */
      case NM_PROJECTS_PROJEKTVORSCHLAG: {
        /* ============= container koop agreement ================== */
        if ($node_environment['container']->type == NM_PROJECTS_KOOPERATIONSVEREINBARUNG) {

          switch ($privacy) {

            case NM_STREAM_PROJECT:
              $records[] = [
                  'realm' => 'nm_stream_project',
                  'gid' => $node_environment['container']->nid,
                ] + $record_template_view;
              $records[] = [
                  'realm' => 'nm_stream_project_update',
                  'gid' => $node_environment['container']->nid,
                ] + $record_template_update;
              $records[] = [
                  'realm' => 'nm_stream_project_delete',
                  'gid' => $node_environment['container']->nid,
                ] + $record_template_delete;
              break;
          }
          break;
        }
      }
        break;
    }
  }
  return $records;
}

/**
 * Implements hook_node_grants().
 * setzt die schlüssel fuer oben gesetzten locks
 */
function nm_stream_node_grants($account, $op) {

  /*
  if ($op != 'view') {
    return;
  }*/
  //speedup by 40% using static cache  
  $grants = &drupal_static(__FUNCTION__);
  if (isset($grants)) {
      return $grants;
  }  
  $grants = [];
  $my_lehrtexte = [];


  $grants['nm_stream_private'][] = $account->uid;
  $grants['nm_stream_public'][] = 1;

  //get users organic_groups
  $user_group_nids = og_get_groups_by_user($account, 'node');

  if (!empty($user_group_nids)) {
    //dpm($account->uid);
    $user_courses = [];
    $user_groups = [];
    foreach ($user_group_nids as $ugn) {
      if (_custom_general_get_node_type($ugn) == NM_COURSE) {
        $user_courses[] = $ugn;
        $grants['nm_stream_course'][] = $ugn;

        $course = node_load($ugn);
        $og_membership = og_get_membership('node', $course->nid, 'user', $account->uid);
        //do not process if user is not member of this course
        if (!empty($og_membership)) {
          $roles = og_get_user_roles('node', $og_membership->gid, $account->uid, TRUE, ($og_membership->state < OG_STATE_BLOCKED));

          if (!empty($course->field_domain_ref[LANGUAGE_NONE][0]['target_id'])) {
            $my_lehrtexte[] = $course->field_domain_ref[LANGUAGE_NONE][0]['target_id'];
          }

          //give access to all coursegroups for administratos and tutors
          //course groups for instructors
          //nicht mehr nötig wegen extra-realm
          //$course_groups = _section_course_get_coursegroups($course);

          foreach ($roles as $key => $value) {
            //grant permission for dozenz and tutor only
            if (in_array($value, [
              NM_COURSES_ROLE_ADMINISTRATOR,
              NM_COURSES_ROLE_TUTOR,
            ])) {
              $grants['nm_stream_course_delete'][] = $ugn;
              $grants['nm_stream_teacher_permission'][] = $ugn;
            }
          }

        }
      }
      if (_custom_general_get_node_type($ugn) == NM_COURSE_GROUP) {
        $user_groups[] = $ugn;
        $grants['nm_stream_team'][] = $ugn;
      }
 

      //bin als TN in einem Lehrtext eingetragen
      if (_custom_general_get_node_type($ugn) == NM_CONTENT_DOMAIN) {
        $my_lehrtexte[] = $ugn;

        $og_membership = og_get_membership('node', $ugn, 'user', $account->uid);
        //if user is member in a domain (lehrtext) -> he or she is the author
        //and may moderate the stream entries
        if(!empty($og_membership)) {
          $grants['nm_stream_domain_update'][] = $ugn;
          $grants['nm_stream_domain_delete'][] = $ugn;
        }

      }
    }
  }

  //lade public-lehrtexte dazu
  $my_lehrtexte = array_merge($my_lehrtexte, _section_content_get_public_domains());
  //lt auf die ich zugriff habe
  $grants['nm_stream_domain'] = $my_lehrtexte;


  return $grants;
}


/**
 * override nm stream create, update and delete permissions
 * @param $perm
 * @param $context
 * also see annvid_og_user_access_alter()
 */
function nm_stream_og_user_access_alter(&$perm, $context) {

  global $user;
  $account = clone $user;

  /**
   *  Dozent and Tutor in his own course;
   *  zugriff auf field_nm_attachments
   */
  if ($context['group']->type == NM_COURSE_GROUP) {
    /*$perm['update own ' . "nm_stream" . ' content'] = FALSE;
    $perm['update any ' . "nm_stream" . ' content'] = FALSE;
    $perm['create ' . "nm_stream" . ' content'] = FALSE;
    $perm['delete own ' . "nm_stream" . ' content'] = FALSE;
    $perm['delete any ' . "nm_stream" . ' content'] = FALSE;
    $perm['view field_nm_attachments field'] = FALSE;

    //create wird in nm_stream_node_access gesetzt
    $perm['create ' . "nm_stream" . ' content'] = TRUE;*/

  }


    /* {
    $course_group = $context['group'];
    $course = node_load($course_group->og_group_ref[LANGUAGE_NONE][0]['target_id']);
    if($course_group) {
      $og_membership = og_get_membership('node', $course->nid, 'user', $account->uid);

      //do not process if user is not member of this course
      if (!empty($og_membership)) {
        //erlaube uneingeschränkt zugriff auf das field; permission auf den stream selbst wird ja separat geregelt
        $perm['view field_nm_attachments field'] = true;
        $roles = og_get_user_roles('node', $og_membership->gid, $account->uid, TRUE, ($og_membership->state < OG_STATE_BLOCKED));

        foreach ($roles as $key => $value) {
          //grant permission for dozenz and tutor only
          if (in_array($value, array(
            NM_COURSES_ROLE_ADMINISTRATOR,
            NM_COURSES_ROLE_TUTOR
          ))) {
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
  }*/
}