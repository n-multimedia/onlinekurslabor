<?php

namespace Page\coursestudent;

class TaskAnswer {

    // include url of current page
    public static $URL = 'course/tasks/%s/%s/solution';
    
    public static $answer_CKField = 'edit-solutions-0-value';
    public static $answering_possible_tag = 'Bearbeitungszeitraum aktiv';
    public static $answered_in_time_tag = "Pünktlich eingereicht";
    public static $confirmDraftButton = 'Als Entwurf speichern';
    public static $confirmSaveButton = "Speichern und Einreichen";


    /**
     * NIDs: todo
     * @param \AcceptanceTester $I
     * @param type $course_nid
     * @param type $task_nid
     */
    public function __construct(\AcceptanceTester $I, $course_nid, $task_nid) {
        $this->tester = $I;
    }

    /**
     * Basic route  for your current URL
     * You can append any additional parameter to URL
     * and use it in tests like: Page\Edit::route('/123-post');
     */
    public static function route($course_nid, $task_nid) {
        return sprintf(static::$URL, $course_nid, $task_nid);
    }
}