<?php
namespace RealisticFaker;

use Faker\Provider\Base;

class OklProvider extends Base
{
    public function node_title()
    {
        return "is set in OklGenerator!"; 
    }
    
    public function node_body()
    {
        return "is set in OklGenerator!"; 
    }
     public function node_body_summary()
    {
        return "is set in OklGenerator!"; 
    }
    
    
    public function currentSemesterName()
    {
        $current_semester = taxonomy_term_load(variable_get('okl_current_semester'));
        return $current_semester->name; 
    }
    
}