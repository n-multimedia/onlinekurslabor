##!/bin/bash
#aktuelle DIR in ssh
current_directory=$(pwd)
# gehe zu Liegeort dieses Scripts
cd "$(dirname "$0")"


cd "$current_directory"




## .ymls existieren, verzeichnis /vendor nicht - installiere dependencies neu
if [ ! -d ./vendor/ ]; then
    echo -e "\n\n\n##################################\nEinrichtung Autotests\n##################################\n"
    sleep 2
    echo -e "Ich installiere nun die Dependencies\n\n"
    sleep 2
    composer install

else # ymls existieren, vendor-verzeichnis auch. Dann mach ich ein Update

    echo -e "##################################\nUpdate Autotests\n##################################\n"

    echo -e "Ich aktualisiere in 10 Sekunden die Dependencies\n\n"
    sleep 10

    composer update

fi



echo -e "Making Symlinks..."

rm vendor/bin/phantomjs
#ln -s ../jakoch/phantomjs/bin/phantomjs vendor/bin/phantomjs

echo "todo: add binary vendor/bin/phantomjs"