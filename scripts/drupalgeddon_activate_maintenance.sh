##!/bin/bash

# 
##############
#   HOWTO
##############
#
# diese Datei ist Teil von drupalgeddon_react.sh
# aus Gründen der Übersichtlichkeit extrahiert.
#
# kann aber auch einfach so aufgerufen werden und sperrt das System:
# :/web/web$ sh ../scripts/drupalgeddon_activate_maintenance.sh
# 

 
cd ../web/
 
 
 #ueberschreibe htaccess
 #printf 'ErrorDocument 403 \"Diese Seite ist aufgrund eines dringenden Updates voruebergehend ausser Betrieb!<br>Das Medienlabor.\" \n order deny,allow \n deny from all\n' > .htaccess
 echo 'ErrorDocument 503 /503_maintenance.html' > .htaccess
 echo 'RewriteEngine On ' >> .htaccess
 echo 'RewriteCond %{REQUEST_URI} !(503_maintenance.html)$' >> .htaccess
 echo 'RewriteCond %{REQUEST_URI} !.(css|gif|ico|jpg|js|png|svg|swf|txt)$' >> .htaccess
 echo 'RewriteRule .* - [R=503,L]' >> .htaccess
 