(function ($) {
  Drupal.behaviors.videosafe = {
    attach: function (context, settings) {

    },
    initialize: function () {
      //alert("initialize");

      Drupal.behaviors.h5p_connector_api.onH5PEditorready(function () {
        Drupal.behaviors.videosafe.replaceUploadBox4();
      });

    },
    /*
    * Das ist jetzt die aktuellste Version. Öffnet unter "top" ein modales Fenster
    * mit einem ajaxifiziertem View.
    * Dieser gibt die Werte wieder an einen Callback zurueck
    */
   replaceUploadBox4: function()
   {
       //speichere originalfunktion in variable
       var original_function = window[0].H5PEditor.widgets.video.createAdd;
       /*callback, wenn jmd im modal-fenster ein video selectiert hat,
        *  argument sind die video-urls*/
       var h5p_callback_function_when_video_selected = function(json_video_data)
       {
           //kann mehrere urls beinhalten mit ogg, mp4 etc
           for (var i in json_video_data) {
               var video_url = json_video_data[i];
               H5P.jQuery(".h5p-add-dialog .h5p-dialog-box").find("input.h5p-file-url").val(video_url);
               H5P.jQuery(".h5p-add-dialog .h5p-buttons").find("button.h5p-insert").click();
           }
       };

       //hier wird original-funktion ueberschrieben
       window[0].H5PEditor.widgets.video.createAdd = function(type) {
           //lade original html
           var h5p_html = original_function(type);

           //bei audio nicht html replacen
           if (type === 'audio')
               return h5p_html;
           
           //statt ersatz-html auszuliefern, haengen wir einfach JS an, das das originale manipuliert
           h5p_html += '<script type="text/javascript">H5P.jQuery(".h5p-dialog-box h3").first().html("Video");'+
                   'H5P.jQuery(".h5p-add-dialog .h5p-file-drop-upload").removeClass("h5p-file-drop-upload").addClass("h5peditor-button-textual").attr("id", "open_videosafe").html("auswählen").off("click").click(function(){' +
                   'top.Drupal.behaviors.videosafe_ajax_browser.openAjaxBrowser( ' + h5p_callback_function_when_video_selected + '  );' +
                   'return false;' +
                   '});</script>';
           return h5p_html;

       }
   },
   /**
    * 
    old3
    */
    replaceUploadBox2: function () { //return;
      // alert("replacing");
      var originalwidgetsvideocreateAddAttachMethod = H5PEditor.widgets.video.createAdd;
      //Ueberschreibe original Funktionsaufruf
      H5PEditor.widgets.video.createAdd = function () {


        return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box">Das Video <u><a href="' + Drupal.settings.basePath + 'videosafe/" target="_blank">bitte hier hochladen oder ein bestehendes auswählen</a></u> und hier die URL einfügen:</div><div class="h5p-dialog-box"><input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';///+'<script>document.write( )</script>';
        /*   return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box"><div class="h5p-dialog-box">'
         +"Bitte laden Sie Ihr Video zunächst unter ... hoch und fügen Sie dann unten den Link ein."+
         '<input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';;*/
      };
    },
    /*die hier kann dann mehr und lädt ne ajaxansicht statt nur text. todo*/
    replaceUploadBox: function () {


      var originalwidgetsvideocreateAddAttachMethod = H5PEditor.widgets.video.createAdd;
      //Ueberschreibe original Funktionsaufruf
      H5PEditor.widgets.video.createAdd = function () {//lade root-folder
        //setze event auf buttons: beim klick wird die url-zeile gefuellt und auf insert gedrueckt
        //event auf links: bei klick wird das subverzeichnis / video nachgeladen (dabei adress-hash der aktuellen seite mitgegeben fuer og_group) und der entspr. div geoffnet
        var js = 'H5P.jQuery(".videosafe_container").load("/videosafe/ajax/");\n\
                          H5P.jQuery(".videosafe_container").on("click", "button[name=\'use_video\']", function(event){H5P.jQuery(this).parents(".h5p-dialog-box").find("input.h5p-file-url").val(H5P.jQuery(this).val()).parents(".h5p-dialog-box").find("button.h5p-insert").click(); return false;}); \n\
                          H5P.jQuery(".videosafe_container").on("click", "a", function(event){H5P.jQuery(this).next(".videosafe-sibling").toggle( "slow").load(H5P.jQuery(this).attr("href")+document.location.search); return false;});';

        return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box"><div class="h5p-dialog-box">Wählen Sie ein Video:<div class="videosafe_container">... lädt</div><script>' + js + '</script>Oder geben Sie eine URL an:<input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';
      };
    }

  }
}(jQuery));


jQuery(document).ready(function () {

  Drupal.behaviors.videosafe.initialize();

});
