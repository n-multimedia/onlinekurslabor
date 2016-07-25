


(function($) {
    Drupal.behaviors.annvid.video = {
       
      initialize: function()
      {
         Drupal.behaviors.h5p_connector_api.interactivevideo.onVideoReady(function(){ jQuery.event.trigger({
                       type: "annvid_entity_loaded",
                       message: "video",
                       time: new Date()
               });
           Drupal.behaviors.h5p_connector_api.interactivevideo.startVideotimeListener();
       });
      },
      
        
    }
           
}(jQuery));
        
jQuery(document).ready(function() {
    Drupal.behaviors.annvid.initialize();
    Drupal.behaviors.annvid.setPDFRenderObject(Drupal.behaviors.html5pdf.getPDFRenderer());//todo: mit Identifier
    jQuery(document).on("videotimechanged", function(e){ 
            //   Drupal.behaviors.annvid.redirect("video:"+e.message);
              Drupal.behaviors.h5p_connector_api.event.redirect("video."+e.message);
                console.log('new time!' + e.message);
    });
   
    
     jQuery(document).on("annvid_entity_loaded", function(e){ 
         Drupal.behaviors.annvid.notifyInitialized(e.message);
    });
    
});