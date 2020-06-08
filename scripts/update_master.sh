#!/usr/bin/env bash
##!/bin/sh
drush vset maintenance_mode 1


#bug in drush - cc before FR!!
drush cc all


#revert single features
drush fr  lehet_ouzo nm_general_features  nm_section_content_features nm_section_courses_features --yes
#drush fr nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features --yes

#import language
drush language-import-translations de ../language/alpha16.po --replace --groups=default

drush en BootstrapCDNToLocal --y
drush updatedb --yes

drush cc all

drush vset maintenance_mode 0
