/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

var $ = jQuery;
/**
 * constructor
 *
 * @param context
 * @constructor
 */
function NMStreamNode(nm_stream, context) {

    this.nm_stream = nm_stream;
    this.state = 0;
    this.container = $(context);

    this.init_bind_events();
}

/**
 * bind events
 */
NMStreamNode.prototype.init_bind_events = function () {

    //bin click events
    this.init_bind_post_edit_event();
    this.init_bind_post_submit_event();
    this.init_bind_post_delete_event();
    this.init_bind_post_cancel_event();
    this.init_bind_toggle_comments_event();

    this.init_bind_attachment_delete_event();


    //initilizing comments
    this.init_bind_nm_stream_comments();

};


/**
 * bind bind submit event
 */
NMStreamNode.prototype.init_bind_post_submit_event = function () {
    var self = this;

    self.container.find('.nm-stream-node-submit').once('nm_stream').click(function () {
        //edit form
        var form_container = $(this).closest('form');
        var body = form_container.find('textarea').val();
        var privacy = form_container.find('.dd-selected-value').val();
        var token = form_container.find('.nm-stream-form-token').val();

        var regresult = $(this).closest('form').attr('id').split('-');
        var nid = regresult.pop();

        var url = self.nm_stream.node_edit_url.replace("%nid", nid);
        var data = {body: body, privacy: privacy, token: token};

        //check if attachments need to be uploaded -> user iframe form submit else post
        if (form_container.find('.MultiFile-wrap').children().length > 1) {

            //26.03.2014 - 16:13 - SN
            //privacy field not transmitted
            //fix before submit .. remove after submitting
            var privacy_input_fix = $('<input type="hidden" name="privacy" value="' + privacy + '" />');
            var token_input_fix = $('<input type="hidden" name="token" value="' + token + '" />');
            form_container.append(privacy_input_fix);
            form_container.append(token_input_fix);

            form_container.attr("action", url);
            form_container.submit();

            privacy_input_fix.remove();
            token_input_fix.remove();

            //unbind all other iframe load bindings first
            $('#nm_stream_hidden_upload').bind('load', function () {

                //reset textarea
                form_container.find('textarea').val('');
                //reset file upload
                form_container.find('.fileupload').MultiFile('reset');


                data = $.parseJSON($(this).contents().find('body').first().text());

                if (data !== null) {
                    if (data.status === 1) {
                        //display new Post
                        //fix, new nodes could not be edited without views-row div around
                        //attach behavior
                        var updated_node = $(form_container).closest('.views-row').html($(data.updated_node).fadeIn()).find(".nm-stream-node-container");
                        //attach behavior
                        self.container = updated_node;
                        self.init_bind_events();
                        self.nm_stream.init_multifile_upload();
                        self.nm_stream.init_privacy_widget();

                    }
                }

                //enable button
                self.nm_stream.nm_stream_unset_loading(form_container);
                self.nm_stream.nm_stream_pause_update_timer = false;

                //todo maybe safe.. could kill other simultaneously running bindings
                $(this).unbind();

            });

        }

        //disable button
        self.nm_stream.nm_stream_form_set_loading(form_container);
        self.nm_stream.nm_stream_pause_update_timer = true;

        //iframe submission, exit!

        if (form_container.find('.MultiFile-wrap').children().length > 1) {
            return false;
        }

        $.post(url, data, function (data) {
            if (data.status === 1) {
                //save succeed

                //display updated post
                var updated_node = $(form_container).closest('.views-row').html($(data.updated_node).fadeIn()).find(".nm-stream-node-container");
                //attach behavior
                self.container = updated_node;
                self.init_bind_events();
                self.nm_stream.init_multifile_upload();
                self.nm_stream.init_privacy_widget();


            } else {
                //error handling todo here

            }
            //enable button
            self.nm_stream.nm_stream_unset_loading(form_container);

            self.nm_stream.nm_stream_pause_update_timer = false;
        });

        return false;
    });
}


/**
 * bind bind toggle event
 */
NMStreamNode.prototype.init_bind_toggle_comments_event = function () {
    var self = this;

    //bind toggle event
    this.container.find('.nm_stream_comment_toggle').once('nm_stream').click(function() {
        var toggle_button = $(this)
        //todo submit new comment

        var comments_container = toggle_button.closest('.nm-stream-comments').find('.nm-stream-comments-container');
        var regresult = $(this).closest('.nm-stream-node-container').attr('id').split('-');
        var nid = regresult.pop();

        var url = self.nm_stream.node_get_all_comments_url.replace("%nid", nid);

        $(this).attr('disabled', 'disabled');


        //just show/hide
        var more_comments = $(toggle_button).next('span').length === 0; //check if caret span is set -> more comments can be loaded

        if (self.nm_stream.nm_stream_toggle_open_data[nid] === true ||
            self.nm_stream.nm_stream_toggle_open_data[nid] === false ||
            more_comments) {
            //case: if no more comments are available to load
            if (typeof self.nm_stream.nm_stream_toggle_open_data[nid] === 'undefined') {
                self.nm_stream.nm_stream_toggle_open_data[nid] = true;
            }

            //toggle comments container
            if (self.nm_stream.nm_stream_toggle_open_data[nid] === true) {
                comments_container.slideUp();
                self.nm_stream.nm_stream_toggle_open_data[nid] = false;
                $(toggle_button).next('span').fadeIn();
                var count_comments = comments_container.find('.nm-stream-comment').length;
                $(toggle_button).html('Kommentare ausblenden');
                $(toggle_button).html('alle Kommentare anzeigen (' + count_comments + ')');
            } else {
                comments_container.slideDown();
                self.nm_stream.nm_stream_toggle_open_data[nid] = true;
                $(toggle_button).next('span').hide();
                $(toggle_button).html('Kommentare ausblenden');

            }
            return false;
        }

        self.nm_stream.post_spinner_black = self.nm_stream.nm_stream_get_post_spinner_black();

        toggle_button.parent().append(self.nm_stream.post_spinner_black.el);

        //load additional items
        $.post(url, '', function(data) {
            if (data.status === 1) {
                //save that this item was toggeled
                self.nm_stream.nm_stream_toggle_open_data[nid] = true;
                $(toggle_button).next('span').hide();
                $(toggle_button).html('Kommentare ausblenden');

                //request succeed
                //display new Post
                $(comments_container).html($(data.comments_container).fadeIn());

                //attach behavior
                self.init_bind_nm_stream_comments();

                self.nm_stream.post_spinner_black.stop();

            } else {
                //error handling todo here

            }

        });

        return false;

    });
};


/**
 * bind edit event
 */
NMStreamNode.prototype.init_bind_post_edit_event = function () {

    var self = this;


    //bind click to edit button
    self.container.find('.nm-stream-node-edit').once('nm_stream').click(function() {
        var edit_button = $(this)

        var regresult = self.container.attr('id').split('-');
        var nid = regresult.pop();

        var url = self.nm_stream.node_edit_url.replace("%nid", nid);

        var post_spinner_black = self.nm_stream.nm_stream_get_post_spinner_black();

        edit_button.parent().append(post_spinner_black.el);

        edit_button.attr('disabled', 'disabled');

        //disable button
        $.post(url, '', function(data) {
            if (data.status === 1) {
                //request succeed
                if (self.container.find('.nm-stream-main').first().find('form').length === 0) {

                    //display the edit form
                    var edit_form = self.container.find('.nm-stream-main-body').first().hide();
                    self.container.find('.nm-stream-main').first().prepend($(data.node_edit_form));

                    //attach behavior
                    self.container.find('textarea').autosize();

                    self.init_bind_events();
                    self.nm_stream.init_multifile_upload();
                    self.nm_stream.init_privacy_widget();
                }

                //append new node

            } else {
                //error handling todo here

            }

            post_spinner_black.stop();
            edit_button.removeAttr('disabled');

        });

        return false;
    });

};

/**
 * bind delete events
 */
NMStreamNode.prototype.init_bind_post_delete_event = function () {

    var self = this;

    //bind click to delete button
    this.container.find('.nm-stream-node-delete').once('nm_stream').click(function() {
        var delete_button = $(this)

        var regresult = self.container.attr('id').split('-');
        var nid = regresult.pop();
        var token = self.container.find('.nm-stream-form-token').val();

        var url = self.nm_stream.node_delete_url.replace("%nid", nid).replace("%token", token);

        var post_spinner_black = self.nm_stream.nm_stream_get_post_spinner_black();

        delete_button.parent().append(post_spinner_black.el);

        bootbox.dialog({
            message: "Wollen Sie diesen Inhalt wirklich löschen?",
            title: "Inhalt löschen",
            buttons: {
                danger: {
                    label: "Löschen!",
                    className: "btn-danger",
                    callback: function() {
                        //ajax request
                        $.post(url, '', function(data) {
                            if (data.status === 1) {
                                //request succeed
                                self.container.fadeOut().remove();
                            } else {
                                //error handling todo here

                            }


                            //check if node updates were made in meantime
                            if (data.update_status === 2) {
                                self.container.refresh(data);
                            }

                        });

                    }
                },
                cancel: {
                    label: "Abbrechen",
                    className: "btn-info",
                    callback: function() {
                        post_spinner_black.stop();
                    }
                }
            }
        });

        return false;

    });

};



/**
 * bind cancel button events
 */
NMStreamNode.prototype.init_bind_post_cancel_event = function () {

    var self = this;
    //bind click to cancel button
    this.container.find('.nm-stream-node-cancel').once('nm_stream').click(function () {

        //edit form
        $(this).closest('.nm-stream-main').find('.nm-stream-main-body').show();
        $(this).closest('form').remove();

        return false;
    });


};

/**
 * initialize comments
 */
NMStreamNode.prototype.init_bind_nm_stream_comments = function () {

    var self = this;

    this.container.find(".nm-stream-comment").once("nm_stream").each(function(index) {
        new NMStreamComment(self.nm_stream, self, this);

    });

    //initialize dummy comment text field if no comments are available yet
    //that's not very neat, but works ;)
    var dummy_comment = new NMStreamComment(self.nm_stream, self, self.container);



};



/**
 * bind attachment delete event
 */
NMStreamNode.prototype.init_bind_attachment_delete_event = function () {
    var self = this;

    this.container.find('.nm-stream-file-delete').once('nm_stream').click(function() {
        var delete_button = $(this)

        var node_container = delete_button.closest('.nm-stream-node-container');
        var regresult = node_container.attr('id').split('-');
        var nid = regresult.pop();

        var regresult_attachment = delete_button.attr('id').split('-');
        var fid = regresult_attachment.pop();
        var token = node_container.find('.nm-stream-form-token').val();

        var url = self.nm_stream.node_delete_attachment_url.replace("%nid", nid).replace("%fid", fid).replace("%token", token);

        self.nm_stream.post_spinner_black = self.nm_stream.nm_stream_get_post_spinner_black();

        delete_button.parent().append(self.nm_stream.post_spinner_black.el);

        bootbox.dialog({
            message: "Wollen Sie die Datei wirklich löschen?",
            title: "Datei löschen",
            buttons: {
                danger: {
                    label: "Löschen!",
                    className: "btn-danger",
                    callback: function() {
                        //ajax request
                        $.post(url, '', function(data) {
                            if (data.status === 1) {
                                //request succeed,
                                var attachments_container = delete_button.closest('.nm-stream-attachments');

                                //remove file
                                delete_button.parent().fadeOut().remove();
                                //remove attachment title, if no attachments are attached to the node

                                if (attachments_container.find('.nm-stream-attachments-main').children().length === 0) {
                                    attachments_container.fadeOut().remove();
                                }

                            } else {
                                //error handling todo here

                            }
                            //enable button
                            //nm_stream_unset_loading(form_container);

                            //check if node updates were made in meantime
                            if (data.update_status === 2) {
                                self.nm_stream.nm_stream_handle_node_updates(data);
                            }

                        });

                    }
                },
                cancel: {
                    label: "Abbrechen",
                    className: "btn-info",
                    callback: function() {
                        self.nm_stream.post_spinner_black.stop();
                    }
                }
            }
        });

        return false;
    });

};




/**
 * add
 */
NMStreamNode.prototype.add = function () {
    //TBI
};

/**
 * update
 */
NMStreamNode.prototype.update = function () {
    //TBI
};

/**
 * delete
 */
NMStreamNode.prototype.delete = function () {
    //TBI
};

/**
 * delete
 */
NMStreamNode.prototype.refresh = function () {
    //TBI
};





