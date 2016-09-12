
(function($) {
    Drupal.behaviors.linkit_extension = {
        attach: function(context, settings) {
            //   Drupal.behaviors.annvid.stream.attach(context, settings);
            //gibnts nich  Drupal.behaviors.annvid.video.attach(context, settings);


        },
        createCKDialog: function(options)
        {
            /*   options["dialog_id"]
             options["title"]
             options["inputlabel"]
             options["linkit_profile_id"]
             var markup_callback = options["markup_callback"]; //return markup for a given node-id and title
             options["onOk"] : custom onOK-function, parameters dialog and editor. optional.
             options["additional_contents"] additional fields for the dialog. requires a custom onOk-function
             */



            CKEDITOR.dialog.add(options["dialog_id"], function(editor) {
                var formelements =
                        [
                            {
                                // Text input field for the abbreviation text.
                                type: 'text',
                                id: 'input',
                                label: options["inputlabel"],
                                // Validation checking whether the field is not empty.
                                validate: CKEDITOR.dialog.validate.notEmpty("Input cannot be empty.")
                            },
                            {
                                // hidden input field for the markup (explanation).
                                type: 'text',
                                id: 'markup',
                                // label: 'Markup (wird automatisch gesetzt)',
                            },
                        ];
                if (options["additional_contents"])
                {
                    for (var i = 0; i < options["additional_contents"].length; i++)
                        formelements.push(options["additional_contents"][i]);
                }

                return {
                    // Basic properties of the dialog window: title, minimum size.
                    title: options["title"],
                    minWidth: 400,
                    minHeight: 200,
                    // Dialog window content definition.
                    contents: [
                        {
                            // Definition of the Basic Settings dialog tab (page).
                            id: 'tab-basic',
                            label: 'Basic Settings',
                            // The tab content.
                            elements: formelements
                        }
                    ],
                    onShow: function()
                    {

                        var element = this.getElement();
                        var dialog = this;
                        //verstecke markup-input, input hidden gibbet nich
                        jQuery('#' + dialog.getContentElement('tab-basic', 'markup')._.inputId).hide();
                        //aktiviere betterautocomplete
                        
                        /*hier folgte eine längere auflistung der better-autocomplete-funktionalität
                         * Referenz fuer Funktionen:
                         * https://github.com/betamos/Better-Autocomplete/blob/develop/src/jquery.better-autocomplete.js
                         */
                        jQuery('#' + dialog.getContentElement('tab-basic', 'input')._.inputId).addClass("linkit_xt_fetch").betterAutocomplete('init', Drupal.settings.linkit.autocompletePath.replace("___profile___?s=", "") + options["linkit_profile_id"], {charLimit: 0}, {
                            constructURL: function(path, query) {
                                return path + (path.indexOf('?') > -1 ? '&' : '?') + 's=' + encodeURIComponent(query);
                            },
                            /**
                             * Called when remote fetching begins.
                             *
                             * <br /><br /><em>Default behavior: Adds the CSS class "fetching" to the
                             * input field, for styling purposes.</em>
                             *
                             * @param {Object} $input
                             *   The input DOM element, wrapped in jQuery.
                             */
                            beginFetching: function($input) {
                                $input.addClass('linkit_xt_fetch_on');
                            },
                            /**
                             * Called when fetching is finished. All active requests must finish before
                             * this function is called.
                             *
                             * <br /><br /><em>Default behavior: Removes the "fetching" class.</em>
                             *
                             * @param {Object} $input
                             *   The input DOM element, wrapped in jQuery.
                             */
                            finishFetching: function($input) {
                                $input.removeClass('linkit_xt_fetch_on');
                            },
                            themeResult: function(result) {
                                var output;
                                output = '<h4>' + result.title + '</h4>';

                                return output;
                            },
                            select: function(result, $input) { // Custom select callback
                                $input.blur();
                                $input.val(result.title);

                                var callbackfunc = options["markup_callback"];
                                //betterautocomplete loest gleich in pfad auf. wir brauchen aber die nid
                                var node_id;
                                var node_path = result.path;
                                node_id = node_path.replace(/[^0-9.]/g, "");
                                //callback mit id, titel
                                markup = callbackfunc(node_id, dialog.getValueOf('tab-basic', 'input'))
                                dialog.setValueOf('tab-basic', 'markup', markup);


                            }
                        }); //ende betterautocomplete
                    },
                    // This method is invoked once a user clicks the OK button, confirming the dialog.
                    onOk: function() {
                        // The context of this function is the dialog object itself.
                        // http://docs.ckeditor.com/#!/api/CKEDITOR.dialog
                        var dialog = this;
                        //optional: use a different onOk-Function
                        if (options["onOk"])
                        {
                            var custom_onOK = options["onOk"];
                            return    custom_onOK(dialog, editor);

                        }



                        var markup = dialog.getValueOf('tab-basic', 'markup');
                        editor.insertText(markup);
                        return;
                    }
                };
            });

        }
    }



    ;
}(jQuery));
