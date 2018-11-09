<?php
/**
 * Description for loginpage
 */
namespace Page\Acceptance;

class LogoutPage {

  // include url of current page
  public static $URL = '/user/logout';
 
 
  /**
   * @var \AcceptanceTester;
   */
  protected $acceptanceTester;

  public function __construct(\AcceptanceTester $I) {
    $this->acceptanceTester = $I;
  }

}
