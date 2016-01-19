<?php

/**
 * insert a new db entry on user registration
 * @param type $user
 */
function nm_login_vhb_db_insert($user) {

  //check if entry already exists for that user first
  $query = db_select('nm_login_vhb', 'nm');
  $query->fields('nm', array('uid'));
  $query->condition('nm.uid', $user->uid);
  $res = $query->execute()->fetchField();
  //check if uid was found
  if (isset($res) && $res > 0) {
    return;
  }

  //add a new entry otherwise

  //add db entry for $user
  db_insert('nm_login_vhb') // Table name no longer needs {}
      ->fields(array(
        'uid' => $user->uid,
        'archivated' => 0,
        'created' => REQUEST_TIME,
      ))
      ->execute();
}

/**
 * check if user has been archivated
 * @param type $vhb_login
 */
function nm_login_vhb_user_is_archivated($vhb_login) {

  $obf_vhblogin = nm_login_vhb_obfuscate_matrikelnummer($vhb_login);
  $query = db_select('nm_login_vhb', 'nm');
  $query->fields('nm', array('uid'));
  $query->condition('nm.archivated', 1);
  $query->condition('nm.login_uid', $obf_vhblogin);
  $res = $query->execute()->fetchField();
  //check if uid was found
  if (isset($res) && $res > 0) {
    return $res;
  }

  return false;
}

/**
 * reactivate archivated users
 * @param type $params
 */
function nm_login_vhb_reactivate_user($uid, $params) {
  $user = user_load($uid);

  //some redundand aspects
  //refactor new generic function
  //course/admin/%1/members/add
  $role = user_role_load_by_name(NM_ROLE_STUDENT);
  $edit = array(
    'name' => $params['VORNAME'] . ' ' . $params['NACHNAME'],
    'pass' => user_password(),
    'mail' => $params['EMAIL'],
    'init' => $params['EMAIL'],
    'status' => 1,
    'access' => REQUEST_TIME,
    'roles' => array($role->rid => $role->name),
  );


  //increment until we get an unused user name
  $count = 1;
  $user_name = $edit['name'];
  while (user_load_by_name($user_name)) {
    $user_name = $edit['name'] . ' ' . $count++;
  }
  $edit['name'] = $user_name;

  //save and notify the user
  $account = user_save($user, $edit);

  if (!$account) {
    drupal_set_message("Account konnte nicht gespeichert werden.", 'error');
    return;
  }

  //student profile
  $profile2 = profile2_load_by_user($account, 'student');
  //Populate profile fields
  $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);
  // $wrapper->field_matrikelnummer->set($params['MATRIKELNUMMER']); 20.11.2014 - 11:42 - SN
  $wrapper->field_matrikelnummer_varchar->set($params['MATRIKELNUMMER']);
  $wrapper->field_studienfach->set($params['STUDIENFACH']);
  //load term id and set hochschule field
  $terms = taxonomy_get_term_by_name($params['HOCHSCHULE']);

  if (!empty($terms)) {
    $wrapper->field_hochschule->set(current($terms)->tid);
  }

  $wrapper->save();

  //master profile
  $profile2 = profile2_load_by_user($account, 'master');

  //Populate profile fields
  $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);
  $wrapper->field_first_name->set($params['VORNAME']);
  $wrapper->field_last_name->set($params['NACHNAME']);
  $wrapper->field_birthday->set(strtotime($params['GEBDAT']));
  //not knowing which SEX options posiible
  //weiblich = female so everything !female will be male
  if ($params['SEX'] == 'weiblich') {
    $wrapper->field_gender->set('female');
  }
  else {
    $wrapper->field_gender->set('male');
  }
  $wrapper->save();

  //data profile
  $profile2 = profile2_load_by_user($account, 'data');

  //Populate profile fields
  $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);
  $wrapper->field_nm_login_vhb_login->set($params['LOGIN']);

  $wrapper->save();

  realname_update($account);

  //drupal_set_message('Student ' . $edit['name'] . ' wurde angelegt.');
  //assign user to defined course
  //load course by LVNR
  $course = nm_login_vhb_get_course($params['LVNR']);
  //subscribe
  nm_login_vhb_user_subscribe($account, $course);

  $num_c = db_update('nm_login_vhb')->fields(array(
        'archivated' => 0,
        'matrikelnummer' => '',
      ))
      ->condition('uid', $user->uid)
      ->execute();

  if ($num_c) {
    drupal_set_message("Der Benutzer " . $user->name . ' wurde reaktiviert.');

    //todo account reactivated!
    //_user_mail_notify('register_admin_created', $account);
  }


  return $account;
}

/**
 * delete db entry
 * @param type $user
 */
function nm_login_vhb_db_delete($user) {
  db_delete('nm_login_vhb')
      ->condition('uid', $user->uid)
      ->execute();

  dpm($user->uid . ' has been deleted.');
}

/**
 * archivate and obfuscate user data
 * @param type $user
 * @return type
 */
function nm_login_vhb_archivate_user($user) {
  //some redundand aspects
  //refactor new generic function
  //course/admin/%1/members/add
  $role = user_role_load_by_name(NM_ROLE_STUDENT);
  $user_mail = $user->mail;
  $edit = array(
    //22.01.2014 - 16:27 - SN
    //real init name will get lost, but should be no problem,
    //because uid should be referenced not the name
    'name' => 'obfuscated',
    'pass' => user_password(),
    'mail' => 'obfuscated@mail' . user_password() . '.de',
    'init' => 'obfuscated@mail' . user_password() . '.de',
    'status' => 0,
  );

  //increment until we get an unused user name
  $count = 1;
  $user_name = $edit['name'];
  while (user_load_by_name($user_name)) {
    $user_name = $edit['name'] . ' ' . $count++;
  }
  $edit['name'] = $user_name;

  //save and notify the user
  $account = user_save($user, $edit);

  if (!$account) {
    drupal_set_message("Account konnte nicht gespeichert werden.", 'error');
    return;
  }

  //student profile
  $profile2_student = profile2_load_by_user($account, 'student');
  $wrapper_student = entity_metadata_wrapper('profile2', $profile2_student->pid);
  $term_hochschule = $wrapper_student->field_hochschule->value();
  $matrikelnummer = $wrapper_student->field_matrikelnummer_varchar->value();

  //master profile
  $profile2_master = profile2_load_by_user($account, 'master');
  $wrapper_master = entity_metadata_wrapper('profile2', $profile2_master->pid);

  //data profile
  $profile2_data = profile2_load_by_user($account, 'data');
  $wrapper_data = entity_metadata_wrapper('profile2', $profile2_data->pid);


  //1
  $vhb_login = null;
  if ($profile2_data) {
    //Populate profile fields
    $vhb_login = $wrapper_data->field_nm_login_vhb_login->value();
  }

  //2 - neeeded for fallback only
  if(!empty($term_hochschule->name) && !empty($matrikelnummer)){
    $hochschule_matrikelnummer = $term_hochschule->name . $matrikelnummer;
  }

  $obscured_login = NULL;
  if(!empty($vhb_login)){
    //1 - VHB LOGIN
    $obscured_login = nm_login_vhb_obfuscate_matrikelnummer($vhb_login);
  }else if(!empty($hochschule_matrikelnummer)){
    //2 - fallback. matrikelnummer + hochschule as unique identifier
    $obscured_login = "deprecated(h+m):".nm_login_vhb_obfuscate_matrikelnummer($hochschule_matrikelnummer);
  }else {
    //3 - fallback - mail
    $obscured_login = "deprecated(e):".nm_login_vhb_obfuscate_matrikelnummer($user_mail);
  }

  //RESET  Values

  //master profile
  $wrapper_master->field_birthday->set(NULL);
  //not knowing which SEX options possible
  //weiblich = female so everything !female will be male
  $wrapper_master->field_gender->set('fa');
  $wrapper_master->save();

  //load matrikelnummer from profile2 data
  //Populate profile fields
  $wrapper_student->field_matrikelnummer_varchar->set(NULL);
  $wrapper_student->field_studienfach->set(NULL);
  $wrapper_student->field_hochschule->set(NULL);
  $wrapper_student->save();

  //data
  $wrapper_data->field_nm_login_vhb_login->set(NULL);
  $wrapper_data->save();

  drupal_set_message('Student ' . $edit['name'] . ' wurde archiviert.');

  //update db entry
  $num_c = db_update('nm_login_vhb')->fields(array(
    'archivated' => 1,
    'login_uid' => $obscured_login,
  ))
    ->condition('uid', $user->uid)
    ->execute();

  if ($num_c) {
    drupal_set_message($user->uid . " has been archivated");
  }

  return $account;

  //assign user to defined course
  //load course by LVNR
  //$course = nm_login_vhb_get_course($params['LVNR']);
  //subscribe
  //nm_login_vhb_user_subscribe($account, $course);
  //todo account deaktiviert
  //...ihr account wurde stillgelegt, beim erneuten einloggen über die vhb, können sie ihren account jederzeit wieder reaktivieren
  //_user_mail_notify('register_admin_created', $account);
}

/**
 * function used to obfuscate a matrikelnummer
 * @param type $matrikelnummer
 * @return type
 */
function nm_login_vhb_obfuscate_matrikelnummer($vhb_identifier) {

  require_once './includes/password.inc';

  $salt = NM_LOGIN_VHB_LOGIN_ENTRY_SALT;
  $hash_bin = hash('sha512', $salt . $vhb_identifier, TRUE);
  $len = strlen($hash_bin);
  $hash = _password_base64_encode($hash_bin, $len);

  return $hash;
}


/**
 * import all users that have a matrikelnummer set into
 * the interface db
 * needed to import existing, users who used the vhb-interface before
 * the db function was implemented
 */
function nm_login_vhb_import_all_users() {
  $query = db_select('users', 'u');
  $query->fields('u', array('uid'));
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $user = user_load($record['uid']);
    $profile = profile2_load_by_user($user, 'student');
    if (!empty($profile) && !empty($profile->field_matrikelnummer)) {
      $matrikelnummer = $profile->field_matrikelnummer[LANGUAGE_NONE][0]['value'];
      if (!empty($matrikelnummer)) {
        //check if user is already listed
        $query = db_select('nm_login_vhb', 'nm');
        $query->fields('nm', array('uid'));
        $query->condition('nm.uid', array($user->uid));
        $count = $query->countQuery()->execute()->fetchField();

        //if not add db entry
        if ($count == 0) {
          nm_login_vhb_db_insert($user);
        }

        dpm($user->uid . ' has been imported.');
      }
    }
  }
}

/**
 * [nm_login_vhb_migrate_to_new_matrikelnummer_varchar_field description]
 * @return [type] [description]
 */
function nm_login_vhb_migrate_to_new_matrikelnummer_varchar_field() {
  $counter = 1;
  $query = db_select('users', 'u');
  $query->fields('u', array('uid'));
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $user = user_load($record['uid']);
    $profile = profile2_load_by_user($user, 'student');
    if (!empty($profile) && !empty($profile->field_matrikelnummer)) {
      $matrikelnummer = $profile->field_matrikelnummer[LANGUAGE_NONE][0]['value'];
      if (!empty($matrikelnummer)) {
        //check if user is already listed
        //$wrapper = entity_metadata_wrapper('profile2', $profile->pid);
        //$wrapper->field_first_name->set($matrikelnummer);

        dpm($counter . ': ' .$matrikelnummer . ' migriert - user: ' . $user->uid);

        if(empty($profile->field_matrikelnummer_varchar)) {
          $profile->field_matrikelnummer_varchar[LANGUAGE_NONE][0]['value'] = $matrikelnummer;
          $profile->save();
        }

        $counter++;

        // if($counter > 5) {
        //   break;
        // }
      }
    }
  }
}

