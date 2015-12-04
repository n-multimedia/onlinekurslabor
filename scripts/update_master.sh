##!/bin/sh

#drush vset maintenance_mode 1

drush en userprotect --yes

#clear cache
drush cc all


#drush vset maintenance_mode 0
