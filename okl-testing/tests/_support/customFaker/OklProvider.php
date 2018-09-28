<?php
namespace RealisticFaker;

use Faker\Provider\Base;

class OklProvider extends Base
{
    public function currentSemesterName()
    {  //@todo das muss natürlich über OKL-Api ausgelesen werden
        return 'SS 18';
    }
}