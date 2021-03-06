#!/bin/bash
#environment needs some infos about pathes - keep line!
. $( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/get-drush-include-path.sh


drush vset maintenance_mode 1


#bug in drush - cc before FR!!
drush cc all

#revert single features
drush fr    nm_section_content_features nm_general_features nm_section_courses_features notification_features nm_administration --yes
#drush fr annvid_features nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features --yes

#import language
drush language-import-translations de ../language/alpha17.po --replace --groups=default

drush updatedb --yes

drush cc all

drush vset maintenance_mode 0
drush vset maintenance_mode 1

drush @none dl utf8mb4_convert-7.x --y
drush cc drush
drush utf8mb4-convert-databases --y

echo "Now fix your config. Enter drush vset maintenance_mode 0 afterwards."