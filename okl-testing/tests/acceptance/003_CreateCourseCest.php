<?php
use \Codeception\Step\Argument\PasswordArgument;

class CreateCourseCest {

  public function _before(AcceptanceTester $I) {
   # $I->setCookie('dev_overlay_skip', 'ja', array('path'=>'/',"expiry"=> time() + 24 * 3600)); //gmdate('D, d M Y H:i:s T', time() + 24 * 3600))
        //geht das nicht schöner?? Zugriff auf drupal-Core??
        require_once(dirname(__FILE__) . "/../../..//web/sites/default/settings.php");

        $I->amOnPage('/');
        $I->click('Anmelden');
        $I->fillField('name', 'fahrneul');
        //special command: hide passwd
        $I->fillField('pass', new PasswordArgument(NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT));
        $I->click('Anmelden', '.form-actions');
        
    }

    public function _after(AcceptanceTester $I) {
  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function CC001_01_DozentLoggedin(AcceptanceTester $I) {
        
    $I->amOnPage('/');
    $I->see('Meine Veranstaltungen');
  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function CC001_02_CreateNewCourse(AcceptanceTester $I) {
        $new_course_title = 'Neuer Kurs @' . date('d.m.Y H:i:s');
        
        $I->amOnPage('/');
        
        $I->click('Meine Veranstaltungen');
        $I->click('//a[@title="Kurs erstellen"]');
        
        //Alternativweg über Kurse
       // $I->click('Kurse');
        //$I->click('Neuen Kurs anlegen','.btn-default');
        
        
        $I->amOnPage('/node/add/courses-course');
        $I->see('Courses - Kurs erstellen'); 
        $I->fillField('title', $new_course_title);
        //@todo: Semester aktuell
         $I->selectOption('field_semester[und]', 'SS 18');
         $I->fillField('field_time_span[und][0][value2][date]', date('m/d/Y',  time()+31*24*60*60)); 
         
        
        $I->click('Veröffentlichen', '.form-actions');
        $I->see('Courses - Kurs ' . $new_course_title . ' wurde erstellt.');
        
        //get current url
        // $uri = $I->grabFromCurrentUrl();
        //example $user_id = $I->grabFromCurrentUrl('~$/user/(\d+)/~');
        
    }

    
  
}
