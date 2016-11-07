##!/bin/sh
drush vset maintenance_mode 1

drush en linkit_extension --yes
drush en bootstrap_check --yes
drush en views_php --yes
drush pm-disable bartik --yes
drush pm-disable seven  --yes

drush fr nm_section_content_features nm_general_features nm_h5p_features nm_section_content_features nm_section_courses_features section_courses_clone_features section_projects_features --yes
drush dis oembed_fix  --yes
#clear cache
drush cc all
drush updatedb --yes
drush fr nm_h5p_features nm_stream_features --yes

drush php-eval 'node_access_rebuild();'


drush language-import-translations de ../language/alpha6.po --replace --groups=default


drush vset maintenance_mode 0