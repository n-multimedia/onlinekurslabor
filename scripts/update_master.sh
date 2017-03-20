##!/bin/sh
drush vset maintenance_mode 1


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
