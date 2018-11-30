<?php

namespace Page\node\domain_content;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of DomainContentBase
 *
 * @author Bernhard
 */
class DomainContentBase extends \Page\node\Node {
    
    private static $baseAddURL = '/domain/add/%s/%s?og_group_ref=%s';
    //private static $baseEditURL = '...';

    public function __construct(\AcceptanceTester $I, $domain_nid, $new_content_type) {
        parent::__construct($I);
        parent::$createURL = sprintf(self::$baseAddURL, $domain_nid, $new_content_type, $domain_nid);
        
    }


}
