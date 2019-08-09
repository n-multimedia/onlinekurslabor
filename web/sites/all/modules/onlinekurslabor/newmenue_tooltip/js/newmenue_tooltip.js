 (function($) {

    Drupal.behaviors.newmenue_tooltip = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {
            
        },
        
        clickConfirm: function()
        {
            //ausgelagert in onClick-funktion weil sonst putt
            jQuery.cookie("newmenue_tooltip_hidden", 1, {expires: 30, path: '/'});
            jQuery('#instructor_tools_toggle_button').popover("destroy")
 
        }
        
        
    };


}(jQuery));

jQuery(document).ready(function () {

    if (!jQuery.cookie("newmenue_tooltip_hidden"))
    {
        jQuery('#instructor_tools_toggle_button.collapsed').popover({html: true, content: 'Das Kursmenü finden Sie nun hier. <button type="submit" class="btn btn-primary newmenue_tooltip_confirm"  onClick="Drupal.behaviors.newmenue_tooltip.clickConfirm();" >Verstanden</button>', placement: "top", template: '<div class="popover" role="tooltip"><div class="arrow"></div><div class="popover-content"></div></div>'});
        jQuery('#instructor_tools_toggle_button.collapsed').popover("show");
       
    }

});