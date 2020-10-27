#!/bin/bash
cd "$(dirname "$0")"
#environment needs some infos about pathes - keep line! ("." means "source")
. $( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/get-drush-include-path.sh


# zeit seit letztem push
#currdate=`date +%s`
#gitdate=`git log -1 --pretty=format:%ct`
#datediff=`expr $currdate - $gitdate`

#hat sich im github was geandert?
changed_dev=`git remote update && git status -uno | grep "Your branch is behind"` #alternativ git diff origin/dev

if [ "$changed_dev" != "Fetching origin" ];
then 
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
