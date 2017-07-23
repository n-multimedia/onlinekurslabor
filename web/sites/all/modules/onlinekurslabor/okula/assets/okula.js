
/*
 * ersetzt description auf der startseite
 */
jQuery(document).ready(function() {
    jQuery("div.navbar-header a.navbar-brand img").attr("src",Drupal.settings.okula.base_path+"/assets/images/okula.png").css("background-repeat","no-repeat");
    jQuery("#startpage-okl-description").html('<h2 style="color:#651118;">Onlinekurslabor</h2>'+
            '<h4 style="color:#651118;">Die Lehr-Lernplattform mit Biss</h4>'
+'<p style="text-align:justify;">Das Onlinekurslabor (<b>okula</b>) ist eine digitale Lernplattform des Medienlabors für Studierende, Hochschullehrende und Partnerorganisationen.</p>'
+'<p style="text-align:justify;">Im Fokus liegen insbesondere erfahrungsorientiertes und forschendes Lernen in realen Projekten. Hier werden Ihnen virtuelle Werkzeuge zur Begleitung der Präsenzlehre, zur Erstellung von E-Learning-Kursen und zur Organisation von Projektseminaren bereitgestellt.</p>'
+'<p>&nbsp;</p>');
jQuery(".okl-home-container").css("background-image", 'url("'+Drupal.settings.okula.base_path+'/assets/images/bg-start.png")').css("background-attachment","fixed");
});


 