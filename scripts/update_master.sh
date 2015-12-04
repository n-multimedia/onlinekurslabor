##!/bin/sh

#drush vset maintenance_mode 1

drush en userprotect defaultavatar --yes

drush fr nm_section_courses_features nm_general_features --yes


#clear cache
drush cc all

drush image-flush

drush updatedb --yes

drush language-import de ../language/alpha3.po --replace


#drush vset maintenance_mode 0
