(function($) {

var attachPlugin = function(context, id, widget_type) {

  var weightClass = '.mvw-weight-delta-order';

  var wrapper = $('#' + id);
  if (widget_type == 'blocks') {
    $('.mvw-group .mvw-group-title .ui-icon', wrapper )
      .not('.ui-icon-processed')
      .addClass("ui-icon-processed")
      .click(function() {
        $(this)
          .toggleClass("ui-icon-minusthick")
          .toggleClass( "ui-icon-plusthick" )
          .parents('.mvw-group:first').find('.mvw-group-content').toggle();
    });
  }

  $(weightClass).hide();

  var updateField =  function (event, ui) {

    var siblings = [];
    if (widget_type == 'tabs') {
      $('.mvw-tabs li a', wrapper).each(function() {
        var sibling = $($(this).attr('href')).get(0);
        siblings.push(sibling)
      })
      var targetElement = $(weightClass, $($('a', ui.item.context).attr('href'))).get(0);
    }
    else {
      $('.mvw-group', wrapper).each(function(){siblings.push(this)})
      var targetElement = $(weightClass, $(ui.item.context)).get(0);
    }
    

    if ($(targetElement).is('select')) {

      // Get a list of acceptable values.
      var values = [];
      $('option', targetElement).each(function () {
        values.push(this.value);
      });

      var maxVal = values[values.length - 1];

      // Populate the values in the siblings.
      $(weightClass, siblings).each(function () {
        // If there are more items than possible values, assign the maximum value to the row.
        if (values.length > 0) {
          this.value = values.shift();
        }
        else {
          this.value = maxVal;
        }
      });
    }
    else {
      // Assume a numeric input field.
      var weight = parseInt($(weightClass, siblings[0]).val(), 10) || 0;
      $(weightClass, siblings).each(function () {
        this.value = weight;
        weight++;
      });
    }

  }

  switch (widget_type) {
    case 'tabs':
      var tabs = wrapper.tabs();
      tabs.find( ".ui-tabs-nav" )
      .sortable({
        axis: "x",
        stop: function() { tabs.tabs( "refresh" ); },
        update: updateField,
        delay: 100
      });
      break;

    case 'accordion':
      wrapper
      .accordion({
        collapsible: true,
        active: false ,
        header: '> div > .mvw-group-title',
      })
      .sortable({
          axis: 'y',
          handle: '.mvw-group-title',
          stop: function( event, ui ) { ui.item.children('.mvw-group-title').triggerHandler('focusout'); },
          update: updateField,
          delay: 100
      });
      break;

    case 'blocks':
      wrapper
      .sortable({
        update: updateField,
        delay: 100
      });

      break;
    
  }

}

/**
 * Main behavior for multiple value widget.
 */
Drupal.behaviors.multiple_value_widget = {
  attach: function (context, settings) {

    $.each(settings.mvw,function(id, type) {
      attachPlugin(context, id, type);
    })

  }
};

})(jQuery);
