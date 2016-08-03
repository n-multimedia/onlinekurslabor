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
$nid = $fields['nid']->raw;

$node_path = url('node/' . $nid);

$node = node_load($nid);

unset($fields['nid']);

/*
  $field_view = field_view_field('node', $node, 'field_course_picture', array('settings' => array('image_style' => 'course_header')));
  //$field_view['#label_display'] = 'hidden';
  $uri = $field_view['#items'][0]['uri'];
  $url = image_style_url('course_overview_image', $uri);

  $path = $url;
 * 
 */
?>


<div class="row partners-po-item">

  <div class="partners-projects-item-image col-md-3" >
    <?php echo $fields['field_po_logo']->content; ?>
  </div>
  <div class="partners-projects-item-title col-md-5" >
    <?php echo $fields['title']->content; ?>
    <?php echo $fields['field_po_short_description']->content; ?>
  </div>
  <div class="partners-projects-item-list col-md-4" >
    <h3>Projektvorschläge</h3>
    <?php echo $fields['view']->content; ?>
  </div>

</div>