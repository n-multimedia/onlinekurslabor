<?php

namespace Page\node;

interface NodeEditInterface {
  
    
    public function   __construct(\AcceptanceTester $I, $nid);
  
     
    /**
     * Edit a Node
     * @param \AcceptanceTester $I
     * @param \Codeception\Example $params  an array containing values 
     */
    public function editFields(\AcceptanceTester $I, \Codeception\Example $params);

}
