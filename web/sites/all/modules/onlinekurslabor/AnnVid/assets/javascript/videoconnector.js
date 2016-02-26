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
              Drupal.behaviors.annvid.video.save_video_object();
              Drupal.behaviors.annvid.video.initialize(Drupal.behaviors.annvid.notifyInitialized);
              Drupal.behaviors.annvid.video.startVideoListener();
              
              //jQuery('body').on('show', '.h5p-play', function(event) {alert("loaded"); });
               //Drupal.behaviors.annvid.video.gotoVideoPosition(0); 
        },
        notifyInitialized: function(name)
        {
            Drupal.behaviors.annvid.initialized_state.push(name);
            if(Drupal.behaviors.annvid.initialized_state.length >=2)
            {
                //springe zur übergebenen url
                Drupal.behaviors.annvid.processHash();
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
      
           
        /*erstellt neuen hash und redirected die url*/
         redirect: function(newfragment) {
            var hash = window.location.hash;
            var new_hash = hash;
            //  var fragment = url.substring(url.indexOf('#')); // '#foo'
              console.debug(newfragment);
            if (hash.length <= 1)
                new_hash = "#" + newfragment;
            else
            {   //erkenne typ des neuen fragments
                var type = newfragment.substr(0, newfragment.indexOf('.'));
                //entferne altvorkommen diesen typs
                var re = new RegExp(type + "\\.\\d+", "g");
                new_hash = hash.replace(re, '');
                //häng frgament an
                new_hash += newfragment;
            }

            console.debug(hash, new_hash);
            window.location = new_hash;
        },
        
/*       (*) Rückgabe: form  [["pdf", "8"], ["video", "260"]]*/
        splitHash: function(hash)
        {  
            var matches = hash.match(/\w+\.\d+/g);
            var counter;
            var pro = new Array();
           
           
           if(matches)
            for (counter = 0; counter < matches.length; ++counter)
            {
               var entry = matches[counter];
                var fullentry = entry.match(/(\w+)/g);
                pro[counter] = fullentry;
            }
            return pro;
        },
        processHash: function()
        {    
             var hash = window.location.hash;
           var matches =   this.splitHash(hash);
          
           var counter; 
           for (counter = 0; counter < matches.length; ++counter) 
               { 
                   entry = matches[counter];
                   console.debug("doing"+entry);
                  if(entry[0]=="pdf")
                      Drupal.behaviors.annvid.getPDFRenderObject().goToPage(entry[1]);
                   if(entry[0]=="video")
                       Drupal.behaviors.annvid.video.gotoVideoPosition(entry[1]);

               }
           
               
           }
        
        
              
    }
}(jQuery));




(function($) {
    Drupal.behaviors.annvid.video = {
         //siehe save_video_objects, wird nach onload gesetzt
        h5p_data_container: null,
        last_seen_time: null,
        videoobject: null,
        interval_check_loaded: null,
      
      initialize: function()
      {
          this.interval_check_loaded =        setInterval(function () {
                                                  Drupal.behaviors.annvid.video.checkInitialized();

                                             },1000);
      },
      checkInitialized: function()
      {var video_object = this.getVideoObject();
          if(jQuery(video_object.container).find(".h5p-pause").length)
          {
             
              this.gotoVideoPosition(0);
              
              //trigger event to listen to
                jQuery.event.trigger({
                       type: "annvid_entity_loaded",
                       message: "video",
                       time: new Date()
               }); 
              clearInterval(this.interval_check_loaded);
              this.interval_check_loaded = 0;
          }
          
      },
      

        /*Klassendefinition fuer ein gespeichertes Videoobjekt*/
        video_object: function(object_g, container_g) {

            this.container = container_g;
            this.object = object_g;
            //console.debug(this);
        },
        
          humanizeTime: function(timeinsecs)
        {
            return H5P.InteractiveVideo.humanizeTime(timeinsecs);
        }
        ,
        computerizeTime: function(timestampstring)
        {//credit:http://stackoverflow.com/questions/6312993/javascript-seconds-to-time-string-with-format-hhmmss
              var ts = timestampstring.split(':');
              if(ts.length == 2)
                  return Date.UTC(1970, 0, 1,  0,    ts[0], ts[1]) / 1000;
              else
                  return Date.UTC(1970, 0, 1, ts[0], ts[1], ts[2]) / 1000;
        },
          getVideoObject: function()
        {
            return this.videoobject;
        },
        
        
        /*object: h5p-interaction-objekt; container: jQuery-Objekt*/
        setVideoObject: function(object, container)
        {
            var video_object = new Drupal.behaviors.annvid.video.video_object(object, container);
            this.videoobject = video_object;
            return true; 
        },
        /*
         save_video_objects: ueberscrheibt temporär die funktion  H5P.InteractiveVideo.prototype.attach um sich einklinken zu koennen. führt die originalversion anschließend aus.
         */
        save_video_object: function()
        { 
           
             if (typeof H5P === 'undefined' || typeof(H5PIntegration) === 'undefined' || typeof H5P.InteractiveVideo === 'undefined')
                return false;
          
              /*
               * 
               * ggf bei neuen versionen anpassen, ist das js-objekt des original-h5p-plugins
               * 
               * 
               */
              this.h5p_data_container = H5PIntegration.contents;
            

            var saved_object = null;
           
            var originalInteractiveVideoPrototypeAttachMethod = H5P.InteractiveVideo.prototype.attach;
            //Ueberschreibe original Funktionsaufruf
            H5P.InteractiveVideo.prototype.attach = function()
            {
                
                //speichert videoobjekt  
                Drupal.behaviors.annvid.video.setVideoObject(this, arguments[0]);

                //Rufe Originalfunktion auf
                var result = originalInteractiveVideoPrototypeAttachMethod.apply(this, arguments);
                return result;
                
            }

        },
        /*prüft den html-code des players*/
        checkTime: function()
        {  //lese momentane zeit aus videoobjekt
             var obj = this.getVideoObject();
             var currvideotime = obj.object.video.getTime();
             var new_time  =  Math.floor(currvideotime); 
        //console.debug("9ihnkbdf variable, comparing: "+new_time+" , "+this.last_seen_time);
         if(new_time != this.last_seen_time)
         { 
           
             //trigger event to listen to
                jQuery.event.trigger({
                       type: "videotimechanged",
                       message: new_time,
                       time: new Date()
               }); 
                this.last_seen_time = new_time;
         }
        },
        startVideoListener: function()
        { 
             setInterval(function () {
                 Drupal.behaviors.annvid.video.checkTime();
               
            },1000);
        },
      
        gotoVideoPosition: function(time_secs)
        {var video_object = this.getVideoObject();
            console.debug(video_object);
            var click_delay = 200;
            //wegen der redirects würde es sonst zu rucklern kommen: wenn zeit die gleiche wie im video, nicht jumpen
            /*if(Math.floor(video_object.object.video.getTime()) == time_secs)
                return false;
             (ist zu ungenau)*/
            video_object.object.video.seek(time_secs);

                //wenn video schon abspielt muss man keinen klick simulieren. sonst schon.
                if (!video_object.object.video.isPlaying())
                { 

                    //ist auf pause, auf play setzen (pause bedeutet, video ist pausiert, bei klick startets wieder)
                    setTimeout(function() {
                        jQuery(video_object.container).find(".h5p-pause")[0].click();
                    }, click_delay);
                    //und wieder auf pause (viceversa))
                    setTimeout(function() {
                        //ist NICHT pausiert, dann auf Pause drücken
                        if (jQuery(video_object.container).find(".h5p-pause").length == 0)
                        { 
                            jQuery(video_object.container).find(".h5p-play")[0].click();
                        }

                    }, 2 * click_delay);
                }

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
/*dom-funktion*/
jQuery(window).on('hashchange', function(e){
   //nach umleitung auf hash: entsprechende befehle durchführen
    Drupal.behaviors.annvid.processHash();
});