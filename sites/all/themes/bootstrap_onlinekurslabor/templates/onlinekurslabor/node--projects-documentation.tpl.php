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
   

  ?>

  <table cellspacing="0" cellpadding="3" width="100%"class="node--projects-documentation" >
              <tr>
                  <th>
                   <h3>Dokumentation</h3>
                   <?   print  render ($content['field_ca_ref']);?>
                  </th>
              </tr>
              <tr>
                  <td  >
                       <?   print render ($content['body']);?>
                  </td>
              </tr>
               <tr>
                  <td  >
                      Author: <?= user_load($node->uid)->realname;   ?>
                  </td>
              </tr>
          <?

?>
   </table>
  <br><br>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_tags']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article> <!-- /.node -->
