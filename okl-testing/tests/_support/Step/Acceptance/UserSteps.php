<?php


namespace Step\Acceptance;
use \Codeception\Step\Argument\PasswordArgument;

use Page\Acceptance\LoginPage;

class UserSteps extends \AcceptanceTester {

  /**
   * @param $userName
   * @param $userPassword
   */
  public function login($userName, $userPassword, $saveSession = TRUE) {
    $I = $this;

    //$I->amOnPage("/user/logout");

    //do not log in, if session is already active
    if ($I->loadSessionSnapshot('login') && $saveSession) {
      return;
    }

    $I->amOnPage(LoginPage::$URL);

    $I->fillField('name', $userName);
    $I->fillField('pass', new PasswordArgument($userPassword));

    $I->click('Anmelden', '.form-actions');


    if($saveSession) {
      $I->saveSessionSnapshot('login');
    }


  }

  public function fillCkEditorById($element_id, $content) {
    $this->fillRteEditor(
      \Facebook\WebDriver\WebDriverBy::cssSelector(
        '#cke_' . $element_id . ' .cke_wysiwyg_frame'
      ),
      $content
    );
  }

  public function fillCkEditorByName($element_name, $content) {
    $this->fillRteEditor(
      \Facebook\WebDriver\WebDriverBy::cssSelector(
        'textarea[name="' . $element_name . '"] + .cke .cke_wysiwyg_frame'
      ),
      $content
    );
  }

  public function fillTinyMceEditorById($id, $content) {
    $this->fillTinyMceEditor('id', $id, $content);
  }

  public function fillTinyMceEditorByName($name, $content) {
    $this->fillTinyMceEditor('name', $name, $content);
  }

  private function fillTinyMceEditor($attribute, $value, $content) {
    $this->fillRteEditor(
      \Facebook\WebDriver\WebDriverBy::xpath(
        '//textarea[@' . $attribute . '=\'' . $value . '\']/../div[contains(@class, \'mce-tinymce\')]//iframe'
      ),
      $content
    );
  }

  private function fillRteEditor($selector, $content) {
    $this->executeInSelenium(
      function (\Facebook\WebDriver\Remote\RemoteWebDriver $webDriver)
      use ($selector, $content) {
        $webDriver->switchTo()->frame(
          $webDriver->findElement($selector)
        );

        $webDriver->executeScript(
          'arguments[0].innerHTML = "' . addslashes($content) . '"',
          [$webDriver->findElement(\Facebook\WebDriver\WebDriverBy::tagName('body'))]
        );

        $webDriver->switchTo()->defaultContent();
      });
  }

}