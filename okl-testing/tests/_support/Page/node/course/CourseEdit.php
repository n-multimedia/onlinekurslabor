<?php

namespace Page\node\course;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of Edit
 *
 * @author Bernhard
 */
class CourseEdit extends CourseBase implements \Page\node\NodeEditInterface {

    public function __construct(\AcceptanceTester $I, $course_nid) {
        //$course = node_load($course_nid);
        \Page\node\Node::__construct($I);
        self::$editURL = sprintf('course/admin/%s/settings?og_group_ref=%s', $course_nid, $course_nid);
    }

    /**
     * Edit a Node
     * @param \AcceptanceTester $I
     * @param \Codeception\Example $params  an array containing values 
     */
    public function editFields(\AcceptanceTester $I, \Codeception\Example $params) {
        if (!empty($params['domain_title'])) {
            $this->setDomain($I, $params['domain_title']);
        }
        if (!empty($params['domain_demo_title'])) {
            $this->setDomain($I, $params['domain_demo_title'], true);
        }
    }

}
