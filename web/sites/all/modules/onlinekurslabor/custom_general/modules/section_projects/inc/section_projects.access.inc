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
  $grants = array();

  //project specific entries
  //ca, doc, objective
  if (in_array($node->type, array(
    NM_PROJECTS_DOKUMENTATION,
    NM_PROJECTS_ZIELVEREINBARUNG
  ))) {
    //set ca nid

    if (!empty($node->field_ca_ref[LANGUAGE_NONE][0]['target_id'])) {
      $ca_node_nid = $node->field_ca_ref[LANGUAGE_NONE][0]['target_id'];
      $grants[] = array(
        'realm' => 'section_projects_ca',
        'gid' => $ca_node_nid,
        'grant_view' => 1,
        'grant_update' => 0,
        'grant_delete' => 0,
        'priority' => 1,
      );
    }
  }
  if ($node->type == NM_PROJECTS_KOOPERATIONSVEREINBARUNG) {
    //set ca nid
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
  if ($node->type === NM_PROJECTS_TAGEBUCH) {
    $privacy = NULL;
    if (!empty($node->field_nm_privacy)) {
      $privacy = $node->field_nm_privacy['und'][0]['value'];

    }
    if (!$privacy) {
      return $grants;
    }

    //always set private realm for view update delete
    $grants[] = array(
      'realm' => 'section_projects_nm_stream_private',
      'gid' => $node->uid,
      'grant_view' => 1,
      'grant_update' => 1,
      'grant_delete' => 1,
      'priority' => 1,
    );

    switch ($privacy) {
      case NM_STREAM_PRIVATE:
        //always set private realm for view update delete
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


  $grants['section_projects_nm_stream_public'][] = 1;

  //grant access to users concerning all blog entries published to the whole project
  //course -> course-group -> cooperation agreement

  if (in_array(NM_ROLE_STUDENT, $account->roles) || in_array(NM_ROLE_DOZENT, $account->roles)) {
    $cas = _section_projects_get_all_cooperation_agreements();
    if (!empty($cas)) {
      foreach ($cas as $key => $ca) {
        $ca = node_load($ca->nid);
        //STUDENTS ONLY
        if (in_array(NM_ROLE_STUDENT, $account->roles)) {
          if (_section_projects_seal_user_is_responsible_student($account, $ca)) {
            $grants['section_projects_nm_stream_project'][] = $ca->nid;
            //grant access for ca and its content
            $grants['section_projects_ca'][] = $ca->nid;
          }

          if (!empty($ca->field_ca_course_group_ref[LANGUAGE_NONE][0]['target_id'])) {
            $course_group_nid = $ca->field_ca_course_group_ref[LANGUAGE_NONE][0]['target_id'];
            $course_group = node_load($course_group_nid);
            if (!empty($course_group->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
              $course_nid = $course_group->og_group_ref[LANGUAGE_NONE][0]['target_id'];
              $course = node_load($course_nid);
              //get users course group in course
              if (_section_courses_get_coursegroup_gid($account->uid, $course) == $course_group_nid) {
                $grants['section_projects_nm_stream_team'][] = $ca->nid;
                //grant access for ca and its content
              }
            }
          }
        }

        //DOZENT ONLY
        if (in_array(NM_ROLE_DOZENT, $account->roles)) {
          if (_section_projects_seal_user_is_responsible_dozent($account, $ca)) {
            $grants['section_projects_nm_stream_team'][] = $ca->nid;
            $grants['section_projects_ca'][] = $ca->nid;
            $grants['section_projects_nm_stream_project'][] = $ca->nid;
          }
        }


      }
    }
  }
  else {
    if (in_array(NM_ROLE_KOOPERATIONSPARTNER, $account->roles)) {
      $cas = _section_projects_get_all_cooperation_agreements();;
      if (!empty($cas)) {
        foreach ($cas as $key => $ca) {
          $ca = node_load($ca->nid);
          //dpm($ca->title . ' ' . $ca->nid);
          //dpm(_section_projects_seal_user_is_responsible_kooperationspartner($account, $ca));
          if (_section_projects_seal_user_is_responsible_kooperationspartner($account, $ca)) {
            $grants['section_projects_nm_stream_project'][] = $ca->nid;
            $grants['section_projects_ca'][] = $ca->nid;
          }
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
  $account = !empty($context['account'])? $context['account']: clone $user;


  /**
   *  STUDENT
   */
  if ($context['group']->type == NM_PROJECTS_KOOPERATIONSVEREINBARUNG) {
    if (in_array(NM_ROLE_STUDENT, $account->roles)) {
      if (_section_projects_seal_user_is_responsible_student($account, $context['group'])) {
        //must NOT edit any objectives
        $perm['update any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        //$perm['delete any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;

        $perm['update any ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
        $perm['delete any ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;


        //fields
        //lernzielvereinbarung
        $perm['view body field'] = TRUE;
        $perm['view field_objective_motivation field'] = TRUE;
        $perm['view field_objective_task field'] = TRUE;
        $perm['view field_objective_matching field'] = TRUE;
        $perm['view field_seal field'] = TRUE;
        $perm['view field_ca_ref field'] = TRUE;

        $perm['update body field'] = TRUE;
        $perm['update field_objective_motivation field'] = TRUE;
        $perm['update field_objective_task field'] = TRUE;
        $perm['update field_objective_matching field'] = TRUE;
        $perm['update field_seal field'] = TRUE;
        $perm['update field_ca_ref field'] = TRUE;
      }
    }


    /*
     * DOZENT
     */
    if (in_array(NM_ROLE_DOZENT, $account->roles)) {
      if (_section_projects_seal_user_is_responsible_dozent($account, $context['group'])) {
        //must NOT edit any objectives
        $perm['update any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        $perm['update own ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        $perm['delete any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;

        $perm['update any ' . NM_PROJECTS_KOOPERATIONSVEREINBARUNG . ' content'] = TRUE;
        $perm['update own ' . NM_PROJECTS_KOOPERATIONSVEREINBARUNG . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_KOOPERATIONSVEREINBARUNG . ' content'] = TRUE;
        $perm['delete any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_KOOPERATIONSVEREINBARUNG . ' content'] = TRUE;

        $perm['update any ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
        $perm['update own ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
        $perm['delete any ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;

        //$perm['update any ' . NM_PROJECTS_TAGEBUCH . ' content'] = TRUE;
        $perm['update own ' . NM_PROJECTS_TAGEBUCH . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_TAGEBUCH . ' content'] = TRUE;
        $perm['delete any ' . NM_PROJECTS_TAGEBUCH . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_TAGEBUCH . ' content'] = TRUE;

        //fields
        //kooperationsvereinbarung
        $perm['view body field'] = TRUE;
        $perm['view field_ca_timespann field'] = TRUE;
        $perm['view field_ca_expectation_academy field'] = TRUE;
        $perm['view field_ca_result field'] = TRUE;
        $perm['view field_ca_partners_role field'] = TRUE;
        $perm['view field_ca_instructors_role field'] = TRUE;
        $perm['view field_ca_cooperation_rules field'] = TRUE;
        $perm['view field_ca_course_group_ref field'] = TRUE;
        $perm['view field_ca_course_group_ref field'] = TRUE;
        $perm['view field_ca_proposal_ref field'] = TRUE;
        $perm['view field_ca_student_refs field'] = TRUE;
        $perm['view field_seal field'] = TRUE;

        $perm['update body field'] = TRUE;
        $perm['update field_ca_timespann field'] = TRUE;
        $perm['update field_ca_expectation_academy field'] = TRUE;
        $perm['update field_ca_result field'] = TRUE;
        $perm['update field_ca_partners_role field'] = TRUE;
        $perm['update field_ca_instructors_role field'] = TRUE;
        $perm['update field_ca_cooperation_rules field'] = TRUE;
        $perm['update field_ca_course_group_ref field'] = TRUE;
        $perm['update field_ca_proposal_ref field'] = TRUE;
        $perm['update field_ca_student_refs field'] = TRUE;
        $perm['update field_seal field'] = TRUE;

        //lernzielvereinbarung
        $perm['view body field'] = TRUE;
        $perm['view field_objective_motivation field'] = TRUE;
        $perm['view field_objective_task field'] = TRUE;
        $perm['view field_objective_matching field'] = TRUE;
        $perm['view field_seal field'] = TRUE;
        $perm['view field_ca_ref field'] = TRUE;

        $perm['update body field'] = TRUE;
        $perm['update field_objective_motivation field'] = TRUE;
        $perm['update field_objective_task field'] = TRUE;
        $perm['update field_objective_matching field'] = TRUE;
        $perm['update field_seal field'] = TRUE;
        $perm['update field_ca_ref field'] = TRUE;

      }
    }

    /*
     * Kooperationspartner
     */
    if (in_array(NM_ROLE_KOOPERATIONSPARTNER, $account->roles)) {
      //lernzielvereinbarung
      $perm['view body field'] = TRUE;
      $perm['view field_objective_motivation field'] = TRUE;
      $perm['view field_objective_task field'] = TRUE;
      $perm['view field_objective_matching field'] = TRUE;
      $perm['view field_seal field'] = TRUE;
      $perm['view field_ca_ref field'] = TRUE;

      //kooperationsvereinbarung
      $perm['view body field'] = TRUE;
      $perm['view field_ca_timespann field'] = TRUE;
      $perm['view field_ca_expectation_academy field'] = TRUE;
      $perm['view field_ca_result field'] = TRUE;
      $perm['view field_ca_partners_role field'] = TRUE;
      $perm['view field_ca_instructors_role field'] = TRUE;
      $perm['view field_ca_cooperation_rules field'] = TRUE;
      $perm['view field_ca_course_group_ref field'] = TRUE;
      $perm['view field_ca_course_group_ref field'] = TRUE;
      $perm['view field_ca_proposal_ref field'] = TRUE;
      $perm['view field_ca_student_refs field'] = TRUE;
      $perm['view field_seal field'] = TRUE;

    }
  }


  /**
   * Kooperationspartner
   */
  if ($context['group']->type == NM_PROJECTS_RROJEKTORGANISATION) {
    if (in_array(NM_ROLE_DOZENT, $account->roles)) {
      //Projektvorschlag
      $perm['update any ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
      $perm['update own ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
      $perm['create ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
      $perm['delete any ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
      $perm['delete own ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;

      //projektvorschlag
      $perm['view body field'] = TRUE;
      $perm['view field_proposal_status field'] = TRUE;
      $perm['view field_proposal_task_area field'] = TRUE;
      $perm['view field_proposal_timespan field'] = TRUE;
      $perm['view field_proposal_expectation  field'] = TRUE;
      $perm['view field_proposal_result field'] = TRUE;
      $perm['view field_proposal_students_role field'] = TRUE;
      $perm['view field_proposal_partners_role field'] = TRUE;
      $perm['view field_proposal_contact field'] = TRUE;
      $perm['view field_proposal_contact field'] = TRUE;
      $perm['view field_partner_organization_ref field'] = TRUE;

      $perm['update body field'] = TRUE;
      $perm['update field_proposal_status field'] = TRUE;
      $perm['update field_proposal_task_area field'] = TRUE;
      $perm['update field_proposal_timespan field'] = TRUE;
      $perm['update field_proposal_expectation  field'] = TRUE;
      $perm['update field_proposal_result field'] = TRUE;
      $perm['update field_proposal_students_role field'] = TRUE;
      $perm['update field_proposal_partners_role field'] = TRUE;
      $perm['update field_proposal_contact field'] = TRUE;
      $perm['update field_proposal_contact field'] = TRUE;
      $perm['update field_partner_organization_ref field'] = TRUE;
    }

    if (in_array(NM_ROLE_KOOPERATIONSPARTNER, $account->roles)) {
      if (_section_projects_seal_user_is_responsible_kooperationspartner($account, $context['group'])) {
        $perm['update any ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
        $perm['update own ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
        $perm['delete any ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = TRUE;

        $perm['update any ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = TRUE;
        $perm['update own ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = TRUE;
        $perm['create ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = TRUE;
        $perm['delete any ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = TRUE;
        $perm['delete own ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = TRUE;

        //fields

        //projektvorschlag
        $perm['view body field'] = TRUE;
        $perm['view field_proposal_status field'] = TRUE;
        $perm['view field_proposal_task_area field'] = TRUE;
        $perm['view field_proposal_timespan field'] = TRUE;
        $perm['view field_proposal_expectation  field'] = TRUE;
        $perm['view field_proposal_result field'] = TRUE;
        $perm['view field_proposal_students_role field'] = TRUE;
        $perm['view field_proposal_partners_role field'] = TRUE;
        $perm['view field_proposal_contact field'] = TRUE;
        $perm['view field_proposal_contact field'] = TRUE;
        $perm['view field_partner_organization_ref field'] = TRUE;

        $perm['update body field'] = TRUE;
        $perm['update field_proposal_status field'] = TRUE;
        $perm['update field_proposal_task_area field'] = TRUE;
        $perm['update field_proposal_timespan field'] = TRUE;
        $perm['update field_proposal_expectation  field'] = TRUE;
        $perm['update field_proposal_result field'] = TRUE;
        $perm['update field_proposal_students_role field'] = TRUE;
        $perm['update field_proposal_partners_role field'] = TRUE;
        $perm['update field_proposal_contact field'] = TRUE;
        $perm['update field_proposal_contact field'] = TRUE;
        $perm['update field_partner_organization_ref field'] = TRUE;

        //partnerorganisation
        $perm['view body field'] = TRUE;
        $perm['view field_operational_area field'] = TRUE;
        $perm['view field_po_short_description field'] = TRUE;
        $perm['view field_po_contact field'] = TRUE;
        $perm['view field_field_po_contact_person field'] = TRUE;

        $perm['update body field'] = TRUE;
        $perm['update field_operational_area field'] = TRUE;
        $perm['update field_po_short_description field'] = TRUE;
        $perm['update field_po_contact field'] = TRUE;
        $perm['update field_field_po_contact_person field'] = TRUE;

      }else {
        $perm['update any ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = FALSE;
        $perm['update own ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = FALSE;
        $perm['create ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = FALSE;
        $perm['delete any ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = FALSE;
        $perm['delete own ' . NM_PROJECTS_PROJEKTVORSCHLAG . ' content'] = FALSE;

        $perm['update any ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = FALSE;
        $perm['update own ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = FALSE;
        $perm['create ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = FALSE;
        $perm['delete any ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = FALSE;
        $perm['delete own ' . NM_PROJECTS_RROJEKTORGANISATION . ' content'] = FALSE;
      }
    }
  }


return;

  /*
   * ===============================
   * IMPORTANT
   * @TODO
   *  bei Student hats was mit den Berechtigungschecks verhauen. Überprüfen!!
   * IMPORTANT
   * =====================================
   */
  if (in_array(NM_ROLE_STUDENT, $account->roles)) {
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
    $perm['create ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
    $perm['update any ' . NM_PROJECTS_DOKUMENTATION . ' content'] = TRUE;
    $perm['update body field'] = TRUE;


    /* studenten, die auf lernzielvereinbarungen zugeifen dürfne,. dürfen auch die felder editieren */
    if (node_access('view', $context['group'])) {
      $perm['update any ' . NM_PROJECTS_ZIELVEREINBARUNG . ' content'] = TRUE;
      $perm['update field_objective_motivation field'] = TRUE;
      $perm['update field_objective_matching field'] = TRUE;
      $perm['update field_objective_task field'] = TRUE;
    }

    //blog eintrag erstellen
    $perm['create projects_blog content'] = TRUE;
    $perm['update field_nm_privacy field'] = TRUE;
    $perm['create field_blog_type content'] = TRUE;
    $perm['update field_blog_type field'] = TRUE;
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

  return NODE_ACCESS_IGNORE;

  //DOZENT
  //deny create permission, to objective
  if (in_array(NM_ROLE_DOZENT, $account->roles)) {
    if ($node == 'projects_objective' || (is_object($node) && $node->type == 'projects_objective')) {
      return NODE_ACCESS_DENY;
    }
  }

  //STUDENT
  if (in_array(NM_ROLE_STUDENT, $account->roles)) {
    if ($node == 'projects_objective' || (is_object($node) && $node->type == 'projects_objective')) {
      return NODE_ACCESS_ALLOW; //@todo need to check context!!!! but ok for the prototype!!
    }
  }


  if (!is_object($node) || $node->nid == 0) {
    return NODE_ACCESS_IGNORE;
  }

  if ($node->type != 'projects_cooperation_agreement' && $node->type != 'projects_objective') {
    return NODE_ACCESS_IGNORE;
  }


  $signing_state = @$node->field_seal;
  $signing_state = (int) ($signing_state['und'][0]['value']);
  $signatures = array();
  if (($signing_state & bindec('100')) == bindec('100')) {
    $signatures[] = 'dozent';
  }
  if (($signing_state & bindec('010')) == bindec('010')) {
    $signatures[] = 'student';
  }
  if (($signing_state & bindec('001')) == bindec('001')) {
    $signatures[] = 'partner';
  }
  if (
    // The $node argument can be either a $node object or a machine name of
    // node's content type. It is called multiple times during a page load
    // so it is enough if you perform the check once you get the object.
    is_object($node)
    &&
    (($node->type == 'projects_cooperation_agreement') && (count($signatures) == 3)
      || ($node->type == 'projects_objective') && (count($signatures) == 2))
    // Operation on which you want to act: "create", "delete", "update", "view".
    && ($op == 'update'
      || $op == 'delete'
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

function rrtt() {
  dpm('123 test');
}