##!/bin/sh
drush vset maintenance_mode 1


#clear cache
drush cc all

drush dis overlay --yes

drush updatedb --yes
drush en browser_compatibility --yes
#bug in drush - cc before FR!!
drush cc all
drush fr  videosafe_features  nm_section_courses_features  section_projects_features nm_h5p_features annvid_features --yes


drush language-import-translations de ../language/alpha7.po --replace --groups=default


drush vset maintenance_mode 0
