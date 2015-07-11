

// Create the dialog namespace.
Drupal.custom_general = Drupal.custom_general || {};
Drupal.custom_general.biblioDialogButtons = Drupal.custom_general.biblioDialogButtons || {};

(function($) {
  

  CKEDITOR.plugins.add( 'custom_general_plugin', {
    init: function( editor ){
      editor.ui.addButton( 'biblio_button', {
        label: 'Biblio', //this is the tooltip text for the button
        command: 'biblio_command',
        icon: this.path + 'images/biblio.gif'
      });
    
      editor.addCommand( 'biblio_command', {
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

          //var linkitCache = Drupal.linkit.getLinkitCache();

          // Lock the selecton for IE.
          if (CKEDITOR.env.ie) {
            linkitCache.selection.lock();
          }

          // Save the selected element.
          Drupal.linkit.setEditorSelectedElement(element);

          //var path = Drupal.settings.linkit.url.ckeditor;
          Drupal.linkit.dialog.buildDialog("/admin/biblio_dashboard");

          // Register an extra fucntion, this will be used in the popup.
          editor._.linkitFnNum = CKEDITOR.tools.addFunction( insertBiblioTag, editor );
          
          //get focus
          $.ajax({ 
            success: function (data) { 
              $('.linkit-wrapper #edit-biblio-search').focus();
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
      
      function insertBiblioTag(data, editor) {

        var linkitCache = Drupal.linkit.getLinkitCache(),
        selection = editor.getSelection();

        data = CKEDITOR.tools.trim(data);
        
        editor.insertHtml( '[bib]' + data + '[/bib]');
        
      };

    }
    
    
  });
  
  
  Drupal.custom_general.getBiblioTag = function() {   
    return $('#linkit-modal #edit-biblio-tag').val();
  };

  
  Drupal.behaviors.biblioDialogButtons = {
    attach: function (context, settings) {
      $('#linkit-modal #-custom-general-biblio-dashboard-form #edit-biblio-insert', context).bind('click', function() {
        
        var linkitCache = Drupal.linkit.getLinkitCache();
        //console.log(linkitCache);
        // Call the insertLink() function.
        Drupal.linkit.editorDialog[linkitCache.editorName].insertBiblioTag(Drupal.custom_general.getBiblioTag());
        
        // Close the dialog.
        Drupal.linkit.dialog.close();
        
        return false;
      });
      
      $('#linkit-modal #biblio-cancel', context).bind('click', Drupal.linkit.dialog.close);
    }
  };
  
  
  Drupal.behaviors.custom_general = {
    attach: function(context, settings) {

      if ($('#linkit-modal #edit-biblio-search', context).length == 0) {
        return;
      }

      Drupal.linkit.$searchInput = $('#linkit-modal #edit-biblio-search', context);

      // Create a "Better Autocomplete" object, see betterautocomplete.js
      Drupal.linkit.$searchInput.betterAutocomplete('init',
      settings.linkit.autocompletePath,
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

          $('#linkit-modal #edit-biblio-search').val(result.title);
          //23.05.2013 - 19:20 - SN : extract nid and embed with bib tags
          $('#linkit-modal #edit-biblio-tag').val(result.path.match(/\d+/));

          // Store the result title (Used when no selection is made bythe user).
          Drupal.linkitCache.link_tmp_title = result.title;

          $('#linkit-modal #edit-biblio-tag').focus();
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

Drupal.linkit.editorDialog.ckeditor.insertBiblioTag = function(link) {
    var linkitCache = Drupal.linkit.getLinkitCache();
    CKEDITOR.tools.callFunction(linkitCache.editor._.linkitFnNum, link, linkitCache.editor);
  };
  
})(jQuery);