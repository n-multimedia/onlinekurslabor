<?php
/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

//get nid and unset field
$nid = $fields['nid_1']->raw;
$node = node_load($nid);
$course_actions = section_courses_render_course_link($node);
?>

<div class="course-item span12">
      <div class="span3"><?php echo $fields['field_course_picture']->content; ?></div>
      <div class="span4">
        <div class="course-title"><h2><?php echo $fields['title']->content; ?></h2></div>
        <div class="course-subtitle"><?php echo $fields['field_subtitle']->content; ?></div>
      </div>
      <div class="span5">
        <div class="course-short-description"><?php echo $fields['field_short_description']->content; ?></div>
        <div class="course-actions"><?php echo $course_actions ?></div>
      </div>
</div>