<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
 
  <?#return; ?>
  <!--
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    
  </header>
  <?   print  render ($content['body']);?> 
       <?   print render ($content['body']);?>
  -->
    
  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
 #dpm($content);

  ?>
   
  <table cellspacing="0" cellpadding="3" width="100%"class="node--projects-documentation" >
              <tr>
                  <th>
                   <h3><?  print  $title?></h3>
                   <?  print  render ($content['field_ca_ref']);?>
                  </th>
              </tr>
              <tr>
                  <td  >
                    
                      
                      <?  
                      //get first (and only) element
                      $pdf_file_uricreator = reset($content['field_pdf_file']['#items'] );
                      $pdf_file_uid =  $pdf_file_uricreator['file']->uuid ;
                      $pdf_file_uricreator = $pdf_file_uricreator['file']->uri;
                      ?>
                  </td>
           
                <tr>
                     <tr>
                  <td  >
                       
                        <?   $h5p_reference_node_id = $content['field_h5p_reference']['#object'];
                         $h5p_reference_node_id =  $h5p_reference_node_id->field_h5p_reference;
                        $h5p_reference_node_id  = $h5p_reference_node_id[LANGUAGE_NONE][0]["target_id"];
                     
                      echo _AnnVid_getPlayer($h5p_reference_node_id, file_create_url($pdf_file_uricreator)) ?>
                  </td>
           
                <tr>
                  <td  >
                   
                 
                      
                          
                      <hr><hr>
                      <?
                   # 
                     
                      
                        
                    //  print _html5pdf_getPDFReader($pdf_file_uid,file_create_url($pdf_file_uricreator))?>
                         <hr><hr>
                  </td>
              </tr>
            
            
               <tr>
                  <td  >
                  <div style="padding:1em; width:100%; border: 1px solid grey; margin:1em;">
                     <?
								    foreach($content['field_testmultimedia']['#items'] as $multimediaentry)
								    {
								    $file = $multimediaentry['file'];
								  #  dpm($file);
								   # echo $file->uri;
								 #  print render($content['field_testmultimedia']);; 
								   ?>
									 <img src="<?php print file_create_url($file->uri); ?>" />
									 <?
								    #var_dump($multimediaentry);
										}
										?>
                    </div>
                  </td>
              </tr>
               <tr>
                  <td  >
                      
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
