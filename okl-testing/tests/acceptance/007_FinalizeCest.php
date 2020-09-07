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
   * @param \Step\Acceptance\Dozent $I
   */
  public function C001_06_resetContext(\Step\Acceptance\Dozent $I) {
    $this->resetCurrentContextNid();
  }

}
