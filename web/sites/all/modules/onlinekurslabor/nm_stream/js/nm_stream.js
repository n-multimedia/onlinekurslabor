/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {


    var nm_stream = null;

    /**
     * Registre JQuery Plugin
     * @constructor
     */
    $.fn.NMStream = function(settings) {
        nm_stream = new NMStream(this, settings);
    };




    Drupal.behaviors.nm_stream = {

        attach: function(context, options) {

            $('.pane-nm-stream').once('nm_stream', function() {
                var settings = {
                    init_bindings_callback: Drupal.attachBehaviors
                };
                $(this).NMStream(settings);
            });


        }
    };

    /**
     * constructor
     *
     * @param context
     * @constructor
     */
    function NMStream(context, options) {

        this.container = context;
        this.node_load_url = '/nm_stream/node/%nid/load';
        this.node_add_url = '/nm_stream/node/add';
        this.node_edit_url = '/nm_stream/node/%nid/edit';
        this.node_delete_url = '/nm_stream/node/%nid/delete/%token';
        this.node_get_all_comments_url = '/nm_stream/node/%nid/get_all_comments';
        this.node_delete_attachment_url = '/nm_stream/node/%nid/file/%fid/delete/%token';
        this.node_get_update_url = '/nm_stream/node/%nid/get_update';
        this.comment_add_url = '/nm_stream/node/%nid/comment/add';
        this.comment_edit_url = '/nm_stream/comment/%cid/edit';
        this.comment_delete_url = '/nm_stream/comment/%cid/delete/%token';

        //init stream variables
        this.nm_stream_toggle_open_data = [];
        this.nm_stream_get_update_timer = false;
        this.nm_stream_pause_update_timer = false;

        this.post_spinner_white = null;
        this.post_spinner_black = null;
        this.post_spinner_load = null;

        this.init_bindings_callback = options.init_bindings_callback;

        this.init();
    }

    /**
     * init
     */
    NMStream.prototype.init = function() {

        //multifile widget an iframe for ajax uploads
        this.init_multifile_upload();

        //initialize
        this.init_privacy_widget();

        this.init_bind_events();
        this.init_override_alert();

        //init polling
        this.nm_stream_get_update();

        //initilizing nodes
        this.init_bind_nm_stream_nodes();

        //initilizing inifinte spinner
        this.init_load_more_as_infinite_spinner();

    };



    /**
     * initialize upload multifile
     */
    NMStream.prototype.init_multifile_upload = function () {
        var self = this;

        $('footer').once('nm_stream', function() {
            //append iframe for uploads
            $(this).append('<iframe id="nm_stream_hidden_upload" src="" name="nm_stream_hidden_upload" style="width:0;height:0;border:0px solid #fff; position:absolute;"></iframe>');
        });


        //UPLOAD
        $('.fileupload').MultiFile({
            list: '.fileupload-list',
            STRING: {
                remove: '<span class="btn btn-danger fileinput-button">\n'+
                '<i class="glyphicon glyphicon-trash"></i>\n'+
                '<span>entfernen</span>\n'+
                '</span>',
                duplicate: '<h3>Diese Datei wurde bereits ausgewählt!</h3>\n<br/>$file'
            }
        });

    };

    /**
     * initialize privacy widget
     */
    NMStream.prototype.init_override_alert = function() {
        (function() {
            var _alert = window.alert;                   // <-- Reference
            window.alert = function(str) {
                this.nm_stream_alert(str);               // Suits for this case
            };
        })();
    };

    /**
     * override alert
     */
    NMStream.prototype.nm_stream_alert = function() {
        //customized alert implementation
        bootbox.alert(msg);
    };

    /**
     * initialize privacy widget
     * das privacy-html-select wird zum bekannten hüsbchen drop-dpown
     * und die description wird verschoben
     * in das a als title-attribute (fuer hover-effekt)
     */
    NMStream.prototype.init_privacy_widget = function() {
        /*
         * privacy dropdown
         */
        $('#nm-stream-add-node-privacy').ddslick();
        $('[id^=nm-stream-edit-node-privacy-]').ddslick();

        //eigentlich ist nun pro option eine desccription vorhanden. die wollen wir aber als hover (im a[title])
        $("ul.dd-options  a.dd-option").each(function(index) {
            var desc = $(".dd-option-description", this).hide().text();
            $(this).attr("title", desc);
        });
    };

    /**
     * bind events
     */
    NMStream.prototype.init_bind_events = function () {
        var self = this;
        //bind click to dummy text field
        self.init_bind_dummy_textfield_event();

        //post button click
        self.init_bind_post_button_event();

        //cancel button click
        self.init_bind_cancel_button_event();

    };

    /**
     * bind click to dummy text field
     */
    NMStream.prototype.init_bind_dummy_textfield_event = function() {
        var self = this;
        //bind click to dummy text field
        $('.nm-stream-node-form-container').once('nm_stream').click(function () {
            $(this).find('.nm-stream-node-form').hide();
            var form_container = this;
            var form = $(this).find('form');
            form.show();
            form.find('textarea').autosize();
            form.find('textarea').bind('input propertychange', function () {
                self.textarea_change($(this), form_container);
            });
            //call initial event to disable buttons
            self.textarea_change(form.find('textarea'), form_container);
            form.find('textarea').focus();
        });
    }


    /**
     * bind post button events
     */
    NMStream.prototype.init_bind_post_button_event = function () {

        var self = this;


        //bind click to post button
        $('#nm-stream-add-node .nm-stream-node-submit').once('nm_stream').click(function () {


            //add form
            var form_container = $(this).closest('.nm-stream-node-form-container');
            var body = form_container.find('textarea').val();
            var privacy = form_container.find('.dd-selected-value').val();
            var token = form_container.find('.nm-stream-form-token').val();

            var url = self.node_add_url; // '/nm_stream/node/add';
            var data = {body: body, privacy: privacy, token: token};

            //check if attachments need to be uploaded -> user iframe form submit else post
            if (form_container.find('.MultiFile-wrap').children().length > 1) {

                $('#nm_stream_hidden_upload').bind('load', function () {


                    //reset textarea
                    form_container.find('textarea').val('');
                    //reset file upload
                    form_container.find('.fileupload').MultiFile('reset');

                    data = $.parseJSON($(this).contents().find('body').first().text());


                    if (data !== null) {
                        if (data.update_status === 2) {
                            self.refresh(data);
                        }
                        //add new node
                        if (data.status === 1) {
                            //display new Post
                            var new_node = ($(data.node)).insertBefore($('.pane-nm-stream .view-content .views-row').first()).fadeIn().find(".nm-stream-node-container");
                            //fix, new nodes could not be edited without views-row div around

                            //attach behavior
                            new NMStreamNode(self, new_node);

                        }else {
                            console.log("error:");
                            console.log(data);
                        }

                    }

                    //enable button
                    self.nm_stream_unset_loading(form_container);
                    self.nm_stream_pause_update_timer = false;

                    //todo maybe safe.. could kill other simultaneously running bindings
                    $(this).unbind();

                });

                //26.03.2014 - 16:13 - SN
                //privacy field not transmitted
                //fix before submit .. remove after submitting
                var privacy_input_fix = $('<input type="hidden" name="privacy" value="' + privacy + '" />');
                form_container.find('form').append(privacy_input_fix);
                //privacy_input_fix.remove();

                $('#nm-stream-add-node').attr("action", url);
                $('#nm-stream-add-node').submit();

                privacy_input_fix.remove();

            }


            //disable button
            self.nm_stream_form_set_loading(form_container);
            self.nm_stream_pause_update_timer = true;

            //iframe submission, exit!
            if (form_container.find('.MultiFile-wrap').children().length > 1) {
                return false;
            }


            $.post(url, data, function (data) {

                //first check if node updates were made in meantime
                if (data.update_status === 2) {
                    self.refresh(data);
                }
                //add new node
                if (data.status === 1) {
                    //save succeed
                    //reset textarea
                    form_container.find('textarea').val('');

                    //prepend node
                    var new_node = ($(data.node)).insertBefore($('.pane-nm-stream .view-content .views-row').first()).fadeIn().find(".nm-stream-node-container");


                    //attach behavior
                    new NMStreamNode(self, new_node);

                }

                //enable button
                self.nm_stream_unset_loading(form_container);
                self.nm_stream_pause_update_timer = false;

            });

            return false;
        });


    };

    /**
     * bind click to comment toggle
     */
    NMStream.prototype.init_bind_cancel_button_event = function () {
        var self = this;

        //bind click to cancel button
        $('#nm-stream-add-node .nm-stream-node-cancel').once('nm_stream').click(function () {

            //add form
            $('.nm-stream-node-form').show();
            $(this).closest('.nm-stream-node-form-container').find('textarea').val('');
            $(this).closest('form').hide();
            //reset file upload
            $(this).closest('form').find('.fileupload').MultiFile('reset');

            return false;
        });
    }

    /**
     * initialize nodes
     */
    NMStream.prototype.init_bind_nm_stream_nodes = function () {

        var self = this;

        $(".nm-stream-node-container").each(function (index) {
            $(this).once("nm_stream", function () {
                new NMStreamNode(self, this);
            });
        });

    };




    /**
     * refresh / update stream
     */
    NMStream.prototype.refresh = function (data) {

        var self = this;

        //NODES
        var view_container = $('.pane-nm-stream .view-content .views-row').first();

        if (typeof data.new_nodes !== 'undefined') {
            var new_nodes = view_container.prepend($(data.new_nodes).fadeIn());

            self.init_bind_nm_stream_nodes();
        }

        if (typeof data.changed_nodes !== 'undefined') {
            //some nodes were changed
            //insert new data
            //refresh every node which has been changed
            for (var nid in data.changed_nodes) {
                var new_top = $(data.changed_nodes[nid]).find('.nm-stream-top').html();
                var new_body = $(data.changed_nodes[nid]).find('.nm-stream-main-body').html();
                var new_attachments = $(data.changed_nodes[nid]).find('.nm-stream-attachments').html();
                var node_top_changed = $('#nm-stream-node-' + nid).find('.nm-stream-top').first().html(new_top);
                var node_body_changed = $('#nm-stream-node-' + nid).find('.nm-stream-main-body').first().html(new_body);
                var node_attachments_changed = $('#nm-stream-node-' + nid).find('.nm-stream-attachments').first().html(new_attachments);

            }
        }

        if (typeof data.deleted_nodes !== 'undefined') {
            //some nodes were deleted

            for (var nid in data.deleted_nodes) {
                $('#nm-stream-node-' + nid).fadeOut().remove();
            }
        }

        //COMMENTS

        //add new
        if (typeof data.new_comments !== 'undefined') {

            //find node, attach to top
            for (var nid in data.new_comments) {
                //check if its the first comment -> complete node has to be loaded

                if ($('#nm-stream-node-' + nid).find('.nm-stream-comments-container').length === 0) {


                    var url = '/nm_stream/node/' + nid + '/load';

                    $.post(url, data, function (data) {
                        if (data.status === 1) {
                            //save succeed
                            //check if user is typing

                            var new_comments = $('#nm-stream-node-' + nid).append($(data.node).find('.nm-stream-comments-section').fadeIn());
                            $('#nm-stream-node-' + nid).find('.nm-stream-comments-section').find('.nm-stream-comments-form').hide();

                            Drupal.attachBehaviors(new_comments);

                        } else {
                            //error handling todo here
                            console.log("error:");
                            console.log(data);
                        }
                    });

                } else {
                    //check if we are in only comments mode
                    //special handling for ajax comment functionality
                    //not easy here
                    var only_comment_function = $('#nm-stream-node-' + nid).closest('.nm-stream-comments-section').length > 0;
                    //var new_comments = $('.nm-stream-comments-section').first().append(data.new_comments[nid]);

                    if (only_comment_function) {
                        //append
                        var new_comments = $('#nm-stream-node-' + nid).find('.nm-stream-comments-container').first().append(data.new_comments[nid]);
                    } else {
                        //prepend
                        var new_comments = $('#nm-stream-node-' + nid).find('.nm-stream-comments-container').first().prepend(data.new_comments[nid]);
                    }


                    //self.init_bind_nm_stream_comments();
                    /**
                     * 23.07.2017 - 20:23 - SN
                     * needs to be refactored
                     * someone else creates an comment - need to bind events
                     */
                    $('#nm-stream-node-' + nid).find(".nm-stream-comment").once("nm_stream").each(function(index) {
                        new NMStreamComment(self.nm_stream, self, this);

                    });
                }
            }

        }

        //apply changes
        if (typeof data.changed_comments !== 'undefined') {
            //some comments were changed
            //insert new data
            //refresh every comment which has been changed
            for (var cid in data.changed_comments) {
                var new_top = $(data.changed_comments[cid]).find('.nm-stream-top').html();
                var new_body = $(data.changed_comments[cid]).find('.nm-stream-main-body').html();
                var comment_top_changed = $('#nm-stream-comment-' + cid).find('.nm-stream-top').first().html(new_top);
                var comment_body_changed = $('#nm-stream-comment-' + cid).find('.nm-stream-main-body').first().html(new_body);

            }
        }

        //delete
        if (typeof data.deleted_comments !== 'undefined') {
            //some nodes were deleted
            for (var cid in data.deleted_comments) {
                $('#nm-stream-comment-' + cid).fadeOut().remove();

            }
        }
        //refresh information data
        if (typeof data.information !== 'undefined') {
            for (var nid in data.information) {
                var node_container = $('#nm-stream-node-' + nid);
                if (node_container.length > 0) {
                    self.nm_stream_update_node_information(node_container, data.information);
                }
            }
        }

    };


    /**
     * update information of a node entry
     * @param node_container
     * @param new_information_data
     */
    NMStream.prototype.nm_stream_update_node_information = function nm_stream_update_node_information(node_container, new_information_data) {

        var self = this;

        var regresult = node_container.attr('id').split('-');
        var nid = regresult.pop();

        var information_text = node_container.find('.nm-stream-node-information').html();

        if (typeof information_text !== "undefined" && information_text !== null) {

            if (information_text.indexOf('Kommentare ausblenden') === -1) {
                var new_information = node_container.find('.nm-stream-node-information').html($(new_information_data[nid]));

                new NMStreamNode(this, new_information);
            }

            if (self.nm_stream_toggle_open_data[nid] === false) {

                $(new_information).find('.nm_stream_comment_toggle').click();
            }
        }
    }


    /**
     * get update
     */
    NMStream.prototype.nm_stream_get_update = function () {
        var self = this;

        //pause update actions
        //case:
        //submitting content where updates are transmitted in response messages
        if (self.nm_stream_pause_update_timer) {
            clearTimeout(self.nm_stream_get_update_timer);
            self.nm_stream_get_update_timer = setTimeout(self.nm_stream_get_update, 5000);
            return;
        }


        var last_node = $('.nm-stream-node-container').first();

        var nid = 0;
        //if no node has been posted yet
        if (last_node.length !== 0) {
            var regresult = $(last_node).attr('id').split('-');
            nid = regresult.pop();
        }

        var url = '/nm_stream/node/' + nid + '/get_update';

        $.ajax({
            url: url,
            success: function(data) {

                if (data.update_status == 0) {
                    //error
                    console.log("error:");
                    console.log(data);
                } else if (data.update_status == 2) {
                    //new data available
                    self.refresh(data);
                }

            },
            complete: function() {
                // Schedule the next request when the current one's complete
                self.nm_stream_get_update_timer = setTimeout(function(){self.nm_stream_get_update();}, 10000);
            }
        });
    };


    /**
     * textbox change event
     */
    NMStream.prototype.textarea_change = function(textarea, form_container) {
        var self = this;
        form_container = $(form_container);
        if (textarea.val().length > 0) {
            self.enable_action_buttons(form_container);
        } else {
            self.disable_action_buttons(form_container);
        }
    };


    /**
     * Form - disable action buttons
     * @param element
     */
    NMStream.prototype.disable_action_buttons = function(element) {
        var submit = element.find("button[class*=-submit]");
        //var cancel = element.find("button[class*=-cancel]");
        submit.attr('disabled', 'disabled');
        //cancel.attr('disabled', 'disabled');
    };

    /**
     * Form - enable action buttons
     * @param element
     */
    NMStream.prototype.enable_action_buttons = function (element) {
        var submit = element.find("button[class*=-submit]");
        var cancel = element.find("button[class*=-cancel]");
        submit.removeAttr('disabled');
        cancel.removeAttr('disabled');
    };

    /**
     * Form set loading
     * @param element
     */
    NMStream.prototype.nm_stream_form_set_loading = function (element) {
        var body = element.find("textarea");
        var privacy = element.find(".dd-select");
        var submit = element.find("button[class*=-submit]");

        body.attr('disabled', 'disabled');
        privacy.hide();
        this.disable_action_buttons(element);

        var post_spinner_white = this.nm_stream_get_post_spinner_white();

        submit.prepend(post_spinner_white.el);

    }


    /**
     * remove disabled attribute
     * @param {type} element
     * @returns {undefined}
     */
    NMStream.prototype.nm_stream_unset_loading = function (element) {
        var self = this;

        var body = element.find("textarea");
        var privacy = element.find(".dd-select");

        body.removeAttr('disabled');
        privacy.show();
        self.enable_action_buttons(element);

        //stop/hide spinner
        self.post_spinner_white.stop();
    };


    /*
     * load more as infinite spinner
     */
    NMStream.prototype.init_load_more_as_infinite_spinner = function () {
        var self = this;

        $('.view-nm-stream .pager a').once('nm_stream', function () {

            self.post_spinner_load = self.nm_stream_get_post_spinner_load();
            $(this).text('');
            $(this).append(self.post_spinner_load.el);

        });
    };



    /**
     * NMSream confirmation dialog
     */
    NMStream.prototype.confirmation = function(dialog_options, callback_confirm, callback_cancel) {

        //init bootbox dialog
        bootbox.dialog({
            message: dialog_options.message,
            title: dialog_options.title,
            buttons: {
                confirm: {
                    label: dialog_options.confirm_label,
                    className: dialog_options.confirm_label_className,
                    callback: callback_confirm
                },
                cancel: {
                    label: cancel_label,
                    className: cancel_label_className,
                    callback: callback_cancel
                }
            }
        });

    };

    /**
     * get white loading spinner
     * @returns {*}
     */
    NMStream.prototype.nm_stream_get_post_spinner_white = function () {

        var opts = {
            lines: 8, // The number of lines to draw
            length: 2, // The length of each line
            width: 3, // The line thickness
            radius: 4, // The radius of the inner circle
            corners: 1, // Corner roundness (0..1)
            rotate: 0, // The rotation offset
            direction: 1, // 1: clockwise, -1: counterclockwise
            color: '#fff', // #rgb or #rrggbb or array of colors
            speed: 1.2, // Rounds per second
            trail: 60, // Afterglow percentage
            shadow: false, // Whether to render a shadow
            hwaccel: false, // Whether to use hardware acceleration
            className: 'spinner', // The CSS class to assign to the spinner
            zIndex: 2e9, // The z-index (defaults to 2000000000)
            top: 'auto', // Top position relative to parent in px
            left: 'auto' // Left position relative to parent in px
        };

        if (!this.post_spinner_white) {
            //first call -> init spinner
            this.post_spinner_white = new Spinner(opts).spin();
        } else {
            this.post_spinner_white.spin();
        }

        return this.post_spinner_white;
    };

    /**
     * get black loading spinner
     * @returns {*}
     */
    NMStream.prototype.nm_stream_get_post_spinner_black = function () {
        var opts = {
            lines: 8, // The number of lines to draw
            length: 2, // The length of each line
            width: 3, // The line thickness
            radius: 4, // The radius of the inner circle
            corners: 1, // Corner roundness (0..1)
            rotate: 0, // The rotation offset
            direction: 1, // 1: clockwise, -1: counterclockwise
            color: '#333', // #rgb or #rrggbb or array of colors
            speed: 1.2, // Rounds per second
            trail: 60, // Afterglow percentage
            shadow: false, // Whether to render a shadow
            hwaccel: false, // Whether to use hardware acceleration
            className: 'spinner', // The CSS class to assign to the spinner
            zIndex: 2e9, // The z-index (defaults to 2000000000)
            top: 'auto', // Top position relative to parent in px
            left: 'auto' // Left position relative to parent in px
        };

        if (!this.post_spinner_black) {
            //first call -> init spinner
            this.post_spinner_black = new Spinner(opts).spin();
        } else {
            this.post_spinner_black.spin();
        }

        return this.post_spinner_black;
    };

    /**
     * get gray post loading spinner
     * @returns {*}
     */
    NMStream.prototype.nm_stream_get_post_spinner_load = function () {

        var opts = {
            lines: 8, // The number of lines to draw
            length: 2, // The length of each line
            width: 3, // The line thickness
            radius: 4, // The radius of the inner circle
            corners: 1, // Corner roundness (0..1)
            rotate: 0, // The rotation offset
            direction: 1, // 1: clockwise, -1: counterclockwise
            color: '#333', // #rgb or #rrggbb or array of colors
            speed: 1.2, // Rounds per second
            trail: 60, // Afterglow percentage
            shadow: false, // Whether to render a shadow
            hwaccel: false, // Whether to use hardware acceleration
            className: 'spinner', // The CSS class to assign to the spinner
            zIndex: 2e9, // The z-index (defaults to 2000000000)
            top: 'auto', // Top position relative to parent in px
            left: 'auto' // Left position relative to parent in px
        };

        if (!this.post_spinner_load) {
            //first call -> init spinner
            this.post_spinner_load = new Spinner(opts).spin();
        } else {
            this.post_spinner_load.spin();
        }

        return this.post_spinner_load;
    };



}(jQuery));
