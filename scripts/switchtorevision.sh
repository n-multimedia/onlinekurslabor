##!/bin/sh
echo "Usage:  sh ../scripts/switchtorevision.sh REVISION-ID"
echo ""
if [ ! $1 ];
then
	echo "Will now switch to latest GIT-Revision"
else 
	echo "Will now switch your platform to GIT-Revision $1"
fi 
echo "\033[0;31m THIS WILL REVERT ALL YOUR CHANGES"
echo "\033[0mYou have 10 seconds to abort."
sleep 10s
if [ ! $1 ];
then
	git checkout dev
	git pull
else 
	git checkout $1
fi 
sleep 5s

drush fr  nm_general_features nm_section_content_features nm_section_courses_features videosafe_features  --yes
drush cc all
drush php-eval 'node_access_rebuild();'
echo  '\007'

echo  '\007'
echo  '\007'
echo  '\007'
echo  '\007'
echo  '\007'
echo  '\007'
