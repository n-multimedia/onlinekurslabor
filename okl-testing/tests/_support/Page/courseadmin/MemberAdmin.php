<?php

namespace Page\courseadmin;

class MemberAdmin {

    // include url of current page
    public static $URL = 'course/admin/%s/members?og_group_ref=%s';
    
    public static $bulkOperationSelect = '#edit-operation';
     
    public static $executeButton = 'Ausführen';
    public static $forwardButton = 'Weiter';
    public static $confirmButton = 'Bestätigen';
    
   

    /* created in constructor */
    public $memberadmin_url;

    public function __construct(\AcceptanceTester $I, $course_nid) {
        $this->tester = $I;
        $this->memberadmin_url = self::route($course_nid);
    }

    /**
     * Basic route  for your current URL
     * You can append any additional parameter to URL
     * and use it in tests like: Page\Edit::route('/123-post');
     */
    public static function route($param) {
        return sprintf(static::$URL, $param, $param);
    }

    /**
     * In Kursadmin: Wähle Bulkoperation aus. z.B. Kursrolle zuweisen 
     * @param String $title  z.B. Kursruolle zuweisen 
     */
    public function selectBulkOperation($title) {
        $I = $this->tester;
        $I->selectOption(static::$bulkOperationSelect, $title);
    }

}
