<?php

function nm_login_vhb_db_insert($user) {
  $result = db_insert('nm_login_vhb') // Table name no longer needs {}
      ->fields(array(
        'uid' => $user->uid,
        'archivated' => 0,
        'created' => REQUEST_TIME,
      ))
      ->execute();
  dpm($result);
}

function nm_login_vhb_db_delete() {
  
}

function nm_login_vhb_obfuscate_user_data() {
  
}