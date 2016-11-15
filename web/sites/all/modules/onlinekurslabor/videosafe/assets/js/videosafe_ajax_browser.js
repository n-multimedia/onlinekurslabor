

(function($) {

    Drupal.behaviors.videosafe_ajax_browser = {
        view_container: null,
        /*exposed_form: die form im ajax view */
        exposed_form: {
            form: null,
            input_folder: null,
            input_title: null,
            button_apply: null,
            button_reset: null,
            callback_video_selected: null,
        },
        /*das, was bei der auswahl eines videos passiert. gesetzt in videosafe_edit.js*/
        callback_video_selected: null,
        /*
         * 
         * 
         * attach
         * 
         */
        attach: function(context, settings) {

            Drupal.behaviors.videosafe_ajax_browser.debug("videosafe_ajax_browser something");
            //initialisiere neu
            this.initialize();
            Drupal.behaviors.videosafe_ajax_browser.debug("attachd and initialized!");

        }
        ,
        initialize: function() {
            var view_container = jQuery(".view-videosafe-folderview.view-id-videosafe_folderview.view-display-id-ajax_browser");
            Drupal.behaviors.videosafe_ajax_browser.debug("der view_container ist: view_container");


            this.view_container = view_container;
            this.exposed_form.form = jQuery("form#views-exposed-form-videosafe-folderview-ajax-browser", view_container);
            this.exposed_form.input_folder = jQuery("input#edit-field-parent-folder-target-id", this.exposed_form.form);
            if (typeof this.exposed_form.input_folder === 'undefined' || this.exposed_form.input_folder.length == 0)
            {   //view noch nicht ready, breche ab. wird spaeter wieder aufgerufen
                Drupal.behaviors.videosafe_ajax_browser.debug("skipping empty exposed_form.input_folder!!");
                return false;
            }
            //view ready, jetzt sucht er sich die ganzen html-elemente zusammen
            this.exposed_form.input_title = jQuery("input#edit-title--2", this.exposed_form.form);
            this.exposed_form.button_apply = jQuery("button#edit-submit-videosafe-folderview", this.exposed_form.form);
            this.exposed_form.button_reset = jQuery("button#edit-reset", this.exposed_form.form);
            this.convertToAjaxfunctionality(this.exposed_form.button_reset, Drupal.settings.videosafe.root_nid);
            Drupal.behaviors.videosafe_ajax_browser.debug("livE1!");
            this.processClickableElements();
            Drupal.behaviors.videosafe_ajax_browser.debug("livE2!");
            //verstecke oberordner-feld des views
            jQuery("#edit-field-parent-folder-target-id-wrapper", this.exposed_form.form).hide();
            var that = this;
            //man tippt was in die suche ein: ordner-feld leeren
            this.exposed_form.input_title.keydown(function() {
                that.exposed_form.input_folder.val("");
            });
            ;

        },
        /*
         * refresht die ajax-view-form durch klick auf den button
         * @returns {undefined}
         */
        refreshForm: function()
        {
            if (this.exposed_form.button_apply)
            {
                console.debug("refreshing");
                this.exposed_form.button_apply.click();
            }
            console.debug("did i refresh`?````");
        },
        /*
         * Konvertiert Links, buttons etc die auf nodes verweise in Ajax-Elemente
         * sprich, der View wird mit den Parametern befüllt
         * @type _L3
         */
        processClickableElements: function()
        {
            var that = this;
            /*macht aus den a[rel] js-links, die das folder-field befüllen und die form abschicken*/
            jQuery('div.view-content a[rel], div.attachment-before a[rel]', this.view_container).not(".videosafe_processed").each(function() {
                var node_id = jQuery(this).attr("rel");
                jQuery(this).addClass("videosafe_processed");
                Drupal.behaviors.videosafe_ajax_browser.debug(node_id);
                that.convertToAjaxfunctionality(jQuery(this), node_id);
            });
            //zb. bearbeiten-link in neuem tab
            jQuery('div.view-content a:not([rel]),  div.attachment-before a:not([rel])', this.view_container).each(function() {
                jQuery(this).attr('target', '_blank');
            });
            /*suche nach buttons, die select_video heißen und ein attr rel haben*/
            jQuery('button.select_video', this.view_container).not(".videosafe_processed").each(function() {
                var encoded_video_data = jQuery(this).attr("rel");

                var json_video_data = JSON.parse(encoded_video_data);
                jQuery(this).addClass("videosafe_processed");
                //bei klick auf button: schließe modal und rufe callback auf
                jQuery(this).click(function() {

                    that.callback_video_selected(json_video_data);
                    jQuery("#videosafe_ajax_modal_dialog").modal('hide');
                    return false;
                });
            });



        },
        /*
         * convertiert jq_object in object, welches bei klick darauf den
         * ajax-view neu laden mit der übergebenen node-id als parameter
         * @param {type} callback_video_selected
         * @returns {undefined}
         */
        convertToAjaxfunctionality: function(jq_object, node_id)
        {
            console.debug("callback registered?");

            var that = this;
            jq_object.click(function() {
                Drupal.behaviors.videosafe_ajax_browser.debug("click caught! Debugging kommt");
                Drupal.behaviors.videosafe_ajax_browser.debug(that.exposed_form.input_folder);
                Drupal.behaviors.videosafe_ajax_browser.debug(that.exposed_form.button_apply);
                that.exposed_form.input_folder.val(node_id);
                that.exposed_form.input_title.val("");
                that.exposed_form.button_apply.click();
                return false;
            });
        },
        /**
         * public method for opening the view 
         * @param {type} callback_video_selected the callback being called when the user has chosen a video
         * @returns  none
         */
        openAjaxBrowser: function(callback_video_selected)
        {
            jQuery("#videosafe_ajax_modal_dialog").modal();
            jQuery("#videosafe_ajax_modal_view_container").html(Drupal.settings.videosafe.loading);
            Drupal.behaviors.videosafe_ajax_browser.loadAjaxBrowserToElement("#videosafe_ajax_modal_view_container");
            Drupal.behaviors.videosafe_ajax_browser.attach();

            this.callback_video_selected = callback_video_selected;
        },
        /**
         * private function. see openAjaxBrowser
         * with big thx to http://stackoverflow.com/questions/4932523/embed-a-view-using-ajax for pointing in the right direction
         * @param {type} element_identifier the html-node-identifier in which the browser will be loaded
         * @returns {none}
         */
        loadAjaxBrowserToElement: function(element_identifier)
        {

            var data = {};
            // Add view settings to the data.
            //previously set via php
            for (var key in Drupal.settings.views.ajaxViews[0]) {

                //kein doppelt setzen
                if (!data[key])
                    data[key] = Drupal.settings.views.ajaxViews[0][key];
            }
// Get the params from the hash.
            //dont need
            /*
             if (location.hash) {
             var q = decodeURIComponent(location.hash.substr(1));
             var o = {'f': function(v) {
             return unescape(v).replace(/\+/g, ' ');
             }};
             $.each(q.match(/^\??(.*)$/)[1].split('&'), function(i, p) {
             p = p.split('=');
             p[1] = o.f(p[1]);
             data[p[0]] = data[p[0]] ? ((data[p[0]] instanceof Array) ? (data[p[0]].push(p[1]), data[p[0]]) : [data[p[0]], p[1]]) : p[1];
             });
             }*/
            //erstes oeffnen: uebergebe root
            data['field_parent_folder_target_id'] = Drupal.settings.videosafe.root_nid;
            jQuery.ajax({
                url: Drupal.settings.views.ajax_path,
                type: 'POST',
                data: data,
                success: function(response) {
                    var viewDiv = '.view-dom-id-' + data.view_dom_id;
                    jQuery(element_identifier).html(response[2].data);
                    // Call all callbacks.
                    Drupal.behaviors.videosafe_ajax_browser.debug("view loaded, now attaching " + viewDiv);
                    Drupal.attachBehaviors(jQuery(viewDiv))
                },
                error: function(xhr) {
                    //kann auftreten bei spontanem db-fehler oder so..
                    jQuery(element_identifier).html('<p id="artist-load-error">Error loading the video-overview. Please contact support.</p>');

                },
                dataType: 'json'
            });

        },
        /*
         * wollte nicht alle debugs entfernen, wenn man sie nochmal braucht, muss man hier aktivieren
         */
        debug: function(str)
        {
            //console.debug(str);
            return false;
        }

    }
}(jQuery));