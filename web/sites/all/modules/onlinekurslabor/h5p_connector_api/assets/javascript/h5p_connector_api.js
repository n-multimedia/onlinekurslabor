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
            //jetzt noch die a-data-links in links mit sprungziel und click-event konvertierern
            $("a[data^='video.'],a[data^='pdf.']", this).each(function() {
                $(this).attr('href', '#' + $(this).attr('data')).click(function() {
                    Drupal.behaviors.h5p_connector_api.event.redirect($(this).attr("data"));
                    return false;
                })
            });
        }); 
    }; 
    
}(jQuery));


(function($) {
    Drupal.behaviors.h5p_connector_api = {
        /*wenn h5p geladen hat, wird der uebergebene callback ausgefuehrt*/
        onH5Pready: function(callback)
        {
            (typeof H5P !== 'object' || typeof H5P.instances !== 'object' || H5P.instances.length === 0) ? setTimeout(Drupal.behaviors.h5p_connector_api.onH5Pready, 1000, callback) : callback();
        }
    };
    Drupal.behaviors.h5p_connector_api.text = {
        regex_pdffeature: /(seite|page|site|p|pp|folie)\s*(\d+)/igm,
        /*VIDEO-MARKE Pflicht: %startzeichen, optional 1 digit und :, optional 0 - 5 und pflicht ein digit und :
         * dann pflicht 0 - 5 und ein digit und : und dann  %not-a gefolgt von %endzeichen
         * %startzeichen = leerzeichen, zeilenstart, html-Zeichen > oder  &nbsp;
         * %not-a = Nicht die kombination </a um Doppel-Replacements zu vermeiden
         * %endzeichen = komma, punkt , leerzeichen , &nbsp; zeilenende oder html-Zeichen <
         * match auf  %startzeichen, zeitstamp und %endzeichen. /greedy, multiline*/
        regex_timestampfeature: /( |^|>|&nbsp;)((?:\d:){0,1}[0-5]{0,1}\d:[0-5]\d)(?!<\/a)([\,\. ]|&nbsp;|$|<)/gm,
    };

    Drupal.behaviors.h5p_connector_api.event = {
        /*erstellt neuen hash und redirected die url*/
        redirect: function(newfragment) {
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

            // console.debug(hash, new_hash);
            window.location = new_hash;
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
        processHash: function()
        {
            var hash = window.location.hash;
            var matches = this.splitHash(hash);

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
        attach: function(context, settings) {


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
            //wird das erste genommen. schöner waere es aber mit der ID, die oben geliefert wird. delay oder sowas..
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
            if (typeof videojsonparsed === 'undefined' || typeof videojsonparsed.interactiveVideo === 'undefined' || (typeof videojsonparsed.interactiveVideo.interactions === 'undefined' && typeof videojsonparsed.interactiveVideo.assets.interactions === 'undefined'))
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
            //  console.debug(H5P.instances[0]);
            var video_object = this.getH5P();
            var click_delay = 100;
            video_object.video.seek(timestamp);

            //wenn video schon abspielt muss man keinen klick simulieren. sonst schon.
            if ((this.getH5PVersion() == 1.0) && !video_object.video.isPlaying()
                    || (this.getH5PVersion() > 1.0) && (video_object.video.parent.currentState > 1)) //1 == playing, 2 == pause 5 = nicht gestartet
            {
                //ist auf pause, auf play setzen (pause bedeutet, video ist pausiert, bei klick startets wieder)
                setTimeout(function() {
                    jQuery(video_object.$container).find(".h5p-pause")[0].click();

                }, click_delay);
                //und wieder auf pause (viceversa))
                setTimeout(function() {
                    //ist NICHT pausiert, dann auf Pause drücken
                    if (jQuery(video_object.$container).find(".h5p-pause").length == 0)
                    {
                        jQuery(video_object.$container).find(".h5p-play")[0].click();
                    }
                    video_object.video.seek(timestamp);
                }, click_delay * 2);
            }

        },
        humanizeTime: function(timeinsecs)
        {
            return H5P.InteractiveVideo.humanizeTime(timeinsecs);
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

jQuery(window).on('hashchange', function(e) {
    //nach umleitung auf hash: entsprechende befehle durchführen
    Drupal.behaviors.h5p_connector_api.event.processHash();
});

/*verlinkt man auf ein video und ein hash ist in der adresszeile soll der beim seiteladen ausgefuehrt werden*/
jQuery(document).ready(function() {
    Drupal.behaviors.h5p_connector_api.onH5Pready(function() {
        Drupal.behaviors.h5p_connector_api.event.processHash();
    });
});