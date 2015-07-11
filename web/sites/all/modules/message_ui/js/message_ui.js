(function ($) {

  Drupal.behaviors.nodeFieldsetSummaries = {
    attach: function (context) {
      $('.message-form-owner', context).drupalSetSummary(function (context) {
        var name = $('.form-item-name input', context).val() || Drupal.settings.anonymous,
          date = $('.form-item-date input', context).val();
        return date ?
          Drupal.t('By @name on @date', { '@name': name, '@date': date }) :
          Drupal.t('By @name', { '@name': name });
      });
    }
  };

})(jQuery);
