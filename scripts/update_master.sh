##!/bin/sh

#drush vset maintenance_mode 1

drush en h5p_connector_api --yes
drush fr nm_general_features --yes
drush fr nm_section_courses_features --yes

#clear cache
drush cc all


drush updatedb --yes


drush language-import-translations de ../language/alpha4.po --replace --groups=default


#drush vset maintenance_mode 0
