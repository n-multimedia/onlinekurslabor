/*
 * custom behaviour for onlinekurslabor-template
 */

jQuery(document).ready(function () {
  //nach laden der seite navigation-tooltips main-nav aktivieren
  //auf kleinen geraeten aus
  if (!window.matchMedia || (window.matchMedia("(min-width: 767px)").matches)) {
        //obey bootstrap-setting
        if (Drupal.settings.bootstrap && Drupal.settings.bootstrap.tooltipEnabled) {
            jQuery('.tooltip-top-navi').tooltip({  placement:"bottom"  } ); 
        }
  }

  // initially scroll to active menu
  var target_item = jQuery(".okl-nav-course-bar a.btn.active");
  if (target_item.length > 0 && jQuery('#section_navigation').length > 0) {
    jQuery('#section_navigation').animate({scrollLeft: target_item.offset().left}, 444);
  }


});
