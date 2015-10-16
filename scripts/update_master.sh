##!/bin/sh


drush dl h5p-7.x-1.0-beta5 --yes

#enable modules
drush en section_projects_features notification_features email_registration htmlmail nm_activity_stream --yes

#revert features
drush fra --yes

drush cc all

drush updatedb --yes

#rebuild node access
drush php-eval 'node_access_rebuild();'

#clear cache
drush cc all
