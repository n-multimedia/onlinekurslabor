<?php

namespace Page\node\domain_content;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of InteractiveCreate
 *
 * @author Bernhard
 */
class InteractiveCreate extends DomainContentBase implements \Page\node\ContentCreateInterface {
    
     /**
     * Declare UI map for this page here. CSS or XPath allowed.
     */
    
    
    private static $h5pEditorIframe = 'h5p-editor-iframe';
     private static $h5peditorlibrarySelect = 'h5peditor-library';
     #private static $ui_mapping['Interactive Video' = array('')]

    public function __construct(\AcceptanceTester $I, $domain_nid) {
        parent::__construct($I, $domain_nid, NM_INTERACTIVE_CONTENT);
    }

    public function fillFields(\AcceptanceTester $I, \Codeception\Example $params) {
        //fix missing ID of iframe
        $I->executeJS("jQuery('." . self::$h5pEditorIframe . "').attr('id', '" . self::$h5pEditorIframe . "')");
        $I->switchToIFrame(self::$h5pEditorIframe);
        $I->selectOption(self::$h5peditorlibrarySelect, $params['h5p_type']);
        $I->wait(5);
        if ($params['h5p_type'] === 'Interactive Video') {

            $I->click(".h5p-add-file");
            //geht nicht, da ein div: $I->click("auswählen"); ; geht auch nicht:  $I->clickWithLeftButton(['css' => '#open_videosafe']);
            $I->executeJS("H5P.jQuery('#open_videosafe').click();");
            //goto top
            $I->switchToIFrame();
            $I->fillField("#edit-title--2", $params['videoname']);
            $I->click("Anwenden");
            $I->wait(5);
            $I->click($params['videoname']);
            $I->wait(5);
            $I->click("Dieses Video auswählen");
            $I->switchToIFrame(self::$h5pEditorIframe);
            $I->see("Videoauflösung");
            //goto top
            $I->switchToIFrame();
            //nun kommt "speichern"
        }
    }

    /**
     * get node-id of lately created course
     * @return int $nid
     */
    public function getNewNid() {
        $I = $this->tester;
        return $I->grabFromCurrentUrl('~/domain/text/(\d+)~');
    }

}
