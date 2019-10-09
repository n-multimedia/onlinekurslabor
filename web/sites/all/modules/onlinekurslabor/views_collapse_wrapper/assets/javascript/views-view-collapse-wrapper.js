
(function ($) {

    /**
     * collapse_wrapper-behaviour
     */
    Drupal.behaviors.collapse_wrapper = {
        /*Auf großen Devices ist wrapping deaktiviert. Dann sollen auch alle Layer verschwinden.
         Ansonsten soll der Layer "collapsed" gesetzt werden.*/
        handleWrapperLayout: function ()
        {
            //if no collapse active
            if ($("#views-view-collapse--button").is(":hidden"))
            {
                //scrollheight = tatsächliche content-length
                var div_height = $(".views-view-collapse-wrapper--collapse-container").get(0).scrollHeight;
                $(".views-view-collapse-wrapper--collapse-container").animate({"maxHeight": div_height}, 400);
            } else //collapse active
            {
                $(".views-view-collapse-wrapper--collapse-container").removeAttr("style");
                $(".views-view-collapse-wrapper--collapse-container").addClass("collapsed");
            }
        }
    }

})(jQuery);
jQuery(document).ready(function () {

    //ggf. wrapper verstecken / zeigen
    Drupal.behaviors.collapse_wrapper.handleWrapperLayout();
    jQuery(window).on('resize', function () {
        Drupal.behaviors.collapse_wrapper.handleWrapperLayout();
    });

    //activate "show-more"-button
    jQuery("#views-view-collapse--button").click(function () {
        //scrollheight = tatsächliche content-length
        var div_height = jQuery(".views-view-collapse-wrapper--collapse-container").get(0).scrollHeight;
        jQuery(".views-view-collapse-wrapper--collapse-container").animate({"maxHeight": div_height}, 400);
        jQuery(".views-view-collapse-wrapper--collapse-container-hover").slideToggle();
        jQuery(this).slideToggle();
    });

});

