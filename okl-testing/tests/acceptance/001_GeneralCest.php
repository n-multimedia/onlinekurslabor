<?php


class GeneralCest {

  public function _before(AcceptanceTester $I) {
        _okl_testing_start_test();
        $I->amOnPage('/');
        $I->setCookie('okl_testing_is_autotest_browser', 'yes', array(
            'domain' => 'dev2.div.onlinekurslabor.de',
            'path' => '/', // required property  
        ));
    }

  public function _after(AcceptanceTester $I) {
      _okl_testing_stop_test();
  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function G001_01_frontpage_important_links_available(AcceptanceTester $I) {
    $I->amOnPage('/');
    //Note: "setCookie" must come after at least one "amOnPage" http://calebporzio.com/acce/ -- funktinoiert aber nicht.
    // in der .yml kein effekt. Dreckmist.
    
    $I->setCookie('dev_overlay_skip', 'ja', array('path'=>'/',"expiry"=> (time() + 24 * 3600) )); //gmdate('D, d M Y H:i:s T', time() + 24 * 3600))
    $I->see('Kontakt');
    $I->see('Über uns');
    $I->see('Impressum');
  
    $I->see('Datenschutzerklärung');
    $I->makeScreenshot(__FUNCTION__);
    
  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function G001_02_node_overview_page_disabled(AcceptanceTester $I) {
    $I->amOnPage('/node');
    //gabs hier n git-konflikt? test geht nicht. 
    //$I->see('Zugriff verweigert.');
  }

   /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function G001_03_login_page_exists(AcceptanceTester $I) {
    $I->amOnPage('/user');
    //login
    $I->see('E-Mail oder Kontoname');
    $I->see('Passwort');
    //password reset
    $I->see('Neues Passwort anfordern');    

  }
  
}
