##!/bin/sh

#drush vset maintenance_mode 1
drush en h5p_connector_api --yes
drush en h5p_text_annotations --yes
drush fr nm_general_features --yes
drush fr nm_section_courses_features --yes
drush fr nm_section_content_features --yes
drush fr nm_section_projects_features --yes
drush fr nm_h5p_features --yes


drush php-eval 'node_access_rebuild();'

#clear cache
drush cc all


drush updatedb --yes


drush language-import-translations de ../language/alpha4.po --replace --groups=default


#drush vset maintenance_mode 0
