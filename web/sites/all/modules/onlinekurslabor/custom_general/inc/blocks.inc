<?php

/**
 * Theme user's navigation block
 * 
 * @param type $variables
 * @return type
 */
function _custom_general_theme_top_nav($variables = NULL) {
  global $user;

  $user_link = "#";
  $user_link_classes = "";


  if ($user->uid) {
    $profile = profile2_load_by_user($user, 'master');
    $user_pic = "";
    if (isset($profile->field_photo)) {
      $field_view = field_view_field('profile2', $profile, 'field_photo', array('settings' => array('image_style' => 'profile_nano_thumbnail')));
      $field_view['#label_display'] = 'hidden';
      $user_pic = drupal_render($field_view);
    }
    $realname = realname_load($user);
    if (empty($realname))
      $realname = $user->name;

    //user menu here
    //$user_link = '<div class="btn-group">';
    //$user_link .= '<a class="btn btn-inverse dropdown-toggle" data-toggle="dropdown" href="#">';
    $user_link = "";
    $user_link .= '<li class="dropdown">';
    $user_link .= '<a class="dropdown-toggle" data-toggle="dropdown" href="/user/' . $user->uid . '">';

    $user_link .= $user_pic;
    /*
    if (in_array(NM_ROLE_TEST_STUDENT, $user->roles)) {
      $user_link .= ' <span class="label">Testkonto</span> ';
    }
    else if (in_array(NM_ROLE_ADMIN, $user->roles)) {
      $user_link .= ' <span class="label">Admin</span> ';
    }
    else if (in_array(NM_ROLE_DOZENT, $user->roles)) {
      $user_link .= ' <span class="label">Dozent</span> ';
    }
    else if (in_array(NM_ROLE_AUTOR, $user->roles)) {
      $user_link .= ' <span class="label">Autor</span> ';
    }*/

    $user_link .= $realname . ' ';

    $user_link .= ' ';


    $user_link .='<span class="caret"></span>';
    $user_link .='</a>';
    $user_link .='<ul class="dropdown-menu">';
    $user_link .='<li><a href="/user/' . $user->uid . '"><i class="icon-user"></i> Mein Profil</a></li>';
    $user_link .='<li><a href="/user/logout"><i class="icon-lock"></i> Ausloggen</a></li>';
    //$user_link .='</ul>';
    //$user_link .='</div>';
    //$user_link .= l("Abmelden", "user/logout");
  }
  else {
    $user_link = l("Anmelden", "user/");
    $user_link_classes = " lock";
  }

  $output = "";
  $output .= '<ul id="custom-top-nav" class="nav pull-right">';

  if (array_intersect(array(NM_ROLE_DOZENT, NM_ROLE_STUDENT, NM_ROLE_TEST_STUDENT, NM_ROLE_ADMIN, NM_ROLE_TUTOR, NM_ROLE_MODERATOR), $user->roles) || $user->uid == 0) {
    $output .= '<li><a href="/courses">Kursübersicht</a></li>';
  }
  
  //19.05.2014 - 15:49 - SN Projects
  if (array_intersect(array(NM_ROLE_KOOPERATIONSPARTNER,NM_ROLE_DOZENT, NM_ROLE_STUDENT, NM_ROLE_TEST_STUDENT, NM_ROLE_TUTOR,  NM_ROLE_ADMIN, NM_ROLE_MODERATOR), $user->roles) || $user->uid == 0) {
    $output .= '<li><a href="/projects/partners">Partner</a></li>';
  }
  
  if (array_intersect(array(NM_ROLE_AUTOR, NM_ROLE_ADMIN, NM_ROLE_MODERATOR), $user->roles)) {
    $output .= '<li><a href="/domains">Themenübersicht</a></li>';
  }

  $output .= '<li class="border-left"><a href="/help">Hilfe</a></li>';
  $output .= '<li class="border-left ' . $user_link_classes . '">' . $user_link . '</li>';
  $output .= '</ul>';


  return $output;
}

function _custom_general_theme_space() {
  $output = '';

  $output .= '<div id="custom_general_space" class=".clearfix"></div>';

  return $output;
}