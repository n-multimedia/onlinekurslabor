

(function ($) {

    Drupal.behaviors.lehet_ouzo = {
        /*toggle solution for qaa questions*/
        attach: function (context, settings) {
            var outline_tree = $('.panels-flexible-column-first ul.menu').first();
            var search_wrapper = $("#outline-search-element");
            //$(".panels-flexible-column-first ul.menu").treemenu();
            search_wrapper.once('lehet_ouzo', function () {
 

               search_wrapper.after('<a id="lehet_ouzo_open" href="#lehet_ouzo_popup" data-toggle="modal">LeHet-Schlagwörter wählen</a><hr>');


                /*Submit-Aktion für Lehet-Kategorien-Form*/
                jQuery("#lehet-ouzo-filter").submit(function () {
                    //values of the form
                    var selected_values = jQuery(this).serializeArray();
                    var selected_string = "";
                    jQuery(selected_values).each(function ()
                    {
                        selected_string += this.value + " ";
                    });
                    selected_string = selected_string.trim();
                    /*console.debug("Submit!");
                     console.debug(selected_values);
                     console.debug(selected_string);*/
                    jQuery("#lehet_ouzo_popup").modal("hide");
                    jQuery("#countent-outline-search").val(selected_string);
                    jQuery("#countent-outline-search").keyup();
                    return false;
                });

            });
        }


    }

}(jQuery));
 