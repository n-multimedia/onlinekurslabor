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

$proposal_field_key = $node->field_proposal_status[LANGUAGE_NONE][0]['value'];

$proposal_status_class = '';

if ($proposal_field_key == 0) {
  $proposal_status_class = 'badge badge-success';
}
else if ($proposal_field_key == 1) {
  $proposal_status_class = 'badge badge-warning';
}
else {
  $proposal_status_class = 'badge badge-important';
}

$field_view = field_view_field('node', $node, 'field_proposal_status');
$field_view['#label_display'] = 'hidden';
$proposal_status = drupal_render($field_view);

?>


<div class="row-fluid partners-projects-item">
  <div class="partners-projects-item-status span1" >
    <span class="<?php echo $proposal_status_class; ?>" style="float:left; margin-right:7px; line-height:12px">&nbsp;</span>
  </div>
  <div class="partners-projects-item-changed span11" >
    
    <?php echo $fields['title']->content; ?>  
  </div>

</div>