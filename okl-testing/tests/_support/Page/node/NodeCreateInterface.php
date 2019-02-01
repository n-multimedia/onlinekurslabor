<?php

namespace Page\node;

interface NodeCreateInterface {

    public function __construct(\AcceptanceTester $I);

    /**
     * get node-id of lately created Node
     * @return int $nid
     */
    public function getNewNid();

    /**
     * Non-abstract class must fill fields.
     * @param \AcceptanceTester $I for convenience
     * @param \Codeception\Example $params 
     */
    public function fillFields(\AcceptanceTester $I, \Codeception\Example $params);
}
