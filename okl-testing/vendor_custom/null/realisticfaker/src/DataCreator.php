<?php
namespace RealisticFaker;

use Faker;


/**
 * @property string $name 
 * @property string $firstName  
 * @property string $middleName
 * @property string $lastName
 * @property string $title  
 *
 * @property string $citySuffix
 * @property string $streetSuffix
 * @property string $buildingNumber
 * @property string $city
 * @property string $streetName
 * @property string $streetAddress
 * @property string $postcode
 * @property string $address
 * @property string $country
 * @property float  $latitude
 * @property float  $longitude
 *
 * @property string $ean13
 * @property string $ean8
 * @property string $isbn13
 * @property string $isbn10
 *
 * @property string $phoneNumber
 *
 * @property string $company
 * @property string $companySuffix
 * @property string $jobTitle
 *
 * @property string $creditCardType
 * @property string $creditCardNumber
 * @method string creditCardNumber($type = null, $formatted = false, $separator = '-')
 * @property \DateTime $creditCardExpirationDate
 * @property string $creditCardExpirationDateString
 * @property array $creditCardDetails
 * @property string $bankAccountNumber
 * @method string iban($countryCode = null, $prefix = '', $length = null)
 * @property string $swiftBicNumber
 * @property string $vat
 *
 * @property string $word
 * @property string|array $words
 * @method string|array words($nb = 3, $asText = false)
 * @property string $sentence
 * @method string sentence($nbWords = 6, $variableNbWords = true)
 * @property string|array $sentences
 * @method string|array sentences($nb = 3, $asText = false)
 * @property string $paragraph
 * @method string paragraph($nbSentences = 3, $variableNbSentences = true)
 * @property string|array $paragraphs
 * @method string|array paragraphs($nb = 3, $asText = false)
 * @property string $text
 * @method string text($maxNbChars = 200)
 *
 * @method string realText($maxNbChars = 200, $indexSize = 2)
 *
 * @property string $email
 * @property string $safeEmail
 * @property string $freeEmail
 * @property string $companyEmail
 * @property string $freeEmailDomain
 * @property string $safeEmailDomain
 * @property string $userName
 * @property string $password
 * @method string password($minLength = 6, $maxLength = 20)
 * @property string $domainName
 * @property string $domainWord
 * @property string $tld
 * @property string $url
 * @property string $slug
 * @method string slug($nbWords = 6, $variableNbWords = true)
 * @property string $ipv4
 * @property string $ipv6
 * @property string $localIpv4
 * @property string $macAddress
 *
 * @property int       $unixTime
 * @property \DateTime $dateTime
 * @property \DateTime $dateTimeAD
 * @property string    $iso8601
 * @property \DateTime $dateTimeThisCentury
 * @property \DateTime $dateTimeThisDecade
 * @property \DateTime $dateTimeThisYear
 * @property \DateTime $dateTimeThisMonth
 * @property string    $amPm
 * @property string    $dayOfMonth
 * @property string    $dayOfWeek
 * @property string    $month
 * @property string    $monthName
 * @property string    $year
 * @property string    $century
 * @property string    $timezone
 * @method string amPm($max = 'now')
 * @method string date($format = 'Y-m-d', $max = 'now')
 * @method string dayOfMonth($max = 'now')
 * @method string dayOfWeek($max = 'now')
 * @method string iso8601($max = 'now')
 * @method string month($max = 'now')
 * @method string monthName($max = 'now')
 * @method string time($format = 'H:i:s', $max = 'now')
 * @method int unixTime($max = 'now')
 * @method string year($max = 'now')
 * @method \DateTime dateTime($max = 'now', $timezone = null)
 * @method \DateTime dateTimeAd($max = 'now', $timezone = null)
 * @method \DateTime dateTimeBetween($startDate = '-30 years', $endDate = 'now')
 * @method \DateTime dateTimeInInterval($date = '-30 years', $interval = '+5 days', $timezone = null)
 * @method \DateTime dateTimeThisCentury($max = 'now', $timezone = null)
 * @method \DateTime dateTimeThisDecade($max = 'now', $timezone = null)
 * @method \DateTime dateTimeThisYear($max = 'now', $timezone = null)
 * @method \DateTime dateTimeThisMonth($max = 'now', $timezone = null)
 *
 * @property string $md5
 * @property string $sha1
 * @property string $sha256
 * @property string $locale
 * @property string $countryCode
 * @property string $countryISOAlpha3
 * @property string $languageCode
 * @property string $currencyCode
 * @property boolean $boolean
 * @method boolean boolean($chanceOfGettingTrue = 50)
 *
 * @property int    $randomDigit
 * @property int    $randomDigitNotNull
 * @property string $randomLetter
 * @property string $randomAscii
 * @method int randomNumber($nbDigits = null, $strict = false)
 * @method int|string|null randomKey(array $array = array())
 * @method int numberBetween($min = 0, $max = 2147483647)
 * @method float randomFloat($nbMaxDecimals = null, $min = 0, $max = null)
 * @method mixed randomElement(array $array = array('a', 'b', 'c'))
 * @method array randomElements(array $array = array('a', 'b', 'c'), $count = 1, $allowDuplicates = false)
 * @method array|string shuffle($arg = '')
 * @method array shuffleArray(array $array = array())
 * @method string shuffleString($string = '', $encoding = 'UTF-8')
 * @method string numerify($string = '###')
 * @method string lexify($string = '????')
 * @method string bothify($string = '## ??')
 * @method string asciify($string = '****')
 * @method string regexify($regex = '')
 * @method string toLower($string = '')
 * @method string toUpper($string = '')
 * @method Generator optional($weight = 0.5, $default = null)
 * @method Generator unique($reset = false, $maxRetries = 10000)
 * @method Generator valid($validator = null, $maxRetries = 10000)
 *
 * @method integer biasedNumberBetween($min = 0, $max = 100, $function = 'sqrt')
 *
 * @property string $macProcessor
 * @property string $linuxProcessor
 * @property string $userAgent
 * @property string $chrome
 * @property string $firefox
 * @property string $safari
 * @property string $opera
 * @property string $internetExplorer
 * @property string $windowsPlatformToken
 * @property string $macPlatformToken
 * @property string $linuxPlatformToken
 *
 * @property string $uuid
 *
 * @property string $mimeType
 * @property string $fileExtension
 * @method string file($sourceDirectory = '/tmp', $targetDirectory = '/tmp', $fullPath = true)
 *
 * @method string imageUrl($width = 640, $height = 480, $category = null, $randomize = true, $word = null, $gray = false)
 * @method string image($dir = null, $width = 640, $height = 480, $category = null, $fullPath = true, $randomize = true, $word = null)
 *
 * @property string $hexColor
 * @property string $safeHexColor
 * @property string $rgbColor
 * @property array $rgbColorAsArray
 * @property string $rgbCssColor
 * @property string $safeColorName
 * @property string $colorName
 *
 * @method string randomHtml($maxDepth = 4, $maxWidth = 4)
 *
 */
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
        * Deswegen wird innerhalb dieses Objekts ein Profil vorgeneriert, welches man via DataCreator::get('somedude')->firstName auslesen kann und sogar
        * durch Übergabe des $identifiers via DataCreator::get('somedude').. wieder neu erzeugen kann 
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
     * steals a private propery from class Faker\Provider\Internet and its derivates and returns randomly one of its values
     * @param type $static_variable_name
     * @return type
     */
    private function getRandomStaticVariableFromInternetProvider($static_variable_name) {
        $thiefprovider = $this->getInternetThiefProvider();
        return $this->faker->randomElement($thiefprovider->steal($static_variable_name));
    }

    /**
     * call a protected function in class Faker\Provider\Internet and its derivates 
     * @param type $static_function_name the function to call
     * @param array $arguments the function's arguments
     * @return mixed $result Function's result
     */
    private function callProtectedFunctionFromInternetProvider($static_function_name, array $arguments = null)
    {
        $thiefprovider = $this->getInternetThiefProvider();
        $result = $thiefprovider->callProtected('transliterate', $arguments);

        return $result;
    }

    /**
     * get InternetThiefProvider in Faker's providerlist. Only used internally
     * @return StdClass $provider
     */
    private function getInternetThiefProvider()
    {
           foreach ($this->faker->getProviders() as $provider) {
            if (strstr(get_class($provider), 'InternetThief')) {
                return $provider;
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
        //führe protected "transliterate" aus
        $new_uname = $this->callProtectedFunctionFromInternetProvider('transliterate', array($new_uname));

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
