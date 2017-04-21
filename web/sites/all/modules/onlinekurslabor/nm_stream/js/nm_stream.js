/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {

    var nm_stream_toggle_open_data = new Array();
    var nm_stream_get_update_timer = false;
    var nm_stream_pause_update_timer = false;


    var nm_stream = {};

    Drupal.behaviors.nm_stream = {

        attach: function(context, settings) {
            nm_stream = new NMStream(context);

        }
    };

    /**
     * constructor
     *
     * @param context
     * @constructor
     */
    function NMStream(context) {
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

        this.post_spinner_white = null;
        this.post_spinner_black = null;
        this.post_spinner_load = null;

        this.init();
    }

    /**
     * init
     */
    NMStream.prototype.init = function() {
        this.init_privacy_widget();
        this.init_bind_events();
        this.init_override_alter();
    };

    /**
     * initialize privacy widget
     */
    NMStream.prototype.init_override_alter = function() {
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

        //cancel button click
        self.init_bind_cancel_button_event();

        //comment toggle click
        self.init_bind_cancel_button_event();

        //post button click
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
     * bind click to cancel button
     */
    NMStream.prototype.init_bind_cancel_button_event = function() {
        var self = this;

        //bind click to cancel button
        $('.nm-stream-add-node-actions .nm-stream-node-cancel').once('nm_stream').click(function() {

            if ($(this).closest('.nm-stream-edit-node-actions').length === 0) {
                //add form
                $('.nm-stream-node-form').show();
                $(this).closest('.nm-stream-node-form-container').find('textarea').val('');
                $(this).closest('form').hide();
                //reset file upload
                $(this).closest('form').find('.fileupload').MultiFile('reset');

            } else {
                //edit form
                $(this).closest('.nm-stream-main').find('.nm-stream-main-body').show();
                $(this).closest('form').remove();
            }

            return false;
        });
    }

    /**
     * bind click to comment toggle
     */
    NMStream.prototype.init_bind_cancel_button_event = function () {
        var self = this;

        //bind comment toggle event
        $('.nm_stream_comment_toggle').once('nm_stream').click(function () {

            return false;
        });
    }

    /**
     * bind post button event
     */
    NMStream.prototype.init_bind_post_button_event = function () {
        var self = this;

    }


        /**
     * refresh / update stream
     */
    NMStream.prototype.refresh = function() {

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
        nm_stream_disable_action_buttons(element);

        post_spinner_white = nm_stream_get_post_spinner_white();

        submit.prepend(post_spinner_white.el);

    }


    /**
     * remove disabled attribute
     * @param {type} element
     * @returns {undefined}
     */
    NMStream.prototype.nm_stream_unset_loading = function (element) {
        var body = element.find("textarea");
        var privacy = element.find(".dd-select");

        body.removeAttr('disabled');
        privacy.show();
        nm_stream_enable_action_buttons(element);

        //stop/hide spinner
        post_spinner_white.stop();
    }

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

        if (!post_spinner_white) {
            //first call -> init spinner
            post_spinner_white = new Spinner(opts).spin();
        } else {
            post_spinner_white.spin();
        }

        return post_spinner_white;
    }

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

        if (!post_spinner_black) {
            //first call -> init spinner
            post_spinner_black = new Spinner(opts).spin();
        } else {
            post_spinner_black.spin();
        }

        return post_spinner_black;
    }

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

        if (!post_spinner_load) {
            //first call -> init spinner
            post_spinner_load = new Spinner(opts).spin();
        } else {
            post_spinner_load.spin();
        }

        return post_spinner_load;
    }


}(jQuery));
