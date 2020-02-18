<?php

/**
 * @file
 * environment_indicator_feature.default_environment_indicator_environments.inc
 */

/**
 * Implements hook_default_environment_indicator_environment().
 */
function environment_indicator_feature_default_environment_indicator_environment() {
  $export = array();

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'dev_environment';
  $environment->name = 'dev environment';
  $environment->regexurl = '(dev|dev-vince).*';
  $environment->settings = array(
    'color' => '#FEBC44',
    'text_color' => '#ffffff',
    'weight' => '3',
    'position' => 'top',
    'fixed' => 1,
  );
  $export['dev_environment'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'live_environment';
  $environment->name = 'Live';
  $environment->regexurl = '(?<!div\\.)online.*';
  $environment->settings = array(
    'color' => '#000000',
    'text_color' => '#ffffff',
    'weight' => '2',
    'position' => 'top',
    'fixed' => 1,
  );
  $export['live_environment'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'test_environment';
  $environment->name = 'test environment';
  $environment->regexurl = '.*test.*';
  $environment->settings = array(
    'color' => '#A5073E',
    'text_color' => '#ffffff',
    'weight' => '4',
    'position' => 'top',
    'fixed' => 1,
  );
  $export['test_environment'] = $environment;

  return $export;
}
