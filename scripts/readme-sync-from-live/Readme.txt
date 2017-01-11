Das Tool ist fertig konfiguriert auf div@plesk2.

Für den Fall eines crashs oder Neukonfiguration auf einem anderen System hier eine Anleitung:
Ausgegangen wird davon, dass ein Entwicklungssystem von Live pullt.
Aus Sicherheitsgründen geht dies nicht ohne KEY, da sonst von Test-System Vollzugriff auf LIVE bestünde.


############################################################
1. ALIAS einrichten, vgl. https://www.drupal.org/node/670460
############################################################
- Auf Live:
echo "<?"  > my.alias.drushrc.php &&  drush site-alias  --with-optional @self >> my.alias.drushrc.php
my.alias.drushrc.php bearbeiten: 
Zu Beginn einfügen:
$hostdefinition_live = array (
  'remote-host' => 'onlinekurslabor.phil.uni-augsburg.de',
  'remote-user' => 'onlinekurslabor',
);
Dann:
"self" durch "okl.live" ersetzen.

Dann: vor ";" am Ende einfügen:
+ $hostdefinition_live

Hinweis: "parent-Deklaration" im Alias nicht mehr möglich (deprecated)

Datei verschieben auf TESTSYSTEM/HOME/.drush/okl.live.alias.drushrc.php (drush ist installiert gemäß http://docs.drush.org/en/master/install/)
my.alias.drushrc.php auf live löschen


############################################################
2. RSA einrichten
############################################################
drush unterstützt keine Authentifizierung per username / password. Deswegen müssen wir RSA einrichten.
In diesem Ordner liegt die push-key-to-server.sh

sh 	push-key-to-server.sh onlinekurslabor@onlinekurslabor.phil.uni-augsburg.de

Die Schritte sind selbsterklärend. SSH-PW für Live wird benötigt.
Es muss ZWINGEND ein KEY erstellt werden und an sicherer Stelle gespeichert werden (nicht auf einem Server inbesondere!)
Dieser wird bei jeder Ausführung der sync_data_from_live benötigt.
 

############################################################ 
3. FERTIG
############################################################
nun sollte die sync_data_from_live funktionieren.