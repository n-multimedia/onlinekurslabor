##!/bin/sh
drush vset maintenance_mode 1
 
drush cc all
 
drush updatedb --yes 
#bug in drush - cc before FR!!
drush cc all
#revert single features
drush fr nm_section_content_features section_projects_features --yes
#drush features-revert-all --yes

 


#dis

drush language-import-translations de ../language/alpha9.po --replace --groups=default



drush vset maintenance_mode 0
