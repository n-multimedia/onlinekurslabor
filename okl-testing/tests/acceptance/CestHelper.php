<?php

use \Codeception\Step\Argument\PasswordArgument;
use \Codeception\Util\Fixtures;

/*
 * Helperclass for Cests. Currently used for the fallback mechanism and a helper for dataproviders
 */

/**
 * Description of CestHelper
 *
 * @author Bernhard
 */
abstract class CestHelper {

     /**
     * goto Course-Home. Either by created course or fallback-course.
     * @param AcceptanceTester $I
     */
    protected function goToCourseHome(AcceptanceTester $I) {
        $nid = $this->getCurrentCourseNid();

        $course_home_url = NM_COURSE_HOME_PATH . '/' . $nid;

        $I->amOnPage($course_home_url);
    }

    /**
     * getCurrentCourseNid. Either by created course or fallback-course.
     * @param AcceptanceTester $I
     */
    protected function getCurrentCourseNid() {
        if (Fixtures::exists('course_nid')) {
            $nid = Fixtures::get('course_nid');
        } else {
            //fallback url
            $fallback_data = _okl_testing_getFallbackData();
            $nid = $fallback_data->nid;
        }

        return  $nid ; 
    }
    
    /**
     * 



      /**
     * accessed via  @before-syntax
     * based on @dataProvider-syntax this will skip the non-applicable testcase
     * @param type $I
     * @param Codeception\Scenario $scenario
     */
    protected function skipNonApplicableExample(AcceptanceTester $I, Codeception\Scenario $scenario) {
        $I->comment("checking if in fallback-mode...");
        //get current @dataprovider-sample
        $example = ($scenario->current('example'));

        //evtl muss man künftig das unique in ne function auslagern.. 
        //hier: kurs wurde erstellt und möchte fallback ausführen: skip
        if (Fixtures::exists('course_nid') && $example['type'] == 'fallback') {
            $I->comment("skipping " . $example['type']);
            $scenario->skip();
        }
        //hier: kein kurs erstellt, aber default ausführen: skip
        elseif (!Fixtures::exists('course_nid') && $example['type'] == 'default') {
            $I->comment("skipping " . $example['type']);
            $scenario->skip();
        }
    }

    /**
     * Use in Dataprovider.
     * get $count teachers
     * 
     * @param type $count
     * @param type $ident_num_start
     * @return type
     */
    protected function DP_getSampleTeachers($count, $ident_num_start = 0, $with_fallback = true) {
        $sample = array();
        $fallback_data = _okl_testing_getFallbackData();
        $runner = 0;
        for ($i = $ident_num_start; $i < $count; $i++) {
            $sample[$runner++] = $this->getPersonSample(array(NM_ROLE_DOZENT), $i) + ['type' => 'default'];
             if($with_fallback)
            {
                $sample[$runner++] = "null"; //ok das geht noch nicht, fehlt das to Array()$fallback_data->random('teacher') + ['type'=>'fallback'];
            }
        }

        return $sample;
    }

    /**
     * Use in Dataprovider.
     * get $count students
     * 
     * @param type $count
     * @param type $ident_num_start
     * @return type
     */
    protected function DP_getSampleStudents($count, $ident_num_start = 0, $with_fallback = true) {
        $sample = array();
        $fallback_data = _okl_testing_getFallbackData();
        $runner = 0;
        for ($i = $ident_num_start; $i < $count; $i++) {
            $sample[$runner++] = $this->getPersonSample(array(NM_ROLE_STUDENT), $i) + ['type' => 'default'];
            if($with_fallback)
            {
                $sample[$runner++] = "null"; //ok das geht noch nicht, fehlt das to Array()$fallback_data->random('student') + ['type'=>'fallback'];
            }
            
        }

        return $sample;
    }

    /**
     * Use in  Dataprovider
     * get a sample course
     * Uniqueness is dependend of $counter
     * @param type $ident_number same number = same sample [within one run]
     * @uses _okl_testing_get_dataprovider_identifier()
     */
    protected function DP_getSampleCourse($ident_number = 0) {
        $fallback_data = _okl_testing_getFallbackData(); //@todo

        return array($fallback_data->toDataProviderSample() + ['type' => 'fallback'], $this->getCourseSample($ident_number) + ['type' => 'default']);
    }

    /**
     * NOT needed ATM
     * gets a dummy student
     * @param type $counter
     * @return array $student
     * @uses _okl_testing_get_dataprovider_identifier()

      private function getStudentSample($counter = 0) {
      return  $this->getPersonSample(array(NM_ROLE_STUDENT), $counter);
      } */

    /**
     * gets a dummy person. Uniqueness is dependend of $roles and $counter
     * @param array $roles
     * @param type $ident_number
     * @return type
     * @uses _okl_testing_get_dataprovider_identifier()
     */
    private function getPersonSample(array $roles, $ident_number = 0) {
        $unique = _okl_testing_get_dataprovider_identifier() . '_user_' . implode('-', $roles) . '_' . $ident_number;
        $fakerobject = \RealisticFaker\OklDataCreator::get($unique);
        return ['sex' => $fakerobject->sex, 'name' => $fakerobject->name, 'firstName' => trim($fakerobject->firstName . ' ' . $fakerobject->middleName), 'lastName' => $fakerobject->lastName, 'mail' => $fakerobject->email, 'roles' => $roles, 'password' => new PasswordArgument(NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT)];
    }

    /**
     * get a basic Sample for a new course
     * Uniqueness is dependend of $ident_number
     * @param type $ident_number same number = same sample [within one run]
     * @uses _okl_testing_get_dataprovider_identifier()
     */
    protected function getCourseSample($ident_number = 0) {

        $faker = $this->getNodeFaker(NM_COURSE, $ident_number);
        $sample = $this->getNodeSample(NM_COURSE, $ident_number);

        //@todo: Semester aktuell
        $sample['currentSemesterName'] = $faker->currentSemesterName;
        return $sample;
    }

    /**
     * Basic node-sample with title and body
     * @return array $sample [title, body]
     */
    private function getNodeSample($node_type, $ident_number = 0) {
        #$return = array();
        $rand_data = $this->getNodeFaker($node_type, $ident_number);
        return ['title' => $rand_data->node_title, 'body' => $rand_data->node_body, 'body_summary' => $rand_data->node_body_summary];
    }

    /**
     * get a Faker-Object based on parameters
     * @param type $node_type
     * @param type $ident_numer
     * @return \RealisticFaker\OklDataCreator $faker
     */
    private function getNodeFaker($node_type, $ident_numer) {
        $ID = _okl_testing_get_dataprovider_identifier() . '_node_' . $node_type . '_' . $ident_numer;
        return \RealisticFaker\OklDataCreator::get($ID);
    }

}
