<?php


/**
 * Implements hook_node_access_records().
 */
/*
function section_courses_node_access_records($node) {
  
  $grants = _section_courses_node_access_records_domain($node);
  
  return !empty($grants) ? $grants : array();
}
 * 
 */

/*
 * access records for DOMAIN Nodes
 */
/*
function _section_courses_node_access_records_domain($node){
  $cids = array();
  
  // handle the Section node itself
  if ($node->type == NM_DOMAIN) {
    $cids[] = $node->nid;
  }

  // Now handle pages within the Section
  else if ($node->type == NM_CHAPTER && !empty($node->{OG_AUDIENCE_FIELD})) {
    foreach ($node->{OG_AUDIENCE_FIELD}[LANGUAGE_NONE] as $entity_ref) {
      $section = node_load($entity_ref['target_id']);
      $cids[] = $entity_ref['target_id'];
    }
  }
  if (empty($cids)) {
    return array();
  }
  foreach ($cids as $cid) {
    $grants[] = array(
      'realm' => NM_DOMAIN_ACCESS_REALM,
      'gid' => $cid,
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
      'priority' => 0,
    );
  }
  return array();
  
  return !empty($grants) ? $grants : array();
}*/
/*
function section_courses_node_grants($account, $op) {
  
  $active_course = _section_courses_get_active_course();
  if ($active_course) {
    $domain_ref = $active_course->field_domain_ref[LANGUAGE_NONE][0]['target_id'];

    $grants[NM_DOMAIN_ACCESS_REALM][] = $domain_ref;
  }else if(user_access("bypass node access")  || user_access("access content"))
  {
   
    //todo
    //not to deny access to anything
    $grants[NM_DOMAIN_ACCESS_REALM] = custom_general_node_ids_by_type(NM_DOMAIN);
    
  }


  return !empty($grants) ? $grants : array();
}
 * 
 * 
 */