##!/bin/sh
drush vset maintenance_mode 1

wget -O sites/default/files/h5p/libraries/H5PEditor.InteractiveVideo-1.15/Scripts/interactive-video-editor.js https://trello-attachments.s3.amazonaws.com/559fa59ca3cc5213d6d8b07d/58e215a8bf2256697570d093/631743669be449f18d955a4909fc7220/interactive-video-editor.js
#clear cache
drush cc all

drush dis overlay --yes

drush updatedb --yes
drush en browser_compatibility --yes
drush en no_mailer --yes
drush en annvid --yes

#bug in drush - cc before FR!!
drush cc all
drush features-revert-all --yes


drush language-import-translations de ../language/alpha7.po --replace --groups=default


drush vset maintenance_mode 0
