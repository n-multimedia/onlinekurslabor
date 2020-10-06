<?php

/**
 * Teste den Nachrichten-Stream 
 */
class StreamCest extends CestHelper {

  /**
   * setze Typ des aktuellen HauptContexts.
   * Also das, was prinzipiell im aktuellen Cest getestet wird.
   * Entweder NM_COURSE oder NM_CONTENT_DOMAIN
   * 
   * @return string type
   */
  protected function getMaincontextType() {
    return NM_COURSE;
  }

  public function _before(\Step\Acceptance\Dozent $I) {
    
  }

  public function _after(AcceptanceTester $I) {
    
  }

  /**
   * Helperfunction für Nutzerwechsel
   * @param \Step\Acceptance\Dozent $I geht aber auch für \Step\Acceptance\Student
   */
  protected function logAccountOut(\Step\Acceptance\Dozent $I) {
    $I->logout();
  }

  /**
   * all students in coursegroups test the stream
   * 
   * @UserStory null
   * @param \Step\Acceptance\Student $I
   * @dataProvider SC001_StudentAndStreamProvider
   * @before logAccountOut
   * @before skipNonApplicableExample
   */
  public function SC001_01_TestStream(\Step\Acceptance\Student $I, \Codeception\Example $studentandstream) {

    $I->login($studentandstream['mail'], null, false);
    $this->goToContextHome($I);


    $I->click(("Kursgruppe"));
    $I->wait(2);
    $I->see($studentandstream['coursegroup_title']);
    //TODO fallback muss man nochmal testen. in der kursgruppe sind angeblich viel zu vilee
   # ./codecept-run-tests.sh 006_StreamCest
   ////siehe  _okl_testing_getDataObjectForCourse
    //.... 
    if (!empty($studentandstream['stream']['message'])) {
      $I->fillField('.stream-post-form textarea.stream-textbody', $studentandstream['stream']['message']);
      $I->click("Speichern");
      $I->wait(2);
      $I->see($studentandstream['stream']['message']);
    }
    else {
      $I->fillField('.stream-comment-from  textarea.stream-textbody', $studentandstream['stream']['comment']);
      $I->click("Speichern");
      $I->wait(2);
      $I->see($studentandstream['stream']['comment']);
    }
    $I->makeScreenshot('STREAM saved' . $studentandstream['mail']);
  }

  /**
   *  Provider für TC001_04_TestTasks
   * @return array
   */
  protected function SC001_StudentAndStreamProvider() {

    // Man kann hier nicht mit $course_nid = $this->getCurrentContextNid() etc arbeiten, da providers vor Ausführung "kompiliert" werden
    
    
    //holt gefakten student und fallback als array
    //ein streameintrag, darauf zwei antworten.
    $student_arr = $this->DP_getSampleUsersToCoursegroups(3, 1, 0, true);
    $return_arr = [];
    $totalcounter = 0;
    foreach ($student_arr as $entry) {
      $rand_data_creator = \RealisticFaker\OklDataCreator::get();
   
      $type = $entry['type'];
      foreach ($entry['users'] as $types_usercount => $user) {
        $return_arr[$totalcounter] = $user;
        $return_arr[$totalcounter]["coursegroup_title"] = $entry["coursegroup_title"];

        //1 streameintrag darauf 2 antworten
        if ($types_usercount % 3 == 0) {
          $return_arr[$totalcounter]['stream']['message'] = $rand_data_creator->realText(240);
          $last_message_username = $user['name'];
        }
        else {
          $return_arr[$totalcounter]['stream']['comment'] = $rand_data_creator->realText(100). ' @' . $last_message_username;
          $last_message_username = $user['name'];
        }
        $return_arr[$totalcounter]['type'] = $type;
        $totalcounter++;
      }
    }
    

    return $return_arr;
  }

}
