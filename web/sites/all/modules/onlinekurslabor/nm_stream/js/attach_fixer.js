/* 
 * das vuejs.-projekt feuert kein drupal attach. das wird hier gefaket.
 * 
 */
jQuery(document).on("nm-stream:update", function (updateEvent) {
    /*das ist noch arg laggy, weil das event gefeuert wird, bevor der Content geprinted wird, teilweise zu spät gefeuert wird(Comments zeigen)*/
    Drupal.attachBehaviors(updateEvent.target, Drupal.settings);
});
     