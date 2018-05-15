##!/bin/bash

# 
##############
#   HOWTO
##############
#
# a) default.emergency_mail_contact.sh kopieren nach emergency_mail_contact.sh und anpassen
# b) Script testen aus dem script-directory: /web/scripts$ bash drupalgeddon_react.sh
# c) cronjob einrichten: 
#     0 */6 * * * bash --SITENAME--/web/scripts/drupalgeddon_react.sh	
# d) gibt es ein security-drupal-Release, wird die Webseite komplett abgeschaltet.
# 
# 


cd "$(dirname "$0")"
#cronetab needs some infos about pathes
export PATH=$PATH:/usr/local/bin

#load emergency mail adresses from file. Execution will stop if file missing
. "emergency_mail_contact.sh"


#path von drush in userfolder benoetigt
export PATH=$PATH:~/drush/
cd ../web/

CHANGED_DRUP=`drush up drupal --no | grep "SECURITY UPDATE available"`


if [ "$CHANGED_DRUP" = ""  ]   ;
then
 printf "\n\nThats good! No code-change\n"
 exit 0;
else
 #"oh-oh."

 sitename=`drush vget site_name`
 bash_user=$(whoami)
 #ueberschreibe htaccess
 printf "ErrorDocument 403 \"$sitename voruebergehend ausser Betrieb!<br>Das Medienlabor.\" \n order deny,allow \n deny from all\n" > .htaccess
 # versende e-mail
 # Parameter $EMERGENCY_MAIL kommt aus emergency_mail_contact.sh
 printf  "Aktueller Benutzername: $bash_user \n\nPfad: $PWD \n\nNotice: $CHANGED_DRUP" | mail -s "$sitename abgeschaltet" "$EMERGENCY_MAIL"
 printf "\n\n\n\n$sitename was shut down!\n\n"
fi

