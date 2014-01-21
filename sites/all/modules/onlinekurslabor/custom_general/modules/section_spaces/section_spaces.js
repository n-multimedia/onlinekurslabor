(function($) {

  Drupal.behaviors.section_domains = {
    /*toggle solution for qaa questions*/
    attach: function(context, settings) {
      $(".nav_tabbox .tab").click(function()
      {
        var lastClass = $(this).attr('class').substr( $(this).attr('class').lastIndexOf(' ') + 1);
        $('.tabpanel').removeClass('active');
        $('.tabpanel.' + lastClass).addClass('active');
        $('.tab').parent('div').removeClass('active');
        $(this).parent('div').addClass('active');
        
        /*
        if(lastClass == "kurse") {
          console.log($(this));
          console.log($(this).parent('.span4'));
          $(this).closest('.span4').removeClass('span4').addClass('span3').next('.span8').removeClass('span8').addClass('span9');
         
        }*/
        
        return false;
      });
            
    }
  };



}(jQuery));