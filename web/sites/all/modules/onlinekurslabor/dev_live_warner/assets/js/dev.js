
/*
 * fügt lustige landingpage hinzu, fügt pagelements hinzu und steuert behaviour dieser erweiterungen
 */
jQuery( document ).ready(function() {
    //fuer admin-overlay
    if(window.self !== window.top)
    {   //falls style grad nicht resetted ist, dev anzeigen
        if(window.top.jQuery("body").hasClass("dev"))
           jQuery("body").addClass("dev");
    }
    else
        jQuery("body").addClass("dev");
 jQuery("body.dev #navbar .navbar-inner").prepend('<a id="reset_style" href="#" class="pull-left">Reset Style</a>');
 jQuery("#reset_style").click(function(){jQuery(this).remove(); jQuery("body").removeClass("dev")});
 if(! (devliveplugin_readCookie("dev_overlay_skip") === "ja"))
 {
     jQuery("body").prepend('<div class="dev_overlay"><div class="dev_overlay_inner">\n\
            Hier wollten Sie nicht hin.\n\
            <br>\n\
            <a href="http://onlinekurslabor.de"><h1>Zum Onlinekurslabor</h1></a>\n\
            <br><br><br><br><br><br><br><br><br>\n\
            <a id="goto_dev">ignorieren</a></div></div>');
 }
 jQuery("#goto_dev").click(function(){devliveplugin_createCookie("dev_overlay_skip", "ja", 30);
                                      jQuery(".dev_overlay").remove();});
});


	 

function devliveplugin_createCookie(name, value, days) {
    var expires;

    if (days) {
        var date = new Date();
        date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
        expires = "; expires=" + date.toGMTString();
    } else {
        expires = "";
    }
    document.cookie = encodeURIComponent(name) + "=" + encodeURIComponent(value) + expires + "; path=/";
}

function devliveplugin_readCookie(name) {
    var nameEQ = encodeURIComponent(name) + "=";
    var ca = document.cookie.split(';');
    for (var i = 0; i < ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) === ' ') c = c.substring(1, c.length);
        if (c.indexOf(nameEQ) === 0) return decodeURIComponent(c.substring(nameEQ.length, c.length));
    }
    return null;
}