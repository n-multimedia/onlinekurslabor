function biblio_markup_callback(node_id, node_title)
{
    return "[bib]" + node_id + "[/bib]";
}
Drupal.behaviors.linkit_extension.createCKDialog({"dialog_id": "biblioDialog", "title": "Bibliografischen Verweis einfügen", "inputlabel": "Biblio-Namen eingeben:", "linkit_profile_id": "biblio", "markup_callback": biblio_markup_callback});
 