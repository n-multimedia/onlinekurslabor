function h5p_markup_callback(node_id, node_title)
{
    return "[h5p]" + node_id + ":" + node_title + "[/h5p]";
}
function h5p_custom_onok(dialog, editor)
{
    var use_ts = dialog.getValueOf('tab-basic', 'insert_timestamp');
    console.debug(use_ts);
    var markup = dialog.getValueOf('tab-basic', 'markup');
    var tsarea_html = "";
    if (use_ts == 1)
        tsarea_html = '<div class="h5p_timestamps">0:00 ' + Drupal.t('example') + '</div><p></p>';

    editor.insertHtml(markup + "\n" + tsarea_html);

}
var h5p_additional_dialog_options = [{// Text input field for the abbreviation text.
        type: 'checkbox',
        id: 'insert_timestamp',
        label: Drupal.t("Insert timestamp-area"),
        title: Drupal.t('Written timestamps in this area will automatically be converted to links'),
        value: 1
    }];
Drupal.behaviors.linkit_extension.createCKDialog({"dialog_id": "h5pDialog", "title": "Interaktiven Inhalt einfügen", "inputlabel": "H5P-Namen eingeben:", "linkit_profile_id": "h5p_interactive_content", "markup_callback": h5p_markup_callback, "onOk": h5p_custom_onok, additional_contents: h5p_additional_dialog_options});
 