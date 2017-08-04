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
    <div class="nm-stream-top col-xs-12">
      <div class="row">
        <div class="nm-stream-left col-xs-1 col-sm-1"><?php echo $nm_author_pic; ?></div>
        <div class="col-xs-11 col-sm-11">
          <div class="row">
            <div class=" nm-stream-middle col-xs-5">
              <div class="nm-stream-name"><?php echo $nm_author_link; ?></div>
              <div class="nm-stream-created"><?php echo $nm_created; ?></div>
            </div>
            <div class="nm-stream-top-right col-xs-7">
              <div class="nm-stream-modified"><?php echo $nm_modified; ?></div>
              <div class="nm-stream-actions"><?php echo $nm_actions; ?></div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="row">

      <div class="nm-stream-left col-xs-1 col-sm-1" style="visibility: hidden;">
        <?php echo $nm_author_pic; ?>
      </div>
      <div class="col-xs-11 col-sm-11">
          <div class="nm-stream-top col-xs-12">
              <div class="col-xs-12"><?php echo $nm_body; ?></div>
          </div>
      </div>
  </div>

</div>