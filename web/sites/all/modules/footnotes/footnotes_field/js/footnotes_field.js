(function ($) {
  Drupal.behaviors.footnotes = {
    attach: function (context, settings) {
      var footnotes_html = '';
      $('ul.footnotes').not('#footnotes-all ul.footnotes').each(function () {
        footnotes_html += $(this).html();
      });
      $('#footnotes-all').html('<ul class="footnotes">' + footnotes_html + '</ul>');
      $('ul.footnotes').not('#footnotes-all ul.footnotes').remove();
    }
  };
})(jQuery);
