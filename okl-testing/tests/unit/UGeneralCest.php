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
     * @example { "text": "@sergio-nachio ciao", "result": true }
     * @example { "text": "@sergio-nachio2 ciao", "result": true }
     * @example { "text": "hallo @sergio_nachio ciao", "result": true }
     * @example { "text": "hallo @sergio_nachio2 ciao", "result": true }
     * @example { "text": "@sergio_nachio", "result": true }
     * @example { "text": "@sergio_nachio2", "result": true }
     * @example { "text": "@Sergio Nacho", "result": true }
     * @example { "text": "@Sergio Nacho2", "result": true }
     * @example { "text": "@Sergio Nacho-Macho", "result": true }
     * @example { "text": "@Sergio Nacho-Macho2", "result": true }
     * @example { "text": "hallo @sergio.nachio", "result": true }
     * @example { "text": "@sergio", "result": true }
     * @example { "text": "@sergio2", "result": true }
     * @example { "text": "hallo @sergio", "result": true }
     * @example { "text": "hallo @sergio2", "result": true }
     * @example { "text": "hallo @sergio ciao", "result": true }
     * @example { "text": "hallo @sergio2 ciao", "result": true }
     * @example { "text": "hallo sergio2 ciao", "result": false }
     * @example { "text": "hallo @ sergio2 ciao", "result": false }
     * @example { "text": "hallo @ sergio_nachio ciao", "result": false }
     */
    public function G001_mention_regex(UnitTester $I, \Codeception\Example $example)
    {
        $matches = [];
        $regex = NM_STREAM_MENTION_REGEX;
        $result = preg_match($regex, $example['text'], $matches, PREG_OFFSET_CAPTURE);

        $I->assertEquals($result, $example['result'], 'regex match found');
    }
    
}
