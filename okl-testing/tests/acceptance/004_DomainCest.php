<?php

use \Codeception\Util\Fixtures; 
 
use Page\node\domain\Create  as CreateDomainPage;

class DomainCest {
 


  public function _before(\Step\Acceptance\Author $I) {

    $I->loginAsAuthor(TRUE);

  }

  public function _after(AcceptanceTester $I) {

  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \AcceptanceTester $I
   */
  public function CD001_01_AuthorLoggedin(AcceptanceTester $I) {

    $I->amOnPage('/');
    $I->see('Meine Veranstaltungen');
    $I->click('Meine Veranstaltungen');
    $I->see('Meine Lehrtexte');
  }

  /**
   * @UserStory null
   * @UserStoryURL null
   *
   * @param \Step\Acceptance\Author $I instead of \AcceptanceTester $I
   * @param \Codeception\Example $example array holds dataprovider's data
   * @dataProvider CD001_02_CreateDomainProvider
   */
  public function CD001_02_CreateDomain(\Step\Acceptance\Author $I, \Codeception\Example $example) {
          
        $I->amOnPage('/');
        
        $I->click('Meine Veranstaltungen');
        $I->click('//a[@title="Lehrtext erstellen"]');
         
        
        
        //refactored
        $cdpage = new CreateDomainPage($I);
         $cdpage->create($example);
        
        //get new nid
         $nid = $cdpage->getNewNid();
        #Fixtures::add('course_home_url', $course_home_url);
    }
    
    
  /**
   * Funktion ist der dataprovider für CD001_02_CreateDomain
   * @return array
   */
  protected function CD001_02_CreateDomainProvider() {
        $return = array();
        $rand_data = \RealisticFaker\OklDataCreator::get();
         
        $return[] = ['title' => $rand_data->text(40), 'body' => $rand_data->paragraph(30)];
        
        return $return;
    }
 
    
  
}
