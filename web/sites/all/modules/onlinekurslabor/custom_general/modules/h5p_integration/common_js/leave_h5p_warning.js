jQuery(document).ready(function() {
    h5p_form_modified = false;
    //form change: modified true
    jQuery('form#h5p-content-node-form').change(function() {
        h5p_form_modified = true;
    })      //submit button clicked: modified = false
            .find("button[type=submit]").click(function() {
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