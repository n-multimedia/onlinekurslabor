/**
 * Aktiviert collapse-Verhalten bei searchform auf /home in der Kurssuche
 * und
 * Ändert Verhalten des Form-Reset-Buttons ("Alle")
 */


(function($) {

    Drupal.behaviors.section_home = {
        attach_counter : 0,
        //attach wird bei jedem nachladen aufgerufen
        attach: function(context, settings) {
            this.attach_counter++;
            var searchbox_form = $("form#views-exposed-form-courses-kurse-bersicht-my-courses-small");
            /*add toggle-behaviour to searchform*/
            //aktiviere searchform bei ajax
            $(searchbox_form).not(".collapse").addClass("collapse in");
            //initiales seitenladen: verstecken ( 1. attach) oder falls keine eingabe
            if(this.attach_counter <= 1 ||  $("input#edit-course-title", searchbox_form).val() == "" )
            {
                $(searchbox_form).removeClass("in");
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