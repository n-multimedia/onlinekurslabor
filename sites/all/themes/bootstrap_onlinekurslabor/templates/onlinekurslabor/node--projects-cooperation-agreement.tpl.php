<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
 
  <!--
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <span class="submitted">
        <?php print $user_picture; ?>
        <?php print $submitted; ?>
      </span>
    <?php endif; ?>
  </header>
  -->
  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
   //    print render ($content[field_ca_timespan]);

     $fields_for_coop = array(  'field_ca_expectation_academy','field_ca_expectation_po',  'field_ca_result',      'field_ca_students_role','field_ca_partners_role', 'field_ca_cooperation_rules');
    ?>
 
  <table cellspacing="0" cellpadding="3" width="100%"class="node--projects-cooperation-agreement" >
              <tr>
                  <td>
                  <?   print render ($content['field_ca_proposal_ref']);?>
                  </td>
                  <td>
                   <?   print render ($content['field_ca_timespan']);?>
                  </td>
              </tr>
          <?
  foreach($fields_for_coop as $coop_part)
  {
      echo '<tr><td colspan="2">';
          print render($content[$coop_part]);
      echo '</tr></td>';
  }
?>
   </table>
  <br>
  <br>
  <br>
<?

 /*
           $content['field_ca_course_group_ref']

           $content['field_ca_proposal_ref']
           $content['field_ca_student_refs']
         //unsicher
          $content['group_group']
         $content['field_seal']
         */


  ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article> <!-- /.node -->
