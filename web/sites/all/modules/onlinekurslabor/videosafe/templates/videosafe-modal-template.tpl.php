<!-- Modal -->
<div id="videosafe_ajax_modal_dialog" class="modal fade" role="dialog">
  <div class="modal-dialog modal-lg">

    <!-- Modal content-->
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal">&times;</button>
        <h4 class="modal-title"><?=t("Select video");?></h4>
      </div>
      <div class="modal-body">
          <p><?=t('First select a folder.')?></p>
          <p><?=t('Then choose one of the videos already uploaded or click "upload" to create a new one.')?></p>
          <p></p>
          <div class="alert alert-warning alert-dismissible" id="just_uploaded_warning" style="display:none;" role="alert">
              <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>
              <strong>Video hochgeladen?</strong> Um es zu finden, müssen Sie nun "Anwenden" klicken.
          </div>
        <div id="videosafe_ajax_modal_view_container">
            <!-- container füer ajax-loader -->
        </div>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal"><?=t('Cancel')?></button>
      </div>
    </div>

  </div>
</div>