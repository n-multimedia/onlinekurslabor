##!/bin/bash

# 
##############
#   HOWTO
##############
#
# a) Script testen aus dem script-directory: /web/scripts$ bash drupalgeddon_react.sh
# b) cronjob einrichten: 
#     0 */6 * * * bash --SITENAME--/web/scripts/drupalgeddon_react.sh	
# 	b1) cronjob konfigurieren: Benachrichtigungen => Nur Fehler => E-Mail eingeben
# c) gibt es ein security-drupal-Release, wird die Webseite komplett abgeschaltet.
# 
# 


cd "$(dirname "$0")"
#cronetab needs some infos about pathes
export PATH=$PATH:/usr/local/bin



#path von drush in userfolder benoetigt
export PATH=$PATH:~/drush/
cd ../web/
drush rf  2> /dev/null    # pm-refresh

#StdErr wird nach null umgeleitet. Darin enthalten sind die warnings über "missing plugins"
CHANGED_DRUP=`drush up drupal --no  2> /dev/null  | grep "SECURITY UPDATE available"`


if [ "$CHANGED_DRUP" = ""  ]   ;
then
# printf "\n\nThats good! No code-change\n"
 exit 0;
else
 #"oh-oh."

 bash_user=$(whoami)
 #ueberschreibe htaccess
 printf "ErrorDocument 403 \"Diese Seite ist aufgrund eines dringenden Updates voruebergehend ausser Betrieb!<br>Das Medienlabor.\" \n order deny,allow \n deny from all\n" > .htaccess
 
 
 #write to stdErr. Crone will send stdErr via email.
 (>&2 printf "$bash_user WAS SHUT DOWN!\n\n")
 (>&2 printf "\n\nPfad: $PWD \n\nNotice: $CHANGED_DRUP")
 
 exit 1;
fi

