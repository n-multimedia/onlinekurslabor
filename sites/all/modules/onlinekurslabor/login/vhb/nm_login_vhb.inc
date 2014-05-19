<?php

/**
 * insert a new db entry on user registration
 * @param type $user
 */
function nm_login_vhb_db_insert($user) {

  //check if entry already exists for that user first
  $query = db_select('nm_login_vhb', 'nm');
  $query->fields('nm', array('uid'));
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
 * @param type $matrikelnummer
 */
function nm_login_vhb_user_is_archivated($matrikelnummer) {

  $obf_matrikelnummer = nm_login_vhb_obfuscate_matrikelnummer($matrikelnummer);
  $query = db_select('nm_login_vhb', 'nm');
  $query->fields('nm', array('uid'));
  $query->condition('nm.archivated', 1);
  $query->condition('nm.matrikelnummer', $obf_matrikelnummer);
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
  $wrapper->field_matrikelnummer->set($params['MATRIKELNUMMER']);
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
  $profile2 = profile2_load_by_user($account, 'student');

  //load matrikelnummer from profile2 data
  if (isset($profile2->field_matrikelnummer) && !empty($profile2->field_matrikelnummer[LANGUAGE_NONE])) {

    $matrikelnummer = $profile2->field_matrikelnummer[LANGUAGE_NONE][0]['value'];
    //Populate profile fields
    $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);
    $wrapper->field_matrikelnummer->set(NULL);
    $wrapper->field_studienfach->set(NULL);
    //load term id and set hochschule field
    //$terms = taxonomy_get_term_by_name...;
    //if (!empty($terms)) {
    $wrapper->field_hochschule->set(NULL);
    //}

    $wrapper->save();

    //master profile
    $profile2 = profile2_load_by_user($account, 'master');

    //Populate profile fields
    $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);
    $wrapper->field_first_name->set('');
    $wrapper->field_last_name->set('');
    $wrapper->field_birthday->set(NULL);
    //not knowing which SEX options possible
    //weiblich = female so everything !female will be male 
    $wrapper->field_gender->set('fa');

    $wrapper->save();

    realname_update($account);

    drupal_set_message('Student ' . $edit['name'] . ' wurde archiviert.');

    //update db entry
    $num_c = db_update('nm_login_vhb')->fields(array(
          'archivated' => 1,
          'matrikelnummer' => nm_login_vhb_obfuscate_matrikelnummer($matrikelnummer),
        ))
        ->condition('uid', $user->uid)
        ->execute();

    if ($num_c) {
      drupal_set_message($user->uid . " has been archivated");
    }

    drupal_set_message("Der Benutzer " . $user->name . ' wurde archiviert.');
    return $account;
  }
  else {
    drupal_set_message("Der Benutzer " . $user->name . ' konnte nicht archiviert werden, da dieser keine Matrikelnummer besitzt.', 'error');
    return NULL;
  }


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
function nm_login_vhb_obfuscate_matrikelnummer($matrikelnummer) {

  require_once './includes/password.inc';

  $salt = NM_LOGIN_VHB_LOGIN_ENTRY_SALT;
  $hash_bin = hash('sha512', $salt . $matrikelnummer, TRUE);
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