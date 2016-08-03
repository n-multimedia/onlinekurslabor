(function($) {

  Drupal.behaviors.section_domains = {

    attach: function(context, settings) {
      $(".nav_tabbox .tab").click(function()
      {
        var lastClass = $(this).attr('class').substr( $(this).attr('class').lastIndexOf(' ') + 1);
        $('.tabpanel').removeClass('active');
        $('.tabpanel.' + lastClass).addClass('active');
        $('.tab').parent('div').removeClass('active');
        $(this).parent('div').addClass('active');
        
        
        return false;
      });
            
    }
  };



}(jQuery));