<?php

/**
 * overwrites vendor/fakerphp/faker/src/Faker/Provider/de_DE/Internet.php
 * using values from vendor/fakerphp/faker/src/Faker/Provider/Internet.php
 */

namespace Faker\Provider\de_DE;

class Internet extends \Faker\Provider\Internet {

    protected static $freeEmailDomain = array(
        'div.onlinekurslabor.de'
    );
    protected static $emailFormats = array(
        '{{userName}}+autotest@{{freeEmailDomain}}',
    );
    protected static $userNameFormats = array(
        '{{lastName}}.{{firstName}}',
        '{{firstName}}.{{lastName}}',
        '{{firstName}}##',
    );
}
