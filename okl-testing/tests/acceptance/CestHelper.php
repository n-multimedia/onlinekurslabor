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
     * based on @dataProvider-syntax this will skip the testcase with an empty example
     * @param type $I
     * @param Codeception\Scenario $scenario
     */
    protected function skipEmptyExample(AcceptanceTester $I, Codeception\Scenario $scenario) {

        //get current @dataprovider-sample
        $example = ($scenario->current('example'));
        if ($this->isEmptyExample($example)) {
            $scenario->skip("an empty example.");
        }
    }
    


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
            $scenario->skip($example['type'] . "-example since Fixtures::exists('course_nid')");
        }
        //hier: kein kurs erstellt, aber default ausführen: skip
        elseif (!Fixtures::exists('course_nid') && $example['type'] == 'default') {
            $scenario->skip($example['type'] . "-example since NO Fixtures::exists('course_nid')");
        }
    }
    
    /**
     * accessed via  @before-syntax
     * this will skip the testcase if _okl_testing_start_prepare_cest was not called before the test
     * @param type $I
     * @param Codeception\Scenario $scenario
     */
    protected function skipIfNotInPrepareMode(AcceptanceTester $I, Codeception\Scenario $scenario) {
        if (!_okl_testing_is_prepare_cest_running()) {
            $scenario->skip("PrepareMode was not activated. To run PrepareCest, run 'codecept-run-prepare_test.sh'");
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
        if ($with_fallback) {
            $fallback_data = _okl_testing_getFallbackData();
        }

        $runner = 0;
        for ($i = $ident_num_start; $i < $count; $i++) {
            $sample[$runner++] = $this->getPersonSample(array(NM_ROLE_DOZENT, NM_ROLE_AUTOR), $i) + ['type' => 'default'];
             if($with_fallback)
            {
                 $sample[$runner++] =  $fallback_data->random('teacher')->toDataProviderSample() + ['type'=>'fallback'];
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
        if ($with_fallback) {
            $fallback_data = _okl_testing_getFallbackData();
        }
        $runner = 0;
        for ($i = $ident_num_start; $i < $count; $i++) {
            $sample[$runner++] = $this->getPersonSample(array(NM_ROLE_STUDENT), $i) + ['type' => 'default'];
            if($with_fallback)
            {
                $sample[$runner++] =  $fallback_data->random('student')->toDataProviderSample() + ['type'=>'fallback'];
            }
            
        }

        return $sample;
    }

    /**
     * Use in  Dataprovider
     * get a sample course
     * Uniqueness is dependend of $ident_number
     * @param type $ident_number same number = same sample [within one run]
     * @param boolean $with_fallback
     * @uses _okl_testing_get_dataprovider_identifier()
     */
    protected function DP_getSampleCourse($ident_number = 0, $with_fallback = true) {
        $sample = array();
        if ($with_fallback) {
            $sample[] = _okl_testing_getFallbackData()->toDataProviderSample() + ['type' => 'fallback'];
        }

        $sample[] = $this->getCourseSample($ident_number) + ['type' => 'default'];

        return $sample;
    }

    /**
     * Use in  Dataprovider
     * get sample coursegroups
     * Uniqueness is dependend of $ident_number
     * @param int $count how many coursegroups
     * @param type $ident_num_start same number = same sample [within one run]
     * @param boolean $with_fallback
     * @uses _okl_testing_get_dataprovider_identifier()
     */
    protected function DP_getSampleCoursegroups($count, $ident_num_start = 0, $with_fallback = true) {
       
        if ($with_fallback) {
            $fallback_data = _okl_testing_getFallbackData();

            if (count($fallback_data->course_groups) < $count) {
                trigger_error("You requested $count coursegroups, but fallback only has " . count($fallback_data->course_groups) . " coursegroups.");
            }
        }
        $sample = array();
       
        $runner = 0;
        for ($i = $ident_num_start; $i < $count; $i++) {
            $sample[$runner++] = $this->getNodeSample(NM_COURSE_GROUP, $i) + ['type' => 'default'];

            if ($with_fallback) {
                $sample[$runner++] = array_values($fallback_data->course_groups)[$runner - 1]->toDataProviderSample() + ['type' => 'fallback'];
            }
        }
        return $sample;
    }
    
    
    /**
     *  Use in  Dataprovider
     * get an assignment of users to coursegroups
     * Every user will be assigned to  one coursegroup (randomly)
     * 
     * @param type $count_users how many users
     * @param type $count_coursegroups how many different coursegroups
     * @param type $ident_num_start
     * @param boolean $with_fallback
     * @return array   'users' => [['name' => ..., 'mail' => ...], ['name' => ..., 'mail' => ...]],  'coursegroup_title' => ... 'type' => ...,];
     */
    protected function DP_getSampleUsersToCoursegroups($count_users, $count_coursegroups, $ident_num_start, $with_fallback = true) {

        $users_and_coursegroups = array('default' => array('users' => null, 'coursegroups' => null), 'fallback' => array('users' => null, 'coursegroups' => null));

        //get values from other providers
        $users = $this->DP_getSampleStudents($count_users, $ident_num_start, $with_fallback);
        $coursegroups = $this->DP_getSampleCoursegroups($count_coursegroups, $ident_num_start, $with_fallback);

        //assign to our array
        foreach ($users as $u) {
            $users_and_coursegroups[$u['type']]['users'][] = $u;
        }
        foreach ($coursegroups as $cg) {
            $users_and_coursegroups[$u['type']]['coursegroups'][] = $cg;
        }

        $unique = _okl_testing_get_dataprovider_identifier() . '_userstogroups_' . $ident_num_start;
        $randomizer = \RealisticFaker\OklDataCreator::get($unique);


        $sample = array();
        $users_per_group = max(1, floor($count_users / $count_coursegroups));
        foreach ($users_and_coursegroups as $type => $values) {
            foreach ($values['coursegroups'] as $cg) {
                $sample[] = array('coursegroup_title' => $cg['title'], 'users' => array(), 'type' => $type);
            }
            foreach ($values['users'] as $u) {
                $random_key = $randomizer->randomKey($sample);
                $sample[$random_key]['users'][] = array('name' => $u['name'], 'mail' => $u['mail']);
            }
        }


        return $sample;
    }

    /**
     * Use in  Dataprovider
     * get a sample domain OR get sample domain + demo domain
     * Uniqueness is dependend of $ident_number
     * @param type $ident_number same number = same sample [within one run]
     * @param $with_demo_domain create a second domain called ... (DEMO)
     * @param $with_fallback (from existing fallbackcourse)
     * @uses _okl_testing_get_dataprovider_identifier()
     */
     protected function DP_getSampleDomain($ident_number = 0, $with_demo_domain = true, $with_fallback = true) {
        $sample = array();
        $domain = $this->getNodeSample(NM_CONTENT_DOMAIN, $ident_number);
        $domain['title'] = RealisticFaker\OklDataCreator::getSafeText($domain['title']);
        $sample[] = $domain + ['type' => 'default'];


        if ($with_demo_domain) {
            $demo_domain = $domain;
            $demo_domain['title'] = substr($demo_domain['title'], 0, -7) . ' (DEMO)';
            $sample[] = $demo_domain + ['type' => 'default'];
        }

        if ($with_fallback) {
            $sample[] = _okl_testing_getFallbackData()->domain->toDataProviderSample() + ['type' => 'fallback'];
            if ($with_demo_domain) {
                $sample[] = _okl_testing_getFallbackData()->domain_demo->toDataProviderSample() + ['type' => 'fallback'];
            }
        }

        return $sample;
    }

    /**
     * Use in  Dataprovider
     * get a sample news
     * Uniqueness is dependend of $ident_number
     * Does NOT provide fallback-data
     * @paramt int $count how many
     * @param type $ident_num_start same number = same sample [within one run]
     * @uses _okl_testing_get_dataprovider_identifier()
     */
    protected function DP_getSampleNews($count, $ident_num_start = 0) {
        $sample = array();
         $runner = 0;
          for ($i = $ident_num_start; $i < $count; $i++) {
                $sample[$runner++] = $this->getNodeSample(NM_COURSE_NEWS, $i);
          }
        return $sample; 
    }
    
    /**
     * get an empty example for dataproviders
     */
    protected function getEmptyExample()
    {
        return array('none'=>'none');
    }
    
    /**
     * Tests, if given example (array or Codeception-Example) equals an empty example
     * @param type $mixed
     * @return type
     */
    protected function isEmptyExample($mixed) {

        $emptysample = $this->getEmptyExample();
        //type is Codeception\Example
        if (is_object($mixed)) {
            $object_emptysample = new Codeception\Example($emptysample);
            return $mixed == $object_emptysample;
        }
        //else: array

        return $mixed == $emptysample;
    }


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

        $sample['currentSemesterName'] = $faker->currentSemesterName;
        return $sample;
    }

    /**
     * Basic node-sample with title and body
     * @return array $sample [title, body]
     */
    protected function getNodeSample($node_type, $ident_number = 0) {
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
