<?php

namespace Page\courseadmin;

class MemberAdminCoursegroup extends MemberAdmin {

    // include url of current page
    public static $URL = 'course/admin/%s/members?og_group_ref=%s';
    public static $kursgruppenMenuButton = 'Kursgruppe';
 



    public function __construct(\AcceptanceTester $I, $course_nid) {
        parent::__construct($I, $course_nid);
    }

    /**
     * Add a student to a coursegroup. Course-Nid defined in constructor.
     * @param array $student - needs name + mail
     * @param String $coursegroup_title  
     * @return \Page\courseadmin\AddMembers
     */
    public function addStudentToCoursegroup($student, $coursegroup_title) {

        return $this->addMultipleStudentsToCoursegroup(array($student), $coursegroup_title);
    }
    
    
    
    
    /**
     * Add multiple students to a coursegroup. Course-Nid already defined in constructor.
     * @param array $students - an array with entries with keys   name , mail
     * @param String $coursegroup_title 
     * @return \Page\courseadmin\AddMembers
     */
    public function addMultipleStudentsToCoursegroup($students, $coursegroup_title) {

        $I = $this->tester;
        $I->amOnPage($this->memberadmin_url);

        $this->selectBulkOperation('Einer Kursgruppe zuweisen');

        foreach ($students as $student) { 
            //td instead of tr for firefox
            $I->clickTagContaining('td', $student['mail']);
        }
        $I->click(parent::$executeButton);
        $I->wait(1);
        $I->clickTagContaining('label', $coursegroup_title);
        $I->click(parent::$forwardButton);

        $I->click(parent::$confirmButton);
        $I->wait(8);
        //typo ist korrekt...
        $strEntries = count($students) > 1 ? count($students).' Einträge': '1 Eintrag';
        $I->see("Die Operation Einer Kursgruppe zuweisen an ".$strEntries." wurde ausgeführt.");


        //do the confirmation stuff
        $I->click(self::$kursgruppenMenuButton);
        $I->click($coursegroup_title);
        
        
        foreach ($students as $student) {
            //multi-byte safe substr, da an dieser stelle durch ... gekürzt
            $I->see(mb_substr($student['name'], 0, 11, 'UTF-8'));
        }
    }

}
