#!/bin/bash
#environment needs some infos about pathes - keep line! ("." means "source")
. $( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/get-drush-include-path.sh

drush vset maintenance_mode 1



drush cc all
drush en eol_configuration_feature --yes

#bug in drush - cc before FR!!
drush cc all

#revert single features
drush fr  home_features annvid_features nm_section_content_features nm_section_courses_features nm_general_features notification_features eol_configuration_feature --yes
#drush fr annvid_features nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features nm_administration nm_uuid_features --yes

#import language
drush language-import-translations de ../language/alpha19.po --replace --groups=default

#diese wurden die letzten ACHT Jahre nicht aktualisiert - sind überholt und unsicher :-[ 
rm sites/default/files/.htaccess
rm ../files_private/.htaccess
drush php-eval "file_ensure_htaccess();"
echo "recreated files-.htaccess-file. Plz check directories."

drush updatedb --yes

drush fr eol_configuration_feature --yes

drush cc all

drush vset maintenance_mode 0
