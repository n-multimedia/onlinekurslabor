<?php

namespace Helper;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

class Acceptance extends \Codeception\Module {


  /**
   * Get current uri from WebDriver [without domain]
   * 
   * @return mixed
   * @throws \Codeception\Exception\ModuleException
   */
  public function getCurrentUri()
  {
    return $this->getModule('WebDriver')->_getCurrentUri();
  }
  
  /**
   * get the full URL (like in webbrowser's address bar) 
   * @return type String full URL including domain and parameters
   */
  public function getCurrentFullUrl()
  {
    return  $this->getModule('WebDriver')->webDriver->getCurrentURL();
  }


}
