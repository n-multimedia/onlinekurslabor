
(function($) {
    Drupal.behaviors.videosafe = {
        interval_api_loaded: null,
        interval_run: 0,
        attach: function(context, settings) {
          
        }, 
        checkAPILoaded: function()
        {   // nach 15 sec noch kein Hinweis auf H5P? Dann lassmers..
            if (this.interval_run++ < 15)
            {
                if (typeof H5PEditor === 'undefined' || typeof H5PEditor.widgets === 'undefined' || typeof H5PEditor.widgets.video === 'undefined') //|| typeof(H5PIntegration) === 'undefined' || typeof H5P.InteractiveVideo === 'undefined')
                {
                    return false;
                }
                else
                {
                    clearInterval(this.interval_api_loaded);
                    Drupal.behaviors.videosafe.replaceUploadBox2();
                }
            } else
            {
                clearInterval(this.interval_api_loaded);
            }

        },
          initialize: function()
        {alert("initialize");
         //  return false;
            this.interval_api_loaded =
                    setInterval(function() {
                        Drupal.behaviors.videosafe.checkAPILoaded();
                    }, 1000);
            
           // jQuery(".h5p-editor-iframe").contents().find("body").on('change', "select", function() {alert(jQuery(this.value))});
            /*alert("hase");
        
            jQuery(".h5p-editor-iframe").contents().find("select").on('change', function() {
                if(this.value==="H5P.InteractiveVideo 1.0")
                        Drupal.behaviors.videosafe.replaceUploadBox();
               });*/
        },
         replaceUploadBox2: function()
        { 
              var originalwidgetsvideocreateAddAttachMethod =   H5PEditor.widgets.video.createAdd;
            //Ueberschreibe original Funktionsaufruf
            H5PEditor.widgets.video.createAdd = function()
            {
                
                var lehrtextext_id = /\/\d+\//g.exec(window.location.href)[0].replace(/\//g,"");
              return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box">Das Video <u><a href="'+Drupal.settings.basePath +'videosafe/?prepoulate_domain='+lehrtextext_id+'" target="_blank">bitte hier hochladen oder ein bestehendes auswählen</a></u> und hier die URL einfügen:</div><div class="h5p-dialog-box"><input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';///+'<script>document.write( )</script>';
             /*   return '<div role="button" tabindex="1" class="h5p-add-file" title="' + H5PEditor.t('core', 'addFile') + '"></div><div class="h5p-add-dialog"><div class="h5p-dialog-box"><div class="h5p-dialog-box">'
                +"Bitte laden Sie Ihr Video zunächst unter ... hoch und fügen Sie dann unten den Link ein."+
                    '<input type="text" placeholder="type in file url" class="h5p-file-url h5peditor-text"/></div><div class="h5p-buttons"><button class="h5p-insert">Insert</button><button class="h5p-cancel">Cancel</button></div></div>';;*/
        }
        },
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
            }  
        } 
       
        }
}(jQuery));


jQuery(document).ready(function() {
    Drupal.behaviors.videosafe.initialize();
    });