<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

<div class="row">
    <div class="col-md-12">
        <?php print render($content['body']); ?>
    </div>
    <div class="hidden-md visible-xs visible-sm" id="is_small_screen_device">
        <!-- platzhalter als JS-Screen-Detector -->
    </div>
</div>

<?php /* klassen werden ueber js dynamisch geandert */ ?>
<div class="row">
<div class="col-md-12" id="annvid_videodiv">

    <?php if (!empty($content['field_pdffile'])): ?>
        <div id="annvid_button_show_pdf_container">
            <ul class="nav nav-tabs" id="annvid_video_fahne">
                <li   class="active" id="annvid_button_show_pdf"><a href="#" class="annvid_dark_button" >PDf&nbsp;anzeigen</a></li>

            </ul>
        </div>
    <?php endif ?>
    <div id="annvid_video_container">
        <?php print render($content['field_h5preference']); ?>
    </div>
    <div id="annvid_video_placeholder" >

    </div>

    <?php
    print _AnnVid_getPlayerCode($node->nid);
    print _AnnVid_getStreamTimeLine();
    module_load_include('inc', 'nm_stream', 'inc/blocks');
    ?>

    <br/>
    <br/>

    <?php
    $environment = nm_stream_get_environment();
    print nm_stream_api_v2_render_stream($environment['context']);
    ?>


</div>


<div class="col-md-6"  id="annvid_pdfdiv">
    <div class="text-right">
        <button type="button" title="PDF schließen" class="btn btn-default annvid_dark_button" id="annvid_button_hide_pdf">
            <span class="glyphicon glyphicon-remove"></span>
        </button>
    </div>
    <div>
        <?php print render($content['field_pdffile']); ?>
    </div>
</div>
<!-- ende row -->
</div>

<?php if (!empty($content['book_navigation'])): ?>
  <?php print render($content['book_navigation']); ?>
<?php endif ?>


</article> <!-- /.node -->

