<?php
namespace RealisticFaker\en_US;

/**
 * Sonderfall: en_US hat keinen internet-provider, da das im Baseprovider drin ist
 * class extends Faker\Provider\Internet in order to get protected values from class
 */
class InternetThief extends \Faker\Provider\Internet {

    public static function steal($protectedelementname) {
        return static::$$protectedelementname;
    }

}
