(function ($) {
    
    Drupal.behaviors.section_courses = {
        attach: function (context, settings) {
           //....
        }
    };

    
    Drupal.behaviors.section_courses.menu = {
        //die Links im Kursmenü haben ein default-Ziel. der Link soll nicht auf eine andere Seite führen, wenn wir ins Menü klicken.
        stopLinkExecutionForMenuentries: function ()
        {
            $("div#instructor-tools li[data-toggle=collapse]").click(function (e)
            {
                event.preventDefault();
            });
        }
    };

}(jQuery));



jQuery(document).ready(function() {
    Drupal.behaviors.section_courses.menu.stopLinkExecutionForMenuentries();
});

