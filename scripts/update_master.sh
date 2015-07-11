##!/bin/sh

#enable modules
drush en section_projects_features --yes

#revert features
drush fr section_projects_features --yes


#clear cache
drush cc all