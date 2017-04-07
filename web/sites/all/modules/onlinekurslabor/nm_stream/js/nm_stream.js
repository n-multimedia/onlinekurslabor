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
    NMStream.prototype.init_bind_events = function() {
        var self = this;
        //bind click to dummy text field
        $('.nm-stream-node-form-container').once('nm_stream').click(function() {
            $(this).find('.nm-stream-node-form').hide();
            var form_container = this;
            var form = $(this).find('form');
            form.show();
            form.find('textarea').autosize();
            form.find('textarea').bind('input propertychange', function() {
                self.textarea_change($(this), form_container);
            });
            //call initial event to disable buttons
            self.textarea_change(form.find('textarea'), form_container);
            form.find('textarea').focus();
        });

    };

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


}(jQuery));
