(function($) {

    Drupal.behaviors.onlinekurslabor_mics_remove = {
        /*toggle solution for qaa questions*/
        attach: function(context, settings) {

            ////End of Code//////////
            $('form').delegate('.onlinekurlabor_misc_remove_button', 'click', function() {
                var row = $(this).closest('td').parent('tr');
                //console.log(row);
                ///Hide
                $(row).remove();
                ////Zebra color settings////////
                var table_id = $(row).parent('tbody').parent('table').attr('id');
                $('#' + table_id + ' tr.draggable:visible').each(function(index, element) {
                    $(element).removeClass('odd').removeClass('even');
                    if ((index % 2) == 0) {
                        $(element).addClass('odd');
                    } else {
                        $(element).addClass('even');
                    }
                });
                
                return false;
            });

        }
    }


}(jQuery));