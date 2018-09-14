<?php


namespace Step\Acceptance;

use Page\Acceptance\LoginPage;

class UserSteps extends \AcceptanceTester {

  /**
   * @param $userName
   * @param $userPassword
   */
  public function login($userName, $userPassword) {
    $I = $this;

    $I->amOnPage(LoginPage::$URL);
    $I->submitForm(LoginPage::$formID, [
      LoginPage::$usernameField => $userName,
      LoginPage::$passwordField => $userPassword,
    ]);
  }

}