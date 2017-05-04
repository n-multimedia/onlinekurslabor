/*
 * Script ersetzt img-Tags durch Hinweistext
 */

jQuery(document).ready(function() {

    var ckinstances_list = CKEDITOR.instances;
    //falls CKEditor geladen. Wenn nicht skippen, sonst JS-Fehler
    if (Object.keys(ckinstances_list).length > 0)
    {

        //get first index in element-list
        var first_ck_index = Object.keys(ckinstances_list)[0];
        alert(first_ck_index);
        var the_ck_editor = ckinstances_list[first_ck_index];

        the_ck_editor.on('paste', function(evt) {
            //sonst doppeltes einfügen
            evt.stop();
            // replace img-tag by alternative image
            var data = evt.data.dataValue.replace(/<img( [^>]*)?>/gi, '<img src="' + Drupal.settings.ckeditor_custom.default_image + '" alt="Bilder bitte hochladen">');
            evt.editor.insertHtml(data);

        }, the_ck_editor.element.$);

    }

});