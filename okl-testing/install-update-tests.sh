##!/bin/bash
#aktuelle DIR in ssh
current_directory=$(pwd)
# gehe zu Liegeort dieses Scripts
cd "$(dirname "$0")"


cd "$current_directory"
echo -e "\n\n\n##################################\nEinrichtung Autotests\n##################################\n"
sleep 2


## die .yml existieren nicht - zuerst anzulegen!
if [ ! -f ./tests/acceptance.suite.yml ]; then
    echo -e "Kopiere zunaechst im Ordner okl-testing/tests die .yml.dist zu .yml und passe die URLs zu deinem Projekt an!\n\n"
    echo -e "Fuehre danach dieses Skript wieder aus.\n\n"
    exit
fi

## .ymls existieren, verzeichnis /vendor nicht - installiere dependencies neu
if [ ! -d ./vendor/ ]; then
    echo -e "Ich installiere nun die Dependencies\n\n"
    sleep 2
    composer install
    exit
fi

## ELSE
# ymls existieren, vendor-verzeichnis auch. Dann mach ich ein Update

echo -e "##################################\nUpdate Autotests\n##################################\n"

echo -e "Ich aktualisiere in 10 Sekunden die Dependencies\n\n"
sleep 10
 
composer update

