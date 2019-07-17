(function ($) {
    Drupal.behaviors.section_courses = {
        attach: function (context, settings) {
            //attach funktinoiert nicht in subclasses
            Drupal.behaviors.section_courses.tasks.removeEmptyTaskFields();
        }
    };


    Drupal.behaviors.section_courses.tasks = {
        /*remove new empty fields when editing a task*/
        removeEmptyTaskFields: function () {
            //wird in php gesetzt
            var task_empty_fields = Drupal.settings.section_courses.task_remove_empty_fields;
            $('#field-generic-task-entry-values .double-field-elements button').once('section_courses_tasks', function (index, context) {

                if (Array.isArray(task_empty_fields) && task_empty_fields.indexOf(index) >= 0) {
                    //$(this).trigger('click');
                    var that = this;
                    
                    //gewisse verzoegerung, sonst probleme mit ckeditor
                    setTimeout(function () {
                        $(that).trigger('mousedown').closest('tr').hide();
                    }, 1300);
                }

            });
        }
    };

}(jQuery));