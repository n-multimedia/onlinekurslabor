(function($) {

    Drupal.behaviors.custom_general = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {
            
            /*
             * Media
             */
            /*
             * Video resizing
             */
            var iframe = $('.row .col-md-12 iframe');

            if (iframe.length >= 1) {
                for (var i = 0; i < iframe.length; i++) {
                    iframetmp = $(iframe[i]);
                    if (iframetmp.width() < 400) {
                        var row = $(iframetmp).wrap('<div class="row" />').addClass("col-md-6").parent();

                        row.append('<div class="col-md-3" />');
                        row.prepend('<div class="col-md-3" />');
                        //26.02.2014 - 15:55 - SN
                        //videos to tiny, -> expanding height
                        iframetmp.height(iframetmp.height()+70);

                    } else if (iframetmp.width() < 500) {
                        var row = $(iframetmp).wrap('<div class="row" />').addClass("col-md-8").parent();

                        row.append('<div class="col-md-2" />');
                        row.prepend('<div class="col-md-2" />');
                        //26.02.2014 - 15:55 - SN
                        //videos to tiny, -> expanding height
                        iframetmp.height(iframetmp.height()+20);

                    } else {
                        $(iframetmp).addClass("col-md-12").wrap('<div class="row" />');
                    }
                }

            } else {

                if (iframe.width() < 400) {
                    var row = $(iframe).wrap('<div class="row" />').addClass("col-md-8").parent();

                    row.append('<div class="col-md-2" />');
                    row.prepend('<div class="col-md-2" />');
                } else if (iframe.width() < 500) {
                    var row = $(iframe).wrap('<div class="row" />').addClass("col-md-6").parent();

                    row.append('<div class="col-md-3" />');
                    row.prepend('<div class="col-md-3" />');
                } else {
                    $(iframe).addClass("col-md-12").wrap('<div class="row" />');
                }
            }

            /*
             * progress bar
             */

            $(".knob").knob({
                'change': function(value) {
                    return false;
                }
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