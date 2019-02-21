<?php

namespace Step\Acceptance;



class Author extends UserSteps {

  public function loginAsAuthor($saveSession = TRUE) {
   
     $I = $this;
    $fallback_data = _okl_testing_getFallbackData();
    $random_teacher = $fallback_data->random('teacher');
    
    $username = $random_teacher->mail;

    $I->login($username, null, $saveSession);

  }

}