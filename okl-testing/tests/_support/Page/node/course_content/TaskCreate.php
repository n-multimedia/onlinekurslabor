<?php

namespace Page\node\course_content;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of TaskCreate
 *
 * @author Bernhard
 */
class TaskCreate extends CourseContentBase implements \Page\node\ContentCreateInterface {

    /**
     * Declare UI map for this page here. CSS or XPath allowed.
     */
    public function __construct(\AcceptanceTester $I, $course_nid) {
        parent::__construct($I, $course_nid, NM_COURSE_GENERIC_TASK);
    }

    public function fillFields(\AcceptanceTester $I, \Codeception\Example $params) {

        //nicht ganz sauber, geht vorerst aber. field_task_type=0: singleaufgabe, field_task_type=1: gruppenaufgabe
        $I->checkOptionByValue($params['field_task_type']);
        //setze Aufgabenbeginn, sonst Rundungsfehler.. 
        $I->fillField('field_task_handling_period['.LANGUAGE_NONE.'][0][value][time]', date('G:00'));
        foreach ($params['elements'] as $key => $elem) {
            if ($key > 0) {
                $I->click("Weiteres Element hinzufügen");
                $I->wait(1);
            }

            $I->selectOption("field_generic_task_entry[" . LANGUAGE_NONE . "][$key][first]", $elem['title']);
            $I->fillCkEditorById("edit-field-generic-task-entry-und-" . $key . "-second-value", $elem["content"]);
        }

        //nun kommt "speichern"
    }

    /**
     * get node-id of lately created task
     * @return int $nid
     */
    public function getNewNid() {
        $I = $this->tester;
        return $I->grabFromCurrentUrl('~course/tasks/\d+/(\d+)~');
    }

}
