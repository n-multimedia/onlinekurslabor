<?php
/**
 * User: SN
 */


define('DRUPAL_ROOT', getcwd() . "/../web/");


require_once DRUPAL_ROOT . '/includes/bootstrap.inc';

//fix missing REMOTE ADDR Notice
if (empty($_SERVER['REMOTE_ADDR'])) {
  $_SERVER['REMOTE_ADDR'] = "127.0.0.1";
}
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

