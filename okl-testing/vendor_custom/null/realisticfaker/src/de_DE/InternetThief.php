<?php
namespace RealisticFaker\de_DE;

/**
 * class extends Faker\Provider\LANG_LANG\Internet in order to get protected values from class
 */
class InternetThief extends \Faker\Provider\de_DE\Internet {

    public static function steal($protectedelementname) {
        return static::$$protectedelementname;
    }

}
