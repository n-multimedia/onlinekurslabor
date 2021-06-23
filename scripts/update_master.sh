#!/bin/bash
#environment needs some infos about pathes - keep line! ("." means "source")
. $( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/get-drush-include-path.sh

drush vset maintenance_mode 1


rsync -va --remove-source-files    ../files_private/profile sites/default/files/
rsync -va --remove-source-files    ../files_private/avatar_* sites/default/files/profile/
rsync -va --remove-source-files    ../files_private/courses/ sites/default/files/courses_preview

#bug in drush - cc before FR!!
drush cc all

drush en onlinekurslabor_cache --yes

#revert single features
drush fr  nm_section_courses_features nm_section_content_features nm_general_features notification_features nm_h5p_features nm_stream_features videosafe_features annvid_features help_features home_features nm_general_features nm_login_vhb_features  section_courses_clone_features videosafe_features  --yes
#drush fr annvid_features nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features --yes

drush image-flush --all



#import language
drush language-import-translations de ../language/alpha18.po --replace --groups=default

drush updatedb --yes

drush php-eval 'node_access_rebuild();'

drush en og_forum_D7_fix --yes
drush en onlinekurslabor_delete_cascade --yes


drush vset user_password_reset_timeout 172800

drush php-eval "devel_rebuild_node_comment_statistics();"

drush cc all

drush vset maintenance_mode 0
