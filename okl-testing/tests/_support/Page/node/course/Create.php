<?php

namespace Page\node\course;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of CreateDomainPage
 *
 * @author Bernhard
 */
class Create extends \Page\node\Node implements \Page\node\NodeCreateInterface {
    
     /**
     * Declare UI map for this page here. CSS or XPath allowed.
     */
    public static $semesterSelect = 'field_semester[und]';
    public static $timespan2field = 'field_time_span[und][0][value2][date]';

    public function __construct(\AcceptanceTester $I) {
        parent::__construct($I, NM_COURSE);
    }

    public function fillFields(\AcceptanceTester $I, \Codeception\Example $params) {
        $I->selectOption(self::$semesterSelect, $params['currentSemesterName']);
        $I->fillField(self::$timespan2field, date('m/d/Y', time() + 31 * 24 * 60 * 60));
        if(!empty($params['domain_title'])) //todo fuer demo-lt
        {
            $I->click("Lehrtext");
            //cutte ggf. falsche zeichen am ende des titels
            $I->fillField('field_domain_ref[und]', substr( $params['domain_title'], 0, -3));
            $I->wait(5); 
            //das geht.
            $I->click($params['domain_title']);
        }
    }

    /**
     * TODO....
     * @return int
     */
    public function getNewNid() {
        $I = $this->tester;
        $I->comment(__FUNCTION__ ." NOT IMPLEMENTED");
        return 23479232039;
    }

}
