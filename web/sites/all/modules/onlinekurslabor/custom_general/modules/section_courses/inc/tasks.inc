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
    return NULL;
  }
  return $tasks_nid;
}

function _course_tasks_generic_tips_view() {

  global $user;

  $field_val = _course_tasks_generic_init_view();

  if (empty($field_val))
    return;

  $output = "";


  //lade objekte      
  $task_nid = _course_tasks_generic_get_task_nid();
  $task_node = node_load($task_nid);
  $solutions = custom_general_get_task_solutions($task_nid, $user->uid);
  $solution_node = NULL;
  if (count($solutions) > 0) {

    $solution = current($solutions);
    $solution_node = node_load($solution->nid);   
  }



  $output .= _course_tasks_generic_section_view($field_val, NM_COURSES_TASK_TIPS);

  // moving this part to the right sidebar!
  //allow assessment if node is in state 3
  $current = workflow_node_current_state($solution_node);

  if ($current == NM_COURSES_TASK_WORKFLOW_DRAFT) {


    $fview = field_view_field('node', $solution_node, 'field_generic_task_reject_notice');
    //hide field label
    $fview['#label_display'] = 'hidden';
    if (strlen(render($fview))) {

      $output .= '<div class="alert alert-danger">';
      $output .= "<h3>Hinweis</h3>";
      $output .= "Die Lösung entsprach nicht den Vorgaben und ist zu verbessern:<hr>";
      $output .= render($fview);

      $output .= '</div>';
    }
  }
  elseif ($current == NM_COURSES_TASK_WORKFLOW_SUBMITTED) {
    if (node_access("update", $task_node)) {
      //add bewertung feld
      $form = drupal_get_form('_section_courses_task_solution_assesment_form', $solution_node->nid);
      $form['to_assess']['assessment']['format']['#attributes']['style'] = 'display:none';
      $form['to_reject']['reject_notice']['format']['#attributes']['style'] = 'display:none';
      $output .= drupal_render($form);
    }
    else {
      $output .= '<div class="alert alert-warning">';
      $output .= "<h3>Bewertung</h3>";
      $output .= "Sie haben Ihre Lösung eingereicht. <br /> Bisher wurde noch kein Feedback abgegeben.";
      $output .= '</div>';
    }
  }
  //Bewertet
  else if (($current == NM_COURSES_TASK_WORKFLOW_ASSESSED)) {
    $output .= '<div class="alert alert-success">';
    $output .= "<h3>Bewertung</h3>";
    //$assessment_field = ($solution_wrapper->field_generic_task_assessment->value());
    $fview = field_view_field('node', $solution_node, 'field_generic_task_assessment');
    //hide field label
    $fview['#label_display'] = 'hidden';
    $output .= render($fview);
    //$output .= $assessment_field['value'];
    $output .= '</div>';
    //prepend workflow form for allowed roles
    $output .= _course_tasks_generic_solution_workflow_form($solution_node);
        
        
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


    //buttons ein wenig versteckt, da irritierend
    if (!empty($form['workflow']['buttons'])) {
    $new_form_workflow = array();
    $new_form_workflow['fieldset_workflow'] = array(
      '#type' => 'fieldset',
      '#title' => t('other actions'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $new_form_workflow['fieldset_workflow']['workflow'] = $form['workflow'];
    $form['workflow'] = $new_form_workflow;
  }
  //rename and style in workflow form
    /*
      if (isset($form['workflow']['buttons']['submit_to_Eingereicht'])) {
      $form['workflow']['buttons']['submit_to_Eingereicht']['#value'] = "Einreichen";
      $form['workflow']['buttons']['submit_to_Eingereicht']['#attributes'] = array('class' => array('btn btn-info'));
      } */

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
    $markup = '<span class="label label-default">Offen</span>';
  }
  elseif ($current == NM_COURSES_TASK_WORKFLOW_SUBMITTED) {
    $markup = '<span class="label label-info">Eingereicht</span>';
  }
  elseif ($current == NM_COURSES_TASK_WORKFLOW_ASSESSED) {
    $markup = '<span class="label label-success"><strong>Bewertet</strong></span>';
  }

  return $markup;
}

/*
liefert texte bzw icons um für aufgabe einreichungszeitraum festzulegen
 * sowie für ggf angegebene solution eine bewertung, ob im bearbeitungszeitrum */
function _courses_tasks_get_task_period_label($task_id, $solution_id = 0) {
    $node = node_load($task_id);
    
    $timezone = $node->field_task_handling_period[LANGUAGE_NONE][0]['timezone_db'];
    $timezone_new = $node->field_task_handling_period[LANGUAGE_NONE][0]['timezone'];
    
     $start_string = strtotime($node->field_task_handling_period[LANGUAGE_NONE][0]['value'].' '.$timezone);
    $starttime_secs = format_date($start_string,'custom','U',$timezone_new);
    
    $endtime_string = strtotime($node->field_task_handling_period[LANGUAGE_NONE][0]['value2'].' '.$timezone);
    $endtime_secs = format_date($endtime_string,'custom','U',$timezone_new);
    
    //ohne endtime wird dise automatisch auf starttime gesetzt
    $has_endtime =  $endtime_secs  > $starttime_secs;
    
    if ($solution_id) {
        $solution = node_load($solution_id);
        $state = workflow_node_current_state($solution);
    }
    //aw nicht im entwurfsmodus
    if ($solution_id && !($state == NM_COURSES_TASK_WORKFLOW_DRAFT)) {

        $eingereicht_time = $solution->field_submitted_on[LANGUAGE_NONE][0];
    
        //keine daten - kein markup
        if (empty($eingereicht_time))
            return '';
        $eingereicht_date = strtotime($eingereicht_time['value'] . ' ' . $eingereicht_time['timezone_db']);
        $eingereicht_secs = format_date($eingereicht_date, 'custom', 'U', $eingereicht_time['timezone']);
        
        if ($eingereicht_secs < $starttime_secs)
            $markup = '<span class="label label-danger"><strong>Zu früh eingereicht</strong></span>';
        elseif ($has_endtime && $eingereicht_secs > $endtime_secs)
            $markup = '<span class="label label-danger"><strong>Zu spät eingereicht</strong></span>';
        else
            $markup = '<span class="label label-info"><strong>Pünktlich eingereicht</strong></span>';
        return $markup;
    }
    //keine solultion vorhanden oder im draft-modus
    if ($starttime_secs > time())
        $markup = '<span class="label label-danger"><strong>Noch kein Bearbeitungszeitraum</strong></span>';
    elseif ($has_endtime && time() > $endtime_secs)
        $markup = '<span class="label label-danger"><strong>Einreichungsfrist verpasst</strong></span>';
    else
        $markup = '<span class="label label-info"><strong>Bearbeitungszeitraum aktiv</strong></span>';
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
  //php-warning abfangen
  $einreichungsfristlabel = _courses_tasks_get_task_period_label($task_nid, @$solution->nid);
  $output = "";
  //$output .= '<div class="alert alert-info">';
  $output .= "<div class='row'><h1 class='col-md-8'>" . $task->title."</h1>". "<span  class='col-md-4'>" . $label .' '. $einreichungsfristlabel.'</span></div>';
  //$output .= '</div>';
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
  //anzeige einer nicht-editable lösung
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
    $field_solution_items = _course_tasks_generic_get_section($field_val, NM_COURSES_TASK_FORM);

    //$solution_wrapper = entity_metadata_wrapper('node', $solution_node->nid);
    //$solutions_field_vals = $solution_wrapper->field_generic_solution_entry->value();
    $solutions_field_vals = field_get_items('node', $solution_node, 'field_generic_solution_entry');
    $fview = field_view_field('node', $solution_node, 'field_generic_solution_entry', $solutions_field_vals);

    foreach ($field_solution_items as $key => $solution_field_description) {
      //apply filters
      $solution_field_description['second'] = check_markup($solution_field_description['second'], 'filtered_html');
      //gleiches design wie bei aufgaben-stellung via label
      $output .= "<label>" . $solution_field_description['second'] . "</label>";
      //$output .= $solutions_field_vals[$key]['value'];

      $output .= render($fview[$key]);
    }
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
    if (isset($item)) {
      unset($item);
    }

    $output .= drupal_render($form);

  }

  $output = '<div class="alert alert-warning">' . $output;
  $output .= '</div>';



  return $output;
}

/**
 * Erstellt die Form, um eine Lösung zu bewerten / zurückzuweisen etc
 * @param type $form
 * @param type $form_state
 * @param type $solution_nid
 * @return string
 */
function _section_courses_task_solution_assesment_form($form, &$form_state, $solution_nid) {
  $node_wrapper = entity_metadata_wrapper('node', $solution_nid);
  $field_notice_instance = field_info_instance('node', 'field_generic_task_reject_notice', 'courses_generic_task_solution');

  $assessment_val = $node_wrapper->field_generic_task_assessment->value();
  $notice_val = $node_wrapper->field_generic_task_reject_notice->value();
  $form = array();


  //[todo] generate possible transitionbuttons automatically ?
  //temporarly - manually checking possible transitions

  $solution = node_load($solution_nid);
  $current_state = workflow_node_current_state($solution);

  switch ($current_state) {
    case NM_COURSES_TASK_WORKFLOW_SUBMITTED:

      $form['solution_nid'] = array(
        '#type' => 'hidden',
        '#value' => $solution_nid,
      );
      $form['to_assess'] = array(
        '#type' => 'fieldset',
        '#title' => t('assess solution'),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
      );
      $form['to_assess']['assessment'] = array(
        '#type' => 'text_format',
        '#base_type' => 'textarea',
        '#default_value' => $assessment_val['value'],
        '#format' => NM_FILTER_FORMAT_FILTERED_HTML,
      );
      $form['to_assess']['save'] = array(
        '#type' => 'submit',
        '#attributes' => array('class' => array('btn', 'btn-primary')),
        '#id' => 'save_assessment',
        '#value' => 'Speichern',
      );
      //limit button to permission
      if (in_array('Bewertet', workflow_field_choices($solution))) {
        $form['to_assess']['assess_solution'] = array(
          '#type' => 'submit',
          '#id' => 'assess_solution',
          '#attributes' => array('class' => array('btn', 'btn-success')),
          '#value' => 'Speichern und Bewerten',
        );
      }

      //limit button to permission
      if (in_array('Entwurf', workflow_field_choices($solution))) {
        $form['to_reject'] = array(
          '#type' => 'fieldset',
          '#title' => t('reject solution'),
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
        );
        $form['to_reject']['reject_notice'] = array(
          '#type' => 'text_format',
          '#base_type' => 'textarea',
          '#description' => t($field_notice_instance['description']),
          '#default_value' => $notice_val['value'],
          '#format' => NM_FILTER_FORMAT_FILTERED_HTML,
        );
        $form['to_reject']['store_cancel_submission'] = array(
          '#type' => 'submit',
          '#id' => 'reject_solution',
          '#attributes' => array('class' => array('btn', 'btn-primary')),
          '#value' => t('Reject and request improvements'),
        );
      }
      break;
  }


  return $form;
}

/**
 * submit-funktion für _section_courses_task_solution_assesment_form
 * @global type $user
 * @param type $form
 * @param type $form_state
 */
function _section_courses_task_solution_assesment_form_submit($form, &$form_state) {
  global $user;

  $solution_nid = $form_state['values']['solution_nid'];
 
  //possible: reject_solution, assess_solution, save_assessment
  $function_called = $form_state['triggering_element']['#id'];
  $node = node_load($solution_nid);


  switch ($function_called) {

    case 'save_assessment':
      $node->field_generic_task_assessment[LANGUAGE_NONE][0]['value'] = $form_state['values']['assessment']['value'];
      $node->field_generic_task_assessment[LANGUAGE_NONE][0]['format'] = NM_FILTER_FORMAT_FILTERED_HTML;
      break;
    case 'assess_solution':
      $node->field_generic_task_assessment[LANGUAGE_NONE][0]['value'] = $form_state['values']['assessment']['value'];
      $node->field_generic_task_assessment[LANGUAGE_NONE][0]['format'] = NM_FILTER_FORMAT_FILTERED_HTML;
      workflow_execute_transition($node, NM_COURSES_TASK_WORKFLOW_ASSESSED);
      break;
    case 'reject_solution':
      $node->field_generic_task_reject_notice[LANGUAGE_NONE][0]['value'] = $form_state['values']['reject_notice']['value'];
      $node->field_generic_task_reject_notice[LANGUAGE_NONE][0]['format'] = NM_FILTER_FORMAT_FILTERED_HTML;
      workflow_execute_transition($node, NM_COURSES_TASK_WORKFLOW_DRAFT);
      break;
  }


  node_save($node);
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
      '#title' => check_markup($item['second'], "filtered_html"),
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
    '#attributes' => array('class' => array('btn','btn-primary')),
    '#value' => 'Als Entwurf speichern',
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
        '#attributes' => array('class' => array('btn','btn-info')),
        '#value' => 'Speichern und Einreichen',
      );
        
    $task_node = node_load($task_nid);
    $task_is_gruppenaufgabe = (boolean) $task_node->field_task_type[LANGUAGE_NONE][0]['value'];
     if($task_is_gruppenaufgabe)
     {   //erhalte kursgruppe
         $users_cg = _section_courses_student_get_coursegroup_gid();
         //user ist in keiner KG und nicht kurs-admin
         if(!$users_cg && !section_courses_instructors_tools_access())
         {

           $course_object =  node_load($task_node->og_group_ref[LANGUAGE_NONE][0]['target_id']);
           $cg_selfsignup_denied = !empty($course_object->field_access_features[LANGUAGE_NONE][0]) && $course_object->field_access_features[LANGUAGE_NONE][0]['value'] ==  'course_group_lock';

           //sperre für alle "studentenformulare" die ausfüllung
           foreach ($form['solutions'] as $counter => &$solution_form_object) {
                     //prüfe ob $counter ein integer
                     if (is_int($counter))
                     {
                           //vernichte textfeld und setze text
                           $solution_form_object = array();
                           $text = t('This is a coursetask but you are not member of a coursegroup in this course.').'<br>';

                           if($cg_selfsignup_denied)
                           {
                               $text .= t('Ask the staff to assign you to a coursegroup.');
                           }
                           else
                           { 
                               $text .= l(t('Sign up for a coursegroup'), "course/groups/" . $course_object->nid . '/'. $course_object->nid).' '. t('or ask the staff to assign you to one.');
                           }
                          $solution_form_object['#markup'] = $text;
                     }
                 }
           unset($form['save_submit']);
           unset($form['save']);
         }
     } 
      break;
  }

  return $form;
}
//wird beim abgeben / speichern einer lösung ausgeführt
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
    $task = node_load($task_nid);
    $node = new stdClass();
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
    $node = node_submit($node); // Prepare node for saving
  }

  //check if any solution fields were committed first
  //possibility of task without solution fields
  if (isset($form_state['values']['solutions'])) {
    foreach ($form_state['values']['solutions'] as $item) {
      $val = $item['value'];
      $node->field_generic_solution_entry[LANGUAGE_NONE][] = array('value' => $val, 'format' => NM_FILTER_FORMAT_FILTERED_HTML);
    }
  }
  //noch nie gesetzt und status ist einreichen
  if(empty($node->field_submitted_on) && $form_state['values']['save_submit'] == $form_state['triggering_element']['#value'])
  {
        $eingereicht_date = new DateTime(date('Y-m-d H:i:s'));
        //save as UTC and convert when reading again - default behaviour
        $eingereicht_date->setTimezone(timezone_open('UTC'));
        $eingereicht_string = $eingereicht_date->format('Y-m-d H:i:s');
        //timezone is set automatically
        $node->field_submitted_on[LANGUAGE_NONE][0]['value'] = $eingereicht_string;
    
    }
    
  node_save($node);

  //check which button was clicked
  //if save and submit was clicked, move node to submitted state
  if ($form_state['values']['save_submit'] == $form_state['triggering_element']['#value']) {
    workflow_execute_transition($node, NM_COURSES_TASK_WORKFLOW_SUBMITTED, TRUE);
  }
}

function _course_tasks_generic_section_view($field_val, $id) {
  $title = "";
  $class = "";
  switch ($id) {
    case NM_COURSES_TASK_DESCRIPTION:
      $title = "Beschreibung";
      break;
    case NM_COURSES_TASK_TASK:
      $title = "Aufgabenstellung";
      break;
    case NM_COURSES_TASK_TIPS:
      $title = "Leitfragen";
      $class = "alert alert-success";
      break;
    case NM_COURSES_TASK_FORM:
      $title = "Formular";
      break;
    default:
  }
  $description_items = _course_tasks_generic_get_section($field_val, $id);
  $output = "";
  if (count($description_items) > 0) {
    $output .= '<div id="task_general_' . $id . '" class="' . $class . '">';
    $output .= '<h3>' . $title . '</h3>';
    foreach ($description_items as $item) {
      $output .= $item['second'];
    }

    $output .= '</div>';
  }


  //apply filters
  $output = check_markup($output, 'filtered_html');

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