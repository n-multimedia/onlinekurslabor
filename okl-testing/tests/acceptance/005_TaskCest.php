<?php

use Page\courseadmin\AddMembers as AddMembersPage;
use Page\courseadmin\MemberAdminCoursegroup as AddMemberToCoursegroupPage;
use Page\node\course_content\TaskCreate as TaskCreatePage;
use Page\coursestudent\TaskAnswer as TaskAnswerPage;

class TaskCest extends CestHelper {

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
    }

    public function _after(AcceptanceTester $I) {
        
    }

    /**
     * Helperfunction für Nutzerwechsel
     * @param \Step\Acceptance\Dozent $I geht aber auch für \Step\Acceptance\Student
     */
    protected function logAccountOut(\Step\Acceptance\Dozent $I) {
        $I->logout();
    }

    /**
     * @UserStory null
     * @UserStoryURL null
     *
     * @param \AcceptanceTester $I
     */
    public function TC001_01_DozentLoggedin(\Step\Acceptance\Dozent $I) {
        $I->loginAsDozent(TRUE);
        $I->amOnPage('/');
        $I->see('Meine Veranstaltungen');
    }

    /**
     * Kursmitglieder ohne Kursgruppe hinzufügen
     * @param \AcceptanceTester $I
     * @param \Codeception\Example $example array holds dataprovider's data
     * @dataProvider TC001_02_AddNonKGMemberProvider
     * @depends TC001_01_DozentLoggedin
     */
    public function TC001_02_AddNonKGMember(AcceptanceTester $I, \Codeception\Example $example) {

        $course_nid = $this->getCurrentContextNid();
        $addmempage = new AddMembersPage($I, $course_nid);
        $addmempage->addByNameAndMail($example["name"], $example["mail"]);
    }

    /**
     * Funktion ist der dataprovider für TC001_02_AddNonKGMember
     * @return array
     */
    protected function TC001_02_AddNonKGMemberProvider() {
        return $this->DP_getSampleStudents(1, 0, false);
    }

    /**
     * Kursmitglieder mit Kursgruppe hinzufügen
     * @param \Step\Acceptance\Dozent $I
     * @param \Codeception\Example $example array holds dataprovider's data
     * @dataProvider TC001_02_AddKGMemberProvider
     * @depends TC001_02_AddNonKGMember
     */
    public function TC001_02_AddKGMembers(\Step\Acceptance\Dozent $I, \Codeception\Example $example) {

        $course_nid = $this->getCurrentContextNid();
        $addmempage = new AddMembersPage($I, $course_nid);
        $addmempage->addByNameAndMail($example["name"], $example["mail"]);


        $course_object = _okl_testing_getDataObjectForCourse($course_nid);
        //hier nehmen wir einfach die erste, damit die getesteten in der selben sind.
        $course_group_for_user = $course_object->get('course_group', 0);

        $cgaddpage = new AddMemberToCoursegroupPage($I, $course_nid);
        $cgaddpage->addStudentToCoursegroup($example, $course_group_for_user->title);
    }

    /**
     * Funktion ist der dataprovider für TC001_02_AddKGMembers
     * @return array
     */
    protected function TC001_02_AddKGMemberProvider() {
        return $this->DP_getSampleStudents(3, 1, false); //fehler in api: für 2 studis beginnend mit Ident "1" braucht man count=3
    }

    /**
     * Erstelle neue Aufgaben (Gruppen- und Einzelaufgabe)
     * @UserStory null
     * @param \Step\Acceptance\Dozent $I
     * @dataProvider TC001_AddTaskProvider
     * @depends TC001_02_AddKGMembers
     */
    public function TC001_03_AddTasks(\Step\Acceptance\Dozent $I, \Codeception\Example $example) {

        $this->goToContextHome($I);

        $taskpage = new TaskCreatePage($I, $this->getCurrentContextNid());
        $taskpage->create($example);
    }

    /**
     *  Provider für Tasks
     * @return array
     */
    protected function TC001_AddTaskProvider() {
        $return = array();


        $rand_data = \RealisticFaker\OklDataCreator::get();

        $node_data = $this->getNodeSample(NM_COURSE_GENERIC_TASK, 0);
        //title : sonderheit bei aufgaben.. siehe _section_courses_courses_generic_task_node_form_submit. Test schlägt sonst bei manchen Chars fehl
        $return[] = ['title' => RealisticFaker\OklDataCreator::getSafeText($node_data['title']), 'field_task_type' => 0, 'elements' => [['title' => 'Beschreibung', 'content' => $rand_data->realText(20)], ['title' => 'Aufgabenstellung', 'content' => $rand_data->realText(20)], ['title' => 'Studenten-Formular', 'content' => $rand_data->realText(20)]], 'preparedanswer' => $rand_data->realText(200)];

        $node_data = $this->getNodeSample(NM_COURSE_GENERIC_TASK, 1);
        //field_task_type=1: gruppenaufgabe
        $return[] = ['title' => 'GROUP_' . RealisticFaker\OklDataCreator::getSafeText($node_data['title']), 'field_task_type' => '1', 'elements' => [['title' => 'Beschreibung', 'content' => $rand_data->realText(20)], ['title' => 'Aufgabenstellung', 'content' => $rand_data->realText(20)], ['title' => 'Studenten-Formular', 'content' => $rand_data->realText(20)]], 'preparedanswer' => $rand_data->realText(200)];

        return $return;
    }

    /**
     * all students test the tasks
     * 
     * @UserStory null
     * @param \Step\Acceptance\Student $I
     * @dataProvider TC001_StudentAndTaskProvider
     * @before logAccountOut
     * @depends TC001_03_AddTasks
     */
    public function TC001_04_TestTasks(\Step\Acceptance\Student $I, \Codeception\Example $studentsandtasks) {
        #  var_dump($studentsandtasks);

        $I->login($studentsandtasks['mail'], null, false);
        $this->goToContextHome($I);


        $student_is_in_kg = $studentsandtasks["kgmember"];
        foreach ($studentsandtasks['tasks'] as $task) {
            $I->click("Aufgaben");
            $I->click($task['title']);

            //gruppenaufgabe
            if ($task["field_task_type"] == "1") {

                //nicht-gruppenmitglieder können gruppenaufgabe nicht einreichen
                if (!$student_is_in_kg) {
                    $I->dontSee(TaskAnswerPage::$confirmDraftButton);
                    $I->dontSee(TaskAnswerPage::$confirmSaveButton);
                    continue;
                }//bin in gruppe, aber gruppenaufgabe wurde schon bearbeitet, 
                elseif (isset($task["prefilled_by_colleague"])) {
                    $I->dontSee(TaskAnswerPage::$confirmDraftButton);
                    $I->dontSee(TaskAnswerPage::$confirmSaveButton);
                    $I->see(TaskAnswerPage::$answered_in_time_tag);
                    continue;
                }
            }
            //keine der obigen bedingungen hat gegriffen, dann muss ausfüllen möglich sein.
            $I->see(TaskAnswerPage::$answering_possible_tag);

            $I->fillCkEditorById(TaskAnswerPage::$answer_CKField, $task['preparedanswer']);
            $I->click(TaskAnswerPage::$confirmSaveButton);
            $I->see(TaskAnswerPage::$answered_in_time_tag);
        }
    }

    /**
     *  Provider für TC001_04_TestTasks
     * @return array
     */
    protected function TC001_StudentAndTaskProvider() {
       
        $nonkgmembers = (array) $this->TC001_02_AddNonKGMemberProvider();
        $kgmembers = (array) $this->TC001_02_AddKGMemberProvider();

        $students = array_merge($nonkgmembers, $kgmembers);

        $alltasks = (array) $this->TC001_AddTaskProvider();
        
        //jedem studi werden die tasks zugewiesen
        foreach ($students as $counter => &$studi) {

            $studi['tasks'] = $alltasks;

            //am anfang stehen die non-kg-members im array
            if ($counter < count($nonkgmembers)) {
                $studi['kgmember'] = false;
            } else {
                $studi['kgmember'] = true;

                //der erste kg-member füllt die aufgabe aus, dann ist sie für 
                //die anderen kg-memmber nicht mehr bearbeitbar
                if ($counter > count($nonkgmembers)) {

                    foreach ($studi['tasks'] as &$task) {
                        if ($task['field_task_type'] == '1') {
                            //$task = array();
                            $task['prefilled_by_colleague'] = TRUE;
                        }
                    }
                }
            }
        }
        return $students;
    }

}
