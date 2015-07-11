<?php
/*
  get the href value of bottom link
 */

$pattern = '/<a[^>]* 
               href\s*=\s* 
               (["\'])(.*?)\1     # Text zwischen gleichen Anführungszeichen 
             [^>]*> 
             \s*(.*?)\s* 
             <\/a> 
            /isx';
$matches = array();
preg_match($pattern, $bottom, $matches);

$link = "#";
if ($matches && isset($matches[2])) {
  $link = $matches[2];
}
?>

<a class="nm_fancy_box_link span12" href="<?php echo $link; ?>">

</a>

<div class="nm_fancy_box_container">
  <div class="nm_fancy_box_top">
    <div class="nm_fancy_box_top_image"><?php echo $image; ?></div>
    <div class="nm_fancy_box_top_desc"><?php echo $description; ?></div>
  </div>
  <div class="nm_fancy_box_midddle"><div class="nm_fancy_box_midddle_icon"></div><?php echo $middle; ?></div>
  <div class="nm_fancy_box_bottom"><?php echo $bottom; ?></div>  
</div>



<script type="text/javascript">
  (function($) {
    Drupal.behaviors.onlinekurslabor_fancy_box = {
      attach: function(context, settings) {
        if ($(".nm_home_sh", context).not('.nm_processed')) {
          $(".nm_home_sh", context).click(function() {
            return false;
          });
          $(".nm_home_sh", context).hover(function() {
            $(".nm_fancy_box_link").toggleClass("hover");
            return false;
          });
          $(".nm_home_sh").addClass('nm_processed');
        }
      }

    };
  }(jQuery));
</script>