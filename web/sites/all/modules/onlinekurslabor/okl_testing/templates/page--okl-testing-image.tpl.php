<?php
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$current_path = current_path();
$file_ext = pathinfo($current_path, PATHINFO_EXTENSION);;

header('Content-type: image/'.$file_ext);

 
$image_content = @ $page['content']['system_main']['main']['#markup'];    
 
print render($image_content) ;
exit;

?>