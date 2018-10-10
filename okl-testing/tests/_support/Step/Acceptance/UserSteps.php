<?php

namespace Step\Acceptance;

use Page\Acceptance\LoginPage;
use \Codeception\Step\Argument\PasswordArgument;

class UserSteps extends \AcceptanceTester {

  /**
   * @param $userName
   * @param $securedPassword (Obj of class  \Codeception\Step\Argument\PasswordArgument)
   */
  public function login($userName,  \Codeception\Step\Argument\PasswordArgument $securedPassword = null, $saveSession = TRUE) {
    $I = $this;

    //$I->amOnPage("/user/logout");

    //do not log in, if session is already active
    if ($I->loadSessionSnapshot('login') && $saveSession) {
      return;
    }
    
    //fallback: use default password
    if(is_null($securedPassword))
    {
        $securedPassword = new PasswordArgument(NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT);
    }

    $I->amOnPage(LoginPage::$URL);

    $I->fillField('name', $userName);
    $I->fillField('pass', $securedPassword);

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