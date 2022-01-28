<?php

namespace Page\node\course_content;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of CoursegroupCreate
 *
 * @author Bernhard
 */
class CoursegroupCreate extends CourseContentBase implements \Page\node\ContentCreateInterface {

    /**
     * Declare UI map for this page here. CSS or XPath allowed.
     */
    public function __construct(\AcceptanceTester $I, $course_nid) {
        parent::__construct($I, $course_nid, NM_COURSE_GROUP);
    }

    public function fillFields(\AcceptanceTester $I, \Codeception\Example $params) {

        $I->fillCkeEditorByAPI('edit-body-und-0-value', $params['body']);

        //nun kommt "speichern"
    }

    /**
     * get node-id of lately created course
     * @return int $nid
     */
    public function getNewNid() {
        $I = $this->tester;
        return $I->grabFromCurrentUrl('~course/groups/\d+/(\d+)~');
    }

}
