<?php


class GeneralCest extends CestHelper{

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function G001_01_frontpage_important_links_available(AcceptanceTester $I) {
    $I->amOnPage('/');
    
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
    $I->see('Zugriff verweigert.');
  }

   /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function G001_03_basic_information_available(AcceptanceTester $I) {
    $I->amOnPage('/');
    $I->see('Informationen für Studierende');
    $I->see('Informationen für Hochschullehrende');
    $I->see('Informationen für Partnerorganisationen');
  }

  
  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   * @before skipIfOnShittyBrowser
   */
  public function G001_04_coursepresentation_available(AcceptanceTester $I) {
    $I->amOnPage('/');
    $I->click("Informationen für Studierende");
    $I->makeScreenshot(__FUNCTION__);
    //Teil der H5P-Info
    # switch to h5p-iframe
    $I->switchToIFrame("#h5p-iframe-6947");
    $I->see('Kursangebot');
  }
  
   /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function G001_05_login_page_exists(AcceptanceTester $I) {
    $I->amOnPage('/user');
    //login
    $I->see('E-Mail oder Kontoname');
    $I->see('Passwort');
    //password reset
    $I->see('Neues Passwort anfordern');    

  }

    protected function getMaincontextType() {
        return "undefined"; //not necessary in this context
    }

}
