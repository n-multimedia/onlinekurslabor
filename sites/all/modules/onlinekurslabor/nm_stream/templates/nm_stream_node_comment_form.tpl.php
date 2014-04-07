<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>

<?php if ($comment): ?>

  <form id="nm-stream-edit-comment-<?php echo $comment->cid ?>" >
    <textarea class="nm-stream-comment-body span12"><?php echo $comment->comment_body[LANGUAGE_NONE][0]['value']; ?></textarea>
    <div class="row-fluid">
      <div class="nm-stream-edit-comment-actions">
        <button class="nm-stream-comment-cancel btn btn-danger"><?php echo t('Cancel'); ?></button>
        <button class="nm-stream-comment-submit btn btn-primary"><?php echo t('Post'); ?></button>
      </div>
    </div>
  </form>

<?php else: ?>
  <div class="nm-stream-comment-form-container">
    <div class="row-fluid">
      <div class="nm-stream-top span12">
        <div class="row-fluid">
          <div class="nm-stream-left span1"><?php echo $nm_author_pic; ?></div>
          <div class="span11">
            <div class="row-fluid">
              <div class="nm-stream-comment-form">
                <?php echo $nm_comment_form_dummy; ?>
              </div>
              <form id="nm-stream-add-comment-<?php echo $nm_node_id ?>" >
                <textarea class="nm-stream-comment-body span12"></textarea>
                <div class="row-fluid">
                  <div class="nm-stream-add-comment-actions">
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

<?php endif; ?>

