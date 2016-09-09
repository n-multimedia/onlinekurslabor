<?php

/**
 * Expose organic groups group types as a context condition.
 */
class custom_general_condition_section_content extends context_condition {

  function condition_values() {
     foreach (node_type_get_types() as $type) {
      if (og_is_group_type('node', $type->type)) {
      $values[$type->type] = $type->name;
      }
      }
      return $values; 
  }
  /*
  function options_form($context) {
    $defaults = $this->fetch_from_context($context, 'options');
    return array(
      'node_form' => array(
        '#title' => t('Set on node form'),
        '#type' => 'checkbox',
        '#description' => t('Set this context on node forms'),
        '#default_value' => isset($defaults['node_form']) ? $defaults['node_form'] : TRUE,
      ),
    );
  }*/

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
    $context = current($this->get_contexts(NM_CONTENT_DOMAIN));

    //22.04.2013 - 17:21 - SN additional check
    if ($this->_section_content_active()) {
      $this->condition_met($context, NM_CONTENT_DOMAIN);
    }
  }

  
  
  //22.04.2013 - 23:50 - SN
  //helper function - special cases when Section Content should be active
  function _section_content_active() {
    //$group = og_context();

    $node = menu_get_object();
    
    $ui_active = _section_domain_author_section_active();


    $domain_overview_active = (isset($node) && $node->nid == NM_DOMAIN_OVERVIEW_ID) ? TRUE : FALSE;
       
    $section_content = $domain_overview_active || $ui_active;

    if ($section_content) {
      return TRUE;
    }

    return FALSE;
  }

}
