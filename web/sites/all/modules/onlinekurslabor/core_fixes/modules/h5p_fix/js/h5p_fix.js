/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


(function($) {

    /**
     * Utility to kill the metadata-button
     */
    Drupal.behaviors.h5p_fix = {
        /*adds an inline-css to the iframe containing the h5p-editor. 
         * The CSS hides the metadata-button*/
        register_metadata_remover: function()
        {
            Drupal.behaviors.h5p_connector_api.onH5PEditorready(function() {
                window[0].H5PEditor.$("head").append('<style>.h5p-metadata-button-wrapper{display:none;}</style>');
            });

        }
    }

})(jQuery);


jQuery(document).ready(function() {
    Drupal.behaviors.h5p_fix.register_metadata_remover();
});
