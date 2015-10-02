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
 
    $fields_for_objective = array('field_objective_motivation' , 'field_objective_task' ,'field_objective_matching'   );
    ?>
  <table cellspacing="0" cellpadding="3" width="100%"class="node--projects-objective" >
   <tr>
                  <td width="90%">
                    
                  <? ?>
                  </td>
                  <td>
                   <?   print render ($content['field_ca_ref']);?>
                  </td>
              </tr>
         <?
          foreach($fields_for_objective as $field)
          {
              echo '<tr><td colspan="2">';
                  print render($content[$field]);
              echo '</tr></td>';
          }
        ?>
   </table>
  <br>
  <br>
<?
  #  print render($content);
  ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article> <!-- /.node -->
