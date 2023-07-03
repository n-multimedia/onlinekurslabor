<?php

namespace Page;

abstract class UserCreateEdit {

    // include url of current page
    public static $URL = ''; // //deswegen abstract
    /**
     * Declare UI map for this page here. CSS or XPath allowed.
     * 
     * 
     */
    public static $mailField = 'mail';
    public static $pw1Field = 'pass[pass1]';
    public static $pw2Field = 'pass[pass2]';
    public static $firstNameField = 'profile_master[field_first_name][und][0][value]';
    public static $lastNameField = 'profile_master[field_last_name][und][0][value]';
    /* public static $roleAdministratorCheckbox = 'roles[30037204]';
      public static $roleModeratorCheckbox = 'roles[197637936]';
      public static $roleAutorCheckbox = 'roles[16675960]';
      public static $roleDozentCheckbox = 'roles[106505419]';
      public static $roleTutorCheckbox = 'roles[126456107]';
     */
    private static $roleCheckboxTemplate = 'roles[%s]';
    
    
    public static $confirmSaveButton = ''; //deswegen abstract

    /**
     * @var AcceptanceTester
     */
    protected $tester;

    public function __construct(\AcceptanceTester $I) {
        $this->tester = $I;
    }

    /**
     * doc: see child-classes
     * @param \Codeception\Example  $params
     * @return \Page\UserCreateEdit
     */
    public function doCreateEdit(\Codeception\Example $params) {
        $I = $this->tester;

        $I->amOnPage(self::$URL);

        if ($params['mail']) {
            $I->fillField(self::$mailField, $params['mail']);
        }

        if ($params['password']) {
            $I->fillField(self::$pw1Field, $params['password']);
            $I->fillField(self::$pw2Field, $params['password']);
        }

        //möglicherweise möchte man alle sonstigen Rollen auch erst noch unchecken.. aber das is dann n Fall für UserEdit
        foreach ($params['roles'] as $rolename) {
            $some_role = user_role_load_by_name($rolename);
            $I->checkOption(sprintf(self::$roleCheckboxTemplate, $some_role->rid));
        }


        $I->click('Stammdaten');

        if ($params['firstName']) {
            $I->fillField(self::$firstNameField, $params['firstName']);
        }
        if ($params['lastName']) {
            $I->fillField(self::$lastNameField, $params['lastName']);
        }

        $I->click(self::$confirmSaveButton);

        //im edit/create-modus ist die Ausgabe und Folgeoperationen unterschiedlich
        if (get_class($this) == "Page\UserCreate") {
            $I->wait(3);
            $I->see("Es wurde ein neues Benutzerkonto erstellt für ");
            //theoretisch müsste man den Acc nun einmal einloggen, damit die Nutzungsvb akzeptiert wird
        }


        return $this;
    }

}
