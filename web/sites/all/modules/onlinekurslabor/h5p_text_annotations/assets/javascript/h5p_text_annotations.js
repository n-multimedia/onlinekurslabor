 
/*setzt man im Lehrtext einem Element die CSS-Klase "h5p_timestamps", so wird der Text darin in anspringbare timestamps konvertiert*/
jQuery(document).ready(function() {
    Drupal.behaviors.h5p_connector_api.onH5Pready(function() {
       jQuery('.h5p_timestamps').convertTextToLinks(['video']);
    });
});