<?php

use \Codeception\Step\Argument\PasswordArgument;
use \Codeception\Util\Fixtures;
use Page\UserCreate as UserCreatePage;
use Page\courseadmin\AddMembers as AddMembersPage;
use Page\node\course\CourseCreate as CreateCoursePage;
use Page\node\course\CourseEdit as EditCoursePage;
use Page\node\domain\Create  as CreateDomainPage;
use Page\node\domain\Edit  as EditDomainPage;
use Page\node\domain_content\Create_Interactive  as CreateInteractiveVideoPage;

class PrepareCest {

    public $run_identifier;
    //create: 3 dozenten
    public $count_dozents = 3;
    //create: 10 studis
    public $count_students = 10;
    //+
    //1 course
    //3 coursegroups
    //assign studis to groups

    /* ONLY for current run */
    private $current_course_nid = null;

    public function __construct() {
        //identifier für diesen Durchlauf des Cests.  
        $this->run_identifier = _okl_testing_get_test_identifier();
    }

    /* API for test*/
    /**
     * get a "new" dummy person. 
     * The person will always be the same for the same combination of $roles, $this->run_identifier and $ident
     * @param array $roles User's roles (e.g. array('Student'))
     * @param $ident Identifier, e.g. 2 or "hansi"
     * @return array
     */
    private function _getDummyPersonExample(array $roles, $ident) {

        $unique = 'person_' . implode('-', $roles) . $this->run_identifier . $ident;
        $basicvalues = \RealisticFaker\OklDataCreator::get($unique);
        return ['name' => $basicvalues->name, 'firstName' => trim($basicvalues->firstName . ' ' . $basicvalues->middleName), 'lastName' => $basicvalues->lastName, 'mail' => $basicvalues->email, 'roles' => $roles, 'password' => new PasswordArgument(NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT)];
    }
    /*ENDE  API for test*/
    
      
     /**
     * @UserStory null
     * @UserStoryURL null
     * 
     * @param \Step\Acceptance\SuperAdmin $I (instead of type \AcceptanceTester) 
     */
     public function P001_01_logSuperAdminIn(\Step\Acceptance\SuperAdmin $I) {
         //login ist in diesem cest gültig, bis logout geschieht
           $I->loginAsSuperAdmin(false);
         
     }
    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\SuperAdmin $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $example Example-array
     * @dataProvider P001_dummyTeachersProvider
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
        $return = array();
        for ($count = 1; $count <= $this->count_dozents; $count ++) {
            $return[] = $this->_getDummyPersonExample(array(NM_ROLE_DOZENT, NM_ROLE_AUTOR), $count);
        }

        return $return;
    }
    
    /**
     * @UserStory null
     * @UserStoryURL null
     * 
     * Als eigener Eintrag. Bei @before-Syntax würde würde er bei jedem Beispiel versuchen, neu einzuloggen
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $random_teacher A single teacher
     * @dataprovider P001_dummySingleTeacherProvider
     */
    public function P001_03_switchUser(\Step\Acceptance\Dozent $I, \Codeception\Example $random_teacher) {
        //logout
        $I->logout();

        $I->amGoingTo('Login as ' . $random_teacher['mail']);
        //login ist in diesem cest gültig, bis logout geschieht
        $I->login($random_teacher['mail'], null, false);
    }

    /**
     * Funktion ist der dataprovider für P001_03_switchUser und  usage in P001_07_addDozentenToCourse
     * @return \Codeception\Example $example returns a teacher
     */
    protected function P001_dummySingleTeacherProvider() {

        $all_teachers = $this->P001_dummyTeachersProvider();
        //geseedeter RealisticFaker für nachvollziehbarkeit
        $single_teacher = \RealisticFaker\OklDataCreator::get($this->run_identifier)->randomElement($all_teachers);
        //providers müssen immer array(data1, data..n) sein
        return array($single_teacher);
    }

    
    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $domain_example Example-object
     * @dataProvider P001_createDomainsProvider
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
     * @return Codeception\Example $course_example 
     */
    protected function P001_createDomainsProvider() {
        $return = array();
        $rand_data = \RealisticFaker\OklDataCreator::get('domain_' . $this->run_identifier);
        $domain_title = implode(' ',$rand_data->words(4));
        $return[] = ['title' => $domain_title, 'body' => $rand_data->realText(360)];
        $return[] = ['title' =>$this->getDemoTitleForDomainTitle($domain_title), 'body' => $rand_data->realText(120)];
        return $return;
    }
    /**
     * liefert zu einem Titel einen ähnlichen mit Ende " (DEMO)"
     * @param String $title
     * @return String $title_demo
     */
    protected function getDemoTitleForDomainTitle($title)
    {
        return  substr($title, 0, -7).' (DEMO)';
    }

    
    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $domain_content_example Example-object
     * @dataProvider P001_createDomainContentProvider
     */
    public function P001_05_createDomainContent(\Step\Acceptance\Dozent $I, Codeception\Example $domain_content_example) {
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
        $rand_data = \RealisticFaker\OklDataCreator::get('domaincontent_' . $this->run_identifier);
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
     */
    public function P001_06_createCourse(\Step\Acceptance\Dozent $I, Codeception\Example $course_example) {

        
        $course_example['domain_title'] = Fixtures::get('domain_title');
                
        //refactored
        $createcoursepage = new CreateCoursePage($I);
        $createcoursepage->create($course_example);

        $home_nid = $createcoursepage->getNewNid();
        $I->comment('The nid of my new course is ' . $home_nid);

        $this->current_course_nid = $home_nid;
    }

    /**
     * der Dataprovider für P001_06_createCourse liefert nötige Variablen
     * @return Codeception\Example $course_example 
     */
    protected function P001_createCourseProvider() {
        $return = array();
        $rand_data = \RealisticFaker\OklDataCreator::get('course_' . $this->run_identifier);
        //@todo: Semester aktuell
        $return[] = ['title' => $rand_data->text(20), 'currentSemesterName' => $rand_data->currentSemesterName];
        return $return;
    }
    
     /**
     * @UserStory null
     * @UserStoryURL null
     *  Weil man "bearbeiten" ja auch braucht... 
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $example Example-object
     */
    public function P001_07_editCourse(\Step\Acceptance\Dozent $I) {
        $new_course_nid = $this->current_course_nid;
        $demo_domain_title = $this->getDemoTitleForDomainTitle(Fixtures::get('domain_title'));

        $course_edit = ['domain_demo_title' => $demo_domain_title];
        $course_edit_example = new Codeception\Example($course_edit);
        $editcoursepage = new EditCoursePage($I, $new_course_nid);
        $editcoursepage->edit($course_edit_example); 
    }

    /**
     * Add students to the newly created course
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $students_example Example-array mit name und mail
     * @dataProvider P001_addStudentsProvider
     */
    public function P001_08_addStudentsToCourse(\Step\Acceptance\Dozent $I, Codeception\Example $students_example) {
        $I->comment(sprintf('now I add memmber %s to the course %s' ,$students_example['mail'], $this->current_course_nid));

        //use AddMembersPage
        $addmempage = new AddMembersPage($I, $this->current_course_nid);
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
        $return = array();
        for ($count = 1; $count <= $this->count_students; $count ++) {
            $return[] = $this->_getDummyPersonExample(array(NM_ROLE_STUDENT), $count);
        }

        return $return;
    }
    
    
    
    
     
     /**
     * Add other created teachers to the newly created course
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @param \Codeception\Example $dozenten_example Example-array with name / mail
     * @uses P001_dummySingleTeacherProvider Infos about currently loggedin dozent
     * @dataProvider P001_dummyTeachersProvider
     */
     public function P001_09_addDozentenToCourse(\Step\Acceptance\Dozent $I, Codeception\Example $dozenten_example) {
        $current_teacher = $this->P001_dummySingleTeacherProvider()[0];

        //füge nicht sich selbst hinzu
        if ($current_teacher["mail"] === $dozenten_example["mail"]) {
            return;
        }

        $I->comment(sprintf('now I add teacher %s to the course %s', $dozenten_example['mail'], $this->current_course_nid));

        //use AddMembersPage
        $addmempage = new AddMembersPage($I, $this->current_course_nid);
        $addmempage->addByMail($dozenten_example["mail"]);
    }
   

    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * 
     */
    public function P001_20_logOut(\Step\Acceptance\Dozent $I){
        $I->logout();
    }

}
