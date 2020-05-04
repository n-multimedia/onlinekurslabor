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

    
 
    public function setDomain(\AcceptanceTester $I, $domain_title, $is_demo = false) {
        $fieldName = $is_demo ? self::$domainDemoField : self::$domainField;

        $I->click("Lehrtext",self::$formEditContext);
        //cutte ggf. falsche zeichen am ende des titels
        $I->fillField($fieldName, trim(substr($domain_title, 0, -3)));
        $I->wait(5);
        //das geht.
        $I->click($domain_title);
    }

}
