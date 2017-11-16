<?php

/**
 * @file
 * Contains FAPI and theme functions for the format settings form.
 * @see okl_dev_menu
 */
function okl_dev_truncate_form($form, &$form_state) {


    $executed_infos = array();
    $executed_infos[] = 'delete empty folders:  rm -rf ../files_private/h5p/content/* sites/default/files/h5p/content/* sites/default/files/oembed/* sites/default/files/resize/* sites/default/files/styles/* ../files_private/resize/* ../files_private/styles/* ';
    $executed_infos[] = 'change siteinfo:  ' . l('Site-Information', 'admin/config/system/site-information');

    #$form = array();

    $form['truncate_info'] = array(
        '#type' => 'fieldset',
        '#title' => t('Truncate Database'),
    );
    //$form_state['executed']: Löschen ausgeführt, nur noch Infos ausgeben
    if ($form_state['executed']) {
        

        $form['truncate_info']['executed'] = array(
            '#type' => 'markup',
            '#markup' => t('<b>Truncate has ended. All gone now :( </b>'),
        );
        $form['truncate_info']['no_worries'] = array(
            '#type' => 'markup',
            '#markup' => '<br>Errors <i>"Datei konnte nicht gelöscht werden, da es keine..."</i> are no problem.'
        );
        $form['truncate_info']['after'] = array(
            '#type' => 'markup',
            '#markup' => '<br><b>You might want to:</b>' .
            '<ul><li>' .
            implode('</li><li>', $executed_infos) .
            '</li></ul>'
        );
        return $form;
    }

    $delete_candidates = array();
    $delete_candidates[] = 'All users (except guest and ADMIN)';
    $delete_candidates[] = 'Nodes';
    $delete_candidates[] = 'H5P-Content';
    $delete_candidates[] = 'Kursforen-Taxonomy';
    $delete_candidates[] = 'Semester-Taxonomy außer Default';
    $delete_candidates[] = 'Dateien (quasi alle)';
    $delete_candidates[] = 'private-MSG-Einträge';
    $delete_candidates[] = 'nm_login_vhb-Daten';
    $delete_candidates[] = 'Biblio-Einträge';
    $delete_candidates[] = 'Watchdog-Logs';

    $form['truncate_info']['text'] = array(
        '#markup' => '<b>This will delete all of the data in your installation. This includes but is not limited to:</b>' .
        '<ul><li>' .
        implode('</li><li>', $delete_candidates) .
        '</li></ul>' .
        '<b>You also confirm that</b>' .
        '<ul>' .
        '<li>Your server has no timeout-issues</li>' .
        '</ul>'
    );
    $form['truncate_info']['accept'] = array(
        '#type' => 'checkbox',
        # '#name' => 'accept',
        '#required' => TRUE,
        '#title' => t('I have read and agree to that'),
    );
    $form['truncate_info']['secret_password'] = array(
        '#type' => 'password',
        # '#name' => 'password',
        '#required' => TRUE,
        '#title' => t("Enter admin's password again:"),
    );
    $form['truncate_info']['button'] = array(
        '#type' => 'submit',
        '#value' => t('Go for it!'),
        '#submit' => array('okl_dev_truncate_form_submit'),
        '#attributes' => array('class' => array('btn', 'btn-warning')),
    );

    return $form;
}

/**
 * okl_dev_truncate_form - validate password
 * @param type $form
 * @param type $form_state
 * @return type
 */
function okl_dev_truncate_form_validate($form, &$form_state) {
    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
    //prüfe admin-passwort
    if (!user_check_password($form_state['values']['secret_password'], user_load(1))) {
        form_set_error('password', t('You have entered an invalid password.'));
    }
    return;
}

/**
 * okl_dev_truncate_form: submit
 * nach validate kommt submit
 * @param array $form
 * @param array $form_state
 * @return string
 */
function okl_dev_truncate_form_submit($form, &$form_state) {
   

    $form_state['rebuild'] = TRUE;

    _okl_dev_wipe_all_data();
    return $form;
}
