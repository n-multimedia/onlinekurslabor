##!/bin/sh
drush vset maintenance_mode 1

drush fr nm_general_features --yes
drush privatize --yes

drush fr nm_general_features --yes

mkdir -p ../files_private/videosafe
chmod -R 0777  ../files_private

drush en privatemsg --yes
drush en support_form --yes
drush en media_wysiwyg --yes

#videosafe-reihenfolge
drush fr nm_general_features --yes
drush en  videosafe_features --yes
drush fr  videosafe_features --yes
echo   "#verweise auf bilder etc falls in private\nRewriteEngine on\nRewriteCond %{REQUEST_FILENAME} !-f\nRewriteCond %{REQUEST_FILENAME} !videosafe\nRewriteRule ^content/([0-9]+)/(.*)/(.*)$ /system/files/h5p/content/\$1/\$2/\$3 [R=301,L]\n#videosafe immer in private\nRewriteEngine on \nRewriteCond %{REQUEST_URI} videosafe\nRewriteRule ^content/([0-9]+)/videosafe/(.*)$ /system/files/videosafe/\$2 [R=301,L]\n" > sites/default/files/h5p/.htaccess
echo   "RewriteEngine on\nRewriteRule ^videosafe/(.*)$ /system/files/videosafe/\$1 [R=307,L]"  > sites/default/files/h5peditor/.htaccess
#find sites/default/files/h5p -type f -iname "files-*.*" -exec  cp {}  ../files_private/videosafe/  \;
drush en videosafe --yes

drush fr nm_general_features --yes
drush fr nm_section_courses_features --yes
drush fr nm_section_content_features --yes
drush fr section_projects_features --yes
drush fr nm_h5p_features --yes
drush fr  videosafe_features --yes

drush en privatemsg_okl pm_email_notify privatemsg_filter privatemsg_realname privatemsg_rules --yes


#clear cache
drush cc all
drush updatedb --yes

drush php-eval 'node_access_rebuild();'


drush language-import-translations de ../language/alpha5.po --replace --groups=default


drush vset maintenance_mode 0

