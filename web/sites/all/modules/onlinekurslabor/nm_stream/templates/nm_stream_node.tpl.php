<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>

<a id="node-<?php echo $nm_nid; ?>"></a>
<div class="nm-stream-node-container  <?php echo $nm_type; ?>" id="nm-stream-node-<?php echo $nm_nid; ?>">
  <div class="nm-stream-context"><?php echo $nm_context; ?></div>
  <div class="nm-stream-node">
    <div class="row">
      <div class="nm-stream-top col-md-12">
        <div class="row">
          <div class="nm-stream-left col-md-1"><?php echo $nm_author_pic; ?></div>
          <div class="nm-stream-right col-md-11">
            <div class="row">
              <div class="nm-stream-middle col-md-5">
                <div class="nm-stream-name"><?php echo $nm_author_link; ?></div>
                <div class="nm-stream-created"><i class="glyphicon glyphicon-time"></i> <?php echo $nm_created; ?></div>
              </div>
              <div class="nm-stream-top-right col-md-7">
                <div class="nm-stream-privacy">
                  <img height="20" width="20" style="opacity:0.9;" src="/<?php echo $nm_privacy['icon_path']; ?>" title="<?php echo $nm_privacy['label']; ?>" />
                </div>
                <div class="nm-stream-modified"><?php echo $nm_modified; ?></div>
                <div class="nm-stream-actions"><?php echo $nm_actions; ?></div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="nm-stream-main col-md-12">
        <div class="nm-stream-main-body"><?php echo $nm_body; ?></div>
      </div>
    </div>

    <div class="row">
      <?php if (!empty($nm_attachments)): ?>
        <div class="nm-stream-attachments col-md-offset-1 col-md-11">
          <div class="nm-stream-attachments-title"><i class="glyphicon glyphicon-download-alt"></i> Anhänge:</div>
          <div class="nm-stream-attachments-main"><?php echo $nm_attachments; ?></div>
        </div>
      <?php endif; ?>

      <?php if ($nm_num_comments == 0 && !empty($comments_form)) : ?>
        <div class="row">
          <div class="nm-stream-comments-form col-md-offset-1 col-md-11"><?php echo $comments_form; ?></div>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <?php if ($nm_num_comments > 0) : ?>

    <div class="nm-stream-comments-section">
      <div class="row">
        <div class="nm-stream-comments col-md-offset-1 col-md-11">
          <div class="nm-stream-node-information"><?php echo $comments_information; ?></div>
          <div class="nm-stream-comments-form"><?php echo $comments_form; ?></div>
          <div class="nm-stream-comments-container"><?php echo $comments_container; ?></div>   
        </div>
      </div>
    </div>
  <?php endif; ?>

</div>