##!/bin/sh

#enable modules
drush en section_projects_features notification_features email_registration --yes

#revert features
drush fra --yes

drush updatedb


#clear cache
drush cc all