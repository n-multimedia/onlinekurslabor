/**
 * Ändert Verhalten des Form-Reset-Buttons auf /home in der Kurssuche
 */


(function($) {

    Drupal.behaviors.section_home = {
        //attach wird bei jedem nachladen aufgerufen
        attach: function(context, settings) {

        }
    };

    //außerhalb drupal-scope
    // nur einmalig beim Laden der Seite soll die searchform versteckt werden
    $(document).ready(function() {
        /*add toggle-behaviour to searchform*/
        $("form#views-exposed-form-courses-kurse-bersicht-my-courses-small").addClass("collapse");
    });

}(jQuery));