/* 
 * custom behaviour for onlinekurslabor-template
 */

jQuery( document ).ready(function() {
   //nach laden der seite navigation-tooltips main-nav aktivieren
   //auf kleinen geraeten aus
   if (!window.matchMedia || (window.matchMedia("(min-width: 767px)").matches)) {
        jQuery('.tooltip-top-navi').tooltip({  placement:"bottom"  } ); 
    }
});