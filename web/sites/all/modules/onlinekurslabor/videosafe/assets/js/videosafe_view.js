/**
 * derzeit 
 * 
 * nicht
 * 
 * in benutzung
 * 
 * 
 * */
(function ($) {
  Drupal.behaviors.videosafe = {

    initialize: function () {  //gnaaz dummer chrome braucht noch ne sekunde
      Drupal.behaviors.h5p_connector_api.onH5Pready(function () {
        setTimeout(function () {
          Drupal.behaviors.videosafe.checkVideoStatus();
        }, 1000);
      });

    },
    /*prüft beim abspielen eines videos auf playability (404, 403 etc) und gibt Fehlermeldung*/
    checkVideoStatus: function () {
      if (isNaN(Drupal.behaviors.h5p_connector_api.av_player.getDuration()))
        alert("Das Video kann nicht abgespielt werden. Bitte kontaktieren Sie uns.");

    }
  }
}(jQuery));


jQuery(document).ready(function () {
  Drupal.behaviors.videosafe.initialize();
});