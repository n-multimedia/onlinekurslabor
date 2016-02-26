<?php

function nm_login_vhb_entity_info() {
  $info['nm_login_vhb_entry'] = array(
    'label' => t('NM Login VHB - Entry'),
    'entity class' => 'NMLoginVhbEntry',
    'controller class' => 'NMLoginVhbEntryController',
    'base table' => 'nm_login_vhb',
    'deletion callback' => 'nm_login_vhb_entry_delete',
    //'uri callback' => 'nm_login_vhb_entry_uri',
    'fieldable' => FALSE,
    'entity keys' => array(
      'id' => 'uid',
      'label' => 'entry identifier',
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
 * Delete single.
 */
function nm_login_vhb_entry_delete($uid) {
  nm_login_vhb_entry_delete_multiple(array($uid));
}

/**
 * Delete multiple.
 */
function nm_login_vhb_entry_delete_multiple($entry_uids) {
  entity_get_controller('nm_login_vhb_entry')->delete($entry_uids);
}


/**
 * @file
 * Controller class definition file for the example "DUG meeting topic" entity.
 */


class NMLoginVhbEntry extends Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'nm_login_vhb_entry');
  }


  /*
   * https://api.drupal.org/api/examples/entity_example%21entity_example.module/function/entity_example_basic_delete/7
  public function delete(){
    entity_get_controller('nm_login_vhb_entry')->delete($entity);
  }
  */

}



/**
 * NMLoginVhbEntryController Controller
 */
class NMLoginVhbEntryController extends EntityAPIController {

  public function __construct($entityType) {
    parent::__construct($entityType);
  }

}

