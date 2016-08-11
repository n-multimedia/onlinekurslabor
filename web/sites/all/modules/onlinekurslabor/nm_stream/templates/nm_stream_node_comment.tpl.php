<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>

<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>

<div class="nm-stream-comment" id="nm-stream-comment-<?php echo $nm_cid; ?>">
  <div class="row">
    <div class="nm-stream-top col-md-12">
      <div class="row">
        <div class="nm-stream-left col-md-1"><?php echo $nm_author_pic; ?></div>
        <div class="col-md-11">
          <div class="row">
            <div class="nm-stream-middle col-md-5">
              <div class="nm-stream-name"><?php echo $nm_author_link; ?></div>
              <div class="nm-stream-created"><?php echo $nm_created; ?></div>
            </div>
            <div class="nm-stream-top-right col-md-7">
              <div class="nm-stream-modified"><?php echo $nm_modified; ?></div>
              <div class="nm-stream-actions"><?php echo $nm_actions; ?></div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="nm-stream-main col-md-offset-1 col-md-11">
      <div class="nm-stream-main-body"><?php echo $nm_body; ?></div>
    </div>
  </div>

</div>