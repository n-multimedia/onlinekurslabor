
// Create the dialog namespace.
Drupal.h5p_integration = Drupal.custom_general || {};
Drupal.h5p_integration.h5pDialogButtons = Drupal.h5p_integration.h5pDialogButtons || {};

(function($) {
  

  CKEDITOR.plugins.add( 'h5p_integration_plugin', {
    init: function( editor ){
      
        editor.ui.addButton( 'h5p_button', {

        label: 'Interactive Media', //this is the tooltip text for the button
        command: 'h5p_command',
        icon: this.path + 'images/h5p.gif'
      });
    
      editor.addCommand( 'h5p_command', {
        exec : function( editor ) {
          // Build the dialog element.
          // Set the editor object.
          Drupal.linkit.setEditor(editor);
          // Set which editor is calling the dialog script.
          Drupal.linkit.setEditorName('ckeditor');
          // Set the name of the editor field, this is just for CKeditor.
          Drupal.linkit.setEditorField(editor.name);

          var linkitCache = Drupal.linkit.getLinkitCache();
          // Unlock the selecton for IE.
          if (CKEDITOR.env.ie && typeof linkitCache.selection !== 'undefined') {
            linkitCache.selection.unlock();
          }

          var selection = editor.getSelection(),
          element = null;

          // If we have selected a link element, we what to grab its attributes
          // so we can inserten them into the Linkit form in the  dialog.
          /*if ((element = CKEDITOR.plugins.linkit.getSelectedLink(editor)) && element.hasAttribute('href')) {
            selection.selectElement(element);
          }
          else {
            element = null;
          }*/

          // Save the selection.
          Drupal.linkit.setEditorSelection(selection);

          var linkitCache = Drupal.linkit.getLinkitCache();

          // Lock the selecton for IE.
          if (CKEDITOR.env.ie) {
            linkitCache.selection.lock();
          }

          // Save the selected element.
          Drupal.linkit.setEditorSelectedElement(element);

          //var path = Drupal.settings.linkit.url.ckeditor;
          Drupal.linkit.dialog.buildDialog("/admin/h5p_course_interactive_content_dashbord");

          // Register an extra fucntion, this will be used in the popup.
          editor._.linkitFnNum = CKEDITOR.tools.addFunction( insertH5PTag, editor );
          
          //get focus
          $.ajax({ 
            success: function (data) { 
              $('.linkit-wrapper #edit-h5p-search').focus();
            } 
          });
          }
        /**
         * Insert the link into the editor.
         *
         * @param {Object} link
         *   The link object.
         */
        
      });
      
      function insertH5PTag(data, editor) {
        var linkitCache = Drupal.linkit.getLinkitCache(),
        selection = editor.getSelection();

        data = CKEDITOR.tools.trim(data);
        
        editor.insertHtml( '[h5p]' + data + '[/h5p]');
        
      };

    }
    
    
  });
  
  Drupal.h5p_integration.getH5PTag = function() {
    return $('#linkit-modal #edit-h5p-tag').val();
  };

  
  Drupal.behaviors.h5pDialogButtons = {
    attach: function (context, settings) {
      $('#linkit-modal #-h5p-course-integration-dashboard-form #edit-h5p-insert', context).bind('click', function() {

        var linkitCache = Drupal.linkit.getLinkitCache();
        //console.log(linkitCache);
        // Call the insertLink() function.
        Drupal.linkit.editorDialog[linkitCache.editorName].insertH5PTag(Drupal.h5p_integration.getH5PTag());
        // Close the dialog.
        Drupal.linkit.dialog.close();
        
        return false;
      });
      
      $('#linkit-modal #h5p-cancel', context).bind('click', Drupal.linkit.dialog.close);
    }
  };
  
  
  Drupal.behaviors.h5p_integration = {
    attach: function(context, settings) {

      if ($('#linkit-modal #edit-h5p-search', context).length == 0) {
        return;
      }

      Drupal.linkit.$searchInput = $('#linkit-modal #edit-h5p-search', context);
 
      // Create a "Better Autocomplete" object, see betterautocomplete.js
      //24.05.2013 - 18:07 - SN todo hardcoded path
      Drupal.linkit.$searchInput.betterAutocomplete('init',
      '/h5p_integration/item/autocomplete?s=',
      settings.linkit.autocomplete,
      { // Callbacks
        select: function(result) {
          // Only change the link text if it is empty
          if (typeof result.disabled != 'undefined' && result.disabled) {
            return false;
          }
          /*
            Drupal.linkit.dialog.populateFields({
              path: result.path
            });
           */
          $('#linkit-modal #edit-h5p-search').val(result.title);
          //23.05.2013 - 19:20 - SN : extract nid and embed with bib tags
          $('#linkit-modal #edit-h5p-tag').val(result.path.match(/\d+/) + ':' + result.title);

          // Store the result title (Used when no selection is made bythe user).
          Drupal.linkitCache.link_tmp_title = result.title;

          $('#linkit-modal #edit-h5p-tag').focus();
        },
        constructURL: function(path, search) {
          return path + encodeURIComponent(search);
        },
        insertSuggestionList: function($results, $input) {
          $results.width($input.outerWidth() - 2) // Subtract border width.
          .css({
            position: 'absolute',
            left: $input.offset().left,
            top: $input.offset().top + $input.outerHeight(),
            // High value because of other overlays like
            // wysiwyg fullscreen mode.
            zIndex: 211000,
            maxHeight: '330px',
            // Visually indicate that results are in the topmost layer
            boxShadow: '0 0 15px rgba(0, 0, 0, 0.5)'
          })
          .hide()
          .insertAfter($('#linkit-modal', context).parent());
        }
      });

      $('#linkit-modal .form-text.required', context).bind({
        keyup: Drupal.linkit.dialog.requiredFieldsValidation,
        change: Drupal.linkit.dialog.requiredFieldsValidation
      });

      Drupal.linkit.dialog.requiredFieldsValidation();

    }
  };



})(jQuery);



/**
 * @file
 * Linkit ckeditor dialog helper.
 */


(function ($) {

  Drupal.linkit.editorDialog.ckeditor.insertH5PTag = function(link) {
    var linkitCache = Drupal.linkit.getLinkitCache();
    CKEDITOR.tools.callFunction(linkitCache.editor._.linkitFnNum, link, linkitCache.editor);
  };
  
})(jQuery);