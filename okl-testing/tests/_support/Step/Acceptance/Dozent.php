<?php

namespace Step\Acceptance;


class Dozent extends UserSteps {

  public function loginAsDozent($saveSession = TRUE) {

    $I = $this;
    $fallback_data = _okl_testing_getFallbackData();
    $random_teacher = $fallback_data->random('teacher');
    
    $username = $random_teacher->mail;

    $I->login($username, null, $saveSession);

  }

}