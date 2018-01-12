/**
 * detectiert changes in forms und warnt vor Verlassen der Seite
 */
jQuery(document).ready(function() {
    var form_was_modified = false;

    //Besonderheit: form_was_modified wird nur einfach gesetzt. 
    //ckeditor-changes greifen generell und nicht auf form-IDs
    //Beim Verlassen der Seite genügt ein einzelnes changed-Flag um eine Warnung auszulösen
    var ckinstances_list = new Array;
    if (typeof CKEDITOR !== 'undefined')
        ckinstances_list = CKEDITOR.instances;

    var ck_exists = false;
    //falls CKEditor geladen, dann
    if (Object.keys(ckinstances_list).length > 0)
    {
        ck_exists = true;
        jQuery.each(ckinstances_list, function(index, value) {
            value.on('change', function(evt) {
                form_was_modified = true;
            });
        });


    }

    jQuery.each(Drupal.settings.changediscard, function(form_id, settings) {

        // alert(form_id);
        //  alert(settings);


        if (ck_exists || settings.override_ck) {
            //alert("change detector for " + form_id);
            //form change: modified true
            jQuery('form#' + form_id).change(function() {
                form_was_modified = true;
            })      //submit button clicked: modified = false
                    .find("button, input[type=submit]").click(function() {
                form_was_modified = false;
            });
        }


    });
    //page-leave-funktion
    window.onbeforeunload = changediscard_warning_confirm_page_leave;
    function changediscard_warning_confirm_page_leave() {
        if (form_was_modified) {
            //text ist egal. browser-default-confirm geht auf
            return "New information not saved. Do you wish to leave the page?";
        }
    }


});