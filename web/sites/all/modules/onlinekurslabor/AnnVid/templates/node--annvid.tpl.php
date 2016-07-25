<div class="span12">
    <?print render ($content['body']);?>
</div>
<div id="annvid_pdfbutton">
    <a class="btn" href=# id="annvid_pdftoggle">PDF anzeigen</a>
     
</div>
<div class="span12" id="annvid_videodiv">
   
  <? print render($content['field_h5preference']); ?>
    
    <?
    print _AnnVid_getPlayerCode($node->nid);
    print  _AnnVid_getStreamTimeLine();;
    module_load_include('inc', 'nm_stream', 'inc/blocks');
print _nm_stream_get_renderedGUI(arg(1));
?>
</div>
<div class="span6"  id="annvid_pdfdiv">
    <? print render($content['field_pdffile']); ?>
</div>
<?php 
 