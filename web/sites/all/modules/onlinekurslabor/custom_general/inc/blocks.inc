<?php

/**
 * Theme user's navigation block
 * 
 * @param type $variables
 * @return type
 */
function _custom_general_theme_top_nav($variables = NULL) {
  global $user;

  $user__li_link = "";
   


  if ($user->uid) {
    $profile = profile2_load_by_user($user, 'master');
    $user_pic = "";
    if (isset($profile->field_photo)) {
      $user_picture_field = field_view_field('profile2', $profile, 'field_photo', 'value');
      $user_pic = '<img src="'.(image_style_url('profile_nano_thumbnail', $user_picture_field['#items'][0]['uri'])).'" class="navigation_user_picture"/>';
    }
    $realname = realname_load($user);
    if (empty($realname))
      $realname = $user->name;

    //user menu here
    $user__li_link = "";
    $user__li_link .= '<li class="dropdown">';
    $user__li_link .= '<a class="dropdown-toggle" data-toggle="dropdown" href="/user/' . $user->uid . '">';

    $user__li_link .= $user_pic;
  

    $user__li_link .= $realname . ' ';

    $user__li_link .= ' ';


    $user__li_link .='<span class="caret"></span>';
    $user__li_link .='</a>';
    $user__li_link .='<ul class="dropdown-menu">';
    $user__li_link .='<li><a href="/user/' . $user->uid . '"><span class="glyphicon glyphicon-user"></span> Mein Profil</a></li>';
    $user__li_link .='<li><a href="/user/logout"><span class="glyphicon glyphicon-log-out"></span> Ausloggen</a></li>';
    $user__li_link .='</ul></li>';
    //$user_link .='</div>';
    //$user_link .= l("Abmelden", "user/logout");
  }
  else {
    $user__li_link = '<li>'.l('<span class="glyphicon glyphicon-log-in"></span> Anmelden', "user/", array('html'=>true)).'</li>';
  }
#$user_link =
  $output = "";
  $output .= '<ul id="custom-top-nav" class="nav navbar-nav navbar-right">';
  
  // TINKERING
  
  if (module_exists('privatemsg') && $user->uid && array_intersect(array('authenticated user'), $user->roles)) {
      $unread_msg = privatemsg_unread_count();
      if ($unread_msg > 0){
        $output .= '<li><a href="/messages">Nachrichten <span class="badge progress-bar-warning">'.$unread_msg.'</span></a></li>';

      }
      else{
        $output .= '<li><a href="/messages">Nachrichten</a></li>';

      }
  }

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

  //forum link for all users
  $forum_path = 'forum/'.variable_get('okl_global_forum_tid', NM_GLOBAL_FORUM_TID);
  if(drupal_valid_path($forum_path)){
    $output .= '<li class="border-left"><a href="'.url($forum_path).'">Forum</a></li>';
  }



  $output .= '<li class="border-left"><a href="/help">Hilfe</a></li>';
  $output .=  $user__li_link ;
  $output .= '</ul>';


  return $output;
}

function _custom_general_theme_space() {
  $output = '';

  $output .= '<div id="custom_general_space" class=".clearfix"></div>';

  return $output;
}