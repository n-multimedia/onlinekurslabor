
(function($) {
    Drupal.behaviors.html5pdf = {
        attach: function(context, settings) {


        },
        //todo: make array. else only one object.
        renderer: null,
        createReader: function(options, identifierstring)
        {
          //  todo alert("renderer braucht ein event on resize, das angesprochen werden kann, da größe nicht definierbar");
            // This is the easiest way to have default options.
            var settings = $.extend({
                pdffile: null,
                /*default-eintraege aus html5pdf-plugin*/
                html_pagecount_id: identifierstring+'_page_count',
                html_currentpage_id: identifierstring+'_page_num',
                html_pdfcanvas_id: identifierstring+'_pdfcanvas',
                width: $('#'+identifierstring+'-html5pdf').css('width')
            }, options);
            this.renderer = new HTML5PDF(settings);
            
            this.renderer.loadPDF(
                    //callback
                    function() {
                        $("#" + identifierstring + '_pdfcanvas').addClass('pdf_canvas_loaded');
                        //trigger event to listen to
                        $.event.trigger({
                            type: "annvid_entity_loaded",
                            message: "pdf",
                            time: new Date()
                        });
                    }
            ,
            //errorcallback
                    function(error) {
                        $('#'+identifierstring+'_pdfscrollcontainer').html('<div style="background:white;min-height: 70px;"><div class="alert alert-block alert-danger messages error">'+Drupal.t('Error loading the PDF!')+'</div></div>');
                    }
            );
            var that = this;
            /*bind created controls to actions*/
            $('#'+identifierstring+'_zoomin').click(function(){that.renderer.zoomIn()});           
            $('#'+identifierstring+'_zoomout').click(function(){that.renderer.zoomOut()});      
            $('#'+identifierstring+'_next').click(function(){that.renderer.pageUp();});           
            $('#'+identifierstring+'_prev').click(function(){that.renderer.pageDown(); });     
        },
        //todo: set und get jeweils mit identifier!
        getPDFRenderer: function() {
            return this.renderer;
        }
    }
}(jQuery));
