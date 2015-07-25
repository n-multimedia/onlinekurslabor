<?php
/**
 * Created by PhpStorm.
 * User: Sergej
 * Date: 25.07.2015
 * Time: 12:16
 */

/* Implements hook_node_access_records().
*/
function section_projects_node_access_records($node) {
  $grants =  array();

  //project specific entries
  //ca, doc, objective
  if (in_array($node->type,
    array(NM_PROJECTS_DOKUMENTATION, NM_PROJECTS_KOOPERATIONSVEREINBARUNG, NM_PROJECTS_ZIELVEREINBARUNG))) {
    $grants[] = array(
      'realm' => 'section_projects_ca',
      'gid' => $node->nid,
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
      'priority' => 1,
    );
  }

  //Blog entries
  if($node->type === NM_PROJECTS_TAGEBUCH) {
    $privacy = NULL;
    if(!empty($node->field_nm_privacy)) {
      $privacy = $node->field_nm_privacy['und'][0]['value'];

    }
    if(!$privacy) {
      return $grants;
    }

    switch ($privacy) {
      case NM_STREAM_PRIVATE:

        $grants[] = array(
          'realm' => 'section_projects_nm_stream_private',
          'gid' => $node->uid,
          'grant_view' => 1,
          'grant_update' => 1,
          'grant_delete' => 1,
          'priority' => 1,
        );
        break;
      case NM_STREAM_TEAM:

        $context_nid = $node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        $context_type = _custom_general_get_node_type($context_nid);
        switch ($context_type) {
          case NM_PROJECTS_KOOPERATIONSVEREINBARUNG:

            $grants[] = array(
              'realm' => 'section_projects_nm_stream_team',
              'gid' => $context_nid,
              'grant_view' => 1,
              'grant_update' => 0,
              'grant_delete' => 0,
              'priority' => 1,
            );
            break;
        }
        break;

      case NM_STREAM_PROJECT:
        $context_nid = $node->og_group_ref[LANGUAGE_NONE][0]['target_id'];
        $context_type = _custom_general_get_node_type($context_nid);
        switch ($context_type) {
          case NM_PROJECTS_KOOPERATIONSVEREINBARUNG:

            $grants[] = array(
              'realm' => 'section_projects_nm_stream_project',
              'gid' => $context_nid,
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
          'realm' => 'section_projects_nm_stream_public',
          'gid' => 1,
          'grant_view' => 1,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 1,
        );
        break;
      default:
        //private
        break;
    }
  }
  return $grants;
}


/* Implements hook_node_grants().
*/
function section_projects_node_grants($account, $op) {

  $grants = array();

  //private for every option
  $grants['section_projects_nm_stream_private'][] = $account->uid;

  if ($op != 'view') {
    return $grants;
  }


  //grant access to users concerning all blog entries published to the whole project
  //course -> course-group -> cooperation agreement

  if(in_array(NM_ROLE_STUDENT , $account->roles) || in_array(NM_ROLE_DOZENT , $account->roles)) {
    $cas = _section_projects_get_all_cooperation_agreements();
    if(!empty($cas)) {
      foreach ($cas as $key => $ca) {
        $ca = node_load($ca->nid);
        //STUDENTS ONLY
        if(in_array(NM_ROLE_STUDENT , $account->roles)) {
          if(_section_projects_seal_user_is_responsible_student($account, $ca)) {
            $grants['section_projects_nm_stream_project'][] = $ca->nid;
            //grant access for ca and its content
            $grants['section_projects_ca'][] = $ca->nid;
          }

          if (!empty($ca->field_ca_course_group_ref)) {
            $course_group_nid = $ca->field_ca_course_group_ref[LANGUAGE_NONE][0]['target_id'];
            $course_group = node_load($course_group_nid);
            $course_nid = $course_group->og_group_ref[LANGUAGE_NONE][0]['target_id'];
            $course = node_load($course_nid);
            //get users course group in course
            if (_section_courses_get_coursegroup_gid($account->uid, $course) == $course_group_nid) {
              $grants['section_projects_nm_stream_team'][] = $ca->nid;
              //grant access for ca and its content
            }
          }
        }

        //DOZENT ONLY
        if(in_array(NM_ROLE_DOZENT, $account->roles)) {
          if(_section_projects_seal_user_is_responsible_dozent($account, $ca)) {
            $grants['section_projects_nm_stream_team'][] = $ca->nid;
          }
        }


      }
    }
  }else if(in_array(NM_ROLE_DOZENT , $account->roles)){
    $cas = _section_projects_get_all_cooperation_agreements($account);
    if(!empty($cas)){
      foreach ($cas as $key => $ca) {
        $ca = node_load($ca->nid);
        if(_section_projects_seal_user_is_responsible_dozent($account, $ca)) {
          $grants['section_projects_nm_stream_project'][] = $ca->nid;
        }
      }
    }
  }else if(in_array(NM_ROLE_KOOPERATIONSPARTNER , $account->roles)) {
    $cas = _section_projects_get_all_cooperation_agreements($account);
    if(!empty($cas)){
      foreach ($cas as $key => $ca) {
        $ca = node_load($ca->nid);
        if(_section_projects_seal_user_is_responsible_kooperationspartner($account, $ca)) {
          $grants['section_projects_nm_stream_project'][] = $ca->nid;
        }
      }
    }
  }

  //cooperation partners

  return $grants;
}



//TODO Permissions einbauen!
function section_projects_og_user_access_alter(&$perm, $context) {

  global $user;
  $account = clone $user;


  //Dozent
  //04.12.2014 - 18:15 - SN todo check context first
  //may dozent do all those things in this group?!!!! !!!IMPORTANT
  if(in_array(NM_ROLE_DOZENT, $account->roles)) {




    //must NOT edit any objectives
    $perm['update any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = FALSE;
    $perm['create ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = FALSE;
    $perm['delete any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = FALSE;
    $perm['delete own ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = FALSE;

    //$perm['create ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
    $perm['update any ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE; // dangerous here 04.12.2014 - 18:23 - SN context need to be checked
  }

  /*
   * ===============================
   * IMPORTANT
   * @TODO
   *  bei Student hats was mit den Berechtigungschecks verhauen. Überprüfen!!
   * IMPORTANT
   * =====================================
   */
  if(in_array(NM_ROLE_STUDENT, $account->roles)) {
    //must NOT edit any objectives
    $perm['update any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
    $perm['create ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
    $perm['delete any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
    $perm['delete own ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;

    //view
    $perm['view field_objective_task field'] = TRUE;
    $perm['view field_objective_motivation field'] = TRUE;
    $perm['view field_ca_ref field'] = TRUE;
    $perm['view field_objective_matching field'] = TRUE;

    //edit
    $perm['update any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
    $perm['update field_objective_motivation field'] = TRUE;
    $perm['update field_objective_matching field'] = TRUE;
    $perm['update field_objective_task field'] = TRUE;

    /* studenten, die auf dokumentation zugeifen dürfne,. dürfen auch die felder editieren */
    /* todo kein zugriff auf wysiwyg */
    $perm['create ' . NM_PROJECTS_DOKUMENTATION . ' content'] = true;
    $perm['update any ' . NM_PROJECTS_DOKUMENTATION . ' content'] = true;
    $perm['update body field'] = true;





    /* studenten, die auf lernzielvereinbarungen zugeifen dürfne,. dürfen auch die felder editieren */
    if(node_access('view',$context['group']))
    {
      $perm['update any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = true;
      $perm['update field_objective_motivation field'] = true;
      $perm['update field_objective_matching field'] = true;
      $perm['update field_objective_task field'] = true;
    }

    //blog eintrag erstellen
    $perm['create projects_blog content'] = true;
    $perm['update field_nm_privacy field'] = true;
    $perm['create field_blog_type content'] = true;
    $perm['update field_blog_type field'] = true;
    //    $perm['create field_blog_type content'] = true;
    //    $perm['view field_blog_type field'] = true;
    //     $perm['update body field'] = true;

//   /*


  }






  return $perm;


}



/*
function section_projects_field_access($op, $field, $entity_type, $entity, $account) {
return true;
}*/
/**
 * Implements hook_node_access().
 */

function section_projects_node_access($node, $op, $account) {

  //DOZENT
  //deny create permission, to objective
  if(in_array(NM_ROLE_DOZENT , $account->roles)) {
    if($node == 'projects_objective' ||  (is_object($node) && $node->type == 'projects_objective')) {
      return NODE_ACCESS_DENY;
    }
  }

  //STUDENT
  if(in_array(NM_ROLE_STUDENT , $account->roles)) {
    if($node == 'projects_objective' ||  (is_object($node) && $node->type == 'projects_objective')) {
      return NODE_ACCESS_ALLOW; //@todo need to check context!!!! but ok for the prototype!!
    }
  }


  if(!is_object($node) || $node->nid == 0) {
    return NODE_ACCESS_IGNORE;
  }

  if($node->type != 'projects_cooperation_agreement' && $node->type != 'projects_objective' ) {
    return NODE_ACCESS_IGNORE;
  }


  $signing_state = @$node->field_seal;
  $signing_state = (int) ($signing_state['und'][0]['value']);
  $signatures = array();
  if (($signing_state & bindec('100')) == bindec('100'))
    $signatures[] = 'dozent';
  if (($signing_state & bindec('010')) == bindec('010'))
    $signatures[] = 'student';
  if (($signing_state & bindec('001')) == bindec('001'))
    $signatures[] = 'partner';
  if (
    // The $node argument can be either a $node object or a machine name of
    // node's content type. It is called multiple times during a page load
    // so it is enough if you perform the check once you get the object.
    is_object($node)
    &&
    ( ($node->type == 'projects_cooperation_agreement') && (count($signatures)==3)
      ||  ($node->type == 'projects_objective')  && (count($signatures)==2  ))
    // Operation on which you want to act: "create", "delete", "update", "view".
    && ( $op == 'update'
      || $op =='delete'
    )

  ) {
    // Check if the node is published.
    { //das würde dann auch beim view auslösen. deshalb nicht anzeigen...
      #drupal_set_message('Dies kann nicht bearbeitet werden, da bereits alle Beteiligten unterschrieben haben.','warning');

      return NODE_ACCESS_DENY;
    }
  }

  return NODE_ACCESS_IGNORE;
}

function rrtt(){
  dpm('123 test');
}