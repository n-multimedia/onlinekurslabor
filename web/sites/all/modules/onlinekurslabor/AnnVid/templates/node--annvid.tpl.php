<div class="col-md-12">
    <? print render($content['body']); ?>
</div>

<? /* klassen werden ueber js dynamisch geandert */ ?>
<div class="col-md-12" id="annvid_videodiv">
    
    <? if (!empty($content['field_pdffile'])): ?>
        <div id="annvid_button_show_pdf_container">
            <ul class="nav nav-tabs" id="annvid_video_fahne">
                <li   class="active" id="annvid_button_show_pdf"><a href="#" class="annvid_dark_button" >PDf&nbsp;anzeigen</a></li>

            </ul>
        </div>
    <? endif ?>
    <? print render($content['field_h5preference']); ?>

    <?
    print _AnnVid_getPlayerCode($node->nid);
    print _AnnVid_getStreamTimeLine();
    module_load_include('inc', 'nm_stream', 'inc/blocks');
    ?>

    <?
    $environment = nm_stream_get_environment();
    print _nm_stream_get_renderedGUI($environment);
    ?>

</div>


<div class="col-md-6"  id="annvid_pdfdiv"> 
    <div class="text-right">
        <button type="button" title="PDF schließen" class="btn btn-default annvid_dark_button" id="annvid_button_hide_pdf">
            <span class="glyphicon glyphicon-remove"></span>
        </button>
    </div>
    <div>
        <? print render($content['field_pdffile']); ?>
    </div>
</div>