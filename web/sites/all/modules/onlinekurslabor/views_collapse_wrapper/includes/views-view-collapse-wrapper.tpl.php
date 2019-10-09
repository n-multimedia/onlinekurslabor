<?php

/**
 * @file
 * simple view template to display a list of rows.
 * First are cut off.
 *
 * @ingroup views_templates
 */

//how many rows must be present to add the "collapse"-feature?
$min_number_of_content = 4; 

//internal
$content_count = 0;
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="views-view-collapse-wrapper--wrapper">
    <div class="views-view-collapse-wrapper--collapse-container collapse show">
      
    <?php foreach ($rows as $id => $row): ?>
      <div<?php if (!empty($classes_array[$id])): ?> class="<?php print $classes_array[$id]; ?>"<?php endif; ?>>
        <?php print $row; ?>
        <?php $content_count += (strlen(trim(strip_tags($row)))>0); ?>
      </div>
    <?php endforeach; ?>
    </div>
    
    <?php if($content_count >= $min_number_of_content):?>
        <div class="views-view-collapse-wrapper--collapse-container-hover"></div>
         <div class="views-view-collapse-wrapper--collapsebutton-container">
           <button class="btn btn-default btn-block" type="button"  id="views-view-collapse--button">
                <?php echo t('Show more');?>
           </button>
         </div>
        <br>
    <?endif?>
</div>