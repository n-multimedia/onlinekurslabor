
jQuery(document).ready(function() {
    jQuery("#views-view-collapse--button").click(function () {
        //scrollheight = tatsächliche content-length
        var div_height = jQuery(".views-view-collapse-wrapper--collapse-container").get(0).scrollHeight;
        jQuery(".views-view-collapse-wrapper--collapse-container").animate({"maxHeight": div_height}, 400);
        jQuery(".views-view-collapse-wrapper--collapse-container-hover").slideToggle();
        jQuery(this).slideToggle();
  
});

});

