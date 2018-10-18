<?php

namespace Step\Acceptance;


class Dozent extends UserSteps {

  public function loginAsDozent($saveSession = TRUE) {

    $I = $this;
    $username = "fahrneul";

    $I->login($username, null, $saveSession);

  }

}