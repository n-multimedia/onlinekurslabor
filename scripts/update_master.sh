##!/bin/sh
drush vset maintenance_mode 1
 
drush cc all

drush updatedb --yes
#bug in drush - cc before FR!!
drush cc all
#revert single features


drush en nm_administration --yes

#drush features-revert-all --yes


drush fr nm_administration --yes


#dis

drush language-import-translations de ../language/alpha9.po --replace --groups=default

drush cc all

drush vset maintenance_mode 0
