/**
 * 
 * ckeditor behaviours für:
 * - copypaste (bei bildern)
 * - neue tabelle einfügen
 */

jQuery(document).ready(function () {

    var ckinstances_list = CKEDITOR.instances;
    //falls CKEditor geladen. Wenn nicht skippen, sonst JS-Fehler
    if (Object.keys(ckinstances_list).length > 0)
    {

        //get first index in element-list
        var first_ck_index = Object.keys(ckinstances_list)[0];
        var the_ck_editor = ckinstances_list[first_ck_index];

        /*
         * Script ersetzt img-Tags durch Hinweistext
         */
        the_ck_editor.on('paste', function (evt) {
            //sonst doppeltes einfügen
            evt.stop();
            // replace img-tag by alternative image
            var data = evt.data.dataValue.replace(/<img( [^>]*)?>/gi, '<img src="' + Drupal.settings.ckeditor_custom.default_image + '" alt="Bilder bitte hochladen">');
            evt.editor.insertHtml(data);

        }, the_ck_editor.element.$);

        /**
         * per default erhalten tabellen nun einen classic-style
         * @see https://ckeditor.com/old/forums/CKEditor-3.x/Adding-class-attributes
         * @see https://stackoverflow.com/questions/12464395/how-do-i-programmatically-set-default-table-properties-for-ckeditor
         * interessanterweise funktionier HIER nur CKEDITOR.on() und nicht the_ck_editor.on()
         */
        CKEDITOR.on('dialogDefinition', function (ev) {
            var dialogName = ev.data.name;
            var dialogDefinition = ev.data.definition;

            if (dialogName == 'table') {
                //var infoTab = dialogDefinition.getContents('info');
                var advTab = dialogDefinition.getContents('advanced');
                var styleClassesField = advTab.get('advCSSClasses');
                styleClassesField ['default'] = 'classic-table';

                //infoTab.get('txtWidth')[ 'default' ] = '100%';       // Set default width to 100%
                //infoTab.get('txtBorder')[ 'default' ] = '0';         // Set default border to 0
            }
        });

    }

});
