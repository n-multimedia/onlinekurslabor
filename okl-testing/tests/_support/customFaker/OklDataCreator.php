<?php

namespace RealisticFaker;

//fuer emailadressen brauchen wir eigene values. Durch includen dieser file wird de_DE-default überschrieben
require_once(__DIR__ . '/Internet-de_DE.php');
//ein eigener Provider fürs OKl
require_once(__DIR__ . '/OklProvider.php');


class OklDataCreator extends \RealisticFaker\DataCreator {

    public static function get($identifier) {
        return new OklDataCreator($identifier, 'de_DE');
    }

    public function __construct($identifier = null, $langcode = 'de_DE') {

        parent::__construct($identifier, $langcode);

        //Zugriff auf erzeugte Namen.. 
        $this->oklUserName = sprintf('%s %s', $this->firstName, $this->lastName);

         
        //schöneres Loremipsum
        $this->addProvider(new \NewAgeIpsum\NewAgeProvider($this->faker));
    }

}
