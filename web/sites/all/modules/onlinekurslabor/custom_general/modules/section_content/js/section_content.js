
(function ($) {

  Drupal.behaviors.section_content = {
    attach: function (context, settings) {
      //....
    }
  };

  Drupal.behaviors.section_content.menu = {
    //die Links im Autorenmenue haben ein default-Ziel. der Link soll nicht auf eine andere Seite führen, wenn wir ins Menü klicken.
    stopLinkExecutionForMenuentries: function ()
    {
      $("div#authoring-tools li[data-toggle=collapse]").click(function (e)
      {
        event.preventDefault();
      });
    }
  };

}(jQuery));



jQuery(document).ready(function() {
  Drupal.behaviors.section_content.menu.stopLinkExecutionForMenuentries();
});
