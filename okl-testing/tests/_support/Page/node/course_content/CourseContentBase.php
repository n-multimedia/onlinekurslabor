<?php

namespace Page\node\course_content;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of CourseContentBase
 *
 * @author Bernhard
 */
class CourseContentBase extends \Page\node\Node {
    
    private static $baseAddURL = '/course/admin/%s/add/%s?og_group_ref=%s';
    //private static $baseEditURL = '...';

    public function __construct(\AcceptanceTester $I, $course_nid, $new_content_type) {
        parent::__construct($I);
        parent::$createURL = sprintf(self::$baseAddURL, $course_nid, $new_content_type, $course_nid);
        
    }


}
