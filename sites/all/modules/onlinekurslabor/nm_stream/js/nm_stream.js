/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {
    
    var nm_stream_toggle_open_data = new Array();
    var nm_stream_get_update_timer = false;
    var nm_stream_pause_update_timer = false;

    Drupal.behaviors.nm_stream = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {

            /*
             * override alert function
             */
            /* new funky alert */
            function nm_stream_alert(msg) {
                /* here goes your funky alert implementation */
                bootbox.alert(msg);
            }

            (function() {
                var _alert = window.alert;                   // <-- Reference
                window.alert = function(str) {
                    //return _alert.apply(this, arguments);  // <-- The universal method
                    nm_stream_alert(str);                             // Suits for this case
                };
            })();

            /*
             * privacy dropdown
             */
            $('#nm-stream-add-node-privacy').ddslick();
            $('[id^=nm-stream-edit-node-privacy-]').ddslick();
            /*
             *  NODE
             */
            //bind click to edit button
            $('.nm-stream-node-delete').once('nm_stream').click(function() {
                var delete_button = $(this)

                var node_container = delete_button.closest('.nm-stream-node-container');
                var regresult = node_container.attr('id').split('-');
                var nid = regresult.pop();

                var url = '/nm_stream/node/' + nid + '/delete';


                post_spinner_black = nm_stream_get_post_spinner_black();

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
                                        node_container.fadeOut().remove();
                                    } else {
                                        //error handling todo here

                                    }
                                    //enable button
                                    //nm_stream_unset_loading(form_container);

                                    //check if node updates were made in meantime
                                    if (data.update_status === 2) {
                                        nm_stream_handle_node_updates(data);
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

            //bind click to edit button
            $('.nm-stream-node-edit').once('nm_stream').click(function() {
                var edit_button = $(this)

                var node_container = edit_button.closest('.nm-stream-node-container');
                var regresult = node_container.attr('id').split('-');
                var nid = regresult.pop();

                var url = '/nm_stream/node/' + nid + '/edit';

                post_spinner_black = nm_stream_get_post_spinner_black();

                edit_button.parent().append(post_spinner_black.el);


                edit_button.attr('disabled', 'disabled');

                //disable button
                //nm_stream_form_set_loading(form_container);
                $.post(url, '', function(data) {
                    if (data.status === 1) {
                        //request succeed
                        if (node_container.find('.nm-stream-main').first().find('form').length === 0) {

                            //display the edit form
                            var edit_form = node_container.find('.nm-stream-main-body').hide();
                            node_container.find('.nm-stream-main').first().prepend($(data.node_edit_form));
                            //todo add form here
                            //node_container.find('.nm-stream-main').first().prepend(data.node_edit_form);
                            //html(data.node_edit_form)
                            //attach behavior
                            Drupal.attachBehaviors(edit_form);
                        }

                        //append new node

                    } else {
                        //error handling todo here

                    }

                    post_spinner_black.stop();
                    edit_button.removeAttr('disabled');

                    //enable button
                    //nm_stream_unset_loading(form_container);
                });

                return false;
            });

            //bind click to dummy text field
            $('.nm-stream-node-form-container').once('nm_stream').click(function() {
                $(this).find('.nm-stream-node-form').hide();
                var form_container = this;
                var form = $(this).find('form');
                form.show();
                form.find('textarea').autosize();
                form.find('textarea').bind('input propertychange', function() {
                    nm_stream_textarea_change($(this), form_container);
                });
                //call initial event to disable buttons
                nm_stream_textarea_change(form.find('textarea'), form_container);
                form.find('textarea').focus();
            });

            //bind click to post button
            $('.nm-stream-node-submit').once('nm_stream').click(function() {
                var post_button = $(this)

                if ($(this).closest('.nm-stream-edit-node-actions').length === 0) {
                    //add form
                    var form_container = $(this).closest('.nm-stream-node-form-container');
                    var body = form_container.find('textarea').val();
                    var privacy = form_container.find('.dd-selected-value').val();

                    var url = $(form_container).find('form#nm-stream-add-node').attr('action'); // '/nm_stream/node/add';
                    var data = {body: body, privacy: privacy};


                    //check if attachments need to be uploaded -> user iframe form submit else post 
                    if (form_container.find('.MultiFile-wrap').children().length > 1) {

                        //26.03.2014 - 16:13 - SN
                        //privacy field not transmitted
                        //fix before submit .. remove after submitting
                        var privacy_input_fix = $('<input type="hidden" name="privacy" value="' + privacy + '" />');
                        form_container.find('form').append(privacy_input_fix);

                        $('#nm-stream-add-node').submit();

                        privacy_input_fix.remove();

                        //privacy_input_fix.remove();

                        $('#nm_stream_hidden_upload').bind('load', function() {

                            //reset textarea
                            form_container.find('textarea').val('');
                            //reset file upload
                            form_container.find('.fileupload').MultiFile('reset');

                            data = $.parseJSON($(this).contents().find('body').first().text());

                            if (data !== null) {
                                if (data.update_status === 2) {
                                    nm_stream_handle_node_updates(data);
                                }
                                //add new node
                                if (data.status === 1) {
                                    //display new Post
                                    var new_node = $('.nm-stream-node-container').closest('.view-content').prepend($(data.node).fadeIn());
                                    //fix, new nodes could not be edited without views-row div around
                                    //attach behavior
                                    Drupal.attachBehaviors(new_node);
                                }
                            }

                            //enable button
                            nm_stream_unset_loading(form_container);
                            nm_stream_pause_update_timer = false;

                            //todo maybe safe.. could kill other simultaneously running bindings
                            $(this).unbind();

                        });

                    }

                    //disable button
                    nm_stream_form_set_loading(form_container);
                    nm_stream_pause_update_timer = true;

                    //iframe submission, exit!
                    if (form_container.find('.MultiFile-wrap').children().length > 1) {
                        return false;
                    }


                    $.post(url, data, function(data) {

                        //first check if node updates were made in meantime
                        if (data.update_status === 2) {
                            nm_stream_handle_node_updates(data);
                        }
                        //add new node
                        if (data.status === 1) {
                            //save succeed
                            //reset textarea
                            form_container.find('textarea').val('');

                            //display new Post
                            var new_node = $('.nm-stream-node-container').closest('.view-content').prepend($(data.node).fadeIn());
                            //fix, new nodes could not be edited without views-row div around
                            //attach behavior
                            Drupal.attachBehaviors(new_node);

                            //append new node

                        } else {
                            //error handling todo here

                        }

                        //enable button
                        nm_stream_unset_loading(form_container);
                        nm_stream_pause_update_timer = false;

                    });
                } else {
                    //edit form    
                    var form_container = $(this).closest('form');
                    var body = form_container.find('textarea').val();
                    var privacy = form_container.find('.dd-selected-value').val();

                    var regresult = $(this).closest('form').attr('id').split('-');
                    var nid = regresult.pop();

                    var url = $(form_container).attr('action'); //'/nm_stream/node/' + nid + '/edit';
                    var data = {body: body, privacy: privacy};


                    //check if attachments need to be uploaded -> user iframe form submit else post 
                    if (form_container.find('.MultiFile-wrap').children().length > 1) {

                        //26.03.2014 - 16:13 - SN
                        //privacy field not transmitted
                        //fix before submit .. remove after submitting
                        var privacy_input_fix = $('<input type="hidden" name="privacy" value="' + privacy + '" />');
                        form_container.append(privacy_input_fix);

                        form_container.submit();

                        privacy_input_fix.remove();

                        //unbind all other iframe load bindings first
                        $('#nm_stream_hidden_upload').bind('load', function() {

                            //reset textarea
                            form_container.find('textarea').val('');
                            //reset file upload
                            form_container.find('.fileupload').MultiFile('reset');


                            data = $.parseJSON($(this).contents().find('body').first().text());

                            if (data !== null) {
                                if (data.status === 1) {
                                    //display new Post
                                    var updated_node = $(form_container).closest('.views-row').html($(data.updated_node).fadeIn());
                                    //fix, new nodes could not be edited without views-row div around
                                    //attach behavior
                                    Drupal.attachBehaviors(updated_node);
                                }
                            }

                            //enable button
                            nm_stream_unset_loading(form_container);
                            nm_stream_pause_update_timer = false;

                            //todo maybe safe.. could kill other simultaneously running bindings
                            $(this).unbind();

                        });

                    }

                    //disable button
                    nm_stream_form_set_loading(form_container);
                    nm_stream_pause_update_timer = true;

                    //iframe submission, exit!

                    if (form_container.find('.MultiFile-wrap').children().length > 1) {
                        return false;
                    }

                    $.post(url, data, function(data) {
                        if (data.status === 1) {
                            //save succeed

                            //display updated post
                            var updated_node = $(form_container).closest('.views-row').html($(data.updated_node).fadeIn());
                            //attach behavior
                            Drupal.attachBehaviors(updated_node);


                        } else {
                            //error handling todo here

                        }
                        //enable button
                        nm_stream_unset_loading(form_container);

                        nm_stream_pause_update_timer = false;
                    });

                }
                return false;
            });

            //bind click to cancel button
            $('.nm-stream-node-cancel').once('nm_stream').click(function() {

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

            //bind toggle event
            $('.nm_stream_comment_toggle').once('nm_stream').click(function() {
                var toggle_button = $(this)
                //todo submit new comment

                var comments_container = toggle_button.closest('.nm-stream-comments').find('.nm-stream-comments-container');
                var regresult = $(this).closest('.nm-stream-node-container').attr('id').split('-');
                var nid = regresult.pop();

                var url = '/nm_stream/node/' + nid + '/get_all_comments';

                $(this).attr('disabled', 'disabled');


                //just show/hide
                var more_comments = $(toggle_button).next('span').length === 0; //check if caret span is set -> more comments can be loaded

                if (nm_stream_toggle_open_data[nid] === true || nm_stream_toggle_open_data[nid] === false ||
                        more_comments)
                {
                    //case: if no more comments are available to load
                    if (typeof nm_stream_toggle_open_data[nid] === 'undefined') {
                        nm_stream_toggle_open_data[nid] = true;
                    }

                    //toggle comments container
                    if (nm_stream_toggle_open_data[nid] === true) {
                        comments_container.slideUp();
                        nm_stream_toggle_open_data[nid] = false;
                        $(toggle_button).next('span').fadeIn();
                        var count_comments = comments_container.find('.nm-stream-comment').length;
                        $(toggle_button).html('Kommentare ausblenden');
                        $(toggle_button).html('alle Kommentare anzeigen (' + count_comments + ')');
                    } else {
                        comments_container.slideDown();
                        nm_stream_toggle_open_data[nid] = true;
                        $(toggle_button).next('span').hide();
                        $(toggle_button).html('Kommentare ausblenden');

                    }
                    return false;
                }

                post_spinner_black = nm_stream_get_post_spinner_black();

                toggle_button.parent().append(post_spinner_black.el);

                //load additional items
                $.post(url, '', function(data) {
                    if (data.status === 1) {
                        //save that this item was toggeled
                        nm_stream_toggle_open_data[nid] = true;
                        $(toggle_button).next('span').hide();
                        $(toggle_button).html('Kommentare ausblenden');

                        //request succeed
                        //display new Post
                        $(comments_container).html($(data.comments_container).fadeIn());

                        //attach behavior
                        Drupal.attachBehaviors(comments_container);

                        post_spinner_black.stop();

                    } else {
                        //error handling todo here

                    }

                });

                return false;

            });
            /*
             * attachments
             */

            $('.nm-stream-file-delete').once('nm_stream').click(function() {
                var delete_button = $(this)

                var node_container = delete_button.closest('.nm-stream-node-container');
                var regresult = node_container.attr('id').split('-');
                var nid = regresult.pop();

                var regresult_attachment = delete_button.attr('id').split('-');
                var fid = regresult_attachment.pop();

                var url = '/nm_stream/node/' + nid + '/file/' + fid + '/delete';

                post_spinner_black = nm_stream_get_post_spinner_black();

                delete_button.parent().append(post_spinner_black.el);

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
                                        //console.log(attachments_container);
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
                                        nm_stream_handle_node_updates(data);
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

            /*
             *  COMMENTS
             */

            $('.nm-stream-comment-delete').once('nm_stream').click(function() {
                var delete_button = $(this)

                var comment_container = delete_button.closest('.nm-stream-comment');
                var regresult = comment_container.attr('id').split('-');
                var cid = regresult.pop();

                var url = '/nm_stream/comment/' + cid + '/delete';


                post_spinner_black = nm_stream_get_post_spinner_black();

                delete_button.parent().append(post_spinner_black.el);

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
                                    } else {
                                        //error handling todo here

                                    }
                                    //enable button
                                    //nm_stream_unset_loading(form_container);

                                    //check if node updates were made in meantime
                                    if (data.update_status === 2) {
                                        nm_stream_handle_node_updates(data);
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

            //bind click to edit button
            $('.nm-stream-comment-edit').once('nm_stream').click(function() {
                var edit_button = $(this)

                var comment_container = edit_button.closest('.nm-stream-comment');
                var regresult = comment_container.attr('id').split('-');
                var cid = regresult.pop();

                var url = '/nm_stream/comment/' + cid + '/edit';

                //disable button
                //nm_stream_form_set_loading(form_container);

                post_spinner_black = nm_stream_get_post_spinner_black();

                edit_button.parent().append(post_spinner_black.el);

                $.post(url, '', function(data) {
                    if (data.status === 1) {
                        //request succeed

                        //display the edit form
                        comment_container.find('.nm-stream-main-body').hide();
                        //prevent creating more than 1 forms
                        if (comment_container.find('.nm-stream-main').find('form').length === 0) {
                            var edit_form = comment_container.find('.nm-stream-main').prepend($(data.comment_edit_form));
                            //todo add form here
                            //node_container.find('.nm-stream-main').first().prepend(data.node_edit_form);
                            //html(data.node_edit_form)
                            //attach behavior
                            Drupal.attachBehaviors(edit_form);
                        } else {
                            comment_container.find('.nm-stream-main').find('form').show();
                        }

                        //append new node

                        post_spinner_black.stop();

                    } else {
                        //error handling todo here

                    }

                    //enable button
                    //nm_stream_unset_loading(form_container);
                });

                return false;
            });

            //bind click to dummy text field
            $('.nm-stream-comment-form-container').once('nm_stream').click(function() {
                var form_container = this;
                $(this).find('.nm-stream-comment-form').hide();
                var form = $(this).find('form');
                form.show();
                form.find('textarea').bind('input propertychange', function() {
                    nm_stream_textarea_change($(this), form_container);
                });
                //call initial event to disable buttons
                nm_stream_textarea_change(form.find('textarea'), form_container);
                form.find('textarea').autosize();
                form.find('textarea').focus();
            });

            //bind click to post button
            $('.nm-stream-comment-submit').once('nm_stream').click(function() {
                //submit new comment
                var post_button = $(this)
                if ($(this).closest('.nm-stream-edit-comment-actions').length === 0) {
                    //add
                    var form_container = $(this).closest('.nm-stream-comment-form-container');
                    var body = form_container.find('textarea').val();

                    var regresult = form_container.find('form').attr('id').split('-');
                    var nid = regresult.pop();

                    var url = '/nm_stream/node/' + nid + '/comment/add';
                    var data = {body: body};

                    //disable button
                    nm_stream_form_set_loading(form_container);

                    nm_stream_pause_update_timer = true;

                    $.post(url, data, function(data) {
                        if (data.update_status === 2) {
                            nm_stream_handle_node_updates(data);
                        }

                        if (data.status === 1) {
                            //save succeed
                            //reset textarea
                            form_container.find('textarea').val('');

                            //first comment, so node object ist available
                            if (typeof data.node === "undefined") {

                                //check if we have a comment container below the post button (source was an initial node without comments)
                                if (post_button.closest('.nm-stream-node-container').find('.nm-stream-comments-section').length > 0) {

                                    //first show comment form which is below the node content
                                    post_button.closest('.nm-stream-node-container').find('.nm-stream-comments-section .nm-stream-comments-form').show();


                                    post_button = post_button.closest('.nm-stream-node-container').find('.nm-stream-comments-section form .nm-stream-comment-submit');

                                    //remove comment init add form
                                    post_button.closest('.nm-stream-node-container').find('.nm-stream-node .nm-stream-comments-form').remove();
                                }

                                //display new Post
                                var new_comment = post_button.closest('.nm-stream-comments').find('.nm-stream-comments-container').prepend($(data.comment).fadeIn());

                                //fix
                                //do not load information info, because we did start with <5 (limit) comments
                                //every new comment is already visible

                                var node_container = post_button.closest('.nm-stream-node-container');

                                nm_stream_update_node_information(node_container, data.information);

                                //attach behavior
                                Drupal.attachBehaviors(new_comment);


                            } else {


                                //append new node
                                var new_node = post_button.closest('.nm-stream-node-container').before($(data.node).fadeIn());

                                post_button.closest('.nm-stream-node-container').hide();
                                //attach behavior
                                Drupal.attachBehaviors(new_node);
                            }

                        } else {
                            //error handling todo here
                        }

                        //enable button
                        nm_stream_unset_loading(form_container);
                        nm_stream_pause_update_timer = false;
                    });

                } else {

                    //edit
                    var form_container = $(this).closest('form');

                    var body = form_container.find('textarea').val();

                    var regresult = form_container.attr('id').split('-');
                    var cid = regresult.pop();

                    var url = '/nm_stream/comment/' + cid + '/edit';
                    var data = {body: body};

                    //disable button
                    nm_stream_form_set_loading(form_container);

                    $.post(url, data, function(data) {
                        if (data.status === 1) {
                            //save succeed
                            var updated_comment = $(form_container).closest('.nm-stream-comment').html($(data.updated_comment).fadeIn());
                            //attach behavior
                            Drupal.attachBehaviors(updated_comment);

                        } else {
                            //error handling todo here
                        }

                        //enable button
                        nm_stream_unset_loading(form_container);
                    });

                }


                return false;
            });
            //bind click to cancel button
            $('.nm-stream-comment-cancel').once('nm_stream').click(function() {
                if ($(this).closest('.nm-stream-edit-comment-actions').length === 0) {
                    //add form
                    $('.nm-stream-comment-form').show();
                    $(this).closest('.nm-stream-comment-form-container').find('textarea').val('');
                    $(this).closest('form').hide();

                } else {
                    //edit form
                    $(this).closest('.nm-stream-main').find('.nm-stream-main-body').show();
                    $(this).closest('form').remove();
                }
                return false;
            });

            /*
             * bind click to comment toggle
             */
            $('.nm_stream_comment_toggle').once('nm_stream').click(function() {

                return false;
            });

            /**
             * set disabled attribute
             * @param {type} element
             * @returns {undefined}
             */
            var post_spinner_white;
            var post_spinner_black;
            var post_spinner_load;

            function nm_stream_disable_action_buttons(element) {
                var submit = element.find("button[class*=-submit]");
                //var cancel = element.find("button[class*=-cancel]");
                submit.attr('disabled', 'disabled');
                //cancel.attr('disabled', 'disabled');
            }

            function nm_stream_enable_action_buttons(element) {
                var submit = element.find("button[class*=-submit]");
                var cancel = element.find("button[class*=-cancel]");
                submit.removeAttr('disabled');
                cancel.removeAttr('disabled');
            }

            function nm_stream_form_set_loading(element) {
                var body = element.find("textarea");
                var privacy = element.find(".dd-select");
                var submit = element.find("button[class*=-submit]");

                body.attr('disabled', 'disabled');
                privacy.hide();
                nm_stream_disable_action_buttons(element);

                post_spinner_white = nm_stream_get_post_spinner_white();

                submit.prepend(post_spinner_white.el);

            }

            function nm_stream_get_post_spinner_white() {

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

            function nm_stream_get_post_spinner_black() {

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
            
             function nm_stream_get_post_spinner_load() {

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

            function nm_stream_textarea_change(textarea, form_container) {
                form_container = $(form_container);
                if (textarea.val().length > 0) {
                    nm_stream_enable_action_buttons(form_container);
                } else {
                    nm_stream_disable_action_buttons(form_container);
                }
            }
            /**
             * remove disabled attribute
             * @param {type} element
             * @returns {undefined}
             */
            function nm_stream_unset_loading(element) {
                var body = element.find("textarea");
                var privacy = element.find(".dd-select");

                body.removeAttr('disabled');
                privacy.show();
                nm_stream_enable_action_buttons(element);

                //stop/hide spinner
                post_spinner_white.stop();
            }


            /*
             *  Update Stream
             */

            //potential error source, if we do not have view-content class wrapper
            $('.view-content').first().once('nm_stream', function() {
                nm_stream_get_update();
                //append iframe for uploads
                $(this).parent().parent().append('<iframe id="nm_stream_hidden_upload" src="" name="nm_stream_hidden_upload" style="width:0;height:0;border:0px solid #fff; position:absolute;"></iframe>');
            });

            function nm_stream_get_update() {
                //pause update actions
                //case:
                //submitting content where updates are transmitted in response messages
                if (nm_stream_pause_update_timer) {
                    clearTimeout(nm_stream_get_update_timer);
                    nm_stream_get_update_timer = setTimeout(nm_stream_get_update, 5000);
                    return;
                }


                var last_node = $('.nm-stream-node-container').first();
                
                if(last_node.length === 0)
                  return;

                var regresult = $(last_node).attr('id').split('-');
                var nid = regresult.pop();
                var url = '/nm_stream/node/' + nid + '/get_update';

                $.ajax({
                    url: url,
                    success: function(data) {
                        //console.log(data);
                        if (data.update_status == 0) {
                            //error
                        } else if (data.update_status == 2) {
                            //new data available

                            nm_stream_handle_node_updates(data);
                        }

                    },
                    complete: function() {
                        // Schedule the next request when the current one's complete

                        nm_stream_get_update_timer = setTimeout(nm_stream_get_update, 10000);
                    }
                });
            }
            ;

            function nm_stream_update_node_information(node_container, new_information_data) {

                var regresult = node_container.attr('id').split('-');
                var nid = regresult.pop();

                var information_text = node_container.find('.nm-stream-node-information').html();

                if (information_text !== null) {

                    if (information_text.indexOf('Kommentare ausblenden') === -1) {
                        var new_information = node_container.find('.nm-stream-node-information').html($(new_information_data[nid]));
                        Drupal.attachBehaviors(new_information);
                    }

                    if (nm_stream_toggle_open_data[nid] === false) {

                        $(new_information).find('.nm_stream_comment_toggle').click();
                    }
                }
            }

            function nm_stream_handle_node_updates(data) {

                //NODES
                var last_node = $('.nm-stream-node-container').first();

                if (typeof data.new_nodes !== 'undefined') {
                    var new_nodes = last_node.parent().prepend($(data.new_nodes).fadeIn());

                    Drupal.attachBehaviors(new_nodes);
                }

                if (typeof data.changed_nodes !== 'undefined') {
                    //some nodes were changed
                    //insert new data
                    //refresh every node which has been changed
                    for (var nid in data.changed_nodes) {
                        var new_top = $(data.changed_nodes[nid]).find('.nm-stream-top').html();
                        var new_body = $(data.changed_nodes[nid]).find('.nm-stream-main-body').html();
                        var node_top_changed = $('#nm-stream-node-' + nid).find('.nm-stream-top').first().html(new_top);
                        var node_body_changed = $('#nm-stream-node-' + nid).find('.nm-stream-main-body').first().html(new_body);

                        Drupal.attachBehaviors(node_top_changed);
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

                            $.post(url, data, function(data) {
                                if (data.status === 1) {
                                    //save succeed
                                    //check if user is typing

                                    var new_comments = $('#nm-stream-node-' + nid).append($(data.node).find('.nm-stream-comments-section').fadeIn());
                                    $('#nm-stream-node-' + nid).find('.nm-stream-comments-section').find('.nm-stream-comments-form').hide();

                                    Drupal.attachBehaviors(new_comments);

                                } else {
                                    //error handling todo here
                                }
                            });

                        } else {
                            var new_comments = $('#nm-stream-node-' + nid).find('.nm-stream-comments-container').first().prepend(data.new_comments[nid]);
                            Drupal.attachBehaviors(new_comments);
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

                        Drupal.attachBehaviors(comment_top_changed);
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
                        }
                        nm_stream_update_node_information(node_container, data.information);
                    }
                }
            }

            /*
             *  UPLOAD
             */
            $('.fileupload').MultiFile({
                list: '.fileupload-list',
                STRING: {
                    remove: '<span class="btn btn-danger fileinput-button">\n\
                            <i class="icon-white icon-remove"></i>\n\
                            <span>entfernen</span>\n\
                        </span>',
                    duplicate: '<h3>Diese Datei wurde bereits ausgewählt!</h3>\n<br/>$file'
                }

            });
            
            /*
             * laod more as infinite spinner
             */
            $('.view-nm-stream .pager a').once('nm_stream', function(){

                post_spinner_load = nm_stream_get_post_spinner_load();
                $(this).text('');
                $(this).append(post_spinner_load.el);
                
            });

        }
    };

}(jQuery));
