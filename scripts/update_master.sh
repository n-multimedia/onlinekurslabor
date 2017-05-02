##!/bin/sh
drush vset maintenance_mode 1
 
drush cc all
 
drush updatedb --yes 
#bug in drush - cc before FR!!
drush cc all
#revert single features
drush fr  nm_general_features nm_login_vhb_features  nm_section_content_features nm_section_courses_features  section_courses_clone_features --yes
#drush features-revert-all --yes


drush en mediamodule_fix --yes

drush language-import-translations de ../language/alpha8.po --replace --groups=default



drush vset maintenance_mode 0
