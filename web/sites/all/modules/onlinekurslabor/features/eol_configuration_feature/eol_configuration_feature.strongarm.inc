<?php

/**
 * @file
 * eol_configuration_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function eol_configuration_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eol_countdown_after';
  $strongarm->value = '</a></div>';
  $export['eol_countdown_after'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eol_countdown_before';
  $strongarm->value = '<div class="okl-death-container" title="Mehr Informationen dazu..."><a  href="/node/56675"><span class="okl-death-link">Betriebsende der Plattform in: </span><br>';
  $export['eol_countdown_before'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eol_countdown_enddate';
  $strongarm->value = '01.11.2023 23:59:59';
  $export['eol_countdown_enddate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eol_countdown_hide_days_secs';
  $strongarm->value = 1;
  $export['eol_countdown_hide_days_secs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eol_countdown_theme';
  $strongarm->value = 'black eol_countdown_small_theme ';
  $export['eol_countdown_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eol_countdown_whiteout';
  $strongarm->value = 1;
  $export['eol_countdown_whiteout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'eol_countdown_whiteout_message';
  $strongarm->value = 'Das Onlinekurslabor ist dauerhaft offline.
Ihr Medienlabor';
  $export['eol_countdown_whiteout_message'] = $strongarm;

  return $export;
}
