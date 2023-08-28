<?php

/**
 * @file
 * OKL CONFIG FILE
 * 
 * 
 * INSTEAD OF HACKING HTMLPURIFIER: USE THIS FILE
 * SEE SAMPLE.php
 */

/**
 * Allow the custom html-Tag "<fn>" (footnote) in okl
 * 
 * Accepts an HTMLPurifier_Config configuration object and configures it.
 *
 * @param $config
 *    Instance of HTMLPurifier_Config to modify. See
 *        http://htmlpurifier.org/doxygen/html/classHTMLPurifier__Config.html
 *    for a full API.
 *
 * @note
 *    No return value is needed, as PHP objects are passed by reference.
 */
function htmlpurifier_config_filtered_html($config) {
  $config->set('HTML.DefinitionID', 'okl-definition');
  $config->set('HTML.DefinitionRev', 1);
  $def = $config->getHTMLDefinition(true);
  $def->addElement(
    'fn', // name
    'Inline', // content set
    'Inline', // allowed children
    'Common', // attribute collection
    array(// attributes
      'value' => 'jumpvalue'
    )
  );
  $def->addAttribute('fn', 'value', 'CDATA'); //strange: Must set attribute "value" twice.
}
