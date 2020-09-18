<?php

namespace Page\node;

abstract class Node {

    // basic variant of current page
    private static $baseCreateURL = '/node/add/%s';
    public static $titleField = 'title';
    public static $publishButton = '#edit-submit';
    public static $formEditContext = 'form.node-form';
    //calculated
    public static $createURL; //calculated in child
    public static $editURL;  //calculated in child
    //type \AcceptanceTester
    public $tester;

    /**
     * must be called from non-abstract classes via parent::__ ...
     * @param \AcceptanceTester $I
     * @param String $content_type only necessary for CREATE, not EDIT
     */
    public function __construct(\AcceptanceTester $I, $content_type = false) {
        if($content_type)
        {
            self::$createURL = self::route(str_replace('_', '-', $content_type));
        }

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
     * Create is always same. Goto url, Fill Title and some fields (custom), click "publish" and confirm
     * @param \Codeception\Example $params
     */
    public function create(\Codeception\Example $params) {
        $I = $this->tester;
        $I->amOnPage(self::$createURL);
        $I->fillField(self::$titleField, $params['title']);

        $this->fillFields($I, $params);

        //click: Veröffentlichen
        $I->click(self::$publishButton);
        $I->wait(1);
        //check: wurde angelegt
        $I->see($params['title'] . ' wurde erstellt.');
    }
    
    /**
     * edit is always same. Goto url, fill fields (custom), click "publish" and confirm
     * @param \Codeception\Example $params
     */
    public function edit(\Codeception\Example $params) {
        $I = $this->tester;

        $I->amOnPage(self::$editURL);
        $I->wait(1);
        $this->editFields($I, $params);
        $I->click(self::$publishButton);
        $I->wait(1);
        //check: wurde bearbeitet
        $I->see("wurde aktualisiert");
    }

}
