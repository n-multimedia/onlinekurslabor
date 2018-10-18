<?php
/**
 * Description for loginpage
 */
namespace Page\Acceptance;

class LoginPage {

  // include url of current page
  public static $URL = '/user/login';

  public static $acceptLegalTermsCheckbox = '#edit-legal-accept';
  public static $acceptLegalButton = 'button#edit-save';
  
  
  //blödsinn, field-identifier sind @todo
  public static $usernameField = '#edit-name';
  public static $passwordField = '#edit-pass';
  public static $formID = '#user-login';

 
  /**
   * @var \AcceptanceTester;
   */
  protected $acceptanceTester;

  public function __construct(\AcceptanceTester $I) {
    $this->acceptanceTester = $I;
  }

}
