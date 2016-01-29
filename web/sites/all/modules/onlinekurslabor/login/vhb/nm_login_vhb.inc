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
 * @param type $vhb_login vhb_login_id
 *  @param type $hochschule_matrikelnummer
 *  ONE OF PARAMS HAVE TO BE PRESENT
 */
function nm_login_vhb_user_is_archivated($vhb_login = null, $hochschule_matrikelnummer = null) {

    $obf_vhblogin = nm_login_vhb_obfuscate_data($vhb_login, $hochschule_matrikelnummer);
    $query = db_select('nm_login_vhb', 'nm');
    $query->fields('nm', array('uid'));
    $query->condition('nm.archivated', 1);
    $query->condition('nm.login_uid', $obf_vhblogin);
    $res = $query->execute()->fetchField();
    //check if uid was found
    if (isset($res) && $res > 0) {
        return $res;
    }

    return FALSE;
}

/**
 * check if user is vhb user
 * @param int $uid User-ID
 * @return boolean is_vhb_member
 */
function nm_login_vhb_is_vhb_user($uid) {

    $query = db_select('nm_login_vhb', 'nm');
    $query->fields('nm', array('uid'));
    $query->condition('nm.uid', $uid);
    $res = $query->execute()->fetchField();
    //check if uid was found
    if (isset($res) && $res > 0) {
        return TRUE;
    }
    return FALSE;
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
    $role = user_role_load_by_name(NM_ROLE_STUDENT); #
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
    //im return nach save fehlt die rolle authentifizierter benutzer
    //account neu laden, dann is sie wieder da.
    $account = user_load($account->uid);

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
    } else {
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
                'login_uid' => '',
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
 * Update empty profile2 fields of existing user
 * by a VHB POST request
 *
 * @param $params VHB encoded POST parameters
 *
 * @return $account user account object
 *
 */
function nm_login_vhb_update_empty_profile_fields($account, $params, $force = FALSE) {
    //some redundand aspects
    //refactor new generic function
    //course/admin/%1/members/add
    $role = user_role_load_by_name(NM_ROLE_STUDENT);

    if (!$account) {
        drupal_set_message("Account konnte nicht geladen werden.", 'error');
        return;
    }

    //student profile
    $profile2 = profile2_load_by_user($account, 'student');

    if (!$profile2) {
        //student profile
        $profile2 = profile2_create(array('type' => 'student'));
        $profile2->setUser($account);
        profile2_save($profile2);
    }

    //Populate profile fields
    $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);


    //20.11.2014 - 11:40 - SN matrikelnummer int changed to varchar
    $tmp = $wrapper->field_matrikelnummer_varchar->value();
    if (empty($tmp) || $force) {
        $wrapper->field_matrikelnummer_varchar->set($params['MATRIKELNUMMER']);
    }


    $tmp = $wrapper->field_studienfach->value();
    if (empty($tmp) || $force) {
        $wrapper->field_studienfach->set($params['STUDIENFACH']);
    }

    $tmp = $wrapper->field_hochschule->value();
    if (empty($tmp) || $force) {
        //load term id and set hochschule field
        $terms = taxonomy_get_term_by_name($params['HOCHSCHULE']);

        if (!empty($terms)) {
            $wrapper->field_hochschule->set(current($terms)->tid);
        }
    }

    $wrapper->save();

    //master profile
    $profile2 = profile2_load_by_user($account, 'master');

    if (!$profile2) {
        //master profile
        $profile2 = profile2_create(array('type' => 'master'));
        $profile2->setUser($account);
        profile2_save($profile2);
    }

    $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);

    $tmp = $wrapper->field_first_name->value();
    if (empty($tmp) || $force) {
        $wrapper->field_first_name->set($params['VORNAME']);
    }

    $tmp = $wrapper->field_last_name->value();
    if (empty($tmp) || $force) {
        $wrapper->field_last_name->set($params['NACHNAME']);
    }


    $tmp = $wrapper->field_birthday->value();
    if (empty($tmp) || $force) {
        $wrapper->field_birthday->set(strtotime($params['GEBDAT']));
    }

    $tmp = $wrapper->field_gender->value();

    if ($tmp == 'fa') {
        //not knowing which SEX options posiible
        //weiblich = female so everything !female will be male
        if ($params['SEX'] == 'weiblich') {
            $wrapper->field_gender->set('female');
        } else {
            $wrapper->field_gender->set('male');
        }
    }
    $wrapper->save();

    //master profile
    $profile2 = profile2_load_by_user($account, 'data');

    if (!$profile2) {
        //master profile
        $profile2 = profile2_create(array('type' => 'data'));
        $profile2->setUser($account);
        profile2_save($profile2);
    }

    $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);

    $tmp = $wrapper->field_nm_login_vhb_login->value();
    if (empty($tmp) || $force) {
        $wrapper->field_nm_login_vhb_login->set($params['LOGIN']);
    }

    $wrapper->save();

    realname_update($account);
}

/**
 * führt einen Check auf Basis-Daten durch, und updated diese ggf
 *
 * @param StdClass $vhb_user user-object
 * @param array $params - die uebergebenen post-daten
 */
function nm_login_vhb_check_update_basicdata($vhb_user, $params) {
    //master profile
    $profile2 = profile2_load_by_user($vhb_user, 'master');

    if (!$profile2) {
        return false;
    }
    $wrapper = entity_metadata_wrapper('profile2', $profile2->pid);

    //Vor- und Nachname passen nicht zu gespeichertem - seltsam!
    if ($wrapper->field_first_name->value() != $params['VORNAME'] && $wrapper->field_last_name->value() != $params['NACHNAME'])
        return false;


    $wrapper->field_first_name->set($params['VORNAME']);
    $wrapper->field_last_name->set($params['NACHNAME']);
    $wrapper->save();

    $vhb_user->mail = $params['EMAIL'];
    user_save($vhb_user);

    return true;
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
    if ($profile2_data && isset($wrapper_data->field_nm_login_vhb_login)) {
        //Populate profile fields
        $vhb_login = $wrapper_data->field_nm_login_vhb_login->value();
    }

    //2 - neeeded for fallback only
    if (!empty($term_hochschule->name) && !empty($matrikelnummer)) {
        $hochschule_matrikelnummer = $term_hochschule->name . $matrikelnummer;
    }

    $obscured_login = nm_login_vhb_obfuscate_data($vhb_login, $hochschule_matrikelnummer, $user_mail);

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
    drupal_set_message('$obscured_login' . $obscured_login);
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
 * function used to obfuscate user_login-data
 * @param string $vhb_login vhb-login-id
 * @param string $hochschule_matrikelnummer  string containing hs and matrikelnummer
 * @param string $email the user's email
 * // one of the parameters need to be set!
 * @return type
 */
function nm_login_vhb_obfuscate_data($vhb_login = null, $hochschule_matrikelnummer = null, $email = null) {
    require_once './includes/password.inc';

    $prependix = "";
    $data = null;
    if ($vhb_login) {
        //default
        $data = $vhb_login;
    } else if ($hochschule_matrikelnummer) {
        //2 - fallback. matrikelnummer + hochschule as unique identifier
        $prependix = "deprecated(h+m):";
        $data = $hochschule_matrikelnummer;
    } elseif ($email) {
        //3 - fallback - mail
        $prependix = "deprecated(e):";
        $data = $email;
    } else
        throw new Exception("No valid data given!");


    $salt = NM_LOGIN_VHB_LOGIN_ENTRY_SALT;
    $hash_bin = hash('sha512', $salt . $data, TRUE);
    $len = strlen($hash_bin);
    $hash = $prependix . _password_base64_encode($hash_bin, $len);

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

                dpm($counter . ': ' . $matrikelnummer . ' migriert - user: ' . $user->uid);

                if (empty($profile->field_matrikelnummer_varchar)) {
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
