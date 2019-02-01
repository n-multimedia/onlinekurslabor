<?php

namespace Step\Acceptance;



class Author extends UserSteps {

  public function loginAsAuthor($saveSession = TRUE) {
   
    $I = $this;

    $username = "fahrneul";
    
    $I->login($username, null, $saveSession);

  }

}