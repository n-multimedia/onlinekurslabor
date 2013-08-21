<?php

function _course_tasks_generic_init_view() {
  $tasks_nid = _course_tasks_generic_get_task_nid();

  $field_val = NULL;
  if (!empty($tasks_nid)) {
    $node_wrapper = entity_metadata_wrapper('node', $tasks_nid);

    $field_val = $node_wrapper->field_generic_task_entry->value();

    // Update the history table, stating that this user viewed this node.
    node_tag_new(node_load($tasks_nid));
  }



  return $field_val;
}

function _course_tasks_generic_get_task_nid() {
  $tasks_nid = arg(3);
  if (empty($tasks_nid) || !is_numeric($tasks_nid)) {
    return array();
  }
  return $tasks_nid;
}

function _course_tasks_generic_tips_view() {

  global $user;

  $field_val = _course_tasks_generic_init_view();

  if (empty($field_val))
    return;

  $output = "";


  //prepend workflow form
  //get workflow form
  //$output .= "<h2>Status</h2>";
  $task_nid = _course_tasks_generic_get_task_nid();
  $solutions = custom_general_get_task_solutions($task_nid, $user->uid);
  $solution_node = NULL;
  if (count($solutions) > 0) {

    $solution = current($solutions);
    $solution_node = node_load($solution->nid);

    $output .=_course_tasks_generic_solution_workflow_form($solution_node);
  }
  //prepend workflow form - end


  $output .= _course_tasks_generic_section_view($field_val, NM_COURSES_TASK_TIPS);

  // moving this part to the right sidebar!
  //allow assessment if node is in state 3
  $current = workflow_node_current_state($solution_node);


  if ($current == 3) {
    if (array_intersect(array(NM_ROLE_ADMIN, NM_ROLE_DOZENT), $user->roles)) {
      //add bewertung feld
      $form = drupal_get_form('_section_courses_task_solution_assesment_form', $solution_node->nid);
      $form['assessment']['format']['#attributes']['style'] = 'display:none';
      $output .= drupal_render($form);
    }
    else {
      $output .= '<div class="alert alert-warning">';
      $output .= "<h2>Bewertung</h2>";
      $output .= "Sie haben Ihre Lösung eingereicht. <br /> Bisher wurde wurde noch kein Feedback abgegeben.";
      $output .= '</div>';
    }
  }
  //Bewertet
  else if (($current == 4)) {
    $output .= '<div class="alert alert-success">';
    $output .= "<h2>Bewertung</h2>";
    //$assessment_field = ($solution_wrapper->field_generic_task_assessment->value());
    $fview = field_view_field('node', $solution_node, 'field_generic_task_assessment');
    //hide field label
    $fview['#label_display'] = 'hidden';
    $output .= render($fview);
    //$output .= $assessment_field['value'];
    $output .= '</div>';
  }

  return $output;
}

function _course_tasks_generic_solution_workflow_form($node) {

  $output = "";

  $workflow = workflow_get_workflow_type_map_by_type($node->type);
  if (!$workflow) {
    return;
  }

  $states = array();
  foreach (workflow_get_workflow_states() as $data) {
    $states[$data->sid] = check_plain(t($data->state));
  }

  $current = workflow_node_current_state($node);

  // Show current state at the top of the node display.
  //$markup = theme('workflow_current_state', array('state' => $states[$current]));

  $markup = _courses_tasks_solution_workflow_label($node->nid);

  //$output .= $markup;
  // If we are at the terminal state, then don't show the change form.
  $choices = workflow_field_choices($node);
  if (count($choices) == 1) {
    if ($current == key($choices)) {
      return $output;
    }
  }
  // Show state change form at the bottom of the node display.
  $form_state = array('cache' => TRUE);
  form_load_include($form_state, 'inc', 'workflow', 'workflow.pages');
  $form = drupal_get_form('workflow_tab_form', $node, $workflow->wid, $states, $current);
  $form['#weight'] = 99;

  //rename and style in workflow form
  /*
    if (isset($form['workflow']['buttons']['submit_to_Eingereicht'])) {
    $form['workflow']['buttons']['submit_to_Eingereicht']['#value'] = "Einreichen";
    $form['workflow']['buttons']['submit_to_Eingereicht']['#attributes'] = array('class' => array('btn btn-info'));
    } */

  $form['workflow']['#title'] = "";

  $output .= drupal_render($form);

  return $output;
}

/**
 * get the workflow state label of a task
 * 
 * @param type $tid
 * @return string
 */
function _courses_tasks_solution_workflow_label($sid = 0) {
  $node = node_load($sid);

  $current = workflow_node_current_state($node);

  $markup = "";
  if ($current == NM_COURSES_TASK_WORKFLOW_DRAFT || $sid == 0) {
    $markup = '<span class="label">Entwurf</span>';
  }
  elseif ($current == NM_COURSES_TASK_WORKFLOW_SUBMITTED) {
    $markup = '<span class="label label-info">Eingereicht</span>';
  }
  elseif ($current == NM_COURSES_TASK_WORKFLOW_ASSESSED) {
    $markup = '<span class="label label-success"><strong>Bewertet</strong></span>';
  }

  return $markup;
}

/**
 * checks if a solution is editable
 * a solution is not editable any more when the node reaches a special workflow state
 * 
 * @param type $node
 * @return boolean
 */
function _courses_tasks_generic_solution_is_editable($node) {

  $current = workflow_node_current_state($node);
  //if state >= Entwurf
  if ($current >= 3) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Description section of a taks on the top of the content
 * 
 * @return type
 */
function _course_tasks_generic_description_view() {

  global $user;

  $field_val = _course_tasks_generic_init_view();

  $task_nid = _course_tasks_generic_get_task_nid();
  if (!is_numeric($task_nid))
    return;

  $task = node_load($task_nid);

  if (empty($field_val))
    return;

  $solutions = custom_general_get_task_solutions($task->nid, $user->uid);

  //get default label first (draft)
  $label = _courses_tasks_solution_workflow_label(0);
  if (count($solutions) > 0) {
    $solution = current($solutions);
    $label = _courses_tasks_solution_workflow_label($solution->nid);
  }

  $output = "";
  $output .= '<div class="alert alert-info">';
  $output .= "<h1>" . $task->title . ' ' . $label . "</h1>";
  $output .= '</div>';
  $output .= '<div class="alert alert-info">';
  $output .= _course_tasks_generic_section_view($field_val, NM_COURSES_TASK_DESCRIPTION);
  $output .= _course_tasks_generic_section_view($field_val, NM_COURSES_TASK_TASK);
  $output .= '</div>';

  return $output;
}

function _course_tasks_generic_solution_form_view() {

  global $user;
  //attach needed feeds here only
  //module_load_include('inc', 'node', 'node.pages');
  //$form2 = node_add('courses_generic_task_solution');
  //$output = "";
  //$form['#title_display'] = 'invisible';
  //$form['title']['#type'] = 'hidden';
  //dpm($form2);

  $output = "";
  $task_nid = arg(3);

  if (!$task_nid || !is_numeric($task_nid))
    return;

  $solutions = custom_general_get_task_solutions($task_nid, $user->uid);
  //check workflow state
  if (count($solutions) > 0 && !_courses_tasks_generic_solution_is_editable(current($solutions))) {

    //Es wurden mehrere Lösungen parallel eingegeben
    //[todo ]merge solutions into 1 file ? 
    if (count($solutions) > 1) {
      watchdog('COURSES_SOLUTION', "Für die Aufgabe %id existieren mehrere Lösungen", array('%id' => $task_nid), WATCHDOG_ALERT);
    }

    $solution = current($solutions);
    $solution_node = node_load($solution->nid);

    $node_wrapper = entity_metadata_wrapper('node', $task_nid);

    $field_val = $node_wrapper->field_generic_task_entry->value();
    $description_items = _course_tasks_generic_get_section($field_val, NM_COURSES_TASK_FORM);

    //$solution_wrapper = entity_metadata_wrapper('node', $solution_node->nid);
    //$solutions_field_vals = $solution_wrapper->field_generic_solution_entry->value();
    $solutions_field_vals = field_get_items('node', $solution_node, 'field_generic_solution_entry');
    $fview = field_view_field('node', $solution_node, 'field_generic_solution_entry', $solutions_field_vals);

    foreach ($description_items as $key => $item) {
      $output .= "<h3>" . $item['second'] . "</h3>";
      //$output .= $solutions_field_vals[$key]['value'];

      $output .= render($fview[$key]);
    }
    /* moving this part to the right sidebar!
     * 
      //allow assessment if node is in state 3
      $current = workflow_node_current_state($solution_node);


      if ($current == 3 && array_intersect(array(NM_ROLE_ADMIN, NM_ROLE_DOZENT), $user->roles)) {
      //add bewertung feld
      $form = drupal_get_form('_section_courses_task_solution_assesment_form', $solution_node->nid);
      $form['assessment']['format']['#attributes']['style'] = 'display:none';
      $output .= drupal_render($form);
      }
      //Bewertet
      else if (($current == 4)) {
      $output .= "<h2>Bewertung</h2>";
      //$assessment_field = ($solution_wrapper->field_generic_task_assessment->value());
      $fview = field_view_field('node', $solution_node, 'field_generic_task_assessment');
      //hide field label
      $fview['#label_display'] = 'hidden';
      $output .= render($fview);
      //$output .= $assessment_field['value'];
      }
     * 
     */
  }
  else {
    //check if a solution has already been submitted
    if (count($solutions) > 0) {
      $solution = current($solutions);
      $solution_node = node_load($solution->nid);

      $solution_wrapper = entity_metadata_wrapper('node', $solution_node->nid);
      $solutions_field_vals = $solution_wrapper->field_generic_solution_entry->value();
    }

    $form = drupal_get_form('_section_courses_task_solution_form', $task_nid);
    //unset input format fieldset
    foreach ($form['solutions'] as $key => &$item) {
      if (is_array($item) && isset($item['format'])) {
        //hide available input formats
        $item['format']['#attributes']['style'] = 'display:none';
        //prefill fields
        if (count($solutions) > 0) {
          $item['value']['#value'] = $solutions_field_vals[$key]['value'];
        }
      }
    }

    $output .= drupal_render($form);
  }

  $output = '<div class="alert alert-warning">' . $output;
  $output .= '</div>';


  return $output;
}

function _section_courses_task_solution_assesment_form($form, &$form_state, $solution_nid) {
  $node_wrapper = entity_metadata_wrapper('node', $solution_nid);

  $field_val = $node_wrapper->field_generic_task_assessment->value();

  $form = array();

  $form['assessment'] = array(
    '#type' => 'text_format',
    '#title' => 'Bewertung',
    '#base_type' => 'textarea',
    '#default_value' => $field_val['value'],
    '#format' => NM_FILTER_FORMAT_FILTERED_HTML,
  );

  $form['solution_nid'] = array(
    '#type' => 'hidden',
    '#value' => $solution_nid,
  );

  //[todo] generate possible transitionbuttons automatically ?
  //temporarly - manually checking possible transitions

  $solution = node_load($solution_nid);
  $current_state = workflow_node_current_state($solution);

  switch ($current_state) {
    case NM_COURSES_TASK_WORKFLOW_SUBMITTED:
      $form['save'] = array(
        '#type' => 'submit',
        '#attributes' => array('class' => array('btn-primary')),
        '#value' => 'Speichern',
      );
      $form['save_assess'] = array(
        '#type' => 'submit',
        '#attributes' => array('class' => array('btn-success')),
        '#value' => 'Speichern und Bewerten',
      );
      $form['save_cancel_submission'] = array(
        '#type' => 'submit',
        '#attributes' => array('class' => array('btn-default')),
        '#value' => 'Speicherun und Einreichung aufheben',
      );
      break;
  }


  return $form;
}

function _section_courses_task_solution_assesment_form_submit($form, &$form_state) {
  global $user;

  $solution_nid = $form_state['values']['solution_nid'];

  $node = node_load($solution_nid);

  $node->field_generic_task_assessment[LANGUAGE_NONE][0]['value'] = $form_state['values']['assessment']['value'];
  $node->field_generic_task_assessment[LANGUAGE_NONE][0]['format'] = NM_FILTER_FORMAT_FILTERED_HTML;

  // 'node' is default,
  // Other possible values are "user" and  "taxonomy_term" 
  $node = node_submit($node); // Prepare node for saving

  node_save($node);

  //check which button was clicked
  //if save and submit was clicked, move node to submitted state
  if (isset($form_state['values']['save_assess']) && ($form_state['values']['save_assess'] == $form_state['triggering_element']['#value'])) {
    workflow_execute_transition($node, NM_COURSES_TASK_WORKFLOW_ASSESSED);
  }
  elseif (isset($form_state['values']['save_cancel_submission']) && ($form_state['values']['save_cancel_submission'] == $form_state['triggering_element']['#value'])) {
    workflow_execute_transition($node, NM_COURSES_TASK_WORKFLOW_DRAFT);
  }
}

/**
 * generate solution form for a specified task
 * 
 * @global type $user
 * @param type $form
 * @param type $form_state
 * @param type $task_nid
 * @return string
 */
function _section_courses_task_solution_form($form, &$form_state, $task_nid) {
  global $user;

  $node_wrapper = entity_metadata_wrapper('node', $task_nid);

  $field_val = $node_wrapper->field_generic_task_entry->value();
  $description_items = _course_tasks_generic_get_section($field_val, NM_COURSES_TASK_FORM);

  $form['solutions']['#tree'] = TRUE;
  foreach ($description_items as $item) {
    $form['solutions'][] = array(
      '#type' => 'text_format',
      '#title' => $item['second'],
      '#base_type' => 'textarea',
      '#format' => NM_FILTER_FORMAT_FILTERED_HTML,
    );
  }

  $form['task_nid'] = array(
    '#type' => 'hidden',
    '#value' => $task_nid,
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#attributes' => array('class' => array('btn-primary')),
    '#value' => 'Speichern',
  );

  //[todo] generate possible transitionbuttons automatically ?
  //temporarly - manually checking possible transitions
  $current_state = 0;
  $solutions = custom_general_get_task_solutions($task_nid, $user->uid);
  if (count($solutions) > 0) {
    $solution = current($solutions);
    $current_state = workflow_node_current_state($solution);
  }

  switch ($current_state) {
    //0 when no solution was submitted yet
    case 0:
    case NM_COURSES_TASK_WORKFLOW_DRAFT:
      $form['save_submit'] = array(
        '#type' => 'submit',
        '#attributes' => array('class' => array('btn-info')),
        '#value' => 'Speichern und Einreichen',
      );
      break;
  }

  return $form;
}

function _section_courses_task_solution_form_submit($form, &$form_state) {
  global $user;

  $task_nid = $form_state['values']['task_nid'];
  $solutions = custom_general_get_task_solutions($task_nid, $user->uid);
  $new_node = FALSE;
  if (count($solutions) > 0) {
    $solution = current($solutions);
    $node = node_load($solution->nid);

    $node->field_generic_solution_entry[LANGUAGE_NONE] = array();
  }
  else {
    $active_course = _section_courses_get_active_course();
    $tas_nid = $form_state['values']['task_nid'];
    $task = node_load($tas_nid);
    $node->title = 'Lösung: ' . $task->title;
    $node->type = NM_COURSE_GENERIC_TASK_SOLUTION;
    node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    $node->language = 'de'; // Or e.g. 'en' if locale is enabled
    $node->uid = $user->uid;
    $node->status = 1; //(1 or 0): published or not
    $node->promote = 0; //(1 or 0): promoted to front page
    $node->comment = 0; // 0 = comments disabled, 1 = read only, 2 = read/write
    $node->og_group_ref[LANGUAGE_NONE][0] = array('target_id' => $active_course->nid);
    $node->field_generic_task[LANGUAGE_NONE][]['target_id'] = $form_state['values']['task_nid'];
  }

  foreach ($form_state['values']['solutions'] as $item) {
    $val = $item['value'];
    $node->field_generic_solution_entry[LANGUAGE_NONE][] = array('value' => $val, 'format' => NM_FILTER_FORMAT_FILTERED_HTML);
  }


  $node = node_submit($node); // Prepare node for saving

  node_save($node);

  //check which button was clicked
  //if save and submit was clicked, move node to submitted state
  if ($form_state['values']['save_submit'] == $form_state['triggering_element']['#value']) {
    workflow_execute_transition($node, NM_COURSES_TASK_WORKFLOW_SUBMITTED, TRUE);
  }
}

function _course_tasks_generic_section_view($field_val, $id) {
  $title = "";
  switch ($id) {
    case NM_COURSES_TASK_DESCRIPTION:
      $title = "Beschreibung";
      break;
    case NM_COURSES_TASK_TASK:
      $title = "Aufgabenstellung";
      break;
    case NM_COURSES_TASK_TIPS:
      $title = "Leitfragen";
      break;
    case NM_COURSES_TASK_FORM:
      $title = "Formular";
      break;
    default:
  }
  $description_items = _course_tasks_generic_get_section($field_val, $id);
  $output = "";
  if (count($description_items) > 0) {
    $output = '<div id="task_general_' . $id . '">';
    $output .= '<h3>' . $title . '</h3>';
    foreach ($description_items as $item) {
      $output .= $item['second'];
    }

    $output .= '</div>';
  }

  return $output;
}

function _course_tasks_generic_get_section($fields, $id) {
  $result = array();
  foreach ($fields as $field) {
    if ($field['first'] == $id) {
      $result[] = $field;
    }
  }

  return $result;
}