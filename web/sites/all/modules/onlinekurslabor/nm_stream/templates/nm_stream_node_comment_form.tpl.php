<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>

<?php if ($comment): ?>

  <form id="nm-stream-edit-comment-<?php echo $comment->cid ?>" >
    <textarea class="nm-stream-comment-body form-control form-textarea"><?php echo $comment->comment_body[LANGUAGE_NONE][0]['value']; ?></textarea>
    <div class="row">
      <div class="nm-stream-edit-comment-actions">
        <button class="nm-stream-comment-cancel btn btn-danger"><?php echo t('Cancel'); ?></button>
        <button class="nm-stream-comment-submit btn btn-primary"><?php echo t('Post'); ?></button>
        <br><br>
      </div>
    </div>
  </form>

<?php else: ?>
  <div class="nm-stream-comment-form-container">
    <div class="row">
      <div class="nm-stream-top col-md-12">
        <div class="row">
          <div class="nm-stream-left col-xs-1"><?php echo $nm_author_pic; ?></div>
          <div class="col-xs-11">
            <div class="row">
                <div class="col-xs-12 nm-stream-comment-form-clearpadding">
                    <div class="nm-stream-comment-form">
                      <?php echo $nm_comment_form_dummy; ?>
                  </div>
              </div>
              <div class="col-xs-12 nm-stream-comment-form-clearpadding">
                <form id="nm-stream-add-comment-<?php echo $nm_node_id ?>" >
                  <textarea class="nm-stream-comment-body  form-control form-textarea"></textarea>
                  <div class="row">
                    <div class="nm-stream-add-comment-actions">
                      <input class="nm-stream-form-token" type="hidden" name="form_token" value="<?php echo drupal_get_token(); ?>" />
                      <button class="nm-stream-comment-cancel btn btn-danger"><?php echo t('Cancel'); ?></button>
                      <button class="nm-stream-comment-submit btn btn-primary"><?php echo t('Post'); ?></button>
                    </div>
                  </div>
                </form>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

<?php endif; ?>

