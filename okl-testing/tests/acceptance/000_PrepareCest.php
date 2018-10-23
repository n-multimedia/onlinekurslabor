<?php

use \Codeception\Step\Argument\PasswordArgument;
use Codeception\Util\Fixtures;
use Page\UserCreate as UserCreatePage;
use Page\CreateCourse as CreateCoursePage;
use Page\courseadmin\AddMembers as AddMembersPage;

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
        //identifier für diesen Durchlauf des Cests. Kann künftig über Variable oÄ gesetzt werden
        $this->run_identifier = "drölfundzwanzig";
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

    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\SuperAdmin $I (instead of type \AcceptanceTester)
     * @dataProvider P001_createTeachersProvider
     */
    public function P001_01_createTeachers(\Step\Acceptance\SuperAdmin $I, \Codeception\Example $example) {
        
        $I->comment('Caution: This cest will only run succesfully the FIRST time on a database until $run_identifier is changed');
      
      //variable_del('okl_testing_fallback_data');
        if (!user_load_by_mail($example['mail'])) {

            $I->loginAsSuperAdmin(true);
            $createPage = new UserCreatePage($I);
            $createPage->create($example);
            //_okl_testing_stop_test(); 
        }

        // Fixtures::add('created_persons', $example);
    }

    /**
     * Funktion ist der dataprovider für P001_01_createTeachers und 
     * @return \Codeception\Example $example
     */
    protected function P001_createTeachersProvider() {
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
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @dataProvider P001_createCourseProvider
     */
    public function P001_02_createCourse(\Step\Acceptance\Dozent $I, Codeception\Example $course_example) {

        //vielleicht auch nicht random sondern faker mit seed für nachvollziehbarkeit
        $randomteacher_number = rand(1, $this->count_dozents);

        $random_teacher = $this->_getDummyPersonExample(array(NM_ROLE_DOZENT, NM_ROLE_AUTOR), $randomteacher_number);

        $I->amGoingTo('Login as ' . $random_teacher['mail']);
        $I->login($random_teacher['mail'], null, true);


        //refactored
        $createcoursepage = new CreateCoursePage($I);
        $createcoursepage->createCourse($course_example);

        $home_nid = $I->grabFromCurrentUrl('~/course/home/(\d+)~');
        $I->comment('The nid of my new course is ' . $home_nid);

        $this->current_course_nid = $home_nid;
    }

    /**
     * der Dataprovider für P001_02_createCourse liefert nötige Variablen
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
     * Add students to the newly created course
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \Step\Acceptance\Dozent $I (instead of type \AcceptanceTester)
     * @dataProvider P001_addMembersProvider
     */
    public function P001_03_addMembersToCourse(\Step\Acceptance\Dozent $I, Codeception\Example $students_example) {
        $I->comment(sprintf('now I add memmber %s to the course %s' ,$students_example['mail'], $this->current_course_nid));

        //use AddMembersPage
        $addmempage = new AddMembersPage($I, $this->current_course_nid);
        $addmempage->addByNameAndMail($students_example["name"], $students_example["mail"]);
        
         //und danach editiere useraccounts mit drupal-api
          /* das geht nicht. Gibt ein Problem mit htmlpurifier :-((
        $curr_students_drupal_account = user_load_by_mail('wieland.zimmer+autotest@div.onlinekurslabor.de');
        $student_password_edit['pass'] = NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT;
        user_save($curr_students_drupal_account, $student_password_edit);*/
        
         
    }

    /**
     * Funktion ist der dataprovider für P001_03_addMembersToCourse 
     * @return \Codeception\Example $example
     */
    protected function P001_addMembersProvider() {
        $return = array();
        for ($count = 1; $count <= $this->count_students; $count ++) {
            $return[] = $this->_getDummyPersonExample(array(NM_ROLE_STUDENT), $count);
        }

        return $return;
    }

}
