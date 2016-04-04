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
$nid = $fields['nid']->raw;
$node = node_load($nid);
$course_actions = section_courses_render_course_link($node);
$label = !$node->status ? '<span class="label label-important">Entwurf</span> ' : '';

$start_text = '';
$end_text = '';
$percent = _section_courses_get_timespan_percentage($node, $start_text, $end_text);
/*@TODO die funktion hat den "bug", dass sie auch admins mit Schreibrechten liefert, obwohl diese keine echten Dozenten sind. Muss gradgezogen werden, deswegen auskommentiert unten*/
$kurs_dozent_ids =  custom_general_get_users_in_group_by_role($nid, array('kurs-dozent'));
foreach ($kurs_dozent_ids as $dozent) {
    $dozent_acc = user_load($dozent->uid);
    $name = realname_load($dozent_acc);
    $kurs_dozenten[] = l($name, drupal_get_path_alias('user/' . $dozent->uid));
}
?>

<script>
  jQuery(function() {
    jQuery("#progressbar_<?php echo $nid ?>").progressbar({
      value: <?php echo $percent; ?>
    });
  });
</script>

<div class="row-fluid">
  <div class="course-item span12">
    <div class="span3"><?php echo $fields['field_course_picture']->content; ?></div>
    <div class="span4">
      <div class="course-title"><h2><?php echo $label ?><?php echo $fields['title']->content ?></h2></div>
      <div class="course-subtitle"><?php echo $fields['field_subtitle']->content; ?></div>
      <!--<div class="course-dozenten"><small>
              <strong>Lehrende: </strong>
                <?echo implode($kurs_dozenten, ', ')?>
              </small>
      </div>-->
      <div class="course-time row-fluid">
        <div class="course-start-date"><strong>Beginn:</strong> <?php echo $start_text; ?></div>
        <div class="course-end-date"><strong>Ende:</strong> <?php echo $end_text; ?></div>
        <div id="progressbar_<?php echo $nid ?>" ></div>
      </div>
    </div>
    <div class="span5">
      <div class="course-short-description"><?php echo $fields['field_short_description']->content; ?></div>
      <div class="course-actions"><?php echo $course_actions ?></div>
    </div>
  </div>
</div>