<?php
/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

?>
<style type="text/css">
    #top_nav
    {
        color:white; background: black; width: 100%; text-align:center; padding:5px;
    }
    #top_nav a, #top_nav a:link, #top_nav a:visited
    {
        color: inherit;
        text-decoration: underline;
    }
    </style>
    
    
<div id="top_nav">
    <a href="/">Zurück zum System</a> | <a href="/okl-testing">Records</a> | <a href="/okl-testing/debug">Debugging-Info</a>
</div>
<?
print render($page['content']) ;
//exit ist wichtig, sonst haut drupal den footer rein ;-) 
//und dann ist das scroollen doof. 
exit;
?>