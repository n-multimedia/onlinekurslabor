<?php

namespace Step\Acceptance;
use \Codeception\Step\Argument\PasswordArgument;


class Dozent extends UserSteps {

  public function loginAsDozent($saveSession = TRUE) {
    $I = $this;

    $username = "fahrneul";

    $I->login($username, null, TRUE);

  }

}