<?php

function nm_stream_node_access($op, $node) {
    
}

function _nm_stream_get_node_environment($stream_node) {
    $environment = array();

    // _nm_stream_get_node_environment(node_load(5342));
    $container = $stream_node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
    $context = $stream_node->field_nm_stream_context[LANGUAGE_NONE][0]['target_id'];
    $environment['context'] = node_load($context);
    $environment['context']->parent = node_load($environment['context']->og_group_ref[LANGUAGE_NONE][0]['target_id']);
    $environment['container'] = node_load($container);
    $environment['container']->parent = node_load($environment['container']->og_group_ref[LANGUAGE_NONE][0]['target_id']);
    return $environment;
    dpm($stream_node);
}

function nm_stream_node_access_records($node) {
    $grant_template = array(
        'realm' => null,
        'gid' => null,
        'grant_view' => 1,
        'grant_update' => 0,
        'grant_delete' => 0,
        'priority' => 1,
    );


    $grants = array();
    // handle the Section node itself

    if ($node->type == 'nm_stream') {
        $privacy = $node->field_nm_privacy[LANGUAGE_NONE][0]['value'];

        //always set private realm for private
        $grants[] = array(
            'realm' => 'nm_stream_private',
            'gid' => $node->uid,
            'grant_view' => 1,
            'grant_update' => 1,
            'grant_delete' => 0,
            'priority' => 1,
        );
        $node_environment = _nm_stream_get_node_environment($node);
        switch ($node_environment['context']->type) {


            /* ============= CONTEXT COURSE ================== */
            case NM_COURSE: {
                    switch ($node_environment['container']->type) {

                        /* ============= container annvid ================== */
                        case ANNVID_CONTENTTYPE: {
                                switch ($privacy) {


                                    case NM_STREAM_COURSE:
                                        $grants[] = array('realm' => 'nm_stream_course',
                                            'gid' => $node_environment['context']->nid) + $grant_template;
                                        break;
                                    case NM_STREAM_DOMAIN:
                                        $grants[] = array('realm' => 'nm_stream_domain',
                                            'gid' => $node_environment['container']->parent->nid) + $grant_template;
                                        break;
                                }
                            }
                            break;
                        /* ============= container course group ================== */
                        case NM_COURSE_GROUP: {
                                switch ($privacy) {
                                    case NM_STREAM_TEAM:
                                        $grants[] = array('realm' => 'nm_stream_team',
                                            'gid' => $node_environment['container']->nid) + $grant_template;
                                        break;

                                    case NM_STREAM_COURSE:
                                        $grants[] = array('realm' => 'nm_stream_course',
                                            'gid' => $node_environment['container']->parent->nid) + $grant_template;
                                        break;
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
                                        $grants[] = array('realm' => 'nm_stream_project',
                                            'gid' => $node_environment['container']->parent->nid) + $grant_template;
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
                                $grants[] = array('realm' => 'nm_stream_domain',
                                    'gid' => $node_environment['context']->nid) + $grant_template;
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
                                $grants[] = array('realm' => 'nm_stream_project',
                                    'gid' => $node_environment['container']->nid) + $grant_template;
                                break;
                        }
                        break;
                    }
                }
                break;
        }
    }
    return $grants;
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
	$my_lehrtexte = array();
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
       $og_membership = og_get_membership('node', $course->nid, 'user', $account->uid);
          //do not process if user is not member of this course
        if (!empty($og_membership)) {
          $roles = og_get_user_roles('node', $og_membership->gid, $account->uid, TRUE, ($og_membership->state < OG_STATE_BLOCKED));
          
          if(!empty($course->field_domain_ref[LANGUAGE_NONE][0]['target_id']))
   		    	$my_lehrtexte[] =     $course->field_domain_ref[LANGUAGE_NONE][0]['target_id'];
       	
      //give access to all coursegroups for administratos and tutors
      //course groups for instructors
      $course_groups = _section_course_get_coursegroups($course);
      if(!empty($course_groups)) {
       

     

          foreach ($roles as $key => $value) {
            //grant permission for dozenz and tutor only
            if (in_array($value, array(
              NM_COURSES_ROLE_ADMINISTRATOR,
              NM_COURSES_ROLE_TUTOR
            ))) {
              foreach ($course_groups as $course_group) {
                $grants["nm_stream_team"][] = $course_group->nid;
                $grants["nm_stream_course"][] = $course_group->nid;
              }
              break;
            }
          }
        }
      }
    }
    if (_custom_general_get_node_type($ugn) == NM_COURSE_GROUP) {
      $user_groups[] = $ugn;
      $grants['nm_stream_team'][] = $ugn;
    }
  }
  
  //lade public-lehrtexte dazu
  $my_lehrtexte = array_merge($my_lehrtexte, _section_content_get_public_domains());
  //lt auf die ich zugriff habe
  $grants['nm_stream_domain'] = $my_lehrtexte;
  

  //dpm($grants);
  return  $grants  ;
}



//@TODO move to custom general
/**
 * Holt Lehrtexte, die in Kursen als Demo-LT eingebunden sind und somit öffentlich zugänglich sind.
 * @return array
 */
function _section_content_get_public_domains() {

  $query = db_select('field_data_field_domain_demo_ref', 'dr');

  $query->condition('dr.deleted', 0, '=')
      ->distinct()
      ->orderBy('field_domain_demo_ref_target_id', 'ASC')
      ->fields('dr', array('field_domain_demo_ref_target_id'));

  $result = $query->execute();

  return $result->fetchCol();
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
   *  Dozent and Tutor in his own course;
   *  zugriff auf field_nm_attachments
   */
  if ($context['group']->type == NM_COURSE_GROUP) {
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
  }
}