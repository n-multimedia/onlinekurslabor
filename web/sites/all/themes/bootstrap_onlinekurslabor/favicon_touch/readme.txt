Um die Touch-Icons zu nutzen, müssen folgendee .htaccess-Befehl eingefügt werden:


RewriteEngine on
RewriteRule "^apple-touch-icon(.*).png$" "/sites/all/themes/bootstrap_onlinekurslabor/favicon_touch/apple-touch-icon$1.png" [L]
RewriteRule "^touch-icon(.*).png$" "/sites/all/themes/bootstrap_onlinekurslabor/favicon_touch/touch-icon$1.png" [L]
RewriteRule "^favicon.ico$" "/sites/all/themes/bootstrap_onlinekurslabor/favicon_touch/favicon.ico" [L]


Hintergrund:
Mancher Browser verlässt sich nicht auf Header-Angaben sondern sucht stur im Document-Root nach den Icons.
Um Document-Root aber nicht zuzumüllen, werden diese hier gespeichert und per Rewrite aus dem Verzeichnis geladen