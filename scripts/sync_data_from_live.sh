##!/bin/bash


#
# sync_data_from_live
#
# usage:
#
#	sync_data_from_live files | db | all
# fetches data db / files as chosen from live-system
#
# you need to define(NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT, "YOUR_PASSWORD") in settings.php
# this will be used as the password for any user-account on login.
#
# needs to have SSH-Connection with RSA configured. See 
# README in readme-sync-from-live
#
#
# This script was originally written by Bernhard Strehl
#
# Permission is granted to use, redistribute and 
# make derived works without restriction.
#

#use printf instead of echo -e for escape-sequences
printf  "\033[0;31m THIS WILL delete DATA like db and files on local system and replace with data from live"
printf "\n\033[0mYou have 10 seconds to abort."
printf "\n"
sleep 10s

# hole master-password aus drupal-config
LOGIN_MASTERPASSWORD=`drush php-eval "echo NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT;"`
#SYSTEM_IDENT fuer die email-adresse
calculated_system_identifier=`drush php-eval 'echo _dev_live_warner_get_system_name()'`  >/dev/null 2>/dev/null
SYSTEM_IDENT="${calculated_system_identifier:-NO_IDENT_FOUND}"

PULL_FILES=false
PULL_DB=false


if [ "$LOGIN_MASTERPASSWORD" = "NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT"  ]   ;
then
 printf "\n\nConstant NM_DEVELOP_LOGIN_MASTERPASSWORD_DEFAULT not defined in settings.php! Exit!"
 exit 0;
fi


#option: file-sync
if [ "$1" = "all"  ]  ||  [ "$1" = "files" ] ;
then
 PULL_FILES=true
fi

#option: db-sync
if [ "$1" = "all"  ]  ||  [ "$1" = "db" ] ;
then
 PULL_DB=true
fi

#check:options
if [ "$PULL_DB" = false  ]  &&  [ "$PULL_FILES" = false ] ;
then
echo  "usage: sync_data_from_live files | db | all . Exit!"
exit;
fi;


printf "\033[0;31m Will now pull files: $PULL_FILES ; pull db: $PULL_DB"
printf "\033[0m"
echo ""
echo "You will be asked for a RSA-Key. Ask your collegue if you don't know it."
sleep 5s

#starte ssh-agent um pw-abfrage nur 1x zu haben
eval `ssh-agent -s`
ssh-add ~/.ssh/id_rsa || ( echo "SSH with RSA not configured. Read README! Exit." && exit; )


if [  "$PULL_DB" = true  ]; 
then
printf "\n\nSYNCING DATABASE\n\n"
drush sql-sync @okl.live @self  --create-db --sanitize --sanitize-email=%mail+$SYSTEM_IDENT@div.onlinekurslabor.de --sanitize-password=$LOGIN_MASTERPASSWORD 

fi



if [  "$PULL_FILES" = true  ]; 
then
printf "\n\nSYNCING FILES\n\n"
drush rsync -v @okl.live:%files @self:%files
drush rsync -v @okl.live:%private  @self:%private 
fi

drush cc all
drush en okl_testing  --yes
printf "\n\nINVOKING UPDATESCRIPT\n\n"
sleep 3s
sh ../scripts/update_master.sh
printf '\007'
sleep 1s
printf '\007'


if [  "$PULL_DB" = true  ]; 
then

sleep 1s
printf "\n\nWill now create a dummy course. Confirm by hitting enter or CMD+C to cancel.\n"
read null

cd ../okl-testing 
bash codecept-run-prepare_test.sh
fi

exit;
