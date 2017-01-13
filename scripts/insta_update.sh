##!/bin/bash
cd "$(dirname "$0")"
#cronetab needs some infos about pathes
export PATH=$PATH:/usr/local/bin

# zeit seit letztem push
#currdate=`date +%s`
#gitdate=`git log -1 --pretty=format:%ct`
#datediff=`expr $currdate - $gitdate`

#hat sich im github was geandert?
changed_dev=`git remote update && git status -uno | grep "Your branch is behind"` #alternativ git diff origin/dev

if [ "$changed_dev" != "Fetching origin" ];
then 
	#path von drush in userfolder benoetigt
	export PATH=$PATH:~/drush/
	cd ../web/
	#leere log und setze start
	echo "RUNNING UPDATE" > sites/default/files/last_update_log
	git pull &>>  sites/default/files/last_update_log
	sh ../scripts/update_master.sh &>>  sites/default/files/last_update_log
	echo "" >> sites/default/files/last_update_log
	echo "Update completed on:" >> sites/default/files/last_update_log
	date >> sites/default/files/last_update_log
else
	echo "nothing changed."
fi
