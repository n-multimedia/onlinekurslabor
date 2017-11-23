<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
  Wipes all user and content data
  Use this function to initialize a onlinekurslabor instance only
 */
function _okl_dev_wipe_all_data() {

    global $user;

    variable_set('truncate_environment', TRUE);

    if ($user->uid != 1) {
        die("What the hell are you trying to do?");
    }
    //user gast und 1 werden nicht gelöscht
    $protected_user_uids = array(0, 1);

    //03.11.2017 - 17:56 - SN
    //uncomment this line if you are sure what you are doing
    #die("Uncomment this line if you are sure, what you are doing. All user and content data will be wiped!");

    

    //Lösche Watchdag-Einträge
    db_delete('watchdog')->execute();

    _okl_dev_watchdoginfo('PREPARING database');
    _okl_dev_prepare_deletion();
    _okl_dev_watchdoginfo('PREPARATION done');

    /**
     * es müssen zuerst files & taxonomy gelöscht werden, da es Exceptions gibt, wenn die og-ref nicht mehr gefunden wird, weil Nodes zuerst gelsöcht wurden. 
     */


    _okl_dev_watchdoginfo('DELETE FILES');
    _okl_dev_wipe_files();
    _okl_dev_watchdoginfo('FILES done');

    //Taxonomy
    _okl_dev_watchdoginfo('DELETING Taxonomy');
    _okl_dev_wipe_taxonomy();
    _okl_dev_watchdoginfo('Taxonomy done');

    /**
     * DELETE NODES (except pane and page) and HELP-Page
     * */
    _okl_dev_watchdoginfo('DELETING NODES');
    _okl_dev_wipe_nodes();
    _okl_dev_watchdoginfo('NODES done');

    _okl_dev_watchdoginfo('DELETE H5P-Content');
    _okl_dev_wipe_h5p();
    _okl_dev_watchdoginfo('H5P-Content done');

    //DIe Benutzer... 
    _okl_dev_watchdoginfo('DELETING USERS');
    _okl_dev_wipe_users($protected_user_uids);
    _okl_dev_watchdoginfo('USERS done');




    /**
     * MESSAGES
     * */
    _okl_dev_watchdoginfo('Private MSG');


    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'message');
    $result = $query->execute();
    $mids = array_keys($result['message']);

    message_delete_multiple($mids);
    //note: cleanup von privatemsg kommt später noch
    _okl_dev_watchdoginfo('Private MSG done');


    /**
     * VHB LOGINS
     * */
    _okl_dev_watchdoginfo('VHB-Login');

    $result = db_truncate('nm_login_vhb')->execute();
    _okl_dev_watchdoginfo('VHB-Login done');

    _okl_dev_watchdoginfo('CACHE');
    /**
     * TRUNCATE CACHE TABLES
     * */
    $query = db_query("SHOW TABLES LIKE 'cache%'");
    $cachetable_result = $query->fetchCol();
    foreach ($cachetable_result as $cachetable_name) {
        db_truncate($cachetable_name)->execute();
        ;
    }
    _okl_dev_watchdoginfo('CACHE done');

    
    _okl_dev_watchdoginfo('CLEANING UP');

    /**
     * CLEAN UP
     * */
    $truncate_tablenames = array(
        //alle biblio-daten
        'biblio_contributor_data',
        'biblio_contributor_type',
        'biblio_contributor_type_data',
        'biblio_duplicates',
        //privatemsg: nachrichten & tags
        'pm_index',
        'pm_message',
        'pm_tags',
        'pm_tags_index',
        //alle suchanfragen
        'search_total',
        'fbss_comments',
        'statuses',
        'workflow_node_history',
        'biblio_keyword_data',
        //failed login attemps
        'flood'
            //
    );
    foreach ($truncate_tablenames as $truncate_tablename) {
        db_truncate($truncate_tablename)->execute();
    }
    //email-notification für privatemsg: user-ids
    db_delete('pm_email_notify')
            ->condition('user_id', $protected_user_uids, 'NOT IN')
            ->execute();

    //realname hat auch n paar leichen
    db_delete('realname')
            ->condition('uid', $protected_user_uids, 'NOT IN')
            ->execute();

    //cleanup broken file_metadata-table
    db_query("delete FROM `file_metadata`
              where fid not IN
             (SELECT fid from file_managed) ; ");
    /*
      //workflow-einträge aufräumen
      db_query("delete FROM `workflow_node`
      where nid not IN
      (SELECT nid from node) ; ");

      db_query("delete FROM `workflow_node_history`
      where nid not IN
      (SELECT nid from node) ; ");
     */
    
    
    
    //file-leichen-einträge aus url-alias-tabelle entfernen

    $url_alias_OR = db_or();
    $url_alias_OR->condition('alias', 'file/file-%', 'LIKE');
    $url_alias_OR->condition('alias', 'file/image-%', 'LIKE');
    $url_alias_OR->condition('alias', 'file/backgroundimage-%', 'LIKE');
    $url_alias_OR->condition('alias', 'file/background-%', 'LIKE');
    db_delete('url_alias')
            ->condition($url_alias_OR)
            ->execute();

    //api-funktionen
    node_access_rebuild();
    devel_rebuild_node_comment_statistics();
    //cleanup done
    _okl_dev_watchdoginfo('CLEANUP done');

    _okl_dev_watchdoginfo('finished');


    variable_set('truncate_environment', FALSE);
}

/**
 * vor massenlöschung müssen ggf irgendwelche preparations durchgeführt werden. 
 * 
 */
function _okl_dev_prepare_deletion() {
    //speichere videosafe-root neu unter admin-uid
    $node = node_load(_videosafe_get_root_directory()->nid);
    $node->uid = 1;
    node_save($node);
}

/**
 * löscht alle files. Ausnahme: Hilfe-header
 */
function _okl_dev_wipe_files() {
    //alle files
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'file')
            //vorauswahl: hilfe-header nicht löschen
            ->propertyCondition('fid', array(NM_HELP_HEADER_FID), "NOT IN");
    $result = $query->execute();
    $fids = array_keys($result['file']);

    //jetzt: files filtern, damit nicht alle gelöscht werden
    $fids_to_delete = [];
    //ausnahmen: profil-/taxonomy-verwendung und defaultimage
    foreach ($fids as $fid) {
        $query = db_select('file_usage', 'fu');
        $query->addField('fu', 'id');
        $query->addField('fu', 'type');
        $query->join('file_managed', 'fm', 'fm.fid = fu.fid');
        $query->condition('fm.fid', $fid, '=');
        //berücksichtige file-usage nur, falls es sich um profil-/defaultimage-/taxonomy-bild handelt. sonst egal!
        $query->condition('fu.type', ["profile2", "default_image", "taxonomy_term"], 'IN');
        $fileusage_count = $query->execute()->rowCount();
        if ($fileusage_count == 0) {
            $fids_to_delete[] = $fid;
        }
    }
    foreach ($fids_to_delete as $fid) {

        try {
            $file = file_load($fid);
            $file->og_group_ref = NULL;
            //include force-parameter!!!
            file_delete($file, TRUE);
        } catch (Exception $e) {
            dpm("fehler bei $fid");
            dpm('Exception abgefangen: ', $e->getMessage());
        }
    }
}

/**
 * Löscht alle nodes, außer ... (siehe code)
 */
function _okl_dev_wipe_nodes() {

    $nodes_nids = db_select('node', 'n')
            ->fields('n', ['nid'])
            //nodes, aber nicht pages und panels
            ->condition('type', ["page", "panel", "plattform_log"], 'NOT IN')
            //hilfe-main-page und videosafe-root wird excluded
            ->condition('nid', [variable_get('okl_help_bid', NM_HELP_BID), _videosafe_get_root_directory()->nid], 'NOT IN')
            ->execute()
            ->fetchCol();

    foreach ($nodes_nids as $nid) {
       
        try {
            node_delete($nid);
        } catch (Exception $e) {
            dpm('Exception abgefangen: ', $e->getMessage());
        }
    }
}

/**
 * Löscht Nutzer außer die übergebenen uids
 * @param array<int> $exept_ids 
 */
function _okl_dev_wipe_users($exept_ids = array(0)) {

    $query = db_select('users', 'u');

    $query->fields('u', array('uid'))
            ->condition('u.uid', $exept_ids, 'NOT IN');
    $user_query_result = $query->execute()->fetchCol();

    foreach ($user_query_result as $user_delete_uid) {

        try {
            user_delete($user_delete_uid);
        } catch (Exception $e) {
            _okl_dev_watchdoginfo('DELETE USER ERROR for ' . $user_delete_uid, array(), WATCHDOG_ALERT);

            dpm('Exception abgefangen: ', $e->getMessage());
        }
    }
    if (count($user_query_result))
        realname_delete_multiple($user_query_result);
    /**
     * DELETE USERS
     * */
    /*
      $query = db_select('users', 'u')
      ->fields('u', ['uid', 'name'])
      ->fields('ur', ['rid']);

      $db_or = db_or()->condition('r.name', ['Administrator', 'Moderator'], 'NOT IN')->isNULL('r.name');
      $query->condition($db_or);

      $query->groupBy('u.uid');
      $query->leftJoin('users_roles', 'ur', 'u.uid = ur.uid');
      $query->leftJoin('role', 'r', 'ur.rid = r.rid');
      $results = $query->execute()->fetchCol();

     */
}

/**
 * Löscht alle Kursforen sowie alle Semester außer default-Semester
 */
function _okl_dev_wipe_taxonomy() {
    /**
     * Taxonomy Terms
     * */
    //todo: alt-semester löschen
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
            ->propertyCondition('name', "Kursforum-(%", "LIKE");
    $result = $query->execute();
    $foren_tids = array_keys($result['taxonomy_term']);

    foreach ($foren_tids as $foren_tid) {
        taxonomy_term_delete($foren_tid);
    }
    //semester löschen
    $semester_vocabulary = taxonomy_vocabulary_machine_name_load('semester');
    $semesters = taxonomy_get_tree($semester_vocabulary->vid);
    //schließe erstes (0th) element aus
    array_shift($semesters);
    //lösche alle anderen semester
    foreach ($semesters as $sem) {
        taxonomy_term_delete($sem->tid);
    }
}

/**
 * lösche h5p-content
 */
function _okl_dev_wipe_h5p() {
    db_truncate('h5p_events')->execute();
}
