


(function($) {
    Drupal.behaviors.annvid.video = {
       
      initialize: function()
      {
          
         Drupal.behaviors.h5p_connector_api.av_player.onAVReady(function(){ jQuery.event.trigger({
                       type: "annvid_entity_loaded",
                       message: "video",
                       detail: {identifier: null},
                       time: new Date()
               });
           
       });
         
      },
      
        
    }
           
}(jQuery));

jQuery(document).ready(function () {
    Drupal.behaviors.annvid.initialize();

    jQuery(document).on("annvid_entity_loaded", function (e) {
        var elements_identifier = e.detail.identifier;
         
        if (e.message === 'pdf')
        {
            Drupal.behaviors.annvid.setPDFRenderObject(Drupal.behaviors.html5pdf.getPDFRenderer(elements_identifier));
        }
        Drupal.behaviors.annvid.notifyInitialized(e.message);
    });

});