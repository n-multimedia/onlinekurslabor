(function ($) {

    Drupal.behaviors.nm_administration_vbo_events = {

        attach: function (context, settings) {

            //27.10.2017 - 14:29 - SN
            //buggy mouseover event when using exposed form!
            //unbind all js events
            $(".vbo-views-form #edit-select .form-submit").unbind();

        }
    }


}(jQuery));