<?php

namespace Page;
/**
 * 
 * 
 * 
 * 
 * Needs to be refactored using NodeCreateInterface
 */
class CreateCourse {

    // include url of current page
    public static $URL = '/node/add/courses-course';

    /**
     * Declare UI map for this page here. CSS or XPath allowed.
     */
    public static $semesterSelect = 'field_semester[und]';
    public static $titleField = 'title';
    public static $timespan2field = 'field_time_span[und][0][value2][date]';
    
    public static $publishButton = '#edit-submit';

    
    public function __construct(\AcceptanceTester $I) {
        $this->tester = $I;
    }

    /**
     * generates a new Course. Parameters in $example: title, currentSemesterName
     * @param \Codeception\Example $example
     * @return \Page\CreateCourse
     */
    public function createCourse(\Codeception\Example $example) {
        $I = $this->tester;

        $I->amOnPage(self::$URL);
        $I->see('Courses - Kurs erstellen');
        $I->fillField(self::$titleField, $example['title']);

        $I->selectOption(self::$semesterSelect, $example['currentSemesterName']);
        $I->fillField(self::$timespan2field, date('m/d/Y', time() + 31 * 24 * 60 * 60));

        //click: Veröffentlichen
        $I->click(self::$publishButton);
        
        $I->see('Courses - Kurs ' . $example['title'] . ' wurde erstellt.');
        return $this;
    }

    /**
     * Basic route example for your current URL
     * You can append any additional parameter to URL
     * and use it in tests like: Page\Edit::route('/123-post');
     */
    public static function route($param) {
        return static::$URL . $param;
    }

}
