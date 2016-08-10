(function($) {

  Drupal.behaviors.section_projects = {

    attach: function(context, settings) {


      $(".section_navigation_cockpit .tab").click(function()
      {
        var linktarget = $(this).attr('href').substring( 1);
        $('.tabpanel').removeClass('active');
        $('.tabpanel.' + linktarget).addClass('active');
        $('.tab').removeClass('active');
        $(this).addClass('active');

      });

      $('a.noaction').click(function(){
          return false;
      });

      /*selektiere gewaehlten tab*/
       var hash = window.location.hash;
       var hashid = hash.substring(1);
       if(hashid) {
        $(".section_navigation_cockpit a." + hashid).click();
       }

        jQuery(window).on('hashchange', function(e) {
            hash = window.location.hash;
            hashid = hash.substring(1);
            if (hashid) {
                $(".section_navigation_cockpit a." + hashid).click();
            }
        });
 

      //seal logic

      $('.projects-seal-widget .action a').once('section_projects').click(function(){

        var self = $(this);
        var container = self.closest('.action');
        var href = self.attr('href');

        //ajax action
        if(href.indexOf('projects/') > 0) {

            var url = href;
            var tml_html = container.find("> a").first().html();
            var post_spinner_black;
            var opts = {
                      lines: 8, // The number of lines to draw
                      length: 2, // The length of each line
                      width: 3, // The line thickness
                      radius: 4, // The radius of the inner circle
                      corners: 1, // Corner roundness (0..1)
                      rotate: 0, // The rotation offset
                      direction: 1, // 1: clockwise, -1: counterclockwise
                      color: '#333', // #rgb or #rrggbb or array of colors
                      speed: 1.2, // Rounds per second
                      trail: 60, // Afterglow percentage
                      shadow: false, // Whether to render a shadow
                      hwaccel: false, // Whether to use hardware acceleration
                      className: 'spinner', // The CSS class to assign to the spinner
                      zIndex: 2e9, // The z-index (defaults to 2000000000)
                      top: 'auto', // Top position relative to parent in px
                      left: 'auto' // Left position relative to parent in px
            };

            if (!post_spinner_black) {
                //first call -> init spinner
                post_spinner_black = new Spinner(opts).spin();
            } else {
                post_spinner_black.spin();
            }

            container.append(post_spinner_black.el);
            //container.find(" > a").first().html(tml_html + html_spin);
            //console.log(url);

            $.ajax({
              type: "GET",
              url: url,
              success: function(response)
              {
                container.parent().html(response.data);
                Drupal.attachBehaviors(container);
                post_spinner_black.stop();

              }
            });

          return false;
        }
      });
    }
  };



}(jQuery));
