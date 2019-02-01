<?php

namespace Step\Acceptance;


class SuperAdmin extends UserSteps {

  public function loginAsSuperAdmin($saveSession = TRUE) {
  
    $I = $this;
    $superadmin_uname = user_load(1)->name;

    $I->login($superadmin_uname, null, $saveSession);

  }

}