<div class="col-md-12">
    <?print render ($content['body']);?>
</div>
<?if(!empty($content['field_pdffile'])):?>
    <div id="annvid_pdfbutton">
        <a class="btn btn-default" href=# id="annvid_pdftoggle">PDF anzeigen</a>
    </div>
<?endif?>
<?/*klassen werden ueber js dynamisch geandert*/?>
<div class="col-md-12" id="annvid_videodiv">
   
  <? print render($content['field_h5preference']); ?>
    
    <?
    print _AnnVid_getPlayerCode($node->nid);
    print  _AnnVid_getStreamTimeLine();;
    module_load_include('inc', 'nm_stream', 'inc/blocks');

    ?>

  <?
    $environment = nm_stream_get_environment();
    print _nm_stream_get_renderedGUI($environment);
  ?>

</div>
<div class="col-md-6"  id="annvid_pdfdiv"> 
    <? print render($content['field_pdffile']); ?>
</div>
