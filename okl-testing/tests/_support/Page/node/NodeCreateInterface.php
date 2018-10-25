<?php

namespace Page\node;

interface NodeCreateInterface {
  
    
    public function __construct(\AcceptanceTester $I);
    
    /**
     * get NID of newly created node
     */
    public function getNewNid();

}
