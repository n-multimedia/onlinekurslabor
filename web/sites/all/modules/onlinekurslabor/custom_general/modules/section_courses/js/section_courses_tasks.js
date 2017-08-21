(function($) {

    Drupal.behaviors.section_courses_tasks = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {

          var task_empty_fields = Drupal.settings.section_courses.task_remove_empty_fields;

          $('#field-generic-task-entry-values .double-field-elements button').once('section_courses_tasks', function(index, context){

            if(Array.isArray(task_empty_fields) && task_empty_fields.indexOf(index) >= 0){
              //$(this).trigger('click');
              var that = this;
              //gewisse verzoegerung, sonst probleme mit ckeditor
              setTimeout(function(){  $(that).trigger('mousedown').closest('tr').hide();},1300);
            }

          });
        }
    };

}(jQuery));