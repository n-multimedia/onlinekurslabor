/* global Drupal */

var H5PEditor = H5PEditor || {};
var ns = H5PEditor;
(function ($) {
  ns.init = function () {
    var h5peditor;
    var $upload = $('input[name="files[h5p]"]').parents('.form-item');
    var $editor = $('.h5p-editor');
    var $create = $('#edit-h5p-editor').hide();
    var $type = $('input[name="h5p_type"]');
    var $params = $('input[name="json_content"]');
    var $library = $('input[name="h5p_library"]');
    var $maxscore = $('input[name="max_score"]');
    var titleFormElement = document.getElementById('h5p-plugin-form-title');
    var library = $library.val();

    ns.$ = H5P.jQuery;
    ns.basePath = Drupal.settings.basePath + Drupal.settings.h5peditor.modulePath + '/h5peditor/';
    ns.contentId = Drupal.settings.h5peditor.nodeVersionId;
    ns.fileIcon = Drupal.settings.h5peditor.fileIcon;
    ns.ajaxPath = Drupal.settings.h5peditor.ajaxPath;
    ns.filesPath = Drupal.settings.h5peditor.filesPath;
    ns.relativeUrl = Drupal.settings.h5peditor.relativeUrl;
    ns.contentRelUrl = Drupal.settings.h5peditor.contentRelUrl;
    ns.editorRelUrl = Drupal.settings.h5peditor.editorRelUrl;
    ns.apiVersion = Drupal.settings.h5peditor.apiVersion;

    // Semantics describing what copyright information can be stored for media.
    ns.copyrightSemantics = Drupal.settings.h5peditor.copyrightSemantics;
    ns.metadataSemantics = Drupal.settings.h5peditor.metadataSemantics;

    // Required styles and scripts for the editor
    ns.assets = Drupal.settings.h5peditor.assets;

    // Required for assets
    ns.baseUrl = Drupal.settings.basePath;

    $type.change(function () {
      if ($type.filter(':checked').val() === 'upload') {
        $create.hide();
        $upload.show();
      }
      else {
        $upload.hide();
        if (h5peditor === undefined) {
          h5peditor = new ns.Editor(library, $params.val(), $editor[0]);
        }
        $create.show();
      }
    }).change();

    $('#h5p-content-node-form').submit(function (event) {
      if (h5peditor !== undefined) {

        var params = h5peditor.getParams();

        if (params !== undefined && params.params !== undefined) {
          // Validate mandatory main title. Prevent submitting if that's not set.
          // Deliberatly doing it after getParams(), so that any other validation
          // problems are also revealed
          if (!h5peditor.isMainTitleSet()) {
            return event.preventDefault();
          }

          // Set main library
          $library.val(h5peditor.getLibrary());

          // Set params
          $params.val(JSON.stringify(params));

          // Calculate & set max score
          $maxscore.val(h5peditor.getMaxScore(params.params));

          // Set Drupal 7's title field to the metadata title if the field
          // is not displayed
          var tmp = document.createElement('div');
          tmp.innerHTML = params.metadata.title;
          titleFormElement.value = tmp.textContent;
        }
      }
    });
  };

  ns.getAjaxUrl = function (action, parameters) {
    var url = Drupal.settings.h5peditor.ajaxPath + action;

    if (parameters !== undefined) {
      for (var key in parameters) {
        url += '/' + parameters[key];
      }
    }

    return url;
  };

  $(document).ready(ns.init);
})(H5P.jQuery);
