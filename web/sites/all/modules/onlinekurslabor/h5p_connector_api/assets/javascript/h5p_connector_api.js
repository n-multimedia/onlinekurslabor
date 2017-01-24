(function($) {
    $.fn.convertTextToLinks = function(options) {
        if (typeof options === 'undefined' || options.length === 0)
            options = ['pdf', 'video'];

        //geht durch die einzelnen inhalte
        $(this).each(function(index) {
            var text = $(this).html();


            /*ersetze Seite 8 (etc) durch Link Seite 8 */
            if (options.indexOf('pdf') >= 0)
            {
                text = text.replace(Drupal.behaviors.h5p_connector_api.text.regex_pdffeature, "<a data=\"pdf.$2\">$1 $2</a>");
            }
            /*VIDEO-MARKE  */
            if (options.indexOf('video') >= 0)
            {
                text = text.replace(Drupal.behaviors.h5p_connector_api.text.regex_timestampfeature, function(s, m1, m2, m3) {
                    return m1 + "<a   data=\"video." + Drupal.behaviors.h5p_connector_api.interactivevideo.computerizeTime(m2) + "\">" + m2 + "</a>" + m3;
                });
            }

            $(this).html(text);
            
          $(this).makeControlLinksClickable();
        });
    };
    $.fn.makeControlLinksClickable = function()
    {
          //jetzt noch die a-data-links in links mit sprungziel und click-event konvertierern
            $("a[data^='video.'],a[data^='pdf.']", this).each(function() {
                $(this).attr('href', '#' + $(this).attr('data')).click(function() {
                    Drupal.behaviors.h5p_connector_api.event.processControlString(Drupal.behaviors.h5p_connector_api.event.getNewHash($(this).attr("data")));
                    Drupal.behaviors.h5p_connector_api.event.redirect($(this).attr("data"));
                    return false;
                })
            });
    }
}(jQuery));


(function($) {
    Drupal.behaviors.h5p_connector_api = {
        h5pEditorreadyCount: 0,
        /*wenn h5p geladen hat, wird der uebergebene callback ausgefuehrt*/
        onH5Pready: function(callback)
        {
            (typeof H5P !== 'object' || typeof H5P.instances !== 'object' || H5P.instances.length === 0) ? setTimeout(Drupal.behaviors.h5p_connector_api.onH5Pready, 1000, callback) : callback();
        },
        /*API-Funktion beim Erstellen eines neuen H5P-Contents / editieren eines vorhandenen*/
         onH5PEditorready: function(callback)
        { 
            //bricht nach 15 sec ab
            if(Drupal.behaviors.h5p_connector_api.h5pEditorreadyCount++ >15)
                return false;
             (typeof H5PEditor === 'undefined' || typeof H5PEditor.widgets === 'undefined' || typeof H5PEditor.widgets.video === 'undefined') ? setTimeout(Drupal.behaviors.h5p_connector_api.onH5PEditorready, 1000, callback) : callback();
        }
    };
    
    Drupal.behaviors.h5p_connector_api.text = {
        regex_pdffeature: /(seite|page|site|p|pp|folie)\s*(\d+)/igm,
        /* with thanks to https://regex101.com/
         * 
         * VIDEO-MARKE
         * matcht HH:MM:SS:FF HH:MM:SS H:MM:SS:FF H:MM:SS MM:SS M:SS
         * Pflicht: %startzeichen,
         * gefolgt von  ((0-99 oder 00-99) und :) (optional, HH: bzw H:) , optional 0 - 5 und pflicht ein digit und : (M: bzw MM:)
         * dann pflicht 0 - 5 und ein digit (SS)
         * dann kommt ein optionaler non-match mit ":00 - :99"(frame 0-99) um frame-angabe abzuschneiden 
         * und dann  %not-a gefolgt von %endzeichen
         * %startzeichen = leerzeichen, zeilenstart, html-Zeichen > , klammer auf oder  &nbsp;
         * %not-a = Nicht die kombination </a um Doppel-Replacements zu vermeiden
         * %endzeichen = komma, punkt , leerzeichen , fragezeichen , &nbsp; , Klammer zu, zeilenende oder html-Zeichen <
         * match auf  %startzeichen, zeitstamp und %endzeichen. /greedy, multiline*/
        regex_timestampfeature: /( |^|>|\(|&nbsp;)((?:\d?\d\:){0,1}[0-5]{0,1}\d:[0-5]\d)(?:\:\d\d){0,1}(?!<\/a)([\,\. \?]|&nbsp;|\)|$|<)/gm,
    };

    Drupal.behaviors.h5p_connector_api.event = {
        /*erstellt neuen hash und redirected die url*/
        redirect: function(newfragment) {
         
            // console.debug(hash, new_hash);
            window.location = this.getNewHash(newfragment);
        },
        /**
         *  erstellt neuen hash basierend auf einer neuen steuerungsinformation
         */
        getNewHash: function(newfragment)
        {
               var hash = window.location.hash;
            var new_hash = hash;
            //  var fragment = url.substring(url.indexOf('#')); // '#foo'
            // console.debug(newfragment);
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
        return new_hash;
        },
        /*       (*) Rückgabe: form  [["pdf", "8"], ["video", "260"]]*/
        splitHash: function(hash)
        {
            var matches = hash.match(/\w+\.\d+/g);
            var counter;
            var pro = new Array();


            if (matches)
                for (counter = 0; counter < matches.length; ++counter)
                {
                    var entry = matches[counter];
                    var fullentry = entry.match(/(\w+)/g);
                    pro[counter] = fullentry;
                }
            return pro;
        },
        /**
         * verarbeitetet den Hash in der Adresszeile und springt entsprechend an die Videoposition
         * muss händisch aufgerufen werden
         * 
         */
        processHash: function()
        {
           this.processControlString(window.location.hash);
        },
        /***
         *
         * @param {string} controlstring wie "#pdf.2video.66
         * @returns {undefined}         
         */
        processControlString: function(controlstring)
        {
            var matches = this.splitHash(controlstring);
            var counter;
            for (counter = 0; counter < matches.length; ++counter)
            {
                entry = matches[counter];

                if (entry[0] == "pdf")
                    Drupal.behaviors.annvid.getPDFRenderObject().goToPage(entry[1]);
                if (entry[0] == "video")
                    Drupal.behaviors.h5p_connector_api.interactivevideo.goTo(entry[1]);

            }
        }
    };

    Drupal.behaviors.h5p_connector_api.interactivevideo = {
        last_seen_time: null,//zuletzt geprüfte zeit
        attach: function(context, settings) {


        },
        onVideoReady: function(callback)
        {
         Drupal.behaviors.h5p_connector_api.onH5Pready(function(){Drupal.behaviors.h5p_connector_api.interactivevideo.onVideoReadyhelper(callback)})   ;
                   
        },
        onVideoReadyhelper: function(callback)
        {
            var vidobject = Drupal.behaviors.h5p_connector_api.interactivevideo.getH5P().video;
            (typeof vidobject === 'undefined' || typeof vidobject.getDuration() === 'undefined') ? setTimeout(Drupal.behaviors.h5p_connector_api.interactivevideo.onVideoReadyhelper,  500, callback) : callback();
        },
        /*
         * Problem: das drupal-filesystem ist nicht das schnellste und wenn man zu früh auf Play drückt,
         * funktioniert die Zeitanzeige im Player nicht. Deswegen verstecken.. 
         */
        showLoadingAnimation: function()
        {
            var loading_animation = '<div class="h5p_connector_loading_inner"><h3>lädt</h3><div>';   
            jQuery("div.h5p-interactive-video").before("<div id='h5p_connector_loading'    >"+loading_animation+"</div>");
        },
        removeLoadingAnimation: function()
        {
            jQuery("div#h5p_connector_loading").fadeOut();
        },
        /*holt das interactivevideo-object*/
        getH5P: function()
        {
            for (i = 0; i < H5P.instances.length; i++) {
                if (H5P.instances[i].libraryInfo.machineName === "H5P.InteractiveVideo")
                    return H5P.instances[i];
            }

        },
        getH5P_ID: function()
        {
            return this.getH5P().contentId;
        },
        getH5PVersion: function()
        {
            return (H5P.instances[0].libraryInfo.majorVersion * 10 + 1 * H5P.instances[0].libraryInfo.minorVersion) / 10;
        },
        /*liefert alle Annotationen zum momentanigen Video*/
        getAllAnnotations: function( )
        {
            //hole json-data
            var videojson = H5PIntegration.contents['cid-' + this.getH5P_ID()];

            if (typeof videojson !== undefined)
            {
                videojson = videojson['jsonContent'];
            }
            else
            {
                //console.log('ERROR: Sorry, but no annotations could be found.');
                return null;
            }

            /*extrahiere annotationsdaten und sortiere diese*/
            var videojsonparsed = jQuery.parseJSON(videojson);
            //Anpassung neue JS-Struktur
            if (typeof videojsonparsed === 'undefined' || typeof videojsonparsed.interactiveVideo === 'undefined' || (typeof videojsonparsed.interactiveVideo.interactions === 'undefined' && ( typeof  videojsonparsed.interactiveVideo.assets ==='undefined' || typeof videojsonparsed.interactiveVideo.assets.interactions === 'undefined')))
                return null;
            var all_interactions = null;
            //fallbackauswahl
            if (typeof videojsonparsed.interactiveVideo.interactions === 'undefined')
                all_interactions = videojsonparsed.interactiveVideo.assets.interactions;
            else
                all_interactions = videojsonparsed.interactiveVideo.interactions;

            return all_interactions;
        },
        /*springt im video zum angegeben computer-timestamp, bspw. 77*/
        goTo: function(timestamp)
        {
            var video_object = this.getH5P();
            var click_delay = 100;
            var click_delay_multiplicator;
            video_object.video.seek(timestamp);
            //console.debug(this.getH5PVersion()+" <- vdersion -> state "+video_object.video.parent.currentState);
            //ab version 2 ist bei state >= 5 nichts mehr noetig
            //moeglicih, dass versionen < 2 nun nicht mehr gehen
            if ((this.getH5PVersion() == 1.0) && !video_object.video.isPlaying()
                    || (this.getH5PVersion() > 1.0) && (video_object.video.parent.currentState > 1) && (video_object.video.parent.currentState < 5)) //1 == playing, 2 == pause, 5 = nicht gestartet
            {
                //Status: pause
                //click_delay_multiplicator: damit vertauscht man die ausfuehrungsreihenfolge, noetig fuer ie
                if (video_object.video.parent.currentState == 2)
                {
                    click_delay_multiplicator = 2;
                }
                //Status: play
                else
                {
                    click_delay_multiplicator = 0.25;
                }

                //kurz anspielen, um laden anzustossen
                setTimeout(function() {
                    video_object.play();
                }, click_delay);

                //pause player und per api neuen timestamp einpflegen
                setTimeout(function() {
                    video_object.pause();
                    video_object.timeUpdate(timestamp);
                }, click_delay * click_delay_multiplicator);


            }

        },
        /*
         * hole momentane zeit im player. leichter versatz im sekundenbereich möglich!!!
         * @param bool humanized: menschliche zeit, sonst zeit in sec
         * @returns {int / string }timestamp beginning from 0 / 00:00
         */
        getCurrentVideoTime: function(humanized)
        {
            if(humanized)
                return this.humanizeTime(this.last_seen_time)
            else
                return this.last_seen_time;
        }
        ,
        /**
         * konvertiert Sekundenangaben in lesbare Zeit
         * bspw: 77 secs = 1:17
         * @param {int} timeinsecs
         * @returns {String} time
         */
        humanizeTime: function(timeinsecs)
        {
            return H5P.InteractiveVideo.humanizeTime(timeinsecs);
        }
        ,
         /*prüft ob der player weitergelaufen ist*/
        checkTime: function()
        {  //lese momentane zeit aus videoobjekt
             var obj = this.getH5P();
             var currvideotime = obj.video.getCurrentTime();
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
        /*
         * startet einen listener auf videotime und wirft ein event
         * videotimechanged bei einer neuen Zeitmarke
         * @returns {undefined}
         */
        startVideotimeListener: function()
        { 
             setInterval(function () {
                 Drupal.behaviors.h5p_connector_api.interactivevideo.checkTime();
               
            },1000);
        }
        ,
        computerizeTime: function(timestampstring)
        {//credit:http://stackoverflow.com/questions/6312993/javascript-seconds-to-time-string-with-format-hhmmss
            var ts = timestampstring.split(':');
            if (ts.length == 2)
                return Date.UTC(1970, 0, 1, 0, ts[0], ts[1]) / 1000;
            else
                return Date.UTC(1970, 0, 1, ts[0], ts[1], ts[2]) / 1000;
        },
    }
}(jQuery));

/* obsolet, da hashchange zu ruckelig
jQuery(window).on('hashchange', function(e) {
    //nach umleitung auf hash: entsprechende befehle durchführen
  //  Drupal.behaviors.h5p_connector_api.event.processHash();
});
*/

jQuery(document).ready(function() {
    /*blende zunächst ladeanimation ein*/
    Drupal.behaviors.h5p_connector_api.onH5Pready(function() {
        Drupal.behaviors.h5p_connector_api.interactivevideo.showLoadingAnimation();
    });

    /*video geladen, fuehre ein paar aktionen aus*/
    Drupal.behaviors.h5p_connector_api.interactivevideo.onVideoReady(function() {
        /*verlinkt man auf ein video und ein hash ist in der adresszeile soll der beim seiteladen ausgefuehrt werden*/
        Drupal.behaviors.h5p_connector_api.event.processHash();
        Drupal.behaviors.h5p_connector_api.interactivevideo.removeLoadingAnimation();
        Drupal.behaviors.h5p_connector_api.interactivevideo.startVideotimeListener();
    });
    // FF mobil und sonstige Fälle in denen Video nicht auto-geladen wird
    setTimeout( Drupal.behaviors.h5p_connector_api.interactivevideo.removeLoadingAnimation, 10000);
    
    //event: videotimechanged: setze neuen hash in adresszeile
    jQuery(document).on("videotimechanged", function(e){ 
              Drupal.behaviors.h5p_connector_api.event.redirect("video."+e.message);
                //console.log('new time!' + e.message);
    });

});

