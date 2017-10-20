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
        pdfrenderobject: null, 
        
        initialize: function()
        {   

            Drupal.behaviors.annvid.video.initialize(Drupal.behaviors.annvid.notifyInitialized);


            jQuery("#annvid_button_show_pdf, #annvid_button_hide_pdf").click(function() {
                Drupal.behaviors.annvid.togglePDFvisibility();
                return false;
            });
            //verschiebt stream-timeline mit ins video-div
            jQuery("#stream_timeline").appendTo("#annvid_video_container");
            
            // Drupal.behaviors.annvid.video.startVideoListener();

            //jQuery('body').on('show', '.h5p-play', function(event) {alert("loaded"); });
            //Drupal.behaviors.annvid.video.gotoVideoPosition(0); 
        },
        /*Beim Ausfuehren der Funktion wird PDF ein- oder ausgeblendet*/
        togglePDFvisibility: function()
        {
            if (jQuery("#annvid_pdfdiv").is(":visible") == true)
                {
                    jQuery("#annvid_videodiv").removeClass("col-md-6").addClass("col-md-12");
                    jQuery(".page_maincontent").removeClass("col-md-12").addClass("col-md-8") ;
                    jQuery("#annvid_pdfdiv").removeClass("pdf_visible");
                    //zeige book-navi links
                    jQuery(".panels-flexible-column-first:has('ul.menu.nav')").show();
                    //author-tools rechts
                    jQuery(".col-md-1:has('#authors_tools-container')").show();
                    jQuery(".col-md-1:has('#instructors_tools-container')").show();
                    
                    jQuery(".main-container").removeAttr("style");
                    Drupal.behaviors.annvid.stream.fillStreamTimeline();
                    jQuery("#annvid_button_show_pdf_container").show();
                    
                } else
                {   //now show pdf!
                 
                    jQuery("#annvid_videodiv").removeClass("col-md-12").addClass("col-md-6");
                    jQuery(".col-md-8").removeClass("col-md-8").addClass("col-md-12").addClass("page_maincontent");
                    jQuery("#annvid_pdfdiv").addClass("pdf_visible");
                    //verstecke book-navi links
                    jQuery(".panels-flexible-column-first:has('ul.menu.nav')").hide();
                    //author-tools rechts
                    jQuery(".col-md-1:has('#authors_tools-container')").hide();
                     jQuery(".col-md-1:has('#instructors_tools-container')").hide();
                    jQuery(".main-container").attr("style", "width:100%;");
                    Drupal.behaviors.annvid.stream.fillStreamTimeline();
                    jQuery("#annvid_button_show_pdf_container").hide();
                }
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
                
                //wenn man die Seite runterscrollt, solls Video mitlaufen
                //nicht für Handies; wird einmalig beim Laden der Seite gecheckt
                if(!jQuery("#is_small_screen_device").is(":visible"))
                {
                     Drupal.behaviors.annvid.startScrollListener();   
                }
            
            }
            
            
        },

         getPDFRenderObject: function()
        {
            return this.pdfrenderobject;
        },
        
        /**
         * wenn man auf der Seite nach unten scrollt, wird das Video verkleinert und 
         * läuft quasi mit den Stremainträgen mit. 
         * @returns {undefined}
         */
        enterScrollMode: function()
        {
            //verhindert flackern
            if (!jQuery("#annvid_video_placeholder").is(":visible"))
            {
                var stream_width = jQuery("#annvid_videodiv").width();
                var space_right = (jQuery( document ).width() - jQuery(".main-container").width() ) / 2 ;
                var scrolled_video_width = 400;
                var video_margin_left = stream_width - scrolled_video_width;
                var viewport_height_reduced = Math.floor(jQuery( window ).height()*0.85);
                //widescreen & PDF versteckt => Video nach rechts verlagern
                if(space_right > scrolled_video_width && ! jQuery("#annvid_pdfdiv").hasClass("pdf_visible")) 
                    video_margin_left = stream_width + 50;
               
                jQuery("#annvid_video_placeholder").show().height(jQuery("#annvid_video_container").height());
                
                jQuery("#annvid_video_container").addClass('annvid_active_scroll_mode').css("margin-left", (video_margin_left) + "px");
                //timeline wiederherstellen
                Drupal.behaviors.annvid.stream.fillStreamTimeline()   ;
                Drupal.behaviors.annvid.stream.repositionTimemark(Drupal.behaviors.h5p_connector_api.interactivevideo.getH5P().video.getCurrentTime());  
                //pdf: position fixed und Höhe reduzieren, um Scrollen innerhalb pdf zu ermöglichen
                jQuery("#annvid_pdfdiv").addClass('annvid_active_scroll_mode').find(".html5pdf_pdfscrollcontainer").css("max-height",viewport_height_reduced+"px");
            }

        },
        /*
         * user hat wieder nach oben gescrollt. Video+PDF wird normal angezeigt. 
         * @returns {undefined}
         */
        leaveScrollMode: function()
        {
            jQuery("#annvid_video_placeholder").hide();
            jQuery("#annvid_video_container").removeClass('annvid_active_scroll_mode').attr('style', '');
           
            
            //timeline wiederherstellen
            Drupal.behaviors.annvid.stream.fillStreamTimeline();
            Drupal.behaviors.annvid.stream.repositionTimemark(Drupal.behaviors.h5p_connector_api.interactivevideo.getH5P().video.getCurrentTime());

            jQuery("#annvid_pdfdiv").removeClass('annvid_active_scroll_mode');
            //entferne height-attribute vom pdf
            jQuery("#annvid_pdfdiv .html5pdf_pdfscrollcontainer").css("height","");
        },
        /**
         * checkt auf Scroll-Event, um Video beim scrollen mitlaufen zu lassen. 
         * Nicht berücksichtigt: Fenster-Resize. 
         * @returns {undefined}
         */
        startScrollListener: function()
        {
            var video_height = jQuery("#annvid_video_container").height();
            //der course-header führt sonst zu problemen
            var header_offset = jQuery("header").height();

            jQuery(document).on('scroll', function() {
                //wenn man die Seite eine gewisse Höhe runtergescrollt hat.. 
                var calculated_scroll_offset = header_offset + video_height * 2 / 3;
                if (jQuery(document).scrollTop() >= calculated_scroll_offset)
                    Drupal.behaviors.annvid.enterScrollMode();
                else
                    Drupal.behaviors.annvid.leaveScrollMode();
            });

        },
         
        
        /*object: pdf-renderer*/
        setPDFRenderObject: function(object)
        { 
            this.pdfrenderobject = object;
            return true; 
        }     
    }
}(jQuery));
