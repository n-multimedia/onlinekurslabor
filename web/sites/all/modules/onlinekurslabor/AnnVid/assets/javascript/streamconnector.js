 

(function($) {
    Drupal.behaviors.annvid.stream = {
        attach: function(context, settings) {
            jQuery(".nm_stream .nm-stream-main-body", context).convertTextToLinks();
            jQuery(".nm-stream-comment .nm-stream-main-body", context).convertTextToLinks();
            jQuery(".nm-stream-node-form").html("Beispiel: Ab 14:30 wird Seite 8 im Skript erklärt");
            //Fehler beim ersten Aufruf, deswegen Video abwarten.. 
            Drupal.behaviors.h5p_connector_api.interactivevideo.onVideoReady(function() {
                Drupal.behaviors.annvid.stream.fillStreamTimeline();
            });

        },
         active_annotations: new Array(),
         timeline_div_id : "#stream_timeline",
         timeline_timemark_id : "#timemark",
         /**
          * highlighted stream-eintraege zur übergebenen zeitmarke
          * @param {int} at_time_in_secs
          *
          */
        highlightAnnotations: function(at_time_in_secs)
        {
            //suche annotations, die den timestamp zu at_time_in_secs  beinhalten
            var regex_time = new RegExp("( |^|>|&nbsp;|0)(" + Drupal.behaviors.h5p_connector_api.interactivevideo.humanizeTime(at_time_in_secs) + ")(?!<\/a)([\,\. \?]|&nbsp;|$|<)", "gm");
            var annolist = jQuery(".nm_stream .nm-stream-main-body").filter(function() {
                return regex_time.test($(this).text());
            });
            if (annolist.length > 0)
            {
                jQuery.each(this.active_annotations, function(index, value) {
                    jQuery(value).removeClass("annotation_highlighted");
                    jQuery(value).parents(".nm-stream-node-container").removeClass("annotation_container_highlighted");
                });

                jQuery.each(annolist, function(index, value) {
                    jQuery(value).parents(".nm-stream-node-container").addClass("annotation_container_highlighted");
                    jQuery(value).addClass("annotation_highlighted");
                });
                this.active_annotations = annolist;
            }
        },
        /**
         * returnt ein javascript array mit annotationen und deren timecodes
         * @returns {Array}
         */
        getAllEntriesWithTimecode: function()
        {
            var entries = new Array();
            var counter = 0;

            jQuery(".nm-stream-node, .nm-stream-comment").each(function(index) {
                if (jQuery("a[data^='video.']", this).length)
                {
                    entries[counter] = new Array();
                    entries[counter]["img"] = jQuery(".field-name-field-photo  img", this).attr("src");
                    entries[counter]["time"] = Drupal.behaviors.h5p_connector_api.interactivevideo.computerizeTime(jQuery("a[data^='video.']", this).html());
                    var anno_text = jQuery(".nm-stream-main-body",this).text().replace(/(\r\n|\n|\r)/gm,"").replace(Drupal.behaviors.h5p_connector_api.text.regex_timestampfeature," ");;
                    if(anno_text.length >30)
                        anno_text = anno_text.substr(0,27)+"...";
                    entries[counter]["text"] = anno_text; 
                    counter++;

                }

            });
            entries.sort(function(a, b) {
                return a["time"] - b["time"]
            });
           
            return(entries);
        },
        /**
         * füllt die zeitleiste unterhalb des h5p mit avataren der kommentatoren
         * 
         */
        fillStreamTimeline: function()
        {
            var jqdiv = jQuery(this.timeline_div_id);



            var pixelspersec = this.getPixelsPerSecond();

            var allannotations = this.getAllEntriesWithTimecode();
            var html = "<div id=timemark></div>";
            jQuery(allannotations).each(function(index, value) {
                // -10 um bildmitte zu treffen, bild = 20x20
                var offset = Math.floor(value["time"] * pixelspersec) - 10;
                var data_str = "video." + value["time"];
                
                html += "<a data=\"" + data_str + "\" title=\""+value["text"]+"\"><img src=" + value["img"] + " class=\"timeline_profile\" style=\"margin-left:  " + offset + "px;\"></a>";

            })
            jqdiv.html(html);
            jQuery(this.timeline_div_id).makeControlLinksClickable();
          
            
        },
        /**
         * positioniert den zeitbalken in der annotation-timeline neu
         * @param {int} at_time_in_secs
         * @returns {undefined}
         */
        repositionTimemark:function(at_time_in_secs)
        {
                    
            var pixelspersec = this.getPixelsPerSecond();
            var position = Math.floor(at_time_in_secs * pixelspersec);
            jQuery(this.timeline_timemark_id).css("margin-left", position);
        },
        /*private*/
        getPixelsPerSecond: function()
        {
            var jqdiv = jQuery(this.timeline_div_id);
            var width = jqdiv.css('width').replace("px", "");
            var videolength = Drupal.behaviors.h5p_connector_api.interactivevideo.getH5P().video.getDuration();

            var pixelspersec = Math.floor(width) / Math.floor(videolength);
            return pixelspersec;
        }
        
    
          
    }
}(jQuery));
 
 
  jQuery(document).on("videotimechanged", function(e){ 
               Drupal.behaviors.annvid.stream.highlightAnnotations(e.message);
                Drupal.behaviors.annvid.stream.repositionTimemark(e.message);
                });