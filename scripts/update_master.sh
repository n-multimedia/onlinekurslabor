##!/bin/sh
drush vset maintenance_mode 1


drush fr nm_section_content_features --yes

#clear cache
drush cc all
drush updatedb --yes


drush language-import-translations de ../language/alpha6.po --replace --groups=default


drush vset maintenance_mode 0
