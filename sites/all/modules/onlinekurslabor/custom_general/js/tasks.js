(function($) {

    Drupal.behaviors.section_content = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {
            $('.qaa_solution_button', context).unbind('click');
            $(".qaa_solution_button", context).click(function() {
                $(this).next().slideToggle("fast");

            });
                           
            /*
            //instructors toolbar position
            var top = $('#block-block-4 .content').offset().top - parseFloat($('#block-block-4 .content').css('marginTop').replace(/auto/, 0));

            $(window).scroll(function(event) {
                // what the y position of the scroll is
                var y = $(this).scrollTop();

                // whether that's below the form
                if (y >= top) {
                    // if so, ad the fixed class
                    $('#block-block-4 .content').addClass('fixed');
                } else {
                    // otherwise remove it
                    $('#block-block-4 .content').removeClass('fixed');
                }
            });
            */
        }
    };


}(jQuery));