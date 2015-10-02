<?php

function section_courses_clone_page() {
  
  $output = '';
  $output = section_courses_clone_render_clone_view();
  return $output;
}

function section_courses_clone_render_clone_view($args = array()) {
  $view_name = 'nm_courses_clone';
  $display_name = 'Master';
  //archivated = 1;
  $view = views_get_view($view_name);
  if (is_object($view)) {
    if(!empty($args)) {
      $view->set_arguments($args);
    }
    $view->set_display($display_name);
    $view->pre_execute();
    $output = $view->render($display_name);
  }

  return $output;
}
