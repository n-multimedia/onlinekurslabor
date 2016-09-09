function tasks_markup_callback(node_id, node_title)
{
    return "[task]" + node_id +":"+node_title+ "[/task]";
}
Drupal.behaviors.linkit_extension.createCKDialog({"dialog_id": "tasksDialog", "title": "Aufgabe einfügen", "inputlabel": "Aufgaben-Namen eingeben:", "linkit_profile_id": "tasks", "markup_callback": tasks_markup_callback});
 