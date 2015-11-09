(function ( $ ) {
    
    var renderer;
 //$//(".nm_stream .nm-stream-main-body").makeStreamClickable()
    $.fn.makeStreamClickable = function( options ) {
        //geht durch kommentare
        $(this).each(function( index ) {
                var comment = $(this).html();
                //http://stackoverflow.com/questions/1494671/regular-expression-for-matching-time-in-military-24-hour-format
               
                
                 /*ersetze Seite 8 (etc) durch Link Seite 8 */
                 /*PDF-SEITE D(Seite etc als Pflichtmatch)optionale Leerzeichen Pflicht-Digit als match, md.1 , /insensitive, greedy multiline*/
                  comment = comment.replace(/(seite|page|site|p|pp)\s*(\d+)/igm , "<a href=\"#pdf.$2\" data=\"pdf.$2\">$1 $2</a>");
                /*VIDEO-MARKE Pflicht: leerzeichen, optional 1 digit und :, optional 0 - 5 und ein digit und :
                 * dann pflicht 0 - 5 und ein digit und : und dann komma, punkt , leerzeichen oder zeilenende
                 * match auf pflichtleerzeichen, zeitstamp und abschlusszeichen. /greedy, multiline*/ 
                  comment = comment.replace(/( )((?:\d:){0,1}[0-5]{0,1}\d:[0-5]\d)([\,\. ]|$)/gm, function(s,m1,m2,m3){return m1+"<a  href=\"#video."+Drupal.behaviors.annvid.video.computerizeTime(m2)+"\" data=\"video."+Drupal.behaviors.annvid.video.computerizeTime(m2)+"\">"+m2+"</a>"+m3;}); 
                  
                  
                 //console.debug(comment);
                //  console.debug("Beispiel auf Seite 8 und Page  10 ".replace(/(seite|page|site)\s*(\d*)/ig , "<a data=\"pdf:$2\">$1 $2</a>"))
                //console.debug("Marie finden wir um 4:30 , 15:30 und 1:30:14".replace(/( )((?:\d:){0,1}[0-5]{0,1}\d:[0-5]\d)([\,\. ]|$)/gm, "$1<a data=\"video:$2\">$2</a>$3"));
                $(this).html(comment);
                //jetzt die neu erstellten links mit click-event versehen
                $("a[data^='pdf.']", this).click(function(){Drupal.behaviors.annvid.redirect($(this).attr("data")); return false; });
                $("a[data^='video.']", this).click(function(){Drupal.behaviors.annvid.redirect($(this).attr("data")); return false; });
        });
    
        //console.debug(comment);
    };
}( jQuery ));

(function($) {
    Drupal.behaviors.annvid.stream = {
        attach: function(context, settings) {


        },
         active_annotations: new Array(),
         highlightAnnotations: function(at_time_in_secs)
        {
             var annolist =     jQuery(".nm_stream .nm-stream-main-body:contains("+Drupal.behaviors.annvid.video.humanizeTime(at_time_in_secs)+")");
              if(annolist.length > 0)
               {  
                   jQuery.each(this.active_annotations, function( index, value ) {
                    jQuery(value).removeClass("annotation_highlighted");
                    });
                     jQuery.each(annolist, function( index, value ) {
                    jQuery(value).addClass("annotation_highlighted");
                    }); 
                    this.active_annotations = annolist ;
               }
        }
    
          
    }
}(jQuery));
 
  jQuery(document).on("videotimechanged", function(e){ 
               Drupal.behaviors.annvid.stream.highlightAnnotations(e.message);
                });