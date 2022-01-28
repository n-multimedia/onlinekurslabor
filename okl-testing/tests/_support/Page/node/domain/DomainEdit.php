<?php

namespace Page\node\domain;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of DomainEdit
 *
 * @author Bernhard
 */
class DomainEdit extends \Page\node\Node implements \Page\node\NodeEditInterface {

    public function __construct(\AcceptanceTester $I, $domain_nid) {
        //$course = node_load($course_nid);
        \Page\node\Node::__construct($I);
        self::$editURL = sprintf('domain/edit/%s?og_group_ref=%s', $domain_nid, $domain_nid);
    }

    /**
     * Edit a Node
     * @param \AcceptanceTester $I
     * @param \Codeception\Example $params  an array containing values 
     */
    public function editFields(\AcceptanceTester $I, \Codeception\Example $params) {
         if(!empty($params['body']))
         {
             $I->fillCkeEditorByAPI('edit-field-domain-description-und-0-value', $params['body']);
         }
         /* if(!empty($params['body-add-h5p']))
          { //göht nisch
              $I->fillCkExtraFeature('h5p_button', $params['body-add-h5p']);
          }*/
        
    }

}
