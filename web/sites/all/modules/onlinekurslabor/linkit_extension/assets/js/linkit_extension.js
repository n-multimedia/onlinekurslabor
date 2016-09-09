
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
                        jQuery('#' + dialog.getContentElement('tab-basic', 'input')._.inputId).betterAutocomplete('init', Drupal.settings.linkit.autocompletePath.replace("___profile___?s=", "") + options["linkit_profile_id"], {charLimit: 0}, {
                            constructURL: function(path, query) {
                                return path + (path.indexOf('?') > -1 ? '&' : '?') + 's=' + encodeURIComponent(query);
                            },
                            themeResult: function(result) {
                                var output;
                                output = '<h4>' + result.title + '</h4>';

                                return output;
                            },
                            select: function(result, $input) { // Custom select callback
                                $input.blur();
                                console.debug($input);
                                $input.val(result.title);

                                var callbackfunc = options["markup_callback"];
                                var node_id;
                                var node_path = result.path;
                                node_id = node_path.replace(/[^0-9.]/g, "");
                                //callback mit id, titel
                                markup = callbackfunc(node_id, dialog.getValueOf('tab-basic', 'input'))
                                dialog.setValueOf('tab-basic', 'markup', markup);


                            }
                        });
                    },
                    // This method is invoked once a user clicks the OK button, confirming the dialog.
                    onOk: function() {
                        // The context of this function is the dialog object itself.
                        // http://docs.ckeditor.com/#!/api/CKEDITOR.dialog
                        var dialog = this;
                        //optional: use a different onOk-Function
                        if (options["onOk"])
                        {
                            var clbck = options["onOk"];
                            return    clbck(dialog, editor);

                        }



                        var markup = dialog.getValueOf('tab-basic', 'markup');
                        editor.insertText(markup);
                        return;
                        // Create a new <abbr> element.
                        var abbr = editor.document.createElement('abbr');

                        // Set element attribute and text by getting the defined field values.
                        abbr.setAttribute('title', dialog.getValueOf('tab-basic', 'input'));
                        abbr.setText(dialog.getValueOf('tab-basic', 'input'));



                        // Finally, insert the element into the editor at the caret position.
                        editor.insertElement(abbr);
                    }
                };
            });

        }
    }



    ;
}(jQuery));
