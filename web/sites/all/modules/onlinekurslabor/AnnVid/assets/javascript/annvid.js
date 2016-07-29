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


            jQuery("#annvid_pdftoggle").click(function() {
                if (jQuery("#annvid_pdfdiv").is(":visible") == true)
                {
                    jQuery("#annvid_videodiv").removeClass("span5").addClass("span12");
                    jQuery(".page_maincontent").removeClass("span12").addClass("span8") ;
                    jQuery("#annvid_pdfdiv").hide();
                    jQuery(".span3").show();
                    jQuery(".span1").show();
                    jQuery(this).html("PDF anzeigen");
                } else
                {
                    jQuery("#annvid_videodiv").removeClass("span12").addClass("span5");
                    jQuery(".span8").removeClass("span8").addClass("span12").addClass("page_maincontent");
                    jQuery("#annvid_pdfdiv").show();
                    jQuery(".span3").hide();
                    jQuery(".span1").hide();

                    jQuery(this).html("PDF verstecken");
                }
                return false;
            });

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
                Drupal.behaviors.annvid.stream.fillStreamTimeline()   ;
                Drupal.behaviors.annvid.stream.repositionTimemark(Drupal.behaviors.h5p_connector_api.interactivevideo.getH5P().video.getCurrentTime());  
                
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
