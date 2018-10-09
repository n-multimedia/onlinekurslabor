<?php
namespace RealisticFaker\de_DE;

/**
 * class extends Faker\Provider\LANG_LANG\Internet in order to get protected values from class
 */
class InternetThief extends \Faker\Provider\de_DE\Internet {

    public static function steal($protectedelementname) {
        return static::$$protectedelementname;
    }
    
    /**
     * execute a normally protected function and return the result 
     * @param string $function_name function to be called, e.g. "transliterate"
     * @param array $arguments the arguments, e.g. array("Mü Nutzernam")
     * @return mixed $return
     */
    public function callProtected($function_name, $arguments)
    {
        return call_user_func_array(array($this,$function_name),$arguments);
    }
   

}
