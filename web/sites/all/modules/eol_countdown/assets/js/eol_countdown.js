
(function ($) {
    Drupal.behaviors.eol_countdown = {
        attach: function (context, settings) {


        },
        /**
         * whitens the screen and shows a message.
         * @returns {undefined}
         */
        whiteout_screen: function ()
        {

            jQuery("body").append('<div class="eol_countdown_modal"><div class="eol_countdown_centered_box">' + Drupal.settings.eol_countdown.whiteout_message + '</div></div>');
            jQuery(".eol_countdown_modal").fadeIn(2000, function () {
                jQuery(".eol_countdown_modal .eol_countdown_centered_box").animate(
                        {fontSize: "2.7em",
                            opacity: 1,
                            width: "50%"
                        }, 2000,
                        Drupal.behaviors.eol_countdown.heartbeat
                        );
            }, );
        },
        /**
         * pulsates the message on the white screen
         * @returns {undefined}
         */
        heartbeat: function ()
        {
            Drupal.behaviors.eol_countdown.heartbeat_helper();
            setInterval(function () {
                Drupal.behaviors.eol_countdown.heartbeat_helper();
            }, 1500);
        },
        heartbeat_helper: function ()
        {
            jQuery(".eol_countdown_modal .eol_countdown_centered_box").animate(
                    {
                        opacity: 0.3
                    }, 700).animate(
                    {
                        opacity: 0.9
                    }, 700);
            ;
        }
    }
}(jQuery));
