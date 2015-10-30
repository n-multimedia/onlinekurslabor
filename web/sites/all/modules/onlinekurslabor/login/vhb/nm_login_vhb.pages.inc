<?php

function nm_login_vhb_admin_list_all() {
  $output = '';

  $output = nm_login_vhb_admin_render_user_view();

  return $output;
}

function nm_login_vhb_admin_list_active() {
  $args = array(0);
  $output = nm_login_vhb_admin_render_user_view($args);

  return $output;
}

function nm_login_vhb_admin_list_archivated() {

  $args = array(1);
  $output = nm_login_vhb_admin_render_user_view($args);

  return $output;
}

function nm_login_vhb_admin_render_user_view($args = array()) {
  $view_name = 'nm_login_vhb';
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