(function($){

	Drupal.behaviors.linkit_picker_buttons = {
		attach: function(context) {
			$('.linkit_picker_button', context).click(function() {
				var type = $(this).attr('id').replace('edit-','');
				$('#linkit-picker-container .view-container').hide();
				$('#linkit-picker-container .view-linkit-picker-' + type).parents('.view-container').toggle();
				return false;
			});
			$('#linkit-picker-container .view-container:first').show();
		}
	}
	
	Drupal.behaviors.linkit_picker = {
		attach: function(context) {
			$('.view-display-id-default tr td', context).click(function() {
				var type = $(this).parent().find('.views-field-linkit-picker');
				$('.form-item-link input.form-text').val($.trim(type.text())).focus();
				$('html, body').animate({scrollTop:0}, 200);
				$('#edit-browser-wrapper.collapsible legend a').click();
			});
		}
	}

})(jQuery);