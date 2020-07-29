<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Mache 10+2 Spalten für Sponsors, 8+4 für > 4 sponsors,  12 ohne sponsors
if (count($sponsors_links) > 4) {
    $additional_classes_left = "col-sm-6 col-md-8";
    $additional_classes_right = "col-sm-6 col-md-4";
    $courses_sponsors_class = "courses_sponsors two-col";
} elseif (count($sponsors_links)) {
    $additional_classes_left = "col-sm-9 col-md-10";
    $additional_classes_right = "col-sm-3 col-md-2";
    $courses_sponsors_class = "courses_sponsors one-col";
} else {
    $additional_classes_left = "col-md-12";
    $additional_classes_right = "";
    $courses_sponsors_class = "";
}
?>

<div id="course_header" class="row equal"  style="background-image: url('<?php echo $course_header_url ?>')">
    <?php if($course_state['draft']):?>
            <div class="view_courses_label draft badge" title="<?php echo t("This course is currently being tested not public yet.");?>">
                <?php echo t('Draft');?>
             </div>
    <?endif?>
    
    <div class="col-xs-12 <?php echo $additional_classes_left?>  course_header_left" >
        <?php if($course_state['demo']):?>
            <div id="course_demo_info" class="">
                <h5><?php echo $demo['title'] ; ?></h5>
                <p><?php echo $demo['text']  ; ?></p> 
                <p>
                   <?php if($course_state['pending']):?>
                         <span class="label label-warning"> <b>... <?php echo $demo['pending_text'];?> ...</b> </span>
                   <?elseif(!$course_state['draft']):?>
                          <?php echo $course_subscribe_link;?>
                   <?php endif?>
                </p>
            </div>
        <?php endif?>

            <div id="course_header_title" class="">
                <h1><?php echo $course_title ?></h1>
            </div>

    </div>
    <div class="hidden-xs <?php echo $additional_classes_right?>  course_header_right">
        <div class="<?php echo $courses_sponsors_class?> ">
            <?php foreach ($sponsors_links as $sp_link): ?>
                <?php echo $sp_link ?>
            <?php endforeach; ?>
        </div>
    </div>
</div>