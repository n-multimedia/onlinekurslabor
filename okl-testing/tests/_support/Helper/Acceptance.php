<?php

namespace Helper;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

class Acceptance extends \Codeception\Module {

    //wird vor jedem Test ausgeführt.
    //beforeSuite nicht funktional, da kein Zugriff auf Browser (und cookies)
    public function _before(\Codeception\TestCase $test) {
        //dadurch wird Drupal gesperrt 
        _okl_testing_start_test();
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

}
