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
class Create extends Base implements \Page\node\NodeCreateInterface {
    
     /**
     * Declare UI map for this page here. CSS or XPath allowed.
     */
    //siehe Base

    public function __construct(\AcceptanceTester $I) {
       \Page\node\Node::__construct($I, NM_COURSE);
    }

    public function fillFields(\AcceptanceTester $I, \Codeception\Example $params) {
        $I->selectOption(self::$semesterSelect, $params['currentSemesterName']);
        $I->fillField(self::$timespan2field, date('m/d/Y', time() + 31 * 24 * 60 * 60));
        //Lehrtext
        if(!empty($params['domain_title']))
        {
           $this->setDomain($I, $params['domain_title']);
        }
        if(!empty($params['domain_demo_title'])) 
        {
           $this->setDomain($I, $params['domain_demo_title']);
        }
    }

    /**
     * get node-id of lately created course
     * @return int $nid
     */
    public function getNewNid() {
        $I = $this->tester;
        return $I->grabFromCurrentUrl('~/course/home/(\d+)~');
    }

}
