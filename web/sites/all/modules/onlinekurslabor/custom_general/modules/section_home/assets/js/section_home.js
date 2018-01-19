/**
 * Aktiviert collapse-Verhalten bei searchform auf /home in der Kurssuche
 * und
 * Ändert Verhalten des Form-Reset-Buttons ("Alle")
 */


(function($) {

    Drupal.behaviors.section_home = {
 
        //attach wird bei jedem nachladen aufgerufen
        attach: function(context, settings) {

            var searchbox_form = $("form#views-exposed-form-courses-kurse-bersicht-my-courses-small", context);

            /*add toggle-behaviour to searchform*/
            searchbox_form.addClass("collapse");

            //initiales seitenladen: Inhalt leeren  
            if (context instanceof HTMLDocument)
            {
                $("input#edit-course-title", searchbox_form).val("")
            }
            //bei ajax: suchanfrage  anzeigen
            else if ($("input#edit-course-title", searchbox_form).val() != "")
            {
                $(searchbox_form).addClass("in");
            }

            //neues behaviour für reset-button("alle")
            $("button#edit-reset", searchbox_form).click(function() {
                $("input#edit-course-title", searchbox_form).val("");
                $("button#edit-submit-courses-kurse-bersicht", searchbox_form).click();
                return false;
            });
        }
    };


}(jQuery));