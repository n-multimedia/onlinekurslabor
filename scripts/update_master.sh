#!/usr/bin/env bash
##!/bin/sh
drush vset maintenance_mode 1
 

#bug in drush - cc before FR!!
drush cc all

drush en legal --yes
drush en nm_administration --yes



#revert single features

#drush fr nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features --yes
drush fr nm_section_courses_features nm_administration  nm_section_content_features --yes
drush cc all

drush en section_administration --yes
drush en  og_field_fix --yes

#revert single features
 
drush language-import-translations de ../language/alpha10.po --replace --groups=default

drush updatedb --yes

drush cc all

drush vset maintenance_mode 0
