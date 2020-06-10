
/*
 * Functions to hide help-block when in fullscreen mode
 *  
 */
(function ($) {
    Drupal.behaviors.support_form = {
        attach: function (context, settings) {
            //nothing to do
        },
    }
}(jQuery));


jQuery(document).ready(function () {

    //Beim Event event_site_in_fullscreen wird der Hilfe-Button ein-/ausgeblendet
    jQuery(document).on("event_site_in_fullscreen", function (e) {
        var state = e.message;
        if (state) //true: fullscreen on
        {
            jQuery("#support_form_btn").fadeOut("slow");
        } else
        {
            jQuery("#support_form_btn").fadeIn("slow");
        }

    });

});
