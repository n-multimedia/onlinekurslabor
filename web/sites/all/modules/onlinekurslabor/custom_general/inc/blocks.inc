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
    $user__li_link .= '<a class="dropdown-toggle top_nav_link" data-toggle="dropdown" href="/user/' . $user->uid . '">';

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
    $user__li_link = '<li>'.l('<span class="glyphicon glyphicon-log-in"></span> Anmelden', "user/", array('html'=>true, 'attributes'=>array('class'=>'top_nav_link'))).'</li>';
  }
 
  $output = "";
    $output .= '<ul id="custom-top-nav" class="nav navbar-nav navbar-right">';


    // TINKERING

    if (module_exists('privatemsg') && $user->uid && array_intersect(array('authenticated user'), $user->roles)) {
        $unread_msg = privatemsg_unread_count();
        $output .= _custom_general_get_top_nav_element('messages', $unread_msg);
    }

    if (array_intersect(array(NM_ROLE_DOZENT, NM_ROLE_STUDENT, NM_ROLE_TEST_STUDENT, NM_ROLE_ADMIN, NM_ROLE_TUTOR, NM_ROLE_MODERATOR), $user->roles) || $user->uid == 0) {
        $output .= _custom_general_get_top_nav_element('courses');
    }

    //19.05.2014 - 15:49 - SN Projects
    if (array_intersect(array(NM_ROLE_KOOPERATIONSPARTNER, NM_ROLE_DOZENT, NM_ROLE_STUDENT, NM_ROLE_TEST_STUDENT, NM_ROLE_TUTOR, NM_ROLE_ADMIN, NM_ROLE_MODERATOR), $user->roles) || $user->uid == 0) {
        $output .= _custom_general_get_top_nav_element('partners');
    }

    if (array_intersect(array(NM_ROLE_AUTOR, NM_ROLE_ADMIN, NM_ROLE_MODERATOR), $user->roles)) {
        $output .= _custom_general_get_top_nav_element('domains');
    }

    //forum link for all logged-in users
    if($user->uid && array_intersect(array('authenticated user'), $user->roles))
        $output .= _custom_general_get_top_nav_element('forum');

    //help
    $output .= _custom_general_get_top_nav_element('help');


    $output .= $user__li_link;
    $output .= '</ul>';


    return $output;
}

/**
 * liefert einen in li-a-gekapselten menuepunkt fuer die hauptnavigation oben
 * @param string $identifier like forum or messages
 * @param int $unread_count wenn es news in dem bereich gibt, wird ein badge gerendert
 * @return string html
 */
function _custom_general_get_top_nav_element($identifier, $unread_count = 0) {
    $forum_path = 'forum/' . variable_get('okl_global_forum_tid', NM_GLOBAL_FORUM_TID);
    $icons = array
        (
        'messages' => array(
            'glyphicon_classes' => 'glyphicon glyphicon-envelope',
            'title' => t('Messages'),
            'path' => 'messages'),
        'courses' => array(
            'glyphicon_classes' => 'glyphicon glyphicon-education',
            'title' => t('Courses'),
            'path' => 'courses'),
        'partners' => array(
            'glyphicon_classes' => 'glyphicon glyphicon-briefcase',
            'title' => t('Partners'),
            'path' => 'projects/partners'),
        'domains' => array(
            'glyphicon_classes' => 'glyphicon glyphicon-book',
            'title' => t('Domains'),
            'path' => 'domains'),
        'forum' => array(
            'glyphicon_classes' => 'glyphicon glyphicon-console',
            'title' => t('Forum'),
            'path' => $forum_path),
        'help' => array(
            'glyphicon_classes' => 'glyphicon glyphicon-question-sign',
            'title' => t('Help'),
            'path' => 'help')
    );
    $nav_tpl = '<li><a href="/%s" title="%s" class="top_nav_link tooltip-top-navi"    ><span class="%s"></span> %s<span class="visible-xs-inline nav_description_xs">%s</span></li>';
    $badge_tpl = '<span class="badge progress-bar-warning">%s</span>';
    $badge = "";
    if ($unread_count > 0)
        $badge = sprintf($badge_tpl, $unread_count);
    return sprintf($nav_tpl, $icons[$identifier]['path'], $icons[$identifier]['title'], $icons[$identifier]['glyphicon_classes'], $badge, $icons[$identifier]['title']);
}

function _custom_general_theme_space() {
  $output = '';

  $output .= '<div id="custom_general_space" class=".clearfix"></div>';

  return $output;
}