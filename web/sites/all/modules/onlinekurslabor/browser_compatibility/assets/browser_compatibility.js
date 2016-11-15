// A $( document ).ready() block.
jQuery( document ).ready(function() {
    if(browser_compatibility_getIEVersion() === 11)
    {
        jQuery(".browser_compatibility_custom_message").show();
        jQuery(".browser_compatibility_warning_affected_browser").html("Internet Explorer 11");
        jQuery(".browser_compatibility_warning_details").html("<ul><li>Das Bearbeiten von Text funktioniert nicht vollständig.</li></ul>")
    }
});

/**
 * checks if ie
 * @returns {Number} ie-version or 0 if not ie
 */
function browser_compatibility_getIEVersion() {
  var sAgent = window.navigator.userAgent;
  var Idx = sAgent.indexOf("MSIE");

  // If IE, return version number.
  if (Idx > 0) 
    return parseInt(sAgent.substring(Idx+ 5, sAgent.indexOf(".", Idx)));

  // If IE 11 then look for Updated user agent string.
  else if (!!navigator.userAgent.match(/Trident\/7\./)) 
    return 11;

  else
    return 0; //It is not IE
}