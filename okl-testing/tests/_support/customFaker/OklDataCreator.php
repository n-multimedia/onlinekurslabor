<?php

namespace RealisticFaker;

//fuer emailadressen brauchen wir eigene values. Durch includen dieser file wird de_DE-default überschrieben
require_once(__DIR__ . '/Internet-de_DE.php');
//ein eigener Provider fürs OKl
require_once(__DIR__ . '/OklProvider.php');

/**
 * @property string $oklUserName
 * 
 * aus OklProvider:
 * @property string $currentSemesterName 
 * @property string $node_title
 * @property string $node_body
 * @property string $node_body_summary
 */
class OklDataCreator extends \RealisticFaker\DataCreator {

    public static function get($identifier = null) {
        return new OklDataCreator($identifier, 'de_DE');
    }

    public function __construct($identifier = null, $langcode = 'de_DE') {

        parent::__construct($identifier, $langcode);

        //Zugriff auf erzeugte Namen.. 
        $this->oklUserName = sprintf('%s %s', $this->firstName, $this->lastName);
      
        
        //OKLProvider für voneinenader unabhängige Random Data-Sets
        $this->addProvider(new OklProvider($this->faker));
        
        //kann in oklprovider nicht auf andere providers zugreifen, gnah ^^ 
        $this->node_title = $this->realText(40);
        $this->node_body = $this->realText(240);
        $this->node_body_summary = $this->realText(120);
          
        //schöneres Loremipsum
        $this->addProvider(new \NewAgeIpsum\NewAgeProvider($this->faker));
    }
    
    /**
     * Bei Node-Verweisen in Drupal dürfen diverse Zeichen nicht im Eingabefeld vorkommen.
     * Diese Funktion entfernt diese
     * @param String $text
     * @return String $text
     */
    public static function getSafeText($text)
    {
        return trim(str_replace(array(',','"', "'", ".","!","?",":"), '', $text));
    }

}
