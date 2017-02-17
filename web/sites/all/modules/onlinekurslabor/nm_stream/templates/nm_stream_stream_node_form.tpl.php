<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>

<?php if (isset($nm_error)): ?>
<div class="alert alert-error"><?php echo $nm_error ?></div>
  <?php return; ?>
<?php endif; ?>

<?php if ($node): ?>
  <?php /* edit */ /*hmpf, warum ist hier eigtl schon wieder code gedoppelt, nur weil der node schon existiert*/ ?>
  <form id="nm-stream-edit-node-<?php echo $node->nid; ?>" method="post" enctype="multipart/form-data" target="nm_stream_hidden_upload" action="/nm_stream/node/<?php echo $node->nid; ?>/edit">
    <textarea class="nm-stream-node-body form-control form-textarea" name="body"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></textarea>
    <div class="row">
      <div class="nm-stream-edit-node-actions col-md-12">
        <div class="row">
          <div class="col-md-12">
            <div class="nm-stream-edit-node-attachments hidden-xs">
              <span class="btn btn-success fileinput-button">
                <i class="glyphicon glyphicon-plus-sign"></i>
                <span>Dateien hinzufügen...</span>
                <input class="fileupload" type="file" name="files[]">
              </span>
              <div class="fileupload-list"></div>
            </div>
            <div class="col-sm-3 col-xs-12" id="nm-stream-edit-node-privacy--<?php echo $node->nid ?> "><?php echo _nm_stream_render_privacy_widget($node, $node->type); ?></div>
            <input type="hidden" name="iframe" value="" />
            <input class="nm-stream-form-token" type="hidden" name="form_token" value="<?php echo drupal_get_token(); ?>" />
            <button class="nm-stream-node-cancel btn btn-danger"><?php echo t('Cancel'); ?></button>&nbsp;<button class="nm-stream-node-submit btn btn-primary"><?php echo t('Post'); ?></button>

          </div>
        </div>
      </div>
    </div>
  </form>
<?php else: ?>
  <?php /* add */ ?>
  <div class="nm-stream-node-form-container">
    <div class="row">
      <div class="nm-stream-top col-md-12">
        <div class="row">
          <div class="nm-stream-left col-xs-1"><?php echo $nm_author_pic; ?></div>
          <div class="col-md-11 col-md-offset-0 col-xs-9 col-xs-offset-1">
            <div class="row">
              <div class="nm-stream-node-form">
                <?php echo $nm_node_form_dummy; ?>
              </div>
              <form id="nm-stream-add-node" method="post" enctype="multipart/form-data" target="nm_stream_hidden_upload" action="/nm_stream/node/add">
                <textarea class="nm-stream-node-body form-control form-textarea" name="body"></textarea>
                <div class="row">
                  <div class="nm-stream-add-node-attachments col-md-12 hidden-xs">
                    <div class="row">
                      <div class="col-md-12">
                        <span class="btn btn-success fileinput-button">
                          <i class="glyphicon glyphicon-plus-sign"></i>
                          <span>Dateien hinzufügen...</span>
                          <input class="fileupload" type="file" name="files[]">
                        </span>
                        <div class="fileupload-list"></div>
                      </div>
                    </div>
                  </div>
                  <div class="row">
                    <div class="nm-stream-add-node-actions col-md-12">
                      <div class="row">
                        <div class="col-md-12">
                          <div id="nm-stream-add-node-privacy"><?php echo $nm_privacy; ?></div>
                          <input type="hidden" name="iframe" value="" />
                          <input class="nm-stream-form-token" type="hidden" name="form_token" value="<?php echo drupal_get_token(); ?>" />
                          <button class="nm-stream-node-cancel btn btn-danger"><?php echo t('Cancel'); ?></button>&nbsp;<button class="nm-stream-node-submit btn btn-primary"><?php echo t('Post'); ?></button>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </form>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

<?php endif; ?>

