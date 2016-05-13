##!/bin/sh
drush en videosafe --yes
mkdir private:
chmod 0777 private\:/

drush vset maintenance_mode 1
drush fr nm_general_features --yes
drush fr nm_section_courses_features --yes
drush fr nm_section_content_features --yes
drush fr section_projects_features --yes
drush fr nm_h5p_features --yes
drush en privatemsg
drush en media_wysiwyg


#clear cache
drush cc all



drush updatedb --yes

drush php-eval 'node_access_rebuild();'


drush language-import-translations de ../language/alpha5.po --replace --groups=default


drush vset maintenance_mode 0

