<?php

function nm_login_vhb_entity_info() {
  $info['nm_login_vhb_entry'] = array(
    'label' => t('NM Login VHB - Entry'),
    'controller class' => 'NMLoginVhbEntryController',
    'base table' => 'nm_login_vhb',
    //'uri callback' => 'nm_login_vhb_entry_uri',
    'fieldable' => FALSE,
    'entity keys' => array(
      'id' => 'uid',
    ),
    'static cache' => TRUE,
    'label callback' => 'nm_login_vhb_entry_label',
    'bundles' => array(
      'nm_login_vhb_entry' => array(
        'label' => 'nm_login_vhb_entry',
      /* 'admin' => array(
        'path' => 'admin/structure/postit/manage',
        'access arguments' => array('administer users'),
        ), */
      ),
    ),
    'view modes' => array(
      'full' => array(
        'label' => t('Full'),
        'custom settings' => FALSE,
      ),
    )
  );

  return $info;
}


function nm_login_vhb_entry_label($entity, $entity_type) {
  $user = user_load($entity->uid);
  return $user->name . ' (' . date('d.m.Y',$entity->created) . ')' ;
}

function nm_login_vhb_entry_load($uid = NULL, $reset = FALSE) {
  $uids = (isset($uid) ? array($uid) : array());
  $entry = nm_login_vhb_entry_load_multiple($uids, $reset);
  return $entry ? reset($entry) : FALSE;
}

function nm_login_vhb_entry_load_multiple($uids = array(), $conditions = array(), $reset = FALSE) {
  return reset(entity_load('nm_login_vhb_entry', $uids, $conditions, $reset));
}

/**
 * @file
 * Controller class definition file for the example "DUG meeting topic" entity.
 */

/**
 * NMLoginVhbEntryController Controller
 */
class NMLoginVhbEntryController extends DrupalDefaultEntityController {}

