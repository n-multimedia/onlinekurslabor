<?php

/*
 * Tabelle mit User-Details im Profil
 */
$user = user_load($uid);
//übergebener parameter $range
$range;


$profile_data = _section_profile_get_profile_data($user) [$range];
//überschrift
$table_header = array(array('data' => t(ucfirst($range) . ' information'), 'colspan' => 2));
$row_content = array();
//löst profil-daten in theme_table-variablen auf https://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_table/7.x
foreach ($profile_data as $title => $info) {
    $row_content[] = array('data' => array(
            array('data' => $title, 'width' => '35%'), array('data' => $info, 'width' => '65%', 'align' => 'right')
    ));
}
echo theme('table', array('header' => $table_header, 'rows' => $row_content, 'attributes' => array('class'=>'profile_details_table_content_wrap')));


