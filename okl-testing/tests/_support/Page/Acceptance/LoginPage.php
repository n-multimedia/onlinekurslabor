<?php

namespace Page\Acceptance;

class LoginPage {

  // include url of current page
  public static $URL = '/user/login';

  public static $usernameField = '#edit-name';
  public static $passwordField = '#edit-pass';
  public static $formID = '#user-login';

  /**
   * Basic route example for your current URL
   * You can append any additional parameter to URL
   * and use it in tests like: Page\Edit::route('/123-post');
   */
  public static function route($param) {
    return static::$URL . $param;
  }

  /**
   * @var \AcceptanceTester;
   */
  protected $acceptanceTester;

  public function __construct(\AcceptanceTester $I) {
    $this->acceptanceTester = $I;
  }

}
