##!/bin/sh

#enable modules
drush en section_projects_features notification_features --yes

#revert features
drush fr section_projects_features notification_features --yes

drush updatedb


#clear cache
drush cc all