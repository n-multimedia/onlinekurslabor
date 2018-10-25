<?php

namespace Page\node;

interface NodeEditInterface {
  
    
    public function   __construct(\AcceptanceTester $I, $content_type);
    /**
     * Edit a Node
     * @param \Codeception\Example $params  an array containing values 
     * @return StdClass $this 
     */
    public function edit($nid, \Codeception\Example $params); 

}
