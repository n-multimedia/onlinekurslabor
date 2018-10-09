<?php

namespace Step\Acceptance;
use \Codeception\Step\Argument\PasswordArgument;


class Author extends UserSteps {

  public function loginAsAuthor($saveSession = TRUE) {
    require_once(dirname(__FILE__) . "/../../../../..//web/sites/default/settings.php");

    $I = $this;

    $username = "fahrneul";
    
    $I->login($username, null, $saveSession);

  }

}