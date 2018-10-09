<?php

namespace Step\Acceptance;
use \Codeception\Step\Argument\PasswordArgument;


class SuperAdmin extends UserSteps {

  public function loginAsSuperAdmin($saveSession = TRUE) {
    require_once(dirname(__FILE__) . "/../../../../..//web/sites/default/settings.php");

    $I = $this;
    $superadmin_uname = user_load(1)->name;

    $I->login($superadmin_uname, null, $saveSession);

  }

}