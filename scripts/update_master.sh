##!/bin/sh
drush vset maintenance_mode 1
 
drush cc all
 
drush updatedb --yes 
#bug in drush - cc before FR!!
drush cc all
#revert single features
drush fr  nm_general_features nm_login_vhb_features home_features  nm_section_content_features nm_section_courses_features  section_courses_clone_features nm_h5p_features annvid_features nm_section_content_features  nm_stream_features  section_projects_features/  --yes
#drush features-revert-all --yes

 

drush en mediamodule_fix --yes
drush en ckeditor_custom --yes
drush en home_features --yes
drush en section_home --yes
drush en changediscard_warning --yes

drush dis og_field_access --yes

drush en section_profile --yes

drush en bootstrap_check --yes

#dis
drush dis browser_compatibility --yes

drush language-import-translations de ../language/alpha8.po --replace --groups=default



drush vset maintenance_mode 0
