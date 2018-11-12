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
     * @param array $student - needs name + uid
     * @param array $coursegroup - needs name + nid
     * @return \Page\courseadmin\AddMembers
     */
    public function addStudentToCoursegroup($student, $coursegroup) {

        return $this->addMultipleStudentsToCoursegroup(array($student), $coursegroup);
    }
    
    
    
    
    /**
     * Add a student to a coursegroup. Course-Nid already defined in constructor.
     * @param array $students - an array with entries with keys name , uid
     * @param array $coursegroup with keys name , uid
     * @return \Page\courseadmin\AddMembers
     */
    public function addMultipleStudentsToCoursegroup($students, $coursegroup) {

        $I = $this->tester;
        $I->comment("todo: rewrite: NO nid, NO uid!");
        $I->amOnPage($this->memberadmin_url);

        $this->selectBulkOperation('Einer Kursgruppe zuweisen');

        //@todo: remove UIDs!
        foreach ($students as $student) {
            $I->checkOptionByValue($student['uid']);
        }
        $I->click(parent::$executeButton);
        //@todo: remove NIDs!!
        $I->checkOptionByValue($coursegroup['nid']);
        $I->click(parent::$forwardButton);

        $I->click(parent::$confirmButton);
        $I->wait(8);
        $strEntries = count($students) > 1 ? count($students).' Einträgen': '1 Eintrag';
        $I->see("Die Operation Einer Kursgruppe zuweisen an ".$strEntries." wurde ausgeführt.");


        //do the confirmation stuff
        $I->click(self::$kursgruppenMenuButton);
        $I->click($coursegroup['name']);
        
        
        foreach ($students as $student) {
            //substr, da an dieser stelle durch ... gekürzt
            $I->see(substr($student['name'], 0, 11));
        }
    }

}
