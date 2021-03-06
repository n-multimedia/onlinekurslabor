#!/bin/bash
#environment needs some infos about pathes - keep line! ("." means "source")
. $( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/get-drush-include-path.sh

drush vset maintenance_mode 1


#bug in drush - cc before FR!!
drush cc all

#revert single features
drush fr  nm_section_courses_features nm_section_content_features nm_general_features notification_features nm_h5p_features nm_stream_features videosafe_features annvid_features help_features home_features nm_general_features nm_login_vhb_features  section_courses_clone_features videosafe_features  --yes
#drush fr annvid_features nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features --yes

drush php-eval 'node_access_rebuild();'

#import language
drush language-import-translations de ../language/alpha18.po --replace --groups=default

drush updatedb --yes

drush en og_forum_D7_fix --yes 

drush cc all

drush vset maintenance_mode 0
