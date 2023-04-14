##!/bin/bash
###########  ABOUT  ####################
#
#   statt
#        codecept run acceptance 001_GeneralCest --steps
#   schreiben wir nun
#
#        ./codecept-run-tests.sh 001_GeneralCest --steps
#
#   Die Funktionsweise und parameter sind  die gleichen wie bei "codecept run acceptance ..."
#
#########################################

function getlocalTestSystemName {
                 local tmp=$(pwd)
                 # remove /var/www... AND cut everything including and after ".div.okl...
                 # result is dev1,dev2 etc
                 [[ $tmp =~  .*/(.*).div.onlinekurslabor.de ]] && local curr_testdir=${BASH_REMATCH[1]}
                 # so ne Art return
                 echo "$curr_testdir"
                }  

#aktuelle DIR in ssh
current_directory=$(pwd)
#gehe zu Liegeort dieses Scripts
cd "$(dirname "$0")"

 

cd "$current_directory"

# extrahiere Übergabeparameter
commandline_arguments=""
for var in "$@"
do
    commandline_arguments="$commandline_arguments $var"
done

 

current_testsystem=$(getlocalTestSystemName)

## prepare test

# truncate output dir
rm -rf tests/_output/*


#hier haben wir den fertigen Befehl. Lauf, kleiner Padawan!
/opt/plesk/php/8.1/bin/php vendor/bin/codecept run acceptance $commandline_arguments --env firefox-env,$current_testsystem
# achtung, php 8.1 is fix eincodiert

echo "<h1>Achtung Bug: die einzeln gelisteten Tests enthalten alle das selbe Sample mit den zuletzt ausgeführten Daten. Da stimmt was mitm Recorder nicht...</h1>" >> tests/_output/records.html

#more infos in blue..
echo -e " \e[104mInformationen ueber den Testlauf koennen auch ueber ~URL/okl-testing/ abgerufen werden. \e[0m"