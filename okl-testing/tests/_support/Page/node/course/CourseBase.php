<?php

namespace Page\node\course;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * generel information about courses. 
 *
 * @author Bernhard
 */
class CourseBase extends \Page\node\Node {

    /**
     * Declare UI map for this page here. CSS or XPath allowed.
     */
    public static $semesterSelect = 'field_semester[und]';
    public static $timespan2field = 'field_time_span[und][0][value2][date]';
    public static $domainField = 'field_domain_ref[und]';
    public static $domainDemoField = 'field_domain_demo_ref[und]';

    
 
    /**
     * setze Lehrtext in Kurs
     * @param \AcceptanceTester $I
     * @param type $domain_title Tiel des Lehrtexts
     * @param boolean $is_demo Nicht Lehrtext, sondern Demolehrtext einbinden
     */
    public function setDomain(\AcceptanceTester $I, $domain_title, $is_demo = false) {
    $fieldName = $is_demo ? self::$domainDemoField : self::$domainField;
    $I->click("Lehrtext", self::$formEditContext);
    //cutte ggf. falsche zeichen am ende des titels
    $I->fillField($fieldName, trim(substr($domain_title, 0, -3)));
    $I->wait(6);
    //FF-freundliche Alternative zu: $I->click($domain_title);
    $I->clickWithLeftButton(['css' => 'input[name="' . $fieldName . '"]'], 0, 30);
    $I->see($domain_title);
  }

}
