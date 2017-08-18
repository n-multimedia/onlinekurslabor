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
function NMStreamComment(nm_stream, node, context) {

    this.nm_stream = nm_stream;
    this.node = node;
    this.state = 0;
    this.container = $(context);


    //bind events
    this.init_bind_events();

}

/**
 * bind events
 */
NMStreamComment.prototype.init_bind_events = function () {

    //bind click to dummy text field
    this.init_bind_dummy_textfield_event();

    this.init_bind_commment_submit_button_event();
    this.init_bind_comment_edit_event();
    this.init_bind_comment_delete_event();
    this.init_bind_comment_cancel_event();

    this.nm_stream.init_bindings_callback(this.container);

};

/**
 * bind dummy text div events
 */
NMStreamComment.prototype.init_bind_dummy_textfield_event = function () {
    var self = this;
    //bind click to dummy text field
    self.container.find(".nm-stream-comments-form").once('nm_stream').click(function() {
        var form_container = this;
        $(this).find('.nm-stream-comment-form').hide();
        var form = $(this).find('form');
        form.show();
        form.find('textarea').bind('input propertychange', function() {
            self.nm_stream.textarea_change($(this), form_container);
        });
        //call initial event to disable buttons
        self.nm_stream.textarea_change(form.find('textarea'), form_container);
        form.find('textarea').autosize();
        form.find('textarea').focus();
    });


}


/**
 * bind post button events
 */
NMStreamComment.prototype.init_bind_commment_submit_button_event = function () {
    var self = this;


    //bind click to post button
    self.container.find('.nm-stream-comment-submit').once('nm_stream').click(function() {
        //submit new comment
        var post_button = $(this)

        if ($(this).closest('.nm-stream-edit-comment-actions').length === 0) {
            //add
            var form_container = $(this).closest('.nm-stream-comment-form-container');
            var body = form_container.find('textarea').val();

            var regresult = form_container.find('form').attr('id').split('-');
            var nid = regresult.pop();
            var token = form_container.find('.nm-stream-form-token').val();

            var url = self.nm_stream.comment_add_url.replace("%nid", nid);

            var data = {body: body, token: token};

            //disable button
            self.nm_stream.nm_stream_form_set_loading(form_container);

            self.nm_stream.nm_stream_pause_update_timer = true;

            $.post(url, data, function(data) {
                if (data.update_status === 2) {
                    self.nm_stream.refresh(data);
                }

                if (data.status === 1) {
                    //save succeed
                    //reset textarea

                    form_container.find('textarea').val('');

                    //special handling for ajax comment functionality
                    var only_comment_function = post_button.closest('.nm-stream-node-container').find('.nm-stream-node').length < 1;

                    //first comment, so node object ist available
                    if (typeof data.node === "undefined" ||  (typeof data.node !== "undefined" && only_comment_function)) {

                        //console.log(only_comment_function);
                        //check if we have a comment container below the post button (source was an initial node without comments)
                        if (post_button.closest('.nm-stream-node-container').find('.nm-stream-comments-section').length > 0) {

                            //first show comment form which is below the node content
                            post_button.closest('.nm-stream-node-container').find('.nm-stream-comments-section .nm-stream-comments-form').show();


                            post_button = post_button.closest('.nm-stream-node-container').find('.nm-stream-comments-section form .nm-stream-comment-submit');

                            //remove comment init add form
                            post_button.closest('.nm-stream-node-container').find('.nm-stream-node .nm-stream-comments-form').remove();
                        }

                        //display new Post
                        var new_comment = [];

                        if (only_comment_function) {

                            //special case in for node comments only - for kooperationsvereinbarung-comments
                            //console.log(post_button);
                            new_comment = ($(data.comment)).insertAfter(post_button.closest('.nm-stream-node-container').parent().find('.nm-stream-comments-section .nm-stream-comments-container .nm-stream-comment').last()).fadeIn();

                            //attach behavior
                            new NMStreamComment(self.nm_stream, self.node, new_comment);


                        } else {
                            //fix
                            //do not load information info, because we did start with <5 (limit) comments
                            //every new comment is already visible
                            //new_comment = post_button.closest('.nm-stream-comments').find('.nm-stream-comments-container').prepend(.fadeIn());

                            var node_container = post_button.closest('.nm-stream-node-container');


                            new_comment = ($(data.comment)).insertBefore(post_button.closest('.nm-stream-comments').find('.nm-stream-comments-container .nm-stream-comment').first()).fadeIn();
                            //fix, new nodes could not be edited without views-row div around

                            //attach behavior
                            new NMStreamComment(self.nm_stream, self.node, new_comment);

                            self.nm_stream.nm_stream_update_node_information(node_container, data.information);

                        }


                    } else {

                        var view_row = post_button.closest('.views-row');
                        post_button.closest('.views-row').find("a").remove();
                        post_button.closest('.nm-stream-node-container').remove();

                        //append new node
                        var new_node = view_row.html($(data.node).fadeIn()).find(".nm-stream-node-container");

                        //attach behavior
                        new NMStreamNode(self.nm_stream, new_node);
                    }

                } else {
                    //error handling todo here
                }

                //enable button
                self.nm_stream.nm_stream_unset_loading(form_container);
                self.nm_stream.nm_stream_pause_update_timer = false;
            });

        } else {

            //edit
            var form_container = $(this).closest('form');

            var body = form_container.find('textarea').val();
            var token = form_container.find('.nm-stream-form-token').val();

            var regresult = form_container.attr('id').split('-');
            var cid = regresult.pop();

            var url = self.nm_stream.comment_edit_url.replace("%cid", cid);

            var data = {body: body, token: token};

            //disable button
            self.nm_stream.nm_stream_form_set_loading(form_container);

            $.post(url, data, function(data) {
                if (data.status === 1) {
                    //save succeed
                    var updated_comment = $(form_container).closest('.nm-stream-comment').html($(data.updated_comment).fadeIn().html());


                    //attach behavior
                    self.container = updated_comment;
                    self.init_bind_events();


                } else {
                    //error handling todo here
                }

                //enable button
                self.nm_stream.nm_stream_unset_loading(form_container);
            });
        }

        return false;
    });



}
/**
 * bind edit button events
 */
NMStreamComment.prototype.init_bind_comment_edit_event = function () {
    var self = this;

    //bind click to edit button
    self.container.closest(".nm-stream-comment").find('.nm-stream-comment-edit').once('nm_stream').click(function() {
        var edit_button = $(this);

        var comment_container = edit_button.closest('.nm-stream-comment');
        var regresult = comment_container.attr('id').split('-');
        var cid = regresult.pop();

        var url = self.nm_stream.comment_edit_url.replace("%cid", cid);

        //disable button
        //nm_stream_form_set_loading(form_container);

        self.nm_stream.post_spinner_black = self.nm_stream.nm_stream_get_post_spinner_black();

        edit_button.parent().append(self.nm_stream.post_spinner_black.el);

        $.post(url, '', function(data) {
            if (data.status === 1) {
                //request succeed

                //display the edit form
                comment_container.find('.nm-stream-main-body').hide();
                //prevent creating more than 1 forms
                if (comment_container.find('.nm-stream-main').find('form').length === 0) {
                    var edit_form = comment_container.find('.nm-stream-main').prepend($(data.comment_edit_form));

                    edit_form.find('textarea').autosize();

                    self.init_bind_events();


                } else {
                    comment_container.find('.nm-stream-main').find('form').show();
                }

                //append new node
                self.nm_stream.post_spinner_black.stop();

            }

            //enable button
            //nm_stream_unset_loading(form_container);
        });

        return false;
    });

}
/**
 * bind delete button events
 */
NMStreamComment.prototype.init_bind_comment_delete_event = function () {
    var self = this;

    self.container.find('.nm-stream-comment-delete').once('nm_stream').click(function() {
        var delete_button = $(this)
        var comment_container = delete_button.closest('.nm-stream-comment');
        var regresult = comment_container.attr('id').split('-');
        var cid = regresult.pop();
        var token = comment_container.closest('.nm-stream-node-container').find('.nm-stream-form-token').val();

        var url = self.nm_stream.comment_delete_url.replace("%cid", cid).replace("%token", token);


        self.nm_stream.post_spinner_black = self.nm_stream.nm_stream_get_post_spinner_black();

        delete_button.parent().append(self.nm_stream.post_spinner_black.el);

        bootbox.dialog({
            message: "Wollen Sie diesen Kommentar wirklich löschen?",
            title: "Kommentar löschen",
            buttons: {
                danger: {
                    label: "Löschen!",
                    className: "btn-danger",
                    callback: function() {
                        //ajax request
                        $.post(url, '', function(data) {
                            if (data.status === 1) {
                                //request succeed
                                comment_container.fadeOut().remove();
                            }

                            //enable button
                            //nm_stream_unset_loading(form_container);

                            //check if node updates were made in meantime
                            if (data.update_status === 2) {
                                //console.log(data);
                                self.nm_stream.refresh(data);
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


}
/**
 * bind cancel button events
 */
NMStreamComment.prototype.init_bind_comment_cancel_event = function () {
    var self = this;

    //bind click to cancel button
    self.container.find('.nm-stream-comment-cancel').once('nm_stream').click(function() {
        if ($(this).closest('.nm-stream-edit-comment-actions').length === 0) {
            //add form
            $(this).closest('.nm-stream-node-container').find('.nm-stream-comment-form').show();
            $(this).closest('.nm-stream-comment-form-container').find('textarea').val('');
            $(this).closest('form').hide();

        } else {
            //edit form
            $(this).closest('.nm-stream-main').find('.nm-stream-main-body').show();
            $(this).closest('form').remove();
        }
        return false;
    });

}




/**
 * add
 */
NMStreamComment.prototype.add = function () {

};

/**
 * update
 */
NMStreamComment.prototype.update = function () {

};

/**
 * delete
 */
NMStreamComment.prototype.delete = function () {

};

/**
 * refresh
 */
NMStreamComment.prototype.refresh = function () {

};


