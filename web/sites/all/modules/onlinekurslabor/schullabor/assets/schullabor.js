
/*
 * ersetzt description auf der startseite
 */
jQuery(document).ready(function() {
    jQuery("div.navbar-header a.navbar-brand img").attr("src",Drupal.settings.schullabor.base_path+"/assets/images/schullabor-logo.png").css("background-repeat","no-repeat");
});