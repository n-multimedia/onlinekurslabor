<?php
namespace RealisticFaker;

use Faker\Provider\Base;

class OklProvider extends Base
{
    public function node_title()
    {
        return "is set in OklDataCreator!"; 
    }
    
    public function node_body()
    {
        return "is set in OklDataCreator!"; 
    }
     public function node_body_summary()
    {
        return "is set in OklDataCreator!"; 
    }
    
    
    public function currentSemesterName()
    {  //@todo das muss natürlich über OKL-Api ausgelesen werden
        return 'SS 18';
    }
    
}