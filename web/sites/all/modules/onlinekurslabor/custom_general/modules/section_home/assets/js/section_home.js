/**
 * Aktiviert collapse-Verhalten bei searchform auf /home in der Kurssuche
 * und
 * Ändert Verhalten des Form-Reset-Buttons ("Alle")
 */


(function($) {

    Drupal.behaviors.section_home = {
        //attach wird bei jedem nachladen aufgerufen
        attach: function(context, settings) {
            var searchbox_form = $("form#views-exposed-form-courses-kurse-bersicht-my-courses-small");
            /*add toggle-behaviour to searchform*/
            //aktiviere searchform bei ajax
            $(searchbox_form).addClass("collapse in");

            //neues behaviour für reset-button("alle")
            $("button#edit-reset", searchbox_form).click(function() {
                $("input#edit-course-title", searchbox_form).val("");
                $("button#edit-submit-courses-kurse-bersicht", searchbox_form).click();
                return false;
            });
        }
    };

    //außerhalb drupal-scope
    // nur einmalig beim Laden der Seite soll die searchform versteckt werden
    $(document).ready(function() {
        //initial form ausblenden
        $("form#views-exposed-form-courses-kurse-bersicht-my-courses-small").removeClass("in");
    });

}(jQuery));