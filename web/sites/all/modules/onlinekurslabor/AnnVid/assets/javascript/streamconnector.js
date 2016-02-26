(function ( $ ) {
    
    var renderer;
 //$//(".nm_stream .nm-stream-main-body").makeStreamClickable()
    $.fn.markFeaturesInStream = function( options ) {
        //geht durch kommentare
        $(this).each(function( index ) {
                var comment = $(this).html();
                //http://stackoverflow.com/questions/1494671/regular-expression-for-matching-time-in-military-24-hour-format
               
                
                 /*ersetze Seite 8 (etc) durch Link Seite 8 */
                    comment = comment.replace(Drupal.behaviors.annvid.stream.regex_pdffeature , "<a href=\"#pdf.$2\" data=\"pdf.$2\">$1 $2</a>");
                /*VIDEO-MARKE  */ 
                  comment = comment.replace(Drupal.behaviors.annvid.stream.regex_timestampfeature , function(s,m1,m2,m3){return m1+"<a  href=\"#video."+Drupal.behaviors.annvid.video.computerizeTime(m2)+"\" data=\"video."+Drupal.behaviors.annvid.video.computerizeTime(m2)+"\">"+m2+"</a>"+m3;}); 
                  
                  
                 //console.debug(comment);
                //  console.debug("Beispiel auf Seite 8 und Page  10 ".replace(/(seite|page|site)\s*(\d*)/ig , "<a data=\"pdf:$2\">$1 $2</a>"))
                //console.debug("Marie finden wir um 4:30 , 15:30 und 1:30:14".replace(/( )((?:\d:){0,1}[0-5]{0,1}\d:[0-5]\d)([\,\. ]|$)/gm, "$1<a data=\"video:$2\">$2</a>$3"));
                $(this).html(comment);
                //jetzt die neu erstellten links mit click-event versehen
                 $(this).makeFeaturesClickable();
               // $("a[data^='pdf.']", this).makeFeaturesClickable();//.click(function(){Drupal.behaviors.annvid.redirect($(this).attr("data")); return false; });
                //$("a[data^='video.']", this).makeFeaturesClickable(); // click(function(){Drupal.behaviors.annvid.redirect($(this).attr("data")); return false; });
        });
    
        //console.debug(comment);
    };
      $.fn.makeFeaturesClickable = function( options ) {
         $("a[data^='pdf.']", this).click(function(){Drupal.behaviors.annvid.redirect($(this).attr("data")); return false; });
          $("a[data^='video.']", this).click(function(){Drupal.behaviors.annvid.redirect($(this).attr("data")); return false; });
    };
}( jQuery ));

(function($) {
    Drupal.behaviors.annvid.stream = {
        attach: function(context, settings) { 
            jQuery(".nm_stream .nm-stream-main-body",context).markFeaturesInStream();
            jQuery(".nm-stream-comment .nm-stream-main-body",context).markFeaturesInStream();;
            jQuery(".nm-stream-node-form").html("Beispiel: Ab 14:30 wird Seite 8 im Skript erklärt");
        },
         active_annotations: new Array(),
         timeline_div_id : "#stream_timeline",
         timeline_timemark_id : "#timemark",
         /*PDF-SEITE (Seite etc als Pflichtmatch)optionale Leerzeichen Pflicht-Digit als match, md.1 , /insensitive, greedy multiline*/
         regex_pdffeature: /(seite|page|site|p|pp|folie)\s*(\d+)/igm ,
          /*VIDEO-MARKE Pflicht: %startzeichen, optional 1 digit und :, optional 0 - 5 und pflicht ein digit und :
                 * dann pflicht 0 - 5 und ein digit und : und dann  %not-a gefolgt von %endzeichen
                 * %startzeichen = leerzeichen, zeilenstart oder html-Zeichen >
                 * %not-a = Nicht die kombination </a um Doppel-Replacements zu vermeiden
                 * %endzeichen = komma, punkt , leerzeichen , zeilenende oder html-Zeichen <
                 * match auf  %startzeichen, zeitstamp und %endzeichen. /greedy, multiline*/ 
         regex_timestampfeature:/( |^|>)((?:\d:){0,1}[0-5]{0,1}\d:[0-5]\d)(?!<\/a)([\,\. ]|$|<)/gm ,
        highlightAnnotations: function(at_time_in_secs)
        {
            //suche annotations, die den timestamp zu at_time_in_secs  beinhalten
            var regex_time = new RegExp("( |^|>)(" + Drupal.behaviors.annvid.video.humanizeTime(at_time_in_secs) + ")(?!<\/a)([\,\. ]|$|<)", "gm");
            var annolist = jQuery(".nm_stream .nm-stream-main-body").filter(function () {
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
        getAllEntriesWithTimecode: function()
        {
            var entries = new Array();
            var counter = 0;

            jQuery(".nm-stream-node, .nm-stream-comment").each(function(index) {
                if (jQuery("a[data^='video.']", this).length)
                {
                    entries[counter] = new Array();
                    entries[counter]["img"] = jQuery(".field-name-field-photo  img", this).attr("src");
                    entries[counter]["time"] = Drupal.behaviors.annvid.video.computerizeTime(jQuery("a[data^='video.']", this).html());
                    var anno_text = jQuery(".nm-stream-main-body",this).text().replace(/(\r\n|\n|\r)/gm,"").replace(Drupal.behaviors.annvid.stream.regex_timestampfeature," ");;
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
        createStreamTimeline: function()
        {
            var jqdiv = jQuery(this.timeline_div_id);



            var pixelspersec = this.getPixelsPerSecond();

            var allannotations = this.getAllEntriesWithTimecode();
            var html = "<div id=timemark></div>";
            jQuery(allannotations).each(function(index, value) {
                // -10 um bildmitte zu treffen, bild = 20x20
                var offset = Math.floor(value["time"] * pixelspersec) - 10;
                var href = "#video." + value["time"];
                
                html += "<a data=\"" + href + "\" href=\"" + href + "\" title=\""+value["text"]+"\"><img src=" + value["img"] + " class=\"timeline_profile\" style=\"left:  " + offset + "px;\"></a>";

            })
            jqdiv.html(html);
            jqdiv.makeFeaturesClickable();
        },
        repositionTimemark:function(at_time_in_secs)
        {
                    
            var pixelspersec = this.getPixelsPerSecond();
            var position = Math.floor(at_time_in_secs * pixelspersec);
            jQuery(this.timeline_timemark_id).css("margin-left", position);
        },
        /*private*/
        getPixelsPerSecond: function()
        {  var jqdiv = jQuery(this.timeline_div_id);
            var width = jqdiv.css('width');
            width = width.replace("px","");
            var video = Drupal.behaviors.annvid.video.getVideoObject();
 
             var videolength = video.object.video.getDuration();
                      
            var pixelspersec = Math.floor(width) / Math.floor(videolength) ;
            return pixelspersec;
        }
        
    
          
    }
}(jQuery));
 
 
  jQuery(document).on("videotimechanged", function(e){ 
               Drupal.behaviors.annvid.stream.highlightAnnotations(e.message);
                Drupal.behaviors.annvid.stream.repositionTimemark(e.message);
                });