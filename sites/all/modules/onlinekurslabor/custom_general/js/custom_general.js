(function($) {

    Drupal.behaviors.custom_general = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {

            var temp_toolbar_width = 0;
            $('#instructors_tools-container').once('custom_general').mouseenter(function() {
                //cache base width
                if (temp_toolbar_width == 0)
                    temp_toolbar_width = $('#instructors_tools-container').width();

                $('#instructors_tools-toolbar').stop(false, true);

                $('#instructors_tools-container').css('overflow', 'visible');
                $('#instructors_tools-container').width(180);

            }).mouseleave(function() {

                $('#instructors_tools-toolbar').stop(false, true);

                $('#instructors_tools-container').width(temp_toolbar_width);
                $('#instructors_tools-container').css('overflow', 'hidden');
                //$('#instructors_tools-container').animate({ width: temp_toolbar_width }, 'fast');
            });
            
            $('#authors_tools-container').once('custom_general').mouseenter(function() {
                //cache base width
                if (temp_toolbar_width == 0)
                    temp_toolbar_width = $('#authors_tools-container').width();

                $('#instructors_tools-toolbar').stop(false, true);

                $('#authors_tools-container').css('overflow', 'visible');
                $('#authors_tools-container').width(180);

            }).mouseleave(function() {

                $('#instructors_tools-toolbar').stop(false, true);

                $('#authors_tools-container').width(temp_toolbar_width);
                $('#authors_tools-container').css('overflow', 'hidden');
                //$('#authors_tools-container').animate({ width: temp_toolbar_width }, 'fast');
            });

            
            /*
             $('#instructors_tools-container a').once('custom_general').mouseenter(function(){
             
             var text = "";
             if($(this).data('title_text') === undefined)
             {
             text = $(this).attr('title');
             $(this).data('title_text', text);
             $(this).removeAttr("title");
             }else
             {
             text = $(this).data('title_text');
             }
             
             //$('#instructors_tools-toolbar').text(text);
             //$('#instructors_tools-toolbar').stop(false, true);
             //$('#instructors_tools-toolbar').toggle(200);
             
             $('#instructors_tools-toolbar').text(text);
             $('#instructors_tools-toolbar').css({
             left: $(this).parent().position().left
             });
             $('#instructors_tools-toolbar').stop(false, true);
             $("#instructors_tools-toolbar").slideDown(250);
             
             }).mouseleave(function(){
             $('#instructors_tools-toolbar').stop(false, true);
             $('#instructors_tools-toolbar').slideUp(250);
             });
             */

            var pb_val = ($('#course_progressbar').text() * 100);
            $('#course_progressbar').text("");

            $('#course_progressbar').progressbar(
                    {
                        value: pb_val
                    }
            );


            /*.mouseleave(function(){
             $('#instructors_tools-toolbar').stop(false, true);
             $('#instructors_tools-toolbar').toggle(700);
             });*/


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