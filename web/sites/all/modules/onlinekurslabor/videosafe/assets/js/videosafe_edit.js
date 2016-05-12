
(function($) {
    Drupal.behaviors.videosafe = {
      
        attach: function(context, settings) {
          
        }, 
          initialize: function()
        {
            //alert("initialize");
            
                            Drupal.behaviors.h5p_connector_api.onH5PEditorready(function(){ Drupal.behaviors.videosafe.replaceUploadBox2();});
                        
        },
       
         replaceUploadBox2: function()
        { //return;
           // alert("replacing");
              var originalwidgetsvideocreateAddAttachMethod =   H5PEditor.widgets.video.createAdd;
            //Ueberschreibe original Funktionsaufruf
            H5PEditor.widgets.video.createAdd = function()
            {console.debug((window.location.href));
                //hole og aus url
                 var lehrtextext_id ;
               try
               {
                   lehrtextext_id = /\og_group_ref=\d+/g.exec(window.location.href)[0];
                   
               }catch(e)
               {
                   lehrtextext_id = /\og_group_ref%3D\d+/g.exec(window.location.href)[0];
                 lehrtextext_id = lehrtextext_id.replace('og_group_ref%3D','');
                 
                   
               }
             lehrtextext_id  =   lehrtextext_id.replace(/[^0-9]/g,"");
              return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box">Das Video <u><a href="'+Drupal.settings.basePath +'videosafe/?prepoulate_domain='+lehrtextext_id+'" target="_blank">bitte hier hochladen oder ein bestehendes auswählen</a></u> und hier die URL einfügen:</div><div class="h5p-dialog-box"><input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';///+'<script>document.write( )</script>';
             /*   return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box"><div class="h5p-dialog-box">'
                +"Bitte laden Sie Ihr Video zunächst unter ... hoch und fügen Sie dann unten den Link ein."+
                    '<input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';;*/
        };
        },
         /*die hier kann dann mehr und lädt ne ajaxansicht statt nur text. todo*/
           replaceUploadBox: function()
        {    
   
            
               var originalwidgetsvideocreateAddAttachMethod =   H5PEditor.widgets.video.createAdd;
            //Ueberschreibe original Funktionsaufruf
            H5PEditor.widgets.video.createAdd = function()
            {//lade root-folder
                //setze event auf buttons: beim klick wird die url-zeile gefuellt und auf insert gedrueckt
                //event auf links: bei klick wird das subverzeichnis / video nachgeladen (dabei adress-hash der aktuellen seite mitgegeben fuer og_group) und der entspr. div geoffnet
                var js = 'H5P.jQuery(".videosafe_container").load("/videosafe/ajax/");\n\
                          H5P.jQuery(".videosafe_container").on("click", "button[name=\'use_video\']", function(event){H5P.jQuery(this).parents(".h5p-dialog-box").find("input.h5p-file-url").val(H5P.jQuery(this).val()).parents(".h5p-dialog-box").find("button.h5p-insert").click(); return false;}); \n\
                          H5P.jQuery(".videosafe_container").on("click", "a", function(event){H5P.jQuery(this).next(".videosafe-sibling").toggle( "slow").load(H5P.jQuery(this).attr("href")+document.location.search); return false;});';
             
                return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box"><div class="h5p-dialog-box">Wählen Sie ein Video:<div class="videosafe_container">... lädt</div><script>'+js+'</script>Oder geben Sie eine URL an:<input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';
            };  
        } 
       
        }
}(jQuery));


jQuery(document).ready(function() {
  
    Drupal.behaviors.videosafe.initialize();
    
    });
     