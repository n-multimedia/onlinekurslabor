##!/bin/bash
###########  ABOUT  ####################
#
#   Es gibt nun einen speziellen Mode für preparecest. 
#   Dieser wird hier aktiviert und dann preparecest ausgeführt
#
#########################################
 
#aktuelle DIR in ssh
current_directory=$(pwd)
#gehe zu Liegeort dieses Scripts
cd "$(dirname "$0")"
#cronetab needs some infos about pathes
export PATH=$PATH:/usr/local/bin
 

cd "$current_directory"
cd ../web
drush php-eval "_okl_testing_start_prepare_cest();"
cd "$current_directory"

./codecept-run-tests.sh 000_PrepareCest --steps