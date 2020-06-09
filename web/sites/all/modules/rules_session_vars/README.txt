
-- SUMMARY --

This rules_session_vars module is a simple module that allows to write/read custom
values to/from $_SESSION array. Also provides a Rules Condition to check if some
value is already in $_SESSION.

For a full description of the module, visit the project page:
  http://www.drupal.org/project/rules_session_vars

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/rules_session_vars


-- REQUIREMENTS --

  Rules module (of course)

-- INSTALLATION --

  Install as usual, see 
  http://drupal.org/documentation/install/modules-themes/modules-7
  for further information.

-- Configuration --

  This module provides three rule actions and one rule condition.
  Use them as seems appropriate.

  Actions:
    * Load value from $_SESSION
    * Remove value from $_SESSION
    * Store value to $_SESSION
  Condition:
    * $_SESSION key exists

-- CONTACT --

Originally inspired by ioskevich's sandbox project.

Current maintainer:
  Lucas Hedding (heddn) - http://drupal.org/user/1463982
