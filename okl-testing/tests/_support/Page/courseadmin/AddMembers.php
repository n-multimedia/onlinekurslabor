<?php

namespace Page\courseadmin;

class AddMembers {

    // include url of current page
    public static $URL = 'course/admin/%s/members/add?og_group_ref=%s';
    
    public static $userAddField = 'import_container[import_users]';
    public static $confirmButton = 'Importieren';
    
    public static $teilnehmendeMenuButton = 'Teilnehmende';
    

    //müsstman refactorn, betrifft wohl mehrere bereiche
    public static $coursemenu_class = '.section_navigation_course';
    
    /* created in constructor */
    public $course_memberadd_url; 
 
     
    
    public function __construct(\AcceptanceTester $I, $course_nid) {
        $this->tester = $I;
        $this->course_memberadd_url = self::route($course_nid);
    }


    /**
     * 
     * @param type $name
     * @param type $mail
     * @return \Page\courseadmin\AddMembers
     */
    public function addByNameAndMail($name, $mail) {

        $I = $this->tester;

        $I->amOnPage($this->course_memberadd_url);


        $I->expect('AK-2: Vor-Nachname und E-Mail angegeben:');

        $I->expect('AK-2.2: Existiert kein Account, wird einer angelegt.');
        $I->fillField(self::$userAddField, $name . " " . $mail);
        $I->click(self::$confirmButton);
        //angepasst an defaultavatar-timeout
        $I->wait(12);

        $I->see("Student " . $name . " wurde angelegt.");
        //schau auf TN-Seite
        $this->confirmSuccessfulAdding($I, $name);

        return $this;
    }
    
    /**
     *
     * Add existing user to a course
     * @param type $mail
     * @return \Page\courseadmin\AddMembers
     */
    public function addByMail($mail) {

        $I = $this->tester;

        $I->amOnPage($this->course_memberadd_url);

        $I->fillField(self::$userAddField, $mail);
        $I->click(self::$confirmButton);
        //Müsst langen
        $I->wait(5);

        $I->see("Erfolgreich hinzugefügt");
        $I->see($mail);
        $I->cantSee("Kein Account vorhanden");

        //lade existing user und name
        $name = format_username(user_load_by_mail($mail));
        //schau auf TN-Seite
        $this->confirmSuccessfulAdding($I, $name);

        return $this;
    }


    /**
     * Confirm, that the new user is visible on the Teilnhemende-List
     * @param \AcceptanceTester $I
     * @param type $name
     */
    private function confirmSuccessfulAdding(\AcceptanceTester $I, $name)
    {
        //neuer student taucht in der Liste auf
        $I->click(self::$teilnehmendeMenuButton,self::$coursemenu_class);
        $I->see($name);
    }

    /**
     * Basic route  for your current URL
     * You can append any additional parameter to URL
     * and use it in tests like: Page\Edit::route('/123-post');
     */
     public static function route($param) {
        return sprintf(static::$URL,  $param,$param);
    }

}
