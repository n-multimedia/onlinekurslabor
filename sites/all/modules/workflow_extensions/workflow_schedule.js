
// Original version contributed by Brian Tully. See http://drupal.org/node/1162632
// This version handles multiple occurrences of the form on a page.

(function($) {
  Drupal.behaviors.WorkflowShowHideScheduledDateTime = {
    attach: function(context, setting) {
      var i = 0;
      // Show/hide schedule date and hour based on which radio button is active.
      $("input:radio[class=form-radio]").each(function(index) {
        var radioButton = $(this);

        if (radioButton.attr("id").substring(0, 23) == "edit-workflow-scheduled") {

          var j = Math.floor(i / 2) + 1;
          var wrappers = (j <= 1)
            ? $("#edit-workflow-scheduled-date,         #edit-workflow-scheduled-hour")
            : $("#edit-workflow-scheduled-date--"+j + ",#edit-workflow-scheduled-hour--"+j);

          if (radioButton.is(':checked') && radioButton.val() < 1) {
            // "Immediately" is already pressed upon page entry
            wrappers.hide();
            wrappers.next().hide(); // for .description
          }
          radioButton.click(function() {
            if (radioButton.val() < 1) {
              // "Immediately" is clicked
              wrappers.hide();
              wrappers.next().hide();
            }
            else {
              // "Schedule for state change" is clicked
              wrappers.show();
              wrappers.next().show();
            }
          });
          i++;
        }
      });

    }
  }
})(jQuery);
