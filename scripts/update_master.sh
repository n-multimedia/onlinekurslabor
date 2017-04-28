##!/bin/sh
drush vset maintenance_mode 1
 
drush cc all
 
drush updatedb --yes 
#bug in drush - cc before FR!!
drush cc all
#revert single features
#drush features-revert-all --yes

drush fr nm_section_content_features --yes

drush language-import-translations de ../language/alpha8.po --replace --groups=default



drush vset maintenance_mode 0
