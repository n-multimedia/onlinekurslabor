 

(function($) {
    Drupal.behaviors.annvid.stream = {
        
        //die container für userinput (mit bild etc)
        stream_annotations_containers: "div#stream .front > .stream-post, div#stream .front > .stream-comment",
        //worin der eigentliche text des userinputs steht
        stream_annotations_containers_textholders: ".field-name-body, .field-name-comment-body",
        
        currently_highlighted_annotations: new Array(),
        timeline_div_id : "#stream_timeline",
        timeline_timemark_id : "#timemark",
        
        attach: function(context, settings) {
           
            jQuery(this.stream_annotations_containers, context).find(this.stream_annotations_containers_textholders).convertTextToLinks();
            jQuery("textarea.stream-post-body").attr("placeholder","Beispiel: Ab 14:30 wird Seite 8 im Skript erklärt");

            //prefille textareas bei focus darauf
            jQuery("textarea.stream-post-body, textarea.stream-comment-body").focus(function()
            {   
                //nur bei leerer textarea
                if (jQuery(this).val() === "")
                {   
                    //weiß nicht, warum timeout jetzt nötig ist. irgendwie resetted sich die form
                    var input_object = this;
                    var input_text = "Um " + Drupal.behaviors.h5p_connector_api.av_player.getCurrentTime(true) + " ";
                    setTimeout(function () {
                        jQuery(input_object).val(input_text);
                    }, 100); 
                }

            });
            
            //erstellen neuer eintrag: setze ggf. highlight drauf
            this.highlightAnnotations(Drupal.behaviors.h5p_connector_api.av_player.getCurrentTime(false));
            
            //klick auf anhang: neuer tab um video nicht zu killen
            //nicht mehr funktional und grad nicht nötig.. vielleicht todo.. jQuery("span.file a", context).attr("target", "_blank");

            
            //Fehler beim ersten Aufruf, deswegen Video abwarten.. 
            Drupal.behaviors.h5p_connector_api.av_player.onAVReady(function() {
                //fuelle timeline neu
                Drupal.behaviors.annvid.stream.fillStreamTimeline();
                //setze fortschrittbalken auf letzten bekannten wert
                Drupal.behaviors.annvid.stream.repositionTimemark(Drupal.behaviors.h5p_connector_api.av_player.getCurrentTime(false));
            });

        },
        detach: function(context) {
             //fuelle timeline neu
             Drupal.behaviors.annvid.stream.fillStreamTimeline();
              //setze fortschrittbalken auf letzten bekannten wert
             Drupal.behaviors.annvid.stream.repositionTimemark(Drupal.behaviors.h5p_connector_api.av_player.getCurrentTime(false));
         },
         /**
          * highlighted stream-eintraege zur übergebenen zeitmarke
          * @param {int} at_time_in_secs
          *
          */
        highlightAnnotations: function(at_time_in_secs)
        {
            //suche annotations, die den timestamp zu at_time_in_secs  beinhalten
            //da wir mit .text() statt .html() arbeiten, tuts eine einfachere regex. Anfang und Ende immer some-char, in der Mitte der Match auf Zeit.
            var regex_string = "(?:[\,\.\-\; \?\s]|^|<)(" + Drupal.behaviors.h5p_connector_api.av_player.humanizeTime(at_time_in_secs) + ")(?:[\,\.\-\; \?\s]|$|<)";
            //das "g" in Regex ist böse und verschiebt bei erstem Match intern nen index. Weitere Tests schlagen dann fehl....
            var regex_time = new RegExp(regex_string, "m");
            var annolist;
            
            //sammle annotation die den current timestamp haben. .grep() > filter()
            annolist = jQuery.grep(jQuery(this.stream_annotations_containers), function (annotation_element) {
                return regex_time.test($(annotation_element).text());
            });

            if (annolist.length > 0)
            {
                //entferne highlight aus alter liste
                jQuery.each(this.currently_highlighted_annotations, function (index, value) {
                    jQuery(value).removeClass("annotation_highlighted");
                    jQuery(value).parents(".card-flip").removeClass("annotation_container_highlighted");
                });
                //setze annotation highlighted
                jQuery.each(annolist, function (index, value) {
                    jQuery(value).parents(".card-flip").addClass("annotation_container_highlighted");
                    jQuery(value).addClass("annotation_highlighted");

                });
                this.currently_highlighted_annotations = annolist;
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
            var class_object = this; 
            jQuery(this.stream_annotations_containers).each(function(index) {
                if (jQuery("a[data^='video.']", this).length)
                {
                    entries[counter] = new Array();
                    entries[counter]["img"] = jQuery("img.card-img-top", this).attr("src");
                    entries[counter]["time"] = Drupal.behaviors.h5p_connector_api.av_player.computerizeTime(jQuery("a[data^='video.']", jQuery(this).find(class_object.stream_annotations_containers_textholders)).html());
                    //Entferne emptychars, entferne einzelnes "Um " am Textanfang, entferne Timestamp 
                    var anno_text = jQuery(class_object.stream_annotations_containers_textholders, this).text().replace(/(\r\n|\n|\r)/gm,"").replace(/(^Um )/gm,"").replace(Drupal.behaviors.h5p_connector_api.text.regex_timestampfeature,"");;
                    if(anno_text.length >30)
                    {
                        anno_text = anno_text.substr(0,27)+"...";
                    }
                    anno_text = Drupal.checkPlain(anno_text);
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
            //-12 um genau Ende + Border des timelinecontainers zu erwischen
            var max_anno_offset = this.getTimelineWidth()-12;
            jQuery(allannotations).each(function(index, value) {
                //Math.min um nicht drueber hinauszuschreiben, wenn invalider timecode drin ist
                // -10 um bildmitte zu treffen, bild = 20x20
                var offset = Math.min(max_anno_offset, Math.floor(value["time"] * pixelspersec)) - 10;
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
           
            var width = this.getTimelineWidth();
            var videolength = Math.floor( Drupal.behaviors.h5p_connector_api.av_player.getDuration());

            var pixelspersec = Math.floor(width) / videolength;
            return pixelspersec;
        },
        /*private*/
        getTimelineWidth: function()
        {
              var jqdiv = jQuery(this.timeline_div_id);
            return jqdiv.css('width').replace("px", "");            
        }
        
    
          
    }
}(jQuery));
 
 
  jQuery(document).on("videotimechanged", function(e){ 
               Drupal.behaviors.annvid.stream.highlightAnnotations(e.message);
                Drupal.behaviors.annvid.stream.repositionTimemark(e.message);
                });