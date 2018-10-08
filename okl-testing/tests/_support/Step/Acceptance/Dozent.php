<?php

namespace Step\Acceptance;
use \Codeception\Step\Argument\PasswordArgument;


class Dozent extends UserSteps {

  public function loginAsDozent($saveSession = TRUE) {
    require_once(dirname(__FILE__) . "/../../../../..//web/sites/default/settings.php");

    $I = $this;

    $username = "fahrneul";
    $password = new PasswordArgument(NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT);

    $I->login($username, $password, TRUE);

  }

}