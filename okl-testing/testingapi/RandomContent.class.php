<?php
namespace testingapi; 
/**
 * Bedienung:  RandomContent::get('somedude')->firstName ; 
 * oder fuer nicht-wiederholbare Zufallswerte: RandomContent::get()->firstName ; 
 *
 * @author Bernhard
 */
class RandomContent {

    private $faker;
    private static $emailformat = '%s.%s+autotest@div.onlinekurslabor.de';

    /**
     * Liefert neues Objekt
     * @param type $identifier: Wird ein $identifier gesetzt, sind die erhaltenen Werte beim nächsten Testdurchlauf unverändert. Sonst bei jedem Durchlauf Zufallswerte
     * @return \RandomContent 
     */
    public static function get($identifier = null) {

        return new RandomContent($identifier);
    }

    /**
     * Konstruktur
     * @param type $identifier: Wird ein $identifier gesetzt, sind die erhaltenen Werte beim nächsten Testdurchlauf unverändert. Sonst bei jedem Durchlauf Zufallswerte
     *  
     */
    public function __construct($identifier = null) {
        $faker = Faker\Factory::create('de_DE');

        if ($identifier) {
            $faker->seed(crc32($identifier));
        } else {
            //entferne ggf vorhandenen seed
            $faker->seed(null);
        }
        $faker->addProvider(new NewAgeIpsum\NewAgeProvider($faker));
        $this->faker = $faker;
        $this->initialize();
    }

    /**
     * überarbeitet Strings. Derzeit:
     * replace "  " by " "
     * @param type $string
     * @return type string veränderter String
     */
    private static function simplifyString($string) {
        return preg_replace('/\s+/', ' ', $string);
    }

    /**
     * Das Problem: Faker liefert bei Ausführung IMMER einen random-Wert.
     * Also: 
     * firstName = Erwin
     * email = Katharina.Hust@... 
     * Das passt nicht.
     * Deswegen wird innerhalb dieses Objekts ein Profil vorgeneriert, welches man via RandomContent::get('somedude')->firstName auslesen kann und sogar
     * durch Übergabe des $identifiers via RandomContent::get('somedude').. wieder neu erzeugen kann 
     * Wird über $obj->creditCardExpirationDate ein Wert abgefragt, der nicht vorinitialisiert wird,
     * wird Faker direkt bemüht.
     * @return \StdClass
     */
    private function initialize() {

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
        $this->username = sprintf("%s %s", $this->firstName, $this->lastName);
        $this->safeUsername = sprintf("%s.%s", $this->firstName, $this->lastName);
        $this->email = strtolower(sprintf(self::$emailformat, $this->firstName, $this->lastName));

        //   $pr->address = $this->faker->address();
        $this->streetName = $this->faker->streetName();
        $this->streetAddress = $this->faker->streetAddress();
        $this->postCode = $this->faker->postCode();
        $this->timezone = $this->faker->timezone();
        $this->password = $this->faker->password();
        $this->imageUrl = $this->faker->imageUrl(200, 200);
    }

     /* ********************************************************
     *   DIESE FUNKTIONEN SIND WRAPPER AUF FAKER
     *   ermöglicht Zugriff auf Original-API via  RandomContent::get()->phoneNumber
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
