<?php

use \Codeception\Util\Fixtures;
use Page\UserCreate as UserCreatePage;
use Page\courseadmin\AddMembers as AddMembersPage;
use Page\node\course\CourseCreate as CreateCoursePage;
use Page\node\course\CourseEdit as EditCoursePage;
use Page\node\domain\DomainCreate  as CreateDomainPage;
use Page\node\domain\DomainEdit  as EditDomainPage;
use Page\node\domain_content\InteractiveCreate  as CreateInteractiveVideoPage;
use Page\node\course_content\CoursegroupCreate as CreateCoursegroupPage; 
use Page\courseadmin\MemberAdminCoursegroup as AddMemberToCoursegroupPage; 


/**
 * PrepareCest hat einen Sonderstatus und kann nur komplett durchgelaufen werden.
 * Das Ausführen einzelner Funktionen ist nicht möglich.
 */
class PrepareCest extends CestHelper{

    //create: 3 dozenten
    public static $count_dozents = 3;
    //create: 10 studis
    public static $count_students = 10;
    //+
    //1 course
    //$count_students/3 coursegroups
    //assign studis to groups

     protected function getMaincontextType() {
        return NM_COURSE; 
    }

     /**
     * @UserStory null
     * @UserStoryURL null
     * 
     * @param \Step\Acceptance\SuperAdmin $I (instead of type \AcceptanceTester) 
     * @before skipIfNotInPrepareMode
     */
     public function P001_01_logSuperAdminIn(\Step\Acceptance\SuperAdmin $I) {
         //login ist in diesem cest gültig, bis logout geschieht
           $I->loginAsSuperAdmin(true);
         
     }
    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\SuperAdmin $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $example Example-array
     * @dataProvider P001_dummyTeachersProvider
     * @depends P001_01_logSuperAdminIn
     * @before renewSession 
     */
    public function P001_02_createTeachers(\Step\Acceptance\SuperAdmin $I, \Codeception\Example $example) {
        
        if (!user_load_by_mail($example['mail'])) {

            $createPage = new UserCreatePage($I);
            $createPage->create($example);
        }

        // Fixtures::add('created_persons', $example);
    }

    /**
     * Funktion ist der dataprovider für P001_01_createTeachers und  P001_06_addDozentenToCourse
     * @return \Codeception\Example $example
     */
    protected function P001_dummyTeachersProvider() {
        return $this->DP_getSampleTeachers(self::$count_dozents, 0, false);
    }
    
    /**
     * @UserStory null
     * @UserStoryURL null
     * 
     * Als eigener Eintrag. Bei @before-Syntax würde würde er bei jedem Beispiel versuchen, sich neu einzuloggen
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $random_teacher A single teacher
     * @dataprovider P001_dummySingleTeacherProvider
     * @depends P001_02_createTeachers
     */
    public function P001_03_switchUser(\Step\Acceptance\Dozent $I, \Codeception\Example $random_teacher) {
        //do logout to kill session
        $I->logout();
        $I->amGoingTo('Login as ' . $random_teacher['mail']);
        $I->login($random_teacher['mail'], null, true);
    }

    /**
     * Funktion ist der dataprovider für P001_03_switchUser und  usage in P001_07_addDozentenToCourse
     * @return \Codeception\Example $example returns a teacher
     */
    protected function P001_dummySingleTeacherProvider() {

        $all_teachers = $this->P001_dummyTeachersProvider();
        //geseedeter RealisticFaker für nachvollziehbarkeit
        $single_teacher = \RealisticFaker\OklDataCreator::get(_okl_testing_get_dataprovider_identifier())->randomElement($all_teachers);
        //providers müssen immer array(data1, data..n) sein
        return array($single_teacher);
    }
    
    /**
     * Die Differenz zwischen P001_dummyTeachersProvider und P001_dummySingleTeacherProvider
     * Funktion ist der dataprovider für P001_03_switchUser und  usage in P001_07_addDozentenToCourse
     * @return \Codeception\Example $example returns a teacher
     */
    protected function P001_otherTeacherProvider() {
        $all_teachers = $this->P001_dummyTeachersProvider();
        $other_teachers = $all_teachers;
         
        $single_teacher = $this->P001_dummySingleTeacherProvider()[0];
        //array_diff wär evtl auch eine option gewesen
        foreach($other_teachers as $ct =>  $teacher)
        {
            if($teacher['mail'] === $single_teacher['mail'] )
            {
                unset($other_teachers[$ct]);
            }
        }
        //in der codeception-logik gibt es kein leeres example
        if (empty($other_teachers)) {
            $other_teachers = array($this->getEmptyExample());
        }
        return $other_teachers; 
    }

    
    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $domain_example Example-object
     * @dataProvider P001_createDomainsProvider
     * @depends P001_03_switchUser
     * @before renewSession
     */
    public function P001_04_createDomains(\Step\Acceptance\Dozent $I, Codeception\Example $domain_example) {

        $ccpage = New CreateDomainPage($I);
        $ccpage->create($domain_example);
        
        if(!strstr($domain_example['title'], '(DEMO)'))
        {
            Fixtures::add('domain_title', $domain_example['title'] );
            Fixtures::add('domain_nid', $ccpage->getNewNid());
        }
        else
        {
            Fixtures::add('domain_demo_nid', $ccpage->getNewNid());
        }
    }

    /**
     * der Dataprovider für P001_04_createDomain liefert nötige Variablen
     * @return Codeception\Example $domain_example 
     */
    protected function P001_createDomainsProvider() {
        
       return $this->DP_getSampleDomain(0, true, false);
    }
    /**
     * liefert zu einem Titel einen ähnlichen mit Ende " (DEMO)"
     * @param String $title
     * @return String $title_demo
     */
    protected function getDemoTitleForDomainTitle($title)
    {
        return  trim(substr($title, 0, -7)).' (DEMO)';
    }

    
    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $domain_content_example Example-object
     * @dataProvider P001_createDomainContentProvider
     * @depends P001_04_createDomains
     * @before skipIfOnShittyBrowser
     * @before renewSession
     */
    /**
     * ACHTUNG
     * createDomainContent -  chrome verschluckt sich. deswegen funktion durch PRIVATE auf nicht-auszuführen gesetzt
     */
    private function P001_05_createDomainContent(\Step\Acceptance\Dozent $I, Codeception\Example $domain_content_example) {
        $domain_nids = [Fixtures::get('domain_nid'), Fixtures::get('domain_demo_nid')];
        foreach ($domain_nids as $nid) {
            //create H5Ps
            $civPage = new CreateInteractiveVideoPage($I, $nid);
            $civPage->create($domain_content_example);
            $iv_nid = $civPage->getNewNid();
            //edit domain  and include h5p in page
            $domain_node  = node_load($nid); 
            $domain_text = $domain_node->field_domain_description[LANGUAGE_NONE][0]['value'];
 
            $edit_sample = ['body' => $domain_text.'[h5p]'.$iv_nid.':'.$domain_content_example['title'].'[/h5p]' ];
            $edDomainPage = new EditDomainPage($I, $nid);
            $edDomainPage->edit(new Codeception\Example($edit_sample));
            $I->see("Interaktives Video");
        }
    }

    /**
     * der Dataprovider für P001_05_createDomainContent liefert nötige Variablen
     * @return Codeception\Example $course_example 
     */
    protected function P001_createDomainContentProvider() {
        $return = array();
        $rand_data = \RealisticFaker\OklDataCreator::get('domaincontent_' . _okl_testing_get_dataprovider_identifier());
        //@todo: move fixed Videoname "berries sample" to a config
        $return[] = ['title' => implode(' ', $rand_data->words(4)), 'h5p_type' => 'Interactive Video', 'videoname' => 'berries sample'];
        return $return;
    }

    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $example Example-object
     * @dataProvider P001_createCourseProvider
     * @depends P001_04_createDomains
     * @before renewSession
     */
    public function P001_06_createCourse(\Step\Acceptance\Dozent $I, Codeception\Example $course_example) {
        
        $course_example['domain_title'] = Fixtures::get('domain_title');
                
        //refactored
        $createcoursepage = new CreateCoursePage($I);
        $createcoursepage->create($course_example);

        $home_nid = $createcoursepage->getNewNid();
        $I->comment('The nid of my new course is ' . $home_nid);
        $this->setCurrentContextNid($home_nid);
    }

    /**
     * der Dataprovider für P001_06_createCourse liefert nötige Variablen
     * @return Codeception\Example $course_example 
     */
    protected function P001_createCourseProvider() {
        return $this->DP_getSampleCourse(0, false);
    }
    
     /**
     * @UserStory null
     * @UserStoryURL null
     *  Weil man "bearbeiten" ja auch braucht... 
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $example Example-object
     * @dataprovider P001_createDomainsProvider
     * @depends P001_06_createCourse
     * @before renewSession
     */
    public function P001_07_editCourse(\Step\Acceptance\Dozent $I, Codeception\Example $domain_example) {
        $new_course_nid = $this->getCurrentContextNid();

        if (strstr($domain_example['title'], '(DEMO)')) {
            $demo_domain_title = $domain_example['title'];
            $course_edit = ['domain_demo_title' => $demo_domain_title];
            $course_edit_example = new Codeception\Example($course_edit);
            $editcoursepage = new EditCoursePage($I, $new_course_nid);
            $editcoursepage->edit($course_edit_example);
        }
        else
        {
            $I->comment("skipping non-demo domain");
        }
    }

    /**
     * Add students to the newly created course
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $students_example Example-array mit name und mail
     * @dataProvider P001_addStudentsProvider
     * @depends P001_07_editCourse
     * @before renewSession
     */
    public function P001_08_addStudentsToCourse(\Step\Acceptance\Dozent $I, Codeception\Example $students_example) {
        $I->comment(sprintf('now I add memmber %s to the course %s' ,$students_example['mail'], $this->getCurrentContextNid()));

        //use AddMembersPage
        $addmempage = new AddMembersPage($I, $this->getCurrentContextNid());
        $addmempage->addByNameAndMail($students_example["name"], $students_example["mail"]);
        
         //und danach editiere useraccounts mit drupal-api
          /* das geht nicht. Gibt ein Problem mit htmlpurifier :-(( (auch als admin)
        $curr_students_drupal_account = user_load_by_mail('wieland.zimmer+autotest@div.onlinekurslabor.de');
        $student_password_edit['pass'] = NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT;
        user_save($curr_students_drupal_account, $student_password_edit);*/
        
         
    }

    /**
     * Funktion ist der dataprovider für P001_06_addStudentsToCourse 
     * @return \Codeception\Example $example
     */
    protected function P001_addStudentsProvider() {
        return $this->DP_getSampleStudents(self::$count_students, 0, false);
    }

    /**
     * Add other created teachers to the newly created course
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $dozenten_example Example-array with name / mail
     * @uses P001_dummySingleTeacherProvider Infos about currently loggedin dozent
     * @dataProvider P001_otherTeacherProvider
     * @before skipEmptyExample
     * @depends P001_06_createCourse
     * @before renewSession
     */
     public function P001_09_addDozentenToCourse(\Step\Acceptance\Dozent $I, Codeception\Example $dozenten_example) {

        //das geht nicht mehr, da sich nach Vorbereitung der Dataprovider der Identifier geänert hat:
        //$current_teacher = $this->P001_dummySingleTeacherProvider()[0];
        $I->comment(sprintf('now I add teacher %s to the course %s', $dozenten_example['mail'], $this->getCurrentContextNid()));

        //use AddMembersPage
        $addmempage = new AddMembersPage($I, $this->getCurrentContextNid());
        $addmempage->addByMail($dozenten_example["mail"]);
    }

    /**
     * Add coursegroups to course
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $cg_example Example-array with name / body
     * doesnt @uses P001_dummySingleTeacherProvider Infos about currently loggedin dozent
     * @dataProvider P001_createCoursegroupsProvider
     * @depends P001_06_createCourse
     * @before renewSession
     */
    public function P001_10_addCoursegroups(\Step\Acceptance\Dozent $I, Codeception\Example $cg_example) {
        //$current_teacher = $this->P001_dummySingleTeacherProvider()[0];
        //course-nid
        $course_nid = $this->getCurrentContextNid();

        $cg_page = new CreateCoursegroupPage($I, $course_nid);
        $cg_page->create($cg_example);
    }

    /**
     * der Dataprovider für P001_09_addCoursegroups liefert nötige Variablen
     * @return Codeception\Example $course_example 
     */
    protected function P001_createCoursegroupsProvider() {
        //minimum 1, sonst student/3 gruppen
        $num_groups = max(array(floor(self::$count_students / 3),1)); 
        return $this->DP_getSampleCoursegroups($num_groups, 0, false);
    }
    
    
   /**
     * Add students to coursegroups  
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $users_to_coursegroup Example-array ['users' =>array(), 'coursegroup_title'=> ...]
     * @dataProvider P001_addUsersToCoursegroupsProvider
     * @depends P001_10_addCoursegroups
     * @before renewSession
     */
    public function P001_11_addUsersToCoursegroups(\Step\Acceptance\Dozent $I, Codeception\Example $users_to_coursegroup) {

        $cgaddpage = new AddMemberToCoursegroupPage($I, $this->getCurrentContextNid());
        $cgaddpage->addMultipleStudentsToCoursegroup($users_to_coursegroup['users'], $users_to_coursegroup['coursegroup_title']);
    }

    /**
     * list uf users to assign to couresgrups. 
     * used in P001_11_addStudentsToCoursegroups
     * @return array [$users, $title]
     */
    protected function P001_addUsersToCoursegroupsProvider() {
        return $this->DP_getSampleUsersToCoursegroups(self::$count_students, max(1, floor(self::$count_students / 3)), 0, false);
    }

    /**
     * store what has been created  
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @depends P001_11_addUsersToCoursegroups
     * @before renewSession
     */
    public function P001_19_storeFallback(\Step\Acceptance\Dozent $I) {
        _okl_testing_storeFallbackNID($this->getCurrentContextNid());
        _okl_testing_set_fallback_identifier();
        $I->comment("stored fallback-course.");
    }
    
    /**
     * Cleanup  
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     */
    public function P001_20_cleanUp(\Step\Acceptance\Dozent $I) {
        _okl_testing_stop_prepare_cest();
    }

    
    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @depends P001_01_logSuperAdminIn
     * @before renewSession
     */
    public function P001_20_logOut(\Step\Acceptance\Dozent $I){
        $I->logout();
    }

}


