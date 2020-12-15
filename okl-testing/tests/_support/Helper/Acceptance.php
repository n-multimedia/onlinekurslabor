<?php

namespace Helper;
require_once(__DIR__ . '/../customFaker/OklFactory.php'); 
require_once(__DIR__ . '/../customFaker/OklGenerator.php'); 
require_once (__DIR__ . '/../../acceptance/CestHelper.php');

// here you can define custom actions
// all public methods declared in helper class will be available in $I

class Acceptance extends \Codeception\Module {

     // HOOK: before each suite
    public function _beforeSuite($settings = array()) {
        //dadurch wird Drupal gesperrt 
        _okl_testing_start_test();
        //dataproviders sind bereits alle erstellt. Dies gilt erst für den näcshten Aufruf:
        _okl_testing_set_dataprovider_identifier();
    }

    
    //wird vor jedem Test ausgeführt.
    //beforeSuite sperrt Seite, hier wird Zugriff via Cookie erlaubt
    public function _before(\Codeception\TestCase $test) {
        
        $I = $this->getModule('WebDriver');

        //setze cookie. Dadurch wird wieder Zugriff auf Drupal gewährt
        $I->amOnPage('/');
        $I->setCookie('okl_testing_is_autotest_browser', 'yes', array(
            'domain' => parse_url($this->getCurrentFullUrl(), PHP_URL_HOST), // required property: current domain-name
            'path' => '/', // required property  
        ));
    }
     //wird nach Testende ausgeführt.
    public function _afterSuite() {
        _okl_testing_stop_test();
    }

    /**
     * Get current uri from WebDriver [without domain]
     * 
     * @return mixed
     * @throws \Codeception\Exception\ModuleException
     */
    public function getCurrentUri() {
        return $this->getModule('WebDriver')->_getCurrentUri();
    }

    /**
     * get the full URL (like in webbrowser's address bar) 
     * @return type String full URL including domain and parameters
     */
    public function getCurrentFullUrl() {
        return $this->getModule('WebDriver')->webDriver->getCurrentURL();
    }
    
     /**
     * get the UserAgent's name and version ("Browser")
     * @return type array with keys browserName, version
     */
    public function getBrowserIdent() {
        $browser_capabilites = (array) $this->getModule('WebDriver')->webDriver->getCapabilities();
        $browser_capabilites_array = array_pop($browser_capabilites);
      
        return array('browserName' => $browser_capabilites_array['browserName'],
            'version' => $browser_capabilites_array['version']);
    }

}
