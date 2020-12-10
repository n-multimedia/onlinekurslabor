<?php

/**
 * Teste den Nachrichten-Stream 
 */
class CourseForumCest extends CestHelper {

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
   * Dozent activates Forum
   * 
   * @UserStory null
   * @param \Step\Acceptance\Dozent $I
   * @before logAccountOut
   * @before skipNonApplicableExample
   */
  public function CFC001_01_ActivateForum(\Step\Acceptance\Dozent $I) {
    $I->loginAsDozent();
    $this->goToContextHome($I);
    $current_course_object = node_load($this->getCurrentContextNid());
    $I->useCourseMenu(false, 'Kurseinstellungen');

    $I->click("Features");
    $I->checkOption("Forum");
    $I->click("Speichern");
    $I->see("Courses - Kurs " . $current_course_object->title . " wurde aktualisiert.");
  }

  /**
   * some students test the forum
   * 
   * @UserStory null
   * @param \Step\Acceptance\Student $I
   * @dataProvider CFC001_StudentAndPostProvider
   * @before logAccountOut
   * @before skipNonApplicableExample
   */
  public function CFC001_02_TestForum(\Step\Acceptance\Student $I, \Codeception\Example $studentandposts) {
    $I->login($studentandposts['mail'], null, false);
    $this->goToContextHome($I);


    //klicke forum in der kursleiste
    $I->click("Forum", "section#block-section-courses-course-top-navigation");


    if (!empty($studentandposts['forum']['message'])) {
      $I->click("Forenthema erstellen");
      $I->fillField('Betreff *', $studentandposts['forum']['message']['title']);
      $I->fillCkEditorByName('body[und][0][value]', $studentandposts['forum']['message']['text']);
      $I->click("Speichern");
      $I->wait(2);
      $I->see("Forenthema " . $studentandposts['forum']['message']['title'] . " wurde erstellt.");
    }
    else {
      $I->wait(1);
      //$I->click($studentandposts['forum']['comment']['topic']); geht nicht
      $I->clickLinkBugProof($studentandposts['forum']['comment']['topic']);

      $I->fillField('subject', $studentandposts['forum']['comment']['title']);
      $I->fillCkEditorByName('comment_body[und][0][value]', $studentandposts['forum']['comment']['text']);
      $I->click("Speichern");
      $I->wait(2);
      $I->see($studentandposts['forum']['comment']['text']);
    }
    $I->makeScreenshot('forum_saved' . $studentandposts['mail']);
  }

  /**
   *  Provider für CFC001_02_TestForum
   * @return array
   */
  protected function CFC001_StudentAndPostProvider() {

    // Man kann hier nicht mit $course_nid = $this->getCurrentContextNid() etc arbeiten, da providers vor Ausführung "kompiliert" werden
    //holt gefakte studenten und fallback als array
    //ein foreneintrag, darauf zwei antworten.
    $sample_arr = $this->DP_getSampleStudents(3, 0, true);
    $student_arr = [];
    foreach ($sample_arr as $user) {
      $student_arr[$user['type']][] = $user;
    }


    $return_arr = [];
    $totalcounter = 0;
    foreach ($student_arr as $type => $userarr) {
      $types_usercount = 0;
      $forum_title = "";
      foreach ($userarr as $user) {

        $rand_data_creator = \RealisticFaker\OklDataCreator::get();
        $return_arr[$totalcounter] = $user;

        //1 forumseintrag darauf 2 antworten
        if ($types_usercount % 3 == 0) {
          $forum_title = $rand_data_creator->realText(15);
          $return_arr[$totalcounter]['forum']['message']['title'] = $forum_title;
          $return_arr[$totalcounter]['forum']['message']['text'] = $rand_data_creator->realText(240);
        }
        else {
          $return_arr[$totalcounter]['forum']['comment']['topic'] = $forum_title;
          $return_arr[$totalcounter]['forum']['comment']['title'] = $rand_data_creator->realText(12);
          $return_arr[$totalcounter]['forum']['comment']['text'] = $rand_data_creator->realText(100);
        }
        $return_arr[$totalcounter]['type'] = $type;
        $totalcounter++;
        $types_usercount++;
      }
    }
 
    return $return_arr;
  }

}
