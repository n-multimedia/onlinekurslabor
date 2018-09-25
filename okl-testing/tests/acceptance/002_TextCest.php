<?php

use \Codeception\Util\Fixtures;


class TextCest {


  private $fallback_text_url = "";


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
   */
  public function T002_02_CreateText(\Step\Acceptance\Author $I) {

    $text = [];
    $text['title'] =  '[T002_02_CreateText] Lehrtext @' . date('d.m.Y H:i:s');
    $text['body'] =  'Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo.';


    $I->amOnPage('/');
    $I->click('Meine Veranstaltungen');
    $I->see('Meine Lehrtexte');


    $I->click('a[title="Lehrtext erstellen"]');

    $I->fillField('title', $text['title']);
    $I->fillCkEditorByName("field_domain_description[und][0][value]", $text['body']);

    $I->click( 'Speichern' );
    $I->see( "Thema " . $text['title'] . " wurde erstellt." );

    $I->amOnPage('/');
    $I->click('Meine Veranstaltungen');
    $I->see($text['title']);

  }


    
  
}
