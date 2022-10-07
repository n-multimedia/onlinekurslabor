<?php

use Page\node\course\CourseCreate as CreateCoursePage;
use Page\courseadmin\AddMembers as AddMembersPage;
use Page\node\course_content\CoursegroupCreate as CreateCoursegroupPage;
use Page\courseadmin\MemberAdminCoursegroup as AddMemberToCoursegroupPage; 
use Page\node\course_content\TaskCreate as TaskCreatePage;


class CourseCest  extends CestHelper{
 
     /**
     * setze Typ des aktuellen HauptContexts.
     * Also das, was prinzipiell im aktuellen Cest getestet wird.
     * Entweder NM_COURSE oder NM_CONTENT_DOMAIN
     * 
     * @return string type
     */
    protected function getMaincontextType() {
        return NM_COURSE;
    }

    public function _before(\Step\Acceptance\Dozent $I) {

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
   * @param \Codeception\Example $example array holds dataprovider's data
   * @dataProvider C001_02_CreateCourseProvider
   */
  public function C001_02_CreateCourse(AcceptanceTester $I, \Codeception\Example $example) {
          
        $I->amOnPage('/');
        
        $I->click('Meine Veranstaltungen');
        $I->click('//a[@title="Kurs erstellen"]');
        
        //Alternativweg über Kurse
       // $I->click('Kurse');
        //$I->click('Neuen Kurs anlegen','.btn-default');
        
        
        //refactored
        $createcoursepage = new CreateCoursePage($I);
        $createcoursepage->create($example);
         
        
        //set current nid
        $this->setCurrentContextNid($createcoursepage->getNewNid());
    }
    
    
  /**
   * Funktion ist der dataprovider für C001_02_CreateCourse
   * @return array
   */
  protected function C001_02_CreateCourseProvider() {
        return array($this->getCourseSample(0)); 
    }
    
    
  /**
   * @UserStoryies KD.01 | Kurs - Dozent - andere Dozenten hinzu | TRELLO
   * @param \AcceptanceTester $I
   * @param \Codeception\Example $example array holds dataprovider's data
   * @dataProvider C001_AddDozentenProvider
   * @before skipIfSamplePersonEqualsMe
   */
  public function C001_03_AddOtherDozenten(\Step\Acceptance\Dozent $I, \Codeception\Example $example) {

    $this->goToContextHome($I);

    $course_nid = $I->grabFromCurrentUrl('~/course/home/(\d+)~');
    //annahme: ich bin im neu erstellten Kurs
    $I->useCourseMenu('Teilnehmende');
    $I->see("Teilnehmende hinzufügen");

    $addmempage = new AddMembersPage($I, $course_nid);
    $addmempage->addByMail($example['mail']);
  }

  /**
   * DataProvider für C001_03_AddOtherDozenten
   * @return array
   */
  protected function C001_AddDozentenProvider() {
    $sample = array(); 
    $fallback_teachers = _okl_testing_getFallbackData()->teachers;
    foreach ($fallback_teachers as  $fb_teacher) {
      $sample[]['mail'] = $fb_teacher->mail;
    }
    return $sample;
  }

  /**
   * @UserStoryies KD.01 | Kurs - Dozent - Kursteilnehmer einladen | https://trello.com/c/lr17dgl0/9-kd01-kurs-dozent-kursteilnehmer-einladen
   * @param \AcceptanceTester $I
   * @param \Codeception\Example $example array holds dataprovider's data
   * @dataProvider C001_04_AddMemberProvider
   * @before skipNonApplicableExample
   */
  public function C001_04_AddMember(\Step\Acceptance\Dozent $I,  \Codeception\Example $example) {

    $this->goToContextHome($I);

    $course_nid = $I->grabFromCurrentUrl('~/course/home/(\d+)~');
    //annahme: ich bin im neu erstellten Kurs
    $I->useCourseMenu('Teilnehmende');
    $I->see("Teilnehmende hinzufügen");
    
    $addmempage = new AddMembersPage($I, $course_nid);
    $addmempage->addByNameAndMail($example["name"] , $example["mail"]);
     


    //TODO
    //$I->expect('AK-1: Person wird anhand ihres Namens gefunden');
    //$I->expect('AK-1.1: Nach Klick auf hinzufügen ist die Person Kurs-TN.');
    //$I->expect('AK-2.1: Existiert Account mit E-Mail, wird der Account in den Kurs eingetragen');
    //$I->expect('AK-3: Nur E-Mail angegeben:');
    //$I->expect('AK-3.1: Siehe 2a');
    //$I->expect('AK-3.2: Sonst Fehlermeldung');

  }
  
  
  
  /**
   * Funktion ist der dataprovider für C001_03_AddMember
   * @return array
   */
  protected function C001_04_AddMemberProvider() {
        return $this->DP_getSampleStudents(1, 0, false);
    }

   /**
   * @UserStoryies KD.04 |  Kurs - Dozent - News einstellen | https://trello.com/c/dMBLuhWz/12-kd04-kurs-dozent-news-einstellen
   * @param \AcceptanceTester $I
   * @param \Codeception\Example $news
   * @dataProvider C001_NewsProvider
   */
  public function C001_05_AddNews(\Step\Acceptance\Dozent $I, \Codeception\Example $news) {
    
      $this->goToContextHome($I);
   // $news = [];
   // $news['title'] =  '[CC001_04_AddNews] Neue Ankündigung @' . date('d.m.Y H:i:s');
   //  $news['body'] =  'Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo.';


    //annahme: ich bin im neu erstellten Kurs
    $I->useCourseMenu('Kursinhalte', 'Ankündigung hinzufügen');
    $I->expect('AK-1: Ankündigung lässt sich per wysiwyg erstellen');
    $I->see("Neue Ankündigung erstellen");
    $I->wait(1);
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
  
   /**
     * News Provider for C001_04_AddNews
     * @return type
     */
    protected function C001_NewsProvider() {
        return $this->DP_getSampleNews(1);
    }

    /**
     * @UserStoryi KD.09 - Kurs - Dozent - Kursgruppe anlegen | https://trello.com/c/0w86zeYF/17-kd09-kurs-dozent-kursgruppe-anlegen
     * @param \AcceptanceTester $I
     * @param \Codeception\Example $cg_example Example-array with name / body
     * @dataProvider C001_Coursegroup_Provider
     * @before skipNonApplicableExample
     * 
     */
    public function C001_06_AddCourseGroup(\Step\Acceptance\Dozent $I, \Codeception\Example $course_group) {
        
        $this->goToContextHome($I);

        //annahme: ich bin im neu erstellten Kurs
        $I->useCourseMenu('Kursgruppen', 'Gruppe hinzufügen');
        $I->expect('AK-1: Es kann ein Titel und ein Beschreibugnstext eingegeben werden');
        $I->see("Neue Kursgruppe erstellen");

        $cg_page = new CreateCoursegroupPage($I, $this->getCurrentContextNid());
        $cg_page->create($course_group);
    }
    
    /**
     * der dataprovider für C001_04_AddCourseGroup
     */
    protected function C001_Coursegroup_Provider()
    {
       //wenn im fallback-kurs, brauchen wir keine KG erstellen
       return array($this->getNodeSample(NM_COURSE_GROUP, 0)+['type'=>'default'] );
    }


    /**
     * @UserStoryi KD.09 - Kurs - Dozent - Kursgruppenmitglieder hinzufügen |->TODO https://trello.com/c/0w86zeYF/17-kd09-kurs-dozent-kursgruppe-anlegen
     * @param \AcceptanceTester $I
     * @dataProvider C001_AddUsersToGroupProvider
     * @before skipNonApplicableExample
     */
    public function C001_07_AddUsersToGroup(\Step\Acceptance\Dozent $I, \Codeception\Example $user_to_coursegroup) {

        $this->goToContextHome($I);

        //annahme: ich bin im neu erstellten Kurs
        //doublecheck: menü geht
        $I->useCourseMenu('Teilnehmende', "Teilnehmende verwalten");

        $cgaddpage = new AddMemberToCoursegroupPage($I, $this->getCurrentContextNid());
        $cgaddpage->addStudentToCoursegroup($user_to_coursegroup['user'], $user_to_coursegroup['coursegroup_title']);
    }

    /**
     * Data Provider for C001_05_AddUsersToGroup : 
     * returns array with keys ['user' => ['name','email'], 'coursegroup_title' => ... ];
     * @return array $UsersToGroup
     */
    protected function C001_AddUsersToGroupProvider() {
        $return = array();
        $default_course_group = $this->C001_Coursegroup_Provider()[0];
        $fallback_course_group = _okl_testing_getFallbackData()->random('course_group')->toDataProviderSample();

        //holt gefakten student und fallback als array
        $student_arr = $this->DP_getSampleStudents(1, 0, true);

        foreach ($student_arr as $counter => $student) {

            if ($student['type'] === 'fallback') {
                $cg_title = $fallback_course_group['title'];
            } else {
                $cg_title = $default_course_group['title'];
            }
            //build providerdata
            $return[$counter] = ['user' => ['name' => $student['name'], 'mail' => $student['mail']], 'type' => $student['type'], 'coursegroup_title' => $cg_title];
        }

        return $return;
    }
    

    //##########################################################################

    /**
   * Basic Data Provider with title and body
   * @return type
   */
  protected function C001_BasicDataProvider() {
        $return = array();
        $rand_data = \RealisticFaker\OklFactory::create();
        $return[] = ['title' => $rand_data->realText(40), 'body' => $rand_data->realText(240)];
        return $return;
    }





}
