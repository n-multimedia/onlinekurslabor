<?php
/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */


foreach ($rows as &$row_item) {
  if (isset($row_item['nid'])) {
    //check if task is new
    $new = _section_courses_course_get_num_unread_by_type(NULL, NM_COURSE_GENERIC_TASK, $row_item['nid']);
    $new_label = "";
    if($new) {
      $new_label = '<small class="badge badge-important">neu</small>';
    }
      
    
    //check solution state for that task
    $solutions = custom_general_get_task_solutions($row_item['nid'], NULL);
    if(count($solutions) > 0)
    {
      $solution = current($solutions);
      $row_item['nid'] = _courses_tasks_solution_workflow_label($solution->nid);
    }else
    {
      $row_item['nid'] = _courses_tasks_solution_workflow_label();
    }
    
    $row_item['nid_1'] = $new_label;
  }
  
  
  //Group or Single task
  if(isset($row_item['field_task_type']) && is_numeric($row_item['field_task_type'])) {
    if($row_item['field_task_type'] == NM_COURSES_TASK_TYPE_SINGLE) {
      $row_item['field_task_type'] = '<i class="icon-user" title="Einzelaufgabe"></i>';
    } else
    {
      $row_item['field_task_type'] = '<i class="icon-user" title="Gruppenaufgabe"></i><i class="icon-user" title="Gruppenaufgabe"></i>';
    }
  }
}

unset($row_item);


?>

<table <?php if ($classes) {
  print 'class="' . $classes . ' table table-hover" ';
} ?><?php print $attributes; ?>>
  <?php if (!empty($title) || !empty($caption)) : ?>
    <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th <?php if ($header_classes[$field]) {
        print 'class="' . $header_classes[$field] . '" ';
      } ?>>
          <?php print $label; ?>
          </th>
    <?php endforeach; ?>
      </tr>
    </thead>
    <?php endif; ?>
  <tbody>
      <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) {
        print 'class="' . implode(' ', $row_classes[$row_count]) . '"';
      } ?>>
        <?php foreach ($row as $field => $content): ?>
          <td <?php if ($field_classes[$field][$row_count]) {
        print 'class="' . $field_classes[$field][$row_count] . '" ';
      } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
    <?php print $content; ?>
          </td>
  <?php endforeach; ?>
      </tr>
<?php endforeach; ?>
  </tbody>
</table>
