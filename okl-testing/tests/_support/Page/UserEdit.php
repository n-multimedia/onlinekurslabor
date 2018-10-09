<?php

namespace Page;

/**
 * funktioniert noch nicht, ungetestet.
 */
class UserEdit {

    // include url of current page
    //see parent
    /**
     * Declare UI map for this page here. CSS or XPath allowed.
     * public static $usernameField = '#username';
     * public static $formSubmitButton = "#mainForm input[type=submit]";
     */
  
    
     public function __construct(\AcceptanceTester $I) {
        parent::__construct($I);
        parent::$URL = 'user/%s/edit';
        parent::$confirmSaveButton = 'Speichern';
    }

    /**
     * Basic route example for your current URL
     * You can append any additional parameter to URL
     * and use it in tests like: Page\Edit::route('/123-post');
     */
    public static function route($param) {
        return sprintf(static::$URL,  array($param));
    }

}
