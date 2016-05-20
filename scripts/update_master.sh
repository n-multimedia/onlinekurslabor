##!/bin/sh
drush fr  videosafe_features --yes
drush en videosafe --yes
mkdir -p ../files_private/videosafe
chmod -R 0777  ../files_private

drush vset maintenance_mode 1
drush fr nm_general_features --yes
drush fr nm_section_courses_features --yes
drush fr nm_section_content_features --yes
drush fr section_projects_features --yes
drush fr nm_h5p_features --yes 
drush fr  videosafe_features --yes
drush en privatemsg
drush en media_wysiwyg


echo -e  "RewriteEngine on \nRewriteRule ^content/([0-9]+)/videos/(.*)$ /system/files/videosafe/\$2 [R=307,L]\nRewriteRule ^content/([0-9]+)/videosafe/(.*)$ /system/files/videosafe/\$2 [R=301,L]" > sites/default/files/h5p/.htaccess
 
find sites/default/files/h5p -type f -iname "files-*.*" -exec  cp {}  ../files_private/videosafe/  \;


#clear cache
drush cc all
drush updatedb --yes

drush php-eval 'node_access_rebuild();'


drush language-import-translations de ../language/alpha5.po --replace --groups=default


drush vset maintenance_mode 0

