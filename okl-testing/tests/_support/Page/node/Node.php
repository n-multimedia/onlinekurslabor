<?php

namespace Page\node;

abstract class Node {

    // basic variant of current page
    private static $baseCreateURL = '/node/add/%s';
    public static $titleField = 'title';
    public static $publishButton = '#edit-submit';
    //calculated
    public static $createURL;
    //type \AcceptanceTester
    public $tester;

    /**
     * must be called from non-abstract classes via parent::__ ...
     * @param \AcceptanceTester $I
     * @param String $content_type like NM_CONTENT_DOMAIN
     */
    public function __construct(\AcceptanceTester $I, $content_type) {
        self::$createURL = self::route(str_replace('_', '-', $content_type));

        $this->tester = $I;
    }

    /**
     * Basic route example for your current URL
     * You can append any additional parameter to URL
     * and use it in tests like: Page\Edit::route('/123-post');
     */
    private static function route($param) {
        return sprintf(self::$baseCreateURL, $param);
    }

    /**
     * Create is always same. Goto url, FiellTitle and some fields (custom), click "publish" and confirm
     * @param \Codeception\Example $params
     */
    public function create(\Codeception\Example $params) {
        $I = $this->tester;
        $I->amOnPage(self::$createURL);
        $I->fillField(self::$titleField, $params['title']);

        $this->fillFields($I, $params);

        //click: Veröffentlichen
        $I->click(self::$publishButton);
        //check: wurde angelegt
        $I->see($params['title'] . ' wurde erstellt.');
    }

    /**
     * Non-abstract class must fill fields.
     * @param \AcceptanceTester $I for convenience
     * @param \Codeception\Example $params 
     */
    abstract function fillFields(\AcceptanceTester $I, \Codeception\Example $params);
}
