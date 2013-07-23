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
    
    //user menu here
    //$user_link = '<div class="btn-group">';
    //$user_link .= '<a class="btn btn-inverse dropdown-toggle" data-toggle="dropdown" href="#">';
    $user_link = "";
    $user_link .= '<li class="dropdown">';
    $user_link .= '<a class="dropdown-toggle" data-toggle="dropdown" href="#">';
    $user_link .= $user_pic . ' ' . $realname . ' ';
    $user_link .='<span class="caret"></span>';
    $user_link .='</a>';
    $user_link .='<ul class="dropdown-menu">';
    $user_link .='<li><a href="/user/"><i class="icon-user"></i> Mein Profil</a></li>';
    $user_link .='<li><a href="/user/logout"><i class="icon-lock"></i> Abmelden</a></li>';
    //$user_link .='</ul>';
    //$user_link .='</div>';
    
    //$user_link .= l("Abmelden", "user/logout");
  }
  else {
    $user_link= l("Anmelden", "user/");
    $user_link_classes = " lock";
  }

  $output = "";
  $output .= '<ul id="custom-top-nav" class="nav pull-right">';
  $output .= '<li><a href="/node/49">Kurseübersicht</a></li>';
  $output .= '<li class="border-left"><a href="#">Hilfe</a></li>';
  $output .= '<li class="border-left '.$user_link_classes.'">' . $user_link . '</li>';
  $output .= '</ul>';


  return $output;
}
