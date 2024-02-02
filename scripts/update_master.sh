#!/bin/bash
#environment needs some infos about pathes - keep line! ("." means "source")
. $( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/get-drush-include-path.sh

drush vset maintenance_mode 1



drush cc all
drush en eol_configuration_feature --yes
drush en d7security_client  --yes

#bug in drush - cc before FR!!
drush cc all

#revert single features
drush fr   annvid_features environment_indicator_feature help_features home_features nm_general_features nm_h5p_features nm_login_vhb_features nm_section_content_features nm_section_courses_features nm_stream_features notification_features section_courses_clone_features section_projects_features videosafe_features --yes
#drush fr annvid_features nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features nm_administration nm_uuid_features --yes

#import language
drush language-import-translations de ../language/alpha19.po --replace --groups=default

#diese wurden die letzten ACHT Jahre nicht aktualisiert - sind überholt und unsicher :-[ 
rm sites/default/files/.htaccess
rm ../files_private/.htaccess
drush php-eval "file_ensure_htaccess();"
echo "recreated files-.htaccess-file. Plz check directories."
sleep 5 

drush dis dblog --y
drush en fast_dblog --y
drush en htmlpurifier_check --y

drush vset --exact fast_dblog_row_limit 10000
drush vset --exact fast_dblog_buffered 1
drush vset --exact fast_dblog_403_404 1
#complex types
php -r "print json_encode(array('0','1','2','3','4','5','6','7'));"  | drush vset --format=json fast_dblog_severity_levels_cron -
php -r "print json_encode(array('0','1','2','3','4','5','6','7'));"  | drush vset --format=json fast_dblog_severity_levels_anonymous -
php -r "print json_encode(array('0','1','2','3'));"  | drush vset --format=json fast_dblog_severity_levels_authenticated -


drush updatedb --yes

drush fr eol_configuration_feature --yes

drush cc all

drush vset maintenance_mode 0
