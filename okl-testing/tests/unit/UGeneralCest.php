<?php


class UGeneralCest
{

    public function _before(UnitTester $I)
    {

    }

    public function _after(UnitTester $I)
    {

    }

    /**
     *
     * @param \UnitTester $I
     */
    public function G001_timezone_casted_correctly(UnitTester $I)
    {
        $end_timestamp = "2020-03-28 10:57 am";
        $end_timestamp_germany = strtotime($end_timestamp);

        $timestamp_germany = time();

        // User from Philippines renders
        date_default_timezone_set('Asia/Manila');

        $timestamp_philippines = time();
        $end_timestamp_philippines = strtotime($end_timestamp);

        $I->assertEquals($timestamp_germany, $timestamp_philippines, 'timestamps for both timezones are equal');
        $I->assertNotEquals($end_timestamp_germany, $end_timestamp_philippines, 'strtotime respects timezones');
        $I->assertEquals(($end_timestamp_germany - $end_timestamp_philippines) / (60 * 60), 7, 'timedifference are 7h');


    }


    /**
     * @param \UnitTester $I
     * @example { "mention": "sergio-nachio", "text": "@sergio-nachio ciao", "result": true }
     * @example { "mention": "sergio-nachio2", "text": "@sergio-nachio2 ciao", "result": true }
     * @example { "mention": "sergio_nachio", "text": "hallo @sergio_nachio ciao", "result": true }
     * @example { "mention": "sergio_nachio2", "text": "hallo @sergio_nachio2 ciao", "result": true }
     * @example { "mention": "sergio_nachio", "text": "@sergio_nachio", "result": true }
     * @example { "mention": "sergio_nachio2", "text": "@sergio_nachio2", "result": true }
     * @example { "mention": "Sergio Nacho", "text": "@Sergio Nacho", "result": true }
     * @example { "mention": "Sergio Nacho2", "text": "@Sergio Nacho2", "result": true }
     * @example { "mention": "Sergio Nacho-Macho", "text": "@Sergio Nacho-Macho", "result": true }
     * @example { "mention": "Sergio Nacho Macho", "text": "@Sergio Nacho Macho", "result": true }
     * @example { "mention": "Sergio Nacho-Macho2", "text": "@Sergio Nacho-Macho2", "result": true }
     * @example { "mention": "sergio.nachio", "text": "hallo @sergio.nachio", "result": true }
     * @example { "mention": "sergio", "text": "@sergio", "result": true }
     * @example { "mention": "sergio2", "text": "@sergio2", "result": true }
     * @example { "mention": "sergio", "text": "hallo @sergio", "result": true }
     * @example { "mention": "sergio2", "text": "hallo @sergio2", "result": true }
     * @example { "mention": "sergio", "text": "hallo @sergio ciao", "result": true }
     * @example { "mention": "sergio2", "text": "hallo @sergio2 ciao", "result": true }
     * @example { "mention": "sergio2", "text": "hallo sergio2 ciao", "result": false }
     * @example { "mention": "", "text": "hallo @ sergio2 ciao", "result": false }
     * @example { "mention": "", "text": "hallo @ sergio_nachio ciao", "result": false }
     */
    public
    function G001_mention_regex(UnitTester $I, \Codeception\Example $example)
    {
        $matches = [];
        $regex = NM_STREAM_MENTION_REGEX;
        $result = preg_match($regex, $example['text'], $matches, PREG_OFFSET_CAPTURE);

        $I->assertEquals($result, $example['result'], 'regex match found');

        // check if the found result is correct
        if ($example['result'] == true) {
            $I->assertEquals($example['mention'], substr(current($matches)[0] , 1), 'mention was selected correctly');
        }


    }

}
