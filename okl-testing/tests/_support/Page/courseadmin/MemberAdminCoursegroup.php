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

        $I = $this->tester;

        $I->amOnPage($this->memberadmin_url);

        $this->selectBulkOperation('Einer Kursgruppe zuweisen');

        $I->checkOptionByValue($student['uid']);
        $I->click(parent::$executeButton);
        $I->checkOptionByValue($coursegroup['nid']);
        $I->click(parent::$forwardButton);

        $I->click(parent::$confirmButton);
        $I->wait(8);
        $I->see("Die Operation Einer Kursgruppe zuweisen an 1 Eintrag wurde ausgeführt.");


        //do the confirmation stuff

        $I->click(self::$kursgruppenMenuButton);
        $I->click($coursegroup['name']);
        //substr, da an dieser stelle durch ... gekürzt
        $I->see(substr($student['name'], 0, 11));
    }

}
