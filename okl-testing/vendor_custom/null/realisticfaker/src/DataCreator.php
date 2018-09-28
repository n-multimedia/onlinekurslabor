<?php
namespace RealisticFaker;

use Faker;


class DataCreator {

    protected $faker;

    /**
     * Liefert neues Objekt
     * @param String $identifier: Wird ein $identifier gesetzt, sind die erhaltenen Werte beim nächsten Testdurchlauf unverändert. Sonst bei jedem Durchlauf Zufallswerte
     * @param String $langcode Sprache. Default: en_US
     * @return \RandomContent 
     */
    public static function get($identifier = null, $langcode = Faker\Factory::DEFAULT_LOCALE) {

        return new DataCreator($identifier,$langcode);
    }

    /**
     * Konstruktur
     * @param String $identifier: Wird ein $identifier gesetzt, sind die erhaltenen Werte beim nächsten Testdurchlauf unverändert. Sonst bei jedem Durchlauf Zufallswerte
     * @param String $langcode Sprache. Default: en_US
     */
    public function __construct($identifier = null,$langcode = Faker\Factory::DEFAULT_LOCALE) {

        $faker = Faker\Factory::create($langcode);

        if ($identifier) {
            $faker->seed(crc32($identifier));
        } else {
            //entferne ggf vorhandenen seed
            $faker->seed(null);
        }
         
      
        $this->faker = $faker;
        
        
        $internetthiefClassName = 'RealisticFaker\\' . $langcode . '\InternetThief';
        $this->addProvider(new $internetthiefClassName($faker));
        
        //Hier wird noch initialisiert
       /**
        * Das Problem: Faker liefert bei Ausführung IMMER einen random-Wert.
        * Also: 
        * firstName = Erwin
        * email = Katharina.Hust@... 
        * Das passt nicht.
        * Deswegen wird innerhalb dieses Objekts ein Profil vorgeneriert, welches man via RandomContent::get('somedude')->firstName auslesen kann und sogar
        * durch Übergabe des $identifiers via RandomContent::get('somedude').. wieder neu erzeugen kann 
        * Wird z.B. über $obj->creditCardExpirationDate ein Wert abgefragt, der nicht vorinitialisiert wird,
        * wird Faker direkt bemüht.
        * 
        */
        //[male, female]
        $sexes = array(Faker\Provider\Person::GENDER_MALE, Faker\Provider\Person::GENDER_FEMALE);
        //diese Klassenvariablen werden gesetzt und somit nicht bei jeder Anfrage erneut erzeugt. 
        //Wird nun über $obj->creditCardExpirationDate  ein Wert abgefragt, der nicht vorinitialisiert wird,
        // wird Faker direkt bemüht.
        $this->sex = $sexes[$this->faker->numberBetween(0, 1)];

        $this->firstName = $this->faker->firstName($this->sex);
        //optional: 2. vorname. Ist unabhängig vom 1.aufruf
        $this->middleName = $this->faker->numberBetween(0, 1) ? '' : $this->faker->firstName($this->sex);
        $this->lastName = $this->faker->lastName();


        //needs to be calculated....
        //gnah... 
        $this->name = self::simplifyString(sprintf("%s %s %s", $this->firstName, $this->middleName, $this->lastName));
        //Auch kalkuliert, aber über custom functions: userName , >email
         
        //   $pr->address = $this->faker->address();
        $this->streetName = $this->faker->streetName();
        $this->streetAddress = $this->faker->streetAddress();
        $this->postCode = $this->faker->postCode();
        $this->timezone = $this->faker->timezone();
        $this->password = $this->faker->password();
        $this->imageUrl = $this->faker->imageUrl(200, 200);
    }

    
    /**
     * wrapper to Faker. Normal usage: 
     * $datacreator->addProvider(new \My\Provider($datacreator->getProvider()));
     * @param StdClass $provider
     * @throws \InvalidArgumentException
     */
    public function addProvider($provider) 
    {
        $this->faker->addProvider($provider);
    }
    
     
    

    
    
    /**
     * faker->parse() nimmt statt der gesetzten Werte einen neuen Wert (zB für firstName), so dass die Ausgabe nicht realistisch ist.
     * Deswegen werden vorab per billiger replace-Funktion die Personen-Variablen ersetzt und andere parse-Funktionen an 
     * $faker weitergegeeben.
     * @param string $format zu parsender String
     * @param boolean $to_lower make string lowercase
     * @return string $result veränderter String
     */
    private function parse($format, $to_lower = false) {
        $result = '';
        $result = str_replace('{{userName}}', $this->username, $format);
        $result = str_replace('{{firstName}}', $this->firstName, $result);
        $result = str_replace('{{lastName}}', $this->lastName, $result);
        
        //gebe sonstige Variablen an Faker weiter
        $result = $this->faker->parse($result);
        $result = Faker\Provider\Base::bothify($result);
        
        //string noch aufräumen
        $result = self::simplifyString($result, $to_lower);

        return $result;
    }
    
    /**
     * überarbeitet Strings. 
     * @param string $string Input-String
     * @param boolean $to_lower make string lowercase
     * @return string string veränderter String
     */
    private static function simplifyString($string, $to_lower) {
        $result = preg_replace('/\s+/', ' ', $string);
        if ($to_lower) {
            $result = strtolower($result);
        }
        // clean possible trailing dots from first/last names
        $result = str_replace('..', '.', $result);
        $result = rtrim($result, '.');
        return $result;
    }

    /**
     * steals a private propery from class Faker\Provider\Internet and its derivates
     * @param type $static_variable_name
     * @return type
     */
    private function getRandomStaticVariableFromInternetProvider($static_variable_name) {
        foreach ($this->faker->getProviders() as $provider) {
            if (strstr(get_class($provider), 'InternetThief')) {
                return $this->faker->randomElement($provider->steal($static_variable_name));
            }
        }
    }
    
    /**
     * overwrite original functions
     */
    
    /**
     * 
     * @return String userName
     */
    public function userName() {

        $usernameformat = $this->getRandomStaticVariableFromInternetProvider('userNameFormats');

        $new_uname = $this->parse($usernameformat, true); 
        $this->userName = $new_uname; 
        return $new_uname;
    }


    /**
     * 
     * @return string $email
     */
    public function email() {
        $mailformat = $this->getRandomStaticVariableFromInternetProvider('emailFormats');
        $mail = $this->parse($mailformat);
        $this->email = $mail; 
        return $mail; 
    }

    
     /* *********************************************************
     *   DIESE FUNKTIONEN SIND WRAPPER AUF FAKER
     *   ermöglicht Zugriff auf Original-API via  DataCreator::get()->phoneNumber
     * ******************************************************** */

    public function __call($name, $arguments) {

        return $this->faker->__call($name, $arguments);
    }

    /**
     * @param string $attribute
     *
     * @return mixed
     */
    public function __get($attribute) {
        return $this->$attribute();
    }

}
