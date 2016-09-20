##!/bin/sh
drush vset maintenance_mode 1

drush en linkit_extension --yes
drush en bootstrap_check --yes

drush fr nm_section_content_features nm_general_features nm_h5p_features nm_section_content_features nm_section_courses_features section_courses_clone_features section_projects_features --yes
drush dis oembed_fix  --yes
#clear cache
drush cc all
drush updatedb --yes


drush language-import-translations de ../language/alpha6.po --replace --groups=default


drush vset maintenance_mode 0
