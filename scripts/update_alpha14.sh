#!/usr/bin/env bash
##!/bin/sh
drush vset maintenance_mode 1


#bug in drush - cc before FR!!
drush cc all



#revert single features

drush fr nm_general_features nm_section_courses_features nm_section_content_features nm_h5p_features notification_features --yes
#drush fr nm_section_content_features nm_section_courses_features nm_general_features section_projects_features nm_h5p_features section_courses_clone_features --yes

#import language
drush language-import-translations de ../language/alpha14.po --replace --groups=default

drush updatedb --yes

drush en newmenue_tooltip --y
drush en views_collapse_wrapper --yes

drush vdel h5p_crossoriginRegex 1 --yes

drush cc all

drush vset maintenance_mode 0
