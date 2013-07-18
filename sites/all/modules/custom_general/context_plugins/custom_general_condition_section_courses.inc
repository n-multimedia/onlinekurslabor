<?php

/**
 * Expose organic groups group types as a context condition.
 */
class custom_general_condition_section_courses extends context_condition {

  function condition_values() {
    foreach (node_type_get_types() as $type) {
      if (og_is_group_type('node', $type->type)) {
        $values[$type->type] = $type->name;
      }
    }
    return $values;
  }

  function execute($group) {
    //$node_form = ((arg(0) == 'node') && ((is_numeric(arg(1)) && (arg(2) == 'edit')) || (arg(1) == 'add')));
    if (!empty($group) && $group['group_type'] == 'node') {
      $node = entity_load_single($group['group_type'], $group['gid']);
      $type = $node ? $node->type : '_none_'; 
     $contexts = $this->get_contexts($type);
      $this->values[$type] = array();

      foreach ($contexts as $context) {
        $options = $this->fetch_from_context($context, 'options');
        // The condition is met unless we are looking at a node form
        // and the "Set on node form" option is unchecked.
        //if (!$node_form || !empty($options['node_form'])) {
        $this->condition_met($context, $type);
        //}
      }
    }
  }
  
  /*
   * Additional execute without param
   */
  function execute2() {
    $context = current($this->get_contexts(NM_COURSE));
    //22.04.2013 - 17:21 - SN additional check
    if ($this->_section_courses_active()) {
      $this->condition_met($context, NM_COURSE);
    }
  }
  
  //22.04.2013 - 23:50 - SN
  //helper function - special cases when Section Content should be active
  function _section_courses_active() {
    $group = og_context();

    $node = menu_get_object();
    
    $ui_active = _section_course_instructor_section_active();
    
    $course_overview_active = (isset($node) && $node->nid == NM_COURSES_OVERVIEW_ID) ? TRUE : FALSE;
       

    $section_content = $course_overview_active || $ui_active;

    if ($section_content) {
      return TRUE;
    }

    return FALSE;
    
  }

}
