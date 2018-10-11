<?php
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

?>
<style type="text/css">
    #back_div
    {
        color:white; background: black; width: 100%; text-align:center; padding:5px;
    }
    #back_div a, #back_div a:link, #back_div a:visited
    {
        color: inherit;
        text-decoration: underline;
    }
    </style>
    
    
<div id="back_div">
    <a href="/">Zurück zum System</a>
</div>
<?
print render($page['content']) ;
//exit ist wichtig, sonst haut drupal den footer rein ;-) 
//und dann ist das scroollen doof. 
exit;
?>