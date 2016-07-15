/*
 * Wir gehen davon aus, dass es eh nur einen Player auf der Seite gibt. 
 *  
 */
(function($) {
    Drupal.behaviors.annvid = {
        attach: function(context, settings) {
       Drupal.behaviors.annvid.stream.attach(context, settings) ;
      //gibnts nich  Drupal.behaviors.annvid.video.attach(context, settings);
        },
        initialized_state: new Array(),
        
        initialize: function()
        {
 
              Drupal.behaviors.annvid.video.initialize(Drupal.behaviors.annvid.notifyInitialized);
             // Drupal.behaviors.annvid.video.startVideoListener();
              
              //jQuery('body').on('show', '.h5p-play', function(event) {alert("loaded"); });
               //Drupal.behaviors.annvid.video.gotoVideoPosition(0); 
        },
        notifyInitialized: function(name)
        {
            Drupal.behaviors.annvid.initialized_state.push(name);
            if(Drupal.behaviors.annvid.initialized_state.length >=2)
            {
                //springe zur übergebenen url
              
                jQuery(".annvid_container").addClass("annvid_container_loaded");
                jQuery(".annvid_loading_div").fadeOut("slow");
                Drupal.behaviors.annvid.stream.createStreamTimeline()   ;
                  
                
            }
            
            
        },
       


        pdfrenderobject: null, 

         getPDFRenderObject: function()
        {
            return this.pdfrenderobject;
        },
        
        
        /*object: pdf-renderer*/
        setPDFRenderObject: function(object)
        {
             this.pdfrenderobject = object;
            return true; 
        },
      
           
          
              
    }
}(jQuery));




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
                console.log('new time!' + e.message);
    });
   
    
     jQuery(document).on("annvid_entity_loaded", function(e){ 
         Drupal.behaviors.annvid.notifyInitialized(e.message);
    });
    
});