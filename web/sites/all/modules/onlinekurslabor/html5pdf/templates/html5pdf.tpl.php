<?php

/*
 * 
 * width is not yet configurable. should be done..
 * available VARS:
 * 
 *
dpm($identifier);
dpm($pdf_file_url);
dpm($module_path);
 *$css_wrapepr_class
 */
?>

<script src="<? echo $module_path ?>/assets/javascript/pdf.js"></script>
<div id="<?php echo $identifier ?>-html5pdf"  class="<?php echo $css_wrapepr_class ?>">
    <div class=html5pdf_control id="<?php echo $identifier ?>_control">
        <i id="<?php echo $identifier ?>_prev" class="html5pdfsprite html5pdfsprite-last"></i> 
        <span class="html5pdf_pager"><span id="<?php echo $identifier ?>_page_num">-</span> / <span id="<?php echo $identifier ?>_page_count">-</span></span>
        <i id="<?php echo $identifier ?>_next" class="html5pdfsprite html5pdfsprite-next"></i>
        <i id="<?php echo $identifier ?>_zoomin" class="html5pdfsprite html5pdfsprite-zoomin"></i>
        <i id="<?php echo $identifier ?>_zoomout" class="html5pdfsprite html5pdfsprite-zoomout"></i>
    </div><div style="clear:both;"></div>
    <div  id="<?php echo $identifier ?>_pdfscrollcontainer" class="html5pdf_pdfscrollcontainer"><div><canvas id="<?php echo $identifier ?>_pdfcanvas"  class="pdf_canvas"></canvas></div></div>
</div>

<script type="text/javascript">
            /*autodetect doesnt work*/
            PDFJS.workerSrc = '<?php echo $module_path ?>/assets/javascript/pdf.worker.js';
    var identifierstring = '<?php echo $identifier ?>';
    var settings;
    Drupal.behaviors.html5pdf.createReader({
        pdffile: '<?php echo $pdf_file_url ?>'
    }, identifierstring);

    jQuery("#<?php echo $identifier ?>_pdfscrollcontainer").scrollview();


</script>
