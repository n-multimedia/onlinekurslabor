##!/bin/sh

#enable modules
drush en section_projects_features notification_features email_registration htmlmail nm_activity_stream --yes

#revert features
drush fra --yes

drush updatedb


#rebuild node access
drush php-eval 'node_access_rebuild();'

#clear cache
drush cc all