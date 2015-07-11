<?php
/**
 * Wiki Plugins
 *
 * @file
 *  Plugins for various wiki links, micro-steps toward evolving a Freelinking Interwiki module.
 *  Currently offers: Wikipedia, Wikiquote, Wiktionary, Wikisource, Wikibooks, Wikinews
 */

/**
 * Allows for a link like [[wp:Matthew Good]] to be expanded to
 * en.wikipedia.org/wiki/Matthew_Good
 */
$freelinking['wikipedia'] = array(
  'indicator' => '/w(iki|ikipedia|p)?$/',
  'translate' => array(' ' => '_'),
  'replacement' => 'http://' . variable_get('freelinking_wikipedia_languagecode', language_default('language')) . '.wikipedia.org/wiki/%1',
  'tip' => t('Link to a wikipedia page.'),
);

$freelinking['wikiquote'] = array(
  'indicator' => '/w(ikiquote|q)/',
  'translate' => array(' ' => '_'),
  'replacement' => 'http://' . variable_get('freelinking_wikipedia_languagecode', language_default('language')) . '.wikiquote.org/wiki/%1',
  'tip' => t('Link to a wikiquote page.'),
);

$freelinking['wiktionary'] = array(
  'indicator' => '/w(iktionary|t)/',
  'translate' => array(' ' => '_'),
  'replacement' => 'http://' . variable_get('freelinking_wikipedia_languagecode', language_default('language')) . '.wiktionary.org/wiki/%1',
  'tip' => t('Link to a wiktionary page.'),
);

$freelinking['wikinews'] = array(
  'indicator' => '/w(ikinews|\n)/',
  'translate' => array(' ' => '_'),
  'replacement' => 'http://' . variable_get('freelinking_wikipedia_languagecode', language_default('language')) . '.wikinews.org/wiki/%1',
  'tip' => t('Link to a wikinews page.'),
);

$freelinking['wikisource'] = array(
  'indicator' => '/^w(ikisource|s)/',
  'translate' => array(' ' => '_'),
  'replacement' => 'http://' . variable_get('freelinking_wikipedia_languagecode', language_default('language')) . '.wikisource.org/wiki/%1',
  'tip' => t('Link to a wikisource page.'),
);

$freelinking['wikibooks'] = array(
  'indicator' => '/w(ikibooks|b)/',
  'translate' => array(' ' => '_'),
  'replacement' => 'http://' . variable_get('freelinking_wikipedia_languagecode', language_default('language')) . '.wikibooks.org/wiki/%1',
  'tip' => t('Link to a wikibooks page.'),
);


/**
 * Settings form for wikipedia plugin
 *
 * @return
 *   array with form configuration
 */
function freelinking_wikipedia_settings() {
  $form['freelinking_wikipedia_languagecode'] = array(
    '#title' => t('Language code'),
    '#type' => 'textfield',
    '#default_value' => variable_get(
      'freelinking_wikipedia_languagecode', language_default('language')
    ),
    '#description' => t('Enter the two-character language code to use for wikipedia links'),
    '#size' => 2,
    '#maxlength' => 2,
    '#required' => TRUE,
  );
  return $form;
} // endfunction freelinking_wikipedia_settings

// vim:tw=300 nowrap syn=php
