<?php

function _section_projects_get_all_cooperation_agreements($account = NULL){


  $result_cas = array();

  //kooperationsvereinbarungen holen, die dem proposal zugeordnet sind
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', NM_PROJECTS_KOOPERATIONSVEREINBARUNG)
      ->propertyCondition('status', 1);

  //where uid == account->uid (instructors dozenten)

  if(!empty($account)) {
      $query->propertyCondition('uid', $account->uid);
  }

  $result = $query->execute();

  if(isset($result['node'])) {
    return  $result['node'];
  }

  return NULL;
}


function _section_projects_get_cooperation_agreements($proposal, $account = NULL) {
  //04.12.2014 - 16:21 - SN
  //add caching here

  if (!$account) {
    global $user;
    $account = $user;
  }

  $result_cas = array();

  //kooperationsvereinbarungen holen, die dem proposal zugeordnet sind
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', NM_PROJECTS_KOOPERATIONSVEREINBARUNG)
      ->propertyCondition('status', 1)
      // ->propertyCondition('uid', $uid)
      ->fieldCondition('field_ca_proposal_ref', 'target_id', $proposal->nid, '=');

  $result = $query->execute();

  //dpm($result);

  if (isset($result['node'])) {
    foreach ($result['node'] as $ca) {
      $ca = node_load($ca->nid);
      $ca_course_group_ref = field_get_items('node', $ca, 'field_ca_course_group_ref');
      $ca_student_refs = field_get_items('node', $ca, 'field_ca_student_refs');

      //dpm($ca_course_group_ref);
      //dpm($ca_student_refs);

      //check if cooperation agreement is assigned to a course
      //group the active user is in
      if (!empty($ca_course_group_ref)) {
        foreach ($ca_course_group_ref as $cg) {
          $users_cgs = _section_projects_get_coursegroups($account);
          //dpm($users_cgs);
          foreach ($users_cgs as $user_cg) {
            if ($user_cg->nid == $cg['target_id']) {
              //match
              $result_cas[] = $ca;
              break 2;
            }
          }
        }
      }

      //check if cooperation agreement is assigned directly
      //to the active user
      if (!empty($ca_student_refs)) {
        foreach ($ca_student_refs as $cs) {
          if ($account->uid == $cs['target_id']) {
            //match
            $result_cas[] = $ca;
            break 1;
          }
        }
      }
    }
  }

  return $result_cas;

  //if course group is set
  //get user's course groups

  /*
   *
    //load Projektvorschlag 4
    $proposal = node_load(1427);

    _section_projects_get_cooperation_agreements($proposal);
   */

  //return isset($result['node']) ? $result['node'] : NULL;
}

/**
 * get the objective linked to a cooperation agreement
 * @param type $ca
 * @return type
 */
function _section_projects_get_objective_by_ca($ca) {

  //kooperationsvereinbarungen holen, die dem proposal zugeordnet sind
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', NM_PROJECTS_ZIELVEREINBARUNG)
      ->propertyCondition('status', 1)
      // ->propertyCondition('uid', $uid)
      ->fieldCondition('field_ca_ref', 'target_id', $ca->nid, '=');
  $result = $query->execute();

  return isset($result['node']) ? current($result['node']) : NULL;

}

/**
 * Get documentation linked to a cooperation agreement
 * @param node $ca cooperation agreement node
 * @return node
 */
function _section_projects_get_documentation_by_ca($ca) {


  //kooperationsvereinbarungen holen, die dem proposal zugeordnet sind
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', NM_PROJECTS_DOKUMENTATION)
      ->propertyCondition('status', 1)
      // ->propertyCondition('uid', $uid)
      ->fieldCondition('field_ca_ref', 'target_id', $ca->nid, '=');
  $result = $query->execute();

  return isset($result['node']) ? current($result['node']) : NULL;

}

/**
 * get course groups by user account
 * @param type $account
 * @return type
 */
function _section_projects_get_coursegroups($account) {

  $query = db_select('node', 'n');

  $query->condition('n.nid', 0, '<>')
      ->condition('n.status', 1, '=')
      ->condition('n.type', NM_COURSE_GROUP)
      ->fields('n', array('nid', 'title', 'type'))
      ->join('og_membership', 'ogm', "ogm.gid = n.nid AND  ogm.etid = :uid AND ogm.entity_type = 'user'", array(':uid' => $account->uid));

  $result = $query->execute();


  return $result->fetchAll();
}