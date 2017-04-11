jQuery(document).ready(function() {
    h5p_form_modified = false;
    jQuery('form#h5p-content-node-form').change(function() {
        h5p_form_modified = true;
    })
        //zeige info nochmal vorm save-button
            .find("button[type=submit]").before('<div class="alert alert-block alert-warning messages warning">Bei Video: Vorm Speichern auf "Interaktionen hinzufügen" klicken!</div>').click(function() {
        h5p_form_modified = false;
    });
    ;
    //page-leave-funktion
    window.onbeforeunload = h5p_integration_confirm_page_leave;
    function h5p_integration_confirm_page_leave() {
        if (h5p_form_modified) {
            //text ist egal. browser-default-confirm geht auf
            return "New information not saved. Do you wish to leave the page?";
        }
    }
});