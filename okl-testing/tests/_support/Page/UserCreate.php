<?php

namespace Page;

class UserCreate extends UserCreateEdit {

    // include url of current page
    //see parent

    /**
     * Declare UI map for this page here. CSS or XPath allowed.
     * public static $usernameField = '#username';
     * public static $formSubmitButton = "#mainForm input[type=submit]";
     */
     

    public function __construct(\AcceptanceTester $I) {
        parent::__construct($I);
        parent::$URL = 'admin/people/create';
        parent::$confirmSaveButton = 'Neues Benutzerkonto erstellen';
    }

    /**
     * create a new User
     * @param \Codeception\Example $params  an array containing mail, password firstName lastName, roles (as array)
     * @return \Page\UserCreate
     */
    public function create(\Codeception\Example $params) {
      return $this->doCreateEdit($params); 
    }


}
