
// Create the dialog namespace.
Drupal.section_content = Drupal.custom_general || {};
Drupal.section_content.tasksDialogButtons = Drupal.section_content.tasksDialogButtons || {};

(function($) {
  

  CKEDITOR.plugins.add( 'section_content_task_plugin', {
      icons:'tasks',
    init: function( editor ){
         editor.addCommand( 'tasks_command', new CKEDITOR.dialogCommand( 'tasksDialog' ) );
      editor.ui.addButton( 'tasks_button', {
        label: 'Tasks', //this is the tooltip text for the button
        command: 'tasks_command',
       icon: this.path + 'images/tasks.gif',
      toolbar: 'insert'
      });
   
// Register our dialog file -- this.path is the plugin folder path.
CKEDITOR.dialog.add( 'tasksDialog', this.path + 'dialogs/tasks.js' );
    }
  });


})(jQuery);
