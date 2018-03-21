


(function($) {
    Drupal.behaviors.annvid.video = {
       
      initialize: function()
      {
          
         Drupal.behaviors.h5p_connector_api.av_player.onAVReady(function(){ jQuery.event.trigger({
                       type: "annvid_entity_loaded",
                       message: "video",
                       time: new Date()
               });
           
       });
         
      },
      
        
    }
           
}(jQuery));
        
jQuery(document).ready(function() {
    Drupal.behaviors.annvid.initialize();
    Drupal.behaviors.annvid.setPDFRenderObject(Drupal.behaviors.html5pdf.getPDFRenderer());//todo: mit Identifier

    jQuery(document).on("annvid_entity_loaded", function(e) {
        Drupal.behaviors.annvid.notifyInitialized(e.message);
    });

});