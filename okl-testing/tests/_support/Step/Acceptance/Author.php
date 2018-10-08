<?php

namespace Step\Acceptance;
use \Codeception\Step\Argument\PasswordArgument;


class Author extends UserSteps {

  public function loginAsAuthor($saveSession = TRUE) {
    require_once(dirname(__FILE__) . "/../../../../..//web/sites/default/settings.php");

    $I = $this;

    $username = "fahrneul";
    $password =  new PasswordArgument(NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT);

    $I->login($username, $password, $saveSession);

  }

}