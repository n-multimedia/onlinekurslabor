<?php

/**
 * Resets  CurrentContextNid
 * Use before running a new CEST
 */
class FinalizeCest extends CestHelper {

  /**
   * setze Typ des aktuellen HauptContexts.
   * Also das, was prinzipiell im aktuellen Cest getestet wird.
   * Entweder NM_COURSE oder NM_CONTENT_DOMAIN
   * 
   * @return string type
   */
  protected function getMaincontextType() {
    return NM_COURSE;
  }

  /**
   * setze current Context wieder auf den Fallbackkurs statt den eben erstellten.
   * @param AcceptanceTester $I
   */
  public function F001_01_resetContext(AcceptanceTester $I) {
    $this->resetCurrentContextNid();
  }

  /**
   * Nötige Aktion, damit records.html nicht leer ist. 
   * @param \Step\Acceptance\Dozent $I
   */
  public function F001_02_fixRecordsHTML(AcceptanceTester $I) {
    //When a komplete CEST doesn\'t have an $I->do()... this leads to the records.html being empty.
    //so just do something.
    $I->amOnPage('/');
  }

}
