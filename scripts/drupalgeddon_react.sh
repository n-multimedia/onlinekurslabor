#!/bin/bash

# 
##############
#   HOWTO
##############
#
# a) Script testen aus dem script-directory: /web/scripts$ bash drupalgeddon_react.sh
# b) cronjob einrichten: 
#     b1) 0 */6 * * * bash --SITENAME--/web/scripts/drupalgeddon_react.sh	
#     b2) mit Mailbenachrichtigung:0 */6 * * * bash --SITENAME--/web/scripts/drupalgeddon_react.sh   2>&1 > /dev/null  |  bash --SITENAME--/web/scripts/mail_if_output.sh RECIPIENT@HOST.COM,RECIPIENT@HOSTER.COM
# c1) gibt es ein security-drupal-Release, wird die Webseite komplett abgeschaltet.
# c2) bei Verwendung von b2) erhalten die Empfänger auch eine E-Mail.
# 


cd "$(dirname "$0")"
#cronetab needs some infos about pathes
export PATH=$PATH:/usr/local/bin


#path von drush in userfolder benoetigt
export PATH=$PATH:~/drush/:~/.composer/vendor/bin/
cd ../web/
drush rf  2> /dev/null   ||  ((>&2 printf "DRUSH COMMAND NOT FOUND\n\n") && exit 1);# pm-refresh OR warning if drush not found

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
../scripts/drupalgeddon_activate_maintenance.sh
 
#write to stdErr. stdErr will be sent via email.
 (>&2 printf "$bash_user WAS SHUT DOWN!\n\n")
 (>&2 printf "Pfad: $PWD \nNotice: $CHANGED_DRUP\n")
 
 exit 1;
fi

