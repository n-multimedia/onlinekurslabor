/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {
    
    

    Drupal.behaviors.nm_stream_activity = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {
             /* cursor auf pointer setzen und aus-einnklappen realisieren*/
    jQuery("div.single_activity.seen").css("cursor", "pointer").once('nm_stream_activity').click(function(){
            jQuery(this).find(".seen_hidden").slideToggle();
    });

        }
    };

}(jQuery));
