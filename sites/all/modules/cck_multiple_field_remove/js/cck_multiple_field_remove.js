jQuery('document').ready(function(){
    ///Hide after the Add More//////////////////
	jQuery(this).ajaxStop(function(e, xhr, settings) {
		var multiple_valued_field = jQuery("input[name=cck_multiple_field_remove_fields]").val();
		multiple_valued_field = multiple_valued_field.split("|");
		for(cck_m_field_count=0;cck_m_field_count<multiple_valued_field.length;cck_m_field_count++){			
			////For textboxes///////////////////
			var field_object_text = jQuery("[name*='"+multiple_valued_field[cck_m_field_count]+"'][type=text]");
			if(field_object_text.length){
				for(field_text_counter=field_object_text.length-1;field_text_counter>=0;field_text_counter--){
					if(field_object_text[field_text_counter].type=="text" && field_object_text[field_text_counter].value!=""){
						break;
					}	
				}
			}
			field_object_text.each(function(index) {
			    var type = this.type || this.tagName.toLowerCase();
			    if(type=="text"){
				    if(index<field_text_counter && jQuery(this).val()==""){
				    	jQuery(this).closest("tr").hide();
				    }
			    }
			});
			///For textarea///////////////////
			var field_object_textarea = jQuery("textarea[name*='"+multiple_valued_field[cck_m_field_count]+"']");
			if(field_object_textarea.length){
				for(field_text_counter=field_object_textarea.length-1;field_text_counter>=0;field_text_counter--){
					if(field_object_textarea[field_text_counter].type=="textarea" && field_object_textarea[field_text_counter].value!=""){
						break;
					}	
				}
			}
			field_object_textarea.each(function(index) {
			    var type = this.type || this.tagName.toLowerCase();
			    if(type=="textarea"){
				    if(index<field_text_counter && jQuery(this).val()==""){
				    	jQuery(this).closest("tr").hide();
				    }
			    }
			});
			///////////////////////////////////////////
			
		}
    });
	////End of Code//////////
    jQuery('div.form-wrapper').delegate('.cck_multiple_field_remove_button', 'click', function(){
    var row = jQuery(this).closest('td').parent('tr');
    ///Hide the textboxes and the Textareas///
    jQuery(row).hide();
    jQuery(row).find('input').val('');
    jQuery(row).find('textarea').text('');
    ////Zebra color settings////////
    var table_id = jQuery(row).parent('tbody').parent('table').attr('id');
    jQuery('#'+table_id+' tr.draggable:visible').each(function(index, element){
      jQuery(element).removeClass('odd').removeClass('even');
      if((index%2) == 0){
        jQuery(element).addClass('odd');
      } else {
        jQuery(element).addClass('even');
      }
    });
  });
});