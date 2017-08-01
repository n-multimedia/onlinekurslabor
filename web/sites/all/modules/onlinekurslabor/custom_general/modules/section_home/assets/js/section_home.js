/**
 * Ändert Verhalten des Form-Reset-Buttons auf /home in der Kurssuche
 */


(function($) {

    Drupal.behaviors.section_home = {
        //attach wird bei jedem nachladen aufgerufen
        attach: function(context, settings) {
            /*add toggle-behaviour to searchform*/
            //aktiviere searchform bei ajax
            $("form#views-exposed-form-courses-kurse-bersicht-my-courses-small").addClass("collapse in");
        }
    };

    //außerhalb drupal-scope
    // nur einmalig beim Laden der Seite soll die searchform versteckt werden
    $(document).ready(function() {
        //initial form ausblenden
        $("form#views-exposed-form-courses-kurse-bersicht-my-courses-small").removeClass("in");
    });

}(jQuery));