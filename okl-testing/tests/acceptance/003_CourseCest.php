<?php

use \Codeception\Util\Fixtures;


class CourseCest {


  private $fallback_course_url = "/course/home/11294";


  public function _before(\Step\Acceptance\Dozent $I) {
    # $I->setCookie('dev_overlay_skip', 'ja', array('path'=>'/',"expiry"=> time() + 24 * 3600)); //gmdate('D, d M Y H:i:s T', time() + 24 * 3600))
    //geht das nicht schöner?? Zugriff auf drupal-Core??

    $I->loginAsDozent(TRUE);

  }

  public function _after(AcceptanceTester $I) {

  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function C001_01_DozentLoggedin(AcceptanceTester $I) {

    $I->amOnPage('/');
    $I->see('Meine Veranstaltungen');
  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function C001_02_CreateCourse(AcceptanceTester $I) {
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
        $course_home_url = $I->getCurrentUri();
        Fixtures::add('course_home_url', $course_home_url);
    }


  /**
   * @UserStoryies KD.01 | Kurs - Dozent - Kursteilnehmer einladen | https://trello.com/c/lr17dgl0/9-kd01-kurs-dozent-kursteilnehmer-einladen
   * @param \AcceptanceTester $I
   */
  public function C001_03_AddMember(AcceptanceTester $I) {

    try {
      $course_home_url = Fixtures::get('course_home_url');
    } catch (Exception  $ex) {
      //fallback url
      $course_home_url = $this->fallback_course_url;
    }


    $member_student = [];
    $member_student["name"] = "Student Test-" . substr(str_shuffle(str_repeat("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVEXYZ", 5)), 0, 5);;
    $member_student["mail"] = "student.test+CC001_03+" . time() . "@onlinekurslabor.de";

    $I->amOnPage($course_home_url);

    //annahme: ich bin im neu erstellten Kurs
    $I->moveMouseOver( '#instr_overview_members' );
    $I->wait(1);
    $I->click( '#instr_add_members a' );
    $I->see("Teilnehmende hinzufügen");

    $I->expect('AK-2: Vor-Nachname und E-Mail angegeben:');


    $I->expect('AK-2.2: Existiert kein Account, wird einer angelegt.');
    $I->fillField('import_container[import_users]', $member_student["name"] . " " . $member_student["mail"]);
    $I->click( 'Importieren' );
    $I->wait(5);
    $I->see("Student ". $member_student["name"] ."  wurde angelegt.");

    //neuer student taucht in der Liste auf
    $I->click("Teilnehmende");
    $I->see($member_student["name"]);


    //TODO
    //$I->expect('AK-1: Person wird anhand ihres Namens gefunden');
    //$I->expect('AK-1.1: Nach Klick auf hinzufügen ist die Person Kurs-TN.');
    //$I->expect('AK-2.1: Existiert Account mit E-Mail, wird der Account in den Kurs eingetragen');
    //$I->expect('AK-3: Nur E-Mail angegeben:');
    //$I->expect('AK-3.1: Siehe 2a');
    //$I->expect('AK-3.2: Sonst Fehlermeldung');

  }

  /**
   * @UserStoryies KD.04 |  Kurs - Dozent - News einstellen | https://trello.com/c/dMBLuhWz/12-kd04-kurs-dozent-news-einstellen
   * @param \AcceptanceTester $I
   */
  public function C001_04_AddNews(\Step\Acceptance\Dozent $I) {

    try {
      $course_home_url = Fixtures::get('course_home_url');
    } catch (Exception  $ex) {
      //fallback url
      $course_home_url = $this->fallback_course_url;
    }

    $I->amOnPage($course_home_url);
    $news = [];
    $news['title'] =  '[CC001_04_AddNews] Neue Ankündigung @' . date('d.m.Y H:i:s');
    $news['body'] =  'Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo.';


    //annahme: ich bin im neu erstellten Kurs
    $I->moveMouseOver( '#instr_overview_content' );
    $I->wait(1);
    $I->click( '#instr_add_news a' );
    $I->expect('AK-1: Ankündigung lässt sich per wysiwyg erstellen');
    $I->see("Neue Ankündigung erstellen");
    $I->seeElement("#cke_edit-body-und-0-value");

    $I->fillField('title', $news['title']);
    $I->fillCkEditorByName("body[und][0][value]", $news['body']);

    //should also be tested for students
    $I->expect('AK-2: Erscheint für alle Kurs-TN danach auf der Kurs-Startseite');

    $I->click( 'Speichern' );
    $I->see( "Ankündigung " . $news['title'] . " wurde erstellt." );

    $I->click( 'Aktuelles' );
    $I->see( $news['title'] );

    //TODO
    //unkritisch
    //$I->expect('(AK-0: Anhangsfeld wurde entfernt & Content ggf migriert)');
    //$I->expect('AK-3: Ist für ander Kurs-TN danach als "neu" gekennzeichnet');

  }

    
  
}
