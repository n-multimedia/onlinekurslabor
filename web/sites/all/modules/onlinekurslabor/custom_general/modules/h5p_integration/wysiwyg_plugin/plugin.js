
// Create the dialog namespace.
Drupal.h5p_integration = Drupal.custom_general || {};
Drupal.h5p_integration.h5pDialogButtons = Drupal.h5p_integration.h5pDialogButtons || {};


/*we need drupal.t here so that the strings are available*/
Drupal.t("Insert timestamp-area");
Drupal.t('Written timestamps in this area will automatically be converted to links');
   
(function($) {
  

  CKEDITOR.plugins.add( 'h5p_integration', {
      icons:'h5p',
    init: function( editor ){
           
         editor.addCommand( 'h5p_command', new CKEDITOR.dialogCommand( 'h5pDialog' ) );
      editor.ui.addButton( 'h5p_button', {
        label: 'h5p', //this is the tooltip text for the button
        command: 'h5p_command',
       icon: this.path + 'images/h5p.gif',
      toolbar: 'insert'
      });
   
// Register our dialog file -- this.path is the plugin folder path.
CKEDITOR.dialog.add( 'h5pDialog', this.path + 'dialogs/h5p.js' );
    }
  });


})(jQuery);
