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

}
