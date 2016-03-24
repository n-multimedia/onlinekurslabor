
(function($) {
    Drupal.behaviors.h5p_connector_api = {
        /*wenn h5p geladen hat, wird der uebergebene callback ausgefuehrt*/
        onH5Pready: function(callback)
        { 
            (typeof H5P !== 'object' || typeof H5P.instances !== 'object' || H5P.instances.length === 0) ? setTimeout(Drupal.behaviors.h5p_connector_api.onH5Pready, 1000, callback) : callback();
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
            var videojson =   H5PIntegration.contents['cid-'+this.getH5P_ID()];

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

        }

    }
}(jQuery));

