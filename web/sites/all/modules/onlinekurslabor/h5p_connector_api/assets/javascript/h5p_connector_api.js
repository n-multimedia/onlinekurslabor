//möchte man neben pdf und video einen weiteren jump-typ einfügen, der im hash erscheint, muss man hier refactoren und die pdf-/video-einträge ergänzen
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
                    return m1 + "<a   data=\"video." + Drupal.behaviors.h5p_connector_api.av_player.computerizeTime(m2) + "\">" + m2 + "</a>" + m3;
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
        
        /**
         * H5P triggert dieverse Events, auf die man reagieren kann
         * @param {type} eventname
         * @param {type} callback
         * @returns {undefined}
         */
        reactOnH5PEvent: function (eventname, callback)
        {   
            // alle events:  Drupal.behaviors.h5p_connector_api.reactOnH5PEvent('*', function(event){console.debug("H5P-Event"); console.debug(event)});
            if(typeof H5P !== 'undefined')
            {
                H5P.externalDispatcher.on(eventname, callback);
            }
        },         
        /*wenn h5p geladen hat, wird der uebergebene callback ausgefuehrt*/
        onH5Pready: function(callback)
        {
            return this.reactOnH5PEvent('initialized', callback);
        },
        /*API-Funktion beim Erstellen eines neuen H5P-Contents / editieren eines vorhandenen*/
         onH5PEditorready: function(callback)
        {  
            return this.reactOnH5PEvent('editorload', callback);
        },
        /*API-Funktion beim Erstellen eines neuen H5P-Contents / editieren eines vorhandenen. Die Editor-GUI ist fertig gerendered.*/
         onH5PEditorrendered: function(callback)
        {    //man beachte beim Event das "..ED"
             return this.reactOnH5PEvent('editorloaded', callback);
        },
        /*wegen h5p-api-changes wird nun vor ausführung immer die version geprüft und auch bei minor-changes ein fehler geworfen*/
        compareVersionAndCallback: function(what, callback)
        {
            var notgood_error = "Severe error: Current version of H5P or H5PEditor does not match h5p_connector_api. Contact developers!!!! Version is:";
            if(what === 'H5PEditor')
            {
                var edit_api = window[0].H5PEditor.apiVersion.majorVersion +"." + window[0].H5PEditor.apiVersion.minorVersion;

                if(edit_api !== "1.24")
                    alert(notgood_error+edit_api);
                else
                    callback();
            }
          //todo in future vrsion  elseif(what === 'H5P')
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
            var matches = hash.match(/(video|pdf)\.\d+/g);
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
            var entry;
            for (counter = 0; counter < matches.length; ++counter)
            {
                entry = matches[counter];

                if (entry[0] == "pdf")
                    Drupal.behaviors.annvid.getPDFRenderObject().goToPage(entry[1]);
                if (entry[0] == "video")
                    Drupal.behaviors.h5p_connector_api.av_player.goTo(entry[1]);

            }
        }
    };

/*
 * WRAPPER für H5p-Audio und H5P-Interactive-Video
 */
    Drupal.behaviors.h5p_connector_api.av_player = {
        last_seen_time: null,//zuletzt geprüfte zeit
        av_object:[],// {type:'audio', version:'2.0', h5p: <object>, duration: 999},
        attach: function(context, settings) {
           

        },
        /**
         * initialisiert Variablen (und wartet zugleich h5p-JS ab)
         * @returns {undefined}
         */
        initialize: function()
        {
            Drupal.behaviors.h5p_connector_api.onH5Pready(function() {
                Drupal.behaviors.h5p_connector_api.av_player.initializeHelper()
            });

        },
        /**
         * Helper-Function für initialize.
         * Prüft regelmäßig, ob H5P-AV schon initialisiert ist und setzt die Variable av_object
         * @returns {undefined}
         */
        initializeHelper: function()
        {
            //es wird kein video-/audioelement angezeigt und somit brechen wir ab.
            if(H5P.instances.length === 0)
            {
                return; 
            }
            for (var i = 0; i < H5P.instances.length; i++) {
                
                var version = H5P.instances[i].libraryInfo.majorVersion + "." + H5P.instances[i].libraryInfo.minorVersion;
                var temp_av_object = []; 
                if (H5P.instances[i].libraryInfo.machineName === "H5P.Audio")
                {
                    temp_av_object = {type: 'audio', version: version, h5p: H5P.instances[i], duration: parseInt(H5P.instances[i].audio.duration)};
                }
                if (H5P.instances[i].libraryInfo.machineName === "H5P.InteractiveVideo")
                {
                   temp_av_object= {type: 'video', version: version, h5p: H5P.instances[i], duration: parseInt(H5P.instances[i].getDuration()) };
                }
            }
            //noch gar kein zugriff aufs objekt oder duration isNan -> nicht fertig geladen
            if (temp_av_object.length === 0 || isNaN (temp_av_object.duration))
            {   
                //console.debug("@todo no success on ready. try aagain.");
                setTimeout(Drupal.behaviors.h5p_connector_api.av_player.initializeHelper, 500);
            }
            else
            {
                Drupal.behaviors.h5p_connector_api.av_player.av_object = temp_av_object;
            }
        },
        
        /**
         * Zuerst triggert Drupal.behaviors.h5p_connector_api.onH5Pready 
         * AV benötigt länger, bis es geladen und initialisiert ist, deswegen diese Funktion als Pendant 
         * @param {type} callback
         * @returns {undefined}
         */
        onAVReady: function(callback)
        {

         Drupal.behaviors.h5p_connector_api.onH5Pready(function(){Drupal.behaviors.h5p_connector_api.av_player.onAVReadyhelper(callback);})   ;
                   
        },
        /**
         * private function
         * Helper für onAVReady
         * @param {type} callback
         * @returns {undefined}
         */
        onAVReadyhelper: function(callback)
        {
            
            (Drupal.behaviors.h5p_connector_api.av_player.av_object.length === 0) ? setTimeout(Drupal.behaviors.h5p_connector_api.av_player.onAVReadyhelper,  500, callback) : callback();
        },
        
        /*holt das interactivevideo-object*/
        //das will ich nicht mehr, soll 1 x gesetzt werden. 
     /*   getH5P: function()
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
        },*/
        /*
         * Problem: das drupal-filesystem ist nicht das schnellste und wenn man zu früh auf Play drückt,
         * funktioniert die Zeitanzeige im Player nicht. Deswegen verstecken.. 
         * 
         * OBSOLET geworden, da H5P besser geworden ist, und den Bug nicht mehr hat. 
         */
        /*
        showLoadingAnimation: function()
        {
            var loading_animation = '<div class="h5p_connector_loading_inner"><h3>lädt</h3><div>';   
            jQuery("div.h5p-interactive-video").before("<div id='h5p_connector_loading'    >"+loading_animation+"</div>");
        },
        removeLoadingAnimation: function()
        {
            jQuery("div#h5p_connector_loading").fadeOut();
        },
         */
        /*liefert alle Annotationen zum momentanigen Video*/
        getAllAnnotations: function( )
        {
            //hole json-data
            var videojson = H5PIntegration.contents['cid-' + this.av_object.h5p.contentId];

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
        
        /*
         * springt im Content zum angegeben computer-timestamp, bspw. 77
         * @param {type} timestamp
         * @returns {undefined}
         */ 
        goTo: function(timestamp)
        { 
            
            var h5p_object = this.av_object.h5p;
            switch(this.av_object['type'])
            {
                case 'audio':
                    h5p_object.audio.currentTime=timestamp ;

                    break;
                case 'video':
                    h5p_object.video.seek(timestamp);
                    //timeUpdate muss man bisschen verzögern
                    setTimeout(function(){h5p_object.timeUpdate(timestamp);}, 500);
                    break;
            }
            
             

        },
        /*
         * hole momentane zeit im player. leichter versatz im sekundenbereich möglich!!!
         * @param bool humanized: menschliche zeit, sonst zeit in sec
         * @returns {int / string }timestamp beginning from 0 / 00:00
         */
        getCurrentTime: function(humanized)
        {
            if(humanized)
                return this.humanizeTime(this.last_seen_time)
            else
                return this.last_seen_time;
        },
        /**
         * gets Duration of h5p-content (video/audio)
         * @param {type} humanized
         * @returns {int}duration in seconds
         */
        getDuration:  function(humanized)
        {
            var duration = this.av_object.duration; 
            
            if(humanized)
                return this.humanizeTime(duration);
            else
              return  duration;
        }
        ,
        /*
         * prüft ob der player weitergelaufen ist
         * private function
         */
        checkTime: function()
        {
            var h5p_object = this.av_object.h5p;
            var h5p_time = 0;
            switch (this.av_object['type'])
            {
                case 'audio':
                    h5p_time = h5p_object.audio.currentTime;
                    break;
                case 'video':
                    h5p_time = h5p_object.video.getCurrentTime();
                    break;
            }

            var new_time = Math.floor(h5p_time);
            //console.debug("9ihnkbdf variable, comparing: "+new_time+" , "+this.last_seen_time);
            if (new_time !== this.last_seen_time)
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
        startTimeListener: function()
        { 
             setInterval(function () {
                 Drupal.behaviors.h5p_connector_api.av_player.checkTime();
               
            },1000);
        }
        ,
        /**
         * Gegenstück zu humanizeTime
         * @param {type} timestampstring
         * @returns {Number}
         */
        computerizeTime: function(timestampstring)
        {//credit:http://stackoverflow.com/questions/6312993/javascript-seconds-to-time-string-with-format-hhmmss
            var ts = timestampstring.split(':');
            if (ts.length == 2)
                return Date.UTC(1970, 0, 1, 0, ts[0], ts[1]) / 1000;
            else
                return Date.UTC(1970, 0, 1, ts[0], ts[1], ts[2]) / 1000;
        },
         /**
         * konvertiert Sekundenangaben in lesbare Zeit
         * bspw: 77 secs = 1:17
         * @param {int} timeinsecs
         * @returns {String} time
         */
        humanizeTime: function(timeinsecs)
        {   var seconds = timeinsecs ; 
            /*code stolen from  H5P.InteractiveVideo.humanizeTime(timeinsecs);*/
            var minutes = Math.floor(seconds / 60);
            var hours = Math.floor(minutes / 60);

            minutes = minutes % 60;
            seconds = Math.floor(seconds % 60);

            var time = '';

            if (hours !== 0) {
                time += hours + ':';

                if (minutes < 10) {
                    time += '0';
                }
            }

            time += minutes + ':';

            if (seconds < 10) {
                time += '0';
            }

            time += seconds;

            return time;
        }
        
    }
}(jQuery));

/* obsolet, da hashchange zu ruckelig
jQuery(window).on('hashchange', function(e) {
    //nach umleitung auf hash: entsprechende befehle durchführen
  //  Drupal.behaviors.h5p_connector_api.event.processHash();
});
*/

jQuery(document).ready(function() {
    Drupal.behaviors.h5p_connector_api.av_player.initialize();
    Drupal.behaviors.h5p_connector_api.av_player.onAVReady(function() {
        
        /*verlinkt man auf ein video und ein hash ist in der adresszeile, so soll der beim seitenladen ausgefuehrt werden*/
        Drupal.behaviors.h5p_connector_api.event.processHash();
        Drupal.behaviors.h5p_connector_api.av_player.startTimeListener();
    });
    
    //event: videotimechanged: setze neuen hash in adresszeile
    jQuery(document).on("videotimechanged", function(e){ 
              Drupal.behaviors.h5p_connector_api.event.redirect("video."+e.message);
                //console.log('new time!' + e.message);
    });
    
    
     

});

