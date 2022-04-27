#!/bin/bash
#environment needs some infos about pathes - keep line! ("." means "source")
. $( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/get-drush-include-path.sh

drush vset maintenance_mode 1


#bug in drush - cc before FR!!
drush cc all

#revert single features
drush fr  home_features annvid_features nm_section_content_features nm_section_courses_features --yes
#drush fr annvid_features nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features nm_administration --yes

#import language
drush language-import-translations de ../language/alpha19.po --replace --groups=default

drush updatedb --yes

drush cc all

drush vset maintenance_mode 0
