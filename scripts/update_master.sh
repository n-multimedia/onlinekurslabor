##!/bin/sh

#drush vset maintenance_mode 1

drush en userprotect defaultavatar dev_live_warner --yes

drush fr nm_section_content_features nm_section_courses_features nm_general_features --yes


#clear cache
drush cc all

drush image-flush --all

drush updatedb --yes

drush language-import-translations de ../language/alpha3.po --replace --groups=default


#drush vset maintenance_mode 0
