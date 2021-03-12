<?php

namespace Step\Acceptance;
use \Codeception\Util\Fixtures;
use Page\Acceptance\LoginPage;
use Page\Acceptance\LogoutPage;
use \Codeception\Step\Argument\PasswordArgument;
use Codeception\Util\Locator;

class UserSteps extends \AcceptanceTester {

  /**
   * @param $userName
   * @param $securedPassword (Obj of class  \Codeception\Step\Argument\PasswordArgument)
   */
  public function login($userName,  \Codeception\Step\Argument\PasswordArgument $securedPassword = null, $saveSession = TRUE, $force_relogin = false) {
    $I = $this;

    //boah hässlich, aber sonst scheitert die $drupalUser->login- Prüfung später.
    entity_get_controller('user')->resetCache();
    $drupalUser = user_load_by_mail($userName)?: user_load_by_name($userName); 
    
    //$I->amOnPage("/user/logout");

    //do not log in, if session is already active
    if ($saveSession && ! $force_relogin) {
        if($I->loadSessionSnapshot('login'))
        {
            return;
        }
      
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
    Fixtures::add('LASTLOGIN_USERNAME', $userName);
    
    //noch nie eingeloggt
    if(!$drupalUser->login)
    {
        $I->click(LoginPage::$acceptLegalTermsCheckbox);
        $I->click(LoginPage::$acceptLegalButton);
    }

    if($saveSession) {
      $I->saveSessionSnapshot('login');
    }


  }
  
  /**
   * Logout any user
   */
  public function logout()
  {
     $I = $this;
     $I->amOnPage(LogoutPage::$URL);
     $I->see(LoginPage::$loginMenuButton);
     $I->deleteSessionSnapshot('login');
  }
  
  /**
   * checkOption only accepts IDs which is not enough. Provide  desired value
   * @param type $option_identifier
   * @param type $value
   */
  public function checkOptionByValue($value)
  {
      $I = $this;
      $obj = Locator::find('input', ['value' => $value]);
      $I->click($obj);
  }
  
  /**
   * click on a <$html_tag> in which a text is included
   * mainly used for a firefox-bug: https://sqa.stackexchange.com/questions/32697/webdriver-firefox-element-could-not-be-scrolled-into-view
   * @param String $html_tag
   * @param type $text
   */
  public function clickTagContaining($html_tag, $text) {
    $I = $this;

    $obj = Locator::contains($html_tag, $text);
    $I->click($obj);
  }

  /**
   * if links cannot be clicked (BUG: "Element <option> could not be scrolled into view"), use this function
   * 
   * @param type $link_text the linktext like "Impressum" or "Login". May be contained in a subelement like <span>
   */
  public function clickLinkBugProof($link_text) {
    $I = $this;
    $this->executeJS("href=jQuery('a:contains(" . addslashes($link_text) . ")').attr('href'); document.location=href;");
    $I->wait(2);
  }

  /**
   * Fill a ckeditor. The $element_id is the string included in '#cke_' . $element_id . ' .cke_wysiwyg_frame';
   * @param type $element_id
   * @param type $content
   */
  public function fillCkEditorById($element_id, $content) {

    $css_id = '#cke_' . $element_id . ' .cke_wysiwyg_frame';
    #$this->clickWithLeftButton($css_id);
    $this->fillRteEditor(
      \Facebook\WebDriver\WebDriverBy::cssSelector(
        $css_id
      ),
      $content
    );
  }

  /**
   * fill ck-editor. For the element_name check the dome for a HIDDEN textarea just before the ckeditor.
   * @param type $element_name name of this hidden textarea
   * @param type $content
   */
  public function fillCkEditorByName($element_name, $content) {
    $css_selector = 'textarea[name="' . $element_name . '"] + .cke .cke_wysiwyg_frame';
    $this->scrollTo($css_selector);
    $this->clickWithLeftButton($css_selector);
    $this->fillRteEditor(
      \Facebook\WebDriver\WebDriverBy::cssSelector(
        'textarea[name="' . $element_name . '"] + .cke .cke_wysiwyg_frame'
      ),
      $content
    );
  }
  /**
   * wrapper für die Extra-Buttons in CK, bspw für footnotes oder h5p
   * @param type $button_name e.g. "footnotes", "h5p_button"..
   * @param type $title of 
   */
  public function fillCkExtraFeature($button_name, $title)
  {      $this->comment("don't use. Autocomplete is not triggered :( ");
      $this->executeJS("jQuery('.cke_button__".$button_name."_icon').click();");
      $this->wait(2);
      //das geht och nich $this->fillField('.cke_dialog_ui_input_text', $title);
      //löse via js-konstrukt..
      $this->executeJS('jQuery("input.cke_dialog_ui_input_text").focus().val("'.$title.'").focus(); ');
      $this->wait(2);
      //trigger enter on autocomplete
     # $this->executeJS(' var e = jQuery.Event("keyup");e.keyCode= 13; jQuery("input.cke_dialog_ui_input_text").trigger(e);');
     
      #$this->wait(5);
      $this->click($title);
      $this->click("OK");
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
  
  
  /**
   * Helperfunktion zur Nutzung des Coursemenus
   * @param String $open_region z.B. "Teinehmende"
   * @param type $click_option z.B. "Teilnehmde verwalten"
   * @throws Exception
   */
  public function useCourseMenu($open_region = false , $click_option= false)
  {
    $this->click( '#instructor_tools_toggle_button' );
    $this->wait(1);
    //add context
    if($open_region)
    {
        $this->click($open_region,'#mobile_instructors_tools-container' );
        $this->wait(1);
    }
    if($click_option)
    {
         $this->click($click_option,'#mobile_instructors_tools-container' );
    }
    
  }

}