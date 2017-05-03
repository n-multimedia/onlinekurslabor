/*
 * Script ersetzt img-Tags durch Hinweistext
 */
// A $( document ).ready() block.
jQuery(document).ready(function() {

    var ckinstances_list = CKEDITOR.instances;
//get first index in element-list
    var first_ck_index = Object.keys(ckinstances_list)[0];
    var the_ck_editor = ckinstances_list[first_ck_index];

    the_ck_editor.on('paste', function(evt) {
        //sonst doppeltes einfügen
        evt.stop();
        // replace img-tag by alternative image
        var data = evt.data.dataValue.replace(/<img( [^>]*)?>/gi, '<img src="'+Drupal.settings.ckeditor_custom.default_image+'" alt="Bilder bitte hochladen">');
        evt.editor.insertHtml(data);

    }, the_ck_editor.element.$);


});