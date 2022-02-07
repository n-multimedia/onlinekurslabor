<?php
namespace RealisticFaker;
use Faker;
require_once(__DIR__ . '/OklGenerator.php');
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of OklFactory
 *
 * @author Bernhard
 */
class OklFactory extends \RealisticFaker\Factory {
  //put your code here
   public static function create($identifier = null, $langcode = 'de_DE') {
    //$generator = new \RealisticFaker\OklGenerator($identifier, $langcode);
    return parent::create($identifier , $langcode  ,"\RealisticFaker\OklGenerator");
  }
}
