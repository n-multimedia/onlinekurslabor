#!/usr/bin/env bash
##!/bin/sh
drush vset maintenance_mode 1
 

#bug in drush - cc before FR!!
drush cc all
 
drush en nm_administration --yes
 
#revert single features
drush fr nm_section_content_features nm_general_features section_projects_features --yes
#drush features-revert-all --yes
 

#revert single features
drush fr nm_administration --yes

drush language-import-translations de ../language/alpha9.po --replace --groups=default

drush updatedb --yes

drush cc all

drush vset maintenance_mode 0
