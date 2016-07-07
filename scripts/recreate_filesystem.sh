##!/bin/sh
MYSQL_DUMP="../private/dump-28-6-userencrypted.sql"
LOG_PATH="../private/update_log"

if [ $USER != "root" ];
then
	echo "must be run as root"
	exit
fi 

echo "using Database-Dump $MYSQL_DUMP and log-pth $LOG_PATH"
echo "\033[0;31m THIS WILL clear your db and invoke update_master"
echo "\033[0mYou have 10 seconds to abort."
sleep 10s

rm -rf private\:/
rm -rf ../files_private/*

sleep 10s
rsync -au --progress onlinekurslabor@onlinekurslabor.phil.uni-augsburg.de:/var/www/vhosts/onlinekurslabor.phil.uni-augsburg.de/web/web/sites/default/files/*  ./sites/default/files/

chmod -R 0777 ./sites/default/files/ 
drush sql-drop --yes
drush sql-cli < $MYSQL_DUMP
drush cc all

sh ../scripts/update_master.sh 2>&1 | tee $LOG_PATH
chmod -R 0777 ../files_private/
rm -rf private\:/
drush cc all
echo  '\007'
sleep 1s
echo  '\007'