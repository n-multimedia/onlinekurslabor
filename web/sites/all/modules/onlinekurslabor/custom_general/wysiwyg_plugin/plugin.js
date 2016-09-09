 

// Create the dialog namespace.
Drupal.custom_general = Drupal.custom_general || {};
Drupal.custom_general.biblioDialogButtons = Drupal.custom_general.biblioDialogButtons || {};

(function($) {
  

  CKEDITOR.plugins.add( 'custom_general_plugin', {
      icons:'biblio',
    init: function( editor ){
         editor.addCommand( 'biblio_command', new CKEDITOR.dialogCommand( 'biblioDialog' ) );
      editor.ui.addButton( 'biblio_button', {
        label: 'Biblio', //this is the tooltip text for the button
        command: 'biblio_command',
       icon: this.path + 'images/biblio.gif',
      toolbar: 'insert'
      });
   
// Register our dialog file -- this.path is the plugin folder path.
CKEDITOR.dialog.add( 'biblioDialog', this.path + 'dialogs/biblio.js' );
    }
  });


})(jQuery);

 
 