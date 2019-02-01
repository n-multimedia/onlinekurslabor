<?php

use Page\node\domain\DomainCreate  as CreateDomainPage;

class TextCest extends CestHelper{

 


  public function _before(\Step\Acceptance\Author $I) {

    $I->loginAsAuthor(TRUE);

  }

  public function _after(AcceptanceTester $I) {

  }

  /**
   * @UserStoryies XX.xx |  xx | https://trello.com/xxx
   *
   * @param \AcceptanceTester $I
   */
  public function T002_01_AuthorLoggedin(AcceptanceTester $I) {

    $I->amOnPage('/');
    $I->see('Meine Veranstaltungen');
  }

  /**
   * @UserStoryies XX.xx |  xx | https://trello.com/xxx
   *
   * @param \AcceptanceTester $I
   * @param \Codeception\Example $domain_example Example-object
   * @dataProvider T002_createDomainsProvider
   */
  public function T002_02_CreateText(\Step\Acceptance\Author $I, Codeception\Example $domain_example) {

    

    $I->amOnPage('/');
    $I->click('Meine Veranstaltungen');
    $I->see('Meine Lehrtexte');


    $I->click('a[title="Lehrtext erstellen"]');

    $ccpage = New CreateDomainPage($I);
    $ccpage->create($domain_example);

    $I->amOnPage('/');
    $I->click('Meine Veranstaltungen');
    $I->see($domain_example['title']);

  }

    /**
     * der Dataprovider liefert nötige Variablen
     * @return Codeception\Example $domain_example 
     */
    protected function T002_createDomainsProvider() {
        return $this->DP_getSampleDomain(0, false, false);
    }

}
