##!/bin/bash
#aktuelle DIR in ssh
current_directory=$(pwd)
//gehe zu Liegeort dieses Scripts
cd "$(dirname "$0")"
#cronetab needs some infos about pathes
export PATH=$PATH:/usr/local/bin

cd ../web
drush fd 

cd "$current_directory"
ls
